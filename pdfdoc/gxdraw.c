#include "gsdraw.h"

// dumb conversions
void
gx_cmyk_to_rgb(float *cmyk, float *rgb)
{
      float k = 0.f - cmyk[3];
      rgb[0] = (1.0f - cmyk[0])*k;
      rgb[1] = (1.0f - cmyk[1])*k;
      rgb[2] = (1.0f - cmyk[2])*k;
}
void
gx_rgb_to_rgb(float *from, float *rgb)
{
      rgb[0] = from[0];
      rgb[1] = from[1];
      rgb[2] = from[2];
}

void
gx_g_to_rgb(float *g, float *rgb)
{
      rgb[0] = (*g);
      rgb[1] = (*g);
      rgb[2] = (*g);
}
