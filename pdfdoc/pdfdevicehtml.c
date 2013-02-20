#include <stdio.h>
#include "pdftypes.h"
#include "pdffilter.h"
#include "pdfdoc.h"
#include "pdfdevice.h"

static void
pdf_dev_html_doc_begin(pdf_device *dev)
{
      fprintf(dev->dest.f, "%s", "<!DOCTYPE html>");
      fprintf(dev->dest.f, "%s", "<html>");
      fprintf(dev->dest.f, "%s", "<body>");
}
static void
pdf_dev_html_doc_end(pdf_device *dev)
{
      fprintf(dev->dest.f, "%s", "</body>");
      fprintf(dev->dest.f, "%s", "</html>");
}
static void
pdf_dev_html_page_begin(pdf_device *dev)
{
      if (dev && dev->dest.f)
      {
	    fprintf(dev->dest.f, "%s", "<p>");
      }
}

static void
pdf_dev_html_page_end(pdf_device *dev)
{
      if (dev && dev->dest.f)
      {
	    fprintf(dev->dest.f, "%s", "</p>");
      }
}

static void
pdf_dev_html_path_paint(pdf_device *d, pdf_path* p, gs_matrix *ctm, int mode)
{
}

static void
pdf_dev_html_char_show(pdf_device *dev, pdf_font *f, gs_matrix *ctm, unsigned int cid, unsigned int mode)
{
      unsigned char uni[8];
      int i, n;
      n = pdf_font_tounicode(f, cid, uni);
      for (i = 0; i < n; i++)
      {
	    fputc(uni[i], dev->dest.f);
      }
}

pdf_device*
pdf_dev_html_new(FILE *out)
{
      pdf_device *d;
      d = pdf_malloc(sizeof(pdf_device));
      if (!d)
	    return d;
      memset(d, 0, sizeof(pdf_device));
      d->dest.f = out;
      d->doc_begin = pdf_dev_html_doc_begin;
      d->doc_end = pdf_dev_html_doc_end;
      d->page_begin = pdf_dev_html_page_begin;
      d->page_end = pdf_dev_html_page_end;
      d->fill_char = pdf_dev_html_char_show;
      d->stroke_char = pdf_dev_html_char_show;
      d->path_paint = pdf_dev_html_path_paint;
      return d;
}
