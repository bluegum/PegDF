#ifndef PDFSTREAM_H
#define PDFSTREAM_H

#include "pdffilter.h"

#define S_SEEK_BEG 0
#define S_SEEK_CUR 1
#define S_SEEK_END 2

typedef struct pdf_stream_s pdf_stream;

#define _PDF_STREAM_STRUCT_ \
	/* apis */                     \
	int    (*close)(pdf_stream*); \
    int    (*flush)(pdf_stream *s); \
    size_t (*write)(char *ptr, size_t size, pdf_stream *s); \
    size_t (*read)(void *ptr, size_t size, pdf_stream *s);  \
    int    (*getc)(pdf_stream *s);  \
    int    (*tell)(pdf_stream *s); \
    int    (*seekp)(pdf_stream *s, int offset, int way);    \
    int    (*seekg)(pdf_stream *s, int offset, int way);    \
    /* private data */             \
    int    length; \
    void  *decodeparms; \
    void  *f; \
    void  *fdecodeparms; \
    int    dl; \
    /* private */  \
    void  *state; \
    pdf_stream *next; \
    pdf_filter *ffilter; /* filter train */

struct pdf_stream_s
{
    _PDF_STREAM_STRUCT_
};

extern size_t pdf_stream_putf(float, pdf_stream*);
extern size_t pdf_stream_puti(int, pdf_stream*);
extern size_t pdf_stream_puth(unsigned char i, pdf_stream *s);
extern size_t pdf_stream_puts(char *ptr, pdf_stream *s);
extern size_t pdf_stream_putc(char c, pdf_stream *s);
extern size_t pdf_stream_write(void *ptr, size_t size, pdf_stream *s);
extern size_t pdf_stream_read(void *ptr, size_t size, pdf_stream *s);
extern size_t pdf_stream_buffer_size(pdf_stream*);
extern int    pdf_stream_seekg(pdf_stream *s, int offset, int way);
extern int    pdf_stream_seekp(pdf_stream *s, int offset, int way);
extern int    pdf_stream_tell(pdf_stream*);
extern int    pdf_stream_getc(pdf_stream *s);
extern int    pdf_stream_flush(pdf_stream *s);
extern int    pdf_stream_close(pdf_stream *s);
extern void   pdf_stream_chain(pdf_stream *head, pdf_stream *chain);
extern pdf_stream* pdf_stream_file_open(char *);
extern pdf_stream* pdf_istream_filted_open(pdf_filterkind);
extern pdf_stream* pdf_ostream_filted_open(pdf_filterkind, void *);
extern pdf_stream* pdf_stream_buffer_open();
extern pdf_err pdf_stream_free(pdf_stream *s, int flag); // flag: for in_mem stream, 1 to free
pdf_stream*
pdf_istream_filtered_load(pdf_obj* o, void *crypto, int numobj, int numgen);

#endif
