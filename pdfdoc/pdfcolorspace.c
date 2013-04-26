#include <stdio.h>
#include "pdftypes.h"
#include "pdfindex.h"
#include "gsdraw.h"
#include "pdffilter.h"
#include "pdfdoc.h"
#include "pdf_priv.h"

#define pdf_to_name(o) (o).value.k
pdf_err
pdf_colorspace_set(pdf_cspace* cs, pdf_obj *o)
{
    pdf_obj obj, *icc = 0;
    pdf_obj_resolve(o);
    if (!o)
	    return pdf_op_err;
    if (o->t == eArray)
    {
	    obj = *(pdf_get_array_item(o, 0));
    }
    else if (obj_is_name(o))
    {
	    obj = *o;
    }
    else
    {
	    return pdf_op_err;
    }
    if (!strcmp(pdf_to_name(obj), "Pattern"))
	    cs->t = Pattern;
    else if (!strcmp(pdf_to_name(obj), "G"))
	    cs->t = DeviceGray;

    else if (!strcmp(pdf_to_name(obj), "RGB"))
	    cs->t = DeviceRGB;

    else if (!strcmp(pdf_to_name(obj), "CalRGB"))
	    cs->t = DeviceRGB;

    else if (!strcmp(pdf_to_name(obj), "CMYK"))
	    cs->t = DeviceCMYK;

    else if (!strcmp(pdf_to_name(obj), "CalCMYK"))
	    cs->t = DeviceCMYK;

    else if (!strcmp(pdf_to_name(obj), "DeviceGray"))
	    cs->t = DeviceGray;

    else if (!strcmp(pdf_to_name(obj), "DeviceRGB"))
	    cs->t = DeviceRGB;

    else if (!strcmp(pdf_to_name(obj), "DeviceCMYK"))
	    cs->t = DeviceCMYK;

    else if (!strcmp(pdf_to_name(obj), "Separation"))
	    cs->t = Separation;
    else if (!strcmp(pdf_to_name(obj), "ICCBased"))
    {
	    cs->t = ICCBased;
	    if (pdf_to_arraylen(o) >= 2)
            icc = pdf_get_array_item(o, 1);
    }
    else
    {
	    return pdf_op_err;
    }

    switch (cs->t)
    {
	    case DeviceGray: case Separation:
            cs->n = 1;
            break;
	    case DeviceRGB:
            cs->n = 3;
            break;
	    case DeviceCMYK:
            cs->n = 4;
            break;
	    case ICCBased:
	    {
            cs->n = 1;
            if (icc)
            {
                cs->n = pdf_to_int(pdf_dict_get(icc, "N"));
            }
            cs->priv = icc;
        }
        break;
	    default:
            cs->n = 1;
            break;
    }
    return pdf_ok;
}
