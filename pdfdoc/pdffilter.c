#include "pdftypes.h"
#include "pdfmem.h"
#include "pdffilter.h"

pdf_error
pdf_flatedecode_new(pdf_filter **f)
{
  if (!f)
    return pdf_ok;
  *f = pdf_malloc(sizeof(pdf_filter));
  return pdf_ok;
}

pdf_error
pdf_flatedecode_delete(pdf_filter *f)
{
  if (!f)
    return pdf_ok;
  pdf_free(f);
  return pdf_ok;
}
