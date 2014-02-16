


# General directory independent rules

%.o:            %.c  | $(OBJ_DIR)
	$(COMP)

%:              %.o
	$(LINK)

%:              %.c
	$(COMPLINK)

%.a:    %.o
	$(AR) r $% $*.o

$(BIN_DIR)/% : $(OBJ_DIR)/%.o $(TGT_LIB) $(LIB_CRYPTO) | $(BIN_DIR)
	$(LINK)

# Per directory rules
#%.o : %.c | $(OBJ_DIR)
#	$(CC) -c $(INCLUDE_ALL) -o $@ $< $(CF_ALL)

# The variables TGT_*, CLEAN and CMD_INST* may be added to by the Makefile
# fragments in the various subdirectories.

.PHONY:         targets
targets:        $(TGT_BIN) $(TGT_SBIN) $(TGT_ETC) $(TGT_LIB)
