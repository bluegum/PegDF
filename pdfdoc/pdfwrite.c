#include <stdio.h>
#include "pdffilter.h"
#include "pdfdoc.h"

typedef
struct pdf_xref_internal_s
{
      int n;
      struct
      {
	    int num;
	    int gen;
	    int used;
      } *entry;
} pdf_xref_internal;

static
void
pdf_write_xref(pdf_doc *doc, FILE *of)
{
}

pdf_err
pdf_write_pdf(pdf_doc *doc, char *ofile, int version, int pg1st, int pglast, char *upw, char *opw)
{
      FILE* out;
      char linebuf[1024];
      if (!ofile)
	    return pdf_ok;
      out = fopen(ofile, "wb");
      if (!out)
	    return pdf_ok;
      sprintf(linebuf, "%%%%PDF-%d.%d\n", version/10, version%10);
      fputs(linebuf, out);
      fputs("%%\333\332\331\330\n", out);

      // write xref table
      pdf_write_xref(doc, out);
      // done
      fclose(out);
      return pdf_ok;
}
