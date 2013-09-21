#include <sys/stat.h>
#include <sys/types.h>
#ifdef __unix__
#include <unistd.h>
#endif
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "bplustree.h"
#include "dict.h"
#include "pdf.h"
#include "pdffilter.h"
#include "pdfindex.h"
#include "pdfdoc.h"
#include "pdfread.h"

#define MARK_BLACK -1
#define MARK_GRAY  -2
// We borrow the term "Mark&Sweep" as 2 stages
// in #1.scanning pdf object for writing, stored in a tree structure and
// #2. Sweep the tree, and re-generate ref-ids and stream offsets.

typedef struct pdf_xref_internal_s pdf_xref_internal;
typedef struct pdf_xref_table_s pdf_xref_table;

struct pdf_xref_internal_s
{
    int n;
    int gen;
    int cur_idx;
    bpt_tree *entry; // storing scanned objects
    pdf_xref_table *xref;
    int page_obj_idx;
    int *page_obj_buf;
    int *page_ref_buf;
};

// pdf_xref_table stores the artifects of object writing. to be written out as new xref table.
struct pdf_xref_table_s
{
    int n; // total number of entries
    int cur; // index to current entry
    int *offsets;
};

static void pdf_obj_write(pdf_obj* o, pdf_xref_internal *x, FILE *f, pdfcrypto_priv *crypto);
static void pdf_key_write(const char *k, pdf_xref_internal *x, FILE *f, pdfcrypto_priv *crypto);
static void pdf_obj_full_write(pdf_obj *o, int n, int g, pdf_xref_internal *x, FILE *f, pdfcrypto_priv *crypto);
static void pdf_obj_scan(pdf_obj *o, pdf_xref_internal *x);
static void pdf_indirect_objs_write(pdf_xref_internal *xref, FILE *out, pdfcrypto_priv *crypto);

static const char escape_chart[256] =
{
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

static inline int
is_escapable(unsigned int c)
{
    return escape_chart[c];
}
static
pdf_xref_internal*
pdf_xref_internal_create(int n, int npages)
{
    pdf_xref_internal* x;
    if (!n)
        return NULL;
    n ++;
    x = pdf_malloc(sizeof(pdf_xref_internal));
    memset(x, 0, sizeof(pdf_xref_internal));
    x->n = 0;
    x->entry = bpt_new_tree(0);
    // make xref table
    x->xref = pdf_malloc(sizeof(pdf_xref_table));
    x->xref->n = n;
    x->xref->cur = 1;
    x->page_obj_buf = pdf_malloc(sizeof(int)*(n));
    // +2 for /catalog and /trailer
    // npage*2 for new page objs and page content objs
    x->xref->offsets = pdf_malloc(sizeof(int)*(n+2+npages*2));
    x->page_ref_buf = pdf_malloc(sizeof(int)*npages);
    return x;
}

static
void
pdf_xref_internal_free(pdf_xref_internal *x)
{
    if (!x)
        return;
    if (x->entry)
    {
        bpt_node_free(x->entry->root);
        pdf_free(x->entry);
    }
    if (x->xref->offsets)
    {
        pdf_free(x->xref->offsets);
        pdf_free(x->xref);
    }
    if (x->page_ref_buf)
	    pdf_free(x->page_ref_buf);
    if (x->page_obj_buf)
	    pdf_free(x->page_obj_buf);

    pdf_free(x);
}

static
pdf_xref_internal *
pdf_xref_internal_append(pdf_xref_internal *x, int n, int g, int color)
{
    // ignore generation number for now.
    int a;
    a = (int)bpt_search(x->entry, n);
    if (a == 0 || a == MARK_GRAY || a == MARK_BLACK)
    {
        if (a == 0 || a == MARK_GRAY)
            bpt_insert(x->entry, n, (void*)color);
        if (a == MARK_GRAY && color == MARK_BLACK)
        {
            x->n += 1;
            x->page_obj_buf[x->page_obj_idx] = n;
            x->page_obj_idx ++;
        }

    }
    return x;
}

static
void
pdf_xref_insert_indirect(pdf_xref_internal *x, pdf_obj *o)
{
    pdf_obj *d;
    if (!o || o->t != eRef)
        return;
    d = pdf_obj_deref(o);
    if (!d)
        return;
    pdf_xref_internal_append(x, o->value.r.num, o->value.r.gen, MARK_GRAY);
    pdf_obj_scan(d, x);
    pdf_xref_internal_append(x, o->value.r.num, o->value.r.gen, MARK_BLACK);
}

static
void
pdf_catalog_write(pdf_doc *doc, pdf_xref_internal *x, FILE *o, pdfcrypto_priv *decrypto, unsigned long flags)
{
    pdf_obj tmp;
    dict *d = dict_new(11);

    if (!d)
        return;
    tmp.t = eDict;
    tmp.value.d.dict = d;

    x->xref->cur = 3;

    bpt_insert(x->entry, doc->root_ref, 2);
    bpt_insert(x->entry, 2, 2);
    bpt_insert(x->entry, 1, 1);
    if (doc->pages_ref)
        bpt_insert(x->entry, doc->pages_ref, 1);

    if (doc->ocproperties && (flags & WRITE_CATALOG_OCPROPERTIES))
    {
        pdf_obj_scan(doc->ocproperties->ocgs, x);
    }
    if (doc->metadata && doc->metadata->t == eRef && (flags & WRITE_CATALOG_METADATA))
    {
        pdf_obj_scan(doc->metadata, x);
    }
    if (doc->markinfo && (flags & WRITE_CATALOG_MARKINFO))
    {
        pdf_obj_scan(doc->markinfo, x);
    }
    if (doc->names && (flags & WRITE_CATALOG_NAMES))
    {
        pdf_obj_scan(doc->names, x);
    }
    if (doc->outlines && (flags & WRITE_CATALOG_OUTLINES))
    {
        pdf_obj_scan(doc->outlines, x);
    }
    if (doc->pagelabels && (flags & WRITE_CATALOG_PAGELABELS))
    {
        pdf_obj_scan(doc->pagelabels, x);
    }
    if (doc->pieceinfo && (flags & WRITE_CATALOG_PIECEINFO))
    {
        pdf_obj_scan(doc->pieceinfo, x);
    }
    if (doc->structtreeroot && (flags & WRITE_CATALOG_STRUCTTREEROOT))
    {
        pdf_obj_scan(doc->structtreeroot, x);
    }
    pdf_indirect_objs_write(x, o, decrypto);
    x->xref->offsets[2] = ftell(o);
    // new catalog dictionary
    pdf_dict_insert_name(d, "Type", "Catalog");
    pdf_dict_insert_ref(d, "Pages", 1, 0);
    if (doc->pagemode)
    {
        dict_insert(d, "PageMode", doc->pagemode);
    }
    if (doc->pagelayout)
    {
        dict_insert(d, "PageLayout", doc->pagelayout);
    }
    if (doc->structtreeroot && (flags & WRITE_CATALOG_STRUCTTREEROOT))
    {
        dict_insert(d, "StructTreeRoot", doc->structtreeroot);
    }
    if (doc->pieceinfo && (flags & WRITE_CATALOG_PIECEINFO))
    {
        dict_insert(d, "PieceInfo", doc->pieceinfo);
    }
    if (doc->pagelabels && (flags & WRITE_CATALOG_PAGELABELS))
    {
        dict_insert(d, "PageLabels", doc->pagelabels);
    }
    if (doc->outlines && (flags & WRITE_CATALOG_OUTLINES))
    {
        dict_insert(d, "Outlines", doc->outlines);
    }
    if (doc->names && (flags & WRITE_CATALOG_NAMES))
    {
        dict_insert(d, "Names", doc->names);
    }
    if (doc->markinfo && (flags & WRITE_CATALOG_MARKINFO))
    {
        dict_insert(d, "MarkInfo", doc->markinfo);
    }
    if (doc->metadata && doc->metadata->t == eRef && (flags & WRITE_CATALOG_METADATA))
    {
        dict_insert(d, "Metadata", doc->metadata);
    }
    if (doc->ocproperties && (flags & WRITE_CATALOG_OCPROPERTIES))
    {
        dict_insert(d, "OCProperties", doc->ocproperties);
    }
    pdf_obj_full_write(&tmp, 2, 0, x, o, decrypto);
}

static
void
pdf_pages_obj_write(pdf_xref_internal *x, num_range *page_ranges, int nr, FILE *o)
{
    int i, j, n = 0;
    pdf_obj tmp, *pages;
    dict *d = dict_new(2);
    if (!d)
        return;

    x->xref->offsets[1] = ftell(o);

    tmp.t = eDict;
    tmp.value.d.dict = d;
    pdf_dict_insert_name(d, "Type", "Pages");
    n = 0;
    for (i = 0; i < nr; i++)
    {
        n += (page_ranges[i].end - page_ranges[i].bgn + 1);
    }
    pdf_dict_insert_int(d, "Count", n);
    pages = pdf_array_build(n);
    if (!pages)
    {
        return;
    }
    for (j = 0; j < nr; j++)
    {
        int pg1st = page_ranges[j].bgn - 1;
        int pglast = page_ranges[j].end - 1;
        if (pg1st < 0)
            pg1st = 0;
        for (i = pg1st; i <= pglast; i++)
        {
            pages->value.a.items[i-pg1st] = pdf_ref_to_obj(x->page_ref_buf[i], 0);
        }
    }
    dict_insert(d, "Kids", pages);
    pdf_obj_full_write(&tmp, 1, 0, x, o, 0);
}

static
int
pdf_xref_write(pdf_xref_internal *x, FILE *o)
{
    int i, startxref;
    startxref = ftell(o);
    fputs("\nxref\n", o);
    fprintf(o, "%d %d\n", 0, x->xref->cur);
    fprintf(o, "%010d %05d f \n", 0, 65535);
    for (i = 1; i < x->xref->cur; i++)
    {
        fprintf(o, "%010d %05d n \n", x->xref->offsets[i], 0);
    }
    return startxref;
}

static
void
pdf_trailer_write(pdf_xref_internal *x, int startxref, FILE *o)
{
    pdf_obj tmp;
    dict *d = dict_new(2);
    if (!d)
        return;
    tmp.t = eDict;
    tmp.value.d.dict = d;
    pdf_dict_insert_int(d, "Size", x->xref->cur);
    pdf_dict_insert_ref(d, "Root", 2, 0);
    fputs("trailer\n", o);
    pdf_obj_write(&tmp, x, o, 0);
    fputs("startxref\n", o);
    fprintf(o,  "%d\n", startxref);
    fputs("%%EOF", o);
    dict_free(d);
}

static void
pdf_obj_write(pdf_obj* o, pdf_xref_internal *x, FILE *f, pdfcrypto_priv *decrypto)
{
    int i;
    if (!o)
        return;
    switch (o->t)
    {
        case eBool:
            fputc(' ', f);
            fputs(o->value.b?"true":"false", f);
            break;
        case eInt:
            fputc(' ', f);
            fprintf(f, "%d ", o->value.i);
            break;
        case eReal:
            fputc(' ', f);
            fprintf(f, "%f ", o->value.f);
            break;
        case eKey:
            fprintf(f, "/%s ", o->value.k);
            break;
        case eName:
        {
            unsigned char *p = o->value.k;
            fputc('/', f);
            while (*p)
            {
                if (is_escapable(*p))
                {
                    char buf[3];
                    sprintf(buf, "%02X", *p);
                    fputc('#', f);
                    fputc(buf[0], f);
                    fputc(buf[1], f);
                }
                else
                {
                    fputc(*p, f);
                }
                p++;
            }
            break;
        }
        case eString:
            fputs("(", f);
            if (decrypto)
            {
                pdf_stream *s = pdf_stream_load(o, decrypto, x->page_obj_buf[x->cur_idx], 0);
                if (s)
                {
                    int c;
                    while ((c = pdf_stream_getchar(s)) != EOF)
                        fputc(c, f);
                    pdf_stream_free(s, 1);
                }
            }
            else
            {
                for (i = 0; i < o->value.s.len; i ++)
                {
                    switch(o->value.s.buf[i])
                    {
                        case ')':
                        case '(':
                            //case '\n':
                            //case '\r':
                        case '\\':
                            fprintf(f, "%c%c", '\\', o->value.s.buf[i]);
                        break;
                        default:
                            fprintf(f, "%c", o->value.s.buf[i]);
                            break;
                    }
                }
            }
            fputc(')', f);
            break;
	    case eHexString:
            fputs("\n<", f);
            if (decrypto)
            {
                pdf_stream *s = pdf_stream_load(o, decrypto, x->page_obj_buf[x->cur_idx], 0);
                if (s)
                {
                    int c;
                    while ((c = pdf_stream_getchar(s)) != EOF)
                    {
                        fprintf(f, "%02X", (byte)c);
                    }
                    pdf_stream_free(s, 1);
                }
            }
            else
            {
                for (i = 0; i < o->value.s.len; i ++)
                {
                    fprintf(f, "%02X", (byte)(o->value.s.buf[i]));
                    if ((i+1)%32==0) fputc('\n', f);
                }
            }
            fputs("> ", f);
            break;
        case eDict:
        {
            dict_list *ll, *l = dict_to_list(o->value.d.dict);
            sub_stream *strm = o->value.d.dict->stream;
            int strmlen = 0;
            int last_off = 0;
            ll = l;
            fputs("<<", f);
            while (l && l->key)
            {
                if (strcmp(l->key, "Length")==0)
                {
                    if (l->val.t == eRef)
                    {
                        pdf_obj *ooo = &l->val;
                        pdf_obj_resolve(ooo);
                        if (ooo->t == eInt)
                        {
                            strmlen = ooo->value.i;
                        }
                    }
                    else
                    {
                        strmlen = l->val.value.i;
                    }
                    if (decrypto)
                    {
                        fprintf(f, "/Length %s\n", "           ");
                        last_off = ftell(f) - 11;
                    }
                    else
                    {
                        fprintf(f, "/Length %d\n", strmlen);
                    }
                    l = l->next;
                    continue;
                }
                else if (strcmp(l->key, "Filter")==0)
                {
                    if (l->val.t == eKey && strcmp(l->val.value.k, "DCTDecode") == 0)
                    {
                        // not to decode DCT filter
                    }
                    else
                    {
                        // Otherwise, we write plain stream whenever crypto
                        // is present
                        if (decrypto)
                        {
                            l = l->next;
                            continue;
                        }
                    }
                }
                pdf_key_write(l->key, x, f, decrypto);
                pdf_obj_write(&l->val, x, f, decrypto);
                l = l->next;
            }
            fputs(">> ", f);
            if (strm && decrypto)
            {
                int obj, gen;
                pdf_stream *s = NULL;
                sub_stream *ss = (sub_stream*)o->value.d.dict->stream;
                FILE *out = f;

                if (ss)
                {
                    obj = ss->obj;
                    gen = ss->gen;
                }
                s = pdf_stream_load(o, decrypto, obj, gen);
                if (s)
                {
                    int c;
                    int curx;
                    int strmoff;

                    fputs("stream\n", f);
                    strmoff = ftell(out);
                    //
                    while ((c = pdf_stream_getchar(s)) != EOF)
                        fputc(c, out);
                    pdf_stream_free(s, 1);
                    //
                    curx = ftell(out);
                    fseek(out, last_off, SEEK_SET);
                    fprintf(out, "%10d", curx - strmoff);
                    fseek(out, curx, SEEK_SET);
                    fputs("\nendstream", out);
                }
                else
                {
                    // write raw stream
                    goto write_rawstream;
                }
            }
            else if (strm)
            {
                unsigned char c;
              write_rawstream:
                fputs("stream\n", f);
                strm->len = strmlen;
                while (strm->read(strm, &c, 1))
                    fputc(c, f);
                strm->close(strm, 1);
                fputs("\nendstream", f);
            }
            dict_list_free(ll);
        }
        break;
        case eArray:
        {
            int i;
            fputs("[", f);
            for (i = 0; i < o->value.a.len; i++)
            {
                pdf_obj_write(&o->value.a.items[i], x, f, decrypto);
            }
            fputs("]", f);
        }
        break;
        case eRef:
        {
            int a = (int)bpt_search(x->entry, o->value.r.num);
            if (a > 0)
            {
                fprintf(f, " %d %d R ", a, o->value.r.gen);
            }
            else
            {
                fprintf(f, " %d %d R ", -a, 0);
            }
        }
        break;
        default:
            break;
    }
}

static void
pdf_key_write(const char *k, pdf_xref_internal *x, FILE *f, pdfcrypto_priv *crypto)
{
    pdf_obj key;
    key.t = eName;
    key.value.k = k;
    pdf_obj_write(&key, x, f, crypto);
}

static void
pdf_obj_full_write(pdf_obj *o, int n, int g, pdf_xref_internal *x, FILE *f, pdfcrypto_priv *crypto)
{
    fprintf(f, "%d %d obj\n", n, g);
    pdf_obj_write(o, x, f, crypto);
    fputs("\nendobj\n", f);
}

static
int
pdf_page_contents_write(pdf_obj *content, unsigned long write_flag, pdf_xref_internal *xref, FILE *out, pdfcrypto_priv *crypto)
{
    int content_ref = xref->xref->cur;
    int off = ftell(out);
    pdf_obj *cobj = content;

    pdf_obj_resolve(cobj);
    if (cobj->t != eDict)
    {
	    return -1;
    }
    pdf_obj_full_write(cobj, xref->xref->cur, 0, xref, out, crypto);
    xref->xref->offsets[xref->xref->cur] = off;
    xref->xref->cur++;
    return content_ref;
}

static
pdf_obj
pdf_group_write(pdf_group *g, pdf_xref_internal *x, pdfcrypto_priv *crypto)
{
    pdf_obj tmp;
    dict *d;

    if (!g)
        return tmp;
    d = dict_new(3);
    if (!d)
        return tmp;
    tmp.t = eDict;
    tmp.value.d.dict = d;
    if (g->cs)
    {
	    dict_insert(d, "CS", g->cs);
    }
    pdf_dict_insert_int(d, "I", g->i);
    pdf_dict_insert_int(d, "K", g->k);
    return tmp;
}

static
pdf_obj
pdf_resources_write(pdf_resources *r, pdf_xref_internal *x, pdfcrypto_priv *crypto)
{
    pdf_obj tmp;
    dict *d;

    d = dict_new(9);
    if (!d)
        return tmp;
    tmp.t = eDict;
    tmp.value.d.dict = d;

    if (r->extgstate)
    {
	    pdf_obj *extg = r->extgstate;
	    pdf_obj_resolve(extg);
	    if (extg && extg->t == eDict)
	    {
            dict_insert(d, "ExtGState", extg);
        }
    } // extgstate
    if (r->font)
    {
        pdf_obj_resolve(r->font);
        dict_insert(d, "Font", r->font);
    }
    if (r->xobject)
    {
        pdf_obj_resolve(r->xobject);
        dict_insert(d, "XObject", r->xobject);
    }
    if (r->colorspace)
    {
        pdf_obj_resolve(r->colorspace);
        dict_insert(d, "ColorSpace", r->colorspace);
    }
    if (r->shading)
    {
        pdf_obj_resolve(r->shading);
        dict_insert(d, "Shading", r->shading);
    }
    if (r->pattern)
    {
        pdf_obj_resolve(r->pattern);
        dict_insert(d, "Pattern", r->pattern);
    }
    if (r->properties)
    {
        pdf_obj_resolve(r->properties);
        dict_insert(d, "Properties", r->properties);
    }
    // end resources
    return tmp;
}

static
void
pdf_obj_scan(pdf_obj *o, pdf_xref_internal *x)
{
    pdf_obj *obj = o;
    if (!o)
        return;
    switch (o->t)
    {
        case eRef:
	    {
            int a = (int)bpt_search(x->entry, o->value.r.num);
            if (a == 0)
            {
                pdf_xref_insert_indirect(x, o);
            }
            break;
	    }
        case eDict:
        {
            dict_list *ll, *l = dict_to_list(obj->value.d.dict);
            ll = l;
            while (l && l->key)
            {
                if (strcmp(l->key, "Length") == 0)
                {
                    l = l->next;
                    continue;
                }
                if (l->val.t == eRef)
                {
                    int aa = (int)bpt_search(x->entry, l->val.value.r.num);
                    // recursively scan this obj for more refs
                    if (aa == 0) {
                        pdf_xref_insert_indirect(x, &l->val);
                    }
                }
                else if (l->val.t == eArray)
                {
                    pdf_obj_scan(&l->val, x);
                }
                else if (l->val.t == eDict)
                {
                    pdf_obj_scan(&l->val, x);
                }
                l = l->next;
            }
            // free list
            dict_list_free(ll);
        }
        break;
        case eArray:
	    {
            int i;
            pdf_obj *oo;
            for (i = 0; i < obj->value.a.len; i++)
            {
                oo = &obj->value.a.items[i];
                if (oo->t == eRef)
                {
#if 0
                    if (x->page_obj_idx)
                    {
                        int m;
                        for (m = 0; m < x->page_obj_idx; m++)
                        {
                            if (oo->value.r.num == x->page_obj_buf[m])
                                break;
                        }
                        if (m < x->page_obj_idx && (oo->value.r.num == x->page_obj_buf[m]))
                            continue;
                    }
#endif
                    pdf_xref_insert_indirect(x, oo);
                }
                else if (oo->t == eDict || oo->t == eArray)
                {
                    pdf_obj_scan(oo, x);
                }
            }
	    }
	    break;
        default:
            break;
    }
}

static
void
pdf_resources_scan(pdf_resources *r, pdf_xref_internal* x)
{
    if (!r)
        return;
    if (r->extgstate)
    {
        pdf_obj_scan(r->extgstate, x);
    }
    if (r->font)
    {
        pdf_obj_scan(r->font, x);
    }
    if (r->xobject)
    {
	    pdf_obj_scan(r->xobject, x);
    }
    if (r->colorspace)
    {
	    pdf_obj_scan(r->colorspace, x);
    }
    if (r->shading)
    {
	    pdf_obj_scan(r->shading, x);
    }
    if (r->pattern)
    {
	    pdf_obj_scan(r->pattern, x);
    }
    if (r->properties)
    {
	    pdf_obj_scan(r->properties, x);
    }
}

static
void
pdf_page_scan(pdf_page* pg, pdf_xref_internal* x, FILE *o, pdfcrypto_priv *crypto)
{
    if (!pg)
        return;
    x->page_obj_idx = 0;
    pdf_resources_scan(pg->resources, x);
    if (pg->group)
    {
        pdf_obj_scan(pg->group->cs, x);
    }
    pdf_indirect_objs_write(x, o, crypto);
}

// Writing out page content which is an array of references.
static
void
pdf_indirect_objs_write(pdf_xref_internal *xref, FILE *out, pdfcrypto_priv *crypto)
{
    if (xref->page_obj_idx)
    {
        int i;
	    // backward scanning to meet dependency
        for (i = 0; i < xref->page_obj_idx; i++)
        {
            int a = (int)bpt_search(xref->entry, xref->page_obj_buf[i]);
            if (a == MARK_BLACK) // MARK_BLACK means new item in the output tree, need to be flushed out.
            {
                pdf_obj *o = pdf_obj_find(xref->page_obj_buf[i], 0);
                xref->cur_idx = i;
                xref->xref->offsets[xref->xref->cur] = ftell(out);
                // insert negative ref-number to mark back-edge
                bpt_insert(xref->entry, xref->page_obj_buf[i], (void*)-xref->xref->cur);
                // serialize
                pdf_obj_full_write(o, xref->xref->cur, 0, xref, out, crypto);
                // update entry
                bpt_insert(xref->entry, xref->page_obj_buf[i], (void*)xref->xref->cur);
                // inc new xref counter
                xref->xref->cur++;
            }
        }
    }
}

static
void
pdf_page_obj_write(pdf_page *page, int pgidx, unsigned long write_flag, pdf_xref_internal *xref, pdfcrypto_priv *crypto, FILE *out)
{
    int content_ref = -1;
    int content_num = 0;
    int content_ref_arr[1024];
    pdf_obj grp, tmp, *mediabox, resources;
    dict *d;

    if (!page)
        return;
    d = dict_new(11);
    if (!d)
        return;
    tmp.t = eDict;
    tmp.value.d.dict = d;

    if (page->contents)
    {
	    pdf_obj *contents = pdf_obj_deref(page->contents);
	    if (contents->t == eDict)
	    {
            content_ref = pdf_page_contents_write(contents, write_flag, xref, out, crypto);
            bpt_insert(xref->entry, content_ref, content_ref);
	    }
	    else if (contents->t == eArray)
	    {
            int i;
            content_num = contents->value.a.len;
            if (content_num > 1024)
            {
                fprintf(stderr, "!!!Too many content streams on one page, limits to 1024 streams!!!\n");
                content_num = 1024;
            }
            for (i = 0; i < content_num; i++)
            {
                content_ref_arr[i] = pdf_page_contents_write(&contents->value.a.items[i], write_flag, xref, out, crypto);
                bpt_insert(xref->entry, content_ref_arr[i], content_ref_arr[i]);
            }
	    }
    }
    if (content_ref == -1 && content_num == 0)
	    return;
    xref->xref->offsets[xref->xref->cur] = ftell(out);
    bpt_insert(xref->entry, xref->xref->cur, xref->xref->cur);
    xref->page_ref_buf[pgidx] = xref->xref->cur;
    xref->xref->cur++;

    // writing out page obj
    pdf_dict_insert_name(d, "Type", "Page");
    mediabox = pdf_array_build(4);
    mediabox->value.a.items[0] = pdf_float_to_obj(page->mediabox.x0);
    mediabox->value.a.items[1] = pdf_float_to_obj(page->mediabox.y0);
    mediabox->value.a.items[2] = pdf_float_to_obj(page->mediabox.x1);
    mediabox->value.a.items[3] = pdf_float_to_obj(page->mediabox.y1);
    dict_insert(d, "MediaBox", mediabox);
    if (page->resources)
    {
        resources = pdf_resources_write(page->resources, xref, crypto);
        dict_insert(d, "Resources", &resources);
    }
    if (page->group)
    {
        grp = pdf_group_write(page->group, xref, crypto);
        dict_insert(d, "Group", &grp);
    }
    if (content_ref != -1)
    {
        pdf_dict_insert_ref(d, "Contents", content_ref, 0);
    }
    else
    {
	    int i;
        pdf_obj *cont = pdf_array_build(content_num);
	    for (i = 0; i < content_num; i++)
	    {
            cont->value.a.items[i] = pdf_ref_to_obj(content_ref_arr[i], 0);
	    }
        dict_insert(d, "Contents", cont);
    }
    pdf_obj_full_write(&tmp, xref->xref->cur-1, 0, xref, out, crypto);
}

pdf_err
pdf_magic_write(FILE *out, pdf_writer_options *options)
{
    char buf[128];
    if (options)
        sprintf(buf, "%%PDF-%d.%d\n", options->version/10, options->version%10);
    else
        sprintf(buf, "%%PDF-%d.%d\n", 1, 7);

    fputs(buf, out);
    fputs("%\333\332\331\330\n", out);
    return pdf_ok;
}

pdf_err
pdf_page_write(pdf_doc *doc, int i/* pg# */, pdfcrypto_priv *crypto, char *outf, pdf_writer_options *options)
{
    FILE* out = 0;
    char buf[128];
    int startxref;
    pdf_xref_internal *xref = 0;
    num_range range;

    out = fopen(outf, "wb");
    if (!out)
	    return pdf_ok;
    pdf_magic_write(out, options);
    // scan pages
    xref = pdf_xref_internal_create(pdf_obj_count(), doc->count);
    if (!xref)
	    goto done_0;
    pdf_catalog_write(doc, xref, out, crypto, WRITE_CATALOG_DEFAULTS);
    pdf_page_scan(doc->pages[i], xref, out, crypto);
    pdf_indirect_objs_write(xref, out, crypto);
    pdf_page_obj_write(doc->pages[i], i, options->flags, xref, crypto, out);

    range.bgn = i + 1;
    range.end = i + 1;
    pdf_pages_obj_write(xref, &range, 1, out);
    // write xref table
    startxref = pdf_xref_write(xref, out);
    pdf_trailer_write(xref, startxref, out);
    // done
  done_0:
    if (xref)
	    pdf_xref_internal_free(xref);
    fclose(out);
    return pdf_ok;
}

pdf_err
pdf_write_pdf(pdf_doc *doc, char* infile, char *ofile, pdf_writer_options *options)
{
    pdf_err e = pdf_ok;
    FILE* out = 0;
    char linebuf[1024];
    int i, j, startxref, err, nr;
    num_range *page_ranges, pr[1];
    pdf_xref_internal *xref = 0;
    pdfcrypto_priv *crypto = NULL;
    char *odir;
    struct stat s;

    if (options->nr == 0)
    {
        page_ranges = pr;
        pr->bgn = 1;
        pr->end = doc->count;
        nr = 1;
    }
    else
    {
        page_ranges = options->page_ranges;
        nr = options->nr;
    }

    if (!ofile && (!(options->flags & WRITE_PDF_PAGE_SEPARATION)))
        return pdf_ok;
    if (pdf_doc_need_passwd(doc))
    {
#ifdef DEBUG
	    printf("%s", "Decrypting page content stream\n");
#endif
	    if (doc->trailer->encrypt)
	    {
            crypto = pdf_crypto_init(doc->trailer->encrypt,
                                     doc->trailer->id[0],
                                     "" // password
                );
	    }
	    if (!crypto)
	    {
            goto done;
	    }
    }
    if (options->flags & WRITE_PDF_PAGE_SEPARATION)
    {
	    char base[128];
	    char *b, *b1;
	    // make output directory
#ifdef __unix__
	    b1 = basename(ofile);
#endif
	    b = strchr(b1, '.');
	    if (b || b1)
	    {
            if (b)
            {
                memcpy(base, b1, b-b1);
                base[b-b1] = 0;
            }
            else
                strcpy(base, b1);
	    }
	    else
	    {
            memcpy(base, infile, strlen(infile));
            base[strlen(infile)] = 0;
	    }
	    odir = base;
	    if ((err = stat(odir, &s)) == 0)
	    {
            if ((!(S_ISDIR(s.st_mode))) && (S_ISREG(s.st_mode)))
            {
                e = pdf_file_err;
                goto done;
            }
	    }
	    if (err || (!S_ISDIR(s.st_mode)))
	    {
            err = mkdir(odir, S_IRWXU | S_IRWXG);
            if (err != 0)
            {
                e = pdf_file_err;
                goto done;
            }

	    }
	    else if (err == 0 && (!S_ISDIR(s.st_mode)))
	    {
            e = pdf_file_err;
            goto done;
	    }
	    //
        for (j = 0; j < nr; j++)
        {
            int pg1st = page_ranges[j].bgn;
            int pglast = page_ranges[j].end;
            if (pg1st <= 0)
                pg1st = 1;
            for (i = pg1st - 1; i <= pglast; i++)
            {
                if (i >= doc->count)
                    break;
                for (i = pg1st - 1; i <= pglast; i++)
                {
#ifdef __unix__
                    b = basename(infile);
#endif
                    b1 = strchr(b, '.');
                    if (b1)
                    {
                        char striped[256];
                        memcpy(striped, b, b1-b);
                        striped[b1-b] = 0;
                        sprintf(linebuf, "%s/%s-%d.%s", odir, striped, i+1, "pdf");
                    }
                    else
                    {
                        sprintf(linebuf, "%s/%s-%d.%s", odir, b, i+1, "pdf");
                    }
                    printf("Writing %s..\n", linebuf);
                    pdf_page_write(doc, i, crypto, linebuf, options);
                }
            }
        }
	    if (crypto)
            pdf_crypto_destroy(crypto);
    }
    else
    {
        int n_pages = 0;
#ifdef DEBUG
	    printf("Writing %s..\n", ofile);
#endif
	    out = fopen(ofile, "wb");
	    if (!out)
            return pdf_ok;
        pdf_magic_write(out, options);
	    // scan pages
	    xref = pdf_xref_internal_create(pdf_obj_count(), doc->count);
	    if (!xref)
            goto done;
	    pdf_catalog_write(doc, xref, out, crypto, WRITE_CATALOG_DEFAULTS);
        for (j = 0; j < nr; j++)
        {
            int pg1st = page_ranges[j].bgn;
            int pglast = page_ranges[j].end;
            if (pg1st < 0)
                break;
            if (pg1st == 0)
                pg1st = 1;
            for (i = pg1st - 1; i <= pglast-1; i++)
            {
                if (i >= doc->count)
                {
                    break;
                }
                pdf_page_scan(doc->pages[i], xref, out, crypto);
                pdf_indirect_objs_write(xref, out, crypto);
                pdf_page_obj_write(doc->pages[i], i, options->flags, xref, crypto, out);
                n_pages++;
            }
        }
        pdf_pages_obj_write(xref, page_ranges, nr, out);
	    // write xref table
	    startxref = pdf_xref_write(xref, out);
	    pdf_trailer_write(xref, startxref, out);
	    // done
      done:
	    if (xref)
            pdf_xref_internal_free(xref);
	    if (crypto)
            pdf_crypto_destroy(crypto);
	    if (out)
            fclose(out);
    }
    return pdf_ok;
}
