#include <stdio.h>
#include <stdlib.h>
#include "pdftypes.h"
#include "dict.h"
#include "pdfmem.h"

dict* dict_new()
{
  dict * d = pdf_malloc(sizeof(dict));
  if (d)
    d->dict = NULL;
  return d;
}
dict* dict_insert(dict* d, char *key, void *val)
{
  if (d)
    {
      if (d->dict)
	{
	  tst_insert(d->dict, key, val);
	}
      else
	{
	  d->dict = tst_insert(NULL, key, val);
	}
    }
  return NULL;
}

void*   dict_get(dict* d, char *key)
{
  return (void*) tst_search(d->dict, key);
}

static void
dict_free_val(char *key, void *val)
{
  extern void pdf_obj_delete(void *o);
  pdf_obj_delete(val);
  if (val)
    pdf_free(val);
  //printf("dict_free_val on entry: %s\n", key);
}

static void
dict_print_keyval(char *key, void *val)
{
  if (!val)
    printf("dict_print_key: %s\n", key);
  else
    printf("%s:%d\n", key, ((pdf_obj*)val)->t);
}

void  dict_free(dict* d)
{
   if (d)
   {
      if (d->dict)
      {
	 tst_traverse(d->dict, dict_free_val);
	 tst_cleanup(d->dict);
      }
      pdf_free(d);
   }
  return;
}

void dict_dump(dict* d)
{
   if (d)
   {
      if (d->dict)
      {
	tst_print_reset();
	 tst_traverse(d->dict, dict_print_keyval);
      }
   }
}
