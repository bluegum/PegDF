/*
  Copyright (C) 2011 by Dakai Liu

  Permission is hereby granted, pdf_free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pdftypes.h"
#include "pdfindex.h"
#include "dict.h"
#include "pdffilter.h"
#include "pdfdoc.h"
#include "pdfmem.h"
#include "pdfcrypto.h"
#include "pdfread.h"

extern int yyparse();
extern char *yytext;
extern void parser_free();
pdf_parser *parser_inst;

int push(e_pdf_kind t, double n, char *s)
{
      parser_inst->stack[++parser_inst->stackp].t =t;
      switch (t)
      {
            case eInt:
                  parser_inst->stack[parser_inst->stackp].value.i = n;
                  break;
            case eReal:
                  parser_inst->stack[parser_inst->stackp].value.f = n;
                  break;
            case eBool:
                  parser_inst->stack[parser_inst->stackp].value.i = n;
                  break;
            case eKey:
                  parser_inst->stack[parser_inst->stackp].value.k = pdf_malloc(strlen(s)+1);
                  memcpy(parser_inst->stack[parser_inst->stackp].value.k, s, strlen(s)+1);
                  break;
            case eHexString:
            {
                  pdf_obj o;
                  o.t = eHexString;
                  if (s)
                  {
                        char *pout;
                        int i;
                        o.value.s.len = strlen(s)/2;
                        pout = o.value.s.buf = pdf_malloc(o.value.s.len);
                        for (i = 0; i < o.value.s.len; i++)
                        {
                              int a = *s++;
                              if (isdigit(a)) *pout = a - '0';
                              else if (isxdigit(a)) *pout = toupper(a) - 'A' + 10;
                              *pout <<= 4;
                              a = *s++;
                              if (isdigit(a)) *pout += a - '0';
                              else if (isxdigit(a)) *pout += toupper(a) - 'A' + 10;
                              pout++;
                        }
                  }
                  else
                        o.value.s.len = 0;
                  parser_inst->stack[parser_inst->stackp] = o;
            }
            break;
            case eString:
            {
                  pdf_obj o;
                  o.t = eString;
                  if (s)
                  {
                        o.value.s.len = strlen(s);
                        o.value.s.buf = pdf_malloc(o.value.s.len);
                        memcpy(o.value.s.buf, s, o.value.s.len);
                  }
                  else
                        o.value.s.len = 0;
                  parser_inst->stack[parser_inst->stackp] = o;
            }
            break;
            default:
                  break;
      }
      return 0;
}

pdf_obj pop(void)   { return parser_inst->stack[parser_inst->stackp--]; }

// pop dict entries off stack and assemble a dict obj and push onto stack
pdf_obj pop_dict(void)
{
      int i = 0;
      pdf_obj o, *a = NULL;
      dict* d = dict_new();

      //printf("pop-dict:-- <<");

      o.t = eDict;
      o.value.d.dict = d;
      while (parser_inst->stack[parser_inst->stackp--].t != eDictMarker)
      {
            if (i%2)
            {
                  //printf("%s|", (char*)(parser_inst->stack[parser_inst->stackp+1].value.k));
                  dict_insert(d, parser_inst->stack[parser_inst->stackp+1].value.k, a);
                  pdf_free(parser_inst->stack[parser_inst->stackp+1].value.k);
            }
            else
            {
                  a = pdf_malloc(sizeof(pdf_obj));
                  *a = parser_inst->stack[parser_inst->stackp+1];
            }
            i += 1;
      }
      //printf(">>\n");
      parser_inst->stackp += 1;
      parser_inst->stack[parser_inst->stackp] = o;
      return o;
}

pdf_obj push_array(void)
{
      int i = parser_inst->stackp;
      pdf_obj o, p;
      int k = 0;
#ifdef YY_DEBUG
      printf("push-array: [");
#endif
      while (parser_inst->stack[i--].t != eArrayMarker);
      o.t = eArray;
      o.value.a.len = parser_inst->stackp-i-1;
      if (o.value.a.len)
	    o.value.a.items = pdf_malloc(sizeof(pdf_obj)*(o.value.a.len));
      else
	    o.value.a.items = NULL;
      for (k = o.value.a.len - 1, p = pop(); p.t != eArrayMarker; k--)
      {
            o.value.a.items[k] = p;
            p = pop();
      }
      parser_inst->stack[++parser_inst->stackp] = o;
#ifdef YY_DEBUG
      printf("]\n");
#endif
      return o;
}

pdf_obj push_literal(char *s)
{
      if (!s)
      {
            pdf_obj o;
            o.t = eString;
            o.value.s.len = 0;
            o.value.s.buf = NULL;
            parser_inst->stack[++parser_inst->stackp] = o;
      }
      else
      {
            pdf_obj *o;
            o = &parser_inst->stack[parser_inst->stackp];
            if (o->value.s.len)
            {
                  char *p = pdf_malloc(o->value.s.len + strlen(s));
                  memcpy(p, o->value.s.buf, o->value.s.len);
                  memcpy(p + o->value.s.len, s, strlen(s));
                  pdf_free(o->value.s.buf);
                  o->value.s.len += strlen(s);
                  o->value.s.buf = p;
            }
            else
            {
                  /* new string */
                  int len = 0;
                  char *p = s;
                  char *d;
#define isoct(a) ((a)>= '0' && (a)<= '7')
                  o->value.s.len = strlen(s);
                  o->value.s.buf = d = pdf_malloc(o->value.s.len);
                  while (*p)
                  {
                        // translate escape sequence to binary
                        if (*p == '\\')
                        {
                              if (isoct(*(p+1)) && isoct(*(p+2)) && isoct(*(p+3)))
                              {
                                    // TODO : tranlate octal string to octal value
                                    *d++ = *p++;
                              }
                              else
                              {
                                    p++;
                                    switch (*p)
                                    {
                                          case 't':
                                                *d++ = '\t';
                                                break;
                                          case 'n':
                                                *d++ = '\n';
                                                break;
                                          case 'r':
                                                *d++ = '\r';
                                                break;
                                          case 'b':
                                                *d++ = '\b';
                                                break;
                                          default:
                                                *d++ = *p;
                                                break;
                                    }
                                    p++;
                              }
                        }
                        else
                              *d++ = *p++;
                        len++;
                  }
                  o->value.s.len = len;
            }
      }
      return parser_inst->stack[parser_inst->stackp];
}

int push_ref(e_pdf_kind t, int r, int gen)
{
      parser_inst->stack[++parser_inst->stackp].t =t;
      parser_inst->stack[parser_inst->stackp].value.r.gen = gen;
      parser_inst->stack[parser_inst->stackp].value.r.num = r;
      return 0;
}

static
pdf_obj *
dup_pdf_obj(pdf_obj *o)
{
      pdf_obj *n = pdf_malloc(sizeof(pdf_obj));
      memcpy(n, o, sizeof(pdf_obj));
      return n;
}

int pop_obj(void)
{
      int n, gen;
      pdf_obj *o;
#ifdef YY_DEBUG
      printf("%s", "pop-obj:\n");
      printf ("object..\n");
#endif
      o = dup_pdf_obj(&parser_inst->stack[parser_inst->stackp]);
      while (parser_inst->stack[parser_inst->stackp--].t != eObjMarker);
      gen = pop().value.i; // gen num
      n = pop().value.i; // obj num
      parser_inst->cur_obj = n;
      parser_inst->cur_gen = gen;
      return pdf_obj_insert(n, gen, o);
}

int read_trailer(void)
{
      trailer *t;
      t = pdf_malloc(sizeof(trailer));
      if (!t)
            return -1;
      memset(t, 0, sizeof(trailer));
      if (parser_inst->trailer)
      {
            t->next = parser_inst->trailer;
            parser_inst->trailer = t;
      }
      else
      {
            parser_inst->trailer = t;
      }
      t->root = pop();
      dict_dump(t->root.value.d.dict);
      return 0;
}

void print_stack()
{
      printf("current stack: depth=%d\n", parser_inst->stackp);
      while (parser_inst->stackp>=0)
      {
            printf("%d\n", parser_inst->stack[parser_inst->stackp--].t);
      }
}
int xref_new(int off, int n)
{
      xreftab *x;
      if (n < 1)
      {
            return 1;
      }
      x = pdf_malloc(sizeof(xreftab));
      if (!x)
            return -1;
      memset(x, 0, sizeof(xreftab));
      if (!parser_inst->xref)
      {
            parser_inst->xref = x;
      }
      else
      {
            // insert to head
            x->next = parser_inst->xref;
            parser_inst->xref = x;
      }
      x->idx = off;
      x->count = n;
      x->obj = pdf_malloc(n*sizeof(xrefentry_t));
#ifdef YY_DEBUG
      printf("Created xref table of %d entries\n", n);
#endif
      return 0;
}

int xref_append(int off, int gen, pdf_obj o)
{
      xreftab *x = parser_inst->xref;
#ifdef YY_DEBUG
      printf("xref_entry:%d,%d,%c\n", off, gen, x.value.i);
#endif
      if (x->idx >= x->count)
            return 0;
      x->obj[x->idx].off = off;
      x->obj[x->idx].gen = gen;
      x->obj[x->idx].x = o.value.i;
      x->idx += 1;
      if (x->idx >= x->count)
      {
            x->idx = x->count - 1;
      }
      return 0;
}

int xref_delete()
{
      xreftab *x = parser_inst->xref;
      //printf("xref=%d\n", g_xreftab.idx);
      while (x)
      {
            xreftab *t = x->next;
            pdf_free(x->obj);
            pdf_free(x);
            x = t;
      }
      return 0;
}

void
xref_start(int i)
{
      char buf[128];
      sprintf(buf, "startxref = %d\n", i);
      DMSG(buf);
      parser_inst->startxref = i;
      return;
}

void pop_comment(char *s, int len)
{
      parser_inst->comment_string = s;
}

void parse_finish()
{
      parser_inst->parse_finished = 1;
}
// return 0 if match
static int
match_string(char *m)
{
      int c;
      char *s = m;
      while (1)
      {
            if (*s == 0) // success
                  break;
            if ((c = (parser_inst->getchar)()) == EOF)
                  return -1;
            if (c == *s++)
            {
                  continue;
            }
            else
            {
                  s = m; // reset
                  continue;
            }
      }
      return 0;
}

void pop_stream(int pos)
{
      pdf_obj *o;
      dict *d;
      sub_stream *s;
      int i, length;
      int c;
      int cache_stm = 0;
      char *cache = NULL;
#ifdef YY_DEBUG
      printf("stream starts at %d.\n", pos);
#endif
      if (parser_inst->stack[parser_inst->stackp].t != eDict)
            return;
      d = parser_inst->stack[parser_inst->stackp].value.d.dict;
      o = dict_get(d, "Length");
      if (o && o->t != eRef)
      {
            length = o->value.i;
            /// is a hinting stream?
            o = dict_get(d, "S");
            if (o) cache_stm = 1;
            /// is it an object stream?
            o = dict_get(d, "Type");
            if (o && o->t == eKey && (strncmp(o->value.k, "ObjStm", 6) == 0)) cache_stm = 1;
            /// is it an xref stream?
            o = dict_get(d, "Type");
            if (o && o->t == eKey && (strncmp(o->value.k, "XRef", 4) == 0)) cache_stm = 1;
            if (//parser_inst->l.Linearized ||
                  cache_stm)
            {
                  char *pcache;
                  cache = pdf_malloc(length);
                  if (!cache)
                        return;
                  pcache = cache;
                  for (i = 0; i < length; i++)
                  {
                        if ((c = (parser_inst->getchar)()) == EOF)
                        {
                              break;
                        }
                        else
                        {
                              *pcache++ = c;
                        }
                  }
            }
            else
            {
                  for (i = 0; i < length; i++)
                        if ((parser_inst->getchar)() == EOF)
                              break;
            }
            // escape 'endstream'
            c = '\r';
            while (c=='\r' || c== '\n') {  c = (parser_inst->getchar)(); }
            if (c == 'e')
            {
                  if (match_string("ndstream") != 0)
                  {
                        DMSG("Stream syntax error!");
                  }
            }
      }
      else
      {
            length = -1; // don't bother to de-reference
            if (parser_inst->l.Linearized)
            {
                  // TODO: cache stream
                  // has to match 'endstream"
                  match_string("endstream");
            }
            else
            {
                  // has to match 'endstream"
                  if (match_string("endstream") != 0)
                  {
                        DMSG("Stream syntax error!");
                  }
            }
      }
      // escape 'endobj'
      c = (parser_inst->getchar)();
      while (c=='\r' || c== '\n' || c== '\t'  || c== ' ') {  c = (parser_inst->getchar)(); }
      if (c == 'e')
      {
            if (match_string("ndobj") != 0)
            {
                  DMSG("Stream syntax error!");
            }
      }

      // S_O stands for stream_object
      // insert stream object
      if (cache_stm)
      {
            extern sub_stream* in_mem_stream_new(int pos, int len);
            s = in_mem_stream_new((int)cache, length);
      }
      else
      {
            s = (parser_inst->create_stream)(pos, 0);
      }
      dict_insert(d, "S_O", s);
      pop_obj();
}
///////////////////////////////////////////////////////////////////////////////
//
// raw object readers
//
///////////////////////////////////////////////////////////////////////////////

extern pdf_parser* parser_new(FILE *in, FILE *out, parser_getchar getchar);

// return 0: ok
int read_linearized_dict(pdf_obj *o, linearized *l)
{
      dict *d;
      pdf_obj *a;
      l->Linearized = 0;
      if (!o || o->t != eDict)
      {
            return 1;
      }
      d = o->value.d.dict;

      a = dict_get(d, "L");
      if (a && a->t == eInt)
            l->L = pdf_to_int(a);
      else
            return 1;
      a = dict_get(d, "H");
      if (a && a->t == eArray)
      {
            int n = pdf_to_int_array(a, l->H);
            if (!n)
                  return 1;
      }
      else
            return 1;
      a = dict_get(d, "O");
      if (a && a->t == eInt)
            l->O = pdf_to_int(a);
      else
            return 1;
      a = dict_get(d, "E");
      if (a && a->t == eInt)
            l->E = pdf_to_int(a);
      else
            return 1;
      a = dict_get(d, "N");
      if (a && a->t == eInt)
            l->N = pdf_to_int(a);
      else
            return 1;
      a = dict_get(d, "T");
      if (a && a->t == eInt)
            l->T = pdf_to_int(a);
      else
            return 1;
      a = dict_get(d, "P");
      if (a && a->t == eInt)
            l->P = pdf_to_int(a);
      l->Linearized = 1;
      return 0;
}
// return 0: ok
int read_xrefstm(pdf_obj *o, pdf_parser *p)
{
      dict *d;
      pdf_obj *a = NULL;
      trailer *t;

      if (!o || o->t != eDict)
      {
            return 1;
      }
      d = o->value.d.dict;
      a = dict_get(d, "Type");
      if (a && a->t == eKey)
      {
            if (strcmp(a->value.k, "XRef") != 0)
            {
                  return -1;
            }
      }
      else
      {
            return -1;
      }
      t = pdf_malloc(sizeof(trailer));
      if (!t)
            return -1;
      memset(t, 0, sizeof(trailer));
#if 0
      a = dict_get(d, "Root");
      if (a && (a->t == eDict || a->t == eRef))
      {
            t->root = *a;
      }
#else
      t->root = *o;
      t->is_xrefstm = 1;
      if ((o = dict_get(o->value.d.dict, "S_O")) != NULL)
      {
            sub_stream *ss = (sub_stream*)o;
            ss->close(ss);
      }
#endif
      if (p->trailer)
      {
            t->next = p->trailer;
            p->trailer = t;
      }
      else
      {
            p->trailer = t;
      }
      return 0;
}
// return 0: ok
int read_hint(pdf_obj *o, hint *h)
{
      dict *d;
      pdf_obj *a;
      if (!o || o->t != eDict)
      {
            return 1;
      }
      d = o->value.d.dict;

      a = dict_get(d, "S");
      if (a && a->t == eInt)
            h->L = pdf_to_int(a);
      else
            return 1;
      a = dict_get(d, "T");
      if (a && a->t == eInt)
            h->T = pdf_to_int(a);
      a = dict_get(d, "O");
      if (a && a->t == eInt)
            h->O = pdf_to_int(a);
      a = dict_get(d, "A");
      if (a && a->t == eInt)
            h->A = pdf_to_int(a);
      a = dict_get(d, "E");
      if (a && a->t == eInt)
            h->E = pdf_to_int(a);
      a = dict_get(d, "V");
      if (a && a->t == eInt)
            h->V = pdf_to_int(a);
      a = dict_get(d, "I");
      if (a && a->t == eInt)
            h->I = pdf_to_int(a);
      a = dict_get(d, "C");
      if (a && a->t == eInt)
            h->C = pdf_to_int(a);
      a = dict_get(d, "L");
      if (a && a->t == eInt)
            h->L = pdf_to_int(a);
      a = dict_get(d, "R");
      if (a && a->t == eInt)
            h->R = pdf_to_int(a);
      a = dict_get(d, "B");
      if (a && a->t == eInt)
            h->B = pdf_to_int(a);
      {
            sub_stream* ss = dict_get(d, "S_O");
            if (!ss)
                  return 0;
            ss->close(ss);
      }
      return 0;
}
///////////////////////////////////////////////////
/// parser getchar, from file
static int f_getchar()
{
      int c;
      c = getc(parser_inst->infile);
      parser_inst->file_position += 1;
#ifdef YY_DEBUG
      if (EOF != c) printf("<%c>\n", c);
#endif
      return c;
}
///////////////////////////////////////////////////
/// parser getchar, from stream
//extern int pdf_stream_getchar(pdf_stream *s);
int
pdf_stream_getchar(pdf_stream *s)
{
      unsigned char c;
      if ((s->ffilter->read)(s->ffilter, &c, 1) == 0)
            return EOF;
      else
            return c;
}

static int s_getchar()
{
      if (parser_inst->cnt_oneobj) {
            parser_inst->cnt_oneobj--;
            return *parser_inst->p_oneobj++;
      }
      else
            return EOF;
}

int  lex_positive_int(pdf_stream *s)
{
      int c;
      int i=0;
      while (1)
      {
            c = pdf_stream_getchar(s);
            if (c == EOF)
                  break;
            if (c == ' ')
                  continue;
            else
                  break;
      }
      i = c - '0';
      while (1)
      {
            c = pdf_stream_getchar(s);
            if (c == EOF)
                  break;
            if (c >= '0' && c <= '9')
            {
                  i *= 10;
                  i += c - '0';
            }
            else
                  break;
      }
      return i;
}

///////////////////////////////////////////////////////////////////////////////
/// End of parser actions
///////////////////////////////////////////////////////////////////////////////

extern pdf_stream* pdf_stream_load(pdf_obj* o, pdfcrypto_priv *crypto, int numobj, int numgen);

// return 0 when ok
int
read_objstream(pdf_obj *o, int num, int gen)
{
      dict *d;
      pdf_obj *a;
      int i, first, n;
      pdf_stream *s;
      pdf_parser *oldparser;
      struct{int obj, off;} *objs;
      if (!o || o->t != eDict)
      {
            return 1;
      }
      d = o->value.d.dict;

      a = dict_get(d, "First");
      if (a && a->t == eInt)
            first = pdf_to_int(a);
      else
            return 1;
      a = dict_get(d, "N");
      if (a && a->t == eInt)
            n = pdf_to_int(a);
      else
            return 1;

      objs = pdf_malloc(sizeof(*objs)*n);
      // construct filter chain and stream interface
      s = pdf_stream_load(o, NULL, num, gen);
      if (!s) return 1;
      // construct parser
      oldparser = parser_inst;
      parser_inst = parser_new(NULL, NULL, s_getchar);
      // switch in the global obj map
      if (parser_inst->map)
            pdf_map_delete(parser_inst->map);
      parser_inst->map = oldparser->map;
      // lex header block for obj/offset pairs
      for (i = 0; i < n; i++)
      {
            objs[i].obj = lex_positive_int(s);
            objs[i].off = lex_positive_int(s);
      }
      // parse each obj string using yyparse
      for (i = 0; i < n-1; i++)
      {
            int j;
            int len = objs[i+1].off-objs[i].off, ll1, ll2;
            char *buf = pdf_malloc(len+100);
            char *p = buf;
            int ret;
            // construct tmp strings for yyparse
            sprintf(p, "%d 0 obj\n", objs[i].obj);
            ll1 = strlen(p);
            p += strlen(p);
            for (j = 0; j < len; j++)
                  *p++ = pdf_stream_getchar(s);
            sprintf(p, "%s", "endobj\n");
            ll2 = strlen(p);
            parser_inst->oneobj = buf;
            parser_inst->p_oneobj = buf;
            parser_inst->cnt_oneobj = ll1+ll2+len;
            ret = yyparse();
            if (ret == 0)
                  printf("%s\n", "Invalid obj");
            pdf_free(buf);
      }
      // last one
      {
            int cc;
            int len = 0, ll1, ll2, max = 1024;
            char *buf = pdf_malloc(max);
            char *p = buf, *e = buf+max;
            int ret;
            // TODO: using in-mem stream instead of read all in.
            // construct tmp strings for yyparse
            sprintf(p, "%d 0 obj\n", objs[i].obj);
            ll1 = strlen(p);
            p += strlen(p);
            while(1)
            {
                  cc = pdf_stream_getchar(s);
                  if (cc == EOF)
                        break;
                  // else
                  *p++ = cc;
                  len++;
                  if (p >= e)
                  {
                        int cur_len = p - buf;
                        buf = pdf_realloc(buf, max*2);
                        if (!buf)
                        {
                              printf("obj buffer too small, realloc failed, aborting parsing obj stream!\n");
                              break;
                        }
                        max *= 2;
                        p = buf + cur_len;
                        e = buf + max;
                  }
            }
            sprintf(p, "%s", "endobj\n");
            ll2 = strlen(p);
            parser_inst->oneobj = buf;
            parser_inst->p_oneobj = buf;
            parser_inst->cnt_oneobj = ll1+ll2+len;
            ret = yyparse();
            if (ret == 0)
                  printf("%s\n", "Invalid obj");
            pdf_free(buf);
      }
      ////////////////////
      pdf_free(parser_inst);
      parser_inst = oldparser;
      pdf_stream_free(s);
      pdf_free(objs);
      return 0;
}

static void
pdf_encrypt_free(pdf_encrypt *encrypt)
{
      if (!encrypt)
	    return;
      if (encrypt->filter) pdf_free(encrypt->filter);
      if (encrypt->subfilter) pdf_free(encrypt->subfilter);
      if (encrypt->stmf) pdf_free(encrypt->stmf);
      if (encrypt->strf) pdf_free(encrypt->strf);
      if (encrypt->eff) pdf_free(encrypt->eff);
      // to free CF
      // free this
      pdf_free(encrypt);
}

/// make a new parser
pdf_parser*
parser_new(FILE *in, FILE *out, parser_getchar getchar)
{
      pdf_parser *parser_inst;
      parser_inst = (pdf_parser*)pdf_malloc(sizeof(pdf_parser));
      if (!parser_inst)
            return NULL;
      parser_inst->parse_finished = 0;
      parser_inst->infile = in;
      parser_inst->outfile = out;
      parser_inst->getchar = getchar;
      parser_inst->file_position = 0;
      parser_inst->xref = 0;
      parser_inst->trailer = 0;
      parser_inst->startxref = -1;
      parser_inst->stackp = -1;
      parser_inst->l.Linearized = 0;
      parser_inst->map = pdf_map_create();
      return parser_inst;
}

pdf_err
pdf_encrypt_load(pdf_obj *o, pdf_encrypt **encrypt)
{
      pdf_obj *a;
      pdf_encrypt *e;
      *encrypt = pdf_malloc(sizeof(pdf_encrypt));
      if (!*encrypt)
            return pdf_mem_err;
      if (!o)
            return pdf_ok;
      pdf_obj_resolve(o);
      memset(*encrypt, 0, sizeof(pdf_encrypt));
      e = *encrypt;
      a = dict_get(o->value.d.dict, "Filter");
      if (a)
      {
            pdf_obj_resolve(a);
            (*encrypt)->filter = pdf_malloc(strlen(a->value.k)+1);
            memcpy((*encrypt)->filter, a->value.k, strlen(a->value.k));
            (*encrypt)->filter[strlen(a->value.k)] = 0;
      }
      a = dict_get(o->value.d.dict, "SubFilter");
      if (a)
      {
            pdf_obj_resolve(a);
            (*encrypt)->subfilter = pdf_malloc(strlen(a->value.k)+1);
            memcpy((*encrypt)->subfilter, a->value.k, strlen(a->value.k));
            (*encrypt)->subfilter[strlen(a->value.k)] = 0;
      }
      a = dict_get(o->value.d.dict, "V");
      if (a)
      {
            pdf_obj_resolve(a);
            (*encrypt)->v = pdf_to_int(a);
      }
      a = dict_get(o->value.d.dict, "Length");
      if (a)
      {
            pdf_obj_resolve(a);
            (*encrypt)->length = pdf_to_int(a);
      }
      a = dict_get(o->value.d.dict, "StmF");
      if (a)
      {
            pdf_obj_resolve(a);
            (*encrypt)->stmf = pdf_malloc(strlen(a->value.k)+1);
            memcpy((*encrypt)->stmf, a->value.k, strlen(a->value.k));
            (*encrypt)->stmf[strlen(a->value.k)] = 0;
      }
      a = dict_get(o->value.d.dict, "StrF");
      if (a)
      {
            pdf_obj_resolve(a);
            (*encrypt)->strf = pdf_malloc(strlen(a->value.k)+1);
            memcpy((*encrypt)->strf, a->value.k, strlen(a->value.k));
            (*encrypt)->strf[strlen(a->value.k)] = 0;
      }
      a = dict_get(o->value.d.dict, "EFF");
      if (a)
      {
            pdf_obj_resolve(a);
            (*encrypt)->eff = pdf_malloc(strlen(a->value.k)+1);
            memcpy((*encrypt)->eff, a->value.k, strlen(a->value.k));
            (*encrypt)->eff[strlen(a->value.k)] = 0;
      }
      a = dict_get(o->value.d.dict, "CF");
      if (a)
      {
            pdf_cf_load(a, &e->cf);
      }
      // standard encryption dictionary (items)
      a = dict_get(o->value.d.dict, "R");
      if (a)
      {
            pdf_obj_resolve(a);
            (*encrypt)->r = pdf_to_int(a);
      }
      a = dict_get(o->value.d.dict, "O"); // owner password
      if (a)
      {
            // should verify length to 32 bytes
            pdf_obj_resolve(a);
            memcpy((*encrypt)->o, a->value.s.buf, a->value.s.len);
      }
      a = dict_get(o->value.d.dict, "U"); // user password
      if (a)
      {
            // should verify length to 32 bytes
            pdf_obj_resolve(a);
            memcpy((*encrypt)->u, a->value.s.buf, a->value.s.len);
      }
      a = dict_get(o->value.d.dict, "P"); // permission flags
      if (a)
      {
            pdf_obj_resolve(a);
            (*encrypt)->p = pdf_to_int(a);
      }
      a = dict_get(o->value.d.dict, "EncryptMetadata");
      if (a)
      {
            pdf_obj_resolve(a);
            (*encrypt)->encrypt_metadata = a->value.b;
      }

      return pdf_ok;
}

static
pdf_err
pdf_trailer_open(trailer *tr, pdf_trailer ** out)
{
      pdf_obj *a, *o;
      pdf_trailer *last = NULL;
  prev_trailer:
      o = &tr->root;
      if (!o || (o->t != eDict && o->t != eRef))
            return pdf_trailer_err;
      pdf_obj_resolve(o);

      a = dict_get(o->value.d.dict, "Root");
      if (!a)
      {
	    if (tr->next)
	    {
		  tr = tr->next;
		  goto prev_trailer;
	    }
      }
      if (!a || a->t != eRef)
            return pdf_trailer_err;

      *out = pdf_malloc(sizeof(pdf_trailer));
      memset(*out, 0, sizeof(pdf_trailer));
      (*out)->last = last;
      (*out)->root_obj = a;
      a = dict_get(o->value.d.dict, "Size");
      if (a && a->t == eInt)
      {
            (*out)->size = a->value.i;
      }
      a = dict_get(o->value.d.dict, "Prev");
      if (a && a->t == eInt)
      {
            (*out)->prev = a->value.i;
      }
      a = dict_get(o->value.d.dict, "Encrypt");
      if (a)
      {
            pdf_encrypt_load(a, &(*out)->encrypt);
      }
      a = dict_get(o->value.d.dict, "Info");
      if (a)
      {
            pdf_info_load(a, &(*out)->info);
      }
      a = dict_get(o->value.d.dict, "ID");
      if (a && a->t == eArray)
      {
            memcpy((*out)->id[0], a->value.a.items[0].value.s.buf, 16);
            memcpy((*out)->id[1], a->value.a.items[1].value.s.buf, 16);
      }
      /// xrefstream entries
      a = dict_get(o->value.d.dict, "Index");
      if (a)
      {
            pdf_to_int_array(a, (*out)->index);
      }
      a = dict_get(o->value.d.dict, "W");
      if (a)
      {
            pdf_to_int_array(a, (*out)->w);
      }

      if (tr->next)
      {
            tr = tr->next;
	    last = *out;
            goto prev_trailer;
      }

      return pdf_ok;
}

static void
pdf_info_free(pdf_info *info)
{
      if (!info)
            return;
      if (info->title)  pdf_free(info->title);
      if (info->author)  pdf_free(info->author);
      if (info->subject)  pdf_free(info->subject);
      if (info->keywords)  pdf_free(info->keywords);
      if (info->creator)  pdf_free(info->creator);
      if (info->producer)  pdf_free(info->producer);
      if (info->creationdate) pdf_free(info->creationdate);
      if (info->moddate)  pdf_free(info->moddate);
}

pdf_err
pdf_trailer_free(pdf_trailer * tr)
{
      trailer *tt, *t = parser_inst->trailer;
      // really done
      while (tr)
      {
	    pdf_trailer *last;
	    if (tr->info)
	    {
		  pdf_info_free(tr->info);
		  pdf_free(tr->info);
		  pdf_encrypt_free(tr->encrypt);
	    }
	    last = tr->last;
	    pdf_free(tr);
	    tr = last;
      }
      // free trailer train
      while (t)
      {
	    tt = t->next;
            if (t->root.t == eDict && t->is_xrefstm == 0)
                  dict_free(t->root.value.d.dict);
	    pdf_free(t);
	    t = tt;
      }

      return pdf_ok;
}

pdf_err
pdf_read(char *in, char *out, pdf_doc **doc)
{
      FILE *inf=stdin, *outf=stdout;
      if (in)
      {
            printf("reading = %s\n", in);
            inf = fopen(in, "rb");
            if (!inf)
            {
                  fprintf(stderr, "Can not open %s.\n", in);
                  return pdf_io_err;
            }
      }
      if (out)
      {
            printf("writing = %s\n", out);
            outf = fopen(out, "wb");
            if (!outf)
            {
                  fprintf(stderr, "Can not open %s.\n", out);
                  return pdf_io_err;
            }
      }
      parser_inst = parser_new(inf, outf, f_getchar);
      if (!parser_inst)
            return -1;
      // configure parser
      init_filestream_parser_instance(parser_inst);

      // parse magic
      yyparse();
      if (*parser_inst->comment_string == '%')
      {
            char *p = parser_inst->comment_string+1;
            while(*p == '%') {p++;};
            if ((p[0] == 'p' || p[0] == 'P') &&
                (p[1] == 'd' || p[1] == 'D') &&
                (p[2] == 'f' || p[2] == 'F'))
            {
                  fprintf(stdout, "%s\n", parser_inst->comment_string);
                  *parser_inst->comment_string = 0;
            }
            else
            {
                  fprintf(stderr, "%s\n", "Not a pdf file!");
                  goto done;
            }
      }
      else
      {
            fprintf(stderr, "%s\n", "Not a pdf file!");
            goto done;
      }
      // escape all leading comment lines
      while (1)
      {
            if (yyparse() == 0)
            {
                  printf("%s\n", "PDF file spec error");
                  break;
            }
            else
            {
                  if (!(*parser_inst->comment_string))
                        break;
                  else
                        *parser_inst->comment_string = 0;
            }
      }
      // Look for linearized dict
      {
            pdf_obj *first_obj;
            first_obj = pdf_obj_find(parser_inst->cur_obj, parser_inst->cur_gen);
            if (first_obj && first_obj->t == eDict)
            {
                  pdf_obj *l;
                  l = dict_get(first_obj->value.d.dict, "Linearized");
                  if (l && (l->t == eReal || l->t == eInt))
                  {
                        DMSG("processing linearized pdf file");
                        read_linearized_dict(first_obj, &parser_inst->l);
                  }
            }
      }
      // process linearized headers
      if (parser_inst->l.Linearized)
      {
            if (yyparse() == 0)
            {
                  printf("%s\n", "PDF file spec error");
            }
            else
            {
                  printf("%s\n", "Processing first xref");
                  if (parser_inst->xref == 0) // On the other hand, a legacy xref tab has been read
                  {
                        // xref must reside inside an XRefStm obj
                        pdf_obj *o = pdf_obj_find(parser_inst->cur_obj, parser_inst->cur_gen);
                        read_xrefstm(o, parser_inst);
                  }
            }
            /// read hinting dict
            while (1)
            {
                  if (yyparse() == 0)
                  {
                        printf("%s\n", "PDF file spec error");
                  }
                  else
                  {
                        pdf_obj *o = pdf_obj_find(parser_inst->cur_obj, parser_inst->cur_gen);
                        if (read_hint(o, &parser_inst->h) == 0)
                        {
                              DMSG("Hinting dictionary processed");
                              break;
                        }
                  }
            }
      }
      // parse the rest
      while (1)
      {
            parser_inst->cur_obj = -1;
            if (yyparse() == 0)
            {
                  printf("%s\n", "PDF file spec error");
                  break;
            }
            else
            {
                  /// process obj stream
                  if (parser_inst->parse_finished)
                        break;
                  if (parser_inst->cur_obj != -1)
                  {
                        pdf_obj *o = pdf_obj_find(parser_inst->cur_obj, parser_inst->cur_gen);
                        if (o && o->t == eDict)
                        {
                              pdf_obj *t = dict_get(o->value.d.dict, "Type");
                              if (t && t->t == eKey)
                              {
                                    if (strncmp(t->value.k, "ObjStm", 6) == 0)
                                    {
                                          DMSG("Procssing Object stream");
                                          read_objstream(o, parser_inst->cur_obj, parser_inst->cur_gen);
                                    }
                                    else if (strncmp(t->value.k, "XRef", 4) == 0)
                                    {
                                          DMSG("Procssing Object stream");
                                          read_xrefstm(o, parser_inst);
                                    }
                              }
                        }
                  }
                  ///
                  if (parser_inst->l.Linearized)
                  {
                        if (parser_inst->cur_obj == parser_inst->l.O)
                        {
                              DMSG("Just parsed the first page");
                        }
                  }
            }
      }
      parser_free();
#ifdef DEBUG
      pdf_obj_walk();
#endif
      if (parser_inst->trailer)
      {
	    pdf_trailer *trailer;
            pdf_trailer_open(parser_inst->trailer, &trailer);
	    *doc = pdf_doc_load(trailer);
      }
      else
	    *doc = NULL;
  done:
      return pdf_ok;
}

pdf_err
pdf_finish(pdf_doc *doc)
{
      xref_delete();
      pdf_obj_free();
      if (parser_inst->infile != stdin)
      {
            fclose(parser_inst->infile);
      }
      if (parser_inst->outfile != stdout)
      {
            fclose(parser_inst->outfile);
      }
      if (parser_inst->map)
      {
            pdf_map_delete(parser_inst->map);
      }
      if (parser_inst)
            pdf_free(parser_inst);
#ifdef DEBUG
      print_mem_tracking();
#endif
      return pdf_ok;
}
