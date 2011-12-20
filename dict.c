#include <stdio.h>
#include <stdlib.h>
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
  return NULL;
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
dict_print_key(char *key, void *val)
{
   printf("dict_print_key: %s\n", key);
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

void dict_show(dict* d)
{
   if (d)
   {
      if (d->dict)
      {
	 tst_traverse(d->dict, dict_print_key);
      }
   }
}
