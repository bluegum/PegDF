#ifndef PDFFILTER_H
#define PDFFILTER_H
#include <stdio.h>
#include "pdftypes.h"

typedef enum pdf_filterkind_e pdf_filterkind;
typedef struct pdf_filter_s pdf_filter;
typedef struct decode_params_s decode_params;

struct decode_params_s
{
    int predictor;
    int colors;
    int bitspercomponent;
    int columns;
    int earlychange;
};

enum pdf_filterkind_e
{
    ASCIIHexDecode,
    ASCII85Decode,
    LZWDecode,
    FlateDecode,
    RunLengthDecode,
    CCITTFaxDecode,
    JBIG2Decode,
    DCTDecode,
    JPXDecode,
    Crypt,
    FlateEncode,
    RC4Encrypt,
    AESEncrypt,
    Raw,
    Standard,
    Limit,
};
#define PDF_FILTER_BUF_SIZE 1024
struct pdf_filter_s
{
    ///
    int eof;
    void *state;
    pdf_filter *next;
    ///
    pdf_err (*close)(pdf_filter*, int flag);
    int (*read)(pdf_filter*, unsigned char *, int);
    int (*write)(pdf_filter*, unsigned char *, int, int *);
    pdf_err (*flush)(pdf_filter*, unsigned char *, int*);
    ///
    unsigned char buf[PDF_FILTER_BUF_SIZE]; // holds input buffer for upstream output
    unsigned char *ptr, *end; // end is at one byte beyond input buffer
    // private
    void *data;
};

#define PDF_FILTER_CLOSE(f, flag)                                       \
    while (f) { pdf_filter *t = (f)->next; (*(f)->close)(f, (flag)); (f) = t; }
extern pdf_err pdf_flated_new(pdf_filter **f);
extern pdf_filter* pdf_filter_new(pdf_filterkind t, pdf_filter *last);
extern int pdf_filter_read(pdf_filter *f, unsigned char *buf, int len);
extern pdf_err pdf_deflate_new(pdf_filter **f);
extern pdf_filterkind pdf_filter_find(char *k);
extern void pdf_filter_str_to_enum(pdf_obj *o, pdf_filterkind* filter_array);
extern const char* pdf_filter_to_string(pdf_filterkind k);
extern pdf_err pdf_filter_rc4_e_new(pdf_filter **f, int n, int g, void *priv);
extern pdf_err pdf_filter_aes_e_new(pdf_filter **f, int n, int g, void *priv);
extern pdf_filter* pdf_rawfilter_new(sub_stream *ss);
extern pdf_filter* pdf_filter_predictor_new(decode_params *params, pdf_filter* last);

#endif
