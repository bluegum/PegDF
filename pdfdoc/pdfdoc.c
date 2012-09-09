#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "pdftypes.h"
#include "pdfindex.h"
#include "pdfmem.h"
#include "pdffilter.h"
#include "pdfdoc.h"
#include "pdfcrypto.h"
#include "pdfread.h"

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
      g->cs = dict_get(o->value.d.dict, "CS");
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

pdf_err pdf_page_load(pdf_obj *o, pdf_page **page)
{
      pdf_page *p;
      dict *d = o->value.d.dict;
      pdf_obj *v;

      *page = pdf_malloc(sizeof(pdf_page));
      p = *page;
      memset(p, 0, sizeof(pdf_page));
      p->s = p->sstk;
      // parse tree dict
      p->parent = dict_get(d, "Parent");
      p->mediabox = pdf_rect_resolve(dict_get(d, "MediaBox"));
      p->resources = pdf_resources_load(dict_get(d, "Resources"));
      // optionals
      p->contents = dict_get(d, "Contents");
      v = dict_get(d, "Rotate");
      if (v)
            p->rotate = v->value.i;
      p->group = pdf_group_load(dict_get(d, "Group"));
      p->annots = pdf_annots_load(dict_get(d, "Annots"));
      p->metadata = dict_get(d, "Metadata");
      p->pieceinfo = dict_get(d, "PieceInfo");
      p->lastmodified = dict_get(d, "LastModified");
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
                        pdf_page_load(o, &d->pages[d->pageidx]);
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
            pdf_page_load(kids, &d->pages[d->pageidx]);
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
      pdf_stream *s;
      if (!p)
            return pdf_ok;
      if (!p->contents)
            return pdf_ok;
      if (p->contents->t != eDict && p->contents->t != eRef && p->contents->t != eArray)
            return pdf_ok;
      //p->content_streams = pdf_streams_load(p->contents);
      {
            pdf_obj *oo;
            int i, n;

            pdf_obj_resolve(p->contents);
            if (!p->contents)
                  return pdf_ok;
            if (p->contents->t == eArray)
            {
                  n = p->contents->value.a.len;
                  oo = &p->contents->value.a.items[0];
            }
            else if (p->contents->t == eDict)
            {
                  n = 1;
                  oo = p->contents;
            }
            else
                  return pdf_ok;

            for (i = 0; i < n && oo; i++, oo++)
            {
                  s = pdf_stream_load(oo, encrypt, oo->value.r.num, oo->value.r.gen);
                  pdf_cs_parse(p, s);
                  pdf_stream_free(s);
            }
      }

      return pdf_ok;
}

pdf_err pdf_page_tree_walk(pdf_doc *d, pdfcrypto_priv* encrypt)
{
      int i;

      for (i = 0; i < d->count; i++)
      {
#ifdef DEBUG
            printf("processing page#%d\n", i);
#endif
            pdf_exec_page_content(d->pages[i], encrypt);
#ifdef DEBUG
            printf("%s", "\n");
#endif
      }
      return pdf_ok;
}

pdf_doc*
pdf_doc_load(pdf_trailer *trailer)
{
      pdf_obj *rdoc;
      pdf_obj *a, *d, *c, *kids;
      pdf_doc *doc;

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
      doc = pdf_malloc(sizeof(pdf_doc));
      if (!doc)
            return NULL;
      memset(doc, 0, sizeof(pdf_doc));
      doc->count = c->value.i;
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

pdf_err pdf_doc_process(pdf_doc *d, pdfcrypto_priv* encrypt)
{
      return pdf_page_tree_walk(d, encrypt);
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
      pdf_trailer_free(d->trailer);
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
      a = dict_get(o->value.d.dict, "Title");
      if (a) {i->title = pdf_malloc(a->value.s.len+1); memcpy(i->title, a->value.s.buf, a->value.s.len); i->title[a->value.s.len] = 0;}
      a = dict_get(o->value.d.dict, "Author");
      if (a) {i->author = pdf_malloc(a->value.s.len+1); memcpy(i->author, a->value.s.buf, a->value.s.len); i->author[a->value.s.len] = 0;}
      a = dict_get(o->value.d.dict, "Subject");
      if (a) {i->subject = pdf_malloc(a->value.s.len+1); memcpy(i->subject, a->value.s.buf, a->value.s.len); i->subject[a->value.s.len] = 0;}
      a = dict_get(o->value.d.dict, "Keywords");
      if (a) {i->keywords = pdf_malloc(a->value.s.len+1); memcpy(i->keywords, a->value.s.buf, a->value.s.len); i->keywords[a->value.s.len] = 0;}
      a = dict_get(o->value.d.dict, "Creator");
      if (a) {i->creator = pdf_malloc(a->value.s.len+1); memcpy(i->creator, a->value.s.buf, a->value.s.len); i->creator[a->value.s.len] = 0;}
      a = dict_get(o->value.d.dict, "Producer");
      if (a) {i->producer = pdf_malloc(a->value.s.len+1); memcpy(i->producer, a->value.s.buf, a->value.s.len); i->producer[a->value.s.len] = 0;}
      a = dict_get(o->value.d.dict, "CreationDate");
      if (a) {i->creationdate = pdf_malloc(a->value.s.len+1); memcpy(i->creationdate, a->value.s.buf, a->value.s.len); i->creationdate[a->value.s.len] = 0;}
      a = dict_get(o->value.d.dict, "ModDate");
      if (a) {i->moddate = pdf_malloc(a->value.s.len+1); memcpy(i->moddate, a->value.s.buf, a->value.s.len); i->moddate[a->value.s.len] = 0;}
      a = dict_get(o->value.d.dict, "Trapped");
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


pdf_err
pdf_cf_load(pdf_obj *o, pdf_cryptfilter **cryptfilter)
{
      pdf_obj *a;
      pdf_cryptfilter *c;
      *cryptfilter = pdf_malloc(sizeof(pdf_cryptfilter));
      if (!*cryptfilter)
            return pdf_mem_err;
      if (!o)
            return pdf_ok;
      memset(*cryptfilter, 0, sizeof(pdf_encrypt));
      c = *cryptfilter;
      a = dict_get(o->value.d.dict, "Type");
      a = dict_get(o->value.d.dict, "CFM");
      a = dict_get(o->value.d.dict, "AuthEvent");
      a = dict_get(o->value.d.dict, "Length");
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
      pdf_filter *last = NULL, *raw, *crypt = NULL;
      pdf_stream *s;
      sub_stream *ss;
      pdf_obj *x, *xx, *y;
      int m, mm;

      // fill stream info
      pdf_obj_resolve(o);
      y = o;
      if (!y || y->t != eDict)
      {
            return NULL;
      }
      x = dict_get(y->value.d.dict, "Length");
      if (!x || (x->t != eInt && x->t != eRef))
      {
            fprintf(stderr, "%s\n", "Invalid stream.");
            return NULL;
      }
      pdf_obj_resolve(x);
      s = pdf_malloc(sizeof(pdf_stream));
      if (!s)
            return NULL;
      memset(s, 0, sizeof(pdf_stream));
      s->length = x->value.i;
      // make raw filter
      /// internal struct. raw stream object
      ss = dict_get(y->value.d.dict, "S_O");
      if (!ss)
            return NULL;
      ss->len = s->length;
      raw = pdf_rawfilter_new(ss);
      // chain crypto filter
      if (crypto)
      {
            crypt = pdf_cryptofilter_new(crypto, numobj, numgen);
            if (!crypt)
                  return NULL;
            crypt->next = raw;
      }
      // chain rest
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
#if 0
pdf_stream*
pdf_streams_load(pdf_obj* o)
{
      pdf_stream *s, *last;
      pdf_obj *oo;
      int i, n;

      if (!o || (o->t != eDict && o->t != eRef && o->t != eArray))
            return NULL;

      pdf_obj_resolve(o);
      if (!o)
            return NULL;
      if (o->t == eArray)
      {
            n = o->value.a.len;
            oo = &o->value.a.items[0];
      }
      else if (o->t == eDict)
      {
            n = 1;
            oo = o;
      }
      else
            return NULL;
      last = NULL;
      for (i = 0; i < n && oo; i++, oo++)
      {
            pdf_stream *t = pdf_stream_load(oo);
            if (last)
            {
                  last->next = t;
            }
            else
            {
                  s = t;
            }
            last = t;
      }
      return s;
}

pdf_err
pdf_streams_free(pdf_stream *s)
{
      pdf_stream *t = s;
      while (s)
      {
            t = s->next;
            pdf_stream_free(s);
            s = t;
      }
      return pdf_ok;
}
#endif
pdf_err
pdf_stream_free(pdf_stream *s)
{
      pdf_filter *f;
      if (!s)
            return pdf_ok;
      f = s->ffilter;
      while (f)
      {
            pdf_filter *t = f->next;
            (*f->close)(f);
            f = t;
      }
      pdf_free(s);
      return pdf_ok;
}

int
pdf_authenticate_user_password(pdf_encrypt *encrypt, unsigned char id[16], unsigned char *pw, int pwlen)
{
      pdfcrypto_priv *crypto = NULL;
      unsigned char u[32];
      int rev;
      crypto = pdf_crypto_init(encrypt, id,
			       pw, // password
			       pwlen // password len
	    );
      rev = crypto->rev;
      // lazy authentication
      pdf_crypto_calc_userpassword(crypto, id,
				   pw, // password
				   pwlen,  // pwlen
				   u);
      pdf_crypto_destroy(crypto);
      if (rev == 3)
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
pdf_doc_authenticate_user_password(pdf_doc *doc, unsigned char *pw, int pwlen)
{
      return pdf_authenticate_user_password(doc->trailer->encrypt,
					    doc->trailer->id[0],
					    pw, pwlen);
}

pdf_err
pdf_doc_process_all(pdf_doc *doc, unsigned char *pw, int pwlen)
{
      pdfcrypto_priv *crypto = NULL;
      unsigned char u[32];
      if (doc->trailer->encrypt)
      {
	    crypto = pdf_crypto_init(doc->trailer->encrypt,
				     doc->trailer->id[0],
				     pw, // password
				     pwlen // password len
		  );
      }
      pdf_doc_process(doc, crypto);
      if (crypto)
	    pdf_crypto_destroy(crypto);
      return pdf_ok;
}

int
pdf_doc_need_passwd(pdf_doc *doc)
{
      return (doc->trailer->encrypt?1:0);
}
