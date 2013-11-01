#ifndef LZW_DECOMP_H
#define LZW_DECOMP_H

typedef void * (*lzw_decomp_malloc)(size_t);
typedef void (*lzw_decomp_free)(void *);
typedef ssize_t (*lzw_decomp_src_read)(int up, void *buf, size_t count);
typedef struct lzw_decompress_t lzw_decompress;

extern lzw_decompress* lzw_decomp_init(lzw_decomp_malloc _malloc, lzw_decomp_free _free, lzw_decomp_src_read _read, void *src);
extern int lzw_decomp_read(lzw_decompress *d, unsigned char *buf, int len);
extern void lzw_decomp_close(lzw_decompress *d);

#endif
