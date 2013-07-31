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
    int page_obj_buf[10240*2];
    int *page_ref_buf;
};

// pdf_xref_table stores the artifects of object writing. to be written out as new xref table.
struct pdf_xref_table_s
{
    int n; // total number of entries
    int cur; // index to current entry
    int *offsets;
};

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
    x->xref->offsets = pdf_malloc(sizeof(int)*n);
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
    pdf_free(x);
}

static
pdf_xref_internal *
pdf_xref_internal_append(pdf_xref_internal *x, int n, int g)
{
    // ignore generation number for now.
    int a;
    a = (int)bpt_search(x->entry, n);
    if (a == 0)
    {
	    bpt_insert(x->entry, n, (void*)-1);
	    x->n += 1;
    }
    return x;
}

static void
pdf_oc_write(pdf_ocproperties *oc, pdf_xref_internal *x, FILE *o)
{
}

static
void
pdf_catalog_write(pdf_doc *doc, pdf_xref_internal *x, FILE *o)
{
    x->xref->cur = 2;
    x->xref->offsets[x->xref->cur] = ftell(o);
    fprintf(o, "%d %d obj\n", 2, 0);
    fprintf(o, "%s\n", "<<");
    fprintf(o, "%s\n", "/Type /Catalog");
    fprintf(o, "/Pages %d %d R\n",1, 0);
    if (doc->ocproperties)
    {
        pdf_oc_write(doc->ocproperties, x, o);
    }
    fprintf(o, "%s\n", ">>");
    fprintf(o, "%s\n", "endobj");
    x->xref->cur ++;
}

static
void
pdf_pages_obj_write(pdf_xref_internal *x, int pg1st, int num, FILE *o)
{
    int i;
    x->xref->offsets[1] = ftell(o);
    fprintf(o, "%d %d obj\n", 1, 0);
    fprintf(o, "%s\n", "<<");
    fprintf(o, "%s\n", "/Type /Pages");
    fprintf(o, "/Count %d\n", num);
    fprintf(o, "/Kids [\n");
    for (i = 0; i < num; i++)
    {
	    fprintf(o, "%d %d R\n", x->page_ref_buf[i+pg1st], 0);
    }
    fprintf(o, "]\n");
    fprintf(o, "%s\n", ">>");
    fprintf(o, "%s\n", "endobj");
}

static
int
pdf_xref_write(pdf_xref_internal *x, FILE *o)
{
    int i, startxref;
    startxref = ftell(o);
    fprintf(o, "%s\n", "xref");
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
    fprintf(o, "%s\n", "trailer");
    fprintf(o, "%s\n", "<<");
    fprintf(o, "/Size %d\n", x->xref->cur);
    fprintf(o, "/Root %d %d R\n", 2, 0);
    fprintf(o, "%s\n", ">>");
    fprintf(o, "%s\n", "startxref");
    fprintf(o, "%d\n", startxref);
    fprintf(o, "%s\n", "%%EOF");
}

static void
pdf_key_int_write(char *k, int i, pdf_xref_internal *x, FILE *f, pdfcrypto_priv *crypto)
{
    fprintf(f, "/%s %d\n", k, i);
}

static void
pdf_obj_write(pdf_obj* o, pdf_xref_internal *x, FILE *f, pdfcrypto_priv *crypto)
{
    int i;
    if (!o)
        return;
    switch (o->t)
    {
        case eBool:
            fprintf(f, "%s ", o->value.b?"true":"false");
            break;
        case eInt:
            fprintf(f, "%d ", o->value.i);
            break;
        case eReal:
            fprintf(f, "%f ", o->value.f);
            break;
        case eKey:
        case eName:
            fprintf(f, "/%s ", o->value.k);
            break;
        case eString:
            fprintf(f, "%s", "(");
            if (crypto)
            {
                pdf_stream *s = pdf_stream_load(o, crypto, x->page_obj_buf[x->cur_idx], 0);
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
            fprintf(f, "%s", ")");
            break;
	    case eHexString:
            fprintf(f, "\n%s", "<");
            if (crypto)
            {
                pdf_stream *s = pdf_stream_load(o, crypto, x->page_obj_buf[x->cur_idx], 0);
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
            fprintf(f, "%s", ">");
            break;
        case eDict:
        {
            dict_list *ll, *l = dict_to_list(o->value.d.dict);
            sub_stream *strm = o->value.d.dict->stream;
            int strmlen = 0;
            int last_off = 0;
            ll = l;
            fprintf(f, "%s", "<<");
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
                    if (crypto)
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
                    // For NOW, we write plain stream whenever crypto is present
                    if (crypto)
                    {
                        l = l->next;
                        continue;
                    }
                }
                fprintf(f, " /%s ", l->key);
                pdf_obj_write(&l->val, x, f, crypto);
                l = l->next;
            }
            fprintf(f, "%s", ">>");
            if (strm && crypto)
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
                s = pdf_stream_load(o, crypto, obj, gen);
                if (s)
                {
                    int c;
                    int curx;
                    int strmoff;
                    int ll;
                    fprintf(f, "%s\n", "stream");
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
                    fprintf(out, "endstream\n");
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
                fprintf(f, "%s\n", "stream");
                strm->len = strmlen;
                while (strm->read(strm, &c, 1))
                    fputc(c, f);
                strm->close(strm, 1);
                fprintf(f, "\n%s\n", "endstream");
            }
            dict_list_free(ll);
        }
        break;
        case eArray:
        {
            int i;
            fprintf(f, "%s", "[");
            for (i = 0; i < o->value.a.len; i++)
            {
                pdf_obj_write(&o->value.a.items[i], x, f, crypto);
            }
            fprintf(f, "%s", "]");
        }
        break;
        case eRef:
        {
            int a = (int)bpt_search(x->entry, o->value.r.num);
            if (a > 0)
            {
                fprintf(f, "%d %d R ", a, o->value.r.gen);
            }
            else
            {
                // write direct object
                pdf_obj *d = pdf_obj_deref(o);
                if (d)
                {
                    pdf_obj_write(d, x, f, crypto);
                }
                else
                { // Now we are screw'd, the reader will complain ref out of range
                    fprintf(f, "%d %d R ", o->value.r.num, o->value.r.gen);
                }
            }
        }
        break;
        default:
            break;
    }
}

static void
pdf_key_obj_write(char *k, pdf_obj *o, pdf_xref_internal *x, FILE *f, pdfcrypto_priv *crypto)
{
    fprintf(f, "/%s ", k);
    pdf_obj_write(o, x, f, crypto);

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
    fprintf(out, "%d 0 obj\n", xref->xref->cur);
    if (write_flag & WRITE_PDF_CONTENT_INFLATE)
    {
	    int obj = 0, gen = 0;
	    pdf_stream *s;
	    sub_stream *ss;
	    ss = (sub_stream*)cobj->value.d.dict->stream;
	    if (ss)
	    {
            obj = ss->obj;
            gen = ss->gen;
	    }
	    s = pdf_stream_load(cobj, crypto, obj, gen);
	    if (s)
	    {
            int c;
            int curx;
            int strmoff;
            int ll;
            int empty = (s->length)?0:1;

            fputs("<<\n", out);
            if (!empty) {
                fputs("/Length            \n", out);
                ll = ftell(out) - 11;
            }
            else
                fprintf(out, "/Length %d\n", 0);

            fputs(">>stream\n", out);
            strmoff = ftell(out);
            //
            if (!empty)
            {
                while ((c = pdf_stream_getchar(s)) != EOF)
                    fputc(c, out);
            }
            pdf_stream_free(s, 1);
            //
            if (!empty) {
                curx = ftell(out);
                fseek(out, ll, SEEK_SET);
                fprintf(out, "%10d", curx - strmoff);
                fseek(out, curx, SEEK_SET);
            }
            fputs("endstream\n", out);
	    }
	    else
	    {
            pdf_obj_write(cobj, xref, out, crypto);
	    }
    }
    else
    {
	    pdf_obj_write(cobj, xref, out, crypto);
    }
    fprintf(out, "%s\n", "endobj");
    xref->xref->offsets[xref->xref->cur] = off;
    xref->xref->cur ++;
    return content_ref;
}

static
void
pdf_group_write(pdf_group *g, pdf_xref_internal *x, FILE *o, pdfcrypto_priv *crypto)
{
    if (!g)
        return;
    fprintf(o, "/%s<<", "Group");
    if (g->cs)
    {
	    pdf_key_obj_write("CS", g->cs, x, o, crypto);
    }
    pdf_key_int_write("I", g->i, x, o, crypto);
    pdf_key_int_write("K", g->k, x, o, crypto);
    fprintf(o, ">>\n");
}

static
void
pdf_resources_write(pdf_resources *r, pdf_xref_internal *x, FILE *o, pdfcrypto_priv *crypto)
{
    fprintf(o, "%s <<", "/Resources");
    if (r->extgstate)
    {
        dict_list *ll, *l;
	    pdf_obj *extg = r->extgstate;
	    pdf_obj_resolve(extg);
	    if (extg && extg->t == eDict)
	    {
            l = dict_to_list(extg->value.d.dict);
            ll = l;
            fprintf(o, "%s <<", "/ExtGState");
            while (l && l->key)
            {
                pdf_obj *t = &l->val;
                dict_array *a;
                if (t->t == eRef)
                    pdf_obj_resolve(t);
                assert(t->t == eDict);
                a = dict_to_array(t->value.d.dict);
                fprintf(o, "/%s <<", l->key);
                if (a)
                {
                    // print dict array "a"
                    if (a->items)
                    {
                        int i;
                        for (i = 0; i < a->cur; i++)
                        {
                            fprintf(o, "/%s ",a->items[i].key);
                            pdf_obj_write(&a->items[i].val, x, o, crypto);
                        }
                    }
                    // free array/dict_entry
                    if (a->items)
                    {
                        int i;
                        for (i = 0; i < a->cur; i++)
                            pdf_free(a->items[i].key);
                        pdf_free(a->items);
                    }
                    pdf_free(a);
                }
                fprintf(o, "%s", ">>");
                l = l->next;
            }
            // free dict_list
            dict_list_free(ll);
            fprintf(o, "%s",  ">>");
	    }
    } // extgstate
    if (r->font)
    {
        pdf_obj *font = r->font;
        pdf_obj_resolve(font);
        fprintf(o, "%s", "/Font");
        pdf_obj_write(font, x, o, crypto);
        fprintf(o, "%s", "\n");
    }
    if (r->xobject)
    {
        pdf_obj_resolve(r->xobject);
        fprintf(o, "%s", "/XObject");
        pdf_obj_write(r->xobject, x, o, crypto);
        fprintf(o, "%s", "\n");
    }
    if (r->colorspace)
    {
        pdf_obj_resolve(r->colorspace);
        fprintf(o, "%s", "/ColorSpace");
        pdf_obj_write(r->colorspace, x, o, crypto);
        fprintf(o, "%s", "\n");
    }
    if (r->shading)
    {
        pdf_obj_resolve(r->shading);
        fprintf(o, "%s", "/Shading");
        pdf_obj_write(r->shading, x, o, crypto);
        fprintf(o, "%s", "\n");
    }
    if (r->pattern)
    {
        pdf_obj_resolve(r->pattern);
        fprintf(o, "%s", "/Pattern");
        pdf_obj_write(r->pattern, x, o, crypto);
        fprintf(o, "%s", "\n");
    }
    // end resources
    fprintf(o, "%s",  ">>\n");
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
            pdf_obj *d = pdf_obj_deref(o);
            pdf_obj_scan(d, x);
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
                    // recursively scan this obj for more refs
                    pdf_obj_scan(&l->val, x);
                    pdf_xref_internal_append(x, l->val.value.r.num, l->val.value.r.gen);
                    x->page_obj_buf[x->page_obj_idx] = l->val.value.r.num;
                    x->page_obj_idx ++;
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
                    pdf_obj_scan(oo, x);
                    pdf_xref_internal_append(x, oo->value.r.num, oo->value.r.gen); // insert a dummy
                    x->page_obj_buf[x->page_obj_idx] = oo->value.r.num;
                    x->page_obj_idx ++;
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
    if (r->extgstate)
    {
        // scan for indirect objs
        pdf_obj *gs = r->extgstate;
        pdf_obj_resolve(gs);
        if (gs->t == eDict)
        {
            dict_list *ll, *l = dict_to_list(gs->value.d.dict);
            ll = l;
            while (l && l->key)
            {
                pdf_obj *thisgs = &l->val;
                if (l->val.t == eRef)
                    thisgs = pdf_obj_deref(&l->val);
                if (thisgs && thisgs->t == eDict)
                {
                    pdf_obj_scan(thisgs, x);
                }
                l = l->next;
            }
            // free list
            dict_list_free(ll);
        }
    }
    if (r->font)
    {
        pdf_obj *font = r->font;
        pdf_obj_resolve(font);
        if (font->t == eDict)
        {
            dict_list *ll, *l = dict_to_list(font->value.d.dict);
            ll = l;
            while (l && l->key)
            {
                if (l->val.t == eRef)
                {
                    // recursively scan this obj for more refs
                    pdf_obj_scan(&l->val, x);
                    pdf_xref_internal_append(x, l->val.value.r.num, l->val.value.r.gen);
                    x->page_obj_buf[x->page_obj_idx] = l->val.value.r.num;
                    x->page_obj_idx ++;
                }
                else if (l->val.t == eDict || l->val.t == eArray)
                {
                    pdf_obj_scan(&l->val, x);
                }
                l = l->next;
            }
            // free list
            dict_list_free(ll);
        }
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
}

static
void
pdf_page_scan(pdf_page* pg, pdf_xref_internal* x)
{
    if (!pg)
        return;
    x->page_obj_idx = 0;
    if (pg->resources)
    {
        pdf_resources_scan(pg->resources, x);
    }
    if (pg->group)
    {
        pdf_obj_scan(pg->group->cs, x);
    }
    //if (pg->contents) // conflicting with content writer
    // pdf_page_contents_write() resolves and write contents array
    if (0)
    {
	    pdf_obj_resolve(pg->contents);
	    if (pg->contents->t == eArray)
	    {
            pdf_obj_scan(pg->contents, x);
	    }
    }
}

// Writing out page content which is an array of references.
static
void
pdf_write_indirect_objs(pdf_xref_internal *xref, FILE *out, pdfcrypto_priv *crypto)
{
    if (xref->page_obj_idx)
    {
        int i;
	    // backward scanning to meet dependency
        for (i = 0; i < xref->page_obj_idx; i++)
        {
            int a = (int)bpt_search(xref->entry, xref->page_obj_buf[i]);
            if (a == -1) // -1 means new item in the output tree, means need to be flushed out.
            {
                pdf_obj *o = pdf_obj_find(xref->page_obj_buf[i], 0);
                xref->cur_idx = i;
                xref->xref->offsets[xref->xref->cur] = ftell(out);
                fprintf(out, "%d 0 obj\n", xref->xref->cur);
                pdf_obj_write(o, xref, out, crypto);
                fprintf(out, "\n%s\n", "endobj");
                // update entry
                bpt_insert(xref->entry, xref->page_obj_buf[i], (void*)xref->xref->cur);
                // inc new xref counter
                xref->xref->cur ++;
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
    if (!page)
        return;
    if (page->contents)
    {
	    pdf_obj *contents = pdf_obj_deref(page->contents);
	    if (contents->t == eDict)
	    {
            content_ref = pdf_page_contents_write(contents, write_flag, xref, out, crypto);
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
                content_ref_arr[i] = pdf_page_contents_write(&contents->value.a.items[i], write_flag, xref, out, crypto);
	    }
    }
    if (content_ref == -1 && content_num == 0)
	    return;
    xref->xref->offsets[xref->xref->cur] = ftell(out);
    fprintf(out, "%d 0 obj\n", xref->xref->cur);
    xref->page_ref_buf[pgidx] = xref->xref->cur;
    xref->xref->cur ++;
    fprintf(out, "%s\n", "<<");
    fprintf(out, "%s\n", "/Type /Page");
    fprintf(out, "%s [%f %f %f %f]\n", "/MediaBox", page->mediabox.x0, page->mediabox.y0,  page->mediabox.x1, page->mediabox.y1);
    if (page->resources)
    {
        pdf_resources_write(page->resources, xref, out, crypto);
    }
    if (page->group)
    {
        pdf_group_write(page->group, xref, out, crypto);
    }
    if (content_ref != -1)
    {
	    fprintf(out, "/Contents %d %d R\n", content_ref, 0);
    }
    else
    {
	    int i;
	    fprintf(out, "/Contents [");
	    for (i = 0; i < content_num; i++)
	    {
            fprintf(out, "%d %d R ", content_ref_arr[i], 0);
	    }
	    fprintf(out, "]");
    }
    fprintf(out, "\n%s\n", ">>");
    fprintf(out, "%s\n", "endobj");
}

pdf_err
pdf_page_write(pdf_doc *doc, int i/* pg# */, unsigned long write_flag, pdfcrypto_priv *crypto, int version, char *outf)
{
    FILE* out = 0;
    char buf[128];
    int startxref;
    pdf_xref_internal *xref = 0;

    out = fopen(outf, "wb");
    if (!out)
	    return pdf_ok;
    sprintf(buf, "%%PDF-%d.%d\n", version/10, version%10);
    fputs(buf, out);
    fputs("%\333\332\331\330\n", out);
    // scan pages
    xref = pdf_xref_internal_create(pdf_obj_count(), doc->count);
    if (!xref)
	    goto done_0;
    pdf_catalog_write(doc, xref, out);
    pdf_page_scan(doc->pages[i], xref);
    pdf_write_indirect_objs(xref, out, crypto);
    pdf_page_obj_write(doc->pages[i], i, write_flag, xref, crypto, out);

    pdf_pages_obj_write(xref, i, 1, out);
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
pdf_write_pdf(pdf_doc *doc, char* infile, char *ofile, unsigned long write_flag, int version, int pg1st, int pglast, char *upw, char *opw)
{
    pdf_err e = pdf_ok;
    FILE* out = 0;
    char linebuf[1024];
    int i, startxref, err;
    pdf_xref_internal *xref = 0;
    pdfcrypto_priv *crypto = NULL;
    char *odir;
    struct stat s;
    if (pg1st < 0)
        pg1st = 0;
    if (pglast < 0)
        pglast = doc->count-1;
    if (pglast < pg1st)
        pglast = pg1st;
    if (!ofile && (!(write_flag&WRITE_PDF_PAGE_SEPARATION)))
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
    if (write_flag&WRITE_PDF_PAGE_SEPARATION)
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
        pglast = doc->count-1;
	    for (i = pg1st; i <= pglast; i++)
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
#if 1
            pdf_page_write(doc, i, write_flag, crypto, version, linebuf);
#else
            out = fopen(linebuf, "wb");
            if (!out)
                return pdf_ok;
            sprintf(linebuf, "%%PDF-%d.%d\n", version/10, version%10);
            fputs(linebuf, out);
            fputs("%\333\332\331\330\n", out);
            // scan pages
            xref = pdf_xref_internal_create(pdf_obj_count(), doc->count);
            if (!xref)
                goto done_0;
            pdf_catalog_write(doc, xref, out);
            pdf_page_scan(doc->pages[i], xref);
            pdf_write_indirect_objs(xref, out, crypto);
            pdf_page_obj_write(doc->pages[i], i, write_flag, xref, crypto, out);

            pdf_pages_obj_write(xref, i, 1, out);
            // write xref table
            startxref = pdf_xref_write(xref, out);
            pdf_trailer_write(xref, startxref, out);
            // done
	      done_0:
            if (xref)
                pdf_xref_internal_free(xref);
            fclose(out);
#endif
	    }
	    if (crypto)
            pdf_crypto_destroy(crypto);
    }
    else
    {
#ifdef DEBUG
	    printf("Writing %s..\n", ofile);
#endif
	    out = fopen(ofile, "wb");
	    if (!out)
            return pdf_ok;
	    sprintf(linebuf, "%%PDF-%d.%d\n", version/10, version%10);
	    fputs(linebuf, out);
	    fputs("%\333\332\331\330\n", out);
	    // scan pages
	    xref = pdf_xref_internal_create(pdf_obj_count(), doc->count);
	    if (!xref)
            goto done;
	    pdf_catalog_write(doc, xref, out);
	    for (i = pg1st; i <= pglast; i++)
	    {
            pdf_page_scan(doc->pages[i], xref);
            pdf_write_indirect_objs(xref, out, crypto);
            pdf_page_obj_write(doc->pages[i], i, write_flag, xref, crypto, out);
	    }
	    pdf_pages_obj_write(xref, pg1st, pglast-pg1st+1, out);
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
