#include <stdio.h>
#include <assert.h>
#include "pdftypes.h"
#include "pdffilter.h"
#include "pdfdoc.h"
#include "pdfindex.h"
#include "pdfcmds.h"
#include "gsdraw.h"
#include "pdffont.h"
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

pdf_err x_BI(pdf_page *p, pdf_obj o)
{
      _DMSG("BI");
      if (o.t == eDict)
      {
	    dict_free(o.value.d.dict);
      }
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
      pdf_font *font = NULL;

      _DMSG("Tf");
      p->s->gs.fs = scale;
      if (p->resources && p->resources->font)
      {
            r = p->resources->font;
            pdf_obj_resolve(r);
            assert(r->t == eDict);
            f = dict_get(r->value.d.dict, res.value.k);
	    if (f)
	    {
		  if (p->i->font && f->t == eRef)
		  {
			font = pdf_font_find(p->i->font, f->value.r.num);
		  }
		  if (!font)
		  {
			font = pdf_font_load(f, 1, p->i->crypto);
			pdf_interpreter_font_insert(p->i, font);
		  }
		  p->i->cur_font = font;
	    }
      }
      pdf_obj_delete(&res);
      return pdf_ok;
}
pdf_err x_Tj(pdf_page *p, pdf_obj o)
{
      int i;
      gs_matrix ctm;
      _DMSG("Tj");
      mat_set(&ctm, p->s->gs.txt_ctm);
      if ((o.t == eString) || (o.t == eHexString))
      {
	    pdf_font *f = p->i->cur_font;
	    for (i = 0; i < o.value.s.len;)
	    {
		  int step =
			pdf_character_show(p->i->dev, p->s, f, &ctm, o.value.s.buf+i);
		  if (step == 0)
			break;
		  i += step;
		  // TODO: use per glyph width
		  ctm.e += p->s->gs.fs;
	    }
      }
      pdf_obj_delete(&o);
      return pdf_ok;
}
pdf_err x_TJ(pdf_page *p, pdf_obj o)
{
      int i;
      gs_matrix ctm;
      float advance;
      _DMSG("TJ");
      if (o.t == eArray)
      {
	    mat_set(&ctm, p->s->gs.txt_ctm);
	    for (i = 0; i < o.value.a.len; i++)
	    {
		  pdf_obj *a = &o.value.a.items[i];
		  if (i%2)
		  {
			advance = a->value.f;
		  }
		  else
		  {
			if (o.value.a.items[i].t == eString)
			{
			      int j;
			      pdf_obj *a = &o.value.a.items[i];
			      pdf_font *f = p->i->cur_font;
			      for (j = 0; j < a->value.s.len;)
			      {
				    int step =
				    pdf_character_show(p->i->dev, p->s, f, &ctm, a->value.s.buf+j);
				    if (!step)
					  break;
				    j += step;
				    ctm.e += p->s->gs.fs;
			      }
			}
		  }
	    }
            pdf_obj_delete(&o);
      }
      return pdf_ok;
}
pdf_err x_Td(pdf_page *p, float a, float b)
{
      gs_matrix ctm, fin;
      _DMSG("Td");
      ctm.a = 1;
      ctm.b = 0;
      ctm.c = 0;
      ctm.d = 1;
      ctm.e = a;
      ctm.f = b;
      mat_mul(&fin, &ctm, p->s->gs.txt_ctm);
      memcpy(p->s->gs.txt_ctm, &fin, sizeof(fin));
      return pdf_ok;
}
pdf_err x_TD(pdf_page *p, float a, float b)
{
      gs_matrix ctm, fin;
      _DMSG("TD");
      ctm.a = 1;
      ctm.b = 0;
      ctm.c = 0;
      ctm.d = 1;
      ctm.e = a;
      ctm.f = b;
      mat_mul(&fin, &ctm, p->s->gs.txt_ctm);
      memcpy(p->s->gs.txt_ctm, &ctm, sizeof(ctm));
      return pdf_ok;
}
pdf_err x_TL(pdf_page *p, float tl)
{
      _DMSG("TL");
      p->s->gs.tl = tl;
      return pdf_ok;
}
pdf_err x_Tm(pdf_page *p, float a, float b, float c, float d, float e, float f)
{
      p->s->gs.txt_ctm[0] = a;
      p->s->gs.txt_ctm[1] = b;
      p->s->gs.txt_ctm[2] = c;
      p->s->gs.txt_ctm[3] = d;
      p->s->gs.txt_ctm[4] = e;
      p->s->gs.txt_ctm[5] = f;
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
	    pdf_obj_resolve(x);
            assert(x->t == eDict);
            x = dict_get(x->value.d.dict, o.value.k);
            pdf_obj_resolve(x);
      }
      pdf_obj_delete(&o);
      return pdf_ok;
}
