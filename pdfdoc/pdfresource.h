#ifndef PDFRESOURCE_H
#define PDFRESOURCE_H

typedef struct pdf_resource_s pdf_resource;

struct pdf_resource_s
{
  void *extgstate;
  void *colorspace;
  void *pattern;
  void *shading;
  void *xobject;
  void *font;
  void *procset;
  void *properties;
};
#endif
