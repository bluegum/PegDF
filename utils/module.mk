d	:= utils

$(d)/readpdf : $(d)/readpdf.o  $(TGT_LIB)

$(d)/readpdf.o : pdfread/pdfread.h

CLEAN		:= $(CLEAN) $(d)/readpdf.o $(d)/readpdf
