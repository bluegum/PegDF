APP            += $(addprefix $(BIN_DIR)/, readpdf picker)
d	       := utils

$(OBJ_DIR)/%.o: $(d)/%.c

$(DEPS_DIR)/%.d: $(d)/%.c
	-@rm -f $@
	$(CC) -MM -MT $(subst .c,.o,$(subst pdfdoc/, $(OBJ_DIR)/, $<)) $(INCLUDE_ALL) $< >> $@

$(BIN_DIR)/readpdf : $(OBJ_DIR)/readpdf.o  $(TGT_LIB)
$(BIN_DIR)/picker  : $(OBJ_DIR)/picker.o  $(TGT_LIB)

$(OBJ_DIR)/readpdf.o : pdfread/pdfread.h

CLEAN          += $(APP) $(CLEAN) $(d)/readpdf.o
