#include <stdio.h>
#include "pdftypes.h"
#include "pdffilter.h"
#include "pdfdoc.h"
#include "pdfdevice.h"

static void
pdf_dev_text_char_show(pdf_device *dev, pdf_font *f, gs_matrix *ctm, unsigned int cid, unsigned int mode)
{
      unsigned int uni[8];
      int i, n;
      n = pdf_font_tounicode(f, cid, uni);
      for (i = 0; i < n; i++)
      {
	    fputc(uni[i]>>8, dev->dest.f);
	    fputc(uni[i]&0xff, dev->dest.f);
      }
}

pdf_device*
pdf_dev_text_new(FILE *out)
{
      pdf_device *d;
      d = pdf_malloc(sizeof(pdf_device));
      if (!d)
	    return d;
      memset(d, 0, sizeof(pdf_device));
      d->dest.f = out;
      d->fill_char = pdf_dev_text_char_show;
      d->stroke_char = pdf_dev_text_char_show;
      return d;
}
