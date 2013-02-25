#include <stdio.h>
#include <math.h>
#include "pdftypes.h"
#include "gsdraw.h"
#include "pdffilter.h"
#include "pdfdoc.h"
#include "pdfdevice.h"


typedef struct h5_state_s h5_state;
typedef enum font_family_e font_family;

enum font_family_e
{
      eCourier,
      eSerif,
      eSans,
};

struct h5_state_s
{
      float fs; // font scale
      byte c[3]; // color
      int font_flags;
      font_family ff;
      fontname_id fid;
};

static void h5_canvas_create(FILE *f, char *id, byte [3]);
static void hs_canvas_font_update(pdf_device *d, font_family f, fontname_id id, float scale, int, int);
static font_family html_find_font(int font_flags);

static void
pdf_dev_html_doc_begin(pdf_device *dev)
{
      h5_state *s;
      fprintf(dev->dest.f, "%s", "<!DOCTYPE html>");
      fprintf(dev->dest.f, "%s", "<html>");
      fprintf(dev->dest.f, "%s", "<head>");
      fprintf(dev->dest.f, "%s", "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/>");
      fprintf(dev->dest.f, "%s", "</head>\n");
      dev->dest.other = pdf_malloc(sizeof(h5_state));
      s = (h5_state*)dev->dest.other;
      ((h5_state*) dev->dest.other)->fs = 12;
      ((h5_state*) dev->dest.other)->c[0] = 0;
      ((h5_state*) dev->dest.other)->c[1] = 0;
      ((h5_state*) dev->dest.other)->c[2] = 0;
      s->font_flags = 0;
      s->fid = eTimes;
}
static void
pdf_dev_html_doc_end(pdf_device *dev)
{
      fprintf(dev->dest.f, "%s", "\n<body>");
      fprintf(dev->dest.f, "%s", "</body>");
      fprintf(dev->dest.f, "%s", "</html>\n");
      if (dev->dest.other)
	    pdf_free(dev->dest.other);
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
      {
	    h5_state *s;
	    if (!dev->dest.other)
		  return;
	    s = (h5_state*) dev->dest.other;
	    s->fs = -1;
      }
      fprintf(dev->dest.f, "<canvas id=\"Canvas%d\" width=\"%d\" height=\"%d\"", i+1, (int)width, (int)height);
      fprintf(dev->dest.f, "%s", "style=\"border:1px solid #000000;\">");
      fprintf(dev->dest.f, "%s", "</canvas>");
      h5_canvas_create(dev->dest.f, i+1, ((h5_state*) dev->dest.other)->c);
      //fprintf(dev->dest.f, "%s", "<script>\n");
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
pdf_dev_html_color_set(pdf_device *dev, float *c, pdf_cspacetype cs, int n)
{
      static char *template_color = "ctx.fillStyle=\"#%s\";";
      char buf[128];
      h5_state *s;
      float out[3];
      if (!dev->dest.other)
	    return;
      s = (h5_state*) dev->dest.other;
      switch (cs)
      {
	    case DeviceGray:
		  gx_g_to_rgb(c, out);
		  break;
	    case DeviceRGB:
		  gx_rgb_to_rgb(c, out);
		  break;
	    case DeviceCMYK:
		  gx_cmyk_to_rgb(c, out);
		  break;
	    default:
		  if (n == 1)
		  {
			gx_g_to_rgb(c, out);
		  }
		  else if (n == 3)
		  {
			gx_rgb_to_rgb(c, out);
		  }
		  else if (n == 4)
		  {
			gx_cmyk_to_rgb(c, out);
		  }
		  break;
      }
      // quantisizing
      s->c[0] = (byte)(out[0]*255);
      s->c[1] = (byte)(out[1]*255);
      s->c[2] = (byte)(out[2]*255);
      sprintf(buf, "%02X%02X%02X", s->c[0], s->c[1], s->c[2]);
      fprintf(dev->dest.f, template_color, buf);
}

#define min(a, b) ((a)<(b)?(a):(b))

static void
pdf_dev_html_char_show(pdf_device *dev, pdf_font *f, float scale, gs_matrix *ctm, unsigned int cid, unsigned int mode)
{
      unsigned char uni[8];
      int i, n;
      gs_matrix fin;
      int font_flags;
      h5_state *s = (h5_state*)dev->dest.other;
      font_family family = eSans;
      // PDF spec problem: type3 font don't scale well with TEXT CTM
      // hack, should be html5/canvas' save() and restore()
      if (scale == 1 && ctm->b == 0 && ctm->c == 0)
      {
	    scale = fabs(ctm->a);
      }
      else
      {
	    scale = scale * min(fabs(ctm->a), fabs(ctm->d));
      }
      // updating font?
      if (s)
      {
	    family = s->ff;
	    font_flags = pdf_font_flags_get(f);
	    if (s->font_flags != font_flags)
	    {
		  s->font_flags = font_flags;
		  family = html_find_font(font_flags);
	    }
      }

      hs_canvas_font_update(dev, family, pdf_font_basefont_id_get(f), scale, font_flags & FFLAGS_FORCEBOLD, font_flags & FFLAGS_ITALIC);
      mat_mul(&fin, ctm, &dev->dev_ctm);
      n = pdf_font_tounicode(f, cid, uni);
      fprintf(dev->dest.f, "ctx.fillText(\"");
      for (i = 0; i < n; i++)
      {
	    if (uni[i] == '\"')
	    {
		  fputc('\\', dev->dest.f);
	    }
	    else if (uni[i] == '\\')
	    {
		  fputc('\\', dev->dest.f);
	    }
	    fputc(uni[i], dev->dest.f);
      }
      fprintf(dev->dest.f, "\",%d,%d);\n", (int)fin.e, (int)fin.f);
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
      d->color_set = pdf_dev_html_color_set;
      return d;
}


// javascript templates
static char *template_canvas =
"<script> \
var c=document.getElementById(\"Canvas%d\"); \
var ctx=c.getContext(\"2d\"); \
ctx.fillStyle=\"#%s\"; \
ctx.font=\"12 Arial\";";

static void
h5_canvas_create(FILE *f, char *id, byte c[3])
{
      char buf[8];
      sprintf(buf, "%02X%02X%02X", c[0], c[1], c[2]);
      fprintf(f, template_canvas, id, buf);
}

static void
hs_canvas_font_update(pdf_device *dev, font_family family, fontname_id id, float scale, int bold, int italic)
{
      static char *template_font ="ctx.font=\"%s %s %fpx %s\";";
      h5_state *s;
      if (!dev->dest.other)
	    return;
      s = (h5_state*) dev->dest.other;
      if (s->fs != scale || s->ff != family || s->fid != id)
      {
	    s->fs = scale;
	    s->ff = family;
	    s->fid = id;
	    switch (id)
	    {
		  case eTimes:
			fprintf(dev->dest.f, template_font,italic?"italic ":" ", bold?"bold ":" ",  scale, "Times");
			break;
		  case eArial:
			fprintf(dev->dest.f, template_font, italic?"italic ":" ", bold?"bold ":" ",  scale, "Arial");
			break;
		  case eMonaco:
			fprintf(dev->dest.f, template_font, italic?"italic ":" ", bold?"bold ":" ",  scale, "Monaco");
			break;
		  default:
			switch (family)
			{
			      case eCourier:
				    fprintf(dev->dest.f, template_font,italic?"italic ":" ", bold?"bold ":" ",  scale, "Courier");
				    break;
			      case eSerif:
				    fprintf(dev->dest.f, template_font, italic?"italic ":" ", bold?"bold ":" ",  scale, "Times");
				    break;
			      case eSans:
			      default:
				    fprintf(dev->dest.f, template_font, italic?"italic ":" ", bold?"bold ":" ",  scale, "Arial");
				    break;
			}
			break;
	    }
      }
}

static font_family
html_find_font(int font_flags)
{
      font_family family;

      if (font_flags & FFLAGS_FIXEDPITCH)
      {
	    family = eCourier;
      }
      else
      {
	    if (font_flags & FFLAGS_SERIF)
		  family = eSerif;
	    else
		  family = eSans;
      }
      return family;
}
