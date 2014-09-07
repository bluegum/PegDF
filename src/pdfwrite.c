#include <sys/stat.h>
#include <sys/types.h>
#ifdef __unix__
#include <unistd.h>
#include <libgen.h>
#endif
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "bplustree.h"
#include "dict.h"
#include "pdf.h"
#include "pdfread.h"
#include "pdffilter.h"
#include "pdfindex.h"
#include "pdfdoc.h"
#include "pdfhelper.h"
#include "pdfstream.h"


#ifndef S_IFDIR
#ifdef _S_IFDIR
#define S_IFDIR _S_IFDIR
#endif
#endif

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
    //
    pdf_stream *filt_stream; // output filtering stream(s)
};

// pdf_xref_table stores the artifects of object writing. to be written out as new xref table.
struct pdf_xref_table_s
{
    int n; // total number of entries
    int cur; // index to current entry
    int *offsets;
};

static void pdf_obj_write(pdf_obj* o, pdf_xref_internal *x, pdf_stream *f, int n, int g, pdfcrypto_priv *crypto, pdfcrypto_priv *encrypto, unsigned long flags);
static void pdf_key_write(const char *k, pdf_xref_internal *x, pdf_stream *f, pdfcrypto_priv *crypto);
static void pdf_obj_full_write(pdf_obj *o, int n, int g, pdf_xref_internal *x, pdf_stream *f, pdfcrypto_priv *crypto, pdfcrypto_priv *encrypto, unsigned long flags);
static void pdf_obj_scan(pdf_obj *o, pdf_xref_internal *x);
static void pdf_indirect_objs_write(pdf_xref_internal *xref, pdf_stream *out, pdfcrypto_priv *crypto, pdfcrypto_priv *encyrpto, unsigned long flags);

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
pdf_xref_internal_create(int n, int npages, pdf_writer_options *options)
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
    // install default deflate output stream
#if 0
    if ((options->flags & WRITE_PDF_CONTENT_INFLATE) == 0)
    {
        x->filt_stream = pdf_ostream_filtered_open(FlateEncode);
    }
#endif
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
pdf_catalog_write(pdf_doc *doc, pdf_xref_internal *x, pdf_stream *o, pdfcrypto_priv *decrypto, unsigned long flags)
{
    pdf_obj tmp;
    pdf_obj *ocptmp = 0;
    dict *d = dict_new(11);

    if (!d)
        return;
    tmp.t = eDict;
    tmp.value.d.dict = d;

    x->xref->cur = 3;

    bpt_insert(x->entry, doc->root_ref, (void*)2);
    bpt_insert(x->entry, 2, (void*)2);
    bpt_insert(x->entry, 1, (void*)1);

    if (doc->ocproperties && (flags & WRITE_CATALOG_OCPROPERTIES))
    {
        pdf_ocproperties *oc = doc->ocproperties;
        if (doc->ocproperties->ocgs)
            pdf_obj_scan(doc->ocproperties->ocgs, x);
        if (doc->ocproperties->has_defaults)
        {
            if (oc->d.on)
                pdf_obj_scan(oc->d.on, x);
            if (oc->d.off)
                pdf_obj_scan(oc->d.off, x);
            if (oc->d.intent)
                pdf_obj_scan(oc->d.intent, x);
            if (oc->d.as)
                pdf_obj_scan(oc->d.as, x);
            if (oc->d.order)
                pdf_obj_scan(oc->d.order, x);
            if (oc->d.rbgroups)
                pdf_obj_scan(oc->d.rbgroups, x);
            if (oc->d.locked)
                pdf_obj_scan(oc->d.locked, x);
        }
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
    pdf_indirect_objs_write(x, o, decrypto, 0, flags);
    x->xref->offsets[2] = pdf_stream_tell(o);
    // new catalog dictionary
    pdf_dict_insert_name(d, "Type", "Catalog");
    pdf_dict_insert_ref(d, "Pages", 1, 0);

    if (doc->pagemode)
    {
        if (doc->pagemode->t == eKey || doc->pagemode->t == eName)
            pdf_dict_insert_name(d, "PageMode", (char*)doc->pagemode->value.k);
        else
            dict_insert(d, "PageMode", (void*)pdf_obj_copy(doc->pagemode));
    }
    if (doc->pagelayout)
    {
        if (doc->pagelayout->t == eKey || doc->pagelayout->t == eName)
            pdf_dict_insert_name(d, "PageLayout", (char*)doc->pagelayout->value.k);
        else
            dict_insert(d, "PageLayout", (void*)pdf_obj_copy(doc->pagelayout));
    }
    if (doc->structtreeroot && (flags & WRITE_CATALOG_STRUCTTREEROOT))
    {
        dict_insert(d, "StructTreeRoot", pdf_obj_copy(doc->structtreeroot));
    }
    if (doc->pieceinfo && (flags & WRITE_CATALOG_PIECEINFO))
    {
        dict_insert(d, "PieceInfo", pdf_obj_copy(doc->pieceinfo));
    }
    if (doc->pagelabels && (flags & WRITE_CATALOG_PAGELABELS))
    {
        dict_insert(d, "PageLabels", pdf_obj_copy(doc->pagelabels));
    }
    if (doc->outlines && (flags & WRITE_CATALOG_OUTLINES))
    {
        dict_insert(d, "Outlines", pdf_obj_copy(doc->outlines));
    }
    if (doc->names && (flags & WRITE_CATALOG_NAMES))
    {
        dict_insert(d, "Names", pdf_obj_copy(doc->names));
    }
    if (doc->markinfo && (flags & WRITE_CATALOG_MARKINFO))
    {
        dict_insert(d, "MarkInfo", pdf_obj_copy(doc->markinfo));
    }
    if (doc->metadata && doc->metadata->t == eRef && (flags & WRITE_CATALOG_METADATA))
    {
        pdf_obj *t = pdf_obj_copy(doc->metadata);
        dict_insert(d, "Metadata", t);
    }
    if (doc->ocproperties && (flags & WRITE_CATALOG_OCPROPERTIES))
    {
        if (doc->ocproperties->ocgs || doc->ocproperties->has_defaults || doc->ocproperties->configs)
        {
            pdf_ocproperties *ocp = doc->ocproperties;;
            dict *d;
            ocptmp = pdf_dict_new(1);
            d = ocptmp->value.d.dict;
            if (doc->ocproperties->ocgs)
            {
                dict_insert(d, "OCGs", (void*)pdf_obj_full_copy(doc->ocproperties->ocgs));
            }
            if (doc->ocproperties->has_defaults)
            {
                dict *df;
                pdf_obj *dftmp = pdf_dict_new(1);
                df = dftmp->value.d.dict;
                if (ocp->d.name)
                {
                    dict_insert(df, "Name", (void*)ocp->d.name);
                }
                if (ocp->d.creator)
                {
                    dict_insert(df, "Creator", (void*)ocp->d.creator);
                }
                if (ocp->d.basestate)
                {
                    dict_insert(df, "BaseState", (void*)ocp->d.basestate);
                }
                if (ocp->d.on)
                {
                    dict_insert(df, "ON", (void*)pdf_obj_full_copy(ocp->d.on));
                }
                if (ocp->d.off)
                {
                    dict_insert(df, "OFF", (void*)pdf_obj_full_copy(ocp->d.off));
                }
                if (ocp->d.intent)
                {
                    if (ocp->d.intent->t == eArray)
                        dict_insert(df, "Intent", (void*)pdf_obj_full_copy(ocp->d.intent));
                    else
                        dict_insert(df, "Intent", (void*)ocp->d.intent);
                }
#if 0
                if (ocp->d.as)
                {
                    int i;
                    pdf_obj *as_arr = pdf_obj_full_copy(ocp->d.as);
                    for (i = 0; i < as_arr->value.a.len; i++)
                    {
                        pdf_obj *tt = pdf_obj_full_copy(&as_arr->value.a.items[i]);
                        as_arr->value.a.items[i] = *tt;
                    }
                    dict_insert(df, "AS", as_arr);
                }
#endif
                if (ocp->d.order)
                {
                    dict_insert(df, "Order", (void*)pdf_obj_full_copy(ocp->d.order));
                }
                if (ocp->d.listmode)
                {
                    dict_insert(df, "ListMode", (void*)ocp->d.listmode);
                }
                if (ocp->d.rbgroups)
                {
                    dict_insert(df, "RBGroups", (void*)pdf_obj_full_copy(ocp->d.rbgroups));
                }
                if (ocp->d.locked)
                {
                    dict_insert(df, "Locked", (void*)pdf_obj_full_copy(ocp->d.locked));
                }
                dict_insert(d, "D", (void*)dftmp);

            }
            // TODO: write /configs
            // Reason not doing it now is those entries are not
            // scanned, means not in the writer's object tree
        }
        if (ocptmp)
            dict_insert(d, "OCProperties", (void*)ocptmp);

    }
    pdf_obj_full_write(&tmp, 2, 0, x, o, decrypto, 0, flags);
    pdf_obj_delete(&tmp);
}

static
void
pdf_pages_obj_write(pdf_xref_internal *x, num_range *page_ranges, int nr, pdf_stream *o)
{
    int i, j, n = 0;
    pdf_obj tmp, *pages;
    dict *d = dict_new(2);
    if (!d)
        return;

    x->xref->offsets[1] = pdf_stream_tell(o);

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
    pdf_obj_full_write(&tmp, 1, 0, x, o, 0, 0, 0);
    pdf_obj_delete(&tmp);
}

static
int
pdf_xref_write(pdf_xref_internal *x, pdf_stream *o)
{
    int i, startxref;
    char tmp[128];
    startxref = pdf_stream_tell(o);
    pdf_stream_puts("\nxref\n", o);
    pdf_stream_puts("0 ", o);
    pdf_stream_puti(x->xref->cur, o);
    pdf_stream_putc('\n', o);
    sprintf(tmp, "%010d %05d f \n", 0, 65535);
    pdf_stream_puts(tmp, o);
    for (i = 1; i < x->xref->cur; i++)
    {
        sprintf(tmp, "%010d %05d n \n", x->xref->offsets[i], 0);
        pdf_stream_puts(tmp, o);
    }
    return startxref;
}

static
pdf_obj*
pdf_trailer_create(pdf_xref_internal *x, char *id1, char *id2, pdf_obj *info, int info_ref, void *encrypto, int encrypt_num)
{
    pdf_obj *o = pdf_dict_new(3);
    dict *d = o->value.d.dict;
    pdf_obj *tmp;

    if (info)
    {
        pdf_dict_insert_ref(d, "Info", info_ref, 0);
    }

    if (id1 && id2)
    {
        pdf_obj *id = pdf_array_build(2);

        tmp = pdf_hstring_new(id1, 16);
        id->value.a.items[0] = *tmp;
        pdf_free(tmp);

        tmp = pdf_hstring_new(id2, 16);
        id->value.a.items[1] = *tmp;
        pdf_free(tmp);

        dict_insert(d, "ID", id);
    }

    bpt_insert(x->entry, x->xref->cur, (void*)2);
    pdf_dict_insert_int(d, "Size", x->xref->cur);
    pdf_dict_insert_ref(d, "Root", x->xref->cur, 0);
    if (encrypto)
    {
        pdf_dict_insert_ref(d, "Encrypt", encrypt_num, 0);
    }
    return o;
}

static
void
pdf_trailer_write(pdf_xref_internal *x, int startxref, char *ids[2], pdf_obj *info, int info_ref, void *encrypt, int encrypt_num, pdf_stream *s)
{
    pdf_err e;
    pdf_obj *tmp;


    tmp = pdf_trailer_create(x, ids[0], ids[1], info, info_ref, encrypt, encrypt_num);

    if (!tmp)
        return;

    pdf_stream_puts("trailer\n", s);

    pdf_obj_write(tmp, x, s,
                  0, // n
                  0, // g
                  0,
                  0,
        0);

    pdf_stream_puts("\nstartxref\n", s);
    pdf_stream_puti(startxref, s);
    pdf_stream_putc('\n', s);
    pdf_stream_puts("%%EOF", s);
    pdf_obj_delete(tmp);
    pdf_free(tmp);
}

static void
pdf_obj_write(pdf_obj* o, pdf_xref_internal *x, pdf_stream *f, int n, int g, pdfcrypto_priv *decrypto, pdfcrypto_priv *encrypto, unsigned long flags)
{
    pdf_err e;
    int i;

    if (!o)
        return;
    switch (o->t)
    {
        case eBool:
            pdf_stream_putc(' ', f);
            pdf_stream_puts(o->value.b?"true":"false", f);
            break;
        case eInt:
            pdf_stream_putc(' ', f);
            pdf_stream_puti(o->value.i, f);
            break;
        case eReal:
            pdf_stream_putc(' ', f);
            pdf_stream_putf(o->value.f, f);
            break;
        case eKey:
            pdf_stream_putc('/', f);
            pdf_stream_puts(o->value.k, f);
            break;
        case eName:
        {
            unsigned char *p = o->value.k;
            pdf_stream_putc('/', f);
            while (*p)
            {
                if (is_escapable(*p))
                {
                    pdf_stream_putc('#', f);
                    pdf_stream_puth(*p, f);
                }
                else
                {
                    pdf_stream_putc(*p, f);
                }
                p++;
            }
            break;
        }
        case eString:
        {
            int c;
            pdf_stream *out = f;
            pdf_stream *encs = 0;
            pdf_stream *sb = 0;

            pdf_stream_puts("(", f);

            if (encrypto)
            {

                pdfcrypto_algorithm algo = which_algo(encrypto);
                sb = pdf_stream_buffer_open();

                if (algo == eRC4)
                {
                    encs = (pdf_stream*)pdf_ostream_filtered_open(RC4Encrypt, n, g, encrypto);
                }
                else if (algo == eAESV2)
                {
                    encs = (pdf_stream*)pdf_ostream_filtered_open(AESEncrypt, n, g, encrypto);
                }

                if (encs)
                {
                    pdf_stream_chain(encs, sb);
                    out = encs;
                }
            }

            if (decrypto)
            {
                pdf_stream *s;

                e = pdf_istream_filtered_load(o, decrypto, x->page_obj_buf[x->cur_idx], 0, &s);
                if (s)
                {
                    while ((c = pdf_stream_getc(s)) != EOF)
                        pdf_stream_putc(c, out);
                    pdf_stream_free(s, 1);

                    pdf_stream_flush(out);
                    if (sb)
                    {
                        pdf_stream_seekg(sb, 0, S_SEEK_BEG);
                        while ((c = pdf_stream_getc(sb)) != EOF)
                        {
                            switch (c)
                            {
                                case ')':
                                case '(':
                                case '\\':
                                    pdf_stream_putc('\\', f);
                                    pdf_stream_putc(c, f);
                                    break;
                                default:
                                    pdf_stream_putc(c, f);
                                    break;
                            }
                        }
                    }
                }
            }
            else
            {
                if (sb)
                {
                    // write to internal stream
                    for (i = 0; i < o->value.s.len; i ++)
                        pdf_stream_putc(o->value.s.buf[i], out);
                    pdf_stream_flush(out);
                    pdf_stream_seekg(sb, 0, S_SEEK_BEG);

                    // write to final output
                    while ((c = pdf_stream_getc(sb)) != EOF)
                    {
                        switch (c)
                        {
                            case ')':
                            case '(':
                            case '\\':
                                pdf_stream_putc('\\', f);
                                pdf_stream_putc(c, f);
                                break;
                            default:
                                pdf_stream_putc(c, f);
                                break;
                        }
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
                            case '\\':
                                pdf_stream_putc('\\', f);
                                pdf_stream_putc(o->value.s.buf[i], out);
                                break;
                            default:
                                pdf_stream_putc(o->value.s.buf[i], out);
                                break;
                        }
                    }
                }
            }

            pdf_stream_putc(')', f);

            if (encs)
                pdf_stream_close(encs);
            if (sb)
                pdf_stream_close(sb);
            break;
        }
	    case eHexString:
            pdf_stream_puts("<", f);
            if (decrypto)
            {
                pdf_stream *s;

                e = pdf_istream_filtered_load(o, decrypto, x->page_obj_buf[x->cur_idx], 0, &s);
                if (s)
                {
                    int c;
                    while ((c = pdf_stream_getc(s)) != EOF)
                    {
                        pdf_stream_puth((byte)c, f);
                    }
                    pdf_stream_free(s, 1);
                }
            }
            else
            {
                for (i = 0; i < o->value.s.len; i ++)
                {
                    pdf_stream_puth((byte)(o->value.s.buf[i]), f);
                    if ((i+1)%32==0)
                        pdf_stream_putc('\n', f);
                }
            }
            pdf_stream_puts("> ", f);
            break;
        case eDict:
        {
            dict_list *ll, *l = dict_to_list(o->value.d.dict);
            sub_stream *strm = o->value.d.dict->stream;
            int strmlen = 0;
            int inflate = pdf_to_int(pdf_dict_get(o, "PEGDF_INFLATE_CONTENT"));
            pdf_filterkind filter_array[16];
            int keep_orig = 0;
            pdf_obj *filters = 0;
            int inflate_all = flags & WRITE_PDF_STREAM_INFLATE;

            if (inflate_all)
                inflate = 1;

            filter_array[0] = Limit;
            if (strm)
            {
                strmlen = pdf_to_int(pdf_dict_get(o, "Length"));
            }
            ll = l;
            pdf_stream_puts("<<", f);
            while (l && l->key)
            {
                if (l->key[0] == 'P' && strcmp(l->key, "PEGDF_INFLATE_CONTENT")==0)
                {
                    l = l->next;
                    continue;
                }
                else if (l->key[0] == 'L' && strcmp(l->key, "Length")==0 && strm)
                {
                    l = l->next;
                    continue;
                }
                else if (l->key[0] == 'F' && strcmp(l->key, "Filter")==0 && strm)
                {
                    filters = &l->val;
                    pdf_filter_str_to_enum(&l->val, filter_array);
                    switch (filter_array[0])
                    {
                        case DCTDecode:
                        case JPXDecode:
                        case JBIG2Decode:
                            inflate = 1;
                            keep_orig = 1;
                            break;
                        case FlateDecode:
                            break;
                        default:
                            break;
                    }
                    l = l->next;
                    continue;
                }
                else if (l->key[0] == 'D' && !strcmp(l->key, "DecodeParms") && strm)
                {
                    if (inflate_all)
                    {
                        l = l->next;
                        continue;
                    }
                }
                pdf_key_write(l->key, x, f, decrypto);
                pdf_obj_write(&l->val, x, f, n, g, decrypto, encrypto, flags);
                l = l->next;
            }
            if (strm)
            {
                int         obj, gen;
                int         c;
                int         i = 0;
                pdf_stream *s = NULL;
                sub_stream *ss = (sub_stream*)o->value.d.dict->stream;
                pdf_stream *sb = pdf_stream_buffer_open();
                pdf_stream *filts = 0, *out = sb;
                pdf_stream *encs = 0;

                // Output options
                //
                if (encrypto)
                {
                    pdfcrypto_algorithm algo = which_algo(encrypto);

                    if (algo == eRC4)
                    {
                        encs = (pdf_stream*)pdf_ostream_filtered_open(RC4Encrypt, n, g, encrypto);
                    }
                    else if (algo == eAESV2)
                    {
                        encs = (pdf_stream*)pdf_ostream_filtered_open(AESEncrypt, n, g, encrypto);
                    }

                    if (encs)
                    {
                        pdf_stream_chain(encs, sb);
                        out = encs;
                    }

                }

                if (!inflate)
                {
                    filts = (pdf_stream*)pdf_ostream_filtered_open(FlateEncode, 0);
                    if (filts)
                    {
                        pdf_stream_chain(filts, out);
                        out = filts;
                    }
                }

                // get input stream
                //
                if (ss) // for descryption
                {
                    obj = ss->obj;
                    gen = ss->gen;
                }

                e = pdf_istream_filtered_load(o, decrypto, obj, gen, &s);

                if (e == pdf_ok)
                {
                    unsigned char buf[1024], *ptr = buf, *lim;

                    lim = ptr + 1024;
                    //
                    while ((c = pdf_stream_getc(s)) != EOF)
                    {
                        if (ptr >= lim)
                        {
                            pdf_stream_write(buf, 1024, out);
                            ptr = buf;
                        }
                        *ptr++ = c;
                    }
                    if (ptr - buf)
                    {
                        pdf_stream_write(buf, ptr-buf, out);
                    }
                    // flush filter stream
                    if (filts)
                    {
                        pdf_stream_flush(filts);
                        pdf_stream_close(filts);
                    }
                    //
                    strmlen = pdf_stream_tell(sb);
                    pdf_stream_puts("/Length ", f);
                    pdf_stream_puti(strmlen, f);
                    if (!inflate || keep_orig)
                    {
                        pdf_key_write("Filter", x, f, 0);
                        if (inflate || filter_array[0] != Limit)
                        {
                            if (!(!inflate && filters->t == eKey && filter_array[0] == FlateDecode))
                                pdf_stream_putc('[', f);
                        }
                        if (!inflate)
                        {
                            pdf_key_write("FlateDecode", x, f, 0);
                        }
                        // discard some, write some filters out
                        while (filter_array[i] != Limit)
                        {
                            switch(filter_array[i]) {
                                case FlateDecode:
                                case ASCIIHexDecode:
                                case ASCII85Decode:
                                case LZWDecode:
                                    break;
                                default:
                                    pdf_key_write(pdf_filter_to_string(filter_array[i]), x, f, 0);
                                    break;
                            }
                            i++;
                        }
                        if (inflate || filter_array[0] != Limit)
                        {
                            if (!(!inflate && filters->t == eKey && filter_array[0] == FlateDecode))
                                pdf_stream_putc(']', f);
                        }
                    }
                    pdf_stream_puts(">> ", f);
                }
                else
                {
                    // write (possible)raw stream
                    int len;
                    unsigned char buf[1024];

                    // read into buffer
                    if (!s)
                    {
                        s = pdf_rawstream_new(strm);
                    }

#if 0
                    strm->len = strmlen;
                    while (len = strm->read(strm, buf, 1024))
                    {
                        pdf_stream_write(buf, len, out);
                    }
                    strm->close(strm, 1);
#else
                    while ((len = pdf_stream_read(buf, 1024, s)) != 0)
                    {
                        pdf_stream_write(buf, len, out);
                    }
#endif

                    pdf_stream_puts("/Length ", f);
                    pdf_stream_puti(strmlen, f);

                    // writing filters
                    pdf_stream_puts("/Filter[", f);

                    for (i = 0; filter_array[i] != Limit; i++)
                    {
                        switch(filter_array[i])
                        {
                            case FlateDecode:
                                if (!inflate)
                                {
                                    pdf_stream_puts("/Filter[/FlateDecode", f);
                                    while (filter_array[i] != Limit)
                                    {
                                        pdf_key_write(pdf_filter_to_string(filter_array[i]), x, f, 0);
                                        i++;
                                    }
                                    pdf_stream_putc(']', f);
                                }
                                else
                                {
                                    pdf_stream_puts("/FlateDecode", f);
                                }
                                break;

                            default:
                                pdf_key_write(pdf_filter_to_string(filter_array[i]), x, f, 0);
                                break;
                        }
                    }
                    pdf_stream_putc(']', f);
                    pdf_stream_puts(">> ", f);
                }

                // write out stream
                pdf_stream_puts("stream\n", f);
                pdf_stream_seekg(sb, 0, S_SEEK_BEG);

                while ((c = pdf_stream_getc(sb)) != EOF)
                    pdf_stream_putc(c, f);

                pdf_stream_puts("\nendstream", f);
                // tidyup
                pdf_stream_close(sb);


                if (encs)
                {
                    pdf_stream_close(encs);
                }
                if (s)
                {
                    pdf_stream_free(s, 1);
                }
            }
            else
            {
                pdf_stream_puts(">> ", f);
            }
            dict_list_free(ll);
        }
        break;
        case eArray:
        {
            int i;
            pdf_stream_puts("[", f);
            for (i = 0; i < o->value.a.len; i++)
            {
                pdf_obj_write(&o->value.a.items[i], x, f, n, g, decrypto, encrypto, flags);
            }
            pdf_stream_puts("]", f);
        }
        break;
        case eRef:
        {
            char tmp[128];
            int a = (int)bpt_search(x->entry, o->value.r.num);
            if (a > 0)
            {
                sprintf(tmp, " %d %d R ", a, o->value.r.gen);
            }
            else
            {
                sprintf(tmp, " %d %d R ", -a, 0);
            }
            pdf_stream_puts(tmp, f);
        }
        break;
        default:
            break;
    }
}

static void
pdf_key_write(const char *k, pdf_xref_internal *x, pdf_stream *f, pdfcrypto_priv *crypto)
{
    pdf_obj key;
    key.t = eName;
    key.value.k = k;
    pdf_obj_write(&key, x, f, 0, 0, crypto, 0, 0);
}

static void
pdf_obj_full_write(pdf_obj *o, int n, int g, pdf_xref_internal *x, pdf_stream *f, pdfcrypto_priv *decrypto, pdfcrypto_priv* encrypto, unsigned long flags)
{
    char tmp[128];
    sprintf(tmp, "%d %d obj\n", n, g);
    pdf_stream_puts(tmp, f);

    pdf_obj_write(o, x, f, n, g, decrypto, encrypto, flags);

    pdf_stream_puts("\nendobj\n", f);

}

static
int
pdf_page_contents_write(pdf_obj *content, unsigned long write_flag, pdf_xref_internal *x, pdf_stream *out, pdfcrypto_priv *crypto, pdfcrypto_priv *encrypto)
{
    int content_ref = x->xref->cur;
    int off = pdf_stream_tell(out);
    pdf_obj *cobj = content;

    pdf_obj_resolve(cobj);
    if (cobj->t != eDict)
    {
	    return -1;
    }
    if (write_flag & WRITE_PDF_CONTENT_INFLATE)
    {
        pdf_dict_insert_int(cobj->value.d.dict, "PEGDF_INFLATE_CONTENT", 1);
    }

    pdf_obj_full_write(cobj, x->xref->cur, 0, x, out, crypto, encrypto, write_flag);
    x->xref->offsets[x->xref->cur] = off;
    x->xref->cur++;
    return content_ref;
}

static
pdf_obj*
pdf_group_write(pdf_group *g, pdf_xref_internal *x, pdfcrypto_priv *crypto)
{
    pdf_obj *tmp = pdf_malloc(sizeof(pdf_obj));
    dict *d;

    if (!g)
        return tmp;
    if (!tmp)
        return 0;
    d = dict_new(3);
    if (!d)
        return tmp;
    tmp->t = eDict;
    tmp->value.d.dict = d;
    if (g->cs)
    {
        pdf_obj *cs = pdf_malloc(sizeof(pdf_obj));
        *cs = *g->cs;
	    dict_insert(d, "CS", cs);
    }
    pdf_dict_insert_int(d, "I", g->i);
    pdf_dict_insert_int(d, "K", g->k);
    return tmp;
}

static
pdf_obj*
pdf_resources_write(pdf_resources *r, pdf_xref_internal *x, pdfcrypto_priv *crypto)
{
    pdf_obj *tmp;
    dict *d;

    tmp = pdf_malloc(sizeof(pdf_obj));
    if (!tmp)
        return 0;
    d = dict_new(9);
    if (!d)
        return 0;
    tmp->t = eDict;
    tmp->value.d.dict = d;

    if (r->extgstate)
    {
        dict_insert(d, "ExtGState", (r->extgstate));
    }
    if (r->font)
    {
        dict_insert(d, "Font", (r->font));
    }
    if (r->xobject)
    {
        dict_insert(d, "XObject", (r->xobject));
    }
    if (r->colorspace)
    {
        dict_insert(d, "ColorSpace", (r->colorspace));
    }
    if (r->shading)
    {
        dict_insert(d, "Shading", (r->shading));
    }
    if (r->pattern)
    {
        dict_insert(d, "Pattern", (r->pattern));
    }
    if (r->properties)
    {
        dict_insert(d, "Properties", (r->properties));
    }

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
pdf_page_scan(pdf_page* pg, pdf_xref_internal* x, pdf_stream *o, pdfcrypto_priv *crypto, pdfcrypto_priv *encrypto, unsigned long flags)
{
    if (!pg)
        return;
    x->page_obj_idx = 0;
    pdf_resources_scan(pg->resources, x);
    if (pg->group)
    {
        pdf_obj_scan(pg->group->cs, x);
    }
    pdf_indirect_objs_write(x, o, crypto, encrypto, flags);
}

// Writing out page content which is an array of references.
static
void
pdf_indirect_objs_write(pdf_xref_internal *x, pdf_stream *out, pdfcrypto_priv *crypto, pdfcrypto_priv *encrypto, unsigned long flags)
{
    if (x->page_obj_idx)
    {
        int i;
	    // backward scanning to meet dependency
        for (i = 0; i < x->page_obj_idx; i++)
        {
            int a = (int)bpt_search(x->entry, x->page_obj_buf[i]);
            if (a == MARK_BLACK) // MARK_BLACK means new item in the output tree, need to be flushed out.
            {
                pdf_obj *o = pdf_obj_find(x->page_obj_buf[i], 0);
                x->cur_idx = i;
                x->xref->offsets[x->xref->cur] = pdf_stream_tell(out);
                // insert negative ref-number to mark back-edge
                bpt_insert(x->entry, x->page_obj_buf[i], (void*)-x->xref->cur);
                // serialize
                pdf_obj_full_write(o, x->xref->cur, 0, x, out, crypto, encrypto, flags);
                // update entry
                bpt_insert(x->entry, x->page_obj_buf[i], (void*)x->xref->cur);
                // inc new xref counter
                x->xref->cur++;
            }
        }
    }
}

static
void
pdf_page_obj_write(pdf_page *page, int pgidx, pdf_xref_internal *x, pdfcrypto_priv *crypto, pdfcrypto_priv *encrypto, pdf_stream *out, unsigned long write_flag)
{
    int content_ref = -1;
    int content_ref_orig = -1;
    int content_num = 0;
    int content_ref_arr[1024];
    pdf_obj *tmp, *mediabox;
    dict *d;
    pdf_obj *contents = 0, *v;

    if (!page)
        return;
    tmp = (pdf_obj*)pdf_dict_new(11);
    if (!tmp)
        return;
    d = tmp->value.d.dict;

    if (page->contents)
    {
        contents = pdf_obj_deref(page->contents);

        if (contents->t == eDict)
        {
            content_ref_orig = page->contents->value.r.num;
            content_ref = pdf_page_contents_write(contents, write_flag, x, out, crypto, encrypto);
            bpt_insert(x->entry, content_ref_orig, (void*)content_ref);
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
                if (contents->value.a.items[i].t == eRef)
                {
                    int nnn = contents->value.a.items[i].value.r.num;
                    content_ref_arr[i] = pdf_page_contents_write(&contents->value.a.items[i], write_flag, x, out, crypto, encrypto);
                    bpt_insert(x->entry, nnn, (void*)content_ref_arr[i]);
                }
            }
	    }
    }
    if (content_ref == -1 && content_num == 0)
    {
        goto error_content;
    }
    x->xref->offsets[x->xref->cur] = pdf_stream_tell(out);
    bpt_insert(x->entry, page->ref.value.r.num, (void*)x->xref->cur);
    x->page_ref_buf[pgidx] = page->ref.value.r.num;
    x->xref->cur++;

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
        pdf_obj *resources;
        resources = pdf_resources_write(page->resources, x, crypto);
        if (resources)
        {
            dict_insert(d, "Resources", resources);
        }
    }
    if (page->group)
    {
        pdf_obj *grp = pdf_group_write(page->group, x, crypto);
        if (grp)
        {
            dict_insert(d, "Group", grp);
        }
    }
    if (content_ref_orig != -1)
    {
        pdf_dict_insert_ref(d, "Contents", content_ref_orig, 0);
    }
	else if (contents)
    {
	    int i;
        pdf_obj *cont = pdf_array_build(content_num);
	    for (i = 0; i < content_num; i++)
	    {
            if (contents->value.a.items[i].t == eRef)
            {
                cont->value.a.items[i] = pdf_ref_to_obj(contents->value.a.items[i].value.r.num, 0);
            }
            else
            {
                fprintf(stderr, "Page content is not indirect obj, is discarded!\n");
            }
	    }
        dict_insert(d, "Contents", cont);
    }

    if (page->rotate)
    {
        pdf_dict_insert_int(d, "Rotate", page->rotate);
    }

    pdf_obj_full_write(tmp, x->xref->cur-1, 0, x, out, crypto, 0, write_flag);

  error_content:
    v = dict_entry_delete(d, "Contents");
    if (v)
    {
        pdf_free(v);
    }
    v = dict_entry_delete(d, "MediaBox");
    if (v)
    {
        pdf_obj_delete(v);
        pdf_free(v);
    }
    v = dict_entry_delete(d, "Resources");
    if (v)
    {
        dict_delete(v->value.d.dict);
        pdf_free(v);
    }
    v = dict_entry_delete(d, "Type");
    pdf_free(v);
    dict_delete(d);
    pdf_free(tmp);
}

pdf_err
pdf_magic_write(pdf_stream *out, pdf_writer_options *options)
{
    char buf[128];
    if (options)
        sprintf(buf, "%%PDF-%d.%d\n", options->version/10, options->version%10);
    else
        sprintf(buf, "%%PDF-%d.%d\n", 1, 7);

    pdf_stream_puts(buf, out);
    pdf_stream_puts("%\333\332\331\330\n", out);
    return pdf_ok;
}

/**
 *  TODO: writing ID strings
 */
pdf_err
pdf_encrypt_write(pdf_xref_internal *x, pdf_stream *out, pdf_writer_options *options, char *of_name, pdf_obj *info, int *num, char o[32], char u[32])
{
    pdf_obj tmp;
    dict *d;
    // inline crypt filter
    pdf_obj cf;
    dict *cfd;
    /* standard cf */
    pdf_obj std_cf;
    dict *std_cfd;
    long permission;

    permission = PERMISSION_ALL;

    if (options->encrypt != eRC4 &&
        options->encrypt != eAESV2)
        return pdf_not_ok;

    *num = x->xref->cur;
    x->xref->offsets[x->xref->cur] = pdf_stream_tell(out);
    bpt_insert(x->entry, x->xref->cur, (void*)x->xref->cur);
    x->xref->cur++;

    d = dict_new(11);

    if (!d)
        return pdf_not_ok;
    tmp.t = eDict;
    tmp.value.d.dict = d;

    pdf_dict_insert_name(d, "Filter", "Standard");
    pdf_dict_insert_int(d, "V", 4);
    pdf_dict_insert_int(d, "R", 4);
    pdf_dict_insert_int(d, "P", permission);
    pdf_dict_insert_int(d, "Length", 128);

    {
        // inline crypt filter
        cfd = dict_new(11);

        if (!cfd)
            return pdf_not_ok;
        cf.t = eDict;
        cf.value.d.dict = cfd;
        {
            pdf_obj oo;
            /* standard cf */
            std_cfd = dict_new(11);

            if (!std_cfd)
                return pdf_not_ok;
            std_cf.t = eDict;
            std_cf.value.d.dict = std_cfd;


            pdf_dict_insert_name(std_cfd, "AuthEvent", "DocOpen");
            pdf_dict_insert_int(std_cfd, "Length", 16);  // pp68, PDF32000
            if (options->encrypt == eRC4)
            {
                pdf_dict_insert_name(std_cfd, "CFM", "V2");
            }
            else
            {
                pdf_dict_insert_name(std_cfd, "CFM", "AESV2");
            }
            make_key(&oo, "StdCF");
            dict_insert(cfd, (char*)oo.value.k, pdf_obj_copy(&std_cf));
        }
        dict_insert(d, "CF", pdf_obj_copy(&cf));
    }
    pdf_dict_insert_name(d, "StmF", "StdCF");
    pdf_dict_insert_name(d, "StrF", "StdCF");

    pdf_dict_insert_string(d, "O", o, 32);
    pdf_dict_insert_string(d, "U", u, 32);

    pdf_obj_full_write(&tmp, x->xref->cur - 1, 0, x, out, 0, 0, options->flags);

    pdf_obj_delete(&tmp);

    return pdf_ok;
}


pdf_err
pdf_page_save(pdf_doc *doc, int i/* pg# */, pdfcrypto_priv *crypto, char *ofile, pdf_writer_options *options)
{
    pdf_stream* out = 0;
    pdf_obj* info = NULL;
    int startxref;
    pdf_xref_internal *x = 0;
    num_range range;
    char *idstrings[2];
    char idstring[16];
    int info_ref;

    out = pdf_stream_file_open(ofile);
    if (!out)
	    return pdf_ok;
    pdf_magic_write(out, options);
    // scan pages
    x = pdf_xref_internal_create(pdf_obj_count(), doc->count, options);
    if (!x)
	    goto done_0;
    pdf_catalog_write(doc, x, out, crypto, WRITE_CATALOG_DEFAULTS);
    pdf_page_scan(doc->pages[i], x, out, crypto, 0, options->flags);
    pdf_indirect_objs_write(x, out, crypto, 0, options->flags);
    pdf_page_obj_write(doc->pages[i], i, x, crypto, 0, out, options->flags);

    range.bgn = i + 1;
    range.end = i + 1;
    pdf_pages_obj_write(x, &range, 1, out);
    //
    info = pdf_info_create(0);
    info_ref = x->xref->cur;
    if (info)
    {
        int off = pdf_stream_tell(out);
        bpt_insert(x->entry, x->xref->cur, (void*)x->xref->cur);
        pdf_obj_full_write(info, x->xref->cur, 0, x, out, 0, 0, 0);
        x->xref->offsets[x->xref->cur] = off;
        x->xref->cur++;
    }
    // write xref table
    startxref = pdf_xref_write(x, out);
    pdf_id_create(ofile, rand(), info, idstring);
    idstrings[1] = idstring;
    if (doc->trailer->id[0])
        idstrings[0] = doc->trailer->id[0];
    else
        idstrings[0] = idstring;

    pdf_trailer_write(x, startxref, idstrings, info, info_ref,
                      0, 0, // encrypto inst, and encrypt obj num
                      out);

  done_0:
    if (x)
	    pdf_xref_internal_free(x);
    pdf_stream_close(out);
    if (info)
    {
        pdf_obj_delete(info);
        pdf_free(info);
    }
    return pdf_ok;
}

pdf_err
pdf_write_pdf(pdf_doc *doc, char* infile, char *ofile, pdf_writer_options *options)
{
    pdf_err e = pdf_ok;
    char linebuf[1024];
    int i, j, startxref, err, nr;
    num_range *page_ranges, pr[1];
    pdf_xref_internal *x = 0;
    pdfcrypto_priv *crypto = NULL;
    char *odir;
    struct stat s;

    if (options->nr == 0)
    {
        page_ranges = pr;
        pr->bgn = 1;
        pr->end = doc->count - 1;
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
                                     (unsigned char*)doc->trailer->id[0],
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
	    char base[1024];
	    char *b, *b1;
	    // make output directory
#if defined(_MSC_VER)
        {
            char drive[2];
            char dir[1024];
            char fname[1024];
            char ext[1024];

            _splitpath_s(ofile,
                         drive, 2,
                         dir, 1024,
                         fname, 1024,
                         ext, 1024);
            if (dir)
            {
                if (strlen(dir)<1024)
                {
                    memcpy(base, dir, strlen(dir)+1);
                }
                else
                {
                    memcpy(base, dir, 1023);
                    base[1024] = 0;
                }
            }
        }
#else
        // use current dir as base
	    b1 = basename(ofile);
	    b = strchr(b1, '.');
	    if (b || b1)
	    {
            // strip extension
            if (b)
            {
                memcpy(base, b1, b-b1);
                base[b-b1] = 0;
            }
            else
            {
                if (strlen(b1) < 1024)
                {
                    memcpy(base, b1, strlen(b1)+1);
                }
                else
                {
                    memcpy(base, b1, 1023);
                    base[1024] = 0;
                }
            }
	    }
	    else
	    {
            memcpy(base, infile, strlen(infile));
            base[strlen(infile)] = 0;
	    }
#endif
	    odir = base;
	    if ((err = stat(odir, &s)) == 0)
	    {
            if ((!((s.st_mode & S_IFDIR))) && ((s.st_mode & S_IFREG)))
            {
                e = pdf_file_err;
                goto done;
            }
	    }
	    if (err || (!(s.st_mode & S_IFDIR)))
	    {
#ifdef _WIN32
            err = _mkdir(odir);
#else
            err = mkdir(odir, S_IRWXU | S_IRWXG);
#endif
            if (err != 0)
            {
                e = pdf_file_err;
                goto done;
            }

	    }
	    else if (err == 0 && (!(s.st_mode & S_IFDIR)))
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
#else
					b = strrchr(infile, '/');
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
                    pdf_page_save(doc, i, crypto, linebuf, options);
                }
            }
        }
	    if (crypto)
        {
            pdf_crypto_destroy(crypto);
        }
    }
    else
    {
        int n_pages = 0;
        pdf_stream *s;
        int enc_obj_num;
        pdf_obj *info_obj;
        char idstring[16];
        char user_str[32], owner_str[32];
        pdfcrypto_priv *encrypto = 0;
        int info_ref;

        s = pdf_stream_file_open(ofile);
        if (!s)
            return pdf_file_err;

        if (doc->trailer && doc->trailer->info == 0)
        {
            info_obj = pdf_info_create(0);
        }
        else
        {
            info_obj = pdf_info_create(doc->trailer->info);
        }

        pdf_id_create(ofile, rand(), info_obj, idstring);

        if (options->encrypt == eRC4 || options->encrypt == eAESV2)
        {
            encrypto = pdf_crypto_create(options->encrypt,
                                         4, // revision number
                                         16, // key length
                                         options->upass, strlen(options->upass),
                                         idstring, owner_str, user_str
                );

        }

        pdf_magic_write(s, options);
	    // scan pages
	    x = pdf_xref_internal_create(pdf_obj_count(), doc->count, options);
	    if (!x)
            goto done;
	    pdf_catalog_write(doc, x, s, crypto, options->flags);
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
                    page_ranges[j].end = i;
                    break;
                }
                pdf_page_scan(doc->pages[i], x, s, crypto, encrypto, options->flags);
                pdf_indirect_objs_write(x, s, crypto, encrypto, options->flags);
                pdf_page_obj_write(doc->pages[i], i, x, crypto, encrypto, s, options->flags);
                n_pages++;
            }
        }
        pdf_pages_obj_write(x, page_ranges, nr, s);

        info_ref = x->xref->cur;
        if (info_obj)
        {
            int off = pdf_stream_tell(s);
            pdf_obj_full_write(info_obj, x->xref->cur, 0, x, s, 0, 0, options->flags);
            x->xref->offsets[x->xref->cur] = off;
            x->xref->cur++;
        }

        if (encrypto)
        {
            pdf_encrypt_write(x, s, options, ofile, info_obj, &enc_obj_num, owner_str, user_str);
        }

	    // write xref table
	    startxref = pdf_xref_write(x, s);
        // write trailer
        {
            char *idstrs[2];
            idstrs[0] = idstring;
            idstrs[1] = idstring;
            pdf_trailer_write(x, startxref, idstrs, info_obj, info_ref, encrypto, enc_obj_num, s);
        }

        if (info_obj)
        {
            pdf_obj_delete(info_obj);
            pdf_free(info_obj);
        }

      done:
	    if (x)
            pdf_xref_internal_free(x);
	    if (crypto)
            pdf_crypto_destroy(crypto);
        if (encrypto)
            pdf_free(encrypto);

        pdf_stream_close(s);
    }
    return e;
}
