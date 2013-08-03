#ifndef PDFOC_H
#define PDFOC_H

#include "pdftypes.h"

typedef struct pdf_ocproperties_s pdf_ocproperties;

struct pdf_ocproperties_s
{
    pdf_obj *ocgs; // must be an array
    pdf_obj *d;    // defaults, must be a dict
    pdf_obj *configs; // an array of dictionaries
};

void pdf_ocproperties_free(pdf_ocproperties* oc);
pdf_ocproperties * pdf_ocproperties_load(pdf_obj *oc);

#endif
