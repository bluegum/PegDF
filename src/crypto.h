#ifndef CRYPTO_H
#define CRYPTO_H

#define fips_md_init(alg) fips_md_init_ctx(alg, alg)

#ifdef OPENSSL_FIPS
#define fips_md_init_ctx(alg, cx) \
        int alg##_Init(cx##_CTX *c) \
        { \
        if (FIPS_mode()) OpenSSLDie(__FILE__, __LINE__, \
                "Low level API call to digest " #alg " forbidden in FIPS mode!"); \
        return private_##alg##_Init(c); \
        } \
        int private_##alg##_Init(cx##_CTX *c)

#define fips_cipher_abort(alg) \
        if (FIPS_mode()) OpenSSLDie(__FILE__, __LINE__, \
                "Low level API call to cipher " #alg " forbidden in FIPS mode!")

#else
#define fips_md_init_ctx(alg, cx) \
        int alg##_Init(cx##_CTX *c)
#define fips_cipher_abort(alg) while(0)
#endif

#endif /*CRYPTO_H*/
