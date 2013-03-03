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
		  m.x = a;
		  m.y = b;
		  memcpy(p, &m, sizeof(m));
		  gs->path_top += sizeof(m);
	    }
	    break;
	    case L:
	    {
		  path_m l;
		  l.t = t;
		  l.x = a;
		  l.y = b;
		  memcpy(p, &l, sizeof(l));
		  gs->path_top += sizeof(l);
	    }
	    break;
	    case C:
	    {
		  path_c cc;
		  cc.t = t;
		  cc.x1 = a;
		  cc.y1 = b;
		  cc.x2 = c;
		  cc.y2 = d;
		  cc.x3 = e;
		  cc.y3 = f;
		  memcpy(p, &cc, sizeof(cc));
		  gs->path_top += sizeof(cc);
	    }
	    break;
	    case V:
	    {
		  path_v cc;
		  cc.t = t;
		  cc.x2 = a;
		  cc.y2 = b;
		  cc.x3 = c;
		  cc.y3 = d;
		  memcpy(p, &cc, sizeof(cc));
		  gs->path_top += sizeof(cc);
	    }
	    break;
	    case Y:
	    {
		  path_y cc;
		  cc.t = t;
		  cc.x1 = a;
		  cc.y1 = b;
		  cc.x3 = c;
		  cc.y3 = d;
		  memcpy(p, &cc, sizeof(cc));
		  gs->path_top += sizeof(cc);
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
pdf_path_fill(pdf_device *dev, pdf_extgstate *gs, int even_odd)
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
      if (dev && dev->path_paint)
	    (dev->path_paint)(dev, 0, 0, 0);
      gs->path_top = gs->path_base;
      return pdf_ok;
}
