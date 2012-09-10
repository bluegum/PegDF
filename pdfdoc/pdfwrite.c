#include <stdio.h>
#include "bplustree.h"
#include "dict.h"
#include "pdffilter.h"
#include "pdfindex.h"
#include "pdfdoc.h"
#include "pdfread.h"

// We borrow the term "Mark&Sweep" as 2 stages
// in #1.scanning pdf object for writing, stored in a tree structure and
// #2. Sweep the tree, and re-generate ref-ids and stream offsets.

typedef struct pdf_xref_internal_s pdf_xref_internal;
typedef struct pdf_xref_table_s pdf_xref_table;

struct pdf_xref_internal_s
{
      int n;
      int gen;
      bpt_tree *entry; // storing scanned objects
      pdf_xref_table *xref;
      int page_obj_idx;
      int page_obj_buf[10240];
      int *page_ref_buf;
};

// pdf_xref_table stores the artifects of object writing. to be written out as new xref table.
struct pdf_xref_table_s
{
      int n; // total number of entries
      int cur; // index to current entry
      int *offsets;
};

static
pdf_xref_internal*
pdf_xref_internal_create(int n, int npages)
{
      pdf_xref_internal* x;
      if (!n)
            return NULL;
      n ++;
      x = pdf_malloc(sizeof(pdf_xref_internal));
      memset(x, 0, sizeof(pdf_xref_internal));
      x->n = 0;
      x->entry = bpt_new_tree(0);
      // make xref table
      x->xref = pdf_malloc(sizeof(pdf_xref_table));
      x->xref->n = n;
      x->xref->cur = 1;
      x->xref->offsets = pdf_malloc(sizeof(int)*n);
      x->page_ref_buf = pdf_malloc(sizeof(int)*npages);
      return x;
}

static
void
pdf_xref_internal_free(pdf_xref_internal *x)
{
      if (!x)
            return;
      if (x->entry)
      {
            bpt_node_free(x->entry->root);
            pdf_free(x->entry);
      }
      if (x->xref->offsets)
      {
            pdf_free(x->xref->offsets);
            pdf_free(x->xref);
      }
      if (x->page_ref_buf)
	    pdf_free(x->page_ref_buf);
      pdf_free(x);
}

static
pdf_xref_internal *
pdf_xref_internal_append(pdf_xref_internal *x, int n, int g)
{
      // ignore generation number for now.
      int a;
      a = bpt_search(x->entry, n);
      if (a == 0)
      {
	    bpt_insert(x->entry, n, -1);
	    x->n += 1;
      }
      return x;
}

static
void
pdf_catalog_write(pdf_xref_internal *x, FILE *o)
{
      x->xref->cur = 2;
      x->xref->offsets[x->xref->cur] = ftell(o);
      fprintf(o, "%d %d obj\n", 2, 0);
      fprintf(o, "%s\n", "<<");
      fprintf(o, "%s\n", "/Type /Catalog");
      fprintf(o, "/Pages %d %d R\n",1, 0);
      fprintf(o, "%s\n", ">>");
      fprintf(o, "%s\n", "endobj");
      x->xref->cur ++;
}

static
void
pdf_pages_obj_write(pdf_xref_internal *x, int pg1st, int num, FILE *o)
{
      int i;
      x->xref->offsets[1] = ftell(o);
      fprintf(o, "%d %d obj\n", 1, 0);
      fprintf(o, "%s\n", "<<");
      fprintf(o, "%s\n", "/Type /Pages");
      fprintf(o, "/Count %d\n", num);
      fprintf(o, "/Kids [\n");
      for (i = 0; i < num; i++)
      {
	    fprintf(o, "%d %d R\n", x->page_ref_buf[i+pg1st], 0);
      }
      fprintf(o, "]\n");
      fprintf(o, "%s\n", ">>");
      fprintf(o, "%s\n", "endobj");
}

static
int
pdf_xref_write(pdf_xref_internal *x, FILE *o)
{
      int i, startxref;
      startxref = ftell(o);
      fprintf(o, "%s\n", "xref");
      fprintf(o, "%d %d\n", 0, x->xref->cur);
      fprintf(o, "%010d %05d f \n", 0, 65535);
      for (i = 1; i < x->xref->cur; i++)
      {
            fprintf(o, "%010d %05d n \n", x->xref->offsets[i], 0);
      }
      return startxref;
}

static
void
pdf_trailer_write(pdf_xref_internal *x, int startxref, FILE *o)
{
      fprintf(o, "%s\n", "trailer");
      fprintf(o, "%s\n", "<<");
      fprintf(o, "/Size %d\n", x->xref->cur);
      fprintf(o, "/Root %d %d R\n", 2, 0);
      fprintf(o, "%s\n", ">>");
      fprintf(o, "%s\n", "startxref");
      fprintf(o, "%d\n", startxref);
      fprintf(o, "%s\n", "%%EOF");
}

static void
pdf_write_obj(pdf_obj* o, pdf_xref_internal *x, FILE *f)
{
      int i;
      if (!o)
            return;
      switch (o->t)
      {
            case eBool:
                  fprintf(f, "%s ", o->value.b?"true":"false");
                  break;
            case eInt:
                  fprintf(f, "%d ", o->value.i);
                  break;
            case eReal:
                  fprintf(f, "%f ", o->value.f);
                  break;
            case eKey:
                  fprintf(f, "/%s ", o->value.k);
                  break;
            case eString:
                  fprintf(f, "%s", "(");
                  for (i = 0; i < o->value.s.len; i ++)
                        fprintf(f, "%c", o->value.s.buf[i]);
                  fprintf(f, "%s", ")");
                  break;
            case eDict:
            {
                  dict_list *ll, *l = dict_to_list(o->value.d.dict);
		  sub_stream *strm = NULL;
		  int strmlen = 0;
                  ll = l;
                  fprintf(f, "%s", "<<");
                  while (l && l->key)
                  {
			if (l->key[0] == 'S' && l->key[1] == '_' && l->key[2] == 'O')
			{
			      strm = l->val.value.i;
			      l = l->next;
			      continue;
			}
			else if (strcmp(l->key, "Length")==0)
			{
			      if (l->val.t == eRef)
			      {
				    pdf_obj *ooo = &l->val;
				    pdf_obj_resolve(ooo);
				    if (ooo->t == eInt)
				    {
					  strmlen = ooo->value.i;
				    }
			      }
			      else
			      {
				    strmlen = l->val.value.i;
			      }
			      fprintf(f, "/Length %d\n", strmlen);
			      l = l->next;
			      continue;
			}
                        fprintf(f, "/%s ", l->key);
                        pdf_write_obj(&l->val, x, f);
                        fprintf(f, "%s", "\n");
                        l = l->next;
                  }
                  fprintf(f, "%s", ">>");
		  if (strm)
		  {
			int c;
			fprintf(f, "%s\n", "stream");
			strm->len = strmlen;
			while (strm->read(strm, &c, 1))
			      fputc(c, f);
			strm->close(strm);
			fprintf(f, "\n%s\n", "endstream");
		  }
                  dict_list_free(ll);
            }
            break;
            case eArray:
            {
                  int i;
                  fprintf(f, "%s", "[");
                  for (i = 0; i < o->value.a.len; i++)
                  {
                        pdf_write_obj(&o->value.a.items[i], x, f);
                  }
                  fprintf(f, "%s", "]");
            }
            break;
            case eRef:
            {
                  int a = bpt_search(x->entry, o->value.r.num);
                  if (a <= 0)
                        fprintf(f, "%d %d R ", o->value.r.num, o->value.r.gen);
                  else
                        fprintf(f, "%d %d R ", a, o->value.r.gen);
            }
            break;
            default:
                  break;
      }
}

static
int
pdf_write_contents(pdf_obj *c, pdf_xref_internal *xref, FILE *out)
{
      int content_ref = xref->xref->cur;
      int off = ftell(out);
      fprintf(out, "%d 0 obj\n", xref->xref->cur);
      pdf_write_obj(c, xref, out);
      fprintf(out, "%s\n", "endobj");
      xref->xref->offsets[xref->xref->cur] = off;
      xref->xref->cur ++;
      return content_ref;
}

static
void
pdf_write_resources(pdf_resources *r, pdf_xref_internal *x, FILE *o)
{
      fprintf(o, "%s <<", "/Resources");
      if (r->extgstate)
      {
            dict_list *ll, *l = dict_to_list(r->extgstate->value.d.dict);
            ll = l;
            fprintf(o, "%s <<", "/ExtGState");
            while (l && l->key)
            {
                  pdf_obj *t = &l->val;
                  dict_array *a;
                  if (t->t == eRef)
                        pdf_obj_resolve(t);
                  a = dict_to_array(t->value.d.dict);
                  fprintf(o, "/%s <<", l->key);
                  if (a)
                  {
                        // print dict array "a"
                        if (a->items)
                        {
                              int i;
                              for (i = 0; i < a->cur; i++)
                              {
                                    fprintf(o, "/%s ",a->items[i].key);
                                    pdf_write_obj(&a->items[i].val, x, o);
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
                  fprintf(o, "%s", ">> ");
                  l = l->next;
            }
            // free dict_list
            dict_list_free(ll);
            fprintf(o, "%s",  ">> ");
      } // extgstate
      if (r->font)
      {
            pdf_obj *font = r->font;
            pdf_obj_resolve(font);
            fprintf(o, "%s", "/Font");
            pdf_write_obj(font, x, o);
            fprintf(o, "%s", "\n");
      }
      if (r->xobject)
      {
            pdf_obj_resolve(r->xobject);
            fprintf(o, "%s", "/XObject");
            pdf_write_obj(r->xobject, x, o);
            fprintf(o, "%s", "\n");
      }
      // end resources
      fprintf(o, "%s",  ">> ");
}

static
void
pdf_scan_object(pdf_obj *o, pdf_xref_internal *x)
{
      pdf_obj *obj = o;
      if (!o)
            return;
      switch (o->t)
      {
            case eRef:
                  pdf_obj_resolve(obj);
                  pdf_scan_object(obj, x);
                  break;
            case eDict:
            {
                  dict_list *ll, *l = dict_to_list(obj->value.d.dict);
                  ll = l;
                  while (l && l->key)
                  {
			if (strcmp(l->key, "S_O") == 0)
			{
			      l = l->next;
			      continue;
			}
			if (strcmp(l->key, "Length") == 0)
			{
			      l = l->next;
			      continue;
			}
                        if (l->val.t == eRef)
                        {
                              pdf_xref_internal_append(x, l->val.value.r.num, l->val.value.r.gen);
                              x->page_obj_buf[x->page_obj_idx] = l->val.value.r.num;
                              x->page_obj_idx ++;
                              // recursively scan this obj for more refs
                              pdf_scan_object(&l->val, x);
                        }
			else if (l->val.t == eArray)
			{
                              pdf_scan_object(&l->val, x);
			}
			else if (l->val.t == eDict)
			{
                              pdf_scan_object(&l->val, x);
			}
                        l = l->next;
                  }
                  // free list
                  dict_list_free(ll);
            }
            break;
            case eArray:
	    {
		  int i;
		  pdf_obj *oo;
		  for (i = 0; i < obj->value.a.len; i++)
		  {
			oo = &obj->value.a.items[i];
			if (oo->t == eRef)
			{
                              pdf_xref_internal_append(x, oo->value.r.num, oo->value.r.gen);
                              x->page_obj_buf[x->page_obj_idx] = oo->value.r.num;
                              x->page_obj_idx ++;
                              // recursively scan this obj for more refs
                              pdf_scan_object(oo, x);
			}
		  }
	    }
	    break;
            default:
                  break;
      }
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
            pdf_obj *font = r->font;
            pdf_obj_resolve(font);
            if (font->t == eDict)
            {
                  dict_list *ll, *l = dict_to_list(font->value.d.dict);
                  ll = l;
                  while (l && l->key)
                  {
                        if (l->val.t == eRef)
                        {
                              pdf_xref_internal_append(x, l->val.value.r.num, l->val.value.r.gen);
                              x->page_obj_buf[x->page_obj_idx] = l->val.value.r.num;
                              x->page_obj_idx ++;
                              // recursively scan this obj for more refs
                              pdf_scan_object(&l->val, x);
                        }
                        l = l->next;
                  }
                  // free list
                  dict_list_free(ll);
            }
      }
      if (r->xobject)
      {
	    pdf_scan_object(r->xobject, x);
      }
}

static
void
pdf_scan_page(pdf_page* pg, pdf_xref_internal* x)
{
      x->page_obj_idx = 0;
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

static
void
pdf_write_indirect_objs(pdf_xref_internal *xref, FILE *out)
{
      if (xref->page_obj_idx)
      {
            int i;
            for (i = xref->page_obj_idx - 1; i >=0; i--)
            {
                  int a = bpt_search(xref->entry, xref->page_obj_buf[i]);
                  if (a == -1)
                  {
                        pdf_obj *o = pdf_obj_find(xref->page_obj_buf[i], 0);
                        xref->xref->offsets[xref->xref->cur] = ftell(out);
                        fprintf(out, "%d 0 obj\n", xref->xref->cur);
                        pdf_write_obj(o, xref, out);
                        fprintf(out, "\n%s\n", "endobj");
                        // update entry
                        bpt_insert(xref->entry, xref->page_obj_buf[i], xref->xref->cur);
                        // inc new xref counter
                        xref->xref->cur ++;
                  }
            }
      }
}

static
void
pdf_write_page_obj(pdf_page *page, int pgidx, pdf_xref_internal *xref, FILE *out)
{
      int content_ref = 0;
      if (page->contents)
      {
            content_ref = pdf_write_contents(page->contents, xref, out);
      }

      xref->xref->offsets[xref->xref->cur] = ftell(out);
      fprintf(out, "%d 0 obj\n", xref->xref->cur);
      xref->page_ref_buf[pgidx] = xref->xref->cur;
      xref->xref->cur ++;
      fprintf(out, "%s\n", "<<");
      fprintf(out, "%s\n", "/Type /Page");
      fprintf(out, "%s [%f %f %f %f]\n", "/MediaBox", page->mediabox.x0, page->mediabox.y0,  page->mediabox.x1, page->mediabox.y1);
      if (page->resources)
      {
            pdf_write_resources(page->resources, xref, out);
      }
      if (content_ref)
      {
	    fprintf(out, "/Contents %d %d R\n", content_ref, 0);
      }
      fprintf(out, "\n%s\n", ">>");
      fprintf(out, "%s\n", "endobj");
}

pdf_err
pdf_write_pdf(pdf_doc *doc, char *ofile, int version, int pg1st, int pglast, char *upw, char *opw)
{
      FILE* out;
      char linebuf[1024];
      int i, startxref;
      pdf_xref_internal *xref;

      if (pg1st < 0)
            pg1st = 0;
      if (pglast < 0)
            pglast = doc->count-1;
      if (pglast < pg1st)
            pglast = pg1st;
      if (!ofile)
            return pdf_ok;
      out = fopen(ofile, "wb");
      if (!out)
            return pdf_ok;
      sprintf(linebuf, "%%PDF-%d.%d\n", version/10, version%10);
      fputs(linebuf, out);
      fputs("%\333\332\331\330\n", out);
      // scan pages
      xref = pdf_xref_internal_create(pdf_obj_count(), doc->count);
      if (!xref)
            goto done;
      pdf_catalog_write(xref, out);
      for (i = pg1st; i <= pglast; i++)
      {
            pdf_scan_page(doc->pages[i], xref);
            pdf_write_indirect_objs(xref, out);
            pdf_write_page_obj(doc->pages[i], i, xref, out);
      }
      pdf_pages_obj_write(xref, pg1st, pglast-pg1st+1, out);
      // write xref table
      startxref = pdf_xref_write(xref, out);
      pdf_trailer_write(xref, startxref, out);
      // done
  done:
      if (xref)
            pdf_xref_internal_free(xref);
      fclose(out);
      return pdf_ok;
}
