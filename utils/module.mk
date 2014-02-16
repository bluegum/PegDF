APP        += $(addprefix $(OUT_DIR)/, readpdf picker pedal readpdfsh)
d	   := utils
HEADERS    := include/pdf.h src/pdfdoc.h

#$(OBJ_DIR)/%.o: $(d)/%.c

$(DEPS_DIR)/%.d: $(d)/%.c
	-@rm -f $@
	$(CC) -MM -MT $(subst .c,.o,$(subst pdfdoc/, $(OBJ_DIR)/, $<)) $(INCLUDE_ALL) $< >> $@

$(OUT_DIR)/readpdf   : $(OBJ_DIR)/readpdf.o  $(LIBS)
$(OUT_DIR)/picker    : $(OBJ_DIR)/picker.o  $(LIBS)
$(OUT_DIR)/pedal     : $(OBJ_DIR)/pedal.o  $(LIBS)

# dynamically linked example
$(BIN_DIR)/readpdfsh : $(OBJ_DIR)/readpdf.o  $(SO_TARGETS)
	$(CC) $(LL_ALL) -o $@ -L $(OBJ_DIR) -lm -ldl $^ -l$(LIB_OBJS)

$(OBJ_DIR)/readpdf.o : src/pdfread.h $(HEADERS)
$(OBJ_DIR)/picker.o  : $(HEADERS)
$(OBJ_DIR)/pedal.o  : $(HEADERS)

CLEAN          += $(APP) $(addprefix $(OBJ_DIR)/, readpdf.o pedal.o picker.o)
