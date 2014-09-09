#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "zlib.h"
#include "pdftypes.h"
#include "pdfmem.h"
#include "pdfread.h"
#include "pdffilter.h"
#include "pdfdoc.h"
#include "lzw_decomp.h"
#include "openjpeg.h"
#include "turbojpeg.h"

static int pdf_filter_aes_read(pdf_filter *f, unsigned char *obuf, int request);

// common member functions
static int
pdf_filter_base_read(pdf_filter *f, unsigned char *obuf, int request)
{
    return 0;
}

static int
pdf_filter_base_write(pdf_filter *f, unsigned char *obuf, int request)
{
    return 0;
}

static pdf_err
pdf_filter_base_flush(pdf_filter *f, unsigned char *buf, int *len)
{
    *len = 0;
    return pdf_ok;
}

// deflates
static int pdf_flated_read(pdf_filter *f, unsigned char *obuf, int request);
static pdf_err pdf_flated_close(pdf_filter *f, int flag);

static void *zalloc(void *opaque, unsigned int items, unsigned int size)
{
    return pdf_malloc(items*size);
}

static void zfree(void *opaque, void *ptr)
{
    pdf_free(ptr);
}

pdf_err
pdf_flated_new(pdf_filter **f)
{
    z_stream *z;
    int ret;
    if (!f)
        return pdf_unknown;
    *f = pdf_malloc(sizeof(pdf_filter));
    if (!(*f))
        return pdf_mem_err;
    z = pdf_malloc(sizeof(z_stream));
    if (!z)
        return pdf_mem_err;
    memset(z, 0, sizeof(z_stream));
    z->zalloc = zalloc;
    z->zfree = zfree;
    z->opaque = 0;//ctx;
    z->next_in = NULL;
    z->avail_in = 0;

    ret = inflateInit(z);
    //ret = inflateInit2(z, 16+31);//MAX_WBITS);
    (*f)->state = (void*)z;
    (*f)->read = pdf_flated_read;
    (*f)->close = pdf_flated_close;
    (*f)->flush = pdf_filter_base_flush;
    (*f)->ptr = (*f)->buf;
    return pdf_ok;
}

static pdf_err
pdf_flated_close(pdf_filter *f, int flag)
{
    int ret;
    if (!f)
        return pdf_ok;
    if (f->state)
        ret = inflateEnd(f->state);
    pdf_free(f->state);
    pdf_free(f);
    return pdf_ok;
}

// return the length read
// return 0 signifies EOF
static int
pdf_flated_read(pdf_filter *f, unsigned char *obuf, int request)
{
    int ret, in = 0;
    pdf_filter *up = f->next; // upstream
    z_stream *z = (z_stream*)f->state;

    if (z->avail_in)
    {
      inflate:
        z->next_out = obuf;
        z->avail_out = request;
        ret = inflate(z, Z_NO_FLUSH);
        assert(ret != Z_STREAM_ERROR);  /* state not clobbered */
        switch (ret) {
            case Z_NEED_DICT:
                ret = Z_DATA_ERROR;     /* and fall through */
            case Z_MEM_ERROR:
                (void)inflateEnd(z);
                return 0;
            case Z_DATA_ERROR:
                if (z->avail_in != 0)
                    return 0; // EOF
                break;
        }
    }
    else
    {
        // read upstream
      read_upstream:
        in = (up->read)(up, f->ptr, PDF_FILTER_BUF_SIZE);
        z->next_in = f->ptr;
        z->avail_in = in;
        goto inflate;
    }
    if (z->avail_out == 0)
    {
        return request;
    }
    else
    {
        if (request == z->avail_out)
            if (in)
                goto read_upstream;
        return request - z->avail_out;
    }
}
///////////////////////////////////////////
// flate compression
///////////////////////////////////////////
#define CHUNK 16384

/* Compress from file source to file dest until EOF on source.
   def() returns Z_OK on success, Z_MEM_ERROR if memory could not be
   allocated for processing, Z_STREAM_ERROR if an invalid compression
   level is supplied, Z_VERSION_ERROR if the version of zlib.h and the
   version of the library linked do not match, or Z_ERRNO if there is
   an error reading or writing the files. */
static int def(FILE *source, FILE *dest, int level)
{
    int ret, flush;
    unsigned have;
    z_stream strm;
    unsigned char in[CHUNK];
    unsigned char out[CHUNK];

    /* allocate deflate state */
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    ret = deflateInit(&strm, level);
    if (ret != Z_OK)
        return ret;

    /* compress until end of file */
    do {
        strm.avail_in = fread(in, 1, CHUNK, source);
        if (ferror(source)) {
            (void)deflateEnd(&strm);
            return Z_ERRNO;
        }
        flush = feof(source) ? Z_FINISH : Z_NO_FLUSH;
        strm.next_in = in;

        /* run deflate() on input until output buffer not full, finish
           compression if all of source has been read in */
        do {
            strm.avail_out = CHUNK;
            strm.next_out = out;
            ret = deflate(&strm, flush);    /* no bad return value */
            assert(ret != Z_STREAM_ERROR);  /* state not clobbered */
            have = CHUNK - strm.avail_out;
            if (fwrite(out, 1, have, dest) != have || ferror(dest)) {
                (void)deflateEnd(&strm);
                return Z_ERRNO;
            }
        } while (strm.avail_out == 0);
        assert(strm.avail_in == 0);     /* all input will be used */
        /* done when last data in file processed */
    } while (flush != Z_FINISH);
    assert(ret == Z_STREAM_END);        /* stream will be complete */

    /* clean up and return */
    (void)deflateEnd(&strm);
    return Z_OK;
}

static int
pdf_deflate_write(pdf_filter *f, unsigned char *in, int request, int *written)
{
    int ret;
    z_stream *z = (z_stream*) f->state;

    if (z->avail_in == 0)
    {
        if (request == 0)
        {
            return 0;
        }

        z->avail_in = request;
        z->next_in = in;
        *written = request;
    }
    else
    {
        *written = 0;
    }
    z->avail_out = PDF_FILTER_BUF_SIZE;
    z->next_out = f->buf;
    ret = deflate(z, Z_NO_FLUSH);    /* no bad return value */
    assert(ret != Z_STREAM_ERROR);  /* state not clobbered */

    return PDF_FILTER_BUF_SIZE - z->avail_out;
}

pdf_err
pdf_deflate_close(pdf_filter *f, int flag)
{
    int ret = Z_OK;
    z_stream *z = (z_stream*) f->state;
    if (f && z)
    {
        ret = deflateEnd(z);
        pdf_free(z);
    }
    if (ret != Z_OK)
        return pdf_io_err;
    return pdf_ok;
}

pdf_err
pdf_deflate_flush(pdf_filter *f, unsigned char *buf, int *len)
{
    int ret = Z_OK;
    z_stream *z = (z_stream*) f->state;
    if (f && z)
    {
        z->avail_out = *len;
        z->next_out = buf;
        ret = deflate(z, Z_FINISH);
        *len = *len - z->avail_out;
    }
    if (ret != Z_OK)
        return pdf_io_err;
    return pdf_ok;
}

pdf_err
pdf_deflate_new(pdf_filter **f)
{
    int ret;
    z_stream *z;

    if (!f)
        return pdf_unknown;
    *f = pdf_malloc(sizeof(pdf_filter));
    if (!(*f))
        return pdf_mem_err;
    z = pdf_malloc(sizeof(z_stream));
    if (!z)
        return pdf_mem_err;
    memset(z, 0, sizeof(z_stream));

    /* allocate deflate state */
    z->zalloc = Z_NULL;
    z->zfree = Z_NULL;
    z->opaque = Z_NULL;
    ret = deflateInit(z, Z_DEFAULT_COMPRESSION);
    if (ret != Z_OK)
        return pdf_io_err;
    (*f)->state = (void*)z;
    (*f)->write = pdf_deflate_write;
    (*f)->read = pdf_filter_base_read;
    (*f)->close = pdf_deflate_close;
    (*f)->flush = pdf_deflate_flush;
    return pdf_ok;
}



///////////////////////////////////////////
pdf_err
pdf_rawfilter_close(pdf_filter *f, int flag)
{
    sub_stream *ss;
    if (!f)
        return 0;
    ss = (sub_stream*) f->state;
    (ss->close)(ss, flag);
    pdf_free(f);
    return pdf_ok;
}

static int
pdf_rawfilter_read(pdf_filter *f, unsigned char *obuf, int request)
{
    sub_stream *ss;
    if (!f)
        return 0;
    ss = (sub_stream*) f->state;
    return (ss->read)(ss, obuf, request);
}

pdf_filter*
pdf_rawfilter_new(sub_stream* ss)
{
    pdf_filter *f = pdf_malloc(sizeof(pdf_filter));
    if (!f)
        return NULL;
    memset(f, 0, sizeof(pdf_filter));
    f->close = pdf_rawfilter_close;
    f->read = pdf_rawfilter_read;
    f->flush = pdf_filter_base_flush;
    f->state = (void*) ss;
    return f;
}

static int
pdf_rawfilter_write(pdf_filter *f, unsigned char *obuf, int request)
{
    FILE *of;
    if (!f)
        return 0;
    of = (FILE*) f->state;
    return fwrite(obuf, 1, request, of);
}

///////////////////////////////////////////
// ASCIIHexDecode
///////////////////////////////////////////
static int asciihex_class[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 3, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

static int asciihex_to_int[] =
{
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0,
 0, 10, 11, 12, 13, 14, 15,  0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 10, 11, 12, 13, 14, 15,  0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};


pdf_err
pdf_ahex_close(pdf_filter *f, int flag)
{
    if (!f)
        return 0;
    pdf_free(f);
    return pdf_ok;
}

static int
pdf_ahex_read(pdf_filter *f, unsigned char *obuf, int request)
{
    int len = request * 2;
    pdf_filter *up = f->next;
    int i, l, o, m = 0;

    if (!up)
        return 0;

    if (len > PDF_FILTER_BUF_SIZE)
        len = PDF_FILTER_BUF_SIZE;

    l = (up->read)(up, f->buf, len);

    if (l)
    {
        unsigned char *op = obuf;
        int tmp;

        o = 0;

      do_more:
        for (i= 0; i < l; i++)
        {
            if (asciihex_class[f->buf[i]] == 1)
            {
                if (o%2)
                {
                    *op++ = asciihex_to_int[f->buf[i]] + tmp;
                }
                else
                {
                    tmp = asciihex_to_int[f->buf[i]] << 4;
                }
                o++;
            }
            else if (asciihex_class[f->buf[i]] == 3)
            {
                // more to read
                m++;
            }
            else
            {
                // error
                // should produce error message
                break;
            }
        }

        if (m && (o%2))
        {
            l = (up->read)(up, f->buf, m);
            m = 0;
            goto do_more;
        }
    }

    return o/2;
}

pdf_err
pdf_ahex_new(pdf_filter **f)
{
    *f = pdf_malloc(sizeof(pdf_filter));
    if (!(*f))
        return pdf_mem_err;
    memset(*f, 0, sizeof(pdf_filter));
    (*f)->close = pdf_ahex_close;
    (*f)->read = pdf_ahex_read;
    (*f)->flush = pdf_filter_base_flush;
    return pdf_ok;
}

/////////////////////////////////////////// ASCII85Decode
struct pdf_a85d_s
{
    unsigned char bp[4];
    unsigned char *rp, *wp;
    int eod;
};

pdf_err
pdf_a85d_close(pdf_filter *f, int flag)
{
    if (!f)
        return 0;
    pdf_free(f->state);
    pdf_free(f);
    return pdf_ok;
}

static int
pdf_a85d_read(pdf_filter *f, unsigned char *obuf, int request)
{
    struct pdf_a85d_s *state;
    pdf_filter *up;
    unsigned char *p = obuf;
    unsigned char *e = obuf+request;
    unsigned char c;
    unsigned int word=0, count=0;

    if (!f)
        return 0;
    state = f->state;
    if (!state)
        return 0;
    up = f->next; // upstream
    if (!up)
        return 0;
    while (p < e)
    {
        int l;
        if (state->eod)
            return p - obuf;
        // read upstream
        l = (up->read)(up, &c, 1);
        if (l == 0)
        { // eof
            return p - obuf;
        }
        if (c >= '!' && c <= 'u')
        {
            if (count == 4)
            {
                word = word * 85 + (c - '!');

                state->bp[0] = (word >> 24) & 0xff;
                state->bp[1] = (word >> 16) & 0xff;
                state->bp[2] = (word >> 8) & 0xff;
                state->bp[3] = (word) & 0xff;
                state->rp = state->bp;
                state->wp = state->bp + 4;

                word = 0;
                count = 0;
            }
            else
            {
                word = word * 85 + (c - '!');
                count ++;
            }
        }
        else if (c == 'z' && count == 0)
        {
            state->bp[0] = 0;
            state->bp[1] = 0;
            state->bp[2] = 0;
            state->bp[3] = 0;
            state->rp = state->bp;
            state->wp = state->bp + 4;
        }
        else if (c == '~')
        {
            int l = (up->read)(up, &c, 1);

            if (l == 0 || (c != '>'))
                printf("%s\n", "bad eod marker in a85d");

            switch (count) {
                case 0:
                    break;
                case 1:
                    printf("%s\n", "partial final byte in a85d");
                case 2:
                    word = word * (85 * 85 * 85) + 0xffffff;
                    state->bp[0] = word >> 24;
                    state->rp = state->bp;
                    state->wp = state->bp + 1;
                    break;
                case 3:
                    word = word * (85 * 85) + 0xffff;
                    state->bp[0] = word >> 24;
                    state->bp[1] = word >> 16;
                    state->rp = state->bp;
                    state->wp = state->bp + 2;
                    break;
                case 4:
                    word = word * 85 + 0xff;
                    state->bp[0] = word >> 24;
                    state->bp[1] = word >> 16;
                    state->bp[2] = word >> 8;
                    state->rp = state->bp;
                    state->wp = state->bp + 3;
                    break;
            }
            state->eod = 1;
        }
        else if (c != ' ')
        {
            printf("%s\n", "bad data in a85d: '%c'");
            return 0;
        }

        while (state->rp < state->wp && p < e)
            *p++ = *state->rp++;
    }
    return p - obuf;
}

pdf_err
pdf_a85d_new(pdf_filter **f)
{
    struct pdf_a85d_s *state;
    *f = pdf_malloc(sizeof(pdf_filter));
    if (!(*f))
        return pdf_mem_err;
    memset(*f, 0, sizeof(pdf_filter));
    (*f)->close = pdf_a85d_close;
    (*f)->read = pdf_a85d_read;
    (*f)->flush = pdf_filter_base_flush;
    state = pdf_malloc(sizeof(struct pdf_a85d_s));
    if (!state)
    {
        pdf_free(*f);
        return pdf_mem_err;
    }
    state->rp = state->bp;
    state->wp = state->bp;
    state->eod = 0;
    (*f)->state = state;
    return pdf_ok;
}

///////////////////////////////////

static pdf_err
pdf_lzw_d_close(pdf_filter *f, int flags)
{
    if (!f)
        return pdf_ok;
    if (f->state)
        lzw_decomp_close(f->state);
    pdf_free(f);
    return pdf_ok;
}

static int
pdf_lzw_d_read(pdf_filter *f, unsigned char *obuf, int request)
{
    return lzw_decomp_read(f->state, obuf, request);
}

pdf_err
pdf_lzw_d_new(pdf_filter **f, pdf_filter *last)
{
    lzw_decompress *lzw = lzw_decomp_init(pdf_malloc, pdf_free, pdf_filter_read, (void*)last);
    if (!lzw)
        return pdf_mem_err;
    *f = pdf_malloc(sizeof(pdf_filter));
    if (!(*f))
        return pdf_mem_err;
    (*f)->state = (void*)lzw;
    (*f)->close = pdf_lzw_d_close;
    (*f)->read = pdf_lzw_d_read;
    (*f)->flush = pdf_filter_base_flush;
    return pdf_ok;
}

///////////////////////////////////

int
pdf_filter_getchar(pdf_filter *f)
{
    unsigned char a;
    int l;
    l = (f->read)(f, &a, 1);
    if (l==0)
        return 0; // should be EOF
    return a;
}

int
pdf_filter_read(pdf_filter *f, unsigned char *buf, int len)
{
    return (f->read)(f, buf, len);
}

pdf_filter*
pdf_filter_new(pdf_filterkind t, pdf_filter* last)
{
    pdf_filter *f = NULL;
    switch (t)
    {
        case FlateDecode:
            pdf_flated_new(&f);
            break;
        case ASCIIHexDecode:
            pdf_ahex_new(&f);
            break;
        case ASCII85Decode:
            pdf_a85d_new(&f);
            break;
        case LZWDecode:
            pdf_lzw_d_new(&f, last);
            break;
        default:
            return NULL;
    }

    if (f)
    {
        f->next = last;
    }
    return f;
}

pdf_filterkind
pdf_filter_find(char *k)
{
    pdf_filterkind t;
    if (strcmp(k, "FlateDecode") == 0)
    {
        t = FlateDecode;
    }
    else if (strcmp(k, "ASCIIHexDecode") == 0)
    {
        t = ASCIIHexDecode;
    }
    else if (strcmp(k, "ASCII85Decode") == 0)
    {
        t = ASCII85Decode;
    }
    else if (strcmp(k, "LZWDecode") == 0)
    {
        t = LZWDecode;
    }
    else if (strcmp(k, "RunLengthDecode") == 0)
    {
        t = RunLengthDecode;
    }
    else if (strcmp(k, "CCITTFaxDecode") == 0)
    {
        t = CCITTFaxDecode;
    }
    else if (strcmp(k, "JBIG2Decode") == 0)
    {
        t = JBIG2Decode;
    }
    else if (strcmp(k, "DCTDecode") == 0)
    {
        t = DCTDecode;
    }
    else if (strcmp(k, "JPXDecode") == 0)
    {
        t = JPXDecode;
    }
    else if (strcmp(k, "Crypt") == 0)
    {
        t = Crypt;
    }
    else if (strcmp(k, "Standard") == 0)
    {
        t = Standard;
    }
    else
    {
        t = Limit;
    }
    return t;
}

void
pdf_filter_str_to_enum(pdf_obj *o, pdf_filterkind* filter_array)
{
    filter_array[0] = Limit;
    if (o->t == eKey || o->t == eName)
    {
        filter_array[0] = pdf_filter_find(o->value.k);
        filter_array[1] = Limit;
    }
    else if (o->t == eArray)
    {
        int i;
        for (i = 0;i < o->value.a.len; i++)
        {
            filter_array[i] = pdf_filter_find(o->value.a.items[i].value.k);
        }
        filter_array[i] = Limit;
    }
}

const char*
pdf_filter_to_string(pdf_filterkind k)
{
    const char *s;
    switch (k)
    {
        case ASCIIHexDecode:
            s = "ASCIIHexDecode";
            break;
        case FlateDecode:
            s = "FlateDecode";
            break;
        case ASCII85Decode:
            s = "ASCII85Decode";
            break;
        case LZWDecode:
            s = "LZWDecode";
            break;
        case RunLengthDecode:
            s = "RunLengthDecode";
            break;
        case CCITTFaxDecode:
            s = "CCITTFaxDecode";
            break;
        case JBIG2Decode:
            s = "JBIG2Decode";
            break;
        case DCTDecode:
            s = "DCTDecode";
            break;
        case JPXDecode:
            s = "JPXDecode";
            break;
        case Crypt:
            s = "Crypt";
            break;
        case RC4Encrypt:
        case AESEncrypt:
        default:
            s = "";
            break;
    }
    return s;
}

struct aes_state_s
{
    void *ctx; // openssl-CTX holder
    char  buf[PDF_FILTER_BUF_SIZE], *ptr, *end;
    int   eof;
};


pdf_err
pdf_filter_aes_close(pdf_filter *f, int flags)
{
    if (f)
    {
        struct aes_state_s *s = f->state;
        if (s)
        {
            if (s->ctx)
                pdf_aes_close(s->ctx);
            s->ctx = 0;
            pdf_free(s);
            f->state = 0;
        }
        if (f->data)
            pdf_free(f->data);

        pdf_free(f);
     }
    return pdf_ok;
}


static int
pdf_filter_aes_write(pdf_filter *f, unsigned char *ibuf, int request, int *written)
{
    // aes writes to filter's internal buffer
    if (f && f->data)
    {
        memcpy(f->buf, f->data, 16);
        // iv
        pdf_free(f->data);
        f->data = 0;
        *written = 0;
        return 16;
    }
    *written = request;
    return pdf_aes_write(f->state, ibuf, f->buf, request);
}

static
pdf_err
pdf_filter_aes_e_close(pdf_filter *f, int flag)
{
    if (f && f->state)
    {
        pdf_aes_close(f->state);
    }
    return pdf_ok;
}

static
pdf_err
pdf_filter_aes_e_flush(pdf_filter *f, char *buf, int *len)
{
    if (f->eof)
    {
        *len = 0;
        return pdf_ok;
    }
    *len = pdf_aes_flush(f->state, buf);
    f->eof = 1;
    return pdf_ok;
}

pdf_err
pdf_filter_aes_e_new(pdf_filter **f, int n, int g, void *priv)
{
    pdfcrypto_priv *crypto = (pdfcrypto_priv *)priv;
    char final_key[256];
    void *ctx;
    unsigned char iv[16];
    unsigned int *piv = (unsigned int*)iv;

    piv[0] = rand();
    piv[1] = rand();
    piv[2] = rand();
    piv[3] = rand();

    *f = pdf_malloc(sizeof(pdf_filter));
    if (!(*f))
        return pdf_mem_err;

    pdf_crypto_obj_key_compute(crypto, n, g, final_key, crypto_key_len(crypto)/8);

    ctx = pdf_aes_e_new(final_key, crypto_key_len(crypto), iv);
    (*f)->state = (void*) ctx;
    (*f)->close = pdf_filter_aes_e_close;
    (*f)->read = pdf_filter_aes_read;
    (*f)->write = pdf_filter_aes_write;
    (*f)->flush = pdf_filter_aes_e_flush;
    (*f)->ptr = (*f)->buf;
    (*f)->eof = 0;
    (*f)->data = pdf_malloc(16); // iv
    memcpy((*f)->data, iv, 16);

    return pdf_ok;
}

// used for reading filter
struct rc4_state_s
{
    void *ctx; // openssl-CTX holder
    char buf[PDF_FILTER_BUF_SIZE], *ptr, *end;
};

static int
pdf_filter_aes_read(pdf_filter *f, unsigned char *obuf, int request)
{
    pdf_filter *up;
    int tmplen = 0, l;
    int max_request = PDF_FILTER_BUF_SIZE - 16; // seems buffer overflows(16 byte) from vpaes_cbc_encrypt

    int req = request;
    struct aes_state_s *s;

    if (!f)
        return 0;
    s = (struct aes_state_s *)f->state;

    if (s->ptr != s->end)
    {
        if (s->end - s->ptr < request)
        {
            int rd = s->end - s->ptr;
            memcpy(obuf, s->ptr, rd);
            s->ptr = s->end;
            return rd;
        }
        else
        {
            memcpy(obuf, s->ptr, request);
            s->ptr += request;
            return request;
        }
    }

    assert(s->ptr == s->end);
    s->ptr = s->buf; // reset buffer ptr

    up = f->next; // upstream
    // read upstream
  update_next:
    if (request <= 16)
    {
	    l = (up->read)(up, f->ptr, 16);
    }
    else
    {
	    l = (up->read)(up, f->ptr, (request < max_request)?request:max_request);
    }

    if (l == 0)
    {
        if (!s->eof)
        {
            l = pdf_aes_final_read(s->ctx, s->buf, PDF_FILTER_BUF_SIZE);
            assert(l <= PDF_FILTER_BUF_SIZE);
            if (l < request)
            {
                memcpy(obuf, s->buf, l);
                request = l;
            }
            else
            {
                memcpy(obuf, s->buf, request);
                s->ptr = s->buf + request;
                s->end = s->buf + l;
            }
            s->eof = 1;
        }
        else
            return 0;
    }
    else
    {
        l = pdf_aes_read(s->ctx, f->ptr, s->buf, l);
        if (l == 0)
            goto update_next;
        if (l <= request)
        {
            memcpy(obuf, s->buf, l);
            s->ptr = s->end;
            return l;
        }
        else
        {
            memcpy(obuf, s->buf, request);
            s->end = s->buf + l;
            s->ptr += request;
        }
    }

    return request;
}


// pdf arc4 decrypt cipher
static
pdf_err
pdf_filter_arc4_close(pdf_filter *f, int flag)
{
    struct rc4_state_s *s;
    s = (struct rc4_state_s *)f->state;

    if (s)
    {
        pdf_rc4_close(s->ctx, flag);
        pdf_free(s);
    }

    pdf_free(f);
    return pdf_ok;
}

static
int
pdf_filter_arc4_read(pdf_filter *f, unsigned char *obuf, int request)
{
    int         l;
    pdf_filter *up;
    struct rc4_state_s *s;

    s = (struct rc4_state_s *)f->state;

    up = f->next; // upstream

    l = (up->read)(up, f->ptr, (request < PDF_FILTER_BUF_SIZE)?request:PDF_FILTER_BUF_SIZE);

    return pdf_rc4_read(s->ctx, f->ptr, obuf, l);

}

// iv: initializing vector
pdf_filter *
pdf_cryptofilter_new(pdfcrypto_priv *crypto, int num, int gen, unsigned char *iv)
{
    unsigned int n;
    unsigned char final_key[256];
    pdf_filter *f = (pdf_filter *)pdf_malloc(sizeof(pdf_filter));

    if (!f)
        return NULL;

    memset(f, 0, sizeof(pdf_filter));

    n = crypto_key_len(crypto)/8;

    pdf_crypto_obj_key_compute(crypto, num, gen, final_key, n);

    // max 16 bytes of key
    if (n>16)
        n = 16;

    if (which_algo(crypto) == eRC4)
    {
        struct rc4_state_s *rc4;

        rc4 = (struct rc4_state_s *)pdf_malloc(sizeof(struct rc4_state_s));
        rc4->ctx = pdf_rc4_new(crypto_key_len(crypto), final_key);
        rc4->end = rc4->buf + PDF_FILTER_BUF_SIZE;
        rc4->ptr = rc4->end;
        f->state = (void*) rc4;


        f->state = (void*) rc4;
        f->close = pdf_filter_arc4_close;
        f->read = pdf_filter_arc4_read;
        f->ptr = f->buf;
    }
    else if (which_algo(crypto) == eAESV2 && crypto_key_len(crypto) > 40)
    {

        struct aes_state_s *aes;

        aes = (struct aes_state_s *)pdf_malloc(sizeof(struct aes_state_s));
        aes->ctx = pdf_aes_new(crypto_key_len(crypto), final_key, iv);
        aes->end = aes->buf + PDF_FILTER_BUF_SIZE;
        aes->ptr = aes->end;
        aes->eof = 0;
        f->state = (void*) aes;

        f->close = pdf_filter_aes_close;
        f->read = pdf_filter_aes_read;
        f->ptr = f->buf;
    }
    else
    {
        goto cf_fail;
    }
    return f;

  cf_fail:
    if (f)
        pdf_free(f);
    return NULL;

}

// pdf arc4 encrypt cipher
static
pdf_err
pdf_filter_arc4_e_close(pdf_filter *f, int flag)
{
    if (f && f->state)
    {
        pdf_rc4_close(f->state, flag);
    }

    return pdf_ok;
}

static int
pdf_filter_arc4_write(pdf_filter *f, unsigned char *ibuf, int request, int *written)
{
    *written = request;
    return pdf_rc4_write(f->state, ibuf, f->buf, request);
}

static
pdf_err
pdf_filter_arc4_e_flush(pdf_filter *f, char *buf, int *len)
{
    if (f->eof)
    {
        *len = 0;
        return pdf_ok;
    }
    *len = pdf_rc4_flush(f->state, buf);
    f->eof = 1;
    return pdf_ok;
}

pdf_err
pdf_filter_rc4_e_new(pdf_filter **f, int n, int g, void *priv)
{
    pdfcrypto_priv *crypto = (pdfcrypto_priv *)priv;
    char final_key[256];
    void *ctx;

    *f = pdf_malloc(sizeof(pdf_filter));
    if (!(*f))
        return pdf_mem_err;

    pdf_crypto_obj_key_compute(crypto, n, g, final_key, crypto_key_len(crypto)/8);

    ctx = pdf_rc4_new(crypto_key_len(crypto), final_key);

    (*f)->state = (void*) ctx;
    (*f)->close = pdf_filter_arc4_e_close;
    (*f)->read  = pdf_filter_arc4_read;
    (*f)->write = pdf_filter_arc4_write;
    (*f)->flush = pdf_filter_arc4_e_flush;
    (*f)->ptr   = (*f)->buf;
    (*f)->eof   = 0;

    return pdf_ok;
}

typedef struct pdf_predictor_s pdf_predictor;

struct pdf_predictor_s
{
    int   predictor;
    int   bpc;
    int   components;
    int   byte_per_pix;
    int   columns;
    int   stride;
    byte *row;
    byte *last_row;
};


#define I_ABS(a) \
    (a) < 0 ? -(a) : (a)

static inline byte
paeth(byte a, byte b, byte c)
{
    int p = a + b - c;
    int pa = I_ABS(p-a);
    int pb = I_ABS(p-b);
    int pc = I_ABS(p-c);

    if (pa <= pb && pa <= pc)
        return a;
    else if (pb <= pc)
        return b;
    else
        return c;
}

static void
filter_png(int predictor, int stride, byte *in, byte *out)
{
    int i;

    switch (predictor)
    {
        case 0:
            memcpy(out, in, stride);
            break;
        case 1:
            *out = *in;
            for (i = 1; i < stride; i++)
            {
                out[i] = out[i-1] + in[i];
            }
            break;
        case 2:
            for (i = 0; i < stride; i++)
            {
                out[i] = out[i] + in[i];
            }
            break;
        case 3:
            *out = *in;
            for (i = 1; i < stride; i++)
            {
                out[i] = (out[i] + in[i-1])/2 + in[i];
            }
            break;
        case 4:
        {
            byte t[2]; // rolling window

            t[0] = in[0] + paeth(0, out[0], 0);
            for (i = 1; i < stride; i++)
            {
                byte tt = in[i] + paeth(in[i-1], out[i], out[i-1]);
                out[i-1] = t[0];
                t[0] = t[1];
                t[1] = tt;
            }
        }
        break;
        default:
            fprintf(stderr, "PNG predictor algorithm is illegal");
            break;
    }
}

static int
pdf_predictor_read(pdf_filter *f, unsigned char *obuf, int request)
{
    int l, ret, in = 0;
    pdf_filter *up = f->next; // upstream
    pdf_predictor *p = (pdf_predictor*)f->state;
    int row = p->stride;
    byte *ptr = p->row;
    int remained;
    int stride = p->stride;


    if (f->eof && f->ptr == f->end)
        return 0;

  read_buffered:
    remained = f->end - f->ptr;
    if (f->ptr < f->end)
    {
        if  (request >= remained)
        {
            memcpy(obuf, f->ptr, remained);
            f->ptr = f->end;
            return remained;
        }
        else
        {
            memcpy(obuf, f->ptr, request);
            f->ptr += request;
            return request;
        }
    }

    assert(f->ptr == f->end);

    // +1 for png embedded predictor per row
    if (p->predictor >= 10 && p->predictor <= 15)
        row += 1;

    do
    {
        l = (up->read)(up, ptr, row);
        ptr += l;
        row -= l;
    } while (row && l);

    if (l == 0 && row)
    {
        f->eof = 1;
        stride -= row;
        if (stride <= 0)
        {
            return 0;
        }
    }

    switch (p->predictor)
    {
        case 1:
            fprintf(stderr, "Error, should not reach here\n");
            break;
        case 2:
            fprintf(stderr, "TIFF predictor is not implemented\n");
            break;
        case 10: case 11: case 12: case 13: case 14: case 15:
            filter_png(p->row[0], stride, p->row + 1, p->last_row);
            f->ptr = p->last_row;
            if (row)
                f->end = f->ptr + stride;
            break;
        default:
            break;
    }

    if (f->ptr < f->end)
        goto read_buffered;

    return 0;
}

static
pdf_err
pdf_predictor_close(pdf_filter *f, int flag)
{
    if (f && f->state)
    {
        pdf_predictor *state = (pdf_predictor*) f->state;;

        pdf_free(state->row);
        pdf_free(state->last_row);
        pdf_free(state);
        pdf_free(f);
   }

    return pdf_ok;
}


pdf_filter*
pdf_filter_predictor_new(decode_params *params, pdf_filter* last)
{
    pdf_predictor *state;
    pdf_filter *f = (pdf_filter *)pdf_malloc(sizeof(pdf_filter));

    if (!f)
        return NULL;

    memset(f, 0, sizeof(pdf_filter));

    state = pdf_malloc(sizeof(pdf_predictor));

    state->predictor = params->predictor;
    state->bpc = params->bitspercomponent;
    state->columns = params->columns;
    state->components = params->colors;

    state->stride = (state->bpc * state->components * state->columns + 7)/8;
    state->byte_per_pix = ((state->bpc + 7)/8 * state->components);
    state->row = pdf_malloc(state->stride + 1); // +1 for extra
                                                // predictor byte at
                                                // head of row
    state->last_row = pdf_malloc(state->stride + 1);
    memset(state->last_row, 0, state->stride + 1);


    f->ptr = f->end = state->last_row + state->stride;
    f->read = pdf_predictor_read;
    f->close = pdf_predictor_close;
    f->state = state;
    f->next = last;


    return f;
}
