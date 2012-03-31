#ifndef DICT_H
#define DICT_H
#include "tst.h"

typedef struct dict_s
{
  Tptr dict;
  int n;
} dict;

extern dict*   dict_new(char *key, void *val);
extern dict*   dict_insert(dict*, char *key, void *val);
extern void*   dict_get(dict*, char *key);
extern void    dict_free(dict*);
extern void    dict_dump(dict* d);

#endif
