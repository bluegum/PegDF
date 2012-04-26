#include <assert.h>
#include "pdftypes.h"
#include "pdfdoc.h"
#include "pdfindex.h"
#include "pdfcmds.h"
#include "gsdraw.h"

pdf_err
x_cs(pdf_page *p, pdf_obj o)
{
  pdf_obj *cspace;
  if (p->resources && p->resources->colorspace)
    {
      cspace = p->resources->colorspace;
      assert(cspace->t == eDict);
      cspace = dict_get(cspace->value.d.dict, o.value.k);
      pdf_obj_resolve(cspace);
      pdf_colorspace_set(&(p->s->brush), cspace);
    }
  pdf_obj_delete(&o);
  return pdf_ok;
}

pdf_err
x_CS(pdf_page *p, pdf_obj o)
{
  pdf_obj *cspace;
  if (p->resources && p->resources->colorspace)
    {
      cspace = p->resources->colorspace;
      assert(cspace->t == eDict);
      cspace = dict_get(cspace->value.d.dict, o.value.k);
      pdf_obj_resolve(cspace);
      pdf_colorspace_set(&(p->s->pen), cspace);
    }
  pdf_obj_delete(&o);
  return pdf_ok;
}

pdf_err
x_d(pdf_page *p, pdf_obj o)
{
#ifdef DEBUG
  printf("%s ", "d");
#endif
  if (o.t == eArray)
    {
      pdf_obj_delete(&o);
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
pdf_err x_BDC(pdf_page *p, pdf_obj n, pdf_obj o)
{
  if (o.t == eDict)
    {
      pdf_obj_delete(&o);
    }
  else if (o.t == eKey)
    {
      pdf_obj_delete(&o);
    }

  if (n.t == eKey)
    {
      pdf_obj_delete(&n);
    }
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
pdf_err x_Tf(pdf_page *p, pdf_obj res, float scale)
{
#ifdef DEBUG
  printf("%s ", "Tf");
#endif
  pdf_obj_delete(&res);
  return pdf_ok;
}
pdf_err x_Tj(pdf_page *p, pdf_obj o)
{
#ifdef DEBUG
  printf("%s ", "Tj");
#endif
  pdf_obj_delete(&o);
  return pdf_ok;
}
pdf_err x_TJ(pdf_page *p, pdf_obj o)
{
#ifdef DEBUG
  printf("%s ", "TJ");
#endif
  if (o.t == eArray)
    {
      pdf_obj_delete(&o);
    }
  return pdf_ok;
}
pdf_err x_Td(pdf_page *p, float a, float b)
{
#ifdef DEBUG
  printf("%s ", "Td");
#endif
  return pdf_ok;
}
pdf_err x_TD(pdf_page *p, float a, float b)
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
pdf_err x_gs(pdf_page *p, pdf_obj o)
{
  pdf_obj_delete(&o);
  return pdf_ok;
}
////////
pdf_err x_Do(pdf_page *p, pdf_obj o)
{
  pdf_obj_delete(&o);
  return pdf_ok;
}
