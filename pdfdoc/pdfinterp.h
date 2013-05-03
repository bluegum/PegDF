#ifndef PDFINTERP_H
#define PDFINTERP_H
#include "pdfdevice.h"
#include "pdfcrypto.h"
#include "pdffont.h"

typedef struct pdf_interp_state_s pdf_interp_state;
// interpreter state
struct pdf_interp_state_s
{
    pdf_device *dev;
    pdfcrypto_priv *crypto;
    // font cache in linked list
    pdf_font *font, *cur_font;
    //
    byte path_stk[1024*1024];
};

extern pdf_interp_state *pdf_interpreter_new(pdf_device*, pdfcrypto_priv* encrypt);
extern void pdf_interpreter_free(pdf_interp_state *i);
extern void pdf_interpreter_font_insert(pdf_interp_state *, pdf_font *f);
#endif
