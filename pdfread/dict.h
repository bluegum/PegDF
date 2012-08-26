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

#endif
