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
extern pdf_obj* make_key(pdf_obj *o, char *s);

typedef enum pdf_error_e
{
    pdf_ok,
    pdf_syntax_err,
	pdf_doc_err,
    pdf_mem_err,
    pdf_io_err,
    pdf_file_err,
    pdf_trailer_err,
    pdf_op_err,
    pdf_stream_zero_length,
    pdf_not_ok,
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
    eName,
    eString,
    eHexString,
    eArray,
    eDict,
    eId,
    eLimit
} e_pdf_kind;

typedef enum
{
    M,
    L,
    C,
    V,
    Y,
    H,
    RE,
} e_path_kind;

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
        unsigned char *k;
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

static inline void
mat_pt(gs_matrix *d, float a, float b, float *a1, float *b1)
{
    *a1 = a * d->a + b * d->c + d->e;
    *b1 = a * d->b + b * d->d + d->f;
}

// paths
typedef struct path_m_t path_m;
typedef struct path_l_t path_l;
typedef struct path_c_t path_c;
typedef struct path_v_t path_v;
typedef struct path_y_t path_y;
typedef struct path_h_t path_h;
typedef struct path_re_t path_re;
typedef struct stroke_state_s stroke_state;

struct path_m_t
{
    e_path_kind t;
    float x, y;
};
struct path_l_t
{
    e_path_kind t;
    float x, y;
};
struct path_c_t
{
    e_path_kind t;
    float x1, y1, x2, y2, x3, y3;
};
struct path_v_t
{
    e_path_kind t;
    float x2, y2, x3, y3;
};
struct path_y_t
{
    e_path_kind t;
    float x1, y1, x3, y3;
};
struct path_h_t
{
    e_path_kind t;
};
struct path_re_t
{
    e_path_kind t;
    float x, y, w, h;
};

struct stroke_state_s
{
    float lw, ml; // line_width, mitre_limit
    int lj, lc;   // line_join, line_cap
    float dash[32];
    int dash_n, dash_offset;
};

// generic helpers

extern pdf_obj* pdf_ref_to_obj_new(int n, int g);
extern pdf_obj  pdf_ref_to_obj(int n, int g);
extern pdf_obj* pdf_int_to_obj(int i);
extern pdf_obj  pdf_key_to_obj(char *s);
extern pdf_obj  pdf_float_to_obj(float f);
extern void pdf_dict_insert_int(dict *d, char *k, int v);
extern void pdf_dict_insert_ref(dict *d, char *k, int n, int g);
extern void pdf_dict_insert_name(dict *d, char *k, char *n);
extern pdf_obj *pdf_string_new(char *s, int len);

static inline pdf_obj* pdf_obj_copy(pdf_obj *o)
{
    pdf_obj *out = (pdf_obj*)pdf_malloc(sizeof(pdf_obj));
    if (out)
        *out = *o;
    return out;
}

static inline
void * null_val() { return 0; }

typedef struct gs_rect_s pdf_rect;

static inline void
name_free(pdf_obj *n)
{
    if (n->t == eName)
	    pdf_free(n->value.k);
}

#define obj_is_name(o)  ((o) && ((o)->t == eKey || (o)->t == eName))
#define obj_is_dict(o)  ((o) && ((o)->t == eDict))

static inline
pdf_obj *
pdf_array_build(int n)
{
    pdf_obj *a = pdf_malloc(sizeof(pdf_obj));
    pdf_obj *items;
    if (!a)
        return a;
    items = pdf_malloc(sizeof(pdf_obj) * n);
    if (!items)
        return 0;
    a->value.a.items = items;
    a->value.a.len = n;
    a->t = eArray;
    return a;
}

extern pdf_obj* pdf_obj_full_copy(pdf_obj *o);
extern pdf_obj* pdf_hstring_new(char *s, int len);

#endif
