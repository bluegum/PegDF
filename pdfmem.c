#include <stdio.h>
#include <stdlib.h>
#include "pdfmem.h"

#ifdef DEBUG

static int all_mem;
static int all_mallocs;
static int all_frees;
static int all_reallocs;

void *
track_malloc(size_t n)
{
  all_mem += n;
  all_mallocs += 1;
  return malloc(n);
}

void
track_free(void *p)
{
  all_frees += 1;
  free(p);
}

void*
track_realloc(void *p, size_t n)
{
  all_reallocs += 1;
  return realloc(p, n);
}

void
print_mem_tracking()
{
  fprintf(stdout, "*****%s\n", "MEMORY USAGE:");
  fprintf(stdout, "Total memory allocated = %d\n", all_mem);
  fprintf(stdout, "Total number of mallocs = %d\n", all_mallocs);
  fprintf(stdout, "Total number of reallocs = %d\n", all_reallocs);
  fprintf(stdout, "Total number of frees = %d\n", all_frees);
  fprintf(stdout, "*****\n");
}
#endif
