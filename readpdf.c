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
#include "pdfread.h"
#include "pdfindex.h"
#include "dict.h"
#include "pdfdoc.h"
#include "pdfmem.h"
////////////////////////////////////////////////////
// example application
////////////////////////////////////////////////////
extern pdf_err pdf_read(char *in, char *out);

int main(int argc, char **argv)
{
      int i = 1;
      char *in = NULL;
      char *out = NULL;
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
                              case 'p':
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
                  fprintf(stderr, "Can not open %s.\n", in);
                  return 1;
            }
      }
      if (out)
      {
            printf("writing = %s\n", out);
            outf = fopen(out, "wb");
            if (!outf)
            {
                  fprintf(stderr, "Can not open %s.\n", out);
                  return 1;
            }
      }
      
      return pdf_read(in, out);
}
