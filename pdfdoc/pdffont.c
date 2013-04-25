#include <stdio.h>
#include "pdftypes.h"
#include "pdfindex.h"
#include "dict.h"
#include "pdffilter.h"
#include "pdffont.h"
#include "pdfencodingtable.c"
#include "glyph_name_to_uni.c"
#include "pdfcrypto.h"
#include "pdfdoc.h"
#include "pdf_priv.h"

static const char * get_glyph_name(pdf_font_encoding *e, unsigned int c);
static unsigned int get_cid_simple(unsigned char *c, unsigned int *cid) { *cid = c[0];return 1; }
static int unicode_get_stub(pdf_font *f, unsigned int c, unsigned char *uni) { *uni = c; return 1; }

static const int ascii_to_int[] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,
    0,10,11,12,13,14,15,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,10,11,12,13,14,15,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};

unsigned char asciihex2byte(unsigned char *c)
{
    unsigned char i;
    i = ((ascii_to_int[c[0]]<<4) +
         (ascii_to_int[c[1]]));
    return i;
}

unsigned int asciihex2int(unsigned char *c)
{
    unsigned int i;
    i = ((ascii_to_int[c[0]]<<4) +
         (ascii_to_int[c[1]]));
    if (c[2])
    {
	    i = (i << 8) + (ascii_to_int[c[2]]<<4) + (ascii_to_int[c[3]]);
    }
    return i;
}
static unsigned int get_cid_identity(unsigned char *c, unsigned int *cid)
{
    *cid = asciihex2int(c);
    return 4;
}

// extract unicode from char code for simple fonts
static int unicode_get_simple(pdf_font *f, unsigned int c, unsigned char *uni)
{
    pdf_font_encoding *e;
    const char *gname = 0;
    *uni = c;
    if (!f)
	    return 1;
    e = f->encoding;
    if (!e)
	    return 1;
    gname = get_glyph_name(e, c);
    if (gname)
    {
	    const struct glyphlist *gl = glyph_name_to_uni(gname, strlen(gname));
	    if (gl)
	    {
            // parse hax string
            int i = 1;
            unsigned int n = 0;
            unsigned char *ptr = (unsigned char*)gl->unicode;
            while (*ptr)
            {
                if (*ptr == ' ')
                {
                    uni[i++] = n;
                    i++;
                }
                else
                {
                    n <<= 8;
                    n += ascii_to_int[*ptr];
                }
                ptr++;
            }
            return i;
	    }
	    else
	    {
            return 1;
	    }
    }
    return 1;
}

static const char * get_glyph_name(pdf_font_encoding *e, unsigned int c)
{
    const char *p = 0;
    if (c > 255)
	    return 0;
    if (e->differences)
    {
	    return e->differences[c];
    }

    switch (e->type)
    {
	    case StandardEncoding:
            p = standard_encoding[c];
            break;
	    case WinAnsiEncoding:
            p = win_ansi_encoding[c];
            break;
	    case MacRomanEncoding:
            p = mac_roman_encoding[c];
            break;
	    case MacExpertEncoding:
            p = expert_encoding[c];
            break;
	    case Symbol:
            p = symbol_encoding[c];
            break;
	    case ZapfDingbat:
            p = zapf_dingbats_encoding[c];
            break;
	    default:
            break;
    }
    return p;
}

void
pdf_encoding_free(pdf_font_encoding *p)
{
    if (p)
    {
	    if (p->differences)
            pdf_free(p->differences);
	    pdf_free(p);
    }
}

void
pdf_font_widths_load(pdf_obj *a, pdf_font* f)
{
    pdf_obj *val;

    if (!a)
	    return;
    val = pdf_dict_get(a, "Widths");
    if  (!val || pdf_to_arraylen(val) == 0)
    {
	    f->widths = 0;
	    return;
    }
    f->widths = pdf_malloc(sizeof(float)*pdf_to_arraylen(val));
    if (!f->widths)
	    return;
    pdf_to_float_array(val, f->widths);
    f->firstchar = pdf_to_int(pdf_dict_get(a, "FirstChar"));
    f->lastchar = pdf_to_int(pdf_dict_get(a, "LastChar"));
}

float
pdf_font_widths_get(pdf_font* f, u32 cid)
{
    if (!f || (!f->widths))
	    return 1000;
    if (cid > f->lastchar)
	    return 1000;
    return f->widths[cid-f->firstchar];
}

void
pdf_encoding_load(pdf_obj *a, pdf_font_encoding* e)
{
    const char **tbl = standard_encoding;
    char *base = 0;

    pdf_obj_resolve(a);
    if (!a)
    {
	    e->type = StandardEncoding;
	    e->get_glyph_name = get_glyph_name;
	    e->get_cid = get_cid_simple;
	    return;
    }
    if (obj_is_dict(a))
    {
        base = pdf_to_name(pdf_dict_get(a, "BaseEncoding"));
    }
    else if (obj_is_name(a))
    {
        base = pdf_to_name(a);
    }

    if (base) {
	    if (strncmp(base, "WinAnsiEncoding", sizeof("WinAnsiEncoding")) == 0)
	    {
            e->type = WinAnsiEncoding;
            tbl = win_ansi_encoding;
	    }
	    else if (strncmp(base, "StandardEncoding", sizeof("StandardEncoding")) == 0)
	    {
            e->type = WinAnsiEncoding;
            tbl = standard_encoding;
	    }
	    else if (strncmp(base, "MacRomanEncoding", sizeof("MacRomanEncoding")) == 0)
	    {
            e->type = MacRomanEncoding;
            tbl = mac_roman_encoding;
	    }
	    else if (strncmp(base, "MacExpertEncoding", sizeof("MacExpertEncoding")) == 0)
	    {
            e->type = MacExpertEncoding;
            tbl = mac_expert_encoding;
	    }
	    else
	    {
            e->type = StandardEncoding;
            tbl = standard_encoding;
	    }
	    e->get_glyph_name = get_glyph_name;
    }
    else {
        e->type = StandardEncoding;
        tbl = standard_encoding;
    }

    if (obj_is_dict(a))
    {
	    pdf_obj *o = pdf_dict_get(a, "Differences");
	    if (o && pdf_to_arraylen(o))
	    {
            int i;
            e->differences = pdf_malloc(sizeof(char*)*256);
            if (e->differences)
                memcpy(e->differences, &tbl[0], sizeof(char*)*256);
            // parse differences array and merge with pre defined encodings
            for (i = 0; i < o->value.a.len;)
            {
                pdf_obj dd = o->value.a.items[i];
                int j = dd.value.i;
                if (j < 256)
                {
                    i++;
                    while (obj_is_name(&o->value.a.items[i]))
                    {
                        const struct glyphlist *gl = glyph_name_to_uni(o->value.a.items[i].value.k, strlen(o->value.a.items[i].value.k));
                        if (gl)
                            e->differences[j] = gl->name;
                        if (i++ >= o->value.a.len)
                            break;
                        if (j++ > 255)
                            break;
                    }
                }
			
            }
	    }
    }
    e->get_cid = get_cid_simple;
}

void
pdf_cid_encoding_load(pdf_obj *a, pdf_font_encoding* e)
{
    char *enc = 0;
    pdf_obj *o;
    if (!a)
        return;
    if ((enc = pdf_to_name(a)))
    {
	    if (strncmp(a->value.k, "Identity-H", sizeof("Identity-H")) == 0)
	    {
            e->get_cid = get_cid_identity;
            e->type = Identity_H;
	    }
	    else if (strncmp(a->value.k, "Identity-V", sizeof("Identity-V")) == 0)
	    {
            e->get_cid = get_cid_identity;
            e->type = Identity_V;
	    }
	    else
	    {
            // TODO: load known Adobe cmaps
            e->get_cid = get_cid_identity;
            e->type = Identity_H;
	    }
    }
    else if ((o = pdf_to_dict(a)))
    {
	    // todo
    }
}

pdf_font_descriptor *
pdf_font_descriptor_load(pdf_obj *a)
{
    int flags = 0;
    pdf_obj *fontname;
    pdf_font_descriptor *d;
    pdf_obj *val;

    if (!a)
	    return 0;

    val = pdf_dict_get(a, "Flags");
    if (!val) {
	    return 0;
    }

    flags = pdf_to_int(val);
    fontname = pdf_dict_get(a, "FontName");
    if (!fontname)
    {
	    return 0;
    }
    // load
    d = (pdf_font_descriptor*)pdf_malloc(sizeof(pdf_font_descriptor));
    if (!d)
    {
	    return 0;
    }
    memset(d, 0, sizeof(pdf_font_descriptor));
    d->flags = flags;
    //
    d->fontname[0] = 0;
    if (obj_is_name(fontname))
    {
	    strncpy(d->fontname, fontname->value.k, strlen(fontname->value.k)<256?strlen(fontname->value.k):256);
	    if (strstr(d->fontname, "Monaco"))
	    {
            d->fontname_id = eMonaco;
	    }
	    else if (strstr(d->fontname, "Times"))
	    {
            d->fontname_id = eTimes;
	    }
	    else if (strstr(d->fontname, "Helvetica"))
	    {
            d->fontname_id = eHelvetica;
	    }
	    else if (strstr(d->fontname, "Courier"))
	    {
            d->fontname_id = eCourier;
	    }
	    else if (strstr(d->fontname, "Arial"))
	    {
            d->fontname_id = eArial;
	    }
	    else if (strstr(d->fontname, "Sans"))
	    {
            d->fontname_id = eArial;
	    }
	    else
	    {
            d->fontname_id = eNoFontName;
	    }
    }
    return d;
}

pdf_font *
pdf_font_load(pdf_obj *o, int cid2uni, pdfcrypto_priv* encrypt)
{
    pdf_font *f;
    pdf_obj *a;
    int ref = -1;
    int gen = 0;
    char *type;

    if (!o) return 0;

    if (o && o->t == eRef) {
	    ref = o->value.r.num;
        gen = o->value.r.gen;
    }

    f = pdf_malloc(sizeof(pdf_font));
    if (!f)
	    return 0;
    f->ref = ref;
    f->next = NULL;
    type = pdf_to_name(pdf_dict_get(o, "Subtype"));
    if (type)
    {
	    // Simple font types
	    if (strncmp(type, "TrueType", 8) == 0)
	    {
            f->type = TrueType;
	    }
	    else if (strncmp(type, "CIDFontType0", 5) == 0)
	    {
            f->type = CIDFontType0;
	    }
	    else if (strncmp(type, "CIDFontType2", 5) == 0)
	    {
            f->type = CIDFontType2;
	    }
	    else if (strncmp(type, "Type3", 5) == 0)
	    {
            f->type = Type3;
	    }
	    // Composite font types
	    else if (strncmp(type, "Type0", 5) == 0)
	    {
            f->type = Type0;
	    }
	    else if (strncmp(type, "Type1", 5) == 0)
	    {
            f->type = Type1;
	    }
	    else if (strncmp(type, "Type2", 5) == 0)
	    {
            f->type = Type2;
	    }
	    else
	    {
            pdf_free(f);
            return 0;
	    }
    }
    // encoding
    f->encoding = pdf_malloc(sizeof(pdf_font_encoding));
    if (!f->encoding)
	    goto fail;
    memset(f->encoding, 0, sizeof(pdf_font_encoding));
    a = pdf_dict_get(o, "Encoding");
    if ((f->type == Type0) || (f->type == Type2))
    {
        pdf_cid_encoding_load(a, f->encoding);
	    f->widths = 0;
    }
    else
    { // simple font
        pdf_encoding_load(a, f->encoding);
	    pdf_font_widths_load(o, f);
    }
    // composite font specific
    if ((f->type == Type0) || (f->type == Type2))
    { // CID fonts
	    //
	    if (f->type == CIDFontType0)
	    {
            a = pdf_dict_get(o, "DescendantFonts");
            if (!a)
                goto fail;
	    }
#if 0
	    a = pdf_dict_get(o, "CIDSystemInfo");
	    if (!a)
            goto fail;
#endif
    }
    else if (f->type == TrueType)
    {
    }
    else if (f->type == Type1)
    {
    }
    else if (f->type == Type3)
    {
    }
    // CidToUnicode
    f->unicode_get = unicode_get_stub;
    f->tounicode = 0;
    if (cid2uni)
    {
	    a = pdf_dict_get(o, "ToUnicode");
	    if (a)
	    {
            pdf_cmap_tounicode_parse(a, f, encrypt);
	    }
	    else
	    {
            if (f->type == TrueType || f->type == Type1 || f->type == Type3)
            {
                f->unicode_get = unicode_get_simple;
            }
            else
            {
                // composite font
            }
	    }
    }
    // FontDescriptor
    a = pdf_dict_get(o, "FontDescriptor");
    if (a)
    {
	    f->fontdescriptor = pdf_font_descriptor_load(a);
    }
    else
    {
	    f->fontdescriptor = 0;
    }
    return f;
  fail:
    if (f)
	    pdf_free(f);
    return 0;
}

void
pdf_font_free(pdf_font *f)
{
    if (f)
    {
	    while (f)
	    {
            pdf_font *next = f->next;
            if (f->widths)
            {
                pdf_free(f->widths);
            }
            if (f->encoding)
            {
                pdf_encoding_free(f->encoding);
            }
            if (f->tounicode)
            {
                pdf_tounicode_free(f->tounicode);
                f->tounicode = 0;
            }
            if (f->fontdescriptor)
            {
                pdf_free(f->fontdescriptor);
            }
            pdf_free(f);
            f = next;
	    }
    }
}

pdf_font*
pdf_font_find(pdf_font* f, int ref)
{
    if (!f)
	    return 0;
    while (f)
    {
	    if (f->ref == ref)
            return f;
	    f = f->next;
    }
    return 0;
}

int
pdf_character_show(pdf_device* dev, pdf_prs *s, pdf_font *f, gs_matrix *ctm, unsigned char *c, u32 *c_id)
{
    unsigned int cid;
    pdf_font_encoding *enc;
    int step;

    if (!f || !f->encoding)
	    return 0;
    enc = f->encoding;
    step = (enc->get_cid)(c, &cid);
    *c_id = cid;
    pdf_device_char_show(dev, f, s->gs.fs, ctm, cid);
    if (step == 1)
    {
#ifdef DEBUG
        unsigned char uni[8];
	    (f->unicode_get)(f, cid, uni);
	    fputc(uni[0]>>8, stdout);
	    fputc(uni[0]&0xff, stdout);
#endif
    }
    else if (step == 4)
    {
#ifdef DEBUG
        unsigned char uni[8];
	    int n = (f->unicode_get)(f, cid, uni);
	    int i;
	    for (i = 0; i < n; i++)
	    {
            fputc(uni[i]&0xff, stdout);
	    }
#endif
    }
    return step;
}

int
pdf_font_tounicode(pdf_font *f, unsigned int cid, unsigned char *uni)
{
    if (f && f->unicode_get)
	    return (f->unicode_get)(f, cid, uni);
    *uni = cid&0xff;
    return 1;
}

int
pdf_font_flags_get(pdf_font *f)
{
    if (!f || !(f->fontdescriptor))
    {
	    return 0;
    }
    return f->fontdescriptor->flags;
}

char *
pdf_font_basefont_get(pdf_font *f)
{
    if (!f || !(f->fontdescriptor))
    {
	    return 0;
    }
    return f->fontdescriptor->fontname;
}
extern fontname_id pdf_font_basefont_id_get(pdf_font *f)
{
    if (!f || !(f->fontdescriptor))
    {
	    return 0;
    }
    return f->fontdescriptor->fontname_id;
}
