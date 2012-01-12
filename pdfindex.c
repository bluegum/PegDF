#include <stdlib.h>
#include <string.h>
#include "bplustree.h"

typedef struct pdf_map
{
   int generation;
   bp_tree *head; 
   struct pdf_map * next;
} pdf_map;

static pdf_map a_pdf_map;

pdf_map *
pdf_map_create()
{
   pdf_map * m = malloc(sizeof(pdf_map));
   memset(m, 0, sizeof(pdf_map));
   return m;
}

void
pdf_map_destroy(pdf_map *m)
{
   pdf_map *i = m;
   for (; i!=0; i=i->next)
   {
      /* delete obj tree */
      bp_destroy(i->head);
   }
}

pdf_map *
pdf_map_insert(int gen)
{
   pdf_map * m = &a_pdf_map;
   while (m->generation != gen)
   {
      m = m->next;
   }
   if (!m)
   {
      m = pdf_map_create;
   }
   if (!m->head)
   {
      m->head = bp_new_tree();
   }
   return m;
}

pdf_map *
pdf_map_find(int gen)
{
   return &a_pdf_map;
}

int
pdf_obj_insert(int n, int gen, void *d)
{
   pdf_map *m = pdf_map_insert(gen);
   bp_insert(m->head, n, d);
   return 0;
}

void *
pdf_obj_find(int n, int gen)
{
   pdf_map *m = pdf_map_find(gen);
   return bp_search(m->head, n);
}
