#ifndef PDFDEVICE_H
#define PDFDEVICE_H
#include <stdio.h>
#include "pdfdoc.h"

struct pdf_device_s
{
      gs_bbox dev_bbox;
      gs_matrix dev_ctm;
      //
      pdf_device* (*create)(int w, int h, int res);
      void (*destroy)(pdf_device *);
      void (*fill_char)(pdf_device *d, pdf_font *f, gs_matrix *ctm, unsigned int cid, unsigned int mode);
      void (*stroke_char)(pdf_device *d, pdf_font *f, gs_matrix *ctm, unsigned int cid, unsigned int mode);
      void (*fill_path)(pdf_device *d);
      void (*stroke_path)(pdf_device *d);
      void (*fill_img)(pdf_device *d);
      void (*set_color)(pdf_device *d, float *);
      void (*bgn_grp)(pdf_device *d);
      void (*end_grp)(pdf_device *d);
      union
      {
	    FILE *f;
	    void *other;
      } dest;
};

extern pdf_device* pdf_dev_text_new(FILE*);
extern pdf_device* pdf_dev_html_new();
extern void pdf_dev_destroy(pdf_device *dev);
#endif
