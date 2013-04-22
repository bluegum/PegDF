#ifndef PDF_PRIV_H
#define PDF_PRIV_H

#include "pdfindex.h"

static inline gs_rect
pdf_rect_resolve(pdf_obj *o)
{
      gs_rect r={0,0,0,0};
      if (!o || (o->t != eArray && o->t != eRef))
            return r;
      pdf_obj_resolve(o);
      // should handle floating point value as well.
      if (o->value.a.items[0].t == eInt)
	    r.x0 = o->value.a.items[0].value.i;
      else if (o->value.a.items[0].t == eReal)
	    r.x0 = o->value.a.items[0].value.f;
      if (o->value.a.items[1].t == eInt)
	    r.y0 = o->value.a.items[1].value.i;
      else if (o->value.a.items[1].t == eReal)
	    r.y0 = o->value.a.items[1].value.f;
      if (o->value.a.items[2].t == eInt)
	    r.x1 = o->value.a.items[2].value.i;
      else if (o->value.a.items[2].t == eReal)
	    r.x1 = o->value.a.items[2].value.f;
      if (o->value.a.items[3].t == eInt)
	    r.y1 = o->value.a.items[3].value.i;
      else if (o->value.a.items[3].t == eReal)
	    r.y1 = o->value.a.items[3].value.f;
      return r;
}

#endif
