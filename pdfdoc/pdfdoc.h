#ifndef PDFDOC_H
#define PDFDOC_H

#include "pdftypes.h"
#include "gsdraw.h"
#include "pdfresource.h"
//#include "pdffilter.h"

typedef struct pdf_page_s pdf_page;
typedef struct pdf_doc_s pdf_doc;
typedef struct pdf_info_s pdf_info;
// typedef struct pdf_extgstate_s pdf_extgstate;
typedef struct pdf_group_s pdf_group;
typedef struct pdf_mask_s pdf_mask;
typedef struct pdf_annots_s pdf_annots;
// logical document structure
typedef struct pdf_structtreeroot_s pdf_structtreeroot;
typedef struct pdf_resources_s pdf_resources;
typedef struct pdf_thread_s pdf_thread;
typedef struct pdf_bead_s pdf_bead;
typedef struct pdf_encrypt_s pdf_encrypt;
typedef struct pdf_cryptfilter_s pdf_cryptfilter;
typedef struct pdfcrypto_priv_s pdfcrypto_priv;
typedef struct pdf_stream_s pdf_stream;
typedef struct pdf_trailer_s pdf_trailer;

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
      pdf_obj *extgstate;
      pdf_obj *colorspace;
      pdf_obj *pattern;
      pdf_obj *shading;
      pdf_obj *xobject;
      pdf_obj *font;
      char **procset;
      pdf_obj *properties;
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
      pdf_prs sstk[32], *s; // Ought to be enough for g/G?
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
      // internal parking spot
      int pageidx;
      //pdf_info *info;
      //pdf_encrypt *encrypt;
      pdf_trailer *trailer;
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

typedef enum pdf_encrypt_kind_e pdf_encrypt_kind;
enum pdf_encrypt_kind_e
{
      eCryptNone,
      eCryptRC4,
      eCryptAES
};

struct pdf_cryptfilter_s
{
      char *type;
      char *cfm;
      enum {eDocOpen, eEFOpen} authevent;
      int length;
      // additional entries for public-key
      void *recipients;
      int encryptmetadata; // boolean
};

struct pdf_encrypt_s
{
      char *filter;
      char *subfilter;
      int v;
      int length;
      pdf_cryptfilter *cf;
      char *stmf;
      char *strf;
      char *eff;
      // standard filter
      int r;
      unsigned char o[32];
      unsigned char u[32];
      int p;
      int encrypt_metadata;
};

/// The splayed trailer
struct pdf_trailer_s
{
      int size;
      int prev;
      pdf_obj * root_obj;
      pdf_encrypt *encrypt;
      pdf_info *info;
      unsigned char id[2][32];
      // xrefstream entries
      int index[2];
      int w[3];
};

// short hands
static inline int pdf_brush_n(pdf_page *p) { return p->s->brush.n; }
static inline int pdf_pen_n(pdf_page *p) { return p->s->pen.n; }
// functions
extern pdf_err pdf_info_print(pdf_info *info);
extern pdf_resources* pdf_resources_load(pdf_obj *o);
extern pdf_extgstate* pdf_extgstate_load(pdf_obj *o);
extern pdf_annots* pdf_annots_load(pdf_obj* o);
extern pdf_stream* pdf_streams_load(pdf_obj* o);
extern pdf_err pdf_streams_free(pdf_stream* s);
extern pdf_stream* pdf_stream_load(pdf_obj* o, pdfcrypto_priv*, int, int);
extern pdf_err pdf_stream_free(pdf_stream *s);
extern pdf_err pdf_annots_free(pdf_annots *a);
extern pdf_err pdf_resources_free(pdf_resources*);
extern pdf_err pdf_extgstate_free(pdf_extgstate*);
extern pdf_err pdf_cs_parse(pdf_page *, pdf_stream *s);
extern pdf_err pdf_cf_load(pdf_obj *o, pdf_cryptfilter **cryptfilter);
extern pdf_err pdf_info_load(pdf_obj *o, pdf_info **info);
extern pdf_doc* pdf_doc_load(pdf_trailer*);
extern void pdf_doc_done(pdf_doc *d);
extern pdf_err  pdf_doc_print_info(pdf_doc *d);
extern pdf_err pdf_doc_process(pdf_doc *d, pdfcrypto_priv* encrypt);
extern pdf_err pdf_read(char *in, char *out,  pdf_doc **doc);
extern pdf_err pdf_finish(pdf_doc *doc);
extern int pdf_doc_authenticate_user_password(pdf_doc *doc, unsigned char *pw, int pwlen);
extern pdf_err pdf_doc_process_all(pdf_doc *doc, unsigned char *pw, int pwlen);
extern int pdf_doc_need_passwd(pdf_doc *doc);

extern pdf_err pdf_write_pdf(pdf_doc *doc, char *ofile, int version, int pg1st, int pglast, char *upw, char *opw);

#endif
