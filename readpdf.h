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
#ifndef READPDF_H
#define READPDF_H

typedef struct xrefentry_s
{
  int off;
  int gen;
  char x;
} xrefentry_t;

typedef struct xreftab_s
{
  int idx;
  int count;
  xrefentry_t *obj;
} xreftab_t;

extern int g_xref_off;
extern int g_xref_gen;

extern int push_marker(e_pdf_kind t);
extern int push(e_pdf_kind t, int n);
extern pdf_obj pop(void);
extern pdf_obj pop_dict(void);
extern pdf_obj pop_obj(void);
extern pdf_obj push_array(void);

extern void print_stack();
extern int xref_new(int n);
extern int xref_add(int off, int gen, char x);

#endif
