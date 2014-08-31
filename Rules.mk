


# General directory independent rules

%.o:            %.c  | $(OBJ_DIR)
	$(COMP)

%:              %.o
	$(LINK)

%:              %.c
	$(COMPLINK)

%.a:    %.o
	$(AR) r $% $*.o


# The variables TGT_*, CLEAN and CMD_INST* may be added to by the Makefile
# fragments in the various subdirectories.

.PHONY:         targets
targets:        $(TGT_BIN) $(TGT_SBIN) $(TGT_ETC) $(TGT_LIB)
