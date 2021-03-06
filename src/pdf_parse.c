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
#include "pdfmem.h"
#include "pdftypes.h"
#include "pdfindex.h"
#include "dict.h"
#include "pdfread.h"
#include "pdffilter.h"

extern pdf_parser *parser_inst;

#ifdef DEBUG
 #define malloc pdf_malloc
 #define free pdf_free
 #define realloc pdf_realloc
#endif

#define YY_INPUT(buf, result, max)                      \
      {                                                 \
            int c = (parser_inst->getchar)();           \
            result= (EOF == c) ? 0 : (*(buf)= c, 1);    \
      }

#include "pdf.c"

void parser_free()
{
#if 0
      if (yybuf) free(yybuf);
      if (yytext) free(yytext);
      if (yythunks) free(yythunks);
      if (yyvals) free(yyvals);
#else
      if (yyctx->buf)    free(yyctx->buf);
      if (yyctx->text)   free(yyctx->text);
      if (yyctx->thunks) free(yyctx->thunks);
      if (yyctx->vals)   free(yyctx->vals);
      if (parser_inst->stack)
	    free(parser_inst->stack);
#endif
}
#undef malloc
#undef free
#undef realloc
