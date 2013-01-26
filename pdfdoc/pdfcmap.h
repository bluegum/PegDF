#ifndef PDFCMAP_H
#define PDFCMAP_H
#include "pdftypes.h"

typedef struct pdf_cidsysteminfo_s pdf_cidsysteminfo;
typedef struct pdf_cmap_s pdf_cmap;

struct pdf_cidsysteminfo_s
{
      char *registry;
      char *ordering;
      int supplement;
};

struct pdf_cmap_s
{
      pdf_obj *cmapname;
      pdf_cidsysteminfo *CIDSystemInfo;
      int wmode;
      pdf_obj *usecmap;
};

#endif // PDFCMAP_H
