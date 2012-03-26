#ifndef PDFINDEX_H
#define PDFINDEX_H
#include "pdftypes.h"

extern int pdf_obj_insert(int n, int gen, void *d);
extern void pdf_obj_walk();
extern pdf_obj *pdf_obj_find(int n, int gen);


#endif
