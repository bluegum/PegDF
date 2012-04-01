#ifndef PDFMEM_H
#define PDFMEM_H
#include <stdlib.h>

#ifdef DEBUG
#define pdf_malloc track_malloc
#define pdf_free track_free
#define pdf_realloc track_realloc

extern void * track_malloc(size_t n);
extern void track_free(void *p);
extern void* track_realloc(void *p, size_t n);
extern void print_mem_tracking();
#else
#define pdf_malloc malloc
#define pdf_free free
#define pdf_realloc realloc
#endif

#endif
