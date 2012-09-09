#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include "pdftypes.h"
#include "pdfmem.h"
#include "pdfindex.h"
#include "pdffilter.h"
#include "pdfdoc.h"
#include "pdfcmds.h"
#include "dict.h"

#define mGETCHAR(s) s_get_char(s)
#define mUNGETCHAR(s) s_unget_char(s)
typedef struct buffer_stream_s buffer_stream;

#define BUFFER_STREAM_BUF_SIZE 1024
#define LEX_BUF_LEN 1024*64+1
#define OP_STK_SIZE 1024
#define ON_ERROR(exp) if (pdf_ok != (exp)) goto error;
static pdf_err pdf_parse_dict(buffer_stream *s, pdf_obj *o);
extern pdf_err pdf_lex_obj(buffer_stream *s, pdf_obj *);
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
// Hard coded 2 bytes unget buffer
struct buffer_stream_s
{
      unsigned char buf[BUFFER_STREAM_BUF_SIZE+2]; // plus 2 for unget buffer
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
            pdf_filter *f = s->f;
            //move last 2 byte to 1st in buffer, in case of unget
            if (s->p != s->buf)
            {
                  s->buf[0] = *(s->e-2);
                  s->buf[1] = *(s->e-1);
                  s->p = s->buf + 2;
            }
            i = (f->read)(f, s->p, BUFFER_STREAM_BUF_SIZE);
            if (i == 0)
                  return EOF;
            s->e = s->p + i;
      }
      if (s->p != s->e)
      {
            return *s->p++;
      }
      return EOF;
}

static void
s_unget_char(buffer_stream *s)
{
      if (s->p > s->buf)
            s->p -= 1;
      else
            printf("%s\n", "Can't do unget, too many to handle!");
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
            s->l = s->p + BUFFER_STREAM_BUF_SIZE + 2;
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
pdf_lex_array(buffer_stream *s, pdf_obj *a)
{
      struct arr_item_s {
            pdf_obj o;
            struct arr_item_s *next;
      } *item = NULL, *p = NULL, *last = NULL;
      int c;
      int i = 0, j;

      item = pdf_malloc(sizeof(struct arr_item_s));
      p = item;
      p->next = NULL;

      while ((c = mGETCHAR(s)) != EOF)
      {
            if (c == ']')
            {
                  break;
            }
            else if (isspace(c))
            {
                  continue;
            }
            else
            {
                  if (!p)
                  {
                        p = pdf_malloc(sizeof(struct arr_item_s));
                        last->next = p;
                  }
                  mUNGETCHAR(s);
                  pdf_lex_obj(s, &p->o);
                  last = p;
                  p->next = NULL;
                  p = p->next;
                  i += 1;
            }
      }
      // transfer items into pdf obj
      a->t = eArray;
      a->value.a.len = i;
      if (i != 0)
            a->value.a.items = pdf_malloc(i * sizeof(pdf_obj));
      p = item;
      for (j = 0; j < i; j++)
      {
            a->value.a.items[j] = p->o;
            p = p->next;
            if (!p)
                  break;
      }
      // free temp
      p = item;
      while (p)
      {
            struct arr_item_s *t = p->next;
            pdf_free(p);
            p = t;
      }
      return pdf_ok;
}

static pdf_err
pdf_lex_string(buffer_stream *s, unsigned char* buf, int max)
{
      int c;
      int i = 0;
      int escaped = 0;

      while ((c = mGETCHAR(s)) != EOF)
      {
            if (escaped)
            {
                  escaped = 0;
                  *buf++ = c;
            }
            else if (c == '(')
                  pdf_lex_string(s, buf, max);
            else if (c == ')')
            {
                  *buf = 0;
                  return pdf_ok;
            }
            else if ( c == '\\')
            {
                  escaped = 1;
            }
            else
            {
                  *buf++ = c;
            }
            if (++i >= max)
                  break;
      }
      return pdf_syntax_err;
}

static pdf_err
pdf_lex_hexstring(buffer_stream *s, unsigned char* buf, int max)
{
      int c;
      int i = 0;

      while ((c = mGETCHAR(s)) != EOF)
      {
            if (c == '>')
            {
                  *buf = 0;
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
pdf_lex_name(buffer_stream *s, unsigned char* buf, int max)
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
pdf_lex_number(buffer_stream *s, int c, float *out)
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
      *out = a+b;
      return pdf_ok;
}

pdf_err
pdf_lex_obj(buffer_stream *s, pdf_obj *o)
{
      int c;
      unsigned char buf[LEX_BUF_LEN];
      pdf_err e = pdf_ok;
      float n;

      while ((c = mGETCHAR(s)) != EOF)
      {
            if (isspace(c))
                  continue;
            else
                  break;
      }
      switch (c)
      {
            case ' ':
            case '\t':
            case '\r':
            case '\n':
                  break;
            case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
            case '.':
            case '+':
            case '-':
                  ON_ERROR(pdf_lex_number(s, c, &n));
                  if (n == floor(n))
                  {
                        o->t = eInt;
                        o->value.i = n;
                  }
                  else
                  {
                        o->t = eReal;
                        o->value.f = n;
                  }
                  mUNGETCHAR(s);
                  break;
            case '(':
                  ON_ERROR(pdf_lex_string(s, buf, LEX_BUF_LEN));
                  o->t = eString;
                  o->value.s.len = strlen((char*)buf);
                  o->value.s.buf = pdf_malloc(o->value.s.len);
                  strncpy(o->value.s.buf, (char*)buf, o->value.s.len);
                  break;
            case '[':
                  ON_ERROR(pdf_lex_array(s, o));
                  o->t = eArray;
                  break;
            case '<':
                  c = mGETCHAR(s);
                  if (c == EOF)
                        goto error;
                  if (c == '<')
                  {
                        ON_ERROR(pdf_parse_dict(s, o));
                  }
                  else
                  {
                        mUNGETCHAR(s);
                        ON_ERROR(pdf_lex_hexstring(s, buf, LEX_BUF_LEN));
                        o->t = eHexString;
                        o->value.s.len = strlen((char*)buf);
                        o->value.s.buf = pdf_malloc(o->value.s.len);
                        strncpy(o->value.s.buf, (char*)buf, o->value.s.len);
                  }
                  break;
            case '/':
                  ON_ERROR(pdf_lex_name(s, buf, LEX_BUF_LEN));
                  o->t = eKey;
                  o->value.k = pdf_malloc(strlen((char*)buf)+1);
                  memcpy(o->value.k, buf, (strlen((char*)buf)+1));
                  mUNGETCHAR(s);
                  break;
            default:
                  goto done;
                  break;
      }
  error:
  done:
      return e;
}
/////////////////////////////////////////////////////////////
static
pdf_err
pdf_lex_cmd(buffer_stream *s, unsigned char *out, int max, int *cnt)
{
      int c;
      int i = 0;
      *cnt = 0;
      c = mGETCHAR(s);
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
                  *out = 0;
                  mUNGETCHAR(s);
                  return pdf_ok;
            }
            *out++ = c;
            *cnt += 1;
            if (++i >= max)
                  return pdf_syntax_err;
      }
      return pdf_ok;
}

///////////////////////////////////////////////////
// ONLY for direct dictionary parsing in a content stream
static
pdf_err
pdf_parse_dict(buffer_stream *s, pdf_obj *o)
{
      int c;
      pdf_obj k, v;
      dict* d = dict_new();
      if (!d)
            return pdf_mem_err;
      o->t = eDict;
      o->value.d.dict = d;
      while ((c = mGETCHAR(s)) != EOF)
      {
            if (c == '>')
            {
                  if (((c = mGETCHAR(s)) != EOF) && (c == '>'))
                  {
                        break;
                  }
            }
            else if (c == '<')
            {
                  if (((c = mGETCHAR(s)) != EOF) && (c == '<'))
                  {
                        pdf_parse_dict(s, o);
                  }
            }
            else if (c == '/')
            {
                  pdf_obj *val;
                  mUNGETCHAR(s);
                  if (pdf_lex_obj(s, &k) != pdf_ok)
                        return pdf_syntax_err;
                  if (pdf_lex_obj(s, &v) != pdf_ok)
                        return pdf_syntax_err;
                  val = pdf_malloc(sizeof(pdf_obj));
                  *val = v;
                  dict_insert(d, k.value.k, val);
                  pdf_obj_delete(&k);
            }
            else if (!isspace(c))
            {
                  printf ("%s\n", "Expecting a name in dictionary key!");
            }
      }

      return pdf_ok;
}
//static float pop_n(float *base, float *p) {if (p <= base) np = base+1; np--; return *np;}
#define PUSH_N(a) *np++ = (a); if (np>=nx) np--
#define POP_N(n) np -= n; if (np <= num_stack) np = num_stack
#define PUSH_O(a) *op++ = (a); if (op>=op_max) op--
#define POP_O (op <= o) ? (*o):(*(--op))
/////////////////////////////////////////////////////////////////////////////////
// Content Stream Parser
//
// Out of curiosity, I keep two operand stacks will parsing, one is number stack,
// which holds all the integers and floating point numbers, the other one is the
// generic stack, which holds pdf_objs. It is up to the operators the pop/push
// the corresponding stacks.
//
/////////////////////////////////////////////////////////////////////////////////
pdf_err
pdf_cs_parse(pdf_page *p, pdf_stream *s)
{
      pdf_obj t, o[OP_STK_SIZE], *op = o, *op_max=op+OP_STK_SIZE;
      unsigned char buf[LEX_BUF_LEN];
      int c;
      buffer_stream *b;
      float n;
      int cmdlen;
      int _2_hash;
      /// lexical value storage
      float num_stack[32], *np = num_stack, *nx = np+32;
      ///
      if (!s)
            return pdf_ok;
      if (!s->ffilter)
            return pdf_ok;
      b = s_buffer_stream_open(s->ffilter);
      if (!b)
            return pdf_ok;

      while ((c = mGETCHAR(b)) != EOF)
      {
            if (isspace(c))
            {
                  continue;
            }
            if (isdigit(c))
            {
                  ON_ERROR(pdf_lex_number(b, c, &n));
                  mUNGETCHAR(b);
                  PUSH_N(n);
                  continue;
            }

            switch(c)
            {
                  case '[':
                        ON_ERROR(pdf_lex_array(b, &t));
                        PUSH_O(t);
                        break;
                  case '(':
                        ON_ERROR(pdf_lex_string(b, buf, LEX_BUF_LEN));
                        t.t = eString;
                        t.value.s.len = strlen((char*)buf);
                        t.value.s.buf = pdf_malloc(o->value.s.len);
                        strncpy(t.value.s.buf, (char*)buf, o->value.s.len);
                        PUSH_O(t);
                        break;
                  case '<':
                        if ((c = mGETCHAR(b)) && c != EOF)
                        {
                              if (c == '<')
                              {
                                    ON_ERROR(pdf_parse_dict(b, &t));
                                    PUSH_O(t);
                              }
                              else
                              {
                                    ON_ERROR(pdf_lex_hexstring(b, buf, LEX_BUF_LEN));
                                    t.t = eHexString;
                                    t.value.s.len = strlen((char*)buf);
                                    t.value.s.buf = pdf_malloc(o->value.s.len);
                                    strncpy(t.value.s.buf, (char*)buf, o->value.s.len);
                                    PUSH_O(t);
                              }
                        }
                        break;
                  case '/':
                        ON_ERROR(pdf_lex_name(b, buf, LEX_BUF_LEN));
                        t.t = eKey;
                        t.value.k = pdf_malloc(strlen((char*)buf)+1);
                        memcpy(t.value.k, buf, (strlen((char*)buf)+1));
                        PUSH_O(t);
                        mUNGETCHAR(b);
                        break;
                  case '.':
                  case '+':
                  case '-':
                        {
                              ON_ERROR(pdf_lex_number(b, c, &n));
                              mUNGETCHAR(b);
                              PUSH_N(n);
                        }
                  break;
                  default:
                        if (isspace(c))
                              break;
                        ///////////////////////////////////////////
                        // lex stream commands
                        mUNGETCHAR(b);
                        ON_ERROR(pdf_lex_cmd(b, buf, LEX_BUF_LEN, &cmdlen))
                              switch (cmdlen)
                              {
                                    ////////////////////////////// single letter command
                                    case 1:
                                          switch (buf[0])
                                          {
                                                case '\"':
                                                      break;
                                                case '\'':
						      x_Tstar(p);
                                                      x_Tj(p, POP_O);
                                                      break;
                                                case 'b':
                                                      break;
                                                case 'c':
                                                      x_c(p, np[-1], np[-2], np[-3], np[-4], np[-5], np[-6]);
                                                      POP_N(6);
                                                      break;
                                                case 'd':
                                                      x_d(p, POP_O);
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
                                                      x_i(p, np[-1]); // flatness
                                                      POP_N(1);
                                                      break;
                                                case 'j':
                                                      x_j(p, np[-1]); // linejoin
                                                      POP_N(1);
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
                                                      x_w(p, np[-1]); // linewidth
                                                      POP_N(1);
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
                                                      x_J(p, np[-1]); // linecap
                                                      POP_N(1);
                                                      break;
                                                case 'K':
                                                      x_K(p, np[-1], np[-2], np[-3], np[-4]);
                                                      POP_N(4);
                                                      break;
                                                case 'M':
                                                      x_M(p, np[-1]); // miterlimit
                                                      POP_N(1);
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
                                                      x_cs(p, POP_O);
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
                                                      x_gs(p, POP_O);
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
                                                      x_ri(p, POP_O); // rendering intents
                                                }
                                                break;
                                                case TWO_HASH('s','c'):
                                                {
                                                      int n = pdf_brush_n(p);
                                                      //x_sc(p);
                                                      POP_N(n);
                                                }
                                                break;
                                                case TWO_HASH('s','h'):
                                                {
                                                      x_sh(p, POP_O);
                                                }
                                                break;
                                                case TWO_HASH('B', '*'): x_Bstar(p); break; // B*
                                                case TWO_HASH('B', 'I'): x_BI(p); break;// BI
                                                case TWO_HASH('B', 'T'): x_BT(p); break; // BT
                                                case TWO_HASH('B', 'X'): x_BX(p); break; // BX
                                                case TWO_HASH('C','S'):
                                                {
                                                      x_CS(p, POP_O);
                                                }
                                                break;
                                                case (TWO_HASH('D','o')):
                                                {
                                                      x_Do(p, POP_O);
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
                                                case TWO_HASH('I', 'D'): // ID
                                                {
                                                      //x_ID(p);
                                                }
                                                break;
                                                case TWO_HASH('T', '*'): // T*
                                                      x_Tstar(p);
                                                      break;
                                                case TWO_HASH('T', 'c'): // Tc
                                                      x_Tc(p);
                                                      break;
                                                case TWO_HASH('T', 'd'): // Td
                                                      x_Td(p, np[-2], np[-1]);
                                                      POP_N(2);
                                                      break;
                                                case TWO_HASH('T', 'D'): // Td
                                                      x_TD(p, np[-2], np[-1]);
                                                      POP_N(2);
                                                      break;
                                                case TWO_HASH('T', 'f'): // Tf
                                                      x_Tf(p, POP_O,  np[-1]);
                                                      POP_N(1);
                                                      break;
                                                case TWO_HASH('T', 'j'): // Tj
                                                      x_Tj(p, POP_O);
                                                      break;
                                                case TWO_HASH('T', 'J'): // TJ
                                                      x_TJ(p, POP_O);
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
                                                pdf_obj a, b;
                                                b = POP_O;
                                                a = POP_O;
                                                x_BDC(p, a, b);
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
                                                int n = pdf_pen_n(p);
                                                //x_sc(p);
                                                POP_N(n);
                                                //x_SCN(p);
                                          }
                                          else if (buf[0] == 's' && buf[1] == 'c' && buf[2] == 'n')
                                          {
                                                int n = pdf_brush_n(p);
                                                //x_sc(p);
                                                POP_N(n);
                                                //x_scn(p);
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
