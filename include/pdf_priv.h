#ifndef PDF_PRIV_H
#define PDF_PRIV_H

#include "pdfindex.h"

static inline gs_rect
pdf_rect_resolve(pdf_obj *o)
{
    gs_rect r={0,0,0,0};
    if (!o || (o->t != eArray && o->t != eRef))
        return r;
    pdf_obj_resolve(o);
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

static inline float
pdf_to_float(pdf_obj *o)
{
    pdf_obj_resolve(o);
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
    pdf_obj_resolve(o);
    if (!o || o->t != eString)
        return 0;
    return o->value.s.buf;
}
static inline int
pdf_to_int(pdf_obj *o)
{
    pdf_obj_resolve(o);
    if (!o || (o->t != eInt && o->t != eBool))
        return 0; // should be NAN
    return o->value.i;
}

// return number of array element
static inline int
pdf_to_int_array(pdf_obj *o, int *a)
{
    int i, n;
    pdf_obj_resolve(o);
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

static inline pdf_obj*
pdf_dict_get(pdf_obj *o, char *s)
{
    pdf_obj *a;
    pdf_obj_resolve(o);
    if (!o || o->t != eDict)
        return 0;
    a = dict_get(o->value.d.dict, s);
    pdf_obj_resolve(a);
    return a;
}

#endif
