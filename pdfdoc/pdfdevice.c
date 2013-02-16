#include "pdftypes.h"
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
