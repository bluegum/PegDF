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

#define WRITE_CATALOG_ANNONTATION      0x01
#define WRITE_CATALOG_STRUCTTREEROOT   0x02
#define WRITE_CATALOG_OUTLINES         0x04
#define WRITE_CATALOG_OCPROPERTIES     0x08
#define WRITE_CATALOG_METADATA         0x10
#define WRITE_CATALOG_NAMES            0x20
#define WRITE_CATALOG_MARKINFO         0x40
#define WRITE_CATALOG_PIECEINFO        0x80
#define WRITE_CATALOG_PAGELABELS       0x100

#define WRITE_CATALOG_DEFAULTS         (WRITE_CATALOG_METADATA | WRITE_CATALOG_OCPROPERTIES)

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

// Configurations
#define PARSER_STACK_MIN 8192

#endif
