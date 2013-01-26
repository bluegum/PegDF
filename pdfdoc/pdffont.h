#ifndef PDFFONT_H
#define PDFFONT_H
#include "pdftypes.h"
#include "pdfcmap.h"

typedef enum pdf_font_type_e pdf_font_type;
typedef struct pdf_font_descriptor_s pdf_font_descriptor;
typedef struct pdf_font_encoding_s pdf_font_encoding;
typedef struct pdf_font_type3_s pdf_font_type3;
typedef struct pdf_font_type1_tt_s pdf_font_type1_tt;
typedef struct pdf_font_s pdf_font;

enum pdf_font_type_e
{
      Type0,
      Type1,
      MMType1,
      Type3,
      TrueType,
      CIDFontType0,
      CIDFontType2
};

struct pdf_font_encoding_s
{
      pdf_obj *baseencoding;
      pdf_obj *differences;
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
      char *basefont;
      int firstchar;
      int lastchar;
      int *widths;
      pdf_font_descriptor *fontdescriptor;
      pdf_font_encoding *encoding;
      pdf_cmap *tounicode;
};

struct pdf_font_type3_s
{
      pdf_rect fontbbox;
      float fontmatrix[6];
      pdf_obj *charprocs;
      pdf_font_encoding *encoding;
      char *basefont;
      int firstchar;
      int lastchar;
      int *widths;
      pdf_font_descriptor *fontdescriptor;
      pdf_obj *resources;
      pdf_cmap *tounicode;
};

struct pdf_font_s
{
      pdf_font_type *type;
      union {
	    pdf_font_type1_tt type1;
	    pdf_font_type1_tt tt;
	    pdf_font_type3 type3;
      } font;
};


extern pdf_font *pdf_font_load(pdf_obj *o);
extern void pdf_font_free(pdf_font *f);

#endif // PDFFONT_H
