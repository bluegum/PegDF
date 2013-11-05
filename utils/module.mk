APP        += $(addprefix $(BIN_DIR)/, readpdf picker pedal readpdfsh)
d	       := utils
HEADERS    := include/pdf.h src/pdfdoc.h

$(OBJ_DIR)/%.o: $(d)/%.c

$(DEPS_DIR)/%.d: $(d)/%.c
	-@rm -f $@
	$(CC) -MM -MT $(subst .c,.o,$(subst pdfdoc/, $(OBJ_DIR)/, $<)) $(INCLUDE_ALL) $< >> $@

$(BIN_DIR)/readpdf   : $(OBJ_DIR)/readpdf.o  $(TGT_LIB)
$(BIN_DIR)/picker    : $(OBJ_DIR)/picker.o  $(TGT_LIB)
$(BIN_DIR)/pedal     : $(OBJ_DIR)/pedal.o  $(TGT_LIB)

# dynamically linked example
$(BIN_DIR)/readpdfsh : $(OBJ_DIR)/readpdf.o  $(OBJ_DIR)/$(SHAREDOBJ)
	$(CC) -o $@ -L $(OBJ_DIR) -lm -ldl $^

$(OBJ_DIR)/readpdf.o : src/pdfread.h $(HEADERS)
$(OBJ_DIR)/picker.o  : $(HEADERS)
$(OBJ_DIR)/pedal.o  : $(HEADERS)

CLEAN          += $(APP) $(CLEAN) $(OBJ_DIR)/readpdf.o
