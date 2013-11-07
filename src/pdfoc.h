#ifndef PDFOC_H
#define PDFOC_H

#include "pdftypes.h"

typedef struct pdf_ocproperties_s pdf_ocproperties;

struct pdf_ocproperties_s
{
    pdf_obj *ocgs; // must be an array
    struct
    {
        pdf_obj *name;
        pdf_obj *creator;
        pdf_obj *basestate;
        pdf_obj *intent;
        pdf_obj *order;
        pdf_obj *as;
        pdf_obj *on;
        pdf_obj *off;
        pdf_obj *listmode;
        pdf_obj *rbgroups;
        pdf_obj *locked;
    }        d;    // defaults, must be a dict
    pdf_obj *configs; // an array of dictionaries

    int has_defaults;
};

void pdf_ocproperties_free(pdf_ocproperties* oc);
pdf_ocproperties * pdf_ocproperties_load(pdf_obj *oc);

#endif
