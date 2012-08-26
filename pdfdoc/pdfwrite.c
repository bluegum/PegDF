#include <stdio.h>
#include "dict.h"
#include "pdffilter.h"
#include "pdfindex.h"
#include "pdfdoc.h"

typedef
struct pdf_xref_entry_internal_s
{
      int num;
      int gen;
      int used;
}pdf_xref_entry_internal;
typedef
struct pdf_xref_internal_s
{
      int n;
      pdf_xref_entry_internal entry[1];
} pdf_xref_internal;

static
pdf_xref_internal*
pdf_xref_internal_create()
{
      pdf_xref_internal* x;
      x = pdf_malloc(sizeof(pdf_xref_internal)+sizeof(pdf_xref_entry_internal)*128);
      x->n = 0;
      return x;
}

static
void
pdf_write_xref(pdf_doc *doc, FILE *of)
{
}

static
void
pdf_scan_resources(pdf_resources *r, pdf_xref_internal* x)
{
      if (r->extgstate)
      {
      }
      if (r->font)
      {
      }
}

static void
pdf_print_obj(pdf_obj* o, FILE *f)
{
      if (!o)
	    return;
      switch (o->t)
      {
	    case eInt:
		  fprintf(f, "%d ", o->value.i);
		  break;
	    default:
		  break;
      }
}

static
void
pdf_write_resources(pdf_resources *r, FILE *o)
{
      if (r->extgstate)
      {
	    dict_list *ll, *l = dict_to_list(r->extgstate->value.d);
	    ll = l;
	    while (l && l->key)
	    {
		  pdf_obj *t = &l->val;
		  dict_array *a;
		  if (t->t == eRef)
			pdf_obj_resolve(t);
		  a = dict_to_array(t->value.d);
		  fprintf(o, "%s", "<<");
		  if (a)
		  {
			// print dict array "a"
			if (a->items)
			{
			      int i;
			      for (i = 0; i < a->cur; i++)
			      {
				    fprintf(o, "/%s ",a->items[i].key);
				    pdf_print_obj(&a->items[i].val, o);
			      }
			}
			// free array/dict_entry
			if (a->items)
			{
			      int i;
			      for (i = 0; i < a->cur; i++)
				    pdf_free(a->items[i].key);
			      pdf_free(a->items);
			}
			pdf_free(a);
		  }
		  fprintf(o, "%s", ">>");
		  l = l->next;
	    }
	    // free dict_list
	    l = ll;
	    while (l)
	    {
		  dict_list *t = l->next;
		  if (l && l->key)
			pdf_free(l->key);
		  pdf_free(l);
		  l = t;
	    }
      }
}

static
void
pdf_scan_page(pdf_page* pg, pdf_xref_internal* x)
{
      if (pg->resources)
      {
	    pdf_scan_resources(pg->resources, x);
      }
      if (pg->group)
      {
      }
      if (pg->contents)
      {
      }
}

pdf_err
pdf_write_pdf(pdf_doc *doc, char *ofile, int version, int pg1st, int pglast, char *upw, char *opw)
{
      FILE* out;
      char linebuf[1024];
      int i;
      pdf_xref_internal *xref;

      if (pg1st < 1)
	    pg1st = 1;
      if (pglast < pg1st)
	    pglast = pg1st;
      if (!ofile)
	    return pdf_ok;
      out = fopen(ofile, "wb");
      if (!out)
	    return pdf_ok;
      sprintf(linebuf, "%%%%PDF-%d.%d\n", version/10, version%10);
      fputs(linebuf, out);
      fputs("%%\333\332\331\330\n", out);
      // scan pages
      xref = pdf_xref_internal_create();
      if (!xref)
	    goto done;
      if (pglast < 0)
	    pglast = doc->count;
      for (i = pg1st-1; i <= pglast-1; i++)
      {
	    pdf_scan_page(doc->pages[i], xref);
	    if (doc->pages[i]->resources)
	    {
		  pdf_write_resources(doc->pages[i]->resources, out);
	    }
      }
      // write xref table
      pdf_write_xref(doc, out);
      // done
  done:
      if (xref)
	    pdf_free(xref);
      fclose(out);
      return pdf_ok;
}
