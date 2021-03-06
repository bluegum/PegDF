d	:= pkgs/zlib

$(OBJ_DIR)/%.o  : $(d)/%.c
	$(CC) -c $(INCLUDE_ALL) -o $@ $< $(CF_ALL)

$(DEPS_DIR)/%.d: $(d)/%.c  | $(DEPS_DIR)
	-@rm -f $@
	$(CC) -MM -MT $(subst .c,.o,$(subst $(d)/, $(OBJ_DIR)/, $<)) $(INCLUDE_ALL) $< >> $@

LOCAL_LIB	:= $(OBJ_DIR)/libzlib.a

SRCS_$(d)	:=         adler32.c \
        compress.c \
        crc32.c \
        deflate.c \
        inffast.c \
        inflate.c \
        inftrees.c \
        trees.c \
        uncompr.c \
        zutil.c

OBJS_$(d)	:= $(addprefix $(OBJ_DIR)/, $(SRCS_$(d):%.c=%.o))

DEPS_$(d)	:= $(addprefix $(DEPS_DIR)/,$(SRCS_$(d):%.c=%.d))

ifneq ($(MAKECMDGOALS), clean)
	-include 	$(DEPS_$(d))
endif

HDRS_$(d)	:= $(wildcard $(d)/*.h)

CLEAN		+= $(OBJS_$(d)) $(DEPS_$(d))

LIBS		+= $(LOCAL_LIB)

$(LOCAL_LIB) : $(OBJS_$(d))
	@echo $^
	$(ARCHIVE)
