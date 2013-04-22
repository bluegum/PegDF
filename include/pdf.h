#ifndef PDF_H
#define PDF_H
#ifdef __cplusplus
extern "C" {
#endif
#include "pdftypes.h"

#define WRITE_PDF_LINEARIZED           0x01
#define WRITE_PDF_INCREMENT            0x02
#define WRITE_PDF_CONTENT_INFLATE      0x10
#define WRITE_PDF_DECIPHER             0x20
#define WRITE_PDF_PAGE_SEPARATION      0x40

typedef struct pdfcrypto_priv_s pdfcrypto;
typedef struct pdf_doc_s pdf_doc;

extern pdfcrypto* pdf_crypto_load(pdf_doc *doc, char *pw);
extern int pdf_doc_page_count(pdf_doc *doc);
extern int pdf_doc_need_passwd(pdf_doc *doc);
extern pdf_err pdf_open(char *in,  pdf_doc **doc);
extern void pdf_doc_done(pdf_doc *d);
extern void pdf_crypto_destroy(pdfcrypto *crypto);
extern pdf_err pdf_finish(pdf_doc *doc);
extern pdf_err pdf_page_write(pdf_doc *doc, int i/* pg# */, unsigned long write_flag, pdfcrypto *crypto, int version, char *outf);
extern int pdf_doc_authenticate_user_password(pdf_doc *doc, char *pw);
extern pdf_err pdf_doc_process_all(pdf_doc *doc, char *dev, FILE *outf, char *pw);

#ifdef __cplusplus
}
#endif

#endif
