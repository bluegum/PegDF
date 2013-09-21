#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "pdftypes.h"
#include "dict.h"
#include "pdfmem.h"

extern const char * pdf_keyword_find (register const char *str, register unsigned int len);
static void dict_free_val(char *key, void *val, void *x);

void entry_no_free(void *e)
{
}

void
entry_name_free(void *e)
{
    if (e)
	    pdf_free(e);
    else
	    printf("!?\n");
}

dict_entry*
dict_entry_new(void *v, char *k)
{
    dict_entry *e;
    e = pdf_malloc(sizeof(dict_entry));
    if (!e)
        return 0;
    if (pdf_keyword_find(k, strlen(k)))
    {
        e->f = entry_no_free;
    }
    else
    {
        e->f = entry_name_free;
    }
    e->v = v;
    e->k = k;
    return e;
}

void
dict_entry_free(char *k, void *v, void *a)
{
    dict_entry *e = (dict_entry*)v;
    if (e)
    {
	    e->f(e->k);
	    dict_free_val(0, e->v, 0);
	    pdf_free(e);
    }
}

dict* dict_new(int n)
{
    dict * d = pdf_malloc(sizeof(dict));
    if (d)
    {
        d->dict = NULL;
	    d->n = 0;
	    d->stream = 0;
    }
    return d;
}

dict* dict_insert(dict* d, char *key, void *val)
{
    if (d)
    {
#ifdef TSTC
        dict_entry *ent = dict_entry_new(val, key);
        if (d->dict)
        {
            d->dict = tstc_insert(d->dict, key, ent);
	    }
	    else
	    {
            d->dict = tstc_insert(NULL, key, ent);
	    }
#else
        if (d->dict)
        {
            tst_insert(d->dict, key, val);
	    }
	    else
	    {
            d->dict = tst_insert(NULL, key, val);
	    }
#endif
	    d->n += 1;
    }
    return NULL;
}

void*
dict_get(dict* d, char *key)
{
#ifdef TSTC
    dict_entry *e = 0;
    int r = tstc_find(d->dict, key, (void*)&e);
    if (r)
    {
	    return e->v;
    }
    return e;
#else
    return (void*) tst_search(d->dict, key);
#endif
}

static void
dict_free_val(char *key, void *val, void *x)
{
    pdf_obj *o;
    extern void pdf_obj_delete(void *o);
    pdf_obj_delete(val);
    o = (pdf_obj*)val;
    if (val)
        pdf_free(val);
    //printf("dict_free_val on entry: %s\n", key);
}

#ifndef TSTC

static void
array_print(pdf_obj *a)
{
    int i;
    printf("%s ", "[");
    for (i = 0; i < a->value.a.len; i++)
    {
        pdf_obj *o = &a->value.a.items[i];
        switch (o->t)
        {
            case eRef:
                printf("ref(%d,%d) ", o->value.r.num, o->value.r.gen);
                break;
            case eKey:
            case eName:
                printf("name(%s) ", o->value.k);
                break;
            case eString:
            case eHexString:
                printf("str(");
                {int i;
                    for (i = 0; i < o->value.s.len; i++) printf("%c", o->value.s.buf[i]);
                }
                printf(")");
                break;
            case eInt:
                printf("i(%d) ", o->value.i);
                break;
            case eReal:
                printf("f(%f) ", o->value.f);
                break;
            case eArray:
            {
                array_print(o);
            }
            break;
            case eDict:
                printf("<< ");
                dict_dump(o->value.d.dict);
                printf(">> ");
                break;
            default:
                printf("%d ", o->t);
                break;
        }
    }
    printf("%s ", "]");
}

static void
dict_print_keyval(char *key, void *val, void *x)
{
    if (!val)
        printf("dict_print_key: %s\n", key);
    else
    {
        pdf_obj *o = (pdf_obj*) val;
        switch (o->t)
        {
            case eRef:
                printf("%s = ref(%d,%d)\n", key, o->value.r.num, o->value.r.gen);
                break;
            case eKey:
            case eName:
                printf("%s = name(%s)\n", key, o->value.k);
                break;
            case eString:
            case eHexString:
                printf("%s = str(%s)\n", key, o->value.s.buf); // could out run buffer
                break;
            case eInt:
                printf("%s = i(%d)\n", key, o->value.i);
                break;
            case eReal:
                printf("%s = f(%f)\n", key, o->value.f);
                break;
            case eArray:
                printf("%s = ", key);
                array_print(o);
                printf("\n");
                break;
            case eDict:
                printf("%s = << ", key);
                dict_dump(o->value.d.dict);
                printf(">>\n");
                break;
            case eBool:
                printf("%s = B(%d)\n", key, o->value.i);
                break;
            default:
                printf("%s:%d\n", key, o->t);
                break;
        }
    }
}
#endif

void  dict_free(dict* d)
{
    if (d)
    {
        if (d->dict)
        {
#ifdef TSTC
            tstc_call(d->dict, 0, dict_entry_free, 0);
            tstc_free(d->dict);
#else
            tst_print_reset(1);
            tst_traverse(d->dict, dict_free_val, NULL);
            tst_cleanup(d->dict);
            tst_print_reset(-1);
#endif
        }
	    if (d->stream)
	    {
            pdf_free(d->stream);
	    }
        pdf_free(d);
    }
    return;
}

void dict_dump(dict* d)
{
    printf("%s", "\n");
    if (d)
    {
        if (d->dict)
        {
#ifdef TSTC
            tstc_print(d->dict);
#else
            tst_print_reset(1);
            tst_traverse(d->dict, dict_print_keyval, NULL);
            tst_print_reset(-1);
#endif
        }
    }
}

// TODO: insert to head, and return head of list.
static
void
dict_list_append(char *key, void *v, void *list)
{
    dict_list *l = (dict_list*)list;
    dict_list *head = l;
    if (!l)
	    return;
    if (l->last)
	    l = l->last;
    l->key = pdf_malloc(strlen(key)+1);
    memcpy(l->key, key, strlen(key)+1);
#ifdef TSTC
    l->val = *(pdf_obj*)((dict_entry*)v)->v;
#else
    l->val = *((pdf_obj*)v);
#endif
    if (!l->last)
    {
	    l->last = (dict_list*)pdf_malloc(sizeof(dict_list));
	    l->last->key = NULL;
	    l->next = l->last;
	    l->next->next = l->next->last = l->last->last = NULL;
	    head->last = l->last;
    }
}
// returned object belongs to caller.
// Experimental: using list as target by imitating "LISP" style.
dict_list*
dict_to_list(dict *d)
{
    dict_list *l = pdf_malloc(sizeof(dict_list));
    l->next = l->last = NULL;
    l->val.t = eLimit;
    if (d && d->dict)
    {
#ifdef TSTC
	    char buf[1024];
	    tstc_call(d->dict, buf, dict_list_append, l);
#else
	    tst_print_reset(1);
	    tst_traverse(d->dict, (tst_hook)dict_list_append, l);
	    tst_print_reset(-1);
#endif
    }
    if (l->val.t == eLimit)
    {
	    pdf_free(l);
	    l = NULL;
    }
    return l;
}

#ifdef TSTC
static
void
dict_tstc_array_append(char *k, void *v, void* arr)
{
    dict_entry *e = (dict_entry*)v;
    char *key = e->k;
    dict_array * a = (dict_array*)arr;
    a->items[a->cur].key = pdf_malloc(strlen(key)+1);
    memcpy(a->items[a->cur].key, key, strlen(key)+1);
    a->items[a->cur].val = *((pdf_obj*)(e->v));
    a->cur += 1;
}
#else
static
void
dict_array_append(char *key, void *v, dict_array* a)
{
    a->items[a->cur].key = pdf_malloc(strlen(key)+1);
    memcpy(a->items[a->cur].key, key, strlen(key)+1);
    a->items[a->cur].val = *((pdf_obj*)v);
    a->cur += 1;
}
#endif
// returned object belongs to caller.
dict_array*
dict_to_array(dict *d)
{
    dict_array *a = pdf_malloc(sizeof(dict_array));
    if (!a)
	    return a;
    a->cur = 0;
    a->items = pdf_malloc((sizeof(struct dict_item))* (d->n));
    if (!a->items)
	    return NULL;
    if (d && d->dict)
    {
#ifdef TSTC
	    tstc_call(d->dict, 0, (tstc_f)dict_tstc_array_append, (void*)a);
#else
	    tst_print_reset(1);
	    tst_traverse(d->dict, (tst_hook)dict_array_append, a);
	    tst_print_reset(-1);
#endif
    }
    return a;
}

int
dict_entries(dict *d)
{
    if (!d)
        return 0;
    return d->n;
}

// Helpers

pdf_obj pdf_ref_to_obj(int n, int g)
{
    pdf_obj o;
    o.t = eRef;
    o.value.r.num = n;
    o.value.r.gen = g;
    return o;
}

pdf_obj* pdf_ref_to_obj_new(int n, int g)
{
    pdf_obj *o = pdf_malloc(sizeof(pdf_obj));
    o->t = eRef;
    o->value.r.num = n;
    o->value.r.gen = g;
    return o;
}

pdf_obj* pdf_int_to_obj(int i)
{
    pdf_obj *o = pdf_malloc(sizeof(pdf_obj));
    o->t = eInt;
    o->value.i = i;
    return o;
}

pdf_obj* pdf_key_to_obj(char *s)
{
    pdf_obj *o = pdf_malloc(sizeof(pdf_obj));
    if (!o)
        return 0;
    o->t = eKey;
    o = make_key(o, s);
    return o;
}

pdf_obj
pdf_float_to_obj(float f)
{
    pdf_obj o;
    o.t = eReal;
    o.value.f = f;
    return o;
}

void
pdf_dict_insert_int(dict *d, char *k, int v)
{
    pdf_obj *val;

    val = pdf_int_to_obj(v);
    dict_insert(d, k, (void*)val);
}

void
pdf_dict_insert_ref(dict *d, char *k, int n, int g)
{
    pdf_obj *val;

    val = pdf_ref_to_obj_new(n, g);
    dict_insert(d, k, (void*)val);
}

void
pdf_dict_insert_name(dict *d, char *k, char *n)
{
    pdf_obj *val = pdf_key_to_obj(n);
    dict_insert(d, k, (void*)val);
}
