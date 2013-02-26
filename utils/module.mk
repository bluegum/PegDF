d	:= utils

$(d)/readpdf : $(d)/readpdf.o  $(TGT_LIB)

$(d)/readpdf.o : pdfread/pdfread.h | $(GLYPH_NAME_TO_UNI)

CLEAN		:= $(CLEAN) $(d)/readpdf.o $(d)/readpdf
