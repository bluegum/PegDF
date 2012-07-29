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
dict_print_keyval(char *key, void *val)
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
                  {
                        printf("%s = ", key);
                        array_print(o);
                        printf("\n");
                  }
                  break;
                  case eDict:
                        printf("%s = << ", key);
                        dict_dump(o->value.d.dict);
                        printf(">>\n");
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
                  tst_traverse(d->dict, dict_free_val);
                  tst_cleanup(d->dict);
                  tst_print_reset(-1);
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
                  tst_traverse(d->dict, dict_print_keyval);
                  tst_print_reset(-1);
            }
      }
}
