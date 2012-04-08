#ifndef PDFCMDS_H
#define PDFCMDS_H

extern pdf_err x_n(pdf_page *p);
extern pdf_err x_m(pdf_page *p, float x, float y);
extern pdf_err x_l(pdf_page *p, float x, float y);
extern pdf_err x_c(pdf_page *p, float a, float b, float c, float d);
extern pdf_err x_B(pdf_page *p);
extern pdf_err x_Bstar(pdf_page *p);
extern pdf_err x_BI(pdf_page *p);
extern pdf_err x_BT(pdf_page *p);
extern pdf_err x_BX(pdf_page *p);
extern pdf_err x_BDC(pdf_page *p);
extern pdf_err x_BMC(pdf_page *p);
/// T group
extern pdf_err x_Tf(pdf_page *p);
extern pdf_err x_Tj(pdf_page *p);
extern pdf_err x_TJ(pdf_page *p);
extern pdf_err x_Tm(pdf_page *p);
extern pdf_err x_Td(pdf_page *p);
extern pdf_err x_TL(pdf_page *p);
/// E group
extern pdf_err x_ET(pdf_page *p);
extern pdf_err x_EX(pdf_page *p);
extern pdf_err x_EMC(pdf_page *p);
extern pdf_err x_re(pdf_page *p);
extern pdf_err x_rg(pdf_page *p);
extern pdf_err x_cm(pdf_page *p);
extern pdf_err x_gs(pdf_page *p);

#endif
