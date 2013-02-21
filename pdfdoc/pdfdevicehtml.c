#include <stdio.h>
#include "pdftypes.h"
#include "pdffilter.h"
#include "pdfdoc.h"
#include "pdfdevice.h"

static void h5_canvas_create(FILE *f, char *id);

static void
pdf_dev_html_doc_begin(pdf_device *dev)
{
      fprintf(dev->dest.f, "%s", "<!DOCTYPE html>");
      fprintf(dev->dest.f, "%s", "<html>");
      fprintf(dev->dest.f, "%s", "<head>");
      fprintf(dev->dest.f, "%s", "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/>");
      fprintf(dev->dest.f, "%s", "</head>\n");
}
static void
pdf_dev_html_doc_end(pdf_device *dev)
{
      fprintf(dev->dest.f, "%s", "\n<body>");
      fprintf(dev->dest.f, "%s", "</body>");
      fprintf(dev->dest.f, "%s", "</html>\n");
}
static void
pdf_dev_html_page_begin(pdf_device *dev, int i, float width, float height)
{
      if (!dev)
	    return;
      if (!dev->dest.f)
	    return;
      dev->dev_ctm.a = 1.0;
      dev->dev_ctm.b = 0.0;
      dev->dev_ctm.c = 0.0;
      dev->dev_ctm.d = -1.0;
      dev->dev_ctm.e = 0.0;
      dev->dev_ctm.f = height;
      dev->dev_bbox.x1 = width;
      dev->dev_bbox.y1 = height;
      fprintf(dev->dest.f, "<canvas id=\"Canvas%d\" width=\"%d\" height=\"%d\"", i+1, (int)width, (int)height);
      fprintf(dev->dest.f, "%s", "style=\"border:1px solid #000000;\">");
      fprintf(dev->dest.f, "%s", "</canvas>");
      h5_canvas_create(dev->dest.f, i+1);
      fprintf(dev->dest.f, "%s", "<script>\n");
}

static void
pdf_dev_html_page_end(pdf_device *dev)
{
      if (!dev)
	    return;
      if (!dev->dest.f)
	    return;
      fprintf(dev->dest.f, "%s", "\n</script>");
      fprintf(dev->dest.f, "%s", "<p>");
      fprintf(dev->dest.f, "%s", "</p>");
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
      gs_matrix fin;

      mat_mul(&fin, ctm, &dev->dev_ctm);
      n = pdf_font_tounicode(f, cid, uni);
      fprintf(dev->dest.f, "ctx.fillText(\"");
      for (i = 0; i < n; i++)
      {
	    if (uni[i] == '\"')
	    {
		  fputc('\\', dev->dest.f);
		  fputc(uni[i], dev->dest.f);
	    }
	    else
		  fputc(uni[i], dev->dest.f);
      }
      fprintf(dev->dest.f, "\",%d,%d);", (int)fin.e, (int)fin.f);
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


// javascript templates
static char *template_canvas =
"<script> \
var c=document.getElementById(\"Canvas%d\"); \
var ctx=c.getContext(\"2d\"); \
ctx.fillStyle=\"#FF0000\"; \
ctx.font=\"12 Arial\"; \
</script>\n";

static void
h5_canvas_create(FILE *f, char *id)
{
      fprintf(f, template_canvas, id);
}
