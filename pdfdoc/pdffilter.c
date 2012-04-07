#include <assert.h>
#include "zlib.h"
#include "pdftypes.h"
#include "readpdf.h"
#include "pdfmem.h"
#include "pdffilter.h"

static int pdf_flated_read(pdf_filter *f, unsigned char *obuf, int request);
static pdf_err pdf_flated_close(pdf_filter *f);

static void *zalloc(void *opaque, unsigned int items, unsigned int size)
{
        return pdf_malloc(items*size);
}

static void zfree(void *opaque, void *ptr)
{
        pdf_free(ptr);
}

pdf_err
pdf_flated_new(pdf_filter **f)
{
  z_stream *z;
  int ret;
  if (!f)
    return pdf_ok;
  *f = pdf_malloc(sizeof(pdf_filter));
  if (!(*f))
    return pdf_ok;
  z = pdf_malloc(sizeof(z_stream));
  if (!z)
    return pdf_ok;
  memset(z, 0, sizeof(z_stream));
  z->zalloc = zalloc;
  z->zfree = zfree;
  z->opaque = 0;//ctx;
  z->next_in = NULL;
  z->avail_in = 0;

  ret = inflateInit(z);
  (*f)->state = (void*)z;
  (*f)->read = pdf_flated_read;
  (*f)->close = pdf_flated_close;
  (*f)->ptr = (*f)->buf;
  return pdf_ok;
}

static pdf_err
pdf_flated_close(pdf_filter *f)
{
  int ret;
  if (!f)
    return pdf_ok;
  if (f->state)
    ret = inflateEnd(f->state);
  pdf_free(f->state);
  pdf_free(f);
  return pdf_ok;
}

// return the length read
// return 0 signifies EOF
static int
pdf_flated_read(pdf_filter *f, unsigned char *obuf, int request)
{
  int ret, in;
  pdf_filter *up = f->next; // upstream
  z_stream *z = (z_stream*)f->state;

  if (z->avail_in)
    {
    inflate:
      z->next_out = obuf;
      z->avail_out = request;
      ret = inflate(z, Z_NO_FLUSH);
      assert(ret != Z_STREAM_ERROR);  /* state not clobbered */
      switch (ret) {
      case Z_NEED_DICT:
	ret = Z_DATA_ERROR;     /* and fall through */
      case Z_DATA_ERROR:
      case Z_MEM_ERROR:
	(void)inflateEnd(z);
	return 0;
      }
    }
  else
    {
      // read upstream
      in = (up->read)(up, f->ptr, PDF_FILTER_BUF_SIZE);
      z->next_in = f->ptr;
      z->avail_in = in;
      goto inflate;
    }
  if (z->avail_out == 0)
    {
      return request;
    }
  else
    {
      return request - z->avail_out;
    }
}
///////////////////////////////////////////
pdf_err
pdf_rawfilter_close(pdf_filter *f)
{
  if (!f)
    return pdf_ok;
  pdf_free(f);
  return pdf_ok;
}

static int
pdf_rawfilter_read(pdf_filter *f, unsigned char *obuf, int request)
{
  sub_stream *ss;
  if (!f)
    return 0;
  ss = (sub_stream*) f->state;
  return (ss->read)(ss, obuf, request);
}

pdf_filter*
pdf_rawfilter_new(sub_stream* ss)
{
  pdf_filter *f = pdf_malloc(sizeof(pdf_filter));
  if (!f)
    return NULL;
  memset(f, 0, sizeof(pdf_filter));
  f->close = pdf_rawfilter_close;
  f->read = pdf_rawfilter_read;
  f->state = (void*) ss;
  return f;
}

///////////////////////////////////
int
pdf_filter_getchar(pdf_filter *f)
{
  unsigned char a;
  int l;
  l = (f->read)(f, &a, 1);
  if (l==0)
    return 0; // should be EOF
  return a;
}

int
pdf_filter_read(pdf_filter *f, unsigned char *buf, int len)
{
  return (f->read)(f, buf, len);
}

pdf_filter*
pdf_filter_new(pdf_filterkind t)
{
  pdf_filter *f = NULL;
  switch (t)
    {
    case FlateDecode:
      pdf_flated_new(&f);
      break;
    default:
      return NULL;
    }
  return f;
}
