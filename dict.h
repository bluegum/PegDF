#ifndef DICT_H
#define DICT_H
#include "tst.h"

typedef struct dict_s
{
  Tptr dict;
  int n;
} dict_t;

extern dict_t* dict_new(char *key, void *val);
extern dict_t* dict_insert(dict_t*, char *key, void *val);
extern void*   dict_get(dict_t*, char *key);
extern void*   dict_remove(dict_t*, char *key);
extern void    dict_destroy(dict_t*);
extern void    dict_show(dict_t* d);

#endif
