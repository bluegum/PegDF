d	:= pdfdoc

$(OBJ_DIR)/%.o: $(d)/%.c | $(LIB_CRYPTO) $(OBJ_DIR)
	$(CC) -c $(INCLUDE_ALL) -o $@ $< $(CF_ALL)
$(DEPS_DIR)/%.d: $(d)/%.c | $(DEPS_DIR)
	-@rm -f $@
	$(CC) -MM -MT $(subst .c,.o,$(subst pdfdoc/, $(OBJ_DIR)/, $<)) $(INCLUDE_ALL) $< >> $@

GLYPH_NAME_TO_UNI := glyph_name_to_uni.c

LOCAL_LIB	:= $(OBJ_DIR)/libpdfdoc.a

SRCS_$(d)	:= pdfdoc.c pdfpage.c pdfcatalog.c pdffilter.c pdfcontentstream.c pdfcmds.c pdfcrypto.c \
		pdfcolorspace.c pdfwrite.c pdffont.c pdfencodingtable.c pdfcmap.c pdfdevice.c pdfdevicetxt.c \
	lzw_decomp.c \
		pdfdevicehtml.c pdfpaint.c gxdraw.c $(GLYPH_NAME_TO_UNI)

OBJS_$(d)	:= $(addprefix $(OBJ_DIR)/, $(SRCS_$(d):%.c=%.o))

DEPS_$(d)	:= $(addprefix $(DEPS_DIR)/, $(SRCS_$(d):%.c=%.d))

-include 	$(DEPS_$(d))

HDRS_$(d)	:= $(wildcard $(d)/*.h)

CLEAN		:= $(CLEAN) $(OBJS_$(d)) $(DEPS_$(d))

TGT_LIB		:= $(TGT_LIB) $(LOCAL_LIB)

$(LOCAL_LIB) : $(OBJS_$(d))
	@echo $^ 
	$(ARCHIVE)

GLYPH_NAME_TO_UNI := $(d)/glyph_name_to_uni.c
GLYPH_NAME_TO_UNI_SRC := $(d)/glyphlist.txt
$(GLYPH_NAME_TO_UNI) : $(GLYPH_NAME_TO_UNI_SRC)
	gperf -CGD -L ANSI-C -e ';' -t -N glyph_name_to_uni -H glyph_name_hash $< --output-file=$(GLYPH_NAME_TO_UNI)
pdfdoc/pdffont.c : $(GLYPH_NAME_TO_UNI)

CLEAN		:= $(CLEAN) $(subst .c,.o,$(GLYPH_NAME_TO_UNI))
