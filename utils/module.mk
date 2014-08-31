LOCAL_APPS := readpdf picker pedal readpdfsh
APP        += $(addprefix $(OUT_DIR)/, $(LOCAL_APPS))
d	       := utils
HEADERS    := include/pdf.h src/pdfdoc.h

$(DEPS_DIR)/%.d: $(d)/%.c
	-@rm -f $@
	$(CC) -MM -MT $(subst .c,.o,$(subst pdfdoc/, $(OBJ_DIR)/, $<)) $(INCLUDE_ALL) $< >> $@

$(OUT_DIR)/readpdf   : $(d)/readpdf.o  $(LIBS)
$(OUT_DIR)/picker    : $(d)/picker.o  $(LIBS)
$(OUT_DIR)/pedal     : $(d)/pedal.o  $(LIBS)

# dynamically linked example
$(OUT_DIR)/readpdfsh : $(d)/readpdf.o  $(SO_TARGETS)
	$(CC) $(LL_ALL) -o $@ -L $(OBJ_DIR) -L $(LIB_DIR) -lm -ldl $^ -l$(LIB_OBJS)

CLEAN          += $(addprefix $(OUT_DIR)/, $(LOCAL_APPS))
