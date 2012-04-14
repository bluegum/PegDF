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
#include "readpdf.h"
#include "pdfindex.h"
#include "dict.h"
#include "pdfdoc.h"
#include "pdfmem.h"

extern int yyparse();
extern char *yytext;

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
    case eString:
      {
	pdf_obj o;
	o.t = eString;
	if (s)
	  {
	    o.value.s.len = strlen(s);
	    o.value.s.buf = pdf_malloc(strlen(s));
	    memcpy(o.value.s.buf, s, strlen(s));
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
  o.value.a.items = pdf_malloc(sizeof(pdf_obj)*(o.value.a.len));
   
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
	  o->value.s.len = strlen(s);
	  o->value.s.buf = pdf_malloc(o->value.s.len);
	  memcpy(o->value.s.buf, s, o->value.s.len);
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
#ifdef DEBUG
  printf("startxref = %d\n", i);
#endif
  parser_inst->startxref = i;
  return;
}

void pop_comment(char *s, int len)
{
  parser_inst->comment_string = s;
}

void pop_stream(int pos)
{
  dict *d;
  sub_stream *s;
#ifdef YY_DEBUG
  printf("stream starts at %d.\n", pos);
#endif
  if (parser_inst->stack[parser_inst->stackp].t != eDict)
    return;
  d = parser_inst->stack[parser_inst->stackp].value.d.dict;
  // S_O stands for stream_object
  // insert stream object
  // +6 to offset "stream"
  s = (parser_inst->create_stream)(pos+6, 0);
  dict_insert(d, "S_O", s);
}

// return 0: ok
int read_linearized_dict(pdf_obj *o, linearized *l)
{
  dict *d;
  pdf_obj *a;
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
  if (p->trailer)
    {
      t->next = p->trailer;
      p->trailer = t;
    }
  else
    {
      p->trailer = t;
    }
#if 0
  a = dict_get(d, "Root");
  if (a && (a->t == eDict || a->t == eRef))
    {
      t->root = *a;
    }
#else
  t->root = *o;
  t->is_xrefstm = 1;
#endif
  return 0;
}
/// parser getchar
static int my_getchar()
{
  int c;
  c = getc(parser_inst->infile);
  parser_inst->file_position += 1;
#ifdef YY_DEBUG
   if (EOF != c) printf("<%c>\n", c); 
#endif
   return c;
}

/// make a new parser
pdf_parser*
parser_new(FILE *in, FILE *out, parser_getchar getchar)
{
  pdf_parser *parser_inst;
  parser_inst = (pdf_parser*)pdf_malloc(sizeof(pdf_parser));
  if (!parser_inst)
    return NULL;
  parser_inst->infile = in;
  parser_inst->outfile = out;
  parser_inst->getchar = getchar;
  parser_inst->file_position = 0;
  parser_inst->xref = 0;
  parser_inst->trailer = 0;
  parser_inst->startxref = -1;
  parser_inst->stackp = -1;
  return parser_inst;
}
////////////////////////////////////////////////////
// example application
////////////////////////////////////////////////////
pdf_parser *parser_inst;
extern void parser_free();

int main(int argc, char **argv)
{
  int i = 1;
  char *in = NULL;
  char *out = NULL;
  int linear = 0;
  FILE *inf=stdin, *outf=stdout;
  if (argc > 1)
    {
      while (i < argc)
	{
	  if (argv[i][0] == '-')
	    {
	      char opt = argv[i][1];
	      switch (opt)
		{
		case 'o':
		  {
		    if (isspace(argv[i][2]))
		      {
			argv += 1;
		      }
		    out = *argv;
		  }
		  break;
		default:
		  break;
		}
	    }
	  else
	    {
	      in = argv[i];
	    }
	  i += 1;
	}
    }
  if (in)
    {
      printf("reading = %s\n", in);
      inf = fopen(in, "rb");
      if (!inf)
	{
	  printf("Can not open %s.\n", in);
	  return 1;
	}
    }
  if (out)
    {
      printf("writing = %s\n", out);
      outf = fopen(out, "wb");
      if (!outf)
	{
	  printf("Can not open %s.\n", out);
	  return 1;
	}
    }
  parser_inst = parser_new(inf, outf, my_getchar);
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
	    printf("%s\n", "processing linearized pdf file");
	    if (read_linearized_dict(first_obj, &parser_inst->l) != 0)
	      linear = 0;
	    else
	      linear = 1;
	  }
      }
  }
  // process linearized headers
  if (linear)
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
    }
  // parse the rest
  while (1)
    {
      if (yyparse() == 0)
	{
	  printf("%s\n", "PDF file spec error");
	  break;
	}
      else
	{
	  if (linear)
	    {
	      if (parser_inst->cur_obj == parser_inst->l.O)
		{
		  printf("%s\n", "Just parsed the first page");
		}
	    }
	}
    }
  parser_free();
#ifdef DEBUG
  pdf_obj_walk();
#endif
  pdf_trailer_open(parser_inst->trailer);
  {
    trailer *t = parser_inst->trailer;
    while (t)
      {
	trailer *tt = t->next;
	pdf_free(t);
	t = tt;
      }
  }
  xref_delete();
  pdf_obj_free();
 done:
  if (parser_inst->infile != stdin)
    {
      fclose(parser_inst->infile);
    }
  if (parser_inst->outfile != stdout)
    {
      fclose(parser_inst->outfile);
    }
  if (parser_inst)
    pdf_free(parser_inst);
#ifdef DEBUG
  print_mem_tracking();
#endif
  return 0;
}
