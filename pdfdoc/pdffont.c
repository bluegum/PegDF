#include "pdftypes.h"
#include "pdffont.h"

pdf_font *
pdf_font_load(pdf_obj *o)
{
      pdf_font *f;
      f = pdf_malloc(sizeof(pdf_font));
      return f;
}

void
pdf_font_free(pdf_font *f)
{
      if (f)
	    pdf_free(f);
}
