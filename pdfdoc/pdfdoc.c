#include <stdio.h>
#include <stdlib.h>
#include "pdfdoc.h"
#include "pdftypes.h"


pdf_err pdf_page_load(pdf_obj *o, pdf_page **page)
{
  pdf_page *p;
  dict *d = o->value.d.dict;
  pdf_obj *v;

  *page = malloc(sizeof(pdf_page));
  p = *page;
  memset(p, 0, sizeof(pdf_page));
  // parse tree dict
  p->parent = dict_get(d, "Parent");
  //p->mediabox = dict_get(d, "Mediabox");
  p->resources = dict_get(d, "Resources");
  // optionals
  p->contents = dict_get(d, "contents");
  v = dict_get(d, "Rotate");
  if (v)
    p->rotate = v->value.i;
  p->group = dict_get(d, "Group");
  p->annots = dict_get(d, "Annots");
  p->metadata = dict_get(d, "Metadata");
  p->pieceinfo = dict_get(d, "PieceInfo");
  return pdf_ok;
}

pdf_err pdf_page_free(pdf_page *page)
{
  free(page);
  return pdf_ok;
}

// Load into a flat array instead of tree
pdf_err pdf_page_tree_load(pdf_doc *d, pdf_obj *o)
{
  int i;
  pdf_obj *a, *kids = o;
  if (o->t == eRef)
    {
      o = pdf_obj_find(o->value.r.num, o->value.r.gen);
      a = dict_get(o->value.d.dict, "Type");
      if (!a)
	return pdf_ok;
      if (a->t == eKey && a->value.k)
	{
	  if (strcmp(a->value.k, "Pages") == 0)
	    {
	      kids = dict_get(o->value.d.dict, "Kids");
	      if (!kids || kids->t != eArray)
		return pdf_ok;
	    }
	  else if (strcmp(a->value.k, "Page") == 0)
	    {
	      pdf_page_load(o, &d->pages[d->pageidx]);
	      d->pageidx += 1;
	      return pdf_ok;
	    }
	  else
	    {
	      return pdf_ok;
	    }
	}
      else
	{
	  return pdf_ok;
	}
    }
  for (i = 0; i < kids->value.a.len; i++)
    {
      pdf_obj a, *b;
      a = kids->value.a.items[i];
      if (a.t == eRef)
	{
	  pdf_page_tree_load(d, &a);
	}
    }
  return pdf_ok;
}

pdf_err pdf_page_tree_walk(pdf_doc *d)
{
  int i;
  for (i = 0; i < d->count; i++)
    {
#if 1
      printf("processing page#%d\n", i);
#endif
    }
  return pdf_ok;
}

pdf_doc* pdf_doc_load(pdf_xref *rdoc)
{
  pdf_obj *a, *d, *c, *kids;
  pdf_doc *doc;
  doc = malloc(sizeof(pdf_doc));
  if (!doc)
    return NULL;
  d = pdf_obj_find(rdoc->num, rdoc->gen);
  if (!d || d->t != eDict)
    return NULL;
  a = dict_get(d->value.d.dict, "Pages");
  if (!a || a->t != eRef)
    return NULL;
  a = pdf_obj_find(a->value.r.num, a->value.r.gen);
  if (!a || a->t != eDict)
    return NULL;
  c = dict_get(a->value.d.dict, "Count");
  if (!c || c->t != eInt)
    return NULL;
  doc->count = c->value.i;
  kids = dict_get(a->value.d.dict, "Kids");
  if (!kids || kids->t != eArray)
    return NULL;
  doc->pages = malloc(sizeof(pdf_page*) * doc->count);
  doc->pageidx = 0;
  pdf_page_tree_load(doc, kids);
  return doc;
}

pdf_err pdf_doc_process(pdf_doc *d)
{
  return pdf_page_tree_walk(d);
}

void pdf_doc_done(pdf_doc *d)
{
  int i;
  for (i = 0; i < d->count; i++)
    {
      pdf_page_free(d->pages[i]);
    }
  free(d->pages);
  free(d);
}

typedef struct pdf_trailer_s pdf_trailer;

struct pdf_trailer_s
{
  int size;
  int prev;
  pdf_doc * root;
  void *encrypt;
  void *info;
  void *id;
};


pdf_err pdf_trailer_open(pdf_obj *trailer)
{
  pdf_obj *a, *root;
  pdf_trailer t;
  pdf_doc * d;

  if (!trailer || trailer->t != eDict)
    return pdf_ok;
  root = dict_get(trailer->value.d.dict, "Root");

  if (!root || root->t != eRef)
    return pdf_ok;

  a = dict_get(trailer->value.d.dict, "Size");
  if (a && a->t == eInt)
    {
      t.size = a->value.i;
    }
  a = dict_get(trailer->value.d.dict, "Prev");
  if (a && a->t == eInt)
    {
      t.prev = a->value.i;
    }
  a = dict_get(trailer->value.d.dict, "Encrypt");
  if (a)
    {
      t.encrypt = a;
    }
  a = dict_get(trailer->value.d.dict, "Info");
  if (a)
    {
      t.info = a;
    }
  a = dict_get(trailer->value.d.dict, "Id");
  if (a)
    {
      t.id = a;
    }
  d = pdf_doc_load(&root->value.r);
  pdf_doc_process(d);
  pdf_doc_done(d);
  return pdf_ok;
}
