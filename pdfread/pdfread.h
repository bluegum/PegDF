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
#include <stdio.h> // due to FILE, should be factored out ASAP
#include "pdftypes.h"
#include "pdfindex.h"

typedef struct pdf_parser_s pdf_parser;
typedef struct sub_stream_s sub_stream;
typedef struct xreftab_s xreftab;
typedef int (*parser_getchar)();

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
      //
      xreftab *next;
} xreftab_t;

typedef struct linearized_s linearized;
struct linearized_s
{
      int Linearized;
      int L;
      int H[4];
      int O;
      int E;
      int N;
      int T;
      int P;
};
typedef struct hint_s hint;
struct hint_s
{
      int S; // shared
      int T; // thumbnail
      int O; // outline
      int A; // thread info
      int E; // named destination
      int V; // interactive form
      int I; // information dict
      int C; // logical struct
      int L; // page label
      int R; // renditions name tree
      int B; // embedded file stream
};

typedef struct trailer_s trailer;
struct trailer_s
{
      pdf_obj root; 
      int is_xrefstm;
      trailer *next;
};

struct pdf_parser_s
{
      int (*getchar)();
      /// parser tmporary storage
      pdf_obj stack[65536]; // large stack size for large array, ouch!
      int stackp;
      char* comment_string;
      //
      xreftab *xref;
      trailer *trailer;
      linearized l;
      hint h;
      int startxref;
      // non-parsing related, for pdf stream object
      int (*seek)(int off);
      int (*read)(unsigned char *, int);
      int (*unget)(unsigned char);
      int (*close)();
      unsigned char* (*cache)(int len);
      sub_stream* (*create_stream)(void *, int, int, int, int);
      /// private
      FILE* infile;
      FILE* outfile;
      int file_position;
      int cur_obj, cur_gen;
      int lock;
      int parse_finished;
      // lex buffer for one-liner parser, for object stream parsing to be specific
      char *oneobj, *p_oneobj;
      int cnt_oneobj;
      // pdf object tree, an alternative to xref table
      pdf_map *map;
};

struct sub_stream_s
{
      int (*reset)(sub_stream*);
      int (*read)(sub_stream*, unsigned char *, int);
      int (*close)(sub_stream*);
      int len;
      int obj, gen;
};

typedef struct obj_num_gen_s
{
      int obj, gen;
} obj_num_gen;

/// The ONLY Global
extern pdf_parser *parser_inst;

/// parser actions
extern int push(e_pdf_kind t, double n, char *s);
extern int push_ref(e_pdf_kind t, int gen, int r);
extern pdf_obj push_array(void);
extern pdf_obj push_literal(char *s);
extern pdf_obj pop(void);
extern pdf_obj pop_dict(void);
extern obj_num_gen pop_obj(void);
extern int read_trailer(void);
extern void print_stack();
extern int xref_new(int off, int n);
extern int xref_append(int off, int gen, pdf_obj x);
extern void pop_comment(char *s, int len);
extern void pop_stream(int pos);
extern void xref_start(int);

/// parser helpers
extern int stream_seek(int s);
extern int stream_read(unsigned char*, int);
extern void init_filestream_parser_instance(pdf_parser *p);
///////////////////// non-descriptives
#ifdef DEBUG
#define DMSG(a)                                 \
      fprintf(stderr, "%s\n", a)
#define _DMSG(a)                                \
      fprintf(stderr, "%s ", a)
#else
#define DMSG(a)
#define _DMSG(a)
#endif
////////////////////////////////
extern void parse_finish();
extern pdf_filter* pdf_rawfilter_new(sub_stream *ss);
#endif
