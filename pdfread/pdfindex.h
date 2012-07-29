#ifndef PDFINDEX_H
#define PDFINDEX_H
#include "bplustree.h"
#include "pdftypes.h"

typedef struct pdf_map_s pdf_map;

struct pdf_map_s
{
      int generation;
      bpt_tree *head;
      pdf_map * next;
};

extern int pdf_obj_insert(int n, int gen, void *d);
extern void pdf_obj_walk();
extern pdf_obj *pdf_obj_find(int n, int gen);
extern void pdf_obj_free();
extern void pdf_obj_delete(pdf_obj *o);
extern pdf_map * pdf_map_create();
extern void pdf_map_delete(pdf_map*);

#define pdf_obj_resolve(o)                                              \
      if ((o)->t == eRef) (o) = pdf_obj_find((o)->value.r.num, (o)->value.r.gen)

#endif
