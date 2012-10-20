#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "pdftypes.h"
#include "dict.h"
#include "pdfmem.h"

dict* dict_new()
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
            if (d->dict)
            {
                  tst_insert(d->dict, key, val);
            }
            else
            {
                  d->dict = tst_insert(NULL, key, val);
            }
	    d->n += 1;
      }
      return NULL;
}

void*   dict_get(dict* d, char *key)
{
      return (void*) tst_search(d->dict, key);
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

void  dict_free(dict* d)
{
      if (d)
      {
            if (d->dict)
            {
                  tst_print_reset(1);
                  tst_traverse(d->dict, dict_free_val, NULL);
                  tst_cleanup(d->dict);
                  tst_print_reset(-1);
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
                  tst_print_reset(1);
                  tst_traverse(d->dict, dict_print_keyval, NULL);
                  tst_print_reset(-1);
            }
      }
}

// TODO: insert to head, and return head of list.
static
void
dict_list_append(char *key, void *v, dict_list* l)
{
      dict_list *head = l;
      if (!l)
	    return;
      if (l->last)
	    l = l->last;
      l->key = pdf_malloc(strlen(key)+1);
      memcpy(l->key, key, strlen(key)+1);
      l->val = *((pdf_obj*)v);
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
	    tst_print_reset(1);
	    tst_traverse(d->dict, (tst_hook)dict_list_append, l);
	    tst_print_reset(-1);
      }
      if (l->val.t == eLimit)
      {
	    pdf_free(l);
	    l = NULL;
      }
      return l;
}

static
void
dict_array_append(char *key, void *v, dict_array* a)
{
      a->items[a->cur].key = pdf_malloc(strlen(key)+1);
      memcpy(a->items[a->cur].key, key, strlen(key)+1);
      a->items[a->cur].val = *((pdf_obj*)v);
      a->cur += 1;
}

// returned object belongs to caller.
dict_array*
dict_to_array(dict *d)
{
      dict_array *a = pdf_malloc(sizeof(dict_array));
      if (!a)
	    return a;
      a->cur = 0;
      a->items = pdf_malloc((sizeof(char*) + sizeof(pdf_obj))* d->n);
      if (!a->items)
	    return NULL;
      if (d && d->dict)
      {
	    tst_print_reset(1);
	    tst_traverse(d->dict, (tst_hook)dict_array_append, a);
	    tst_print_reset(-1);
      }
      return a;
}
