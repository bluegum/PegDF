#include <stdio.h>
#include "pdftypes.h"
#include "gsdraw.h"
#include "pdffilter.h"
#include "pdfdoc.h"

#define pdf_to_name(o) (o).value.k
pdf_err
pdf_colorspace_set(pdf_cspace* cs, pdf_obj *o)
{
  if (!o)
    return pdf_ok;
  if (o->t == eArray)
    {
      pdf_obj obj = o->value.a.items[0];
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

      else
	return pdf_unknown;

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
    default:
      cs->n = 1;
      break;
    }
  return pdf_ok;
}
