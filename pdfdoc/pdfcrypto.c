#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "evp.h"
#include "pdftypes.h"
#include "pdffilter.h"
#include "pdfdoc.h"
#include "pdfcrypto.h"

static unsigned char pdf_key_padding[32] =
{
      0x28,0xBF,0x4E,0x5E,0x4E,0x75,0x8A,0x41,0x64,0x00,0x4E,0x56,0xFF,0xFA,0x01,0x08,
      0x2E,0x2E,0x00,0xB6,0xD0,0x68,0x3E,0x80,0x2F,0x0C,0xA9,0xFE,0x64,0x53,0x69,0x7A
};

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
}

pdfcrypto_priv *
pdf_crypto_init(pdf_encrypt* encrypt, unsigned char id1[16], char *pw)
{
      pdfcrypto_priv *crypto = pdf_malloc(sizeof(pdfcrypto_priv));
      int pwlen = 0;
      if (pw)
	    pwlen = strlen(pw);
      if (!crypto)
            return NULL;
      crypto->rev = encrypt->r;
      crypto->len = encrypt->length;
      if (encrypt->v == 4)
      {
            if (!encrypt->cf) return NULL;
            if (encrypt->cf->cfm == eCryptRC4)
            {
                  crypto->algo = e40plusbitsRC4;
            }
            else if (encrypt->cf->cfm == eCryptAES)
            {
                  crypto->algo = e40plusbitsAES;
            }
      }
      else if (encrypt->v == 1)
      {
            crypto->algo = e40bitsRC4;
      }
      else if (encrypt->v == 2)
      {
            crypto->algo = e40plusbitsRC4;
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
pdf_crypto_encrypt_arc4(pdfcrypto_algorithm algo, unsigned char *key, unsigned char *str, unsigned char *outbuf, int *outlen)
{
      EVP_CIPHER_CTX ctx;
      const EVP_CIPHER *rc4;
      int tmplen;

      if (algo == e40bitsRC4)
      {
	    rc4 = EVP_rc4_40();
      }
      else
      {
	    rc4 = EVP_rc4();
      }
      EVP_CIPHER_CTX_init (&ctx);

      EVP_EncryptInit(&ctx, rc4, key, NULL); // NULL for rc4 iv
#if 0
      if (algo == e40bitsRC4)
	    EVP_CIPHER_CTX_set_key_length(&ctx, 5);
      else
	    EVP_CIPHER_CTX_set_key_length(&ctx, 16);
#endif
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
pdf_crypto_calc_userpassword(pdfcrypto_priv* c, unsigned char id1[16], char *pw, int pwlen, unsigned char *o)
{
      int len;

      assert (c);

      if (c->rev == 2)
      {
	    pdf_crypto_encrypt_arc4(c->algo, c->key, pdf_key_padding, o, &len);
      }
      else if (c->rev == 3 || c->rev == 4)
      {
            EVP_MD_CTX ctx;
            const EVP_MD *md = EVP_md5();
            int n = c->len/8;
            unsigned char digest[16], out[16], xor[16];
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
            pdf_crypto_encrypt_arc4(c->algo, c->key, digest, out, &olen);
            /* step 2 - rc4 19 times */
            for (x = 1; x <= 19; x++)
            {
                  int i;
                  for (i = 0; i < n; i++)
                        xor[i] = c->key[i] ^ x;
                  pdf_crypto_encrypt_arc4(c->algo, xor, out, o, &olen);
                  memcpy(out, o, 16);
            }
            memcpy(o + 16, pdf_key_padding, 16);
      }
      else if (c->rev == 5)
      {
      }
      return;
}

// pdf arc4 cipher
static
pdf_err
pdf_filter_arc4_close(pdf_filter *f, int flag)
{
      EVP_CIPHER_CTX *ctx;
      if (!f)
            return 0;
      ctx = (EVP_CIPHER_CTX*)f->state;
      EVP_CIPHER_CTX_cleanup(ctx);
      pdf_free(ctx);
      //printf("\nf=%x\n", (unsigned long)f);
      pdf_free(f);
      return pdf_ok;
}

static
int
pdf_filter_arc4_read(pdf_filter *f, unsigned char *obuf, int request)
{
      pdf_filter *up;
      EVP_CIPHER_CTX *ctx;
      int tmplen, l;

      if (!f)
            return 0;
      ctx = (EVP_CIPHER_CTX*)f->state;
      up = f->next; // upstream
      // read upstream
      l = (up->read)(up, f->ptr, (request < PDF_FILTER_BUF_SIZE)?request:PDF_FILTER_BUF_SIZE);
      if (l == 0)
      {
            if (!EVP_DecryptFinal(ctx, obuf, &tmplen))
                  return 0;
            else
                  return tmplen;
      }
      if(!EVP_DecryptUpdate(ctx, obuf, &request, f->ptr, l))
      {
            /* Error */
            return 0;
      }
      return request;
}

// pdf AES cipher
struct aes_priv_s
{
      unsigned char *p, *e;
      // TODO: buffer overflow over buffer sise 16.
      unsigned char buf[32];
};

pdf_err
pdf_filter_aes_close(pdf_filter *f)
{
      EVP_CIPHER_CTX *ctx;
      if (!f)
            return 0;
      ctx = (EVP_CIPHER_CTX*)f->state;
      if (ctx)
      {
            EVP_CIPHER_CTX_cleanup(ctx);
            pdf_free(ctx);
      }
      if (f->data)
          pdf_free(f->data);
      pdf_free(f);
      return pdf_ok;
}

static int
pdf_filter_aes_read(pdf_filter *f, unsigned char *obuf, int request)
{
      pdf_filter *up;
      EVP_CIPHER_CTX *ctx;
      int tmplen = 0, l;
      int max_request = PDF_FILTER_BUF_SIZE - 16; // seems buffer overflows(16 byte) from vpaes_cbc_encrypt
      struct aes_priv_s *buf = (struct aes_priv_s*)(f->data);
      int e;
      int last_request = request;

      if (!f)
            return 0;
      if (buf && buf->p < buf->buf+16)
      {
	    if (request == 1)
	    {
		  *obuf = *buf->p;
		  if (buf->p >= buf->e)
		  {
			return 0;
		  }
		  else
		  {
			buf->p++;
			return 1;
		  }
	    }
      }
      ctx = (EVP_CIPHER_CTX*)f->state;
      if (!ctx)
            return 0;
      up = f->next; // upstream
      // read upstream
      if (request <= 16)
      {
	    l = (up->read)(up, f->ptr, 16);
      }
      else
      {
	    l = (up->read)(up, f->ptr, (request < max_request)?request:max_request);
      }
      if (l == 0)
      {
            if (!EVP_DecryptFinal(ctx, obuf, &tmplen))
                  return 0;
            else
            {
                  EVP_CIPHER_CTX_cleanup(ctx);
                  pdf_free(ctx);
                  f->state = NULL;
                  return tmplen;
            }
      }
      if (l <= 16)
      {
	    e = EVP_DecryptUpdate(ctx, buf->buf, &request, f->ptr, 16);
      }
      else
      {
	    e = EVP_DecryptUpdate(ctx, obuf, &request, f->ptr, l);
      }
      if (!e)
      {
            /* Error */
            return 0;
      }
      if (request == 0)
      {
	    unsigned char tmp[16];
            if (!EVP_DecryptFinal(ctx, tmp, &tmplen))
                  return 0;
            else
            {
                  EVP_CIPHER_CTX_cleanup(ctx);
                  pdf_free(ctx);
                  f->state = NULL;
		  if (tmplen > 0 && tmplen < (buf->p-buf->buf))
		  {
			memcpy(buf->buf, tmp, tmplen);
			*obuf = buf->buf[0];
			buf->p = buf->buf+1;
			buf->e = buf->buf+tmplen;
			return 1;
		  }
		  else
			return 0;
            }
      }
      return request;
}

// cipher filter api(s)
pdf_filter *
pdf_cryptofilter_new(pdfcrypto_priv *crypto, int num, int gen, unsigned char *iv)
{
      unsigned int n;
      unsigned char key[256];
      unsigned char final_key[256];
      pdf_filter *f = pdf_malloc(sizeof(pdf_filter));
      EVP_MD_CTX ctx;
      const EVP_MD *md = EVP_md5();
      if (!f)
            return NULL;
      //printf("\nc=%x", (unsigned long)f);
      memset(f, 0, sizeof(pdf_filter));
      n = crypto->len/8;
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

      if (crypto->algo == e40plusbitsAES)
            EVP_DigestUpdate(&ctx, (unsigned char *)"sAlT", 4);
      EVP_DigestFinal(&ctx, final_key, &n);
      EVP_MD_CTX_cleanup (&ctx);
      // max 16 bytes of key
      if (n>16)
            n = 16;

      if ((crypto->algo == e40plusbitsRC4) || (crypto->algo == e40bitsRC4))
      {
            EVP_CIPHER_CTX *ctx; // cipher state
            const EVP_CIPHER *rc4 = EVP_rc4();

            ctx = pdf_malloc(sizeof(EVP_CIPHER_CTX));
            if (!ctx)
                  goto cf_fail; // cipher filter fail
            EVP_CIPHER_CTX_init (ctx);
            //EVP_DecryptInit(ctx, rc4, final_key, NULL); // NULL for rc4 iv
	    EVP_CipherInit_ex(ctx, rc4, NULL, NULL, NULL, 0);
	    if (crypto->algo == e40bitsRC4)
		  EVP_CIPHER_CTX_set_key_length(ctx, 10);
	    else
		  EVP_CIPHER_CTX_set_key_length(ctx, 16);
	    /* We finished modifying parameters so now we can set key and IV */
	    EVP_CipherInit_ex(ctx, NULL, NULL, final_key, NULL, 0);

            f->state = (void*) ctx;
            f->close = pdf_filter_arc4_close;
            f->read = pdf_filter_arc4_read;
            f->ptr = f->buf;
      }
      else if (crypto->algo == e40plusbitsAES)
      {
            EVP_CIPHER_CTX *ctx; // cipher state
            const EVP_CIPHER *aes128 = EVP_aes_128_cbc();
            const EVP_CIPHER *aes256 = EVP_aes_256_cbc();
            unsigned char t[16];
            int request;
	    // TODO: remove the "+8" HACK
	    struct aes_priv_s* buf = pdf_malloc(sizeof(struct aes_priv_s));

            ctx = pdf_malloc(sizeof(EVP_CIPHER_CTX));
            if (!ctx)
                  goto cf_fail; // cipher filter fail
            EVP_CIPHER_CTX_init (ctx);
            if (crypto->len == 128)
                  EVP_DecryptInit(ctx, aes128, final_key, iv);
            else
                  EVP_DecryptInit(ctx, aes256, final_key, iv);
            f->state = (void*) ctx;
            f->close = pdf_filter_aes_close;
            f->read = pdf_filter_aes_read;
            f->ptr = f->buf;
	    buf->p = buf->buf+16;
	    f->data = (void*)buf;
      }
      else
      {
            goto cf_fail;
      }
      return f;
  cf_fail:
      if (f)
            pdf_free(f);
      return NULL;
}

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
