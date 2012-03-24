#ifndef PDFDOC_H
#define PDFDOC_H

#include "gsdraw.h"
#include "pdfresource.h"

typedef enum pdf_error_e
  {
    pdf_ok,
    pdf_unknown
  } pdf_err;

typedef struct pdf_page_s pdf_page;
typedef struct pdf_doc_s pdf_doc;

struct pdf_page_s
{
  void *parent;
  void *lastmodified;
  pdf_resource * resources;
  gs_rect mediabox;
  void *contents;
  int rotate;
  void *group;
  void *thumb;
  void *b;
  void *dur;
  void *trans;
  void *annots;
  void *aa;
  void *metadata;
  void *pieceinfo;
  void *structparents;
  unsigned char *id;
  int pz;
  void *separationinfo;
  void *tabs;
  void *templateinstantiated;
  void *pressteps;
  int userunit;
  void *vp;
};

struct pdf_doc_s
{
  // catalog
  int version;
  void *extentions;
  void *pagelabels;
  void *names;
  void *dests;
  void *viewerpreferences;
  void *pagelayout;
  void *pagemode;
  void *outlines;
  void *threads;
  void *openaction;
  void *aa;
  void *uri;
  void *acroform;
  void *metadata;
  void *structtreeroot;
  void *markinfo;
  char *lang;
  void *spiderinfo;
  void *outputintents;
  void *pieceinfo;
  void *ocproperties;
  void *perms;
  void *legal;
  void *requirements;
  void *collection;
  int needsrendering; // boolean
  // page tree
  pdf_page **pages;
  int count;
  // internal
  int pageidx;
};

typedef enum pdf_filter_e pdf_filter;

enum pdf_filter_e
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
    Limit
  };

struct pdf_stream_s
{
  int length;
  pdf_filter *filter; // terminated by Limit
  void *decodeparms;
  void *f;
  void *ffilter;
  void *fdecodeparms;
  int dl;
};

#endif
