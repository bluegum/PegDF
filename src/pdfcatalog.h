#ifndef PDFCATALOG_H
#define PDFCATALOG_H

typedef enum  {
    pageModeNone,
    pageModeOutlines,
    pageModeThumbs,
    pageModeFullScreen,
    pageModeOC,
    pageModeAttach,
    pageModeNull
} PageMode;
typedef enum  {
    pageLayoutNone,
    pageLayoutSinglePage,
    pageLayoutOneColumn,
    pageLayoutTwoColumnLeft,
    pageLayoutTwoColumnRight,
    pageLayoutTwoPageLeft,
    pageLayoutTwoPageRight,
    pageLayoutNull
} PageLayout;

// Returns the page mode.
PageMode getPageMode();
PageLayout getPageLayout();

#endif
