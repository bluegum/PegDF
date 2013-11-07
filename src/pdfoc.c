#include "pdfoc.h"
#include "pdfhelper.h"

pdf_ocproperties *
pdf_ocproperties_load(pdf_obj *oc)
{
    pdf_ocproperties *ocp;
    pdf_obj *defaults;

    if (!oc)
        return 0;
    ocp = pdf_malloc(sizeof(pdf_ocproperties));
    if (!ocp)
        return 0;
    memset(ocp, 0, sizeof(pdf_ocproperties));

    ocp->ocgs = pdf_dict_get(oc, "OCGs");
    if (!ocp->ocgs)
    {
        pdf_free(ocp);
        return 0;
    }

    defaults = pdf_dict_get(oc, "D");
    if (!defaults)
    {
        pdf_free(ocp);
        return 0;
    }
    else
    {
        pdf_obj *d = pdf_obj_deref(defaults);
        ocp->d.name = pdf_dict_get(d, "Name");
        ocp->d.creator = pdf_dict_get(d, "Creator");
        ocp->d.basestate = pdf_dict_get(d, "BaseState");
        ocp->d.on = pdf_dict_get(d, "ON");
        ocp->d.off = pdf_dict_get(d, "OFF");
        ocp->d.intent = pdf_dict_get(d, "Intent");
        ocp->d.as = pdf_dict_get(d, "AS");
        ocp->d.order = pdf_dict_get(d, "Order");
        ocp->d.listmode = pdf_dict_get(d, "ListMode");
        ocp->d.rbgroups = pdf_dict_get(d, "RBGroups");
        ocp->d.locked = pdf_dict_get(d, "Locked");

        ocp->has_defaults = 1;
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
