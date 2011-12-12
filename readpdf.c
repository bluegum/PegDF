/*
  Copyright (C) 2011 by Dakai Liu

  Permission is hereby granted, free of charge, to any person obtaining a copy
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
#include "pdftypes.h"
#include "readpdf.h"

pdftypes_t stack[1024];
int stackp= -1;
xreftab_t g_xreftab;
int g_xref_off;
int g_xref_gen;

int push(e_pdfsimpletypes t, int n) { stack[++stackp].t =t; stack[stackp].value.i = n; }
int push_marker(e_pdfsimpletypes t)
{
   stack[++stackp].t = t;
}
int push_key(char *s)
{
   stack[++stackp].value.k = malloc(strlen(s)+1);
   memcpy(stack[stackp].value.k, s, strlen(s)+1);
   stack[stackp].t = eKey;
}

pdftypes_t pop(void)   { return stack[stackp--]; }

pdftypes_t pop_dict(void)
{
   int i = 0;
   printf("pop-dict:-- <<");
   while (stack[stackp--].t != eDictMarker)
   {
      if (i%2)
      {
	 printf("%s|", (char*)(stack[stackp+1].value.k));
      }
      i += 1;
   }
   printf(">>\n");
}
pdftypes_t pop_array(void)
{
   int i = 0;
   printf("pop-array: [");
   while (stack[stackp--].t != eArrayMarker)
   {
      printf("-%d-", stack[stackp+1].t);
   }
   printf("]\n");
}
pdftypes_t pop_obj(void)
{
   printf("%s", "pop-obj:\n");
   while (stack[stackp--].t != eObjMarker)
   {
      printf("%d--%d--;", stackp, stack[stackp+1].t);
   }
   ;
   printf("->%d, %d\n", pop().value.i, pop().value.i);
}

void print_stack()
{
   printf("current stack: depth=%d\n", stackp);
   while (stackp>=0)
   {
      printf("%d\n", stack[stackp--].t);
   }
}
int xref_new(int n)
{
   if (n < 1)
   {
      return 1;
   }
   g_xreftab.idx = 0;
   g_xreftab.count = n;
   g_xreftab.obj = malloc(n*sizeof(xrefentry_t));
   printf("Created xref table of %d entries\n", n);
   return 0;
}
int xref_add(int off, int gen, char x)
{
   printf("xref_entry:%d,%d,%c\n", off, gen, x);
   g_xreftab.obj[g_xreftab.idx].off = off;
   g_xreftab.obj[g_xreftab.idx].gen = gen;
   g_xreftab.obj[g_xreftab.idx].x = x;
   g_xreftab.idx += 1;
   if (g_xreftab.idx >= g_xreftab.count)
   {
      g_xreftab.idx = g_xreftab.count - 1;
   }
   return 0;
}

int xref_delete()
{
   //printf("xref=%d\n", g_xreftab.idx);
   free(g_xreftab.obj);
   return 0;
}

FILE* infile;
FILE* outfile;

int main(int argc, char **argv)
{
   int i = 1;
   char *in = NULL;
   char *out = NULL;

   infile = stdin;
   outfile = stdout;

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
		  out = argv;
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
      infile = fopen(in, "rb");
      if (!infile)
      {
	 printf("Can not open %s.\n", in);
	 return 1;
      }
   }
   if (out)
   {
      printf("writing = %s\n", out);
      outfile = fopen(out, "wb");
      if (!outfile)
      {
	 printf("Can not open %s.\n", out);
	 return 1;
      }
   }
   printf(yyparse() ? "\n\nsuccess\n" : "failure\n");
   xref_delete();
   if (infile != stdin)
   {
      fclose(infile);
   }
   if (outfile != stdout)
   {
      fclose(stdout);
   }
   return 0;
}
