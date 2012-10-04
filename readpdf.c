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
//#include "pdftypes.h"
//#include "pdfindex.h"
//#include "dict.h"
#include "pdffilter.h"
#include "pdfdoc.h"
//#include "pdfmem.h"
//#include "pdfread.h"
////////////////////////////////////////////////////
// example application
////////////////////////////////////////////////////

static void
print_help()
{
      printf("%s\n",
"\n\"readpdf\" reads a pdf file and iterate through pages using stub functions for pdf stream operators.\n\
Usage:\n\
    readpdf [-p passwd] [-x pagenum] [-i] [--help] infile [outfile] [-o outfile]\n\
    Options:\n\
           -p : user password\n\
           -x : extract a single at pagenum, start from 1\n\
           -i : inflate content streams\n\
           --help : print this\n\
\n"
	    );
}

int main(int argc, char **argv)
{
      int i = 1;
      char *in = NULL;
      char *out = NULL;
      pdf_doc *doc;
      char *passwd = NULL;
      int firstpage = 1;
      int lastpage = -1;
      int inflate = 0;
      unsigned char write_flag = 0;

      if (argc > 1)
      {
            while (i < argc)
            {
                  if (argv[i][0] == '-' && argv[i][1] == '-')
		  {
			if (strncmp(argv[i], "--help", sizeof("--help")-1) == 0)
			{
			      print_help();
			      return 0;
			}
		  }
		  else if (argv[i][0] == '-')
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
				    passwd = argv[i];
                                    break;
			      case 'x':
                              {
                                    if (isspace(argv[i][2]) || strlen(argv[i])==2)
                                    {
                                          i++;
					  firstpage = atoi(argv[i]);
                                    }
				    else
				    {
					  firstpage = atoi(argv[i]+2);
				    }
				    lastpage = firstpage;
			      }
			      break;
			      case 'i':
				    inflate = 1;
				    break;
                              default:
                                    break;
                        }
                  }
                  else
                  {
			if (i == 1 || argc - i == 2)
			      in = argv[i];
			else if (i == 2 || argc - i == 1)
			      out = argv[i];
                  }
                  i += 1;
            }
      }
      if (!out)
	    printf("\n%s%s\n\n", "Dry run on ", in);
      pdf_read(in, out, &doc);
      if (!doc)
	    goto done;
      pdf_doc_print_info(doc);
      if (!passwd && pdf_doc_need_passwd(doc) && pdf_doc_authenticate_user_password(doc, "", 0) != 0)
      {
	    printf("%s\n", "Need user password, use -p option");
	    goto done;
      }
      if (!passwd || !pdf_doc_need_passwd(doc))
      {
	    pdf_doc_process_all(doc, "", 0);
      }
      else if (passwd && pdf_doc_need_passwd(doc))
      {
	    pdf_doc_process_all(doc, passwd, strlen(passwd));
      }
      // writing out pdf using doc structure.
      if (out)
      {
	    if (inflate)
		  write_flag |= WRITE_PDF_CONTENT_INFLATE;
	    pdf_write_pdf(doc, out, write_flag, 17, firstpage-1, lastpage-1, NULL, NULL);
      }
  done:
      pdf_doc_done(doc);
      pdf_finish(doc);
      return 0;
}
