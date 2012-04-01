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
#include "pdftypes.h"
#include "readpdf.h"
#include "pdfindex.h"
#include "dict.h"

extern FILE* infile;
extern FILE* outfile;

static int my_getchar()
{
  int c;
  c = getc(infile);
#ifdef YY_DEBUG
   if (EOF != c) printf("<%c>\n", c); 
#endif
   return c;
}


#define YY_INPUT(buf, result, max)                      \
{                                                       \
  int c = my_getchar();             			\
  result= (EOF == c) ? 0 : (*(buf)= c, 1);              \
}

#include "pdf.c"