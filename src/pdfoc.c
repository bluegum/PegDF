#include "pdfoc.h"
#include "pdfhelper.h"

pdf_ocproperties *
pdf_ocproperties_load(pdf_obj *oc)
{
    pdf_ocproperties *ocp;
    if (!oc)
        return 0;
    ocp = pdf_malloc(sizeof(pdf_ocproperties));
    if (!ocp)
        return 0;
    ocp->ocgs = pdf_dict_get(oc, "OCGs");
    if (!ocp->ocgs)
    {
        pdf_free(ocp);
        return 0;
    }
    ocp->d = pdf_dict_get(oc, "D");
    if (!ocp->d)
    {
        pdf_free(ocp);
        return 0;
    }
    ocp->configs = pdf_dict_get(oc, "Configs");
    return ocp;
}

void
pdf_ocproperties_free(pdf_ocproperties* oc)
{
    if (!oc)
        return;
    pdf_free(oc);
}
