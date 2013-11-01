#ifndef PDFFONT_H
#define PDFFONT_H
#include "pdftypes.h"
#include "pdfcmap.h"
#include "pdfcrypto.h"
#include "gsdraw.h"

typedef enum pdf_font_type_e pdf_font_type;
typedef enum pdf_font_encoding_type_e pdf_font_encoding_type;

typedef struct pdf_font_descriptor_s pdf_font_descriptor;
typedef struct pdf_font_encoding_s pdf_font_encoding;
typedef struct pdf_font_type3_s pdf_font_type3;
typedef struct pdf_font_type1_tt_s pdf_font_type1_tt;
typedef struct pdf_font_s pdf_font;

enum pdf_font_type_e
{
      Type0,
      Type1,
      Type2,
      Type3,
      MMType1,
      TrueType,
      CIDFontType0,
      CIDFontType2
};

enum pdf_font_encoding_type_e
{
      // simple font
      StandardEncoding,
      WinAnsiEncoding,
      MacRomanEncoding,
      MacExpertEncoding,
      Symbol,
      ZapfDingbat,
      // Composite fonts
      Identity_H,
      Identity_V,
};

struct pdf_font_encoding_s
{
      pdf_font_encoding_type type;
      pdf_obj *baseencoding;
      const char **differences;
      unsigned int (*get_cid)(unsigned char*s, unsigned int *code);
      const char * (*get_glyph_name)(pdf_font_encoding *e, unsigned int code);
};

struct pdf_font_descriptor_s
{
      char fontname[256];
      char *fontfamily;
      pdf_obj *fontstretch;
      int fontweight;
      unsigned int flags;
      pdf_rect fontbbox;
      float italicangle;
      float ascent;
      float descent;
      float leading;
      float capheight;
      float xheight;
      float stemv;
      float stemh;
      float avgwidth;
      float maxwidth;
      float missingwidth;
      pdf_obj *fontfile;
      pdf_obj *fontfile2;
      pdf_obj *fontfile3;
      unsigned char *charset;
      // private
      fontname_id fontname_id;
};

struct pdf_font_type1_tt_s
{
      int firstchar;
      int lastchar;
      pdf_cmap *tounicode;
};

struct pdf_font_type3_s
{
      pdf_rect fontbbox;
      float fontmatrix[6];
      pdf_obj *charprocs;
      int firstchar;
      int lastchar;
      int *widths;
      pdf_obj *resources;
      pdf_cmap *tounicode;
};

struct pdf_font_s
{
      pdf_font_type type;
      char basefont[256];
      pdf_font_encoding *encoding;
      pdf_tounicode *tounicode;
      union {
	    pdf_font_type1_tt type1;
	    pdf_font_type1_tt tt;
	    pdf_font_type3 type3;
      } font;
      int firstchar;
      int lastchar;
      float *widths;
      pdf_font_descriptor *fontdescriptor;
      // private
      int ref;
      pdf_font* next;
      int (*unicode_get)(pdf_font *, unsigned int char_code, unsigned char *unicode); // return the number of unicodes, normally 1.
};

extern pdf_font *pdf_font_load(pdf_obj *o, int, pdfcrypto_priv* encrypt);
extern void pdf_font_free(pdf_font *f);
extern void pdf_cmap_tounicode_parse(pdf_obj *cmap, pdf_font *f, pdfcrypto_priv* encrypt);
extern int unicode_get_cmap(pdf_font *f, unsigned int c, unsigned char *uni);
extern int pdf_font_tounicode(pdf_font *f, unsigned int cid, unsigned char *uni);
extern float pdf_font_widths_get(pdf_font* f, u32 cid);
extern int pdf_font_flags_get(pdf_font *f);
extern char *pdf_font_basefont_get(pdf_font *f);
extern fontname_id pdf_font_basefont_id_get(pdf_font *f);
extern pdf_font* pdf_font_find(pdf_font* f, int ref);

#endif // PDFFONT_H
