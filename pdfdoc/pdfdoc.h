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
typedef struct pdf_info_s pdf_info;
typedef struct pdf_stream_s pdf_stream;
typedef struct pdf_extgstate_s pdf_extgstate;
typedef struct pdf_group_s pdf_group;
typedef struct pdf_mask_s pdf_mask;
typedef struct pdf_annots_s pdf_annots;
// logical document structure
typedef struct pdf_structtreeroot_s pdf_structtreeroot;
typedef struct pdf_resource_s pdf_resource;

struct pdf_mask_s
{
  char *s;
  pdf_stream *g;
  pdf_obj *bc;
  void *tr;
};

struct pdf_group_s
{
  void *cs;
  int i;
  int k;
};

struct pdf_annots_s
{
  void *subtype;
  gs_rect rect;
  char *contents;
  pdf_obj *p;
  char *nm;
  char *m;
  int f;
  pdf_obj *ap;
  void *as;
  int *boarder;
  float *c;
  int structparent;
  pdf_obj *oc;
};

struct pdf_resource_s
{
  pdf_extgstate *extgstate;
  void *colorspace;
  void *pattern;
  void *shading;
  void *xobject;
  void *font;
  void *procset;
  void *properties;
};

struct pdf_page_s
{
  pdf_obj *parent;
  char *lastmodified;
  pdf_resource * resources;
  gs_rect mediabox;
  pdf_stream *contents;
  int rotate;
  pdf_group *group;
  pdf_obj *thumb;
  void *b;
  void *dur;
  void *trans;
  pdf_annots *annots;
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

typedef enum pdf_pagemode_e pdf_pagemode;
enum pdf_pagemode_e
  {
    UseNone,
    UseOutlines,
    UseThumbs,
    FullScreen,
    UseOC,
    UseAttachments
  };

struct pdf_info_s
{
  char *title;
  char *author;
  char *subject;
  char *keywords;
  char *creator;
  char *producer;
  char *creationdate;
  char *moddate;
  enum {UNknown, TRue, FAlse} trapped;
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
  pdf_pagemode pagemode;
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
  pdf_info *info;
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

// logical document layout
struct pdf_structtreeroot_s
{
  char *type;
  void *k;
  void *idtree;
  void *parenttree;
  int parenttreenextkey;
  void *rolemap;
  void *classmap;
};

// functions
extern pdf_err pdf_info_print(pdf_info *info);

#endif
