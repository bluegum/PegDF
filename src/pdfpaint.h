#ifndef PDFPAINT_H
#define PDFPAINT_H

typedef struct pdf_path_s pdf_path;
typedef enum pdf_path_kind_e pdf_path_kind;
typedef struct pdf_path_segment_s pdf_path_segment;

enum pdf_path_kind_e
{
      eMOVETO,
      eLINETO,
      eCURVETO,
      eCLOSEPATH
};

struct pdf_path_segment_s
{
      pdf_path_kind (*get)(float *a, float *b, float *c, float *d);
};

struct pdf_path_s
{
      int n;
      pdf_path_segment **subpath; // array of subpaths
};

#endif
