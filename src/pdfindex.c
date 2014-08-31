#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bplustree.h"
#include "pdfindex.h"
#include "pdfmem.h"
#include "pdfread.h"
#include "pdffilter.h"
#include "pdfdoc.h"

extern pdf_parser *parser_inst;

pdf_map *
pdf_map_create()
{
      pdf_map * m = pdf_malloc(sizeof(pdf_map));
      if (m)
            memset(m, 0, sizeof(pdf_map));
      return m;
}

void
pdf_map_delete(pdf_map *m)
{
      pdf_map *t = m;
      while (m)
      {
            t = m->next;
            pdf_free(m);
            m = t;
      }
}

pdf_map *
pdf_map_insert(int n, int gen)
{
      pdf_map * m = parser_inst->map;
      while (m->generation != gen)
      {
	    if (!m->next)
	    {
		 m->next = pdf_map_create();
		 m->next->generation = gen;
	    }
            m = m->next;
      }
      if (!m)
      {
            m = pdf_map_create();
      }
      if (!m->head)
      {
            m->head = bpt_new_tree(n);
      }
      return m;
}

pdf_map *
pdf_map_find(int gen)
{
      pdf_map *m = parser_inst->map;
      while (m)
      {
	    if (m->generation == gen)
		  return m;
	    else
		  m = m->next;
      }

	  return m;
}

int
pdf_obj_insert(int n, int gen, void *d)
{
      pdf_map *m = pdf_map_insert(n, gen);
      pdf_obj *o = NULL;
      if (o = pdf_obj_find(n, gen))
      {
	    char buf[128];
	    sprintf(buf, "Duplicated object (%d,%d) is found, old one is removed!\n", n, gen);
	    DMSG(buf);
	    pdf_obj_delete(o);
	    pdf_free(o);
      }
      bpt_insert(m->head, n, d);
      return 0;
}

pdf_obj *
pdf_obj_find(int n, int gen)
{
      pdf_map *m = pdf_map_find(gen);
      return (pdf_obj*)bpt_search(m->head, n);
}

void
pdf_obj_walk()
{
      pdf_map * m = parser_inst->map;//&a_pdf_map;
      for (;m; m = m->next)
      {
            bpt_walk(m->head, NULL);
      }
}

void free_array(pdf_obj *o)
{
      if (o && o->t == eArray)
      {
            int i;
            for (i = 0; i < o->value.a.len; i++)
            {
                  pdf_obj_delete(&o->value.a.items[i]);
            }
            if (o->value.a.len)
                  pdf_free(o->value.a.items);
	    //else if (o->value.a.items)
	    //	  pdf_free(o->value.a.items);
      }
}

// Remove a single obj
void
pdf_obj_delete(pdf_obj *o)
{
      if (!o)
            return;
      switch(o->t)
      {
            case eDict:
                  dict_free(o->value.d.dict);
                  break;
            case eString:
            case eHexString:
                  pdf_free(o->value.s.buf);
                  break;
            case eName:
#ifndef HASHMAP
                pdf_free(o->value.k);
#endif
                break;
            case eArray:
                  free_array(o);
                  break;
            default:
                  break;
      }
}

void
pdf_obj_free()
{
	  pdf_map * m = parser_inst->map;//&a_pdf_map;
      pdf_map *i = m;

	  if (!parser_inst && !parser_inst->map)
		  return;

	  for (; i != 0; i = i->next)
      {
            /* delete obj tree nodes */
            bpt_delete_node(i->head, (leaf_action)pdf_obj_delete);
      }
      i = m;
      for (; i!=0; i=i->next)
      {
            /* delete obj tree */
            bpt_destroy(i->head);
            pdf_free(i->head);
      }
}

int
pdf_obj_count()
{
      int c = 0;
      pdf_map * i = parser_inst->map;
      for (; i!=0; i=i->next)
      {
            c += bpt_count_leaf(i->head);
      }
      return c;
}
