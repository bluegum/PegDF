#ifndef PDFSTREAM_H
#define PDFSTREAM_H
#include <stdio.h>
#include "pdffilter.h"

typedef struct pdf_stream_s pdf_stream;

struct pdf_stream_s
{
	// apis
	int (*close)(pdf_stream*);
    size_t (*write)(void *ptr, size_t size, pdf_stream *s);
    size_t (*read)(void *ptr, size_t size, pdf_stream *s);
    // private data
    int length;
    void *decodeparms;
    void *f;
    pdf_filter *ffilter; // filter train
    void *fdecodeparms;
    int dl;
    // private
    pdf_stream *next;
    void *state;
};

size_t pdf_stream_write(void *ptr, size_t size, pdf_stream *s);
size_t pdf_stream_read(void *ptr, size_t size, pdf_stream *s);
int    pdf_stream_close(pdf_stream *s);
void   pdf_stream_chain(pdf_stream *head, pdf_stream *chain);
pdf_stream* pdf_stream_file_open(FILE *);

#endif
