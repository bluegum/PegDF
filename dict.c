#include <stdio.h>
#include <stdlib.h>
#include "pdftypes.h"
#include "dict.h"

dict* dict_new(char *key, void *val)
{
   dict * d = malloc(sizeof(dict));
   d->dict = tst_insert(0, key, val);
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
   }
   return NULL;
}
void*   dict_get(dict* d, char *key)
{
  return (void*) tst_search(d->dict, key);
}
void*   dict_remove(dict* d, char *key)
{
  return NULL;
}

static void
dict_free_val(char *key, void *val)
{
   printf("dict_free_val on entry: %s\n", key);
}

static void
dict_print_keyval(char *key, void *val)
{
  if (!val)
    printf("dict_print_key: %s\n", key);
  else
    printf("%s:%d\n", key, ((pdf_obj*)val)->t);
}

void    dict_destroy(dict* d)
{
   if (d)
   {
      if (d->dict)
      {
	 tst_traverse(d->dict, dict_free_val);
	 tst_cleanup(d->dict);
      }
      free(d);
   }
  return;
}

void dict_dump(dict* d)
{
   if (d)
   {
      if (d->dict)
      {
	 tst_traverse(d->dict, dict_print_keyval);
      }
   }
}
