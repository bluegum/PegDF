#ifndef PDFCMDS_H
#define PDFCMDS_H

extern pdf_err x_colorspace(pdf_page *p, pdf_obj o, int pen);
extern pdf_err x_d(pdf_page *p, pdf_obj o, float);
extern pdf_err x_f(pdf_page *p, int);
extern pdf_err x_g(pdf_page *p, float g, int pen);
extern pdf_err x_k(pdf_page *p, float a, float b, float c, float d, int pen);
extern pdf_err x_n(pdf_page *p);
extern pdf_err x_m(pdf_page *p, float x, float y);
extern pdf_err x_l(pdf_page *p, float x, float y);
extern pdf_err x_c(pdf_page *p, float a, float b, float c, float d, float e, float f);
extern pdf_err x_v(pdf_page *p, float a, float b, float c, float d);
extern pdf_err x_y(pdf_page *p, float a, float b, float c, float d);
extern pdf_err x_B(pdf_page *p);
extern pdf_err x_Bstar(pdf_page *p);
extern pdf_err x_BI(pdf_page *p, pdf_obj);
extern pdf_err x_BT(pdf_page *p);
extern pdf_err x_BX(pdf_page *p);
extern pdf_err x_BDC(pdf_page *p, pdf_obj, pdf_obj);
extern pdf_err x_BMC(pdf_page *p);
/// T group
extern pdf_err x_Tstar(pdf_page *p);
extern pdf_err x_Tc(pdf_page *p, float);
extern pdf_err x_Tf(pdf_page *p, pdf_obj, float scale);
extern pdf_err x_Tj(pdf_page *p, pdf_obj);
extern pdf_err x_TJ(pdf_page *p, pdf_obj);
extern pdf_err x_Tm(pdf_page *p, float a, float b, float c, float d, float e, float f);
extern pdf_err x_Td(pdf_page *p, float, float);
extern pdf_err x_TD(pdf_page *p, float a, float b);
extern pdf_err x_TL(pdf_page *p, float);
extern pdf_err x_Tr(pdf_page *p, int mode);
extern pdf_err x_Ts(pdf_page *p, float rise);
extern pdf_err x_Tw(pdf_page *p, float);
extern pdf_err x_Tz(pdf_page *p, float);
/// E group
extern pdf_err x_ET(pdf_page *p);
extern pdf_err x_EX(pdf_page *p);
extern pdf_err x_EMC(pdf_page *p);
extern pdf_err x_re(pdf_page *p, float a, float b, float c, float d);
extern pdf_err x_rg(pdf_page *p, float a, float b, float c, int);
extern pdf_err x_cm(pdf_page *p, float a, float b, float c, float d, float e, float f);
extern pdf_err x_gs(pdf_page *p, pdf_obj);
extern pdf_err x_ri(pdf_page *p, pdf_obj o);
extern pdf_err x_sh(pdf_page *p, pdf_obj o);
extern pdf_err x_i(pdf_page *p, float flatness);
extern pdf_err x_w(pdf_page *p, float linewidth);
extern pdf_err x_j(pdf_page *p, int linejoin);
extern pdf_err x_J(pdf_page *p, int linecap);
extern pdf_err x_M(pdf_page *p, float miterlimit);
///
extern pdf_err x_Do(pdf_page *p, pdf_obj);
extern pdf_err x_popgs(pdf_page *p);
extern pdf_err x_pushgs(pdf_page *p);
///
extern pdf_err x_h(pdf_page *p);
extern pdf_err x_s(pdf_page *p);
extern pdf_err x_S(pdf_page *p);

#endif
