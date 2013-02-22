#include "pdftypes.h"
#include "pdffilter.h"
#include "pdfdevice.h"

void
pdf_dev_destroy(pdf_device *dev)
{
      if (dev)
      {
	    if (dev->destroy)
		  (dev->destroy)(dev);
	    pdf_free(dev);
      }
}

void pdf_device_char_show(pdf_device *dev, pdf_font *f, float scale, gs_matrix *ctm, unsigned int cid)
{
      if (dev && dev->fill_char)
      {
	    (dev->fill_char)(dev, f, scale, ctm, cid, 0);
      }
}

