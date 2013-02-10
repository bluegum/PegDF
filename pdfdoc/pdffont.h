#ifndef PDFFONT_H
#define PDFFONT_H
#include "pdftypes.h"
#include "pdfcmap.h"

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
      unsigned int (*get_cid)(unsigned int code);
      const char * (*get_glyph_name)(pdf_font_encoding *e, unsigned int code);
};

struct pdf_font_descriptor_s
{
      pdf_obj *fontname;
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
};

struct pdf_font_type1_tt_s
{
      int firstchar;
      int lastchar;
      int *widths;
      pdf_font_descriptor *fontdescriptor;
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
      pdf_font_descriptor *fontdescriptor;
      pdf_obj *resources;
      pdf_cmap *tounicode;
};

struct pdf_font_s
{
      pdf_font_type type;
      char *basefont;
      pdf_font_encoding *encoding;
      union {
	    pdf_font_type1_tt type1;
	    pdf_font_type1_tt tt;
	    pdf_font_type3 type3;
      } font;
      // private
      int ref;
      pdf_font* next;
      int (*unicode_get)(pdf_font *, unsigned int char_code, unsigned int *unicode); // return the number of unicodes, normally 1.
};

extern pdf_font *pdf_font_load(pdf_obj *o, int);
extern void pdf_font_free(pdf_font *f);
extern void pdf_character_show(void* dev, pdf_font *f, gs_matrix *ctm, unsigned int c);


#endif // PDFFONT_H
