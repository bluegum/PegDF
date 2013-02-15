#include <ctype.h>
#define _GNU_SOURCE
#include <search.h>
#include "pdftypes.h"
#include "pdfindex.h"
#include "pdffilter.h"
#include "pdfdoc.h"
#include "pdffont.h"
#include "pdfcmap.h"

typedef enum pdf_cmap_token_type_e pdf_cmap_token_type;
enum pdf_cmap_token_type_e
{
      eCOMMENT,
      eKEYWORD,
      eNUMSTR,
      eHEXSTR,
      eARRAY,
      eNAME,
      eDICT,
      eNONE
};

pdf_cmap_token_type
pdf_cmap_lex(pdf_stream *s, unsigned char *tokenbuf)
{
      unsigned char c;
      pdf_cmap_token_type t = eNONE;

      while ((s->ffilter->read)(s->ffilter, &c, 1))
      {
	    if (isspace(c))
		  continue;
	    switch (c)
	    {
		  case '%':
			while ((s->ffilter->read)(s->ffilter, &c, 1))
			{
			      if (c == '\r' || c == '\n')
				    break;
			}
			break;
		  case '<':
			if ((s->ffilter->read)(s->ffilter, &c, 1))
			{
			      if (c == '<')
			      {
				    t = eDICT;
			      }
			      else if (isxdigit(c))
			      {
				    *tokenbuf++ = c;
				    while ((s->ffilter->read)(s->ffilter, &c, 1))
				    {
					  if (c == '>')
						break;
					  else
						*tokenbuf++ = c;
				    }
				    *tokenbuf = 0;
				    t = eHEXSTR;
			      }
			}
			break;
		  case '0':
		  case '1':
		  case '2':
		  case '3':
		  case '4':
		  case '5':
		  case '6':
		  case '7':
		  case '8':
		  case '9':
			*tokenbuf++ = c;
			while ((s->ffilter->read)(s->ffilter, &c, 1))
			{
			      if (isspace(c))
				    break;
			      else
				    *tokenbuf++ = c;
			}
			*tokenbuf = 0;
			t = eNUMSTR;
			break;
		  case '[':
			t = eARRAY;
			break;
		  case '/':
			while ((s->ffilter->read)(s->ffilter, &c, 1))
			{
			      if (isspace(c))
				    break;
			      else
				    *tokenbuf++ = c;
			}
			t = eNAME;
			break;
		  default:
			*tokenbuf++ = c;
			while ((s->ffilter->read)(s->ffilter, &c, 1))
			{
			      if (isspace(c))
				    break;
			      else
				    *tokenbuf++ = c;
			}
			t = eKEYWORD;
			break;
	    }
	    break;
      }
      *tokenbuf = 0;
      return t;
}

static int
cmap_touni_cmp(const void *pa, const void *pb)
{
      pdf_tounicode* a = (pdf_tounicode*) pa;
      pdf_tounicode* b = (pdf_tounicode*) pb;
      if (a->cid < b->cid)
	    return -1;
      else if ( a->cid >= b->cid+b->n)
	    return 1;
      else
	    return 0;
}

void
pdf_cmap_bfchar_parse(pdf_stream *s, int n, pdf_font *f)
{
      char tokenbuf[1024];
      pdf_cmap_token_type tok;

      while ((tok = pdf_cmap_lex(s, tokenbuf)) != eNONE)
      {
	    if (tok == eHEXSTR)
	    {
		  unsigned int cid = asciihex2int(tokenbuf);
		  if ((tok = pdf_cmap_lex(s, tokenbuf)) == eHEXSTR)
		  {
			void *v;
			pdf_tounicode *touni = (pdf_tounicode*) pdf_malloc(sizeof(pdf_tounicode));
			if (touni)
			{
			      touni->cid = cid;
			      touni->n = 1;
			      touni->hex = pdf_malloc(strlen(tokenbuf));
			      strcpy(touni->hex, tokenbuf);
			      v = tsearch(touni, &f->tounicode, cmap_touni_cmp);
			}
		  }
	    }
	    else if (tok == eKEYWORD &&
		strcmp(tokenbuf, "endbfchar") == 0)
		  break;
      }
}

void
pdf_cmap_bfrange_parse(pdf_stream *s, int n, pdf_font *f)
{
      char tokenbuf[1024];
      pdf_cmap_token_type tok;
      void *v;

      while ((tok = pdf_cmap_lex(s, tokenbuf)) != eNONE)
      {
	    if (tok == eHEXSTR)
	    {
		  unsigned int from_cid = asciihex2int(tokenbuf);
		  unsigned int to_cid;
		  if ((tok = pdf_cmap_lex(s, tokenbuf)) == eHEXSTR)
		  {
			to_cid = asciihex2int(tokenbuf);
			tok = pdf_cmap_lex(s, tokenbuf);
			if (tok == eHEXSTR)
			{
			      pdf_tounicode *touni = (pdf_tounicode*) pdf_malloc(sizeof(pdf_tounicode));
			      if (touni)
			      {
				    touni->cid = from_cid;
				    touni->n = to_cid - from_cid;
				    touni->hex = pdf_malloc(strlen(tokenbuf));
				    strcpy(touni->hex, tokenbuf);
				    v = tsearch(touni, &f->tounicode, cmap_touni_cmp);
			      }
			}
			else if (tok = eARRAY)
			{
			      int i, n;
			      n = to_cid - - from_cid;
			      for (i = 0; i < to_cid - from_cid; i++)
			      {
				    pdf_tounicode *touni = (pdf_tounicode*) pdf_malloc(sizeof(pdf_tounicode));
				    touni->cid = from_cid;
				    touni->n = to_cid - from_cid;
				    if ((tok = pdf_cmap_lex(s, tokenbuf)) == eHEXSTR)
				    {
					  touni->hex = pdf_malloc(strlen(tokenbuf));
					  strcpy(touni->hex, tokenbuf);
					  v = tsearch(touni, &f->tounicode, cmap_touni_cmp);
				    }
			      }
			}
		  }
	    }
	    else if (tok == eKEYWORD &&
		strcmp(tokenbuf, "endbfrange") == 0)
		  break;
      }
}
static void
cmap_skip_dict(pdf_stream *s)
{
      unsigned char c;
      while ((s->ffilter->read)(s->ffilter, &c, 1))
      {
	    if (c == '>')
	    {
		  if ((s->ffilter->read)(s->ffilter, &c, 1) && c == '>')
			return;
	    }
      }
}

void
pdf_cmap_tounicode_parse(pdf_obj *cmap, pdf_font *f)
{
      pdf_stream *s;
      char tokenbuf[1024];
      pdf_cmap_token_type tok, pre_tok = eNONE;
      int num;

      if (!cmap)
	    return;
      if (cmap->t != eRef)
	    return;
      s = pdf_stream_load(cmap, 0, 0, 0);
      if (!s)
	    return;
      f->tounicode = 0;
      while ((tok = pdf_cmap_lex(s, tokenbuf)) != eNONE)
      {
	    switch (tok)
	    {
		  case eDICT:
			cmap_skip_dict(s);
			break;
		  case eKEYWORD:
			if (strcmp(tokenbuf, "beginbfchar") == 0)
			{
			      if (pre_tok == eNUMSTR && num)
				    pdf_cmap_bfchar_parse(s, num, f);
			}
			else if (strcmp(tokenbuf, "beginbfrange") == 0)
			{
			      if (pre_tok == eNUMSTR && num)
				    pdf_cmap_bfrange_parse(s, num, f);
			}
			break;
		  case eNUMSTR:
			num = atoi(tokenbuf);
			break;
		  default:
			break;
	    }
	    pre_tok = tok;
      }
      f->unicode_get = unicode_get_cmap;
      pdf_stream_free(s);
}

int
unicode_get_cmap(pdf_font *f, unsigned int c, unsigned int *uni)
{
      pdf_tounicode u;
      void *val;
      if (!f->tounicode)
      {
	    *uni = c;
	    return 1;
      }
      u.cid = c;
      val = tfind(&u, &f->tounicode, cmap_touni_cmp);
      if (val)
      {
	    int i;
	    pdf_tounicode **vv = (pdf_tounicode **)val;
	    pdf_tounicode *v = *vv;
	    for (i = 0; i < v->n; i++)
	    {
		  if (c == v->cid + i)
			break;
	    }
	    if (i == v->n)
	    {
		  *uni = c;
		  return 1;
	    }
	    else
	    {
		  // TODO: UTF16-BE decoding
		  char *p = v->hex;
		  *uni = asciihex2int(p);
		  *uni += i;
		  return 1;
	    }
      }
      else
      {
	    *uni = c;
	    return 1;
      }
}

static void
tounicode_free(void *v)
{
      pdf_tounicode* a = (pdf_tounicode*) v;
      if (a->hex)
	    pdf_free(a->hex);
      pdf_free(a);
}

void
pdf_tounicode_free(pdf_tounicode *u)
{
      if (u)
      {
	    tdestroy(u, tounicode_free);
      }
}
