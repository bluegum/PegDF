#include <string.h>
#include "pdfstream.h"

size_t
pdf_stream_write(void *ptr, size_t size, pdf_stream *s)
{
    return s->write(ptr, size, s);
}
size_t
pdf_stream_read(void *ptr, size_t size, pdf_stream *s)
{
    return s->read(ptr, size, s);
}

int
pdf_stream_close(pdf_stream *s)
{
    return s->close(s);
}
void
pdf_stream_chain(pdf_stream *head, pdf_stream *chain)
{
    head->next = chain;
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
pdf_stream_file_close(pdf_stream *s)
{
    FILE *f = (FILE*)s->state;
    return fclose(f);
}

pdf_stream*
pdf_stream_file_open(FILE *f)
{
    pdf_stream *s;

    s = pdf_malloc(sizeof(pdf_stream));
    if (!s)
        return 0;
    memset(s, 0, sizeof(pdf_stream));
    s->state = (void*) f;
    s->close = pdf_stream_file_close;
    s->write = pdf_stream_file_write;
    s->read = pdf_stream_file_read;
    return s;
}
