#include "pdftypes.h"
#include "pdfdoc.h"
#include "pdfcmds.h"

pdf_err
x_d(pdf_page *p, pdf_obj *o)
{
#ifdef DEBUG
  printf("%s ", "d");
#endif
  if (o || o->t == eArray)
    {
      int i;
      for (i=0; i < o->value.a.len; i++)
	{
	  pdf_obj a = o->value.a.items[i];
	  if (a.t == eString)
	    pdf_free(a.value.s.buf);
	}
      if (o->value.a.len)
	pdf_free(o->value.a.items);
    }
  return pdf_ok;
}

pdf_err
x_g(pdf_page *p, float g)
{
  return pdf_ok;
}
pdf_err
x_k(pdf_page *p, float a, float b, float c, float d)
{
  return pdf_ok;
}

pdf_err
x_G(pdf_page *p, float g)
{
  return pdf_ok;
}
pdf_err
x_K(pdf_page *p, float a, float b, float c, float d)
{
  return pdf_ok;
}

pdf_err
x_n(pdf_page *p)
{
  return pdf_ok;
}
pdf_err
x_m(pdf_page *p, float x, float y)
{
  return pdf_ok;
}
pdf_err
x_l(pdf_page *p, float x, float y)
{
  return pdf_ok;
}
pdf_err
x_c(pdf_page *p, float a, float b, float c, float d, float e, float f)
{
  return pdf_ok;
}
pdf_err
x_v(pdf_page *p, float a, float b, float c, float d)
{
  return pdf_ok;
}
pdf_err
x_y(pdf_page *p, float a, float b, float c, float d)
{
  return pdf_ok;
}
/// B group
pdf_err
x_B(pdf_page *p)
{
  return pdf_ok;
}
pdf_err x_Bstar(pdf_page *p)
{
  return pdf_ok;
}

pdf_err x_BI(pdf_page *p)
{
  return pdf_ok;
}
pdf_err x_BT(pdf_page *p)
{
#ifdef DEBUG
  printf("%s ", "BT");
#endif
  return pdf_ok;
}
pdf_err x_BX(pdf_page *p)
{
  return pdf_ok;
}
pdf_err x_BDC(pdf_page *p)
{
  return pdf_ok;
}
pdf_err x_BMC(pdf_page *p)
{
  return pdf_ok;
}
/// T group
pdf_err x_Tstar(pdf_page *p)
{
  return pdf_ok;
}
pdf_err x_Tf(pdf_page *p, void *res, float scale)
{
#ifdef DEBUG
  printf("%s ", "Tf");
#endif
  return pdf_ok;
}
pdf_err x_Tj(pdf_page *p)
{
#ifdef DEBUG
  printf("%s ", "Tj");
#endif
  return pdf_ok;
}
pdf_err x_TJ(pdf_page *p, pdf_obj *o)
{
  int i;
#ifdef DEBUG
  printf("%s ", "TJ");
#endif
  if (o || o->t == eArray)
    {
      for (i=0; i < o->value.a.len; i++)
	{
	  pdf_obj a = o->value.a.items[i];
	  if (a.t == eString)
	    pdf_free(a.value.s.buf);
	}
      if (o->value.a.len)
	pdf_free(o->value.a.items);
    }
  return pdf_ok;
}
pdf_err x_Td(pdf_page *p)
{
#ifdef DEBUG
  printf("%s ", "Td");
#endif
  return pdf_ok;
}
pdf_err x_TD(pdf_page *p)
{
#ifdef DEBUG
  printf("%s ", "TD");
#endif
  return pdf_ok;
}
pdf_err x_TL(pdf_page *p)
{
#ifdef DEBUG
  printf("%s ", "Td");
#endif
  return pdf_ok;
}
pdf_err x_Tm(pdf_page *p, float a, float b, float c, float d, float e, float f)
{
  return pdf_ok;
}
pdf_err x_Tc(pdf_page *p)
{
  return pdf_ok;
}
pdf_err x_Tr(pdf_page *p)
{
  return pdf_ok;
}
pdf_err x_Ts(pdf_page *p)
{
  return pdf_ok;
}
pdf_err x_Tw(pdf_page *p)
{
  return pdf_ok;
}
pdf_err x_Tz(pdf_page *p)
{
  return pdf_ok;
}

/// E group
pdf_err x_ET(pdf_page *p)
{
#ifdef DEBUG
  printf("%s ", "ET");
#endif
  return pdf_ok;
}
pdf_err x_EX(pdf_page *p)
{
  return pdf_ok;
}
pdf_err x_EMC(pdf_page *p)
{
  return pdf_ok;
}
pdf_err x_re(pdf_page *p, float a, float b, float c, float d)
{
  return pdf_ok;
}
pdf_err x_rg(pdf_page *p, float a, float b, float c)
{
  return pdf_ok;
}
pdf_err x_RG(pdf_page *p, float a, float b, float c)
{
  return pdf_ok;
}
pdf_err x_cm(pdf_page *p, float a, float b, float c, float d, float e, float f)
{
  return pdf_ok;
}
pdf_err x_gs(pdf_page *p)
{
  return pdf_ok;
}
////////
pdf_err x_Do(pdf_page *p)
{
  return pdf_ok;
}
