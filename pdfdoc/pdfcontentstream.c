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
	  *last = mGETCHAR(s);
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
  float a = 1;
  float b = 0;
  float man = 0.1;
  int i = 0;

  if (c == '.')
    {
      frac = 1;
      b += (c - '0') * man;
      man *= 0.1;
      a = 0;
    }
  else if (c == '+')
    {
      a = 1;
    }
  else if (c == '-')
    {
      a = -1;
      man = -0.1;
    }
  else
    {
      a = (c - '0');
    }

  while ((c = mGETCHAR(s)) != EOF)
    {
      if (isdigit(c))
	{
	  if (!frac)
	    a = a * 10 + (c - '0');
	  else
	    {
	      b += (c - '0') * man;
	      man *= 0.1;
	    }
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
  *out = a+b;
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
	return pdf_syntax_err;
    }
  *last = c;
  return pdf_ok;
}

///////////////////////////////////////////////////
// ONLY for direct dictionary parsing in a content stream
static
pdf_err
pdf_parse_dict(buffer_stream *s, int *last)
{
  int c;
  while ((c = mGETCHAR(s)) != EOF)
    {
    weird:
      if (c == '>')
	{
	  if (((c = mGETCHAR(s)) != EOF) && (c == '>'))
	    {
	      *last = mGETCHAR(s);
	      break;
	    }
	}
      else if (c == '<')
	{
	  if (((c = mGETCHAR(s)) != EOF) && (c == '<'))
	    {
	      pdf_parse_dict(s, last);
	      c = *last;
	      goto weird;
	    }
	}
    }
  return pdf_ok;
}
//static float pop_n(float *base, float *p) {if (p <= base) np = base+1; np--; return *np;}
#define PUSH_N(a) *np++ = (a); if (np>=nx) np--
#define POP_N(n) np -= n; if (np <= num_stack) np = num_stack
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
  int _2_hash;
  /// lexical value storage
  float num_stack[32], *np = num_stack, *nx = np+32;
  //unsigned char **str_stk; // for string/hex-string
  //unsigned char **name_stk; // for resources
  //unsigned char **dict_stk; // for direct dictionary
  ///
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
	  PUSH_N(n);
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
	  if ((c = mGETCHAR(b)) && c != EOF)
	    {
	      if (c == '<')
		{
		  ON_ERROR(pdf_parse_dict(b, &c));
		}
	      else
		{
		  ON_ERROR(pdf_lex_hexstring(b, &c, buf, LEX_BUF_LEN));
		}
	    }
	  break;
	case '/':
	  ON_ERROR(pdf_lex_name(b, &c, buf, LEX_BUF_LEN));
	  break;
	case '.':
	case '+':
	case '-':
	  ON_ERROR(pdf_lex_number(b, &c, c, &n));
	  PUSH_N(n);
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
		case '"':  break;
		case '\'':  break;
		case 'b':
		  break;
		case 'c':
		  x_c(p, np[-1], np[-2], np[-3], np[-4], np[-5], np[-6]);
		  POP_N(6);
		  break;
		case 'd':
		  break;
		case 'f':
		  break;
		case 'g':
		  x_g(p, np[-1]);
		  POP_N(1);
		  break;
		case 'h':
		  break;
		case 'i':
		  break;
		case 'j':
		  break;
		case 'k':
		  x_k(p, np[-1], np[-2], np[-3], np[-4]);
		  POP_N(4);
		  break;
		case 'l':
		  {
		    x_m(p, np[-2], np[-1]);
		    POP_N(2);
		  }
		  break;
		case 'm':
		  {
		    x_m(p, np[-2], np[-1]);
		    POP_N(2);
		  }
		  break;
		case 'n':
		  x_n(p);
		  break;
		case 'q':
		  break;
		case 's':
		  break;
		case 'v':
		  x_v(p, np[-1], np[-2], np[-3], np[-4]);
		  POP_N(4);
		  break;
		case 'w':
		  break;
		case 'y':
		  x_y(p, np[-1], np[-2], np[-3], np[-4]);
		  POP_N(4);
		  break;
		  ///
		case 'B':
		  break;
		case 'F':
		  break;
		case 'G':
		  x_G(p, np[-1]);
		  POP_N(1);
		  break;
		case 'J':
		  break;
		case 'K':
		  x_K(p, np[-1], np[-2], np[-3], np[-4]);
		  POP_N(4);
		  break;
		case 'M':
		  break;
		case 'Q':
		  break;
		case 'S':
		  break;
		case 'W':
		  break;
		default:
		  goto syntax_err;
		  break;
		}
	      break;
	      /////////////////////////////// two letter command
	    case 2:
	      _2_hash = (buf[0]<<8)+buf[1];
#define TWO_HASH(a, b) (((a)<<8)+(b))
	      switch (_2_hash)
		{
		case TWO_HASH('b','*'):
		  //x_bstar(p);
		  break;
		case (TWO_HASH('c','m')):
		  x_cm(p, np[-1], np[-2], np[-3], np[-4], np[-5], np[-6]);
		  POP_N(6);
		  break;
		case (TWO_HASH('c','s')):
		  {
		    //x_cs(p);
		  }
		  break;
		case (TWO_HASH('d','0')):
		  {
		    //x_d0(p);
		  }
		  break;
		case (TWO_HASH('d','1')):
		  {
		    //x_d1(p);
		  }
		  break;
		case (TWO_HASH('f','*')):
		  {
		    //x_fstar(p);
		  }
		  break;
		case (TWO_HASH('g','s')):
		  {
		    x_gs(p);
		  }
		  break;
		case TWO_HASH('r','e'):
		  {
		    x_re(p, np[-4], np[-3], np[-2], np[-1]);
		    POP_N(4);
		  }
		  break;
		case TWO_HASH('r','g'):
		  {
		    x_rg(p, np[-3], np[-2], np[-1]);
		    POP_N(3);
		  }
		  break;
		case TWO_HASH('r','i'):
		  {
		    //x_ri(p);
		  }
		  break;
		case TWO_HASH('s','c'):
		  {
		    //x_sc(p);
		  }
		  break;
		case TWO_HASH('s','h'):
		  {
		    //x_sh(p);
		  }
		  break;
		case TWO_HASH('B', '*'): x_Bstar(p); break; // B*
		case TWO_HASH('B', 'I'): x_BI(p); break;// BI
		case TWO_HASH('B', 'T'): x_BT(p); break; // BT
		case TWO_HASH('B', 'X'): x_BX(p); break; // BX
		case TWO_HASH('C','S'):
		  {
		    //x_CS(p);
		  }
		  break;
		case (TWO_HASH('D','o')):
		  {
		    x_Do(p);
		  }
		break;
		case (TWO_HASH('D','P')):
		  {
		    //x_DP(p);
		  }
		  break;
		case TWO_HASH('E','T'):
		  {
		    x_ET(p);
		  }
		break;
		case TWO_HASH('E', 'X'):
		  {
		    x_EX(p);
		  }
		break;
		case TWO_HASH('T', '*'): // T*
		  x_Tstar(p);
		  break;
		case TWO_HASH('T', 'c'): // Tc
		  x_Tc(p);
		  break;
		case TWO_HASH('T', 'd'): // Td
		  x_Td(p);
		  break;
		case TWO_HASH('T', 'f'): // Tf
		  x_Tf(p, NULL,  np[-1]);
		  POP_N(1);
		  break;
		case TWO_HASH('T', 'j'): // Tj
		  x_Tj(p);
		  break;
		case TWO_HASH('T', 'J'): // TJ
		  x_TJ(p);
		  break;
		case TWO_HASH('T', 'L'): // TL
		  x_TL(p);
		  break;
		case TWO_HASH('T', 'm'): // Tm
		  x_Tm(p, np[-1], np[-2], np[-3], np[-4], np[-5], np[-6]);
		  POP_N(6);
		  break;
		case TWO_HASH('T', 'r'): // Tr
		  x_Tr(p);
		  break;
		case TWO_HASH('T', 's'): // Ts
		  x_Ts(p);
		  break;
		case TWO_HASH('T', 'w'): // Tw
		  x_Tw(p);
		  break;
		case TWO_HASH('T', 'z'): // Tz
		  x_Tz(p);
		  break;
		case TWO_HASH('R', 'G'):
		  {
		    x_RG(p, np[-3], np[-2], np[-1]);
		    POP_N(3);
		  }
		  break;
		case TWO_HASH('S', 'C'):
		  {
		    // x_SC();
		  }
		  break;
		case TWO_HASH('W', '*'):
		  {
		    // x_Wstar();
		  }
		  break;
		  ///
		default:
		  goto syntax_err;
		  break;
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
	      else if (buf[0] == 'S' && buf[1] == 'C' && buf[2] == 'N')
		{
		  //x_EMC(p);
		}
	      else if (buf[0] == 's' && buf[1] == 'c' && buf[2] == 'n')
		{
		  //x_EMC(p);
		}
	      else
		{
		  goto syntax_err;
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
#ifdef DEBUG
  printf("content stream syntax error!\n");
#endif
  return pdf_syntax_err;
 done:
  return pdf_ok;
}
