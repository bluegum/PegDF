#ifndef PDFFILTER_H
#define PDFFILTER_H
#include <stdio.h>
#include "pdftypes.h"

typedef enum pdf_filterkind_e pdf_filterkind;
typedef struct pdf_filter_s pdf_filter;

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
      Limit,
      Raw
};
#define PDF_FILTER_BUF_SIZE 1024
struct pdf_filter_s
{
      ///
      void *state;
      pdf_filter *next;
      ///
      pdf_err (*close)(pdf_filter*, int flag);
      int (*read)(pdf_filter*, unsigned char *, int);
      int (*write)(pdf_filter*, unsigned char *, int);
      ///
      unsigned char buf[PDF_FILTER_BUF_SIZE]; // holds input buffer for upstream output
      unsigned char *ptr, *end; // end is at one byte beyond buffer
      // private
      void *data;
};

#define PDF_FILTER_CLOSE(f, flag)						\
      while (f) { pdf_filter *t = (f)->next; (*(f)->close)(f, (flag)); (f) = t; }
extern pdf_err pdf_flated_new(pdf_filter **f);
extern pdf_filter* pdf_filter_new(pdf_filterkind t, pdf_filter *last);
extern int pdf_filter_read(pdf_filter *f, unsigned char *buf, int len);

#endif
