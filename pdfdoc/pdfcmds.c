#include <assert.h>
#include "pdftypes.h"
#include "pdffilter.h"
#include "pdfdoc.h"
#include "pdfindex.h"
#include "pdfcmds.h"
#include "gsdraw.h"
#include "pdfread.h" // for _DMSG
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
      _DMSG("op: d");
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
pdf_err
x_i(pdf_page *p, float flatness)
{
      return pdf_ok;
}
pdf_err
x_j(pdf_page *p, int linejoin)
{
      return pdf_ok;
}
pdf_err
x_J(pdf_page *p, int linecap)
{
      return pdf_ok;
}
pdf_err
x_w(pdf_page *p, float linewidth)
{
      return pdf_ok;
}
pdf_err
x_M(pdf_page *p, float miterlimit)
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
      _DMSG("BT");
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
      pdf_obj *r, *f;
      _DMSG("Tf");
      if (p->resources && p->resources->font)
      {
            r = p->resources->font;
            pdf_obj_resolve(r);
            assert(r->t == eDict);
            f = dict_get(r->value.d.dict, res.value.k);
            pdf_obj_resolve(f);
      }
      pdf_obj_delete(&res);
      return pdf_ok;
}
pdf_err x_Tj(pdf_page *p, pdf_obj o)
{
      _DMSG("Tj");
      pdf_obj_delete(&o);
      return pdf_ok;
}
pdf_err x_TJ(pdf_page *p, pdf_obj o)
{
      _DMSG("TJ");
      if (o.t == eArray)
      {
            pdf_obj_delete(&o);
      }
      return pdf_ok;
}
pdf_err x_Td(pdf_page *p, float a, float b)
{
      _DMSG("Td");
      return pdf_ok;
}
pdf_err x_TD(pdf_page *p, float a, float b)
{
      _DMSG("TD");
      return pdf_ok;
}
pdf_err x_TL(pdf_page *p)
{
      _DMSG("Td");
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
      _DMSG("ET");
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
      pdf_resources *r = p->resources;
      pdf_obj *extg, *thisg;
      pdf_extgstate* g = NULL;
      if (o.t != eKey)
	    return pdf_ok;
      // find it in resources
      extg = r->extgstate;
      pdf_obj_resolve(extg);
      thisg = dict_get(extg->value.d.dict, o.value.k);
      if (thisg)
	    pdf_obj_resolve(thisg);
      g = pdf_extgstate_load(thisg);
      // TODO: save g in interpreter state
      if (g) pdf_extgstate_free(g);
      pdf_obj_delete(&o);
      return pdf_ok;
}
pdf_err x_ri(pdf_page *p, pdf_obj o)
{
      pdf_obj_delete(&o);
      return pdf_ok;
}
pdf_err x_sh(pdf_page *p, pdf_obj o)
{
      pdf_obj_delete(&o);
      return pdf_ok;
}
////////
pdf_err x_Do(pdf_page *p, pdf_obj o)
{
      pdf_obj *x;
      assert(o.t == eKey);
      if (p->resources && p->resources->xobject)
      {
            x = p->resources->xobject;
            assert(x->t == eDict);
            x = dict_get(x->value.d.dict, o.value.k);
            pdf_obj_resolve(x);
      }
      pdf_obj_delete(&o);
      return pdf_ok;
}
