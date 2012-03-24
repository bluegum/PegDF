#ifndef PDFDRAW_H
#define PDFDRAW_H

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

#endif
