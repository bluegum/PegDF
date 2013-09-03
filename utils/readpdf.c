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
#include <getopt.h>
#include "pdf.h"
#include "pdfdoc.h"
////////////////////////////////////////////////////
// example application
////////////////////////////////////////////////////

static int show_help;

static struct option const long_options[] =
{
    {"help", no_argument, &show_help, 1},
    {0, 0, 0, 0}
};

static void
usage(int status)
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
 -I : print catalog\n\
 --help : print this\n\
\n\
Example#1: to extract each and every page and write into a sequence of pdf files with inflated content stream,\n\
 and the output are with format as: out%d.pdf:\n\
 ./readpdf -x 0 -s -i in.pdf out.pdf\n\
 To inflate all page contents and write to a new pdf file:\n\
 ./readpdf -i in.pdf out.pdf\n\
 To extract from page#3 to lastpage write to a new pdf file:\n\
 ./readpdf -x 3 in.pdf out.pdf\n\
 \n"
          );
    exit (status);
}

int main(int argc, char **argv)
{
    int c, option_index;
    char in[1024];
    char out[1024];
    char passwd[1024];
    int firstpage = 1;
    int lastpage = -1;
    int inflate = 0;
    char write_flag = 0;
    int separation = 0;
    int info = 0;
    FILE *outf = 0;
    pdf_err e;
    pdf_doc *doc;

    if (argc <= 1)
        usage(EXIT_SUCCESS);

    in[0] = 0;
    out[0] = 0;
    passwd[0] = 0;

    while (1)
    {
        c = getopt_long(argc, argv, "Iisp:x:",
                        long_options, &option_index);
        if (c == -1)
            break;
        switch (c)
        {
            case 0:
                // long option
                break;
            case 's':
                separation = 1;
                break;
            case 'o':
                strncpy(out, optarg, 1023);
                break;
            case 'p':
                strncpy(passwd, optarg, 1023);
                break;
            case 'x':
                if (strlen(optarg) == strspn(optarg, "0123456789"))
                    firstpage = atoi(optarg);
                else
                    usage(EXIT_SUCCESS);
                break;
            case 'i':
                inflate = 1;
                break;
            case 'I':
                info = 1;
                break;
            default:
                usage(EXIT_SUCCESS);
                break;
        }
    }

    if (optind < argc)
    {
        strncpy(in, argv[optind], 1023);
        optind++;
    }
    else
    {
        usage(EXIT_SUCCESS);
        return EXIT_SUCCESS;
    }

    if (optind < argc)
    {
        strncpy(out, argv[optind], 1023);
    }

    if (!out[0])
	    printf("\n%s%s\n\n", "Dry run on ", in);
    //pdf_open(in, separation?NULL:out, &doc);
    e = pdf_open(in, &doc);
    if (!doc || e != pdf_ok)
	    goto done;
    if (info)
	    pdf_doc_print_info(doc);
    if (!passwd[0] && pdf_doc_need_passwd(doc) && pdf_doc_authenticate_user_password(doc, "") != 0)
    {
	    printf("%s\n", "Need user password, use -p option");
	    goto done;
    }

    if (out[0] && inflate)
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

    if (!passwd[0] || !pdf_doc_need_passwd(doc))
    {
	    e = pdf_doc_process_all(doc, 0, outf, "");
    }
    else if (passwd[0] && pdf_doc_need_passwd(doc))
    {
	    e = pdf_doc_process_all(doc, 0, outf, passwd);
    }
    // writing out pdf using doc structure.
    if (out[0])
    {
	    if (inflate)
            write_flag |= WRITE_PDF_CONTENT_INFLATE;
	    if (doc->encrypt)
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

  done:
    pdf_doc_done(doc);
    pdf_finish(doc);
    if (outf)
	    fclose(outf);
    if (e != pdf_ok)
        return -1;
    return 0;
}
