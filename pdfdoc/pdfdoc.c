#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pdfdoc.h"
#include "pdftypes.h"
#include "pdfindex.h"

static inline int
pdf_to_int(pdf_obj *o)
{
  if (!o || o->t != eInt)
    return 0; // should be NAN
  return o->value.i;
}
static inline gs_rect
pdf_rect_resolve(pdf_obj *o)
{
  gs_rect r={0,0,0,0};
  if (!o || o->t != eArray || o->t != eRef)
    return r;
  // should handle xref as obj as well.
  // should handle floating point value as well.
  r.x0 = o->value.a.items[0].value.i;
  r.y0 = o->value.a.items[1].value.i;
  r.x1 = o->value.a.items[2].value.i;
  r.y1 = o->value.a.items[3].value.i;
  return r;
}

static inline pdf_group*
pdf_group_load(pdf_obj *o)
{
  pdf_group *g;
  if (!o || o->t != eDict)
    return NULL;
  g = malloc(sizeof(pdf_group));
  if (!g)
    return NULL;
  memset(g, 0, sizeof(pdf_group));
  g->cs = dict_get(o->value.d.dict, "CS");
  g->i = pdf_to_int(dict_get(o->value.d.dict, "I"));
  g->k = pdf_to_int(dict_get(o->value.d.dict, "K"));
  return g;
}

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
  p->mediabox = pdf_rect_resolve(dict_get(d, "MediaBox"));
  p->resources = dict_get(d, "Resources");
  // optionals
  p->contents = dict_get(d, "contents");
  v = dict_get(d, "Rotate");
  if (v)
    p->rotate = v->value.i;
  p->group = pdf_group_load(dict_get(d, "Group"));
  p->annots = dict_get(d, "Annots");
  p->metadata = dict_get(d, "Metadata");
  p->pieceinfo = dict_get(d, "PieceInfo");
  p->lastmodified = dict_get(d, "LastModified");
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

pdf_doc* pdf_doc_load(pdf_obj *rdoc)
{
  pdf_obj *a, *d, *c, *kids;
  pdf_doc *doc;
  if (rdoc->t == eRef)
    {
      d = pdf_obj_find(rdoc->value.r.num, rdoc->value.r.gen);
    }
  else if (rdoc->t == eDict)
    {
      d = rdoc;
    }
  else
    {
      return pdf_ok;
    }
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
  doc = malloc(sizeof(pdf_doc));
  if (!doc)
    return NULL;
  doc->count = c->value.i;
  kids = dict_get(a->value.d.dict, "Kids");
  if (!kids || kids->t != eArray)
    {
      free(doc);
      return NULL;
    }
  doc->pages = malloc(sizeof(pdf_page*) * doc->count);
  doc->pageidx = 0;
  pdf_page_tree_load(doc, kids);
  return doc;
}

pdf_err pdf_doc_process(pdf_doc *d)
{
  return pdf_page_tree_walk(d);
}

pdf_err  pdf_doc_print_info(pdf_doc *d)
{
  if (d->info)
    pdf_info_print(d->info);
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
  pdf_info *info;
  unsigned char *id[2];
};

pdf_err pdf_info_load(pdf_obj *o, pdf_info **info)
{
  pdf_obj *a;
  pdf_info *i;
  *info = malloc(sizeof(pdf_info));
  if (!*info)
    return pdf_ok;
  if (!o)
    return pdf_ok;
  memset(*info, 0, sizeof(pdf_info));
  if (o->t == eRef)
    {
      o = pdf_obj_find(o->value.r.num, o->value.r.gen);
    }
  if (!o)
    return pdf_ok;
  i = *info;
  a = dict_get(o->value.d.dict, "Title");
  if (a) i->title = a->value.s.buf;
  a = dict_get(o->value.d.dict, "Author");
  if (a) i->author = a->value.s.buf;
  a = dict_get(o->value.d.dict, "Subject");
  if (a) i->subject = a->value.s.buf;
  a = dict_get(o->value.d.dict, "Keywords");
  if (a) i->keywords = a->value.s.buf;
  a = dict_get(o->value.d.dict, "Creator");
  if (a) i->creator = a->value.s.buf;
  a = dict_get(o->value.d.dict, "Producer");
  if (a) i->producer = a->value.s.buf;
  a = dict_get(o->value.d.dict, "CreationDate");
  if (a) i->creationdate = a->value.s.buf;
  a = dict_get(o->value.d.dict, "ModDate");
  if (a) i->moddate = a->value.s.buf;
  a = dict_get(o->value.d.dict, "Trapped");
  i->trapped = UNknown;
  if (a)
    {
      if (strcmp(a->value.k, "True") == 0)
	i->trapped = TRue;
      else if (strcmp(a->value.k, "False") == 0)
	i->trapped = FAlse;
    }
  return pdf_ok;
}

pdf_err pdf_info_print(pdf_info *info)
{
  printf("Title:%s\n", info->title);
  printf("Auther:%s\n", info->author);
  printf("Subject:%s\n", info->subject);
  printf("Keywords:%s\n", info->keywords);
  printf("Creator:%s\n", info->creator);
  printf("Producer:%s\n", info->producer);
  printf("CreationDate:%s\n", info->creationdate);
  printf("ModDate:%s\n", info->moddate);
  printf("Trapped:%s\n", info->trapped==TRue?"Yes":(info->trapped==FAlse)?"No":"Unknown");
  return pdf_ok;
}

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
      pdf_info_load(a, &t.info);
    }
  a = dict_get(trailer->value.d.dict, "Id");
  if (a && a->t == eArray)
    {
      t.id[0] = &a->value.a.items[0];
      t.id[1] = &a->value.a.items[1];
    }
  d = pdf_doc_load(root);
  if (!d)
    return pdf_ok;
  d->info = t.info; // pass info as member of doc
  pdf_doc_process(d);
  pdf_doc_print_info(d);
  pdf_doc_done(d);
  return pdf_ok;
}
