#include <stdio.h>
#include <assert.h>
#include "zlib.h"
#include "pdftypes.h"
#include "pdfmem.h"
#include "pdffilter.h"
#include "pdfdoc.h"
#include "pdfread.h"
#include "lzw_decomp.h"


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
pdf_filter_base_flush(pdf_filter *f, char *buf, int *len)
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
pdf_deflate_write(pdf_filter *f, unsigned char *in, int request)
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
pdf_deflate_flush(pdf_filter *f, char *buf, int *len)
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

/////////////////////////////////////////// ASCII85Decode
struct pdf_a85d_s
{
    unsigned char bp[4];
    unsigned char *rp, *wp;
    int eod;
};

pdf_err
pdf_a85d_close(pdf_filter *f)
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
pdf_lzw_d_close(pdf_filter *f)
{
    int ret;
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
        case ASCII85Decode:
            pdf_a85d_new(&f);
            break;
        case LZWDecode:
            pdf_lzw_d_new(&f, last);
            break;
        default:
            return NULL;
    }
    return f;
}
