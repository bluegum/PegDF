#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
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

static void pdf_gstate_init(pdf_page* p);

static inline pdf_group*
pdf_group_load(pdf_obj *o)
{
      pdf_group *g;
      if (!o || o->t != eDict)
            return NULL;
      g = pdf_malloc(sizeof(pdf_group));
      if (!g)
            return NULL;
      memset(g, 0, sizeof(pdf_group));
      g->cs = (pdf_obj*)dict_get(o->value.d.dict, "CS");
      g->i = pdf_to_int(dict_get(o->value.d.dict, "I"));
      g->k = pdf_to_int(dict_get(o->value.d.dict, "K"));
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
      dict *d = o->value.d.dict;
      pdf_obj *v;

      *page = pdf_malloc(sizeof(pdf_page));
      p = *page;
      memset(p, 0, sizeof(pdf_page));
      // parse tree dict
      p->parent = dict_get(d, "Parent");
      mediabox = dict_get(d, "MediaBox");
      if (mediabox)
            p->mediabox = pdf_rect_resolve(mediabox);
      else
      {
            gs_rect *r = doc->get_mediabox(doc);
            if (r)
                  p->mediabox = *r;
      }
      p->resources = pdf_resources_load(dict_get(d, "Resources"));
      // optionals
      p->contents = (pdf_obj*)dict_get(d, "Contents");
      v = (pdf_obj*)dict_get(d, "Rotate");
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
      p->group = pdf_group_load(dict_get(d, "Group"));
      p->annots = pdf_annots_load(dict_get(d, "Annots"));
      p->metadata = (pdf_obj*)dict_get(d, "Metadata");
      p->pieceinfo = (pdf_obj*)dict_get(d, "PieceInfo");
      p->lastmodified = (pdf_obj*)dict_get(d, "LastModified");
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
            pdf_obj_resolve(o);
            a = dict_get(o->value.d.dict, "Type");
            if (!a)
                  return pdf_ok;
            if (a->t == eKey && a->value.k)
            {
                  if (strcmp(a->value.k, "Pages") == 0)
                  {
                        kids = dict_get(o->value.d.dict, "Kids");
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
      pdf_obj_resolve(kids);
      if (kids->t == eDict)
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
      pdf_cs_parse(p, encrypt, 0);

      return pdf_ok;
}

pdf_err pdf_page_tree_walk(pdf_doc *d, pdf_device *dev, pdfcrypto_priv* encrypt)
{
      int i, c;
      pdf_interp_state *interp;

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
            pdf_exec_page_content(d->pages[i], encrypt);
	    if (dev)
		  (dev->page_end)(dev);
#ifdef DEBUG
            printf("%s", "\n");
#endif
      }
      pdf_interpreter_free(interp);
      return pdf_ok;
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
      pdf_obj *rdoc;
      pdf_obj *a, *d, *c, *kids;
      pdf_doc *doc;
      pdf_doc_private *pdoc;
      if (!trailer)
            return NULL;
      rdoc = trailer->root_obj;
      pdf_obj_resolve(rdoc);

      assert (rdoc);
      assert (rdoc->t == eDict);

      d = rdoc;

      if (!d || d->t != eDict)
            return NULL;
      a = dict_get(d->value.d.dict, "Pages");
      if (!a || a->t != eRef)
            return NULL;
      pdf_obj_resolve(a);
      if (!a || a->t != eDict)
            return NULL;
      c = dict_get(a->value.d.dict, "Count");
      if (!c || c->t != eInt)
            return NULL;
      pdoc = doc = pdf_malloc(sizeof(pdf_doc_private));
      if (!doc)
            return NULL;
      memset(doc, 0, sizeof(pdf_doc));
      doc->count = c->value.i;
      c = dict_get(a->value.d.dict, "MediaBox");
      if (c)
      {
            pdf_obj_resolve(c);
            pdoc->mediabox = pdf_rect_resolve(c);
            doc->get_mediabox = pdf_doc_get_mediabox;
      }
      else
      {
            doc->get_mediabox = null_val;
      }
      kids = dict_get(a->value.d.dict, "Kids");
      if (!kids || (kids->t != eArray && kids->t != eRef))
      {
            pdf_free(doc);
            return NULL;
      }
      doc->pages = pdf_malloc(sizeof(pdf_page*) * doc->count);
      memset(doc->pages, 0, (sizeof(pdf_page*) * doc->count));
      doc->pageidx = 0;
      pdf_page_tree_load(doc, kids);
      /// shuffle in some auxillary info
      ///
      doc->trailer = trailer;
      //doc->info = trailer->info; // pass info as member of doc
      //doc->encrypt = trailer->encrypt; // pass encrypt
      //trailer->encrypt = NULL; // TODO: move it out
      return doc;
}

pdf_err pdf_doc_process(pdf_doc *d, pdf_device *dev, pdfcrypto_priv* encrypt)
{
      pdf_err e;
      if (dev)
	    dev->doc_begin(dev);
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
      pdf_free(d);
}

pdf_err
pdf_info_load(pdf_obj *o, pdf_info **info)
{
      pdf_obj *a;
      pdf_info *i;

      *info = pdf_malloc(sizeof(pdf_info));
      if (!*info)
            return pdf_ok;
      if (!o)
            return pdf_ok;
      memset(*info, 0, sizeof(pdf_info));

      pdf_obj_resolve(o);
      if (!o || o->t != eDict)
      {
            pdf_free(*info);
            *info = NULL;
            return pdf_ok;
      }
      i = *info;
      a = (pdf_obj*)dict_get(o->value.d.dict, "Title");
      if (a) {i->title = pdf_malloc(a->value.s.len+1); memcpy(i->title, a->value.s.buf, a->value.s.len); i->title[a->value.s.len] = 0;}
      a = (pdf_obj*)dict_get(o->value.d.dict, "Author");
      if (a) {i->author = pdf_malloc(a->value.s.len+1); memcpy(i->author, a->value.s.buf, a->value.s.len); i->author[a->value.s.len] = 0;}
      a = (pdf_obj*)dict_get(o->value.d.dict, "Subject");
      if (a) {i->subject = pdf_malloc(a->value.s.len+1); memcpy(i->subject, a->value.s.buf, a->value.s.len); i->subject[a->value.s.len] = 0;}
      a = (pdf_obj*)dict_get(o->value.d.dict, "Keywords");
      if (a) {i->keywords = pdf_malloc(a->value.s.len+1); memcpy(i->keywords, a->value.s.buf, a->value.s.len); i->keywords[a->value.s.len] = 0;}
      a = (pdf_obj*)dict_get(o->value.d.dict, "Creator");
      if (a) {i->creator = pdf_malloc(a->value.s.len+1); memcpy(i->creator, a->value.s.buf, a->value.s.len); i->creator[a->value.s.len] = 0;}
      a = (pdf_obj*)dict_get(o->value.d.dict, "Producer");
      if (a) {i->producer = pdf_malloc(a->value.s.len+1); memcpy(i->producer, a->value.s.buf, a->value.s.len); i->producer[a->value.s.len] = 0;}
      a = (pdf_obj*)dict_get(o->value.d.dict, "CreationDate");
      if (a) {i->creationdate = pdf_malloc(a->value.s.len+1); memcpy(i->creationdate, a->value.s.buf, a->value.s.len); i->creationdate[a->value.s.len] = 0;}
      a = (pdf_obj*)dict_get(o->value.d.dict, "ModDate");
      if (a) {i->moddate = pdf_malloc(a->value.s.len+1); memcpy(i->moddate, a->value.s.buf, a->value.s.len); i->moddate[a->value.s.len] = 0;}
      a = (pdf_obj*)dict_get(o->value.d.dict, "Trapped");
      i->trapped = UNknown;
      if (a)
      {
            if (strcmp(a->value.k, "True") == 0)
                  i->trapped = TRue;
            else if (strcmp(a->value.k, "False") == 0)
                  i->trapped = FAlse;
      }
      return pdf_ok;
}

pdf_err pdf_info_print(pdf_info *info)
{
      if (info->title) printf("Title:%s\n", info->title);
      if (info->author) printf("Auther:%s\n", info->author);
      if (info->subject) printf("Subject:%s\n", info->subject);
      if (info->keywords) printf("Keywords:%s\n", info->keywords);
      if (info->creator) printf("Creator:%s\n", info->creator);
      if (info->producer) printf("Producer:%s\n", info->producer);
      if (info->creationdate) printf("CreationDate:%s\n", info->creationdate);
      if (info->moddate) printf("ModDate:%s\n", info->moddate);
      printf("Trapped:%s\n", info->trapped==TRue?"Yes":(info->trapped==FAlse)?"No":"Unknown");
      return pdf_ok;
}

// Load crypt_filter
pdf_err
pdf_cf_load(pdf_obj *o, pdf_cryptfilter **cf)
{
      pdf_obj *a;

      if (!o)
	    return pdf_ok;
      if (o->t != eKey && o->t != eDict)
	    return pdf_ok;
      if (o->t == eKey &&
	  strcmp(o->value.k, "Identity") == 0)
	    return pdf_ok;
      if (o->t == eKey)
	    return pdf_ok;
      a = dict_get(o->value.d.dict, "StdCF"); // Dont support private CF
      if (!a)
	    return pdf_ok;
      o = a;
      pdf_obj_resolve(o);
      if (o->t != eDict)
	    return pdf_ok;
      *cf = pdf_malloc(sizeof(pdf_cryptfilter));
      if (!*cf)
            return pdf_mem_err;
      if (!o)
            return pdf_ok;
      memset(*cf, 0, sizeof(pdf_cryptfilter));
      a = dict_get(o->value.d.dict, "CFM");
      if (a && a->t == eKey)
      {
            if (strcmp(a->value.k, "V2") == 0)
            {
                  (*cf)->cfm = eCryptRC4;
            }
            else if (strcmp(a->value.k, "None") == 0)
            {
                  (*cf)->cfm = eCryptNone;
            }
            else if (strcmp(a->value.k, "AESV2") == 0)
            {
                  (*cf)->cfm = eCryptAES;
            }
            else
            {
                  (*cf)->cfm = eCryptNone; // better return error ?
            }
      }
      a = dict_get(o->value.d.dict, "AuthEvent");
      if (a && a->t == eKey)
      {
            if (strcmp(a->value.k, "EFOpen") == 0)
            {
                  (*cf)->authevent = eEFOpen;
            }
            else if (strcmp(a->value.k, "DocOpen") == 0)
	    {
                  (*cf)->authevent = eDocOpen;
	    }
      }
      a = dict_get(o->value.d.dict, "Length");
      if (a && a->t == eInt)
      {
	    (*cf)->length = a->value.i;
      }
      return pdf_ok;
}

pdf_resources*
pdf_resources_load(pdf_obj *o)
{
      pdf_resources *r;
      dict *d;
      if (!o || (o->t != eDict && o->t != eRef))
            return NULL;

      pdf_obj_resolve(o);
      r = pdf_malloc(sizeof(pdf_resources));
      if (!r)
            return NULL;
      d = o->value.d.dict;
      r->extgstate = dict_get(d, "ExtGState");
      r->colorspace = dict_get(d, "ColorSpace");
      r->pattern = dict_get(d, "Pattern");
      r->shading = dict_get(d, "Shading");
      r->xobject = dict_get(d, "XObject");
      r->font = dict_get(d, "Font");
      r->procset = dict_get(d, "ProcSet");
      r->properties = dict_get(d, "Properties");
      return r;
}

pdf_stream*
pdf_stream_load(pdf_obj* o, pdfcrypto_priv *crypto, int numobj, int numgen)
{
      pdf_filter *last = NULL, *raw = NULL, *crypt = NULL;
      pdf_stream *s;
      sub_stream *ss;
      pdf_obj *x, *xx, *y;
      int m, mm;

      if (o && o->t == eRef)
      {
	    numobj = o->value.r.num;
	    numgen = o->value.r.gen;
      }
      // fill stream info
      pdf_obj_resolve(o);
      y = o;
      if (!y)
      {
            return NULL;
      }
      if (o->t == eDict)
      {
	    x = dict_get(y->value.d.dict, "Length");
	    if (!x || (x->t != eInt && x->t != eRef))
	    {
		  fprintf(stderr, "%s\n", "Invalid stream.");
		  return NULL;
	    }
	    pdf_obj_resolve(x);
	    s = pdf_malloc(sizeof(pdf_stream));
	    if (!s)
		  goto fail;
	    memset(s, 0, sizeof(pdf_stream));
	    s->length = x->value.i;
	    // make raw filter
	    /// internal struct. raw stream object
	    ss = y->value.d.dict->stream;
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
      if (0)//(ss->reset)(ss) != 0)
      {
            pdf_free(ss);
            // a little haxie, because we SHOULD NOT call global "parser_inst"
            ss = (parser_inst->create_stream)(NULL, y->value.d.stm_offset, s->length, 0, 0);
            y->value.d.dict->stream = ss;
            if (!ss)
            {
                  goto fail;
            }
      }
      raw = pdf_rawfilter_new(ss);
      // chain crypto filter
      if (crypto)
      {
	    if (crypto->algo == e40plusbitsAES || crypto->algo == e40bitsAES)
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
      if (y->t == eString)
      {
	    last = (crypt)?crypt:raw;
	    goto done;
      }

      // chain the rest
      x = dict_get(y->value.d.dict, "Filter");
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
            else if (x->t == eKey)
            {
                  mm = 1;
                  xx = x;
            }
      }

      for (m = 0; m < mm; m++, xx++)
      {
            pdf_filterkind t = Raw;
            pdf_filter *f;
            if (xx->t != eKey)
            {
                  break;
            }
            if (strcmp(xx->value.k, "FlateDecode") == 0)
            {
                  t = FlateDecode;
            }
            else if (strcmp(xx->value.k, "ASCIIHexDecode") == 0)
            {
                  t = ASCIIHexDecode;
            }
            else if (strcmp(xx->value.k, "ASCII85Decode") == 0)
            {
                  t = ASCII85Decode;
            }
            else if (strcmp(xx->value.k, "LZWDecode") == 0)
            {
                  t = LZWDecode;
            }
            else if (strcmp(xx->value.k, "RunLengthDecode") == 0)
            {
                  t = RunLengthDecode;
            }
            else if (strcmp(xx->value.k, "CCITTFaxDecode") == 0)
            {
                  t = CCITTFaxDecode;
            }
            else if (strcmp(xx->value.k, "JBIG2Decode") == 0)
            {
                  t = JBIG2Decode;
            }
            else if (strcmp(xx->value.k, "DCTDecode") == 0)
            {
                  t = DCTDecode;
            }
            else if (strcmp(xx->value.k, "JPXDecode") == 0)
            {
                  t = JPXDecode;
            }
            else if (strcmp(xx->value.k, "Crypt") == 0)
            {
                  t = Crypt;
            }
            else
            {
                  t = Raw;
            }
            // make the filter
            f = pdf_filter_new(t);
            if (!f)
            {
                  if (s)
                        pdf_free(s);
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
      dict *d;

      if (!o || (o->t != eDict && o->t != eRef))
            return NULL;
      pdf_obj_resolve(o);
      g = pdf_malloc(sizeof(pdf_extgstate));
      if (!g)
            return NULL;
      memset(g, 0, sizeof(pdf_extgstate));
      d = o->value.d.dict;
      // Todo: check default value
      g->LW = pdf_to_float(dict_get(d, "LW"));
      g->LC = pdf_to_int(dict_get(d, "LC"));
      g->LJ = pdf_to_int(dict_get(d, "LJ"));
      g->ML = pdf_to_float(dict_get(d, "ML"));
      pdf_to_int_array(dict_get(d, "D"), g->D);
      g->RI = pdf_to_string(dict_get(d, "RI"));
      g->OP = pdf_to_int(dict_get(d, "OP"));
      g->OPM = pdf_to_int(dict_get(d, "OPM"));
      g->op = pdf_to_int(dict_get(d, "op"));
      g->BM = dict_get(d, "BM");
      g->SA = pdf_to_int(dict_get(d, "SA"));
      // font
      // bg
      g->CA = pdf_to_float(dict_get(d, "CA"));
      g->ca = pdf_to_float(dict_get(d, "ca"));
      g->AIS = pdf_to_int(dict_get(d, "AIS"));
      g->TK = pdf_to_int(dict_get(d, "TK"));
      return g;
}

pdf_err pdf_extgstate_free(pdf_extgstate*g)
{
      if (!g)
            return pdf_ok;
      pdf_free(g);
      return pdf_ok;
}

static inline char*
pdf_key_resolve(pdf_obj*o)
{
      if (!o || o->t != eKey)
            return NULL;
      return o->value.k;
}

pdf_annots*
pdf_annots_load(pdf_obj* o)
{
      pdf_annots *a=NULL, *first=NULL, *last = NULL;
      dict *d;
      int i;

      if (!o || (o->t != eArray && o->t != eRef))
            return NULL;

      pdf_obj_resolve(o);

      for (i = 0; i < o->value.a.len; i++)
      {
            pdf_obj *t = &o->value.a.items[i];
            pdf_obj_resolve(t);
            a = pdf_malloc(sizeof(pdf_annots));
            if (!a)
                  return NULL;
            memset(a, 0, sizeof(pdf_annots));
            d = t->value.d.dict;
            // load annotation node
            a->subtype = pdf_key_resolve(dict_get(d, "SubType"));
            a->rect = pdf_rect_resolve(dict_get(d, "Rect"));
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
      f = s->ffilter;
      PDF_FILTER_CLOSE(f, flag);
      pdf_free(s);
      return pdf_ok;
}

//extern int pdf_stream_getchar(pdf_stream *s);
int
pdf_stream_getchar(pdf_stream *s)
{
      unsigned char c;
      if ((s->ffilter->read)(s->ffilter, &c, 1) == 0)
            return EOF;
      else
            return c;
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
      rev = crypto->rev;
      // lazy authentication
      pdf_crypto_calc_userpassword(crypto, id,
                                   pw, pwlen,
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
pdf_doc_process_all(pdf_doc *doc, char *devtype, FILE *out, unsigned char *pw)
{
      pdf_device *dev = NULL;
      pdfcrypto_priv *crypto = NULL;

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

      pdf_doc_process(doc, dev, crypto);
      if (crypto)
            pdf_crypto_destroy(crypto);
      if (dev)
	    pdf_dev_destroy(dev);
      return pdf_ok;
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
      if (info->title)  pdf_free(info->title);
      if (info->author)  pdf_free(info->author);
      if (info->subject)  pdf_free(info->subject);
      if (info->keywords)  pdf_free(info->keywords);
      if (info->creator)  pdf_free(info->creator);
      if (info->producer)  pdf_free(info->producer);
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
      if (i)
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
}

void
pdf_device_color_set(pdf_device *d, float *c, pdf_cspacetype cs, int n)
{
      if (d)
	    (d->color_set)(d, c, cs, n);
}

void
pdf_update_brush(pdf_page *p)
{
      pdf_prs *s0, *s1;
      s0 = p->s - 1;
      s1 = p->s;
      if (s0->brush.t != s1->brush.t)
      {
	    return pdf_device_color_set(p->i->dev, s0->brush.c, s0->brush.t, s0->brush.n);
      }
      else if (memcmp(&s0->brush.c, &s1->brush.c, s0->brush.n*sizeof(float)) != 0)
      {
	    return pdf_device_color_set(p->i->dev, s0->brush.c, s0->brush.t, s0->brush.n);
      }
}
