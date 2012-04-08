#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include "pdftypes.h"
#include "pdfmem.h"
#include "pdfdoc.h"
#include "pdfcmds.h"

#define mGETCHAR(s) s_get_char(s)
#define BUFFER_STREAM_BUF_SIZE 1024
#define LEX_BUF_LEN 1024
#define ON_ERROR(exp) if (pdf_ok != (exp)) goto error;
//////////////////////////////////////////
static inline
int
isdelim(unsigned char c)
{
  if (isspace(c))
    return 1;
  switch(c)
    {
    case '(':
    case')':
    case'<':
    case'>':
    case'[':
    case']':
    case'{':
    case'}':
    case'/':
    case'%':
      return 1;
      break;
    default:
      return 0;
    }
}
//////////////////////////////////////////

typedef struct buffer_stream_s buffer_stream;

struct buffer_stream_s
{
  unsigned char buf[BUFFER_STREAM_BUF_SIZE];
  unsigned char *p, *e, *l; // e -> buffer end, x -> buffer limit 
  pdf_filter *f;
};

static int
s_get_char(buffer_stream *s)
{
  assert(s);
  if (s->p == s->e)
    {
      int i;
      i = (s->f->read)(s->f, s->buf, BUFFER_STREAM_BUF_SIZE);
      if (i == 0)
	return EOF;
      s->p = s->buf;
      s->e = s->p + i;
    }
  if (s->p != s->e)
    {
      return *s->p++;
    }
  return EOF;
}

static buffer_stream*
s_buffer_stream_open(pdf_filter *f)
{
  buffer_stream *s = pdf_malloc(sizeof(buffer_stream));
  if (s)
    {
      s->f = f;
      s->p = &s->buf[0];
      s->e = s->p;
      s->l = s->p + BUFFER_STREAM_BUF_SIZE;
    }
  return s;
}

static pdf_err
s_buffer_stream_close(buffer_stream *s)
{
  if (s)
    pdf_free(s);
  return pdf_ok;
}

//////////////////////////////////////////////////////////////////////////////////// lexers

static pdf_err
pdf_lex_array(buffer_stream *s, int *last, unsigned char* buf, int max)
{
  int c;
  int i = 0;
  while ((c = mGETCHAR(s)) != EOF)
    {
      if (c == ']')
	{
	  *buf = 0;
	  *last = mGETCHAR(s);
	  return pdf_ok;
	}
      else
	*buf ++ = c;
      if (++i >= max)
	break;
    }
  return pdf_syntax_err;
}

static pdf_err
pdf_lex_string(buffer_stream *s, int *last, unsigned char* buf, int max)
{
  int c;
  int i = 0;

  while ((c = mGETCHAR(s)) != EOF)
    {
      if (c == ')')
	{
	  *buf = 0;
	  *last = c;
	  return pdf_ok;
	}
      else
	{
	  *buf ++ = c;
	}
      if (++i >= max)
	break;
    }
  return pdf_syntax_err;
}

static pdf_err
pdf_lex_hexstring(buffer_stream *s, int *last, unsigned char* buf, int max)
{
  int c;
  int i = 0;

  while ((c = mGETCHAR(s)) != EOF)
    {
      if (c == '>')
	{
	  *buf = 0;
	  *last = c;
	  return pdf_ok;
	}
      else
	{
	  *buf ++ = c;
	}
      if (++i >= max)
	break;
    }
  return pdf_syntax_err;
}

static pdf_err
pdf_lex_name(buffer_stream *s, int *last, unsigned char* buf, int max)
{
  int c;
  unsigned char *p = buf;
  int i = 0;
  while ((c = mGETCHAR(s)) != EOF)
    {
      if (isdelim(c))
	{
	  *p = 0;
#ifdef DEBUG
	  printf("/%s ", buf);
#endif
	  *last = c;
	  return pdf_ok;
	}
      else
	{
	  *p++ = c;
	}
      if (++i >= max)
	break;
    }
  return pdf_syntax_err;
}

static pdf_err
pdf_lex_number(buffer_stream *s, int *last, int c, float *out)
{
  int frac = 0;
  float a;
  float b = 0;
  int i = 0;

  if (c != '.')
    a = c - '0';
  else
    a = 1;

  while ((c = mGETCHAR(s)) != EOF)
    {
      if (isdigit(c))
	{
	  if (!frac)
	    a *= (c - '0');
	  else
	    b += (c - '0') * log10(i) ;
	}
      else if (c == '.')
	{
	  frac = 1;
	  i = 1;
	}
      else if (isdelim(c))
	{
	  *out = a+b;
	  break;
	}
      else
	{
	  // lexical error
	  return pdf_syntax_err;
	}
    }
  *last = c;
  return pdf_ok;
}

static
pdf_err
pdf_lex_cmd(buffer_stream *s, int *last, int c, unsigned char *out, int max, int *cnt)
{
  int i = 0;
  *cnt = 0;
  while (isdelim(c))
    {
      if ((c = mGETCHAR(s)) != EOF)
	continue;
    }
  if (c == EOF)
    return pdf_syntax_err;

  *out++ = c;
  (*cnt) += 1;
  while ((c = mGETCHAR(s)) != EOF)
    {
      if (isdelim(c))
	{
	  *last = c;
	  *out = 0;
	  return pdf_ok;
	}
      *out++ = c;
      *cnt += 1;
      if (++i >= max)
	break;
    }
  return pdf_syntax_err;
}

/////////////////////////////////////////////////////////////////////////////////
// Content Stream Parser 
/////////////////////////////////////////////////////////////////////////////////
pdf_err
pdf_cs_parse(pdf_page *p, pdf_stream *s)
{
  unsigned char buf[LEX_BUF_LEN];
  int c;
  buffer_stream *b;
  float n;
  int cmdlen;

  if (!s)
    return pdf_ok;
  if (!s->ffilter)
    return pdf_ok;
  b = s_buffer_stream_open(s->ffilter);
  if (!b)
    return pdf_ok;

  c = ' ';
  while (1)
    {
      if (c == EOF)
	break;
      if (isspace(c))
	{
	  c = mGETCHAR(b);
	  continue;
	}
      if (isdigit(c))
	{
	  ON_ERROR(pdf_lex_number(b, &c, c, &n));
	}

      switch(c)
	{
	case '[':
	  ON_ERROR(pdf_lex_array(b, &c, buf, LEX_BUF_LEN));
	  break;
	case '(':
	  ON_ERROR(pdf_lex_string(b, &c, buf, LEX_BUF_LEN));
	  break;
	case '<':
	  ON_ERROR(pdf_lex_hexstring(b, &c, buf, LEX_BUF_LEN));
	  break;
	case '/':
	  ON_ERROR(pdf_lex_name(b, &c, buf, LEX_BUF_LEN));
	  break;
	case '.':
	case '+':
	case '-':
	  ON_ERROR(pdf_lex_number(b, &c, c, &n));
	break;
	default:
	  if (isspace(c))
	    break;
	  ///////////////////////////////////////////
	  // lex stream commands
	  ON_ERROR(pdf_lex_cmd(b, &c,  c, buf, LEX_BUF_LEN, &cmdlen))
	  switch (cmdlen)
	    {
	      ////////////////////////////// single letter command
	    case 1:
	      switch (buf[0])
		{
		case 'n':
		  x_n(p);
		  break;
		case 'm':
		  {
		    float x, y;
		    x_m(p, x, y);
		  }
		  break;
		case 'l':
		  break;
		case 'c':
		  break;
		case 'f':
		  break;
		case 'W':
		  break;
		  // graphics state
		case 'q':
		  break;
		case 'Q':
		  break;
		default:
		  break;
		}
	      break;
	      /////////////////////////////// two letter command
	    case 2:
	      if (buf[0] == 'c' && buf[1] == 'm')
		{
		  x_cm(p);
		}
	      else if (buf[0] == 'g' && buf[1] == 's')
		{
		  x_gs(p);
		}
	      else if (buf[0] == 'r')
		{
		  if (buf[1] == 'e') // re
		    {
		      x_re(p);
		    }
		  else if (buf[1] == 'g')
		    {
		      x_rg(p);
		    }
		  else
		    {
		      goto syntax_err;
		    }
		}
	      else if (buf[0] == 'T')
		{
		  switch (buf[1])
		    {
		    case 'f': // Tf
		      x_Tf(p);
		      break;
		    case 'j': // Tj
		      x_Tj(p);
		      break;
		    case 'J': // TJ
		      x_TJ(p);
		      break;
		    case 'm': // Tm
		      x_Tm(p);
		      break;
		    case 'd': // Td
		      x_Td(p);
		      break;
		    case 'L': // TL
		      x_TL(p);
		      break;
		    default:
		      //goto syntax_err;
		      break;
		    }
		}
	      else if (buf[0] == 'B')
		{
		  switch (buf[1])
		    {
		    case '*': x_Bstar(p); break; // B*
		    case 'I': x_BI(p); break;// BI
		    case 'T': x_BT(p); break; // BT
		    case 'X': x_BX(p); break; // BX
		    default:
		      goto syntax_err;
		    }
		}
	      else if (buf[0] == 'E')
		{
		  if (buf[1] == 'T')
		    {
		      x_ET(p);
		    }
		  else if (buf[1] == 'X')
		    {
		      x_EX(p);
		    }
		  else
		    {
		      goto syntax_err;
		    }
		}
	      else
		{
		  // will jump to error
		}
	      break;
	      //////////////////////////////////////////// 3 letter command
	    case 3:
	      if (buf[0] == 'B' && buf[1] == 'D' && buf[2] == 'C')
		{
		  x_BDC(p);
		}
	      else if (buf[0] == 'B' && buf[1] == 'M' && buf[2] == 'C')
		{
		  x_BMC(p);
		}
	      else if (buf[0] == 'E' && buf[1] == 'M' && buf[2] == 'C')
		{
		  x_EMC(p);
		}
	      break;
	    default:
	      goto syntax_err;
	    } // cmd switch
	} // lex switch
    } // loop
  s_buffer_stream_close(b);
  goto done;
 error:
 syntax_err:
  if (b)
    {
      s_buffer_stream_close(b);
    }
  printf("syntax error!\n");
  return pdf_syntax_err;
 done:
  return pdf_ok;
}
