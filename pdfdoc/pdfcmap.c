#include "pdftypes.h"
#include "pdffilter.h"
#include "pdfdoc.h"
#include "pdfcmap.h"

typedef enum pdf_cmap_token_type_e pdf_cmap_token_type;
enum pdf_cmap_token_type_e
{
      eCOMMENT,
      eKEYWORD,
      eNUM,
      eHEX,
      eARRAY,
      eNONE
};

pdf_cmap_token_type
pdf_cmap_lex(pdf_stream *s)
{
      return eNONE;
}

void
pdf_cmap_bfchar_parse(pdf_stream *s)
{
}

void
pdf_cmap_bfrange_parse(pdf_stream *s)
{
}

void
pdf_cmap_tounicode_parse(pdf_obj *cmap, pdf_font *f)
{
}
