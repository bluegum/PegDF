#include <stdio.h>
#include <string.h>
#include "pdftypes.h"
#include "pdfstream.h"

// super class functions in wrappers

size_t
pdf_stream_puth(unsigned char i, pdf_stream *s)
{
    static char _ascii_tab[16] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char tmp[2];
    tmp[0] = _ascii_tab[i >> 4];
    tmp[1] = _ascii_tab[i & 0x0f];
    return s->write(tmp, 2, s);
}

size_t
pdf_stream_puti(int i, pdf_stream *s)
{
    char tmp[128];
    sprintf(tmp, "%d", i);
    return s->write(tmp, strlen(tmp), s);
}

size_t
pdf_stream_putf(float i, pdf_stream *s)
{
    char tmp[128];
    sprintf(tmp, "%f", i);
    return s->write(tmp, strlen(tmp), s);
}

size_t
pdf_stream_puts(char *ptr, pdf_stream *s)
{
    return s->write(ptr, strlen(ptr), s);
}

size_t
pdf_stream_putc(char c, pdf_stream *s)
{
    return s->write(&c, 1, s);
}

size_t
pdf_stream_write(void *ptr, size_t size, pdf_stream *s)
{
    return s->write(ptr, size, s);
}

int
pdf_stream_getc(pdf_stream *s)
{
    if (s && s->getc)
        return (s->getc)(s);
    else
        return EOF;
}

size_t
pdf_stream_read(void *ptr, size_t size, pdf_stream *s)
{
    return s->read(ptr, size, s);
}

size_t
pdf_stream_getchar(pdf_stream *s)
{
    unsigned char c;
    if ((s->ffilter->read)(s->ffilter, &c, 1) == 0)
        return EOF;
    else
        return c;
}

int
pdf_stream_close(pdf_stream *s)
{
    int stat;
#if 0
    if (s->next)
        stat = pdf_stream_close(s->next);
#endif
    stat = s->close(s);
    pdf_free(s);
    return stat;
}

int
pdf_stream_flush(pdf_stream *s)
{
    int stat;
    stat = s->flush(s);
    return stat;
}

int
pdf_stream_tell(pdf_stream *s)
{
    if (s && s->next)
        return pdf_stream_tell(s->next);
    else if (s && s->tell)
        return s->tell(s);
    else
        return 0;
}

void
pdf_stream_chain(pdf_stream *head, pdf_stream *chain)
{
    head->next = chain;
}

int
pdf_stream_seekg(pdf_stream *s, int offset, int way)
{
    return s->seekg(s, offset, way);
}

int
pdf_stream_seekp(pdf_stream *s, int offset, int way)
{
    return s->seekp(s, offset, way);
}

////////////////////////////////////////////////////////////////////////
// Base stream
////////////////////////////////////////////////////////////////////////

static int
pdf_stream_base_seekg(pdf_stream *s, int offset, int way)
{
    return 1;
}

static int
pdf_stream_base_seekp(pdf_stream *s, int offset, int way)
{
    return 1;
}

static int
pdf_stream_base_getc(pdf_stream *s)
{
    return 1;
}

static int
pdf_stream_base_flush(pdf_stream *s)
{
    return 1;
}

static void
pdf_stream_base_init(pdf_stream *s)
{
    s->seekg = pdf_stream_base_seekg;
    s->seekp = pdf_stream_base_seekp;
    s->getc  = pdf_stream_base_getc;
    s->flush = pdf_stream_base_flush;
}

////////////////////////////////////////////////////////////////////////
// File stream
////////////////////////////////////////////////////////////////////////

static size_t
pdf_stream_file_read(void *ptr, size_t size, pdf_stream *s)
{
    FILE *f = (FILE*)s->state;
    return fread(ptr, 1, size, f);
}

static size_t
pdf_stream_file_write(void *ptr, size_t size, pdf_stream *s)
{
    FILE *f = (FILE*)s->state;
    return fwrite(ptr, 1, size, f);
}

static int
pdf_stream_file_flush(pdf_stream *s)
{
    FILE *f = (FILE*)s->state;
    return fflush(f);
}

static int
pdf_stream_file_close(pdf_stream *s)
{
    FILE *f = (FILE*)s->state;
    return fclose(f);
}

static int
pdf_stream_file_tell(pdf_stream *s)
{
    FILE *f = (FILE*)s->state;
    return ftell(f);
}

static int
pdf_stream_file_seek(pdf_stream *s, int offset, int whence)
{
    FILE *f = (FILE*)s->state;
    switch (whence)
    {
        case S_SEEK_BEG:
            return fseek(f, offset, SEEK_SET);
            break;
        case S_SEEK_CUR:
            return fseek(f, offset, SEEK_CUR);
            break;
        case S_SEEK_END:
            return fseek(f, offset, SEEK_END);
            break;
        default:
            break;
    }
    return 1;
}

pdf_stream*
pdf_stream_file_open(char *ofile)
{
    pdf_stream *s;
    FILE *f;

#ifdef DEBUG
    printf("Writing %s..\n", ofile);
#endif

    f = fopen(ofile, "wb");
    if (!f)
        return 0;

    s = pdf_malloc(sizeof(pdf_stream));
    if (!s)
        return 0;

    memset(s, 0, sizeof(pdf_stream));
    pdf_stream_base_init(s);
    s->state = (void*) f;
    s->close = pdf_stream_file_close;
    s->write = pdf_stream_file_write;
    s->read = pdf_stream_file_read;
    s->tell = pdf_stream_file_tell;
    s->seekg = pdf_stream_file_seek;
    s->seekp = pdf_stream_file_seek;
    s->flush = pdf_stream_file_flush;
    return s;
}

////////////////////////////////////////////////////////////////////////
// Buffer stream
////////////////////////////////////////////////////////////////////////

#define PDF_STREAM_BUFFER_CHUNK 1024
#define PDF_STREAM_BUFFER_EOF(s)   ((s)->ptop == (s)->gptr)

typedef struct stream_buffer_s stream_buffer;

struct stream_buffer_s
{
    byte *buf;
    byte *gcur, *limit, *ptop;
    stream_buffer *next;
};

typedef struct pdf_buffer_stream_s
{
    _PDF_STREAM_STRUCT_
    stream_buffer *buf, *active;
    int gptr, pptr, ptop;
    int count;
} pdf_buffer_stream;

static int
pdf_stream_buffer_seekg(pdf_stream *sb, int offset, int way)
{
    pdf_buffer_stream *s = (pdf_buffer_stream*)sb;
    stream_buffer *f = s->active;

    switch (way)
    {
        case S_SEEK_CUR:
            break;
        case S_SEEK_BEG:
            s->active = s->buf;
            f = s->active;
            s->gptr = offset;
            if (offset > 0)
            {
                while (f && (offset > f->ptop - f->buf))
                {
                    f = f->next;
                }
                if (!f)
                    return 1;
                s->active = f;
                f->gcur = f->buf + (s->gptr % PDF_STREAM_BUFFER_CHUNK);
            }
            else if (offset < 0)
            {
                return 1;
            }
            break;
        case S_SEEK_END:
            s->ptop = 0;
            break;
        default:
            return 1;
            break;
    }
    return 0;
}

static size_t
pdf_stream_buffer_read(void *ptr, size_t size, pdf_stream *sb)
{
    pdf_buffer_stream *s = (pdf_buffer_stream*)sb;
    stream_buffer *f = s->active;

    if (!f)
        return 0;

    size = size < (f->ptop - f->gcur) ? size : (f->ptop - f->gcur);
    memcpy(ptr, f->gcur, size);
    f->gcur += size;
    if (f->gcur == f->ptop)
        s->active = f->next;
    return size;
}

int
pdf_stream_buffer_getc(pdf_stream *sb)
{
    pdf_buffer_stream *s = (pdf_buffer_stream*)sb;
    stream_buffer *f = s->active;

  again:
    if (!f)
        return EOF;
    if (PDF_STREAM_BUFFER_EOF(s))
        return EOF;

    if (f->gcur < f->ptop)
    {
        s->gptr++;
        return *f->gcur++;
    }
    else
    {
        if (f->ptop == f->limit)
        {
            f = f->next;
            s->active = f;
            goto again;
        }
        else
        {
            return EOF;
        }
    }

}

static void
pdf_stream_buffer_grow(pdf_stream *sb)
{
    pdf_buffer_stream *s = (pdf_buffer_stream*)sb;
    stream_buffer *f = (stream_buffer*)pdf_malloc(sizeof(stream_buffer));;

    f->buf = pdf_malloc(PDF_STREAM_BUFFER_CHUNK);
    f->ptop = f->buf;
    f->gcur = f->buf;
    f->limit = f->buf + PDF_STREAM_BUFFER_CHUNK;
    f->next = 0;
    s->active->next = f;
    s->active = f;
}

static size_t
pdf_stream_buffer_write(void *ptr, size_t size, pdf_stream *sb)
{
    char *p = (char *)ptr;
    pdf_buffer_stream *s = (pdf_buffer_stream*)sb;
    stream_buffer *f = s->active;
    int sz = size;
  again:
    while (size &&  f->ptop < f->limit)
    {
        *f->ptop++ = *p++;
        size--;
    }
    if (size)
    {
        pdf_stream_buffer_grow(sb);
        f = (stream_buffer*)s->active;
        goto again;
    }
    s->pptr += sz;
    if (s->pptr >= s->ptop)
        s->ptop = s->pptr;
    return sz;
}

static int
pdf_stream_buffer_close(pdf_stream *bs)
{
    pdf_buffer_stream *s = (pdf_buffer_stream*)bs;
    stream_buffer *p = s->buf;
    while (p)
    {
        stream_buffer *t = p->next;
        pdf_free(p->buf);
        pdf_free(p);
        p = t;
    }
    return 0;
}

static int
pdf_stream_buffer_flush(pdf_stream *bs)
{
    pdf_buffer_stream *s = (pdf_buffer_stream*)bs;
    stream_buffer *p = s->buf;
    // todo

    return 0;
}

static int
pdf_stream_buffer_tell(pdf_stream *ss)
{
    pdf_buffer_stream *s = (pdf_buffer_stream*)ss;
    return s->ptop;
}

static int
pdf_stream_buffer_seekp(pdf_stream *s, int offset, int way)
{
    return 1;
}

pdf_stream*
pdf_stream_buffer_open()
{
    pdf_buffer_stream *s;
    stream_buffer *buf;

    s = (pdf_buffer_stream*)pdf_malloc(sizeof(pdf_buffer_stream));
    if (!s)
        return 0;
    memset(s, 0, sizeof(pdf_buffer_stream));

    buf = (stream_buffer*)pdf_malloc(sizeof(stream_buffer));
    if (!buf)
        return 0;
    memset(buf, 0, sizeof(stream_buffer));
    pdf_stream_base_init((pdf_stream*)s);
    buf->buf = (byte*)pdf_malloc(PDF_STREAM_BUFFER_CHUNK);
    buf->limit = buf->buf + PDF_STREAM_BUFFER_CHUNK;
    buf->gcur = buf->buf;
    buf->ptop = buf->buf;
    buf->next = 0;
    s->buf = buf;
    s->active = buf;

    s->close = pdf_stream_buffer_close;
    s->write = pdf_stream_buffer_write;
    s->read  = pdf_stream_buffer_read;
    s->getc  = pdf_stream_buffer_getc;
    s->tell  = pdf_stream_buffer_tell;
    s->seekg = pdf_stream_buffer_seekg;
    s->seekp = pdf_stream_buffer_seekp;
    s->flush = pdf_stream_buffer_flush;
    return (pdf_stream*)s;
}


////////////////////////////////////////////////////////////////////////
// Filter stream
////////////////////////////////////////////////////////////////////////

typedef struct pdf_stream_filtered_s
{
    _PDF_STREAM_STRUCT_
    pdf_filter *filter;
} pdf_stream_filtered;


static int
pdf_istream_filtered_close(pdf_stream *sf)
{
    pdf_stream_filtered *s = (pdf_stream_filtered*)sf;
    return 0;
}

pdf_stream*
pdf_istream_filtered_open(pdf_filterkind f)
{
    return 0;
}


static size_t
pdf_ostream_filtered_write(void *ptr, size_t size, pdf_stream *sf)
{
    pdf_stream_filtered *s = (pdf_stream_filtered*)sf;
    pdf_filter *f = s->filter;
    int osize;

    osize = f->write(f, ptr, size);
    if (!osize)
        return size;
    if (s->next)
        pdf_stream_write(f->buf, osize, s->next);

    do
    {
        osize = f->write(f, 0, 0);
        if (osize && s->next)
        {
            pdf_stream_write(f->buf, osize, s->next);
        }
    }
    while (osize);
    return size;
}

static int
pdf_ostream_filtered_close(pdf_stream *sf)
{
    pdf_stream_filtered *s = (pdf_stream_filtered*)sf;
    pdf_filter *f = s->filter;

    f->close(f, 0);
    pdf_free(f);
    return 0;
}

static int
pdf_ostream_filtered_flush(pdf_stream *sf)
{
    pdf_stream_filtered *s = (pdf_stream_filtered*)sf;
    pdf_filter          *f = s->filter;
    int                  remain;
    unsigned char        buf[1024];

    // to flush
    do
    {
        remain = 1024;
        f->flush(f, buf, &remain);
        if (remain && s->next)
            pdf_stream_write(buf, remain, s->next);
    }
    while (remain);

    return 0;
}

pdf_stream*
pdf_ostream_filtered_open(pdf_filterkind f)
{
    pdf_stream_filtered *s;
    pdf_filter *filt;

    s = (pdf_stream_filtered*)pdf_malloc(sizeof(pdf_stream_filtered));
    if (!s)
        return 0;
    memset(s, 0, sizeof(pdf_stream_filtered));
    s->write = pdf_ostream_filtered_write;
    s->close = pdf_ostream_filtered_close;
    s->flush = pdf_ostream_filtered_flush;
    switch (f)
    {
        case FlateEncode:
            if (pdf_deflate_new(&filt) != pdf_ok)
            {
                pdf_free(s);
                s = 0;
                break;
            }
            s->filter = filt;
            break;
        case RC4Encrypt:
            break;
        case AESEncrypt:
            break;
        default:
            break;
    }

    return (pdf_stream*)s;
}
