#include <stdio.h>
#include "pdfdoc.h"
#include "pdftypes.h"

pdf_doc* pdf_doc_load(pdf_xref *doc)
{
  pdf_obj *a, *d, *c, *kids;
  d = pdf_obj_find(doc->num, doc->gen);
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
  kids = dict_get(a->value.d.dict, "Kids");
  if (!kids)
    return NULL;
  
  return NULL;
}

void pdf_doc_done()
{

}

pdf_err pdf_page_load(pdf_xref *xref)
{
  return 0;
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
  pdf_doc_load(&root->value.r);
  return pdf_ok;
}
