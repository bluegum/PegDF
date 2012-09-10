#ifndef DICT_H
#define DICT_H
#include "tst.h"
#include "pdftypes.h"

struct dict_s
{
      Tptr dict;
      int n;
};

typedef struct dict_list_s dict_list;
typedef struct dict_array_s dict_array;

struct dict_list_s
{
      char *key;
      pdf_obj val;
      dict_list *next, *last;
};

struct dict_array_s
{
      int cur;
      struct {
	    char *key;
	    pdf_obj val;
      } *items;
};

extern dict*   dict_new();
extern dict*   dict_insert(dict*, char *key, void *val);
extern void*   dict_get(dict*, char *key);
extern void    dict_free(dict*);
extern void    dict_dump(dict* d);

static inline void
dict_list_free(dict_list *l)
{
      while (l)
      {
	    dict_list *n = l->next;
	    if (l->key)
		  pdf_free(l->key);
	    pdf_free(l);
	    l = n;
      }
}

extern dict_array* dict_to_array(dict *d);
extern dict_list* dict_to_list(dict *d);

#endif