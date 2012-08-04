#ifndef PDFFILTER_H
#define PDFFILTER_H
#include "pdftypes.h"
//#include "pdfread.h"

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
#define PDF_FILTER_BUF_SIZE 1024
struct pdf_filter_s
{
  ///
  void *state;
  pdf_filter *next;
  ///
  pdf_err (*close)(pdf_filter*);
  int (*read)(pdf_filter*, unsigned char *, int);
  /// 
  unsigned char buf[PDF_FILTER_BUF_SIZE]; // holds input buffer for upstream output
  unsigned char *ptr, *end; // end is at one byte beyond buffer
};

extern pdf_err pdf_flated_new(pdf_filter **f);
extern pdf_filter* pdf_filter_new(pdf_filterkind t);
#endif
