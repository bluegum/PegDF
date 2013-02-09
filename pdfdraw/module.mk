d	:= pdfdraw

$(OBJ_DIR)/%.o  : $(d)/%.c
	$(CC) -c $(INCLUDE_ALL) -o $@ $< $(CF_ALL)
$(DEPS_DIR)/%.d : $(d)/%.c | $(DEPS_DIR)
	-@rm -f $@
	$(CC) -MM -MT $(subst .c,.o,$(subst pdfdraw/, $(OBJ_DIR)/, $<)) $(INCLUDE_ALL) $< >> $@

LOCAL_LIB	:= $(OBJ_DIR)/libpdfdraw.a

SRCS_$(d)	:= pdfdraw.c

OBJS_$(d)	:= $(addprefix $(OBJ_DIR)/, $(SRCS_$(d):%.c=%.o))

DEPS_$(d)	:= $(addprefix $(DEPS_DIR)/, $(SRCS_$(d):%.c=%.d))

include 	$(DEPS_$(d))

CLEAN		:= $(CLEAN) $(OBJS_$(d)) $(DEPS_$(d))

TGT_LIB		:= $(TGT_LIB) $(LOCAL_LIB)

$(LOCAL_LIB) : $(OBJS_$(d)) $(COMMON_HEADERS)
		$(ARCHIVE)
