#ifndef PDFHELPHER_H
#define PDFHELPHER_H

typedef struct pdf_info_s pdf_info;
struct pdf_info_s
{
    char *title;
    char *author;
    char *subject;
    char *keywords;
    char *creator;
    char *producer;
    char *creationdate;
    char *moddate;
    enum {UNknown, TRue, FAlse} trapped;
};

#endif
