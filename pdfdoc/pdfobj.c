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
            strcpy(p, o->value.k);
            out->value.k = p;
            break;
        }
        default:
            break;
    }
    return out;
}
