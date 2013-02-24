/*
  Copyright (C) 2011 by Dakai Liu

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/
#ifndef PDFTYPES_H
#define PDFTYPES_H
#include <string.h>
#include "pdfmem.h"

#if _MSC_VER >= 1500 /* MSVC 9 or newer */
#define inline __inline
#elif __GNUC__ >= 3 /* GCC 3 or newer */
#define inline __inline
#endif

// Generics
typedef unsigned char  byte;
typedef unsigned int   uint;
typedef unsigned long  u32;
// PDF types
typedef struct pdf_obj_s pdf_obj;
typedef struct pdf_xref_s pdf_xref;
typedef struct dict_s dict;

typedef enum pdf_error_e
{
      pdf_ok,
      pdf_syntax_err,
      pdf_mem_err,
      pdf_io_err,
      pdf_file_err,
      pdf_trailer_err,
      pdf_unknown
} pdf_err;

struct pdf_xref_s
{
      int num;
      int gen;
};

typedef enum pdf_kind
{
      eObjMarker,
      eDictMarker,
      eArrayMarker,
      eNull,
      eBool,
      eInt,
      eReal,
      eRef,
      eKey,
      eString,
      eHexString,
      eArray,
      eDict,
      eId,
      eLimit
} e_pdf_kind;

struct pdf_obj_s
{
      e_pdf_kind t;
      int refs;
      union
      {
            int marker;
            int b;
            int i;
            double f;
	    char *id;
            char *k;
            struct {
                  unsigned short len;
                  char *buf;
            } s;
            struct {
                  int len;
                  pdf_obj *items;
            } a;
            struct {
                  dict *dict;
		  int stm_offset;
            } d;
            pdf_xref r;
      } value;
};

typedef struct gs_matrix_s gs_matrix;
typedef struct gs_point_s gs_point;
typedef struct gs_rect_s gs_rect;
typedef struct gs_bbox_s gs_bbox;

struct gs_matrix_s
{
      float a, b, c, d, e, f;
};

struct gs_point_s
{
      float x, y;
};

struct gs_rect_s
{
      float x0, y0;
      float x1, y1;
};

struct gs_bbox_s
{
      int x0, y0;
      int x1, y1;
};

static inline void
mat_init(gs_matrix *ctm, float a, float b, float c, float d, float e, float f)
{
      ctm->a = a;
      ctm->b = b;
      ctm->c = c;
      ctm->d = d;
      ctm->e = e;
      ctm->f = f;
}
static inline void
mat_set(gs_matrix *ctm, float a[6])
{
      ctm->a = a[0];
      ctm->b = a[1];
      ctm->c = a[2];
      ctm->d = a[3];
      ctm->e = a[4];
      ctm->f = a[5];
}
static inline void
mat_translate(gs_matrix *ctm, float e, float f)
{
      ctm->a = 1;
      ctm->b = 0;
      ctm->c = 0;
      ctm->d = 1;
      ctm->e = e;
      ctm->f = f;
}
static inline void
mat_cp(gs_matrix *a, gs_matrix *b)
{
      memcpy(a, b, sizeof(gs_matrix));
}
static inline gs_matrix
mat_con(gs_matrix *a, gs_matrix *b)
{
      gs_matrix d;
      d.a = a->a * b->a + a->b * b->c;
      d.b = a->a * b->b + a->b * b->d;
      d.c = a->c * b->a + a->d * b->c;
      d.d = a->c * b->b + a->d * b->d;
      d.e = a->e * b->a + a->f * b->c + b->e;
      d.f = a->e * b->b + a->f * b->d + b->f;
      return d;
}
static inline void
mat_mul(gs_matrix *d, gs_matrix *a, gs_matrix *b)
{
      *d = mat_con(a, b);
}
static inline int
pdf_to_int(pdf_obj *o)
{
      if (!o || (o->t != eInt && o->t != eBool))
            return 0; // should be NAN
      return o->value.i;
}
// return number of array element
static inline int
pdf_to_int_array(pdf_obj *o, int *a)
{
      int i, n;
      if (!o || o->t != eArray)
            return 0;
      n = o->value.a.len;
      for (i = 0; i < n; i++, a++)
      {
            if (o->value.a.items[i].t == eInt)
                  *a = o->value.a.items[i].value.i;
      }
      return n;
}

static inline float
pdf_to_float(pdf_obj *o)
{
      if (!o || (o->t != eInt && o->t != eReal))
            return 0; // should be NAN
      if (o->t == eInt)
            return o->value.i;
      else
            return o->value.f;
}

static inline char*
pdf_to_string(pdf_obj *o)
{
      if (!o || o->t != eString)
            return 0; // should be NAN
      return o->value.s.buf;
}

static inline gs_rect
pdf_rect_resolve(pdf_obj *o)
{
      gs_rect r={0,0,0,0};
      if (!o || (o->t != eArray && o->t != eRef))
            return r;
      // should handle xref as obj as well.
      // should handle floating point value as well.
      if (o->value.a.items[0].t == eInt)
	    r.x0 = o->value.a.items[0].value.i;
      else if (o->value.a.items[0].t == eReal)
	    r.x0 = o->value.a.items[0].value.f;
      if (o->value.a.items[1].t == eInt)
	    r.y0 = o->value.a.items[1].value.i;
      else if (o->value.a.items[1].t == eReal)
	    r.y0 = o->value.a.items[1].value.f;
      if (o->value.a.items[2].t == eInt)
	    r.x1 = o->value.a.items[2].value.i;
      else if (o->value.a.items[2].t == eReal)
	    r.x1 = o->value.a.items[2].value.f;
      if (o->value.a.items[3].t == eInt)
	    r.y1 = o->value.a.items[3].value.i;
      else if (o->value.a.items[3].t == eReal)
	    r.y1 = o->value.a.items[3].value.f;
      return r;
}

static inline
pdf_obj pdf_int_to_obj(int i)
{
      pdf_obj o;
      o.t = eInt;
      o.value.i = i;
      return o;
}

static inline
pdf_obj pdf_key_to_obj(char *s)
{
      pdf_obj o;
      char *k;
      k = pdf_malloc(strlen(s)+1);
      if (k)
      {
            strcpy(k, s);
            o.t = eKey;
            o.value.k = k;
      }
      else
      {
            o.t = eLimit;
            o.value.k = NULL;
      }
      return o;
}

static inline
void * null_val() { return 0; }

typedef struct gs_rect_s pdf_rect;

#endif
