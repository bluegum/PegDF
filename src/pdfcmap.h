#ifndef PDFCMAP_H
#define PDFCMAP_H

#include "pdftypes.h"
#if defined (_MSC_VER)
#include "radix-trie.h"
#endif

typedef struct pdf_cidsysteminfo_s pdf_cidsysteminfo;
typedef struct pdf_cmap_s pdf_cmap;
typedef struct pdf_tounicode_s pdf_tounicode;

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

struct pdf_tounicode_s
{
      int cid;
      int n;
      char *hex;
};

extern void pdf_tounicode_free(void *u);

#endif // PDFCMAP_H
