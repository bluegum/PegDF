#ifndef DICT_H
#define DICT_H

#if 0
#define TSTC
#else
#define HASHMAP
#endif


#if defined (TSTC)
#include "tst_compact.h"
#elif defined (HASHMAP)
#include "hash_map.h"
#else
#include "tst.h"
#endif

#include "pdftypes.h"

typedef void (*dict_k_free)(void *);

typedef struct
{
    void *v;
    char *k;
    dict_k_free f;
} dict_entry;


struct dict_s
{
#if defined (HASHMAP)
    hash_map *dict;
#else
    Tptr dict;
#endif
    int n;
    void *stream;
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
    struct dict_item {
	    char *key;
	    pdf_obj val;
    } *items;
};

extern dict*   dict_new(int);
extern dict*   dict_insert(dict*, char *key, void *val);
extern void*   dict_get(dict*, char *key);
extern void    dict_free(dict*);
extern void    dict_dump(dict* d);
extern int     dict_entries(dict* d);

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
extern dict_entry* dict_entry_new(void *v, char *k);
extern void dict_entry_free(char *k, void *v, void*);
extern void entry_no_free(void *e);
extern void entry_name_free(void *e);
extern dict* dict_copy(dict *d);
extern void dict_each(dict *d, void (*call()), void *a);
extern void pdf_dict_insert_string(dict *d, char *k, char *s, int n);

#endif
