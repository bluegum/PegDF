#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "evp.h"
#include "pdftypes.h"
#include "pdffilter.h"
#include "pdfdoc.h"
#include "pdfcrypto.h"

struct pdfcrypto_priv_s
{
    pdfcrypto_algorithm algo;
    int rev;
    authevent event;
    int len;
    unsigned char key[32];
};

static unsigned char pdf_key_padding[32] =
{
    0x28,0xBF,0x4E,0x5E,0x4E,0x75,0x8A,0x41,0x64,0x00,0x4E,0x56,0xFF,0xFA,0x01,0x08,
    0x2E,0x2E,0x00,0xB6,0xD0,0x68,0x3E,0x80,0x2F,0x0C,0xA9,0xFE,0x64,0x53,0x69,0x7A
};

pdfcrypto_priv *
pdfcrypto_new(pdfcrypto_algorithm algo, authevent e, int len)
{
    pdfcrypto_priv *cf;
    cf = pdf_malloc(sizeof(pdfcrypto_priv));
    if (!cf)
        return 0;
    memset(cf, 0, sizeof(pdfcrypto_priv));
    cf->algo = algo;
    cf->event = e;
    cf->len = len;
    return cf;
}

pdfcrypto_algorithm
which_algo(pdfcrypto_priv *c)
{
    return c->algo;
}
int which_revision(pdfcrypto_priv *c)
{
    return c->rev;
}

int
crypto_key_len(pdfcrypto_priv *crypto)
{
    return crypto->len;
}

/*
 * input:
 * r - revision
 * n - key length
 */
void
pdf_compute_key(int r, unsigned int n, char *password, int pwlen, unsigned char O[32], unsigned long P, unsigned char ID1[16], unsigned char *encrypt_metadata, unsigned char *key)
{
    int i;
    unsigned char pw[32];
    unsigned char buf[4];
    unsigned char digest[16];
    unsigned int digest_len;

    EVP_MD_CTX ctx;
    const EVP_MD *md = EVP_md5();

    /* Step 0 - init md5 */
    EVP_MD_CTX_init (&ctx);
    EVP_DigestInit(&ctx, md);

    /* Step 1 - copy and pad password string */
    if (pwlen)
        memcpy(pw, password, pwlen);
    for (i = pwlen; i < 32; i++)
    {
        pw[i] = pdf_key_padding[i-pwlen];
    }
    /* Step 2 - pass value of step 1 */
    EVP_DigestUpdate(&ctx, pw, 32);
    /* Step 3 - pass O(owner password) value */
    EVP_DigestUpdate(&ctx, O, 32);
    /* Step 4 - pass P value as unsigned int, low-order byte first */
    buf[0] = (P) & 0xFF;
    buf[1] = (P >> 8) & 0xFF;
    buf[2] = (P >> 16) & 0xFF;
    buf[3] = (P >> 24) & 0xFF;
    EVP_DigestUpdate(&ctx, buf, 4);
    /* Step 5 - pass first element of ID array */
    EVP_DigestUpdate(&ctx, ID1, 16);
    /* Step 6 (revision 4 or greater) - if metadata is not encrypted pass 0xFFFFFFFF */
    if (r >= 4)
    {
        if (0)//!encrypt_metadata)
        {
            buf[0] = 0xFF;
            buf[1] = 0xFF;
            buf[2] = 0xFF;
            buf[3] = 0xFF;
            EVP_DigestUpdate(&ctx, buf, 4);
        }
    }

    /* Step 7 - finish the hash */
    EVP_DigestFinal(&ctx, digest, &digest_len);

    /* Step 8 (revision 3 or greater) - do some voodoo 50 times */
    if (r >= 3)
    {
        for (i = 0; i < 50; i++)
        {
            EVP_DigestInit(&ctx, md);
            EVP_DigestUpdate(&ctx, digest, n);
            EVP_DigestFinal(&ctx, digest, &n);
        }
    }

    /* Step 9 - the key is the first 'n' bytes of the result */
    memcpy(key, digest, n);
    /* All done */
    EVP_MD_CTX_cleanup (& ctx);
    for (i = 0; i < 16; i ++) /* can't trust libc's memset */
        digest[i] = 0;
    for (i = 0; i < 32; i ++) /* can't trust libc's memset */
        pw[i] = 0;
    #ifdef DEBUG
    printf("key=%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X\n",
           key[0], key[1], key[2], key[3], key[4], key[5], key[6], key[7],
           key[8], key[9], key[10], key[11], key[12], key[13], key[14], key[15]);
    #endif
}

pdfcrypto_priv *
pdf_crypto_init(pdf_encrypt* encrypt, unsigned char id1[16], char *pw)
{
    pdfcrypto_priv *crypto;
    int pwlen = 0;
    if (pw)
	    pwlen = strlen(pw);
    crypto = pdf_malloc(sizeof(pdfcrypto_priv));
    if (!crypto)
        return NULL;
    if (encrypt->v == 4)
    {
        memcpy(crypto, encrypt->stmf, (sizeof(pdfcrypto_priv)));
    }
    crypto->rev = encrypt->r;
    if (encrypt->v == 4)
    {
        crypto->len = encrypt->length;
    }
    else if (encrypt->v == 1)
    {
        crypto->algo = eRC4;
        crypto->len = 40;
    }
    else if (encrypt->v == 2)
    {
        crypto->algo = eRC4;
        crypto->len = 128;
    }
    else
    {
        return NULL;
    }

    pdf_compute_key(crypto->rev,
                    crypto->len/8,
                    pw, // password
                    pwlen,  // password len,
                    encrypt->o,
                    encrypt->p,
                    id1,
                    NULL, //encrypt_metadata,
                    crypto->key);

    return crypto;
}

void
pdf_crypto_destroy(pdfcrypto_priv *crypto)
{
    if (crypto)
    {
        memset(crypto, 0, sizeof(pdfcrypto_priv));
        pdf_free(crypto);
    }
}

void
pdf_crypto_encrypt_arc4(pdfcrypto_algorithm algo, int len, unsigned char *key, unsigned char *str, unsigned char *outbuf, int *outlen)
{
    EVP_CIPHER_CTX ctx;
    const EVP_CIPHER *rc4;
    int tmplen;

    if (algo == eRC4 && len == 40)
    {
	    rc4 = EVP_rc4_40();
    }
    else
    {
	    rc4 = EVP_rc4();
    }
    EVP_CIPHER_CTX_init (&ctx);

    EVP_EncryptInit(&ctx, rc4, key, NULL); // NULL for rc4 iv

    if(!EVP_EncryptUpdate(&ctx, outbuf, outlen, str, 32))
    {
        /* Error */
        return;
    }
    /* Buffer passed to EVP_EncryptFinal() must be after data just
     * encrypted to avoid overwriting it.
     */
    if(!EVP_EncryptFinal(&ctx, outbuf + *outlen, &tmplen))
    {
        /* Error */
        return;
    }

    EVP_CIPHER_CTX_cleanup(&ctx);
}

void
pdf_compute_user_password(pdfcrypto_priv* c, unsigned char id1[16], unsigned char *o)
{
    int len;

    assert (c);

#ifdef DEBUG
    printf("ID=%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X\n",
           id1[0], id1[1], id1[2], id1[3], id1[4], id1[5], id1[6], id1[7],
           id1[8], id1[9], id1[10], id1[11], id1[12], id1[13], id1[14], id1[15]);
#endif
    if (c->rev == 2)
    {
        pdf_crypto_encrypt_arc4(c->algo, c->len, c->key, pdf_key_padding, o, &len);
    }
    else if (c->rev == 3 || c->rev == 4)
    {
        EVP_MD_CTX ctx;
        const EVP_MD *md = EVP_md5();
        int n = c->len/8;
        unsigned char digest[16], out[32], xor[16];
        int x, olen;
        unsigned int digest_len;
        /* Step 0 - init md5 */
        EVP_MD_CTX_init (&ctx);
        EVP_DigestInit(&ctx, md);
        EVP_DigestUpdate(&ctx, pdf_key_padding, 32);
        EVP_DigestUpdate(&ctx, id1, 16);
        EVP_DigestFinal(&ctx, digest, &digest_len);
        EVP_MD_CTX_cleanup (&ctx);
        /* step 1 - rc4 digest*/
        pdf_crypto_encrypt_arc4(c->algo, c->len, c->key, digest, out, &olen);
        /* step 2 - rc4 19 times */
        for (x = 1; x <= 19; x++)
        {
            int i;
            for (i = 0; i < n; i++)
                xor[i] = c->key[i] ^ x;
            pdf_crypto_encrypt_arc4(c->algo, c->len, xor, out, o, &olen);
            memcpy(out, o, 16);
#ifdef DEBUG
            printf("u%d=%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X\n", x,
           o[0], o[1], o[2], o[3], o[4], o[5], o[6], o[7],
           o[8], o[9], o[10], o[11], o[12], o[13], o[14], o[15]);
#endif
        }
        memcpy(o + 16, pdf_key_padding, 16);
    }
    else if (c->rev == 5)
    {
    }
#ifdef DEBUG
    printf("U=%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X\n",
           o[0], o[1], o[2], o[3], o[4], o[5], o[6], o[7],
           o[8], o[9], o[10], o[11], o[12], o[13], o[14], o[15]);
#endif
    return;
}

// pdf arc4 cipher

pdf_err
pdf_rc4_close(void *s, int flag)
{
    EVP_CIPHER_CTX *ctx = (EVP_CIPHER_CTX *)s;
    EVP_CIPHER_CTX_cleanup(ctx);
    pdf_free(ctx);
    return pdf_ok;
}


int
pdf_rc4_read(void *ctx, unsigned char *in, unsigned char *obuf, int request)
{
    int tmplen;

    if (request == 0)
    {
        if (!EVP_DecryptFinal(ctx, obuf, &tmplen))
            return 0;
        else
            return tmplen;
    }
    if(!EVP_DecryptUpdate(ctx, obuf, &request, in, request))
    {
        /* Error */
        return 0;
    }
    else
    {
        return request;
    }
    return 0;
}

// pdf AES cipher
struct aes_priv_s
{
    unsigned char *p, *e;
    // TODO: buffer overflow over buffer sise 16.
    unsigned char buf[32];
};

void*
pdf_aes_priv_new()
{
    struct aes_priv_s *buf;
    buf = (struct aes_priv_s *)pdf_malloc(sizeof(struct aes_priv_s));
    if (buf)
    {
        buf->p = buf->buf+16;
        buf->e = buf->buf+16;
    }
    return (void*)buf;
}

pdf_err
pdf_aes_close(EVP_CIPHER_CTX *ctx)
{
    if (ctx)
    {
        EVP_CIPHER_CTX_cleanup(ctx);
        pdf_free(ctx);
    }
    return pdf_ok;
}

void*
pdf_aes_e_new(char *final_key, int key_len, unsigned char *iv)
{
    EVP_CIPHER_CTX *ctx; // cipher state
    const EVP_CIPHER *aes128 = EVP_aes_128_cbc();
    const EVP_CIPHER *aes256 = EVP_aes_256_cbc();

    ctx = pdf_malloc(sizeof(EVP_CIPHER_CTX));

    if (ctx)
    {
        EVP_CIPHER_CTX_init (ctx);
        if (key_len == 128)
            EVP_EncryptInit(ctx, aes128, final_key, iv);
        else
            EVP_EncryptInit(ctx, aes256, final_key, iv);
    }

    return (void*)ctx;
}


void
pdf_crypto_obj_key_compute(pdfcrypto_priv *crypto, int num, int gen, char *final_key, int keylen)
{
    int n = keylen;
    unsigned char key[256];
    EVP_MD_CTX ctx;
    const EVP_MD *md = EVP_md5();

    memcpy(key, crypto->key, n);
    // Pad with obj-num and gen-num
    key[n] = (num) & 0xff;
    key[n+1] = (num >> 8) & 0xff;
    key[n+2] = (num >> 16) & 0xff;
    key[n+3] = (gen) & 0xff;
    key[n+4] = (gen >> 8) & 0xff;
    // md5 to get key
    n += 5;
    EVP_DigestInit(&ctx, md);
    EVP_DigestUpdate(&ctx, key, n);

    if (crypto->algo == eAESV2)
        EVP_DigestUpdate(&ctx, (unsigned char *)"sAlT", 4);
    EVP_DigestFinal(&ctx, final_key, &keylen);
    EVP_MD_CTX_cleanup (&ctx);

}

///////////////////////////////////////////////////////////////////
// cipher filter api(s)




pdfcrypto_priv* pdf_crypto_load(pdf_doc *doc, char *pw)
{
    pdfcrypto_priv* crypto = 0;
    if (doc->trailer->encrypt)
    {
	    crypto = pdf_crypto_init(doc->trailer->encrypt,
                                 doc->trailer->id[0],
                                 pw);
    }
    return crypto;
}


static pdfcrypto_priv*
pdf_crypto_rc4_create(int len, char *passwd)
{
    return 0;
}

static pdfcrypto_priv*
pdf_crypto_aes_create(int len, char *passwd)
{
    return 0;
}

static void
pdf_compute_owner_password(pdfcrypto_priv *crypto, char *pwo, int pwolen, char *pwu, int pwulen, char *o)
{
    int  i;
    char pw[32];
    char key[16];
    EVP_MD_CTX    dctx;
    const EVP_MD *md;

    if (!o)
        return;
    /* Step 0 - init md5 */
    md = EVP_md5();
    EVP_MD_CTX_init (&dctx);
    EVP_DigestInit(&dctx, md);

    if (!pwo)
        memcpy(pw, pwu, pwulen);
    else
        memcpy(pw, pwo, pwolen);

    // pad or truncate password
    if (pwolen)
        memcpy(pw, pwo, pwolen);
    for (i = pwolen; i < 32; i++)
    {
        pw[i] = pdf_key_padding[i-pwolen];
    }
    /* Step 2 - pass value of step 1 */
    EVP_DigestUpdate(&dctx, pw, 32);

    // c) d) md5 50 more times, for revision >= 4
    for (i = 0; i < 50; i++)
        EVP_DigestUpdate(&dctx, pw, 16);

    memcpy(key, pw, 16);

    // e)
    if (pwulen)
        memcpy(pw, pwu, pwulen);
    for (i = pwolen; i < 32; i++)
    {
        pw[i] = pdf_key_padding[i-pwulen];
    }

    // f)
    {
        char buf[32];
        int outlen, tmplen;
        EVP_CIPHER_CTX ctx;
        const EVP_CIPHER *rc4;


        EVP_CIPHER_CTX_init (&ctx);
	    rc4 = EVP_rc4();
        EVP_EncryptInit(&ctx, rc4, key, NULL); // NULL for rc4 iv
        EVP_CIPHER_CTX_set_key_length(&ctx, 16);
//	    EVP_CipherInit_ex(&ctx, rc4, NULL, NULL, NULL, 0);

        if(!EVP_EncryptUpdate(&ctx, buf, &outlen, pw, 32))
        {
            /* Error */
            return;
        }
        /* Buffer passed to EVP_EncryptFinal() must be after data just
         * encrypted to avoid overwriting it.
         */
        if(!EVP_EncryptFinal(&ctx, buf + outlen, &tmplen))
        {
            /* Error */
            return;
        }

        EVP_CIPHER_CTX_cleanup(&ctx);

        // g)
        outlen = 0;
        for (i = 0; i < 19; i++)
        {
            unsigned char _key[16], _buf[32];
            int j;

            for (j = 0; j < 16; j++)
                _key[j] = key[j] ^ i;
#if 1
            pdf_crypto_encrypt_arc4(eRC4, 128, _key, buf, _buf, &outlen);
#else
            EVP_CIPHER_CTX_init (&ctx);
            EVP_EncryptInit(&ctx, rc4, _key, NULL); // NULL for rc4 iv

            if(!EVP_EncryptUpdate(&ctx, _buf, &outlen, buf, 32))
            {
                /* Error */
                return;
            }

            if(!EVP_EncryptFinal(&ctx, _buf + outlen, &tmplen))
            {
                /* Error */
                return;
            }

            EVP_CIPHER_CTX_cleanup(&ctx);
#endif
            memcpy(buf, _buf, 32);
        }

        // h) done
        memcpy(o, buf, 32);
    }

    // clean up
    EVP_MD_CTX_cleanup (&dctx);

}


pdfcrypto_priv*
pdf_crypto_create(pdfcrypto_algorithm algo, int rev, int len, char *pw, int pwlen, char *id, char o[32], char u[32])
{
    pdfcrypto_priv *crypto;
    long _p_; // for permissions

    _p_ = PERMISSION_ALL; //??



    crypto = pdf_malloc(sizeof(pdfcrypto_priv));
    if (!crypto)
        return NULL;
    crypto->rev = rev;
    crypto->len = len * 8;

    pdf_compute_owner_password(crypto, pw, pwlen, pw, pwlen, o);

    pdf_compute_key(rev,
                    len,
                    pw, // password
                    pwlen,  // password len,
                    o,
                    _p_,
                    id,
                    NULL, //encrypt_metadata,
                    crypto->key);

    pdf_compute_user_password(crypto, id, u);

    crypto->algo = algo;
    if (algo == eRC4)
    {
        pdf_crypto_rc4_create(len, pw);
    }
    else if (algo == eAESV2)
    {
        pdf_crypto_aes_create(len, pw);
    }
    else
    {
        pdf_free(crypto);
        return 0;
    }
    return crypto;
}


void
pdf_digest_md5(char *s, size_t len, unsigned char *digest)
{
    int n;
    EVP_MD_CTX ctx;
    const EVP_MD *md = EVP_md5();

    /* Step 0 - init md5 */
    EVP_MD_CTX_init (&ctx);
    EVP_DigestInit(&ctx, md);

    EVP_DigestUpdate(&ctx, s, len);
    EVP_DigestFinal(&ctx, digest, &n);

    assert(n==16);

    EVP_MD_CTX_cleanup (&ctx);

}

// return number of bytes read
int
pdf_aes_final_read(EVP_CIPHER_CTX *ctx, char *out, int len)
{
    int tmplen;

    if (!EVP_DecryptFinal(ctx, out, &tmplen))
    {
        return 0;
    }
    else
    {
        return tmplen;
    }
    return 0;
}

// return number of bytes read
int
pdf_aes_read(EVP_CIPHER_CTX *ctx, char *in, char *out, int req)
{
    int tmplen;
    int e;

    if (req == 0)
    {
        return pdf_aes_final_read(ctx, out, req);
    }
    else
    {
	    e = EVP_DecryptUpdate(ctx, out, &tmplen, in, req);
        if (!e)
        {
            /* Error */
            return 0;
        }
        return tmplen;
    }

    return 0;
}

int
pdf_aes_flush(void *_ctx, char *out)
{
    int tmplen;
    EVP_CIPHER_CTX *ctx = (EVP_CIPHER_CTX*)_ctx;

    if(!EVP_EncryptFinal(ctx, out, &tmplen))
    {
        /* Error */
        return 0;
    }
    return tmplen;
}

// return number of bytes written
int
pdf_aes_write(void *_ctx, char *in, char *out, int req)
{
    int tmplen = 0;
    EVP_CIPHER_CTX *ctx = (EVP_CIPHER_CTX*)_ctx;

    if (req)
    {
        if (!EVP_EncryptUpdate(ctx, out, &tmplen, in, req))
        {
            /* Error */
            return 0;
        }
    }
    return tmplen;
}

void *
pdf_aes_new(int len, char *key, char *iv)
{
    EVP_CIPHER_CTX *ctx; // cipher state
    const EVP_CIPHER *aes128 = EVP_aes_128_cbc();
    const EVP_CIPHER *aes256 = EVP_aes_256_cbc();

    ctx = pdf_malloc(sizeof(EVP_CIPHER_CTX));
    if (ctx)
    {
        EVP_CIPHER_CTX_init (ctx);
        if (len == 128)
            EVP_DecryptInit(ctx, aes128, key, iv);
        else
            EVP_DecryptInit(ctx, aes256, key, iv);
        if (0)
        {
            char tmp[16];
            int  tmplen, e;
            e = EVP_DecryptUpdate(ctx, tmp, &tmplen, iv, 16);
        }
    }
    return ctx;
}

void *
pdf_rc4_new(int len, char *key)
{
    EVP_CIPHER_CTX *ctx; // cipher state
    const EVP_CIPHER *rc4 = EVP_rc4();

    ctx = pdf_malloc(sizeof(EVP_CIPHER_CTX));
    if (ctx)
    {
        EVP_CIPHER_CTX_init (ctx);
-	    EVP_CipherInit_ex(ctx, rc4, NULL, NULL, NULL, 0);
        if (len == 40)
            EVP_CIPHER_CTX_set_key_length(ctx, 10);
        else
            EVP_CIPHER_CTX_set_key_length(ctx, 16);
	    /* We finished modifying parameters so now we can set key and IV */
	    EVP_CipherInit_ex(ctx, NULL, NULL, key, NULL, 0);
    }
    return ctx;
}


int
pdf_rc4_flush(void *_ctx, char *out)
{
    int tmplen;
    EVP_CIPHER_CTX *ctx = (EVP_CIPHER_CTX*)_ctx;

    if(!EVP_EncryptFinal(ctx, out, &tmplen))
    {
        /* Error */
        return 0;
    }
    return tmplen;
}


// return number of bytes written
int
pdf_rc4_write(void *_ctx, char *in, char *out, int req)
{
    int tmplen = 0;
    EVP_CIPHER_CTX *ctx = (EVP_CIPHER_CTX*)_ctx;

    if (req)
    {
        if (!EVP_EncryptUpdate(ctx, out, &tmplen, in, req))
        {
            /* Error */
            return 0;
        }
    }
    return tmplen;
}

