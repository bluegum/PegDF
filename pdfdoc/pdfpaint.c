#include <stdio.h>
#include "pdfdoc.h"
#include "pdfpaint.h"

pdf_path_segment *
pdf_path_segment_new(pdf_path_kind e)
{
      return 0;
}
void
pdf_path_add(pdf_extgstate *gs, e_path_kind t, float a, float b, float c, float d, float e, float f)
{
      byte *p = gs->path_top;
      switch (t)
      {
	    case M:
	    {
		  path_m m;
		  m.t = t;
		  mat_pt(&gs->ctm, a, b, &m.x, &m.y);
		  memcpy(p, &m, sizeof(m));
		  gs->path_top += sizeof(m);
	    }
	    break;
	    case L:
	    {
		  path_m l;
		  l.t = t;
		  mat_pt(&gs->ctm, a, b, &l.x, &l.y);
		  memcpy(p, &l, sizeof(l));
		  gs->path_top += sizeof(l);
	    }
	    break;
	    case C:
	    {
		  path_c cc;
		  cc.t = t;
		  mat_pt(&gs->ctm, a, b, &cc.x1, &cc.y1);
		  mat_pt(&gs->ctm, c, d, &cc.x2, &cc.y2);
		  mat_pt(&gs->ctm, e, f, &cc.x3, &cc.y3);
		  memcpy(p, &cc, sizeof(cc));
		  gs->path_top += sizeof(cc);
	    }
	    break;
	    case V:
	    {
		  path_v vv;
		  vv.t = t;
		  mat_pt(&gs->ctm, a, b, &vv.x2, &vv.y2);
		  mat_pt(&gs->ctm, c, d, &vv.x3, &vv.y3);
		  memcpy(p, &vv, sizeof(vv));
		  gs->path_top += sizeof(vv);
	    }
	    break;
	    case Y:
	    {
		  path_y yy;
		  yy.t = t;
		  mat_pt(&gs->ctm, a, b, &yy.x1, &yy.y1);
		  mat_pt(&gs->ctm, c, d, &yy.x3, &yy.y3);
		  memcpy(p, &yy, sizeof(yy));
		  gs->path_top += sizeof(yy);
	    }
	    break;
	    case H:
	    {
		  path_h h;
		  h.t = t;
		  memcpy(p, &h, sizeof(h));
		  gs->path_top += sizeof(h);
	    }
	    break;
	    case RE:
	    {
		  path_re re;
		  float x1, y1;
		  re.t = t;
		  mat_pt(&gs->ctm, a, b, &re.x, &re.y);
		  mat_pt(&gs->ctm, a+c, b+d, &x1, &y1);
		  re.w = x1 - re.x;
		  re.h = y1 - re.y;
		  memcpy(p, &re, sizeof(re));
		  gs->path_top += sizeof(re);
	    }
	    break;
	    default:
		  break;
      }
}

static void
pdf_device_path_add(pdf_device *d, byte *p, int n)
{
      if (d && d->path_add)
	    (d->path_add)(d, p, n);
}

pdf_err
pdf_path_paint(pdf_device *dev, pdf_extgstate *gs, int stroke, int even_odd)
{
      byte *base = gs->path_base;
      byte *top = gs->path_top;
      byte *p = base;
      while (p<top)
      {
	    e_path_kind t = (e_path_kind)(p[0]);
	    switch (t)
	    {
		  case M:
			pdf_device_path_add(dev, p, sizeof(path_m));
			p += sizeof(path_m);
			break;
		  case L:
			pdf_device_path_add(dev, p, sizeof(path_l));
			p += sizeof(path_l);
			break;
		  case C:
			pdf_device_path_add(dev, p, sizeof(path_c));
			p += sizeof(path_c);
			break;
		  case V:
			pdf_device_path_add(dev, p, sizeof(path_v));
			p += sizeof(path_v);
			break;
		  case Y:
			pdf_device_path_add(dev, p, sizeof(path_y));
			p += sizeof(path_y);
			break;
		  case H:
			pdf_device_path_add(dev, p, sizeof(path_h));
			p += sizeof(path_h);
			break;
		  case RE:
			pdf_device_path_add(dev, p, sizeof(path_re));
			p += sizeof(path_re);
			break;
		  default:
			p = top;
			break;
	    }
      }
      if (stroke)
      {
	    stroke_state ss;
	    ss.lw = gs->LW;
	    ss.ml = gs->ML;
	    ss.lj = gs->LJ;
	    ss.lc = gs->LC;
	    memcpy(&ss.dash, gs->D, sizeof(float)*gs->D_n);
	    ss.dash_n = gs->D_n;
	    ss.dash_offset = gs->D_OFFSET;
	    if (dev && dev->path_stroke)
		  (dev->path_stroke)(dev, &ss);
      }
      else
      {
	    if (dev && dev->path_fill)
		  (dev->path_fill)(dev, 0);
      }
      gs->path_top = gs->path_base;
      return pdf_ok;
}
