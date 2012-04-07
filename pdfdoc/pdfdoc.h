#ifndef PDFDOC_H
#define PDFDOC_H
#include "pdftypes.h"
#include "gsdraw.h"
#include "pdfresource.h"
#include "pdffilter.h"

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
typedef struct pdf_resources_s pdf_resources;
typedef struct pdf_thread_s pdf_thread;
typedef struct pdf_bead_s pdf_bead;

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

enum pdf_annotation_type_e
  {
    eText,
    eLink,
    eFreeText,
    eLine,
    eSquare,
    eCircle, 
    ePolygon,
    ePolyLine,
    eHighlight, 
    eUnderline, 
    eSquiggly, 
    eStrikeOut, 
    eStamp, 
    eCaret, 
    eInk, 
    ePopup, 
    eFileAttachment, 
    eSound, 
    eMovie, 
    eWidget, 
    eScreen, 
    ePrinterMark, 
    eTrapNet, 
    eWatermark, 
    e3D, 
    eRedact,
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
  // private
  pdf_annots *next;
};

struct pdf_resources_s
{
  pdf_extgstate *extgstate;
  pdf_cspace *colorspace;
  void *pattern;
  void *shading;
  void *xobject;
  void *font;
  char **procset;
  void *properties;
};

struct pdf_page_s
{
  pdf_obj *parent;
  char *lastmodified;
  pdf_resources * resources;
  gs_rect mediabox;
  pdf_obj *contents;
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
  // private
  pdf_stream *content_streams;
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

struct pdf_stream_s
{
  int length;
  void *decodeparms;
  void *f;
  pdf_filter *ffilter; // filter train
  void *fdecodeparms;
  int dl;
  // private
  pdf_stream *next;
};

/*
 * XObject
 */

typedef struct pdf_xobject_s pdf_xobject;

struct pdf_xobject_s
{
        int refs;
        gs_matrix matrix;
        gs_rect bbox;
        int isolated;
        int knockout;
        int transparency;
        pdf_obj *resources;
  //fz_buffer *contents;
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

struct pdf_pagelabel_s
{
  enum {D, R, r, A, a} s;
  char *p;
  int st;
};

struct pdf_thread_s
{
  pdf_bead *f;
  pdf_info *i;
};

struct pdf_bead_s
{
  pdf_thread *t; // thread
  pdf_bead *n; // next bead
  pdf_bead *v; // prev bead
  pdf_page *p; // page it belongs to
  gs_rect r;
};

// functions
extern pdf_err pdf_info_print(pdf_info *info);
extern pdf_resources* pdf_resources_load(pdf_obj *o);
extern pdf_extgstate* pdf_extgstate_load(pdf_obj *o);
extern pdf_annots* pdf_annots_load(pdf_obj* o);
extern pdf_stream* pdf_streams_load(pdf_obj* o);
extern pdf_err pdf_streams_free(pdf_stream* s);
extern pdf_stream* pdf_stream_load(pdf_obj* o);
extern pdf_err pdf_stream_free(pdf_stream *s);
extern pdf_err pdf_annots_free(pdf_annots *a);
extern pdf_err pdf_resources_free(pdf_resources*);
extern pdf_err pdf_extgstate_free(pdf_extgstate*);
extern pdf_err pdf_trailer_open(pdf_obj *trailer);
#endif
