#ifndef PDFCRYPTO_H
#define PDFCRYPTO_H

typedef enum pdfcrypto_algorithm_e pdfcrypto_algorithm;
typedef struct pdfcrypto_priv_s pdfcrypto_priv;

enum pdfcrypto_algorithm_e
  {
    eNotBeUsed,
    e40bits,
    e40plusbits,
    eUnpublished,
    eCryptoFilter
  };

struct pdfcrypto_priv_s
{
  pdfcrypto_algorithm algo;
  int rev;
  int len;
  unsigned char key[32];
};

extern void pdf_crypto_destroy(pdfcrypto_priv *crypto);
extern pdfcrypto_priv *pdf_crypto_init(pdf_encrypt* encrypt, unsigned char id1[16], char *pw, int pwlen);
extern void pdf_crypto_calc_userpassword(pdfcrypto_priv* c, unsigned char id1[16], char *pw, int pwlen, unsigned char *o);

#endif
