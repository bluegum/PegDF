#ifndef PDFFILTER_H
#define PDFFILTER_H
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
    Limit,
    Raw
  };

struct pdf_filter_s
{
  unsigned char buf[1024];
  unsigned char *ptr, *end;
  ///
  void *state;
  pdf_filter *next;
  ///
  pdf_err (*close)(pdf_filter*);
  int (*getchar)(pdf_filter*);
};

extern pdf_err pdf_flatedecode_new(pdf_filter **f);
extern pdf_err pdf_flatedecode_delete(pdf_filter *f);
#endif
