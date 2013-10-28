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

// permissions
// bit32
#define PERMISSION_RESERVED (0xfffff000)
// bit#3
#define PERMISSION_PRINT (1<<2)
// bit#4
#define PERMISSION_MODIFY (1<<3)
// bit#5
#define PERMISSION_COPY (1<<4)
// bit#6
#define PERMISSION_ANNOT (1<<5)
// bit#9
#define PERMISSION_FORM (1<<8)
// bit#10
#define PERMISSION_EXTRACT (1<<9)
// bit#11
#define PERMISSION_ASSEMBLE (1<<10)
// bit#12
#define PERMISSION_PRINT_HIGH (1<<11)
// all permitted
#define PERMISSION_ALL (PERMISSION_RESERVED | PERMISSION_PRINT | \
PERMISSION_MODIFY | \
PERMISSION_COPY | \
PERMISSION_ANNOT | \
PERMISSION_FORM | \
PERMISSION_EXTRACT | \
PERMISSION_ASSEMBLE | PERMISSION_PRINT_HIGH)



extern pdfcrypto_priv* pdf_crypto_create(pdfcrypto_algorithm algo, int rev, int len, char *passwd, int passwdlen, char *id, char o[32], char u[32]);
extern void pdf_crypto_destroy(pdfcrypto_priv *crypto);
extern void pdf_compute_user_password(pdfcrypto_priv* c, unsigned char id1[16], unsigned char *o);
extern pdf_filter* pdf_cryptofilter_new(pdfcrypto_priv *, int, int, unsigned char*);
extern void pdf_digest_md5(char *s, size_t len, unsigned char *digest);
extern pdfcrypto_algorithm which_algo(pdfcrypto_priv *c);
extern int which_revision(pdfcrypto_priv *c);
extern pdfcrypto_priv *pdfcrypto_new(pdfcrypto_algorithm, authevent, int len);
extern void *pdf_rc4_new(int len, char *key);
extern void *pdf_aes_new(int len, char *key, char *iv);
extern void* pdf_rc4_e_new(char *final_key, int key_len);
extern void* pdf_aes_e_new(char *final_key, int key_len, unsigned char *iv);
extern int pdf_arc4_read(void *ctx, unsigned char *in, unsigned char *obuf, int request);
extern pdf_err pdf_arc4_close(void *s, int flag);
extern int pdf_aes_write(void *ctx, char *in, char *out, int req);






#endif
