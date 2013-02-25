#include <stdio.h>
#include "pdftypes.h"
#include "pdfindex.h"
#include "dict.h"
#include "pdffilter.h"
#include "pdffont.h"
#include "pdfencodingtable.c"
#include "glyph_name_to_uni.c"
#include "pdfcrypto.h"
#include "pdfdoc.h"

static const char * get_glyph_name(pdf_font_encoding *e, unsigned int c);

static unsigned int get_cid_simple(unsigned char *c, int *cid) { *cid = c[0];return 1; }
static int unicode_get_stub(pdf_font *f, unsigned int c, unsigned int *uni) { *uni = c; return 1; }

static const int ascii_to_int[] = {
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,
0,10,11,12,13,14,15,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,10,11,12,13,14,15,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};

unsigned int asciihex2int(unsigned char *c)
{
      unsigned int i;
      i = ((ascii_to_int[c[0]]<<4) +
	   (ascii_to_int[c[1]]));
      if (c[2])
      {
	    i = (i << 8) + (ascii_to_int[c[2]]<<4) + (ascii_to_int[c[3]]);
      }
      return i;
}
static unsigned int get_cid_identity(unsigned char *c, int *cid)
{
      *cid = asciihex2int(c);
      return 4;
}

// extract unicode from char code for simple fonts
static int unicode_get_simple(pdf_font *f, unsigned int c, unsigned int *uni)
{
      pdf_font_encoding *e;
      const char *gname = 0;
      *uni = c;
      if (!f)
	    return 1;
      e = f->encoding;
      if (!e)
	    return 1;
      gname = get_glyph_name(e, c);
      if (gname)
      {
	    const struct glyphlist *gl = glyph_name_to_uni(gname, strlen(gname));
	    if (gl)
	    {
		  // parse hax string
		  int i = 1;
		  unsigned int n = 0;
		  unsigned char *ptr = (unsigned char*)gl->unicode;
		  while (*ptr)
		  {
			if (*ptr == ' ')
			{
			      uni[i++] = n;
			      i++;
			}
			else
			{
			      n <<= 8;
			      n += ascii_to_int[*ptr];
			}
			ptr++;
		  }
		  return i;
	    }
	    else
	    {
		  return 1;
	    }
      }
}

static const char * get_glyph_name(pdf_font_encoding *e, unsigned int c)
{
      const char *p = 0;
      if (c > 255)
	    return 0;
      if (e->differences)
      {
	    return e->differences[c];
      }

      switch (e->type)
      {
	    case StandardEncoding:
		  p = standard_encoding[c];
		  break;
	    case WinAnsiEncoding:
		  p = win_ansi_encoding[c];
		  break;
	    case MacRomanEncoding:
		  p = mac_roman_encoding[c];
		  break;
	    case MacExpertEncoding:
		  p = expert_encoding[c];
		  break;
	    case Symbol:
		  p = symbol_encoding[c];
		  break;
	    case ZapfDingbat:
		  p = zapf_dingbats_encoding[c];
		  break;
	    default:
		  break;
      }
      return p;
}

void
pdf_encoding_free(pdf_font_encoding *p)
{
      if (p)
      {
	    if (p->differences)
		  pdf_free(p->differences);
	    pdf_free(p);
      }
}

void
pdf_font_widths_load(pdf_obj *a, pdf_font* f)
{
      int i;
      pdf_obj *val, *w = pdf_obj_deref(a);
      if (!w || w->t != eDict)
	    return;
      val = dict_get(w->value.d.dict, "Widths");
      if (!val)
      {
	    f->widths = 0;
	    return;
      }
      val = pdf_obj_deref(val);
      if  (!val || val->t != eArray)
	    return;
      f->widths = pdf_malloc(sizeof(float)*val->value.a.len);
      if (!f->widths)
	    return;
      for (i = 0; i < val->value.a.len; i++)
      {
	    if (val->value.a.items[i].t == eReal)
	    {
		  f->widths[i] = val->value.a.items[i].value.f;
	    }
	    else
	    {
		  f->widths[i] = val->value.a.items[i].value.i;
	    }
      }
      val = dict_get(w->value.d.dict, "FirstChar");
      if (val)
	    f->firstchar = val->value.i;
      val = dict_get(w->value.d.dict, "LastChar");
      if (val)
	    f->lastchar = val->value.i;
}

float
pdf_font_widths_get(pdf_font* f, u32 cid)
{
      if (!f || (!f->widths))
	    return 1000;
      if (cid > f->lastchar)
	    return 1000;
      return f->widths[cid-f->firstchar];
}

void
pdf_encoding_load(pdf_obj *a, pdf_font_encoding* e)
{
      const char **tbl = standard_encoding;
      if (!a)
      {
	    e->type = StandardEncoding;
	    e->get_glyph_name = get_glyph_name;
	    e->get_cid = get_cid_simple;
	    return;
      }
      if (a->t == eKey)
      {
	restart:
	    if (strncmp(a->value.k, "WinAnsiEncoding", sizeof("WinAnsiEncoding")) == 0)
	    {
		  e->type = WinAnsiEncoding;
		  tbl = win_ansi_encoding;
	    }
	    else if (strncmp(a->value.k, "MacRomanEncoding", sizeof("MacRomanEncoding")) == 0)
	    {
		  e->type = MacRomanEncoding;
		  tbl = mac_roman_encoding;
	    }
	    else if (strncmp(a->value.k, "MacExpertEncoding", sizeof("MacExpertEncoding")) == 0)
	    {
		  e->type = MacExpertEncoding;
		  tbl = mac_expert_encoding;
	    }
	    else
	    {
		  e->type = StandardEncoding;
	    }
	    e->get_glyph_name = get_glyph_name;
	    if (a->t == eDict || a->t == eRef)
		  goto restart_follow;
      }
      else if (a->t == eDict || a->t == eRef)
      {
	    pdf_obj *o;
	    pdf_obj_resolve(a);
	    if (!a)
		  return;
	    o = dict_get(a->value.d.dict, "BaseEncoding");
	    if (o && o->t == eKey)
	    {
		  goto restart;
	    }
	    else
	    {
		  e->type = StandardEncoding;
	    }
	restart_follow:
	    o = dict_get(a->value.d.dict, "Differences");
	    if (o && o->t == eArray)
	    {
		  int i;
		  e->differences = pdf_malloc(sizeof(char*)*256);
		  if (e->differences)
			memcpy(e->differences, &tbl[0], sizeof(char*)*256);
		  // parse differences array and merge with pre defined encodings
		  for (i = 0; i < o->value.a.len;)
		  {
			pdf_obj dd = o->value.a.items[i];
			int j = dd.value.i;
			if (j < 256)
			{
			      i++;
			      while (o->value.a.items[i].t == eKey)
			      {
				    struct glyphlist *gl = glyph_name_to_uni(o->value.a.items[i].value.k, strlen(o->value.a.items[i].value.k));
				    if (gl)
					  e->differences[j] = gl->name;
				    if (i++ >= o->value.a.len)
					  break;
				    if (j++ > 255)
					  break;
			      }
			}
			
		  }
	    }
      }
      e->get_cid = get_cid_simple;
}

void
pdf_cid_encoding_load(pdf_obj *a, pdf_font_encoding* e)
{
      if (a->t == eKey)
      {
	    if (strncmp(a->value.k, "Identity-H", sizeof("Identity-H")) == 0)
	    {
		  e->get_cid = get_cid_identity;
		  e->type = Identity_H;
	    }
	    else if (strncmp(a->value.k, "Identity-V", sizeof("Identity-V")) == 0)
	    {
		  e->get_cid = get_cid_identity;
		  e->type = Identity_V;
	    }
      }
      else if (a->t == eDict)
      {
	    // todo
      }
}

pdf_font_descriptor *
pdf_font_descriptor_load(pdf_obj *o)
{
      int flags = 0;
      pdf_obj *fontname;
      pdf_font_descriptor *d;
      pdf_obj *val, *a = pdf_obj_deref(o);
      if (!a || a->t != eDict)
	    return 0;
      val = dict_get(a->value.d.dict, "Flags");
      if (!val)
      {
	    return 0;
      }
      if (val && val->t == eInt)
      {
	    flags = val->value.i;
      }
      fontname = dict_get(a->value.d.dict, "FontName");
      if (!fontname)
      {
	    return 0;
      }
      // load
      d = (pdf_font_descriptor*)pdf_malloc(sizeof(pdf_font_descriptor));
      if (!d)
      {
	    return 0;
      }
      memset(d, 0, sizeof(pdf_font_descriptor));
      d->flags = flags;
      //
      d->fontname[0] = 0;
      if (fontname->t == eKey)
      {
	    strncpy(d->fontname, fontname->value.k, strlen(fontname->value.k)<256?strlen(fontname->value.k):256);
	    if (strstr(d->fontname, "Monaco"))
	    {
		  d->fontname_id = eMonaco;
	    }
	    else if (strstr(d->fontname, "Sans"))
	    {
		  d->fontname_id = eArial;
	    }
	    else if (strstr(d->fontname, "Times"))
	    {
		  d->fontname_id = eArial;
	    }
	    else
	    {
		  d->fontname_id = eNoFontName;
	    }
      }
      return d;
}

pdf_font *
pdf_font_load(pdf_obj *o, int cid2uni, pdfcrypto_priv* encrypt)
{
      pdf_font *f;
      pdf_obj *a;
      int ref = -1;

      if (!o)
	    return 0;
      if (o->t == eRef)
	    ref = o->value.r.num;
      pdf_obj_resolve(o);
      if (!o)
	    return 0;
      if (o->t != eDict)
	    return 0;
      f = pdf_malloc(sizeof(pdf_font));
      if (!f)
	    return 0;
      f->ref = ref;
      f->next = NULL;
      a = dict_get(o->value.d.dict, "Subtype");
      if (a && a->t == eKey)
      {
	    // Simple font types
	    if (strncmp(a->value.k, "TrueType", 8) == 0)
	    {
		  f->type = TrueType;
	    }
	    else if (strncmp(a->value.k, "CIDFontType0", 5) == 0)
	    {
		  f->type = CIDFontType0;
	    }
	    else if (strncmp(a->value.k, "CIDFontType2", 5) == 0)
	    {
		  f->type = CIDFontType2;
	    }
	    else if (strncmp(a->value.k, "Type3", 5) == 0)
	    {
		  f->type = Type3;
	    }
	    // Composite font types
	    else if (strncmp(a->value.k, "Type0", 5) == 0)
	    {
		  f->type = Type0;
	    }
	    else if (strncmp(a->value.k, "Type1", 5) == 0)
	    {
		  f->type = Type1;
	    }
	    else if (strncmp(a->value.k, "Type2", 5) == 0)
	    {
		  f->type = Type2;
	    }
	    else
	    {
		  pdf_free(f);
		  return 0;
	    }
      }
      // encoding
      f->encoding = pdf_malloc(sizeof(pdf_font_encoding));
      if (!f->encoding)
	    goto fail;
      memset(f->encoding, 0, sizeof(pdf_font_encoding));
      a = dict_get(o->value.d.dict, "Encoding");
      if ((f->type == Type0) || (f->type == Type2))
      {
	    if (a)
	    {
		  pdf_cid_encoding_load(a, f->encoding);
	    }
	    f->widths = 0;
      }
      else
      { // simple font
	    if (!a)
	    {
		  pdf_encoding_load(a, f->encoding);
	    }
	    else if (a->t == eKey)
	    {
		  pdf_encoding_load(a, f->encoding);
	    }
	    else if (a->t == eDict || a->t == eRef)
	    {
		  pdf_encoding_load(a, f->encoding);
	    }
	    else
	    {
		  pdf_encoding_load(0, f->encoding);
	    }
	    pdf_font_widths_load(o, f);
      }
      // composite font specific
      if ((f->type == Type0) || (f->type == Type2))
      { // CID fonts
	    //
	    if (f->type == CIDFontType0)
	    {
		  a = dict_get(o->value.d.dict, "DescendantFonts");
		  if (!a)
			goto fail;
	    }
#if 0
	    a = dict_get(o->value.d.dict, "CIDSystemInfo");
	    if (!a)
		  goto fail;
#endif
      }
      else if (f->type == TrueType)
      {
      }
      else if (f->type == Type1)
      {
      }
      else if (f->type == Type3)
      {
      }
      // CidToUnicode
      f->unicode_get = unicode_get_stub;
      f->tounicode = 0;
      if (cid2uni)
      {
	    a = dict_get(o->value.d.dict, "ToUnicode");
	    if (a)
	    {
		  pdf_cmap_tounicode_parse(a, f, encrypt);
	    }
	    else
	    {
		  if (f->type == TrueType || f->type == Type1 || f->type == Type3)
		  {
			f->unicode_get = unicode_get_simple;
		  }
		  else
		  {
			// composite font
		  }
	    }
      }
      // FontDescriptor
      a = dict_get(o->value.d.dict, "FontDescriptor");
      if (a)
      {
	    f->fontdescriptor = pdf_font_descriptor_load(a);
      }
      else
      {
	    f->fontdescriptor = 0;
      }
      return f;
  fail:
      if (f)
	    pdf_free(f);
      return 0;
}

void
pdf_font_free(pdf_font *f)
{
      if (f)
      {
	    while (f)
	    {
		  pdf_font *next = f->next;
		  if (f->widths)
		  {
			pdf_free(f->widths);
		  }
		  if (f->encoding)
		  {
			pdf_encoding_free(f->encoding);
		  }
		  if (f->tounicode)
		  {
			pdf_tounicode_free(f->tounicode);
			f->tounicode = 0;
		  }
		  if (f->fontdescriptor)
		  {
			pdf_free(f->fontdescriptor);
		  }
		  pdf_free(f);
		  f = next;
	    }
      }
}

pdf_font*
pdf_font_find(pdf_font* f, int ref)
{
      if (!f)
	    return 0;
      while (f)
      {
	    if (f->ref == ref)
		  return f;
	    f = f->next;
      }
      return 0;
}

int
pdf_character_show(pdf_device* dev, pdf_prs *s, pdf_font *f, gs_matrix *ctm, char *c, unsigned int *c_id)
{
      u32 cid;
      pdf_font_encoding *enc;
      int step;
      byte uni[8];
      if (!f)
	    return 0;
      enc = f->encoding;
      if (!enc)
	    return 0;
      step = (enc->get_cid)(c, &cid);
      *c_id = cid;
      if (dev)
      {
	    pdf_device_char_show(dev, f, s->gs.fs, ctm, cid);
      }
      else
      {
	    if (step == 1)
	    {
#ifdef DEBUG
		  int n = (f->unicode_get)(f, cid, uni);
		  fputc(uni[0]>>8, stdout);
		  fputc(uni[0]&0xff, stdout);
#endif
	    }
	    else if (step == 4)
	    {
		  int n = (f->unicode_get)(f, cid, uni);
		  int i;
		  for (i = 0; i < n; i++)
		  {
#ifdef DEBUG
			fputc(uni[i]&0xff, stdout);
#endif
		  }
	    }
      }
      return step;
}

int
pdf_font_tounicode(pdf_font *f, unsigned int cid, unsigned char *uni)
{
      if (f && f->unicode_get)
	    return (f->unicode_get)(f, cid, uni);
}

int
pdf_font_flags_get(pdf_font *f)
{
      if (!f || !(f->fontdescriptor))
      {
	    return 0;
      }
      return f->fontdescriptor->flags;
}

char *
pdf_font_basefont_get(pdf_font *f)
{
      if (!f || !(f->fontdescriptor))
      {
	    return 0;
      }
      return f->fontdescriptor->fontname;
}
extern fontname_id pdf_font_basefont_id_get(pdf_font *f)
{
      if (!f || !(f->fontdescriptor))
      {
	    return 0;
      }
      return f->fontdescriptor->fontname_id;
}
