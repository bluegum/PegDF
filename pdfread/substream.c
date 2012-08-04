#include <stdio.h>
#include "pdftypes.h"
#include "pdffilter.h"
#include "pdfdoc.h"
#include "pdfread.h"
#include "pdfcmds.h"

typedef struct file_stream_s file_stream;

struct file_stream_s
{
      int (*reset)(sub_stream*);
      int (*read)(sub_stream*, unsigned char *, int);
      int (*close)(sub_stream*);
      int len;
      // private
      pdf_parser *p; // global object
      int offset;
      int r; // to seek
      int avail;
};

static int
file_seek(int off)
{
      return fseek(parser_inst->infile, off, SEEK_SET);
}
static int
file_read(unsigned char *buf, int len)
{
      return fread(buf, 1, len, parser_inst->infile);
}
static int
file_unget(unsigned char c)
{
      return ungetc(c, parser_inst->infile);
}
static int
file_close()
{
      return 0;
}
static unsigned char*
file_cache(int len)
{
      return 0;
}

static int
fs_reset(sub_stream* s)
{
      int ret = 0;
      file_stream *fs = (file_stream*)s;
      if (!fs)
            return 0;
      if (!fs->p)
            return 0;
      if (fs->r)
      {
            fs->r = 0;
            fs->avail = fs->len; // through API is better
            ret = (fs->p->seek)(fs->offset-1);
#if 0
            {
                  unsigned char buf[6];
                  // escape "stream"
                  (fs->p->read)(buf, 6);
                  // escape line terminator
                  (fs->p->read)(buf, 1);
                  (fs->p->read)(buf, 1);
                  if (buf[0] == '\n' || buf[0] == '\r')
                  {
                        // do nothing
                  }
                  else
                  {
                        // unget c
                        (fs->p->unget)(buf[0]);
                  }
            }
#endif
      }
      return ret;
}
static int
fs_read(sub_stream* s, unsigned char *buf, int len)
{
      file_stream *fs = (file_stream*)s;
      if (!fs)
            return 0;
      if (!fs->p)
            return 0;
      (fs->reset)(s);
      if (fs->avail == 0)
            return 0;
      if (len > fs->avail)
      {
            len = fs->avail;
            fs->avail = 0;
      }
      else
      {
            fs->avail -= len;
      }
      return (fs->p->read)(buf, len);
}

static int
fs_close(sub_stream* s)
{
      return 0;
}

static
sub_stream*
file_stream_new(int pos, int len)
{
      file_stream *f;
      f = pdf_malloc(sizeof(file_stream));
      if (!f)
            return NULL;
      f->reset = fs_reset;
      f->read = fs_read;
      f->close = fs_close;
      f->offset = pos;
      f->len = len;
      f->p = parser_inst;
      f->r = 1;
      return (sub_stream*)f;
}

void
init_filestream_parser_instance(pdf_parser *p)
{
      if (!p)
            return;
#if 0
      p->infile = stdin;
      p->outfile = stdout;
#endif
      p->seek = file_seek;
      p->read = file_read;
      p->unget = file_unget;
      p->close = file_close;
      p->cache = file_cache;
      p->create_stream = file_stream_new;
      p->lock = 0;
}

///////////////////////////////////////////////////////
typedef struct in_mem_stream_s in_mem_stream;

struct in_mem_stream_s
{
      int (*reset)(sub_stream*);
      int (*read)(sub_stream*, unsigned char *, int);
      int (*close)(sub_stream*);
      int len;
      // private
      unsigned char *s; // start
      unsigned char *p; // current
      unsigned char *e; // end
};

static int
im_reset(sub_stream* s)
{
      in_mem_stream *ms = (in_mem_stream*)s;
      if (!ms)
            return 0;
      return 0;
}
static int
im_read(sub_stream* s, unsigned char *buf, int len)
{
      in_mem_stream *ms = (in_mem_stream*)s;
      if (!ms)
            return 0;
      if (ms->e == ms->p)
            return 0;
      if (ms->e - ms->p >= len)
      {
            memcpy(buf, ms->p, len);
            ms->p += len;
            return len;
      }
      else
      {
            len = ms->e - ms->p;
            memcpy(buf, ms->p, len);
            return len;
      }
}

static int
im_close(sub_stream* s)
{
      in_mem_stream *ms = (in_mem_stream*)s;
      if (!ms || !ms->s)
            return 0;
      pdf_free(ms->s);
      return 0;
}

sub_stream*
in_mem_stream_new(int pos, int len)
{
      in_mem_stream *s;
      s = pdf_malloc(sizeof(in_mem_stream));
      if (!s)
            return NULL;
      s->len = len;
      s->s = (unsigned char*)pos;
      s->p = s->s;
      s->e = s->s + s->len;
      s->reset = im_reset;
      s->read = im_read;
      s->close = im_close;
      return (sub_stream*)s;
}

void
init_in_mem_stream_parser_instance(pdf_parser *p)
{
      if (!p)
            return;
      p->create_stream = in_mem_stream_new;
}
