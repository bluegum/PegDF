#include <stdio.h>
#include "pdftypes.h"
#include "pdfindex.h"
#include "gsdraw.h"
#include "pdffilter.h"
#include "pdfdoc.h"

#define pdf_to_name(o) (o).value.k
pdf_err
pdf_colorspace_set(pdf_cspace* cs, pdf_obj *o)
{
      pdf_obj obj, *data = 0;
      if (!o)
	    return pdf_ok;
      if (o->t == eArray)
      {
	    obj = o->value.a.items[0];
      }
      else if (obj_is_name(o))
      {
	    obj = *o;
      }
      else if (o->t == eRef)
      {
	    pdf_obj *x = pdf_obj_deref(&o);
	    obj = *x;
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

      else if (!strcmp(pdf_to_name(obj), "CMYK"))
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
	    if (o->value.a.len >= 2)
		  data = &o->value.a.items[1];
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
		  if (data)
		  {
			pdf_obj *icc = pdf_obj_deref(data);
			if (icc && icc->t == eDict)
			{
			      pdf_obj *a = dict_get(icc->value.d.dict, "N");
			      if (a && a->t == eInt)
				    cs->n = a->value.i;
			}
			cs->priv = data;
		  }
		  break;
	    }
	    default:
		  cs->n = 1;
		  break;
      }
      return pdf_ok;
}
