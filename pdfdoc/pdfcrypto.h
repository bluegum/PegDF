#ifndef PDFCRYPTO_H
#define PDFCRYPTO_H

#include "pdf.h"

typedef struct pdfcrypto_priv_s pdfcrypto_priv;
typedef enum authevent_e authevent;

enum authevent_e
{
    eDocOpen,
    eEFOpen
};

struct pdfcrypto_priv_s
{
    pdfcrypto_algorithm algo;
    int rev;
    authevent event;
    int len;
    unsigned char key[32];
};

extern pdfcrypto_priv* pdf_crypto_create(pdfcrypto_algorithm algo, int rev, int len, char *passwd);
extern void pdf_crypto_destroy(pdfcrypto_priv *crypto);
extern void pdf_crypto_calc_userpassword(pdfcrypto_priv* c, unsigned char id1[16], char *pw, int pwlen, unsigned char *o);
extern pdf_filter* pdf_cryptofilter_new(pdfcrypto_priv *, int, int, unsigned char*);
extern void pdf_digest_md5(char *s, size_t len, unsigned char *digest);

#endif
