#include <assert.h>
#include "zlib.h"
#include "pdftypes.h"
#include "pdfmem.h"
#include "pdffilter.h"
#include "pdfdoc.h"
#include "pdfread.h"

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
            return pdf_unknown;
      *f = pdf_malloc(sizeof(pdf_filter));
      if (!(*f))
            return pdf_mem_err;
      z = pdf_malloc(sizeof(z_stream));
      if (!z)
            return pdf_mem_err;
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
        read_upstream:
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
            if (request == z->avail_out)
                  if (in)
                        goto read_upstream;
            return request - z->avail_out;
      }
}
///////////////////////////////////////////
pdf_err
pdf_rawfilter_close(pdf_filter *f)
{
      sub_stream *ss;
      if (!f)
            return 0;
      ss = (sub_stream*) f->state;
      (ss->close)(ss);
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

/////////////////////////////////////////// ASCII85Decode
struct pdf_a85d_s
{
      unsigned char bp[4];
      unsigned char *rp, *wp;
      int eod;
};

pdf_err
pdf_a85d_close(pdf_filter *f)
{
      if (!f)
            return 0;
      pdf_free(f->state);
      pdf_free(f);
      return pdf_ok;
}

static int
pdf_a85d_read(pdf_filter *f, unsigned char *obuf, int request)
{
      struct pdf_a85d_s *state;
      pdf_filter *up;
      unsigned char *p = obuf;
      unsigned char *e = obuf+request;
      unsigned char c;
      unsigned int word=0, count=0;

      if (!f)
            return 0;
      state = f->state;
      if (!state)
            return 0;
      up = f->next; // upstream
      if (!up)
            return 0;
      while (p < e)
      {
            int l;
            if (state->eod)
                  return p - obuf;
            // read upstream
            l = (up->read)(up, &c, 1);
            if (l == 0)
            { // eof
                  return p - obuf;
            }
            if (c >= '!' && c <= 'u')
            {
                  if (count == 4)
                  {
                        word = word * 85 + (c - '!');

                        state->bp[0] = (word >> 24) & 0xff;
                        state->bp[1] = (word >> 16) & 0xff;
                        state->bp[2] = (word >> 8) & 0xff;
                        state->bp[3] = (word) & 0xff;
                        state->rp = state->bp;
                        state->wp = state->bp + 4;

                        word = 0;
                        count = 0;
                  }
                  else
                  {
                        word = word * 85 + (c - '!');
                        count ++;
                  }
            }
            else if (c == 'z' && count == 0)
            {
                  state->bp[0] = 0;
                  state->bp[1] = 0;
                  state->bp[2] = 0;
                  state->bp[3] = 0;
                  state->rp = state->bp;
                  state->wp = state->bp + 4;
            }
            else if (c == '~')
            {
                  int l = (up->read)(up, &c, 1);

                  if (l == 0 || (c != '>'))
                        printf("%s\n", "bad eod marker in a85d");

                  switch (count) {
                        case 0:
                              break;
                        case 1:
                              printf("%s\n", "partial final byte in a85d");
                        case 2:
                              word = word * (85 * 85 * 85) + 0xffffff;
                              state->bp[0] = word >> 24;
                              state->rp = state->bp;
                              state->wp = state->bp + 1;
                              break;
                        case 3:
                              word = word * (85 * 85) + 0xffff;
                              state->bp[0] = word >> 24;
                              state->bp[1] = word >> 16;
                              state->rp = state->bp;
                              state->wp = state->bp + 2;
                              break;
                        case 4:
                              word = word * 85 + 0xff;
                              state->bp[0] = word >> 24;
                              state->bp[1] = word >> 16;
                              state->bp[2] = word >> 8;
                              state->rp = state->bp;
                              state->wp = state->bp + 3;
                              break;
                  }
                  state->eod = 1;
            }
            else if (c != ' ')
            {
                  printf("%s\n", "bad data in a85d: '%c'");
                  return 0;
            }

            while (state->rp < state->wp && p < e)
                  *p++ = *state->rp++;
      }
      return p - obuf;
}

pdf_err
pdf_a85d_new(pdf_filter **f)
{
      struct pdf_a85d_s *state;
      *f = pdf_malloc(sizeof(pdf_filter));
      if (!(*f))
            return pdf_mem_err;
      memset(*f, 0, sizeof(pdf_filter));
      (*f)->close = pdf_a85d_close;
      (*f)->read = pdf_a85d_read;
      state = pdf_malloc(sizeof(struct pdf_a85d_s));
      if (!state)
      {
            pdf_free(*f);
            return pdf_mem_err;
      }
      state->rp = state->bp;
      state->wp = state->bp;
      state->eod = 0;
      (*f)->state = state;
      return pdf_ok;
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
            case ASCII85Decode:
                  pdf_a85d_new(&f);
                  break;
            default:
                  return NULL;
      }
      return f;
}
