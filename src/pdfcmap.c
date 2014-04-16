#include <stdio.h>
#include <ctype.h>
#define _GNU_SOURCE
#ifdef _WIN32
/* to expose tree structure */
#define _SEARCH_PRIVATE
#endif
#include <search.h>
#include "pdftypes.h"
#include "pdfindex.h"
#include "pdfread.h"
#include "pdffilter.h"
#include "pdfdoc.h"
#include "pdffont.h"
#include "pdfcmap.h"

extern int EncodeCharToUTF8Bytes( unsigned int c, unsigned char * encodebuf, int* count );

typedef enum pdf_cmap_token_type_e pdf_cmap_token_type;
enum pdf_cmap_token_type_e
{
    eCOMMENT,
    eKEYWORD,
    eNUMSTR,
    eHEXSTR,
    eARRAY,
    eNAME,
    eDICT,
    eNONE
};


typedef struct cmap_range_entry_s cmap_range_entry;
typedef struct cmap_range_node_s cmap_range_node;

struct cmap_range_entry_s
{
    int low, hi;
};


struct cmap_range_node_s
{
    int offset;
    int n;

    union
    {
        cmap_range_entry *entry;
        cmap_range_node  *node;
    } *childen;

};





pdf_cmap_token_type
pdf_cmap_lex(pdf_stream *s, unsigned char *tokenbuf)
{
    unsigned char c;
    pdf_cmap_token_type t = eNONE;

    while ((s->ffilter->read)(s->ffilter, &c, 1))
    {
	    if (isspace(c))
            continue;
	    switch (c)
	    {
            case '%':
                while ((s->ffilter->read)(s->ffilter, &c, 1))
                {
                    if (c == '\r' || c == '\n')
                        break;
                }
                break;
            case '<':
                if ((s->ffilter->read)(s->ffilter, &c, 1))
                {
                    if (c == '<')
                    {
                        t = eDICT;
                    }
                    else if (isxdigit(c))
                    {
                        *tokenbuf++ = c;
                        while ((s->ffilter->read)(s->ffilter, &c, 1))
                        {
                            if (c == '>')
                                break;
                            else
                                *tokenbuf++ = c;
                        }
                        *tokenbuf = 0;
                        t = eHEXSTR;
                    }
                }
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                *tokenbuf++ = c;
                while ((s->ffilter->read)(s->ffilter, &c, 1))
                {
                    if (isspace(c))
                        break;
                    else
                        *tokenbuf++ = c;
                }
                *tokenbuf = 0;
                t = eNUMSTR;
                break;
            case '[':
                t = eARRAY;
                break;
            case '/':
                while ((s->ffilter->read)(s->ffilter, &c, 1))
                {
                    if (isspace(c))
                        break;
                    else
                        *tokenbuf++ = c;
                }
                t = eNAME;
                break;
            default:
                *tokenbuf++ = c;
                while ((s->ffilter->read)(s->ffilter, &c, 1))
                {
                    if (isspace(c))
                        break;
                    else
                        *tokenbuf++ = c;
                }
                t = eKEYWORD;
                break;
	    }
	    break;
    }
    *tokenbuf = 0;
    return t;
}

static int
cmap_touni_cmp(const void *pa, const void *pb)
{
    pdf_tounicode* a = (pdf_tounicode*) pa;
    pdf_tounicode* b = (pdf_tounicode*) pb;
    if (a->cid < b->cid)
	    return -1;
    else if ( a->cid >= b->cid+b->n)
	    return 1;
    else
	    return 0;
}

/*
 * For base font cid mapping
 */
void
pdf_cmap_bfchar_parse(pdf_stream *s, int n, pdf_font *f)
{
    char tokenbuf[1024];
    pdf_cmap_token_type tok;

    while ((tok = pdf_cmap_lex(s, tokenbuf)) != eNONE)
    {
	    if (tok == eHEXSTR)
	    {
            unsigned int cid = asciihex2int(tokenbuf);
            if ((tok = pdf_cmap_lex(s, tokenbuf)) == eHEXSTR)
            {
                void *v;
                pdf_tounicode *touni = (pdf_tounicode*) pdf_malloc(sizeof(pdf_tounicode));
                if (touni)
                {
                    touni->cid = cid;
                    touni->n = 1;
                    touni->hex = pdf_malloc(strlen(tokenbuf)+1); // plus one to terminate string
                    memcpy(touni->hex, tokenbuf, strlen(tokenbuf)+1);
                    v = tsearch(touni, &f->tounicode, cmap_touni_cmp);
                }
            }
	    }
	    else if (tok == eKEYWORD &&
                 strcmp(tokenbuf, "endbfchar") == 0)
            break;
    }
}

/*
 * For base font cid mapping
 */
void
pdf_cmap_bfrange_parse(pdf_stream *s, int n, pdf_font *f)
{
    char tokenbuf[1024];
    pdf_cmap_token_type tok;
    void *v;

    while ((tok = pdf_cmap_lex(s, tokenbuf)) != eNONE)
    {
	    if (tok == eHEXSTR)
	    {
            unsigned int from_cid = asciihex2int(tokenbuf);
            unsigned int to_cid;
            if ((tok = pdf_cmap_lex(s, tokenbuf)) == eHEXSTR)
            {
                to_cid = asciihex2int(tokenbuf);
                tok = pdf_cmap_lex(s, tokenbuf);
                if (tok == eHEXSTR)
                {
                    pdf_tounicode *touni = (pdf_tounicode*) pdf_malloc(sizeof(pdf_tounicode));
                    if (touni)
                    {
                        touni->cid = from_cid;
                        touni->n = to_cid - from_cid + 1;
                        touni->hex = pdf_malloc(strlen(tokenbuf)+1);
                        memcpy(touni->hex, tokenbuf, strlen(tokenbuf)+1);
                        v = tsearch(touni, &f->tounicode, cmap_touni_cmp);
                    }
                }
                else if (tok = eARRAY)
                {
                    int i, n;
                    n = to_cid - from_cid;
                    for (i = 0; i < to_cid - from_cid; i++)
                    {
                        pdf_tounicode *touni = (pdf_tounicode*) pdf_malloc(sizeof(pdf_tounicode));
                        touni->cid = from_cid;
                        touni->n = to_cid - from_cid;
                        if ((tok = pdf_cmap_lex(s, tokenbuf)) == eHEXSTR)
                        {
                            touni->hex = pdf_malloc(strlen(tokenbuf)+1);
                            memcpy(touni->hex, tokenbuf, strlen(tokenbuf)+1);
                            v = tsearch(touni, &f->tounicode, cmap_touni_cmp);
                        }
                    }
                }
            }
	    }
	    else if (tok == eKEYWORD &&
                 strcmp(tokenbuf, "endbfrange") == 0)
            break;
    }
}

static void
cmap_skip_dict(pdf_stream *s)
{
    unsigned char c;
    while ((s->ffilter->read)(s->ffilter, &c, 1))
    {
	    if (c == '>')
	    {
            if ((s->ffilter->read)(s->ffilter, &c, 1) && c == '>')
                return;
	    }
    }
}

void
pdf_cmap_tounicode_parse(pdf_obj *cmap, pdf_font *f, pdfcrypto_priv* encrypt)
{
    pdf_err e;
    pdf_stream *s;
    char tokenbuf[1024];
    pdf_cmap_token_type tok, pre_tok = eNONE;
    int num;

    if (!cmap)
	    return;
    if (cmap->t != eRef)
	    return;
    e = pdf_istream_filtered_load(cmap, encrypt, cmap->value.r.num, cmap->value.r.gen, &s);
    if (!s)
	    return;
    f->tounicode = 0;
    while ((tok = pdf_cmap_lex(s, tokenbuf)) != eNONE)
    {
	    switch (tok)
	    {
            case eDICT:
                cmap_skip_dict(s);
                break;
            case eKEYWORD:
                if (strcmp(tokenbuf, "beginbfchar") == 0)
                {
                    if (pre_tok == eNUMSTR && num)
                        pdf_cmap_bfchar_parse(s, num, f);
                }
                else if (strcmp(tokenbuf, "beginbfrange") == 0)
                {
                    if (pre_tok == eNUMSTR && num)
                        pdf_cmap_bfrange_parse(s, num, f);
                }
                break;
            case eNUMSTR:
                num = atoi(tokenbuf);
                break;
            default:
                break;
	    }
	    pre_tok = tok;
    }
    f->unicode_get = unicode_get_cmap;
    pdf_stream_free(s, 1);
}

int
unicode_get_cmap(pdf_font *f, unsigned int c, unsigned char *uni)
{
    pdf_tounicode u;
    void *val;
    if (!f->tounicode)
    {
	    *uni = c;
	    return 1;
    }
    u.cid = c;
    val = tfind(&u, &f->tounicode, cmap_touni_cmp);
    if (val)
    {
	    int i;
	    pdf_tounicode **vv = (pdf_tounicode **)val;
	    pdf_tounicode *v = *vv;
	    for (i = 0; i < v->n; i++)
	    {
            if (c == v->cid + i)
                break;
	    }
	    if (i == v->n)
	    {
            return 0;
	    }
	    else
	    {
            int cnt;
            char *p = v->hex;
            unsigned int u = asciihex2int(p);
            u += i;
            if (EncodeCharToUTF8Bytes(u, uni, &cnt) == 0)
                return cnt;
            else
                return 0;
	    }
    }
    else
    {
	    return 0;
    }
}

static void
tounicode_free(void *v)
{
    pdf_tounicode* a = (pdf_tounicode*) v;
    if (a->hex)
	    pdf_free(a->hex);
    pdf_free(a);
}

#if defined(_WIN32)
#if !defined (_MSC_VER)
typedef struct __node_s
{
	struct __node_s *llink, *rlink;
	void *key;

} node_t;
#endif

/* Because minGW is strictly POSIX */
static void
tdestroy_recurse(node_t* root, void (*free_node)(void *))
{
  if (root->llink != NULL)
    tdestroy_recurse(root->llink, free_node);
  if (root->rlink != NULL)
    tdestroy_recurse(root->rlink, free_node);

  (*free_node)((void *)root->key);
  /* Free the node */
  free(root);
}

void
tdestroy(void *root, void(*free_node)(void *nodep))
{

  if (root)
    tdestroy_recurse(root, free_node);
}
#endif

void
pdf_tounicode_free(pdf_tounicode *u)
{
    if (u)
    {
	    tdestroy(u, tounicode_free);
    }
}

typedef enum
{
    no,
    yes
} Bool;
#define kNumUTF8Sequences        7
#define kMaxUTF8Bytes            4

#define kUTF8ByteSwapNotAChar    0xFFFE
#define kUTF8NotAChar            0xFFFF

#define kMaxUTF8FromUCS4         0x10FFFF

#define kUTF16SurrogatesBegin    0x10000
#define kMaxUTF16FromUCS4        0x10FFFF

/* UTF-16 surrogate pair areas */
#define kUTF16LowSurrogateBegin  0xD800
#define kUTF16LowSurrogateEnd    0xDBFF
#define kUTF16HighSurrogateBegin 0xDC00
#define kUTF16HighSurrogateEnd   0xDFFF

int EncodeCharToUTF8Bytes( unsigned int c, unsigned char * encodebuf, int* count )
{
    byte tempbuf[10] = {0};
    byte* buf = &tempbuf[0];
    int bytes = 0;
    Bool hasError = no;

    if ( encodebuf )
        buf = (byte*) encodebuf;

    if (c <= 0x7F)  /* 0XXX XXXX one byte */
    {
        buf[0] = (byte) c;
        bytes = 1;
    }
    else if (c <= 0x7FF)  /* 110X XXXX  two bytes */
    {
        buf[0] = (byte) ( 0xC0 | (c >> 6) );
        buf[1] = (byte) ( 0x80 | (c & 0x3F) );
        bytes = 2;
    }
    else if (c <= 0xFFFF)  /* 1110 XXXX  three bytes */
    {
        buf[0] = (byte) (0xE0 | (c >> 12));
        buf[1] = (byte) (0x80 | ((c >> 6) & 0x3F));
        buf[2] = (byte) (0x80 | (c & 0x3F));
        bytes = 3;
        if ( c == kUTF8ByteSwapNotAChar || c == kUTF8NotAChar )
            hasError = yes;
#if 0 /* Breaks Big5 D8 - DF */
        else if ( c >= kUTF16LowSurrogateBegin && c <= kUTF16HighSurrogateEnd )
            /* unpaired surrogates not allowed */
            hasError = yes;
#endif
    }
    else if (c <= 0x1FFFFF)  /* 1111 0XXX  four bytes */
    {
        buf[0] = (byte) (0xF0 | (c >> 18));
        buf[1] = (byte) (0x80 | ((c >> 12) & 0x3F));
        buf[2] = (byte) (0x80 | ((c >> 6) & 0x3F));
        buf[3] = (byte) (0x80 | (c & 0x3F));
        bytes = 4;
        if (c > kMaxUTF8FromUCS4)
            hasError = yes;
    }
    else if (c <= 0x3FFFFFF)  /* 1111 10XX  five bytes */
    {
        buf[0] = (byte) (0xF8 | (c >> 24));
        buf[1] = (byte) (0x80 | (c >> 18));
        buf[2] = (byte) (0x80 | ((c >> 12) & 0x3F));
        buf[3] = (byte) (0x80 | ((c >> 6) & 0x3F));
        buf[4] = (byte) (0x80 | (c & 0x3F));
        bytes = 5;
        hasError = yes;
    }
    else if (c <= 0x7FFFFFFF)  /* 1111 110X  six bytes */
    {
        buf[0] = (byte) (0xFC | (c >> 30));
        buf[1] = (byte) (0x80 | ((c >> 24) & 0x3F));
        buf[2] = (byte) (0x80 | ((c >> 18) & 0x3F));
        buf[3] = (byte) (0x80 | ((c >> 12) & 0x3F));
        buf[4] = (byte) (0x80 | ((c >> 6) & 0x3F));
        buf[5] = (byte) (0x80 | (c & 0x3F));
        bytes = 6;
        hasError = yes;
    }
    else
        hasError = yes;


#if 1 && defined(_DEBUG)
    if ( hasError )
    {
        int i;
        fprintf( stderr, "UTF-8 encoding error for U+%x : ", c );
        for (i = 0; i < bytes; i++)
            fprintf( stderr, "0x%02x ", buf[i] );
        fprintf( stderr, "\n" );
    }
#endif

    *count = bytes;
    if (hasError)
        return -1;
    return 0;
}
