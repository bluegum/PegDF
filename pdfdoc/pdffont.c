#include "pdftypes.h"
#include "pdfindex.h"
#include "dict.h"
#include "pdffont.h"

#include "pdfencodingtable.c"

static unsigned int get_cid_identity(unsigned int c) { return c; }

static const char * get_glyph_name(pdf_font_encoding *e, unsigned int c)
{
      const char *p = 0;
      if (c > 255)
	    return 0;
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
pdf_encoding_load(pdf_obj *a, pdf_font_encoding* e)
{
      if (!a)
      {
	    e->type = StandardEncoding;
	    e->get_glyph_name = get_glyph_name;
	    return;
      }
      if (a->t == eKey)
      {
	restart:
	    if (strncmp(a->value.k, "WinAnsiEncoding", sizeof("WinAnsiEncoding")) == 0)
	    {
		  e->type = WinAnsiEncoding;
	    }
	    else if (strncmp(a->value.k, "MacRomanEncoding", sizeof("MacRomanEncoding")) == 0)
	    {
		  e->type = MacRomanEncoding;
	    }
	    else if (strncmp(a->value.k, "MacExpertEncoding", sizeof("MacExpertEncoding")) == 0)
	    {
		  e->type = MacExpertEncoding;
	    }
	    else
	    {
		  e->type = StandardEncoding;
	    }
	    e->get_glyph_name = get_glyph_name;
      }
      else if (a->t == eDict || a->t == eRef)
      {
	    pdf_obj *o;
	    pdf_obj_resolve(a);
	    if (!a)
		  return;
	    o = dict_get(a->value.d.dict, "Differences");
	    if (o && o->t == eArray)
	    {
		  int i;
		  e->differences = pdf_malloc(sizeof(char*)*256);
		  if (e->differences)
			memset(e->differences, 0, sizeof(char*)*256);
		  // parse
		  for (i == 0; i < o->value.a.len; i++)
		  {
			pdf_obj dd = o->value.a.items[i];
		  }
	    }
	    o = dict_get(a->value.d.dict, "BaseEncoding");
	    if (o && o->t == eKey)
	    {
		  goto restart;
	    }
	    else
	    {
		  e->type = StandardEncoding;
	    }
      }
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

pdf_font *
pdf_font_load(pdf_obj *o)
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
	    else if (a->t == eDict)
	    {
		  pdf_encoding_load(a, f->encoding);
	    }
	    else
	    {
	    }
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
/*
	    a = dict_get(o->value.d.dict, "CIDSystemInfo");
	    if (!a)
		  goto fail;
*/
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
		  if (f->encoding)
			pdf_encoding_free(f->encoding);
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
