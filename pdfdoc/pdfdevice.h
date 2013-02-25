#ifndef PDFDEVICE_H
#define PDFDEVICE_H
#include <stdio.h>
#include "gsdraw.h"
#include "pdffont.h"
#include "pdfpaint.h"

typedef struct pdf_device_s pdf_device;

struct pdf_device_s
{
      gs_bbox dev_bbox;
      gs_matrix dev_ctm;
      //
      pdf_device* (*create)(int w, int h, int res);
      void (*destroy)(pdf_device *);
      void (*doc_begin)(pdf_device *d);
      void (*doc_end)(pdf_device *d);
      void (*page_begin)(pdf_device *d, int idx, float w, float h);
      void (*page_end)(pdf_device *d);
      void (*fill_char)(pdf_device *d, pdf_font *f, float scale, gs_matrix *ctm, unsigned int cid, unsigned int mode);
      void (*stroke_char)(pdf_device *d, pdf_font *f, gs_matrix *ctm, unsigned int cid, unsigned int mode);
      void (*path_paint)(pdf_device *d, pdf_path*, gs_matrix *ctm, int mode);
      void (*image_paint)(pdf_device *d);
      void (*color_set)(pdf_device *d, float *, pdf_cspacetype, int n);
      void (*grp_bgn)(pdf_device *d);
      void (*grp_end)(pdf_device *d);
      struct
      {
	    FILE *f;
	    void *other;
      } dest;
};

extern pdf_device* pdf_dev_text_new(FILE*);
extern pdf_device* pdf_dev_html_new();
extern void pdf_dev_destroy(pdf_device *dev);
#endif
