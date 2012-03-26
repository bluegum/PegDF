#ifndef GSDRAW_H
#define GSDRAW_H

typedef struct gs_matrix_s gs_matrix;
typedef struct gs_point_s gs_point;
typedef struct gs_rect_s gs_rect;
typedef struct gs_bbox_s gs_bbox;

struct gs_matrix_s
{
        float a, b, c, d, e, f;
};

struct gs_point_s
{
        float x, y;
};

struct gs_rect_s
{
        float x0, y0;
        float x1, y1;
};

struct gs_bbox_s
{
        int x0, y0;
        int x1, y1;
};

#include "pdftypes.h"

struct pdf_extgstate_s
{
  float LW;
  int LC;
  int LJ;
  float ML;
  int *D;
  char *RI;
  int OP;
  int op;
  int OPM;
  struct {pdf_obj * font; float size;} *Font;
  void *BG;
  void *BG2;
  void *UCR;
  void *UCR2;
  void *TR;
  void *TR2;
  float FL;
  float SM;
  int SA;
  void *BM;
  void *SMask;
  float CA;
  float ca;
  int AIS;
  int TK;
};

#endif
