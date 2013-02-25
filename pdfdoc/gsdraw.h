#ifndef GSDRAW_H
#define GSDRAW_H

#include "pdftypes.h"

typedef enum pdf_cspacetype_e pdf_cspacetype;
typedef struct pdf_cspace_s pdf_cspace;

enum pdf_cspacetype_e
{
      DeviceGray, DeviceRGB, DeviceCMYK, CalGray, CalRGB, Lab, ICCBased, Indexed, Pattern, Separation, DeviceN
};

enum pdf_renderingintents_e
{
      AbsoluteColorimetric,
      RelativeColorimetric,
      Saturation,
      Perceptual,
};

struct pdf_calgray_s
{
      float whitepoint [3];
      float blackpoint [3];
      float Gamma ;
};

struct pdf_calrgb_s
{
      float whitepoint [3];
      float blackpoint [3];
      float Gamma ;
      float matrix[9];
};
struct pdf_lab_s
{
      float whitepoint [3];
      float blackpoint [3];
      float range[4];
};
struct pdf_icc_s
{
      int n;
      void *Alternate;
      float *range;
      void *metadata;
};

struct pdf_separation_s
{
      char *name;
      pdf_cspacetype alternatespace;
      pdf_obj *tinttransform;
};

struct pdf_indexed_s
{
      pdf_cspacetype base;
      int hival;
      void *lookup;
};

struct pdf_devicen_s
{
      char **names;
      pdf_cspacetype alternatespace;
      pdf_obj *tinttransform;
      struct {
	    pdf_obj *Colorants ;
	    pdf_obj *Process ;
	    pdf_obj *MixingHints ;
      } *attributes;
};

//////////////////////////////////////////////////////////////////////////
// page rendering states
//////////////////////////////////////////////////////////////////////////

struct pdf_cspace_s
{
      pdf_cspacetype t;
      float c[16]; // Ought to be enough for DeviceN
      int n;
      void *priv;
};

////////////////////////////////
extern pdf_err pdf_colorspace_set(pdf_cspace* p, pdf_obj *o);
extern void gx_cmyk_to_rgb(float *cmyk, float *rgb);
extern void gx_rgb_to_rgb(float *, float *rgb);
extern void gx_g_to_rgb(float *, float *rgb);

#endif
