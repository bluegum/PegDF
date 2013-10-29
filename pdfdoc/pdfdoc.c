#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "dict.h"
#include "pdftypes.h"
#include "pdfindex.h"
#include "pdfmem.h"
#include "pdffilter.h"
#include "pdfdoc.h"
#include "pdfcrypto.h"
#include "pdfread.h"
#include "pdffont.h"
#include "pdfdevice.h"
#include "pdf_priv.h"

static void pdf_gstate_init(pdf_page* p);

static inline pdf_group*
pdf_group_load(pdf_obj *o)
{
    pdf_group *g;
    if (!o)
        return NULL;
    g = pdf_malloc(sizeof(pdf_group));
    if (!g)
        return NULL;
    memset(g, 0, sizeof(pdf_group));
    g->cs = pdf_dict_get(o, "CS");
    g->i = pdf_to_int(pdf_dict_get(o, "I"));
    g->k = pdf_to_int(pdf_dict_get(o, "K"));
    return g;
}
pdf_err
pdf_group_free(pdf_group *g)
{
    pdf_free(g);
    return pdf_ok;
}

pdf_err pdf_page_load(pdf_doc *doc, pdf_obj *o, pdf_page **page)
{
    pdf_page *p;
    pdf_obj *mediabox;
    pdf_obj *v;

    if (o->t != eRef)
        return pdf_syntax_err;
    *page = pdf_malloc(sizeof(pdf_page));
    p = *page;
    memset(p, 0, sizeof(pdf_page));
    p->ref = *o;
    // parse tree dict
    p->parent = pdf_dict_get(o, "Parent");
    mediabox = pdf_dict_get(o, "MediaBox");
    if (mediabox)
        p->mediabox = pdf_rect_get(mediabox);
    else
    {
        gs_rect *r = doc->get_mediabox(doc);
        if (r)
            p->mediabox = *r;
    }
    p->resources = pdf_resources_load(pdf_dict_get(o, "Resources"));
    // optionals
    p->contents = pdf_dict_get(o, "Contents");
    v = (pdf_obj*)pdf_dict_get(o, "Rotate");
    if (v)
    {
        p->rotate = v->value.i;
        if (p->rotate < 0)
            p->rotate = 360 - ((-p->rotate) % 360);
        if (p->rotate >= 360)
            p->rotate = p->rotate % 360;
        p->rotate = 90*((p->rotate + 45)/90);
        if (p->rotate > 360)
            p->rotate = 0;
        if (p->rotate == 90 || p->rotate == 270)
        {
            float x = p->mediabox.y1;
            p->mediabox.y1 =  p->mediabox.x1;
            p->mediabox.x1 = x;
        }
    }
    p->group = pdf_group_load(pdf_dict_get(o, "Group"));
    p->cropbox = pdf_dict_get(o, "CropBox");
    p->bleedbox = pdf_dict_get(o, "BleedBox");
    p->trimbox = pdf_dict_get(o, "TrimBox");
    p->artbox = pdf_dict_get(o, "ArtBox");
    p->boxcolorinfo = pdf_dict_get(o, "BoxColorInfo");
    p->thumb = pdf_dict_get(o, "Thumb");
    p->b = pdf_dict_get(o, "b");
    p->dur = pdf_to_float(pdf_dict_get(o, "Dur"));
    p->trans = pdf_dict_get(o, "Trans");

    p->annots = pdf_annots_load(pdf_dict_get(o, "Annots"));
    p->aa = pdf_dict_get(o, "AA");

    p->metadata = pdf_dict_get(o, "Metadata");
    p->pieceinfo = pdf_dict_get(o, "PieceInfo");
    p->structparents = pdf_to_int(pdf_dict_get(o, "StructParents"));
    p->id = pdf_to_int(pdf_dict_get(o, "ID"));
    p->pz = pdf_to_float(pdf_dict_get(o, "PZ"));
    p->separationinfo = pdf_dict_get(o, "SeparationInfo");
    p->tabs = pdf_dict_get(o, "Tabs");
    p->templateinstantiated = pdf_dict_get(o, "TemplateInstantiated");
    p->pressteps = pdf_dict_get(o, "PresSteps");
    p->userunit = pdf_to_float(pdf_dict_get(o, "UserUnit"));
    p->vp = pdf_dict_get(o, "VP");
    // required depends
    p->lastmodified = pdf_dict_get(o, "LastModified");
    return pdf_ok;
}

pdf_err pdf_page_free(pdf_page *page)
{
    if (!page)
        return pdf_ok;
    if (page->resources)
    {
        pdf_resources_free(page->resources);
    }
    if (page->annots)
    {
        pdf_annots_free(page->annots);
    }
    if (page->group)
    {
        pdf_group_free(page->group);
    }
    pdf_free(page);
    return pdf_ok;
}

// Load into a flat array instead of tree
pdf_err pdf_page_tree_load(pdf_doc *d, pdf_obj *o)
{
    int i;
    pdf_obj *a, *kids = o;
    if (o->t == eRef)
    {
        a = pdf_dict_get(o, "Type");
        if (!a)
            return pdf_ok;
        if (obj_is_name(a) && a->value.k)
        {
            if (strcmp(a->value.k, "Pages") == 0)
            {
                kids = pdf_dict_get(o, "Kids");
                if (!kids || ((kids->t != eArray) && (kids->t != eRef)))
                    return pdf_ok;
            }
            else if (strcmp(a->value.k, "Page") == 0)
            {
                pdf_page_load(d, o, &d->pages[d->pageidx]);
                d->pageidx += 1;
                return pdf_ok;
            }
            else
            {
                return pdf_ok;
            }
        }
        else
        {
            return pdf_ok;
        }
    }
    if (kids->t == eDict || kids->t == eRef)
    {
        pdf_page_load(d, kids, &d->pages[d->pageidx]);
        d->pageidx += 1;
    }
    else if (kids->t == eArray)
    {
        for (i = 0; i < kids->value.a.len; i++)
        {
            pdf_obj a;
            a = kids->value.a.items[i];
            if (a.t == eRef)
            {
                pdf_page_tree_load(d, &a);
            }
        }
    }

    return pdf_ok;
}

pdf_err pdf_exec_page_content(pdf_page *p, pdfcrypto_priv* encrypt)
{
    pdf_stream *s = NULL, *first;
    if (!p)
        return pdf_ok;
    if (!p->contents)
        return pdf_ok;
    if (p->contents->t != eDict && p->contents->t != eRef && p->contents->t != eArray)
        return pdf_ok;
    // reset graphics state
    p->s = p->sstk;
    pdf_gstate_init(p);
    // run page contents
    return pdf_cs_parse(p, encrypt, 0);
}

pdf_err pdf_page_tree_walk(pdf_doc *d, pdf_device *dev, pdfcrypto_priv* encrypt)
{
    int i, c;
    pdf_interp_state *interp;
    pdf_err e = pdf_ok;

    interp = pdf_interpreter_new(dev, encrypt);
    c = (d->pageidx < d->count) ? d->pageidx : d->count;
    for (i = 0; i < c; i++)
    {
#ifdef DEBUG
        printf("processing page#%d\n", i);
#endif
        d->pages[i]->i = interp;
        if (dev)
            (dev->page_begin)(dev, i, d->pages[i]->mediabox.x1, d->pages[i]->mediabox.y1);
        e = pdf_exec_page_content(d->pages[i], encrypt);
        if (dev)
            (dev->page_end)(dev);
#ifdef DEBUG
        printf("%s", "\n");
#endif
        if (e != pdf_ok)
            break;
    }
    pdf_interpreter_free(interp);
    return e;
}

// The purpose of having private doc struct is to provide members to be referenced by other objects, however
// the referencing is actually forced to perform a copy on referencing, so the private members stay atomic and invisible.
// private members also can only be accessed by a read_only member function of the public API.
typedef struct pdf_doc_private_s
{
    pdf_doc doc;
    gs_rect mediabox;
} pdf_doc_private;

static
gs_rect* pdf_doc_get_mediabox(pdf_doc* doc)
{
    pdf_doc_private *pdoc = (pdf_doc_private*)doc;
    return &pdoc->mediabox;
}

pdf_doc*
pdf_doc_load(pdf_trailer *trailer)
{
    pdf_obj *a, *d, *c, *kids, *oc;
    pdf_doc *doc;
    pdf_doc_private *pdoc;
    int count;
    if (!trailer)
        return NULL;
    d = trailer->root_obj;
    if (!d || d->t != eRef)
        return NULL;

    a = pdf_dict_get(d, "Pages");
    if (!a)
        return NULL;
    count = pdf_to_int(pdf_dict_get(a, "Count"));
    if (!count)
        return NULL;
    pdoc = doc = pdf_malloc(sizeof(pdf_doc_private));
    if (!doc)
        return NULL;
    memset(doc, 0, sizeof(pdf_doc));
    doc->root_ref = d->value.r.num;
    if (a->t == eRef)
        doc->pages_ref = a->value.r.num;
    doc->count = count;
    c = pdf_dict_get(a, "MediaBox");
    if (c)
    {
        pdoc->mediabox = pdf_rect_get(c);
        doc->get_mediabox = pdf_doc_get_mediabox;
    }
    else
    {
        doc->get_mediabox = null_val;
    }
    kids = pdf_dict_get(a, "Kids");
    if (!kids || (kids->t != eArray && kids->t != eRef))
    {
        pdf_free(doc);
        return NULL;
    }
    doc->pages = pdf_malloc(sizeof(pdf_page*) * doc->count);
    memset(doc->pages, 0, (sizeof(pdf_page*) * doc->count));
    doc->pageidx = 0;
    // optional content
    oc = pdf_dict_get(d, "OCProperties");
    if (oc)
    {
        doc->ocproperties = pdf_ocproperties_load(oc);
    }
    doc->version = pdf_dict_get(d, "Version");
    doc->extentions = pdf_dict_get(d, "Extentions");
    doc->pagelabels = pdf_dict_get(d, "PageLabels");
    doc->names = pdf_dict_get(d, "Names");
    doc->dests = pdf_dict_get(d, "Dests");
    doc->viewerpreferences = pdf_dict_get(d, "ViewerPreferences");
    doc->pagelayout = pdf_dict_get(d, "PageLayout");
    doc->pagemode = pdf_dict_get(d, "PageMode");
    doc->outlines = pdf_dict_get(d, "Outlines");
    doc->threads = pdf_dict_get(d, "Threads");
    doc->openaction = pdf_dict_get(d, "OpenAction");
    doc->aa = pdf_dict_get(d, "AA");
    doc->uri = pdf_dict_get(d, "URI");
    doc->acroform = pdf_dict_get(d, "AcroForm");
    doc->metadata = pdf_dict_get(d, "Metadata");
    doc->structtreeroot = pdf_dict_get(d, "StructTreeRoot");
    doc->markinfo = pdf_dict_get(d, "MarkInfo");
    doc->lang = pdf_dict_get(d, "Lang");
    doc->spiderinfo = pdf_dict_get(d, "SpiderInfo");
    doc->outputintents = pdf_dict_get(d, "OutputIntents");
    doc->pieceinfo = pdf_dict_get(d, "PieceInfo");
    doc->perms = pdf_dict_get(d, "Perms");
    doc->legal = pdf_dict_get(d, "Legal");
    doc->requirements = pdf_dict_get(d, "Requirements");
    doc->collection = pdf_dict_get(d, "Collection");
    a = pdf_dict_get(d, "NeedsRendering");
    if (a) {
        doc->needsrendering = pdf_to_int(pdf_dict_get(d, "NeedsRendering"));
    }
    //
    pdf_page_tree_load(doc, kids);
    /// shuffle in some auxillary info
    ///
    doc->trailer = trailer;
    doc->encrypt = trailer->encrypt;
    //doc->info = trailer->info; // pass info as member of doc
    //doc->encrypt = trailer->encrypt; // pass encrypt
    //trailer->encrypt = NULL; // TODO: move it out
    return doc;
}

pdf_err pdf_doc_process(pdf_doc *d, pdf_device *dev, pdfcrypto_priv* encrypt)
{
    pdf_err e;
    if (dev)
        dev->doc_begin(dev, d->trailer->info);
    e = pdf_page_tree_walk(d, dev, encrypt);
    if (dev)
        (dev->doc_end)(dev);
    return e;
}

pdf_err  pdf_doc_print_info(pdf_doc *d)
{
    if (!d)
        return pdf_ok;
    if (d->trailer->info)
        pdf_info_print(d->trailer->info);
    return pdf_ok;
}

void pdf_doc_done(pdf_doc *d)
{
    int i;
    if (!d)
        return;
    for (i = 0; i < d->count; i++)
    {
        pdf_page_free(d->pages[i]);
    }
    pdf_doc_trailer_free(d->trailer);
    pdf_free(d->pages);
    pdf_ocproperties_free(d->ocproperties);
    pdf_free(d);
}

pdf_err
pdf_info_load(pdf_obj *o, pdf_info **info)
{
    pdf_obj *a;
    pdf_info *i;

    if (!o)
        return pdf_ok;
    *info = pdf_malloc(sizeof(pdf_info));
    if (!*info)
        return pdf_ok;

    i = *info;
    memset(*info, 0, sizeof(pdf_info));
    if (a = pdf_dict_get(o, "Title"))
    {
        i->title = pdf_obj_full_copy(a);
    }
    if (a = pdf_dict_get(o, "Author"))
    {
        i->author = pdf_obj_full_copy(a);
    }
    if (a = pdf_dict_get(o, "Subject"))
    {
        i->subject = pdf_obj_full_copy(a);
    }
    if (a = (pdf_obj*)pdf_dict_get(o, "Keywords"))
    {
        i->keywords = pdf_obj_full_copy(a);
    }
    if (a = (pdf_obj*)pdf_dict_get(o, "Creator"))
    {
        i->creator = pdf_obj_full_copy(a);
    }
    if (a = pdf_dict_get(o, "Producer"))
    {
        i->producer = pdf_obj_full_copy(a);
    }

    a = pdf_dict_get(o, "CreationDate");
    if (a) {i->creationdate = pdf_malloc(a->value.s.len+1); memcpy(i->creationdate, a->value.s.buf, a->value.s.len); i->creationdate[a->value.s.len] = 0;}
    a = pdf_dict_get(o, "ModDate");
    if (a) {i->moddate = pdf_malloc(a->value.s.len+1); memcpy(i->moddate, a->value.s.buf, a->value.s.len); i->moddate[a->value.s.len] = 0;}
    if (a = pdf_dict_get(o, "Trapped"))
    {
        i->trapped = pdf_obj_full_copy(a);
    }
    return pdf_ok;
}

pdf_err pdf_info_print(pdf_info *info)
{
    if (info->title)
        printf("Title:%s\n", info->title->value.s.buf);
    if (info->author)
        printf("Auther:%s\n", info->author->value.s.buf);
    if (info->subject)
        printf("Subject:%s\n", info->subject->value.s.buf);
    if (info->keywords)
        printf("Keywords:%s\n", info->keywords->value.s.buf);
    if (info->creator)
        printf("Creator:%s\n", info->creator->value.s.buf);
    if (info->producer)
        printf("Producer:%s\n", info->producer->value.s.buf);
    if (info->creationdate)
        printf("CreationDate:%s\n", info->creationdate);
    if (info->moddate)
        printf("ModDate:%s\n", info->moddate);
    if (info->trapped)
    {
        printf("Trapped=??");
    }
    return pdf_ok;
}

// Load crypt_filter
pdf_err
pdf_cf_load(pdf_encrypt* e, pdf_obj *o, char *name, pdfcrypto_priv **cf)
{
    pdf_obj *a;
    pdfcrypto_algorithm algo;
    authevent event;
    int len;


    *cf = 0;
    if (!o)
        return pdf_ok;
    if (!obj_is_name(o) && o->t != eDict)
        return pdf_ok;
    if (obj_is_name(o) &&
        strcmp(o->value.k, "Identity") == 0)
        return pdf_ok;
    if (obj_is_name(o))
        return pdf_ok;
    a = pdf_dict_get(o, name);
    if (!a)
        return pdf_ok;
    o = a;

    a = pdf_dict_get(o, "CFM");
    algo = eRC4;
    if (a && obj_is_name(a))
    {
        if (strcmp(a->value.k, "V2") == 0)
        {
            algo = eRC4;
        }
        else if (strcmp(a->value.k, "None") == 0)
        {
            algo = eNotBeUsed;
        }
        else if (strcmp(a->value.k, "AESV2") == 0)
        {
            algo = eAESV2;
        }
        else if (strcmp(a->value.k, "AESV3") == 0)
        {
            algo = eAESV3;
        }
        else
        {
            algo = eUnpublished;
        }
    }
    a = pdf_dict_get(o, "AuthEvent");
    if (a && obj_is_name(a))
    {
        if (strcmp(a->value.k, "EFOpen") == 0)
        {
            event = eEFOpen;
        }
        else if (strcmp(a->value.k, "DocOpen") == 0)
        {
            event = eDocOpen;
        }
    }
    len = e->length;
    a = pdf_dict_get(o, "Length");
    if (a && a->t == eInt)
    {
        len = a->value.i*8;
    }
    *cf = pdfcrypto_new(algo, event, len);
    if (!*cf)
        return pdf_mem_err;
    return pdf_ok;
}


pdf_err
pdf_encrypt_load(pdf_obj *o, pdf_encrypt **encrypt)
{
    pdf_obj *a;
    pdf_encrypt *e;
    if (!o)
        return pdf_ok;
    pdf_obj_resolve(o);
    if (!o)
        return pdf_ok;
    *encrypt = pdf_malloc(sizeof(pdf_encrypt));
    if (!*encrypt)
        return pdf_mem_err;
    memset(*encrypt, 0, sizeof(pdf_encrypt));
    e = *encrypt;
    e->v = 0;
    a = pdf_dict_get(o, "Filter");
    if (a)
    {
        pdf_obj_resolve(a);
        (*encrypt)->filter = pdf_malloc(strlen(a->value.k)+1);
        memcpy((*encrypt)->filter, a->value.k, strlen(a->value.k));
        (*encrypt)->filter[strlen(a->value.k)] = 0;
    }
    a = pdf_dict_get(o, "SubFilter");
    if (a)
    {
        pdf_obj_resolve(a);
        (*encrypt)->subfilter = pdf_malloc(strlen(a->value.k)+1);
        memcpy((*encrypt)->subfilter, a->value.k, strlen(a->value.k));
        (*encrypt)->subfilter[strlen(a->value.k)] = 0;
    }
    a = pdf_dict_get(o, "V");
    if (a)
    {
        (*encrypt)->v = pdf_to_int(a);
    }
    e->length = 40;
    a = pdf_dict_get(o, "Length");
    if (a)
    {
        (*encrypt)->length = pdf_to_int(a);
    }
    if (e->v == 4)
    {
        pdf_obj *cf = pdf_dict_get(o, "CF");
        if (cf)
        {
            a = pdf_dict_get(o, "StmF");
            if (a)
            {
                pdf_obj_resolve(a);
                pdf_cf_load(e, cf, a->value.k, &e->stmf);
            }
            a = pdf_dict_get(o, "StrF");
            if (a)
            {
                pdf_obj_resolve(a);
                pdf_cf_load(e, cf, a->value.k, &e->strf);
            }
            a = pdf_dict_get(o, "EFF");
            if (a)
            {
                pdf_obj_resolve(a);
                pdf_cf_load(e, cf, a->value.k, &e->eff);
            }
        }
    }

    // standard encryption dictionary (items)
    a = pdf_dict_get(o, "R");
    if (a)
    {
        (*encrypt)->r = pdf_to_int(a);
    }
    a = pdf_dict_get(o, "O"); // owner password
    if (a)
    {
        // should verify length to 32 bytes
        pdf_obj_resolve(a);
        memcpy((*encrypt)->o, a->value.s.buf, a->value.s.len);
    }
    a = pdf_dict_get(o, "U"); // user password
    if (a)
    {
        // should verify length to 32 bytes
        pdf_obj_resolve(a);
        memcpy((*encrypt)->u, a->value.s.buf, a->value.s.len);
    }
    a = pdf_dict_get(o, "P"); // permission flags
    if (a)
    {
        (*encrypt)->p = pdf_to_int(a);
    }
    a = pdf_dict_get(o, "EncryptMetadata");
    if (a)
    {
        pdf_obj_resolve(a);
        (*encrypt)->encrypt_metadata = a->value.b;
    }

    return pdf_ok;
}

pdf_resources*
pdf_resources_load(pdf_obj *o)
{
    pdf_resources *r;
    if (!o)
        return NULL;

    r = pdf_malloc(sizeof(pdf_resources));
    if (!r)
        return NULL;
    r->extgstate = pdf_dict_get(o, "ExtGState");
    r->colorspace = pdf_dict_get(o, "ColorSpace");
    r->pattern = pdf_dict_get(o, "Pattern");
    r->shading = pdf_dict_get(o, "Shading");
    r->xobject = pdf_dict_get(o, "XObject");
    r->font = pdf_dict_get(o, "Font");
    r->procset = pdf_dict_get(o, "ProcSet");
    r->properties = pdf_dict_get(o, "Properties");
    return r;
}

pdf_stream*
pdf_stream_load(pdf_obj* o, pdfcrypto_priv *crypto, int numobj, int numgen)
{
    pdf_filter *last = NULL, *raw = NULL, *crypt = NULL;
    pdf_stream *s = 0;
    sub_stream *ss;
    pdf_obj *x, *xx;
    int m, mm;

    if (o && o->t == eRef) {
        numobj = o->value.r.num;
        numgen = o->value.r.gen;
    }
    else if (o->t != eDict) {
        return NULL;
    }
    pdf_obj_resolve(o);
    if (!o) {
        return NULL;
    }
    // fill stream info
    if (o->t == eDict)
    {
        int length;
        pdf_obj *len_obj = pdf_dict_get(o, "Length");
        if (!len_obj)
        {
            fprintf(stderr, "%s\n", "Invalid stream.");
            return NULL;
        }
        length = pdf_to_int(len_obj);
        s = pdf_malloc(sizeof(pdf_stream));
        if (!s)
            goto fail;
        memset(s, 0, sizeof(pdf_stream));
        s->length = length;
        if (length == 0)
        { // zero lenght stream, just return
            return s;
        }
        // make raw filter
        /// internal struct. raw stream object
        ss = o->value.d.dict->stream;
        if (!ss)
            goto fail;
        ss->len = s->length;
    }
    else if (o->t == eString)
    {
        s = pdf_malloc(sizeof(pdf_stream));
        if (!s)
            goto fail;
        memset(s, 0, sizeof(pdf_stream));
        s->length = o->value.s.len;
        // make string raw filter
        ss = string_stream_new(o->value.s.buf, 0, o->value.s.len, 0, 0);
    }
    else
        goto fail;
#if 0
    if (ss->reset)(ss) != 0)
    {
        pdf_free(ss);
        // a little haxie, because we SHOULD NOT call global "parser_inst"
        ss = (parser_inst->create_stream)(NULL, o->value.d.stm_offset, s->length, 0, 0);
        o->value.d.dict->stream = ss;
        if (!ss)
        {
            goto fail;
        }
    }
#endif
    raw = pdf_rawfilter_new(ss);
    // chain crypto filter
    if (crypto)
    {
        if (which_algo(crypto) == eAESV2)
        {
            // need initial_vector
            unsigned char iv[16];
            int n;
            n = (raw->read)(raw, iv, 16);
            crypt = pdf_cryptofilter_new(crypto, numobj, numgen, iv);
        }
        else
        {
            crypt = pdf_cryptofilter_new(crypto, numobj, numgen, NULL);
        }
        if (!crypt)
            goto fail;
        crypt->next = raw;
    }
    if (o->t == eString)
    {
        last = (crypt)?crypt:raw;
        goto done;
    }

    // chain the rest
    x = pdf_dict_get(o, "Filter");
    last = (crypt)?crypt:raw;
    if (!x)
    {
        goto done;
    }
    else
    {
        if (x->t == eArray)
        {
            mm = x->value.a.len;
            xx = x->value.a.items;
        }
        else if (obj_is_name(x))
        {
            mm = 1;
            xx = x;
        }
    }

    for (m = 0; m < mm; m++, xx++)
    {
        pdf_filterkind t = Raw;
        pdf_filter *f;
        if (!obj_is_name(xx))
        {
            break;
        }
        t = pdf_filter_find(xx->value.k);
        if (t == Limit)
        {
            fprintf(stderr, "Unkown filter type: %s\n", xx->value.k);
            continue;
        }
        // make the filter
        switch (t)
        {
            case FlateDecode:
            case ASCII85Decode:
            case LZWDecode:
                f = pdf_filter_new(t, last);
                if (!f)
                {
                    if (s)
                        pdf_free(s);
                    if (crypt)
                        PDF_FILTER_CLOSE(crypt, 0); // do not free in_mem stream
                    return NULL;
                }
                // train them
                if (!last)
                {
                    last = f;
                    s->ffilter = f;
                }
                else
                {
                    f->next = last;
                    last = f;
                }
                break;
            default:
                fprintf(stderr, "filter type: %s is not implemented\n", xx->value.k);
                break;
        }
    }
  done:
    s->ffilter = last;
    return s;
  fail:
    if (s)
        pdf_free(s);
    if (raw)
        raw->close(raw, 1);
    return NULL;
}
// public api
pdf_err
pdf_resources_free(pdf_resources *r)
{
    if (!r)
        return pdf_ok;
    pdf_free(r);
    return pdf_ok;
}

pdf_extgstate*
pdf_extgstate_load(pdf_obj *o)
{
    pdf_extgstate *g;

    if (!o || (o->t != eDict && o->t != eRef))
        return NULL;
    g = pdf_malloc(sizeof(pdf_extgstate));
    if (!g)
        return NULL;
    memset(g, 0, sizeof(pdf_extgstate));

    // Todo: check default value
    g->LW = pdf_to_float(pdf_dict_get(o, "LW"));
    g->LC = pdf_to_int(pdf_dict_get(o, "LC"));
    g->LJ = pdf_to_int(pdf_dict_get(o, "LJ"));
    g->ML = pdf_to_float(pdf_dict_get(o, "ML"));
    pdf_to_float_array(pdf_dict_get(o, "D"), g->D);
    g->RI = pdf_to_string(pdf_dict_get(o, "RI"));
    g->OP = pdf_to_int(pdf_dict_get(o, "OP"));
    g->OPM = pdf_to_int(pdf_dict_get(o, "OPM"));
    g->op = pdf_to_int(pdf_dict_get(o, "op"));
    g->BM = pdf_dict_get(o, "BM");
    g->SA = pdf_to_int(pdf_dict_get(o, "SA"));
    // font
    // bg
    g->CA = pdf_to_float(pdf_dict_get(o, "CA"));
    g->ca = pdf_to_float(pdf_dict_get(o, "ca"));
    g->AIS = pdf_to_int(pdf_dict_get(o, "AIS"));
    g->TK = pdf_to_int(pdf_dict_get(o, "TK"));
    return g;
}

pdf_err pdf_extgstate_free(pdf_extgstate*g)
{
    if (!g)
        return pdf_ok;
    pdf_free(g);
    return pdf_ok;
}

pdf_annotation_type
pdf_annots_type(pdf_obj *o)
{
    pdf_annotation_type t = eText;
    char *p = pdf_to_name(o);
    if (!p) return t;

    if (strcmp(p, "Text") == 0) return t;
    else if (strcmp(p, "Link") == 0) return eLink;
    else if (strcmp(p, "FreeText") == 0) return eFreeText;
    else if (strcmp(p, "Line") == 0) return eLine;
    else if (strcmp(p, "Square") == 0) return eSquare;
    else if (strcmp(p, "Polygon") == 0) return ePolygon;
    else if (strcmp(p, "PolyLine") == 0) return ePolyLine;
    else if (strcmp(p, "Highlight") == 0) return eHighlight;
    else if (strcmp(p, "Underline") == 0) return eUnderline;
    else if (strcmp(p, "eSquiggly") == 0) return eSquiggly;
    else if (strcmp(p, "eStrikeOut") == 0) return eStrikeOut;
    else if (strcmp(p, "eStamp") == 0) return eStamp;
    else if (strcmp(p, "eCaret") == 0) return eCaret;
    else if (strcmp(p, "eInk") == 0) return eInk;
    else if (strcmp(p, "ePopup") == 0) return ePopup;
    else if (strcmp(p, "eFileAttachment") == 0) return eFileAttachment;
    else if (strcmp(p, "eSound") == 0) return eSound;
    else if (strcmp(p, "eMovie") == 0) return eMovie;
    else if (strcmp(p, "eWidget") == 0) return eWidget;
    else if (strcmp(p, "eScreen") == 0) return eScreen;
    else if (strcmp(p, "ePrinterMark") == 0) return ePrinterMark;
    else if (strcmp(p, "eTrapNet") == 0) return eTrapNet;
    else if (strcmp(p, "eWatermark") == 0) return eWatermark;
    else if (strcmp(p, "e3D") == 0) return e3D;
    else if (strcmp(p, "eRedact") == 0) return eRedact;
    else return t;
}

pdf_annots*
pdf_annots_load(pdf_obj* o)
{
    pdf_annots *a=NULL, *first=NULL, *last = NULL;
    int i;
    pdf_obj *x, *t;

    o = pdf_array_get(o);
    if (!o)
        return NULL;

    for (i = 0; i < pdf_to_arraylen(o); i++)
    {
        t = pdf_get_array_item(o, i);
        pdf_obj_resolve(t);
        if (!t || t->t != eDict)
            continue;
        a = pdf_malloc(sizeof(pdf_annots));
        if (!a)
            return NULL;
        memset(a, 0, sizeof(pdf_annots));
        // default border
        a->border[0] = 0, a->border[1] = 0, a->border[2] = 1;
        // load annotation node
        a->subtype = pdf_annots_type(pdf_dict_get(t, "Subtype"));
        a->rect = pdf_rect_get(pdf_dict_get(t, "Rect"));
        if ((x = pdf_dict_get(t, "Border"))) {
            a->border[0] = pdf_to_float(pdf_get_array_item(x, 0));
            a->border[1] = pdf_to_float(pdf_get_array_item(x, 1));
            a->border[2] = pdf_to_float(pdf_get_array_item(x, 2));
            if (pdf_to_arraylen(x) > 3) {
                pdf_obj *y = pdf_get_array_item(x, 3);
                a->border[3] =  pdf_to_float(pdf_get_array_item(y, 0));
                a->border[4] =  pdf_to_float(pdf_get_array_item(y, 1));
            }
        }
        // make linked list
        if (last)
            last->next = a;
        if (i == 0)
        {
            first = a;
        }
        last = a;
    }
    return first;
}

pdf_err
pdf_annots_free(pdf_annots *a)
{
    pdf_annots *t;
    while (a)
    {
        t = a->next;
        pdf_free(a);
        a = t;
    }
    return pdf_ok;
}

pdf_err
pdf_stream_free(pdf_stream *s, int flag)
{
    pdf_filter *f;
    if (!s)
        return pdf_ok;
    if (s->length) {
        f = s->ffilter;
        PDF_FILTER_CLOSE(f, flag);
    }
    pdf_free(s);
    return pdf_ok;
}

int
pdf_authenticate_user_password(pdf_encrypt *encrypt, unsigned char id[16], unsigned char *pw)
{
    pdfcrypto_priv *crypto = NULL;
    unsigned char u[32];
    int rev;
    int pwlen;

    if (!pw)
        pwlen = 0;
    else
        pwlen = strlen(pw);
    crypto = pdf_crypto_init(encrypt, id,
                             pw);
    rev = which_revision(crypto);
    // lazy authentication
    pdf_compute_user_password(crypto, id,
                                 u);
    pdf_crypto_destroy(crypto);
    if (rev == 3 || rev == 4)
    {
        return (memcmp(u, encrypt->u, 16));
    }
    else if (rev == 2)
    {
        return (memcmp(u, encrypt->u, 32));
    }
    return 1;
}

int
pdf_doc_authenticate_user_password(pdf_doc *doc, char *pw)
{
    return pdf_authenticate_user_password(doc->trailer->encrypt,
                                          doc->trailer->id[0],
                                          pw);
}

pdf_err
pdf_doc_process_all(pdf_doc *doc, char *devtype, FILE *out, char *pw)
{
    pdf_device *dev = NULL;
    pdfcrypto_priv *crypto = NULL;
    pdf_err e = pdf_ok;

    //unsigned char u[32];
    if (doc->trailer->encrypt)
    {
        crypto = pdf_crypto_init(doc->trailer->encrypt,
                                 doc->trailer->id[0],
                                 pw // password
            );
    }
    if (devtype && out)
    {
        if (strcmp(devtype, "text") == 0)
            dev = pdf_dev_text_new(out);
        else if (strcmp(devtype, "html") == 0)
            dev = pdf_dev_html_new(out);
    }

    e = pdf_doc_process(doc, dev, crypto);

    if (crypto)
        pdf_crypto_destroy(crypto);

    if (dev)
        pdf_dev_destroy(dev);
    return e;
}

int
pdf_doc_need_passwd(pdf_doc *doc)
{
    return (doc->trailer->encrypt?1:0);
}

static void
pdf_info_free(pdf_info *info)
{
    if (!info)
        return;
    if (info->title)
    {
        pdf_obj_delete(info->title);
        free(info->title);
    }
    if (info->author)
    {
        pdf_obj_delete(info->author);
        pdf_free(info->author);
    }
    if (info->subject)
    {
        pdf_obj_delete(info->subject);
        pdf_free(info->subject);
    }
    if (info->keywords)
    {
        pdf_obj_delete(info->keywords);
        pdf_free(info->keywords);
    }
    if (info->creator)
    {
        pdf_obj_delete(info->creator);
        pdf_free(info->creator);
    }
    if (info->producer)
    {
        pdf_obj_delete(info->producer);
        pdf_free(info->producer);
    }
    if (info->trapped)
    {
        pdf_obj_delete(info->trapped);
        pdf_free(info->trapped);
    }
    if (info->creationdate) pdf_free(info->creationdate);
    if (info->moddate)  pdf_free(info->moddate);
}

static void
pdf_encrypt_free(pdf_encrypt *encrypt)
{
    if (!encrypt)
        return;
    if (encrypt->filter) pdf_free(encrypt->filter);
    if (encrypt->subfilter) pdf_free(encrypt->subfilter);
    if (encrypt->stmf) pdf_free(encrypt->stmf);
    if (encrypt->strf) pdf_free(encrypt->strf);
    if (encrypt->eff) pdf_free(encrypt->eff);
    // to free CF
    if (encrypt->cf) pdf_free(encrypt->cf);
    // free this
    pdf_free(encrypt);
}

void
pdf_doc_trailer_free(pdf_trailer * tr)
{
    // really done
    while (tr)
    {
        pdf_trailer *last;
        if (tr->info)
        {
            pdf_info_free(tr->info);
            pdf_free(tr->info);
        }
        if (tr->encrypt)
        {
            pdf_encrypt_free(tr->encrypt);
        }
        last = tr->last;
        pdf_free(tr);
        tr = last;
    }
}

pdf_interp_state *
pdf_interpreter_new(pdf_device *dev, pdfcrypto_priv* encrypt)
{
    pdf_interp_state *i = pdf_malloc(sizeof(pdf_interp_state));
    if (i)
    {
        memset(i, 0, sizeof(pdf_interp_state));
        i->dev = dev;
        i->crypto = encrypt;
    }
    return i;
}

void
pdf_interpreter_free(pdf_interp_state *i)
{
    if (i)
    {
        pdf_font_free(i->font);
        pdf_free(i);
    }
}

void
pdf_interpreter_font_insert(pdf_interp_state *i, pdf_font *f)
{
    if (i && f)
    {
        // insert into head
        f->next = i->font;
        i->font = f;
    }
}

static void
pdf_gstate_init(pdf_page *p)
{
    pdf_prs *s = p->s;
    int rotate = p->rotate;
    pdf_extgstate *gs;
    gs = &s->gs;

    gs->th = 1;
    mat_init(&gs->ctm, 1, 0, 0, 1, 0, 0);
    if (rotate)
    {
        switch (rotate)
        {
            case 90:
                mat_init(&gs->ctm, 0, -1, 1, 0, 0, p->mediabox.y1);
                break;
            case 180:
                mat_init(&gs->ctm, -1, 0, 0, 1, p->mediabox.x1, 0);
                break;
            case 270:
                mat_init(&gs->ctm, 0, 1, -1, 0, p->mediabox.x1, 0);
                break;
            case 360:
                mat_init(&gs->ctm, 1, 0, 0, -1, 0, p->mediabox.y1);
                break;
            default:
                break;
        }
    }
    mat_init(&gs->txt_ctm, 1, 0, 0, 1, 0, 0);
    mat_init(&gs->txt_lm, 1, 0, 0, 1, 0, 0);
    // path stack
    gs->path_base = p->i->path_stk;
    gs->path_top = gs->path_base;
    gs->D_n = 0;
    gs->D_OFFSET = 0;
}

void
pdf_device_color_set(pdf_device *d, float *c, pdf_cspacetype cs, int n, int pen)
{
    if (d)
        (d->color_set)(d, c, cs, n, pen);
}

void
pdf_update_brush(pdf_page *p)
{
    pdf_prs *s0, *s1;
    s0 = p->s - 1;
    s1 = p->s;
    if (s0->brush.t != s1->brush.t)
    {
        return pdf_device_color_set(p->i->dev, s0->brush.c, s0->brush.t, s0->brush.n, 0);
    }
    else if (memcmp(&s0->brush.c, &s1->brush.c, s0->brush.n*sizeof(float)) != 0)
    {
        return pdf_device_color_set(p->i->dev, s0->brush.c, s0->brush.t, s0->brush.n, 0);
    }
}

int
pdf_doc_page_count(pdf_doc *doc)
{return doc->count;}


void
pdf_id_create(char *filename, int filesize, pdf_obj *info, char *out)
{
    int i;
    char msg[2048];
    char buf[256];

    msg[0] = 0;
    buf[0] = 0;

    sprintf(buf, "%d", time(0));
    strcat(msg, buf);
    strcat(msg, filename);
    sprintf(buf, "%d", filesize);
    strcat(msg, buf);

    if (info && info->t == eDict)
    {
        void info_concat_string(char *k, void *val, void *b)
        {
            dict_entry *e = (dict_entry*) val;
            pdf_obj *o = e->v;
            if (o->t == eString)
            {
                strncat(b, o->value.s.buf, o->value.s.len);
            }
        }

        dict_each(info->value.d.dict, info_concat_string, msg);
    }
    pdf_digest_md5(msg, strlen(msg), out);

}

pdf_obj *
pdf_datestring_create()
{
    time_t     t;
    struct tm *tmp;
    char       buf[128];

    t = time(0);
    tmp = localtime(&t);
    if (tmp)
    {
        strftime(buf, 128, "D:%G%m%d%H%M%S%z00", tmp);
        return pdf_string_new(buf, strlen(buf));
    }
    return 0;
}

pdf_obj *
pdf_info_create(pdf_info *i)
{
    pdf_obj *o = pdf_dict_new(0);
    dict *d;
    char buf[128];
    pdf_obj *date_obj;

    if (!o)
        return 0;

    d = o->value.d.dict;

    if (i && i->title)
    {
        pdf_dict_insert_obj(d, "Title", i->title);
    }
    if (i && i->author)
    {
        pdf_dict_insert_obj(d, "Author", i->author);
    }
    if (i && i->subject)
    {
        pdf_dict_insert_obj(d, "Subject", i->subject);
    }
    if (i && i->keywords)
    {
        pdf_dict_insert_obj(d, "Keywords", i->keywords);
    }

    if (!i || !i->producer)
    {
        pdf_dict_insert_string(d, "Producer", "PegDF", strlen("PegDF"));
    }
    else
    {
        pdf_dict_insert_obj(d, "Producer", i->producer);
    }
    if (!i || !i->creator)
    {
        pdf_dict_insert_string(d, "Creator", "PegDF", strlen("PegDF"));
    }
    else
    {
        pdf_dict_insert_obj(d, "Creator", i->creator);
    }

    date_obj = pdf_datestring_create();

    if (!i || !i->creationdate)
    {
        if (date_obj)
            pdf_dict_insert_obj(d, "CreationDate", date_obj);
    }
    else
    {
        pdf_dict_insert_string(d, "CreationDate", i->creationdate, strlen(i->creationdate));
    }

    if (date_obj)
    {
        pdf_dict_insert_obj(d, "ModDate", date_obj);
    }

    if (date_obj)
    {
        pdf_obj_delete(date_obj);
        pdf_free(date_obj);
    }

    if (i && i->trapped)
    {
        pdf_dict_insert_obj(d, "Trapped", i->trapped);
    }

    return o;

}


