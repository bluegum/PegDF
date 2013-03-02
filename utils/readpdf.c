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
#include "pdf.h"
#include "pdfdoc.h"
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
           -s : separate page\n\
           -i : inflate content streams\n\
           -d : device\n\
           -I : print catalog\n\
           --help : print this\n\
\n\
    Devices: text html \
\n\
    Example#1: to extract each and every page and write into a sequence of pdf files with inflated content stream,\n\
         and the output are with format as: out%d.pdf:\n\
         ./readpdf -x0 -s -i in.pdf out.pdf\n\
         To extract page#3 and onwards:\n\
         ./readpdf -x3 -s -i in.pdf out.pdf\n\
 \n"
	    );
}

int main(int argc, char **argv)
{
      int i = 1;
      char *in = NULL;
      char *out = NULL;
      char *devtype = NULL;
      pdf_doc *doc;
      char *passwd = NULL;
      int firstpage = 1;
      int lastpage = -1;
      int inflate = 0;
      unsigned char write_flag = 0;
      int separation = 0;
      int info = 0;
      FILE *outf = 0;
      pdf_err e;

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
			      case 's':
				    separation = 1;
				    break;
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
					  int n = strspn(argv[i+1], "0123456789");
					  if (n == strlen(argv[i+1]))
					  {
						i++;
						firstpage = atoi(argv[i]);
					  }
					  else
					  {
						firstpage = 1;
					  }
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
			      case 'd':
                              {
				    if (isspace(argv[i][2]) || argv[i][2] == 0)
                                    {
					  devtype = argv[2];
                                    }
			      }
			      break;
			      case 'I':
				    info = 1;
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
      if (!in && out)
      {
	    in = out;
	    out = 0;
      }
      if (!out)
	    printf("\n%s%s\n\n", "Dry run on ", in);
      //pdf_open(in, separation?NULL:out, &doc);
      e = pdf_open(in, &doc);
      if (!doc || e != pdf_ok)
	    goto done;
      if (info)
	    pdf_doc_print_info(doc);
      if (!passwd && pdf_doc_need_passwd(doc) && pdf_doc_authenticate_user_password(doc, "") != 0)
      {
	    printf("%s\n", "Need user password, use -p option");
	    goto done;
      }

      if (out && (inflate || devtype))
      {
#ifdef DEBUG
            printf("writing = %s\n", out);
#endif
            outf = fopen(out, "wb");
            if (!outf)
            {
                  fprintf(stderr, "Can not open %s.\n", out);
                  return pdf_io_err;
            }
      }

      if (!passwd || !pdf_doc_need_passwd(doc))
      {
	    pdf_doc_process_all(doc, devtype, outf, (unsigned char*)"");
      }
      else if (passwd && pdf_doc_need_passwd(doc))
      {
	    pdf_doc_process_all(doc, devtype, outf, (unsigned char*)passwd);
      }
      // writing out pdf using doc structure.
      if (out && (!devtype))
      {
	    if (inflate)
		  write_flag |= WRITE_PDF_CONTENT_INFLATE;
	    if (doc->trailer && doc->trailer->encrypt)
		  write_flag |= WRITE_PDF_CONTENT_INFLATE;
	    if (separation)
		  write_flag |= WRITE_PDF_PAGE_SEPARATION;
	    if (outf)
	    {
		  fclose(outf);
		  outf = 0;
	    }
	    pdf_write_pdf(doc, in, out, write_flag, 17, firstpage-1, lastpage-1, NULL, NULL);
      }
      if (!out)
      {
	    printf("Need to specify output file/directory!\n");
      }
  done:
      pdf_doc_done(doc);
      pdf_finish(doc);
      if (outf)
	    fclose(outf);
      return 0;
}
