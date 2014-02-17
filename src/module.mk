d	:= src

KEYWORDS_HASH   := keywords_hash.c
KEYWORDS_HASH_OUT := $(d)/keywords_hash.c

$(OBJ_DIR)/%.o: $(d)/%.c | $(LIB_CRYPTO) $(OBJ_DIR) $(KEYWORDS_HASH_OUT) $(DEPS_DIR)
	$(CC) -c $(INCLUDE_ALL) -o $@ $< $(CF_ALL)
$(DEPS_DIR)/%.d: $(d)/%.c | $(DEPS_DIR)
	-@rm -f $@
	$(CC) -MM -MT $(subst .c,.o,$(subst src/, $(OBJ_DIR)/, $<)) $(INCLUDE_ALL) $< >> $@

GLYPH_NAME_TO_UNI := glyph_name_to_uni.c

LOCAL_LIB	:= $(OBJ_DIR)/libpdfdoc.a

SRCS_$(d)	:= pdfdoc.c pdfpage.c pdfcatalog.c pdffilter.c pdfcontentstream.c pdfcmds.c pdfcrypto.c \
		pdfcolorspace.c pdfwrite.c pdffont.c pdfencodingtable.c pdfcmap.c pdfdevice.c pdfdevicetxt.c \
		pdfoc.c pdfstream.c \
		lzw_decomp.c \
	    pdfobj.c \
		pdfdevicehtml.c pdfpaint.c gxdraw.c \
		\
		pdfread.c bplustree.c dict.c tst.c tst_compact.c pdfindex.c pdfmem.c substream.c $(KEYWORDS_HASH)

OBJS_$(d)	:= $(addprefix $(OBJ_DIR)/, $(SRCS_$(d):%.c=%.o))

DEPS_$(d)	:= $(addprefix $(DEPS_DIR)/, $(SRCS_$(d):%.c=%.d))

ifneq ($(MAKECMDGOALS), clean)
	-include 	$(DEPS_$(d))
endif

HDRS_$(d)	:= $(wildcard $(d)/*.h)

CLEAN		+= $(OBJS_$(d)) $(DEPS_$(d)) $(LOCAL_LIB)

LIBS		+= $(LOCAL_LIB)

$(LOCAL_LIB) : $(OBJS_$(d)) $(d)/pdf_parse.o
	@echo $^
	$(ARCHIVE)

GLYPH_NAME_TO_UNI := $(d)/glyph_name_to_uni.c
GLYPH_NAME_TO_UNI_SRC := $(d)/glyphlist.txt
$(GLYPH_NAME_TO_UNI) : $(GLYPH_NAME_TO_UNI_SRC)
	gperf -CGD -L ANSI-C -e ';' -t -N glyph_name_to_uni -H glyph_name_hash $< --output-file=$(GLYPH_NAME_TO_UNI)

src/pdffont.c : $(GLYPH_NAME_TO_UNI)

CLEAN		+=  $(subst .c,.o,$(GLYPH_NAME_TO_UNI))


########## peg grammar files and extra rules
$(d)/pdf_parse.c $(d)/pdf_parse.o:	$(d)/pdf.c

$(d)/pdf.c  : $(d)/pdf.peg peg/peg
	peg/peg -v -o $(@) $(<)
peg/peg    :
	$(MAKE) -C peg peg

$(KEYWORDS_HASH) : $(KEYWORDS_HASH_OUT)

$(KEYWORDS_HASH_OUT) : $(d)/keywords.txt
	sort $< | uniq | gperf -CGD -L ANSI-C -e ';' -N pdf_keyword_find --output-file=$(KEYWORDS_HASH_OUT)

$(d)/pdfread.c : $(KEYWORDS_HASH)


OBJS           += OBJS_$(d)
