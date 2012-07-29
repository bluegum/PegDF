d               := pdfread

LOCAL_LIB       := $(d)/libpdfread.a

SRCS__$(d)      := pdfread.c bplustree.c dict.c tst.c pdfindex.c pdfmem.c substream.c

SRCS_$(d)       := $(addprefix $(d)/, $(SRCS__$(d)))

OBJS_$(d)       := $(SRCS_$(d):%.c=%.o)

DEPS_$(d)       := $(SRCS_$(d):%.c=%.d)

include         $(DEPS_$(d))

HDRS_$(d)       := $(wildcard $(d)/*.h)

CLEAN           := $(CLEAN) $(OBJS_$(d)) $(DEPS_$(d)) $(d)/pdf.c $(d)/pdf_parse.o

TGT_LIB         := $(TGT_LIB) $(LOCAL_LIB)

$(LOCAL_LIB) : $(OBJS_$(d))  $(d)/pdf_parse.o
	@echo $^ 
	$(ARCHIVE)
########## peg grammar files and extra rules 
$(d)/pdf_parse.c $(d)/pdf_parse.o:	$(d)/pdf.c
$(d)/pdf.c  : $(d)/pdf.peg
	peg -v -o $(@) $(<)
