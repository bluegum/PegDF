#ifndef PDF_H
#define PDF_H
#ifdef __cplusplus
extern "C" {
#endif
#include "pdftypes.h"

typedef enum pdfcrypto_algorithm_e pdfcrypto_algorithm;

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
typedef struct pdf_writer_options_s pdf_writer_options;
typedef enum   pdf_compression_e pdf_compression;

extern pdfcrypto* pdf_crypto_load(pdf_doc *doc, char *pw);
extern int pdf_doc_page_count(pdf_doc *doc);
extern int pdf_doc_need_passwd(pdf_doc *doc);
extern pdf_err pdf_open(char *in,  pdf_doc **doc);
extern void pdf_doc_done(pdf_doc *d);
extern void pdf_crypto_destroy(pdfcrypto *crypto);
extern pdf_err pdf_finish(pdf_doc *doc);
extern pdf_err pdf_write_pdf(pdf_doc *doc, char *infile, char *ofile, pdf_writer_options *options);
extern pdf_err pdf_page_save(pdf_doc *doc, int i/* pg# */, pdfcrypto *crypto, char *outf, pdf_writer_options*);
extern int pdf_doc_authenticate_user_password(pdf_doc *doc, char *pw);
extern pdf_err pdf_doc_process_all(pdf_doc *doc, char *dev, FILE *outf, char *pw);

enum pdfcrypto_algorithm_e
{
    eNotBeUsed,
    eRC4,
    eAESV2,
    eAESV3,
    eUnpublished,
};

enum pdf_compression_e
{
    eNoCompression,
    eFlate,
    eLZW,
};

typedef struct num_range_s
{
    int bgn;
    int end;
} num_range;


struct pdf_writer_options_s
{
    int  version;
    long flags;
    long catalog_flags;
    num_range *page_ranges;
    int nr;
    pdf_compression compression;
    pdfcrypto_algorithm encrypt;
    char upass[32];
    char opass[32];
};

#ifdef __cplusplus
}
#endif

// Configurations
#define PARSER_STACK_MIN 8192

#endif
