#include <string.h>
#include "pdftypes.h"
#include "pdfmem.h"
#include "dict.h"



pdf_obj*
pdf_dict_new(int n)
{
    pdf_obj *o = pdf_malloc(sizeof(pdf_obj));
    if (!o)
        return 0;
    o->t = eDict;
    o->value.d.dict = dict_new(n);
    if (!o->value.d.dict)
        return 0;
    return o;
}


pdf_obj*
pdf_string_new(char *s, int len)
{
    pdf_obj *o = pdf_malloc(sizeof(pdf_obj));

    if (!o)
        return 0;

    o->t = eString;
    o->value.s.len = len;
    o->value.s.buf = pdf_malloc(len);
    memcpy(o->value.s.buf, s, len);

    return o;
}

pdf_obj*
pdf_hstring_new(char *s, int len)
{
    pdf_obj *o = pdf_string_new(s, len);
    if (o)
        o->t = eHexString;
    return o;
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

pdf_obj pdf_key_to_obj(char *s)
{
    pdf_obj o;
    o.t = eKey;
    make_key(&o, s);
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


pdf_obj*
pdf_obj_full_copy(pdf_obj *o)
{
    pdf_obj *out = (pdf_obj*)pdf_malloc(sizeof(pdf_obj));
    if (out)
        *out = *o;
    switch (o->t)
    {
        case eString:
        case eHexString:
        {
            char *p = pdf_malloc(o->value.s.len);
            memcpy(p, o->value.s.buf, o->value.s.len);
            out->value.s.buf = p;
            break;
        }
        case eName:
        {
            char *p = pdf_malloc(strlen(o->value.k)+1);
            memcpy(p, o->value.k, strlen(o->value.k)+1);
            out->value.k = p;
            break;
        }
        case eArray:
            if (o->value.a.len)
            {
                out->value.a.items = pdf_malloc(sizeof(pdf_obj)*(o->value.a.len));
                memcpy(out->value.a.items, o->value.a.items, (sizeof(pdf_obj)*(o->value.a.len)));
            }
            break;
        case eDict:
            out->value.d.dict = dict_copy(o->value.d.dict);
            break;
        default:
            break;
    }
    return out;
}
