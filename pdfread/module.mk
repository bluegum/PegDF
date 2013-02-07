d               := pdfread

$(OBJ_DIR)/%.o  : $(d)/%.c
	$(CC) -c $(INCLUDE_ALL) -o $@ $< $(CF_ALL) 

$(DEPS_DIR)/%.d: $(d)/%.c
	-rm -f $@
	$(CC) -MM -MT $(subst .c,.o,$<) $(INCLUDE_ALL) $< >> $@

LOCAL_LIB       := $(OBJ_DIR)/libpdfread.a

SRCS_$(d)       := pdfread.c bplustree.c dict.c tst.c pdfindex.c pdfmem.c substream.c

OBJS_$(d)	:= $(addprefix $(OBJ_DIR)/, $(SRCS_$(d):%.c=%.o))

DEPS_$(d)	:= $(addprefix $(DEPS_DIR)/, $(SRCS_$(d):%.c=%.d))

include         $(DEPS_$(d))

HDRS_$(d)       := $(wildcard $(d)/*.h)

CLEAN           := $(CLEAN) $(OBJS_$(d)) $(DEPS_$(d)) $(d)/pdf.c $(d)/pdf_parse.o

TGT_LIB         := $(TGT_LIB) $(LOCAL_LIB)

$(LOCAL_LIB) : $(OBJS_$(d))  $(d)/pdf_parse.o
	@echo $^
	$(ARCHIVE)
########## peg grammar files and extra rules
$(d)/pdf_parse.c $(d)/pdf_parse.o:	$(d)/pdf.c
$(d)/pdf.c  : $(d)/pdf.peg ./pegx
	./pegx -v -o $(@) $(<)
