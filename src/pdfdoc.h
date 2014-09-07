#ifndef PDFDOC_H
#define PDFDOC_H

#include "pdf.h"
#include "pdfread.h"
#include "pdfmem.h"
#include "gsdraw.h"
#include "pdfresource.h"
#include "pdffilter.h"
#include "pdfstream.h"
#include "pdfcrypto.h"
#include "pdffont.h"
#include "pdfdevice.h"
#include "pdfinterp.h"
#include "pdfoc.h"

typedef struct pdf_page_s pdf_page;
//typedef struct pdf_doc_s pdf_doc;
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
typedef struct pdf_trailer_s pdf_trailer;
typedef struct pdf_extgstate_s pdf_extgstate;
typedef struct pdf_prs_s pdf_prs;
typedef enum pdf_annotation_type_e pdf_annotation_type;

struct pdf_info_s
{
    pdf_obj *title;
    pdf_obj *author;
    pdf_obj *subject;
    pdf_obj *keywords;
    pdf_obj *creator;
    pdf_obj *producer;
    pdf_obj *trapped;
    char *creationdate;
    char *moddate;
};

struct pdf_mask_s
{
    char *s;
    pdf_stream *g;
    pdf_obj *bc;
    void *tr;
};

struct pdf_group_s
{
    pdf_obj *cs;
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
    pdf_annotation_type subtype;
    gs_rect rect;
    char *contents;
    pdf_obj *p;
    char *nm;
    char *m;
    int f;
    pdf_obj *ap;
    void *as;
    float border[5];
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

struct pdf_extgstate_s
{
    float LW;
    int LC;
    int LJ;
    float ML;
    float D[32], D_OFFSET;
    int D_n;
    char *RI;
    int OP;
    int op;
    int OPM;
    struct {pdf_obj * font; float size;} *Font;
    void *BG;
    void *BG2;
    void *UCR;
    void *UCR2;
    void *TR;
    void *TR2;
    float FL;
    float SM;
    int SA;
    void *BM;
    void *SMask;
    float CA;
    float ca;
    int AIS;
    int TK;
    // generics
    gs_matrix ctm;
    // text/font state
    int tr;
    float fs, tl, tw, tc, ts, th;
    gs_matrix txt_ctm;
    gs_matrix txt_lm;
    // path
    byte *path_base;
    byte *path_top;
};

struct pdf_prs_s
{
    pdf_cspace brush;
    pdf_cspace pen;
    pdf_extgstate gs;
};

struct pdf_page_s
{
    pdf_obj *parent;
    char   *lastmodified;
    pdf_resources * resources;
    gs_rect mediabox;
    pdf_obj *cropbox;
    pdf_obj *bleedbox;
    pdf_obj *trimbox;
    pdf_obj *artbox;
    pdf_obj *boxcolorinfo;
    pdf_obj *contents;
    int      rotate;
    pdf_group *group;
    pdf_obj *thumb;
    pdf_obj *b;
    float    dur;
    pdf_obj *trans;
    pdf_annots *annots;
    pdf_obj *aa;
    pdf_obj *metadata;
    pdf_obj *pieceinfo;
    int      structparents;
    pdf_obj *id;
    float    pz;
    pdf_obj *separationinfo;
    pdf_obj *tabs;
    pdf_obj *templateinstantiated;
    pdf_obj *pressteps;
    float    userunit;
    pdf_obj *vp;
    // private
    pdf_stream *content_streams;
    pdf_prs sstk[32], *s; // Ought to be enough for g/G?
    pdf_interp_state* i;
    pdf_obj  ref;
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

struct pdf_doc_s
{
    // catalog
    pdf_obj* version;
    pdf_obj *extentions;
    pdf_obj *pagelabels;
    pdf_obj *names;
    pdf_obj *dests;
    pdf_obj *viewerpreferences;
    pdf_obj *pagelayout;
    pdf_obj *pagemode;
    pdf_obj *outlines;
    pdf_obj *threads;
    pdf_obj *openaction;
    pdf_obj *aa;
    pdf_obj *uri;
    pdf_obj *acroform;
    pdf_obj *metadata;
    pdf_obj *structtreeroot;
    pdf_obj *markinfo;
    char *lang;
    pdf_obj *spiderinfo;
    pdf_obj *outputintents;
    pdf_obj *pieceinfo;
    pdf_ocproperties *ocproperties;
    pdf_obj *perms;
    pdf_obj *legal;
    pdf_obj *requirements;
    pdf_obj *collection;
    int needsrendering; // boolean
    // page tree
    pdf_page **pages;
    int count;
    // internal parking spot
    int pageidx;
    int root_ref; // The original ref number, for writer re-referencing
    int pages_ref; // The original ref number, for writer re-referencing
    //pdf_info *info;
    pdf_encrypt *encrypt;
    pdf_trailer *trailer;
    // member functions
    gs_rect *(*get_mediabox)(pdf_doc*);
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

struct pdf_encrypt_s
{
    char *filter;
    char *subfilter;
    int v;
    int length;
    pdf_cryptfilter *cf;
    pdfcrypto_priv *stmf;
    pdfcrypto_priv *strf;
    pdfcrypto_priv *eff;
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
    char* id[2];
    // xrefstream entries
    int index[128];
    int w[3];
    // chain
    pdf_trailer *last;
};

// short hands
static inline int pdf_brush_n(pdf_page *p) { return p->s->brush.n; }
static inline int pdf_pen_n(pdf_page *p) { return p->s->pen.n; }
// functions
extern pdf_err pdf_info_print(pdf_info *info);
extern pdf_resources* pdf_resources_load(pdf_obj *o);
extern pdf_extgstate* pdf_extgstate_load(pdf_obj *o);
extern pdf_annots* pdf_annots_load(pdf_obj* o);
extern pdf_err pdf_annots_free(pdf_annots *a);
extern pdf_err pdf_resources_free(pdf_resources*);
extern pdf_err pdf_extgstate_free(pdf_extgstate*);
extern pdf_err pdf_cs_parse(pdf_page *, pdfcrypto_priv*, pdf_stream *s);
extern pdf_err pdf_cf_load(pdf_encrypt *e, pdf_obj *o, char *name, pdfcrypto_priv **cryptfilter);
extern pdf_err pdf_info_load(pdf_obj *o, pdf_info **info);
extern pdf_doc* pdf_doc_load(pdf_trailer*);
extern void pdf_doc_done(pdf_doc *d);
extern pdf_err  pdf_doc_print_info(pdf_doc *d);
extern pdf_err pdf_doc_process(pdf_doc *d, pdf_device*, pdfcrypto_priv* encrypt);
extern pdf_err pdf_open(char *in,  pdf_doc **doc);
extern pdf_err pdf_finish(pdf_doc *doc);
extern int pdf_doc_authenticate_user_password(pdf_doc *doc, char *pw);
extern int pdf_doc_need_passwd(pdf_doc *doc);
extern void pdf_doc_trailer_free(pdf_trailer * tr);
extern int pdf_character_show(pdf_device* dev, pdf_prs *s, pdf_font *f, gs_matrix *ctm, unsigned char *c, u32 *cid);
extern pdfcrypto_priv *pdf_crypto_init(pdf_encrypt* encrypt, unsigned char id1[16], char *pw);
extern void pdf_device_char_show(pdf_device *dev, pdf_font *f, float scale, gs_matrix *ctm, unsigned int cid);
extern void pdf_device_color_set(pdf_device *d, float *c, pdf_cspacetype cs, int n, int pen);
extern void pdf_path_add(pdf_extgstate *gs, e_path_kind t, float a, float b, float c, float d, float e, float f);
extern pdf_err pdf_path_paint(pdf_device *dev, pdf_extgstate *gs, int stroke, int even_odd);
extern void pdf_update_brush(pdf_page *p);
extern pdf_obj *pdf_info_create(pdf_info *);
extern void pdf_id_create(char *filename, int filesize, pdf_obj *info, char *out);

#endif
