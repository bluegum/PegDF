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

// large stack size for large array, ouch!
pdf_obj stack[65536];
int stackp= -1;

int push(e_pdf_kind t, int n) { stack[++stackp].t =t; stack[stackp].value.i = n; return 0;}
int push_marker(e_pdf_kind t)
{
   stack[++stackp].t = t;
   return 0;
}

int push_key(char *s)
{
   stack[++stackp].value.k = pdf_malloc(strlen(s)+1);
   memcpy(stack[stackp].value.k, s, strlen(s)+1);
   stack[stackp].t = eKey;
   return 0;
}

pdf_obj pop(void)   { return stack[stackp--]; }

pdf_obj pop_dict(void)
{
   int i = 0;
   pdf_obj o, *a = NULL;
   dict* d = dict_new();

   //printf("pop-dict:-- <<");

   o.t = eDict;
   o.value.d.dict = d;
   while (stack[stackp--].t != eDictMarker)
   {
      if (i%2)
      {
	//printf("%s|", (char*)(stack[stackp+1].value.k));
	 dict_insert(d, stack[stackp+1].value.k, a);
	 pdf_free(stack[stackp+1].value.k);
      }
      else
      {
	 a = pdf_malloc(sizeof(pdf_obj));
	 *a = stack[stackp+1];
      }
      i += 1;
   }
   //printf(">>\n");
   stackp += 1;
   stack[stackp] = o;
   return o;
}

pdf_obj push_array(void)
{
   int i = stackp;
   pdf_obj o, p;
   int k = 0;
#ifdef DEBUG
   printf("push-array: [");
#endif
   while (stack[i--].t != eArrayMarker);
   o.t = eArray;
   o.value.a.len = stackp-i-1;
   o.value.a.items = pdf_malloc(sizeof(pdf_obj)*(o.value.a.len));
   
   for (k = o.value.a.len - 1, p = pop(); p.t != eArrayMarker; k--)
   {
      o.value.a.items[k] = p;
      p = pop();
   } 
   stack[++stackp] = o;
#ifdef DEBUG
   printf("]\n");
#endif
   return o;
}

pdf_obj push_hexliteral(char *s)
{
   pdf_obj o;
   o.t = eString;
   o.value.s.len = 0;
   if (s)
   {
      o.value.s.len = strlen(s);
      o.value.s.buf = pdf_malloc(strlen(s));
      memcpy(o.value.s.buf, s, strlen(s));
   }
   stack[++stackp] = o;
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
       stack[++stackp] = o;
   }
   else
   {
       pdf_obj *o;
       o = &stack[stackp];
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
   return stack[stackp];
}

void print_literal()
{
#ifdef DEBUG
    int i;
    pdf_obj o = stack[stackp];
    for ( i = 0; i < o.value.s.len; i++) printf("%c", o.value.s.buf[i]);
    printf("\n");
#endif
}

int push_ref(e_pdf_kind t, int r, int gen)
{
   stack[++stackp].t =t; 
   stack[stackp].value.r.gen = gen;
   stack[stackp].value.r.num = r;
   return 0;
}

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
#ifdef DEBUG
   printf("%s", "pop-obj:\n");
   printf ("object..\n");
#endif
   o = dup_pdf_obj(&stack[stackp]);
   while (stack[stackp--].t != eObjMarker);
   gen = pop().value.i; // gen num
   n = pop().value.i; // obj num
   pdf_parser_inst.cur_obj = n;
   pdf_parser_inst.cur_gen = gen;
   return pdf_obj_insert(n, gen, o);
}

int read_trailer(void)
{
  trailer *t;
  t = pdf_malloc(sizeof(trailer));
  if (!t)
    return -1;
  memset(t, 0, sizeof(trailer));
  if (pdf_parser_inst.trailer)
    {
      t->next = pdf_parser_inst.trailer;
      pdf_parser_inst.trailer = t;
    }
  else
    {
      pdf_parser_inst.trailer = t;
    }
  t->root = pop();
  dict_dump(t->root.value.d.dict);
  return 0;
}

void print_stack()
{
   printf("current stack: depth=%d\n", stackp);
   while (stackp>=0)
   {
      printf("%d\n", stack[stackp--].t);
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
   if (!pdf_parser_inst.xref)
     {
       pdf_parser_inst.xref = x;
     }
   else
     {
       // insert to head
       x->next = pdf_parser_inst.xref;
       pdf_parser_inst.xref = x;
     }
   x->idx = off;
   x->count = n;
   x->obj = pdf_malloc(n*sizeof(xrefentry_t));
#ifdef DEBUG
   printf("Created xref table of %d entries\n", n);
#endif
   return 0;
}

int xref_append(int off, int gen, pdf_obj o)
{
  xreftab *x = pdf_parser_inst.xref;
#ifdef DEBUG
  //printf("xref_entry:%d,%d,%c\n", off, gen, x.value.i);
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
  xreftab *x = pdf_parser_inst.xref;
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
xref_start()
{
  pdf_obj o = pop();
  printf("startxref = %d\n", o.value.i);
  return;
}

static char* comment_string;

void pop_comment(char *s, int len)
{
  comment_string = s;
}

void pop_stream(int pos)
{
    dict *d;
    sub_stream *s;
#ifdef DEBUG
  printf("stream starts at %d.\n", pos);
#endif
    if (stack[stackp].t != eDict)
        return;
    d = stack[stackp].value.d.dict;
    // S_O stands for stream_object
    // insert stream object
    // +6 to offset "stream"
    s = (pdf_parser_inst.create_stream)(pos, 0);
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
      int n = pdf_to_int_array(a, &l->H);
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
////////////////////////////////////////////////////
// example application
////////////////////////////////////////////////////
pdf_parser pdf_parser_inst;

int main(int argc, char **argv)
{
   int i = 1;
   char *in = NULL;
   char *out = NULL;
   int linear = 0;

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
   init_filestream_parser_instance(&pdf_parser_inst);
   if (in)
   {
      printf("reading = %s\n", in);
      pdf_parser_inst.infile = fopen(in, "rb");
      if (!pdf_parser_inst.infile)
      {
	 printf("Can not open %s.\n", in);
	 return 1;
      }
   }
   if (out)
   {
      printf("writing = %s\n", out);
      pdf_parser_inst.outfile = fopen(out, "wb");
      if (!pdf_parser_inst.outfile)
      {
	 printf("Can not open %s.\n", out);
	 return 1;
      }
   }
   pdf_parser_inst.file_position = 0;
   pdf_parser_inst.xref = 0;
   pdf_parser_inst.trailer = 0;
   
   //root_obj.t = eLimit;
   //root_obj.value.marker = 0;
   // parse magic
   yyparse();
   if (*comment_string == '%')
     {
       char *p = comment_string+1;
       while(*p == '%') {p++;};
       if ((p[0] == 'p' || p[0] == 'P') &&
	   (p[1] == 'd' || p[1] == 'D') &&
	   (p[2] == 'f' || p[2] == 'F'))
	 {
	   fprintf(stdout, "%s\n", comment_string);
	   *comment_string = 0;
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
	   if (!(*comment_string))
	     break;
	   else
	     *comment_string = 0;
	 }
     }
   // Look for linearized dict
   {
     pdf_obj *first_obj;
     first_obj = pdf_obj_find(pdf_parser_inst.cur_obj, pdf_parser_inst.cur_gen);
     if (first_obj && first_obj->t == eDict)
       {
	 pdf_obj *l;
	 l = dict_get(first_obj->value.d.dict, "Linearized");
	 if (l && (l->t == eReal || l->t == eInt))
	   {
	     printf("%s\n", "processing linearized pdf file");
	     if (read_linearized_dict(first_obj, &pdf_parser_inst.l) != 0)
	       linear = 0;
	     else
	       linear = 1;
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
	      if (pdf_parser_inst.cur_obj == pdf_parser_inst.l.O)
		{
		  printf("%s\n", "Just parsed the first page");
		}
	    }
	}
   }
#ifdef DEBUG
   print_mem_tracking();
   //pdf_obj_walk();
#endif
   pdf_trailer_open(pdf_parser_inst.trailer);
   {
     trailer *t = pdf_parser_inst.trailer;
     while (t)
       {
	 trailer *tt = t->next;
	 pdf_free(t);
	 t = tt;
       }
   }
   xref_delete();
   pdf_obj_free();
#ifdef DEBUG
   print_mem_tracking();
#endif
 done:
   if (pdf_parser_inst.infile != stdin)
   {
      fclose(pdf_parser_inst.infile);
   }
   if (pdf_parser_inst.outfile != stdout)
   {
      fclose(pdf_parser_inst.outfile);
   }
   return 0;
}
