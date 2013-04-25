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
      eMonoSpace,
      eSerif,
      eSans,
};

struct h5_state_s
{
      float fs; // font scale
      byte brush[3]; // color
      byte pen[3]; // color
      int font_flags;
      font_family ff;
      fontname_id fid;
      int path_flag;
};

static void h5_canvas_create(FILE *f, char *id, byte [3]);
static void hs_canvas_font_update(pdf_device *d, font_family f, fontname_id id, float scale, int, int);
static font_family html_find_font(int font_flags);

static void html_info_write(pdf_device *dev, pdf_info *info)
{
    if (info->title)
        fprintf(dev->dest.f, "<title>%s</title>", info->title);
    if (info->keywords)
        fprintf(dev->dest.f, "<meta name=\"keywords\" content=\"%s\">", info->keywords);
    if (info->author)
        fprintf(dev->dest.f, "<meta name=\"author\" content=\"%s\">", info->author);
}

static void
pdf_dev_html_doc_begin(pdf_device *dev, pdf_info *i)
{
      h5_state *s = (h5_state*) dev->dest.other;
      fprintf(dev->dest.f, "%s", "<!DOCTYPE html>");
      fprintf(dev->dest.f, "%s", "<html>");
      fprintf(dev->dest.f, "%s", "<head>");
      fprintf(dev->dest.f, "%s", "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/>");
      if (i)
          html_info_write(dev, i);
      fprintf(dev->dest.f, "%s", "</head>");
      dev->dest.other = pdf_malloc(sizeof(h5_state));
      s = (h5_state*)dev->dest.other;
      ((h5_state*) dev->dest.other)->fs = 12;
      s->brush[0] = 0;
      s->brush[1] = 0;
      s->brush[2] = 0;
      s->pen[0] = 0;
      s->pen[1] = 0;
      s->pen[2] = 0;
      s->font_flags = 0;
      s->fid = eTimes;
      s->path_flag = 0;
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
      h5_canvas_create(dev->dest.f, i+1, ((h5_state*) dev->dest.other)->brush);
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
pdf_dev_html_path_add(pdf_device *dev, byte *p, int n)
{
      e_path_kind t = (e_path_kind)(p[0]);
      float x, y;
      h5_state *s;

      s = (h5_state*) dev->dest.other;

      if (s->path_flag == 0)
      {
	    fprintf(dev->dest.f, "ctx.beginPath();");
	    s->path_flag = 1;
      }

      switch (t)
      {
	    case M:
	    {
		  path_m *mm = (path_m*)p;
		  mat_pt(&dev->dev_ctm, mm->x, mm->y, &x, &y);
		  fprintf(dev->dest.f, "ctx.moveTo(%f,%f);", x, y);
		  break;
	    }
	    case L:
	    {
		  path_l *ll = (path_l*)p;
		  mat_pt(&dev->dev_ctm, ll->x, ll->y, &x, &y);
		  fprintf(dev->dest.f, "ctx.lineTo(%f,%f);", x, y);
		  break;
	    }
	    case C:
	    {
		  path_c *cc = (path_c*)p;
		  float x2, y2, x3, y3;

		  mat_pt(&dev->dev_ctm, cc->x1, cc->y1, &x, &y);
		  mat_pt(&dev->dev_ctm, cc->x2, cc->y2, &x2, &y2);
		  mat_pt(&dev->dev_ctm, cc->x3, cc->y3, &x3, &y3);
		  fprintf(dev->dest.f, "ctx.bezierCurveTo(%f,%f,%f,%f,%f,%f);", x, y, x2, y2, x3, y3);
		  break;
	    }
	    case V:
	    {
		  path_v *vv = (path_v*)p;
		  float x2, y2, x3, y3;

		  mat_pt(&dev->dev_ctm, vv->x2, vv->y2, &x2, &y2);
		  mat_pt(&dev->dev_ctm, vv->x3, vv->y3, &x3, &y3);
		  fprintf(dev->dest.f, "ctx. quadraticCurveTo(%f,%f,%f,%f);", x2, y2, x3, y3);
		  break;
	    }
	    case Y:
	    {
		  path_y *yy = (path_y*)p;
		  float x3, y3;

		  mat_pt(&dev->dev_ctm, yy->x1, yy->y1, &x, &y);
		  mat_pt(&dev->dev_ctm, yy->x3, yy->y3, &x3, &y3);
		  fprintf(dev->dest.f, "ctx.bezierCurveTo(%f,%f,%f,%f,%f,%f);", x, y, x3, y3, x3, y3);
		  break;
	    }
	    case RE:
	    {
		  path_re *re = (path_re*)p;
		  float w, h;
		  mat_pt(&dev->dev_ctm, re->x, re->y, &x, &y);
		  mat_pt(&dev->dev_ctm, re->x + re->w, re->y + re->h, &w, &h);
		  w -= x;
		  h -= y;
		  //w = fabs(w);
		  //h = fabs(h);
		  fprintf(dev->dest.f, "ctx.rect(%f,%f,%f,%f);", x, y, w, h);
		  break;
	    }
	    default:
		  break;
      }
}

static void
pdf_dev_html_path_stroke(pdf_device *d, stroke_state *ss)
{
      h5_state *s;
      s = (h5_state*) d->dest.other;
      if (ss)
      {
	    if (ss->lw < 1)
		  fprintf(d->dest.f, "ctx.lineWidth=1;");
	    else
		  fprintf(d->dest.f, "ctx.lineWidth=%f;", ss->lw);
	    switch (ss->lc)
	    {
		  case 0:
			fprintf(d->dest.f, "ctx.lineCap=\'butt\';");
			break;
		  case 1:
			fprintf(d->dest.f, "ctx.lineCap = \'round\';");
			break;
		  case 2:
			fprintf(d->dest.f, "ctx.lineCap = \'square\';");
			break;
		  default:
			break;
	    }
	    switch (ss->lj)
	    {
		  case 0:
			fprintf(d->dest.f, "ctx.lineJoin=\"bevel\";");
			break;
		  case 1:
			fprintf(d->dest.f, "ctx.lineJoin=\"round\";");
			break;
		  case 2:
			fprintf(d->dest.f, "ctx.lineJoin=\"miter\";");
			break;
		  default:
			break;
	    }
#if 0
	    if (ss->dash_n)
	    {
		  int i;
		  fprintf(d->dest.f, "ctx.setLineDash\([");
		  for (i = 0; i < ss->dash_n - 1; i++)
			fprintf(d->dest.f, "%f,", ss->dash[i]);
		  fprintf(d->dest.f, "%f", ss->dash[i]);
		  fprintf(d->dest.f, "]\);");
		  fprintf(d->dest.f, "ctx.lineDashOffset=%d;", ss->dash_offset);
	    }
	    else
	    {
		  fprintf(d->dest.f, "ctx.setLineDash\(\);");
	    }
#endif
      }
      fprintf(d->dest.f, "ctx.strokeStyle=\"#%02X%02X%02X\";", s->pen[0], s->pen[1], s->pen[2]);
      fprintf(d->dest.f, "ctx.stroke();");
      s->path_flag = 0;
}

static void
pdf_dev_html_path_fill(pdf_device *d, int mode)
{
      h5_state *s;
      s = (h5_state*) d->dest.other;
      fprintf(d->dest.f, "%s;", "ctx.closePath();");
      fprintf(d->dest.f, "%s;", "ctx.fill();");
      s->path_flag = 0;
}

static void
pdf_dev_html_color_set(pdf_device *dev, float *c, pdf_cspacetype cs, int n, int pen)
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
      if (pen)
      {
	    s->pen[0] = (byte)(out[0]*255);
	    s->pen[1] = (byte)(out[1]*255);
	    s->pen[2] = (byte)(out[2]*255);
	    fprintf(dev->dest.f, "ctx.strokeStyle=\"#%02X%02X%02X\";", s->pen[0], s->pen[1], s->pen[2]);
      }
      else
      {
	    s->brush[0] = (byte)(out[0]*255);
	    s->brush[1] = (byte)(out[1]*255);
	    s->brush[2] = (byte)(out[2]*255);
	    fprintf(dev->dest.f, "ctx.fillStyle=\"#%02X%02X%02X\";", s->brush[0], s->brush[1], s->brush[2]);
      }
      //sprintf(buf, "%02X%02X%02X", s->c[0], s->c[1], s->c[2]);
      //fprintf(dev->dest.f, template_color, buf);
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
      switch (n)
      {
	    case 1:
		  switch (uni[0])
		  {
			case  '\(':
			case  ')':
			case  '\'':
			case  '`':
			case  '\"':
			case  '\\':
			{
			      fputc('\\', dev->dest.f);
			      fputc(uni[0], dev->dest.f);
			}
			break;
			case 11:
			case 12:
			case 13:
			case 14:
			      break;
			default:
			      fputc(uni[0], dev->dest.f);
			      break;
		  }
		  break;
	    default:
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
		  break;
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
      d->path_fill = pdf_dev_html_path_fill;
      d->path_stroke = pdf_dev_html_path_stroke;
      d->color_set = pdf_dev_html_color_set;
      d->path_add = pdf_dev_html_path_add;
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
		  case eHelvetica:
			fprintf(dev->dest.f, template_font, italic?"italic ":" ", bold?"bold ":" ",  scale, "Helvetica");
			break;
		  case eCourier:
			fprintf(dev->dest.f, template_font, italic?"italic ":" ", bold?"bold ":" ",  scale, "Courier");
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
			      case eMonoSpace:
				    fprintf(dev->dest.f, template_font,italic?"italic ":" ", bold?"bold ":" ",  scale, "Courier");
				    break;
			      case eSans:
				    fprintf(dev->dest.f, template_font, italic?"italic ":" ", bold?"bold ":" ",  scale, "Arial");
				    break;
			      case eSerif:
			      default:
				    fprintf(dev->dest.f, template_font, italic?"italic ":" ", bold?"bold ":" ",  scale, "Times");
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
	    family = eMonoSpace;
      }
      else
      {
	    if (font_flags & FFLAGS_SERIF)
		  family = eSerif;
	    else if (font_flags & FFLAGS_SYMBOLIC)
		  family = eSerif;
	    else
		  family = eSans;
      }
      return family;
}
