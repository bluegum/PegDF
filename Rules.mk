
# Standard stuff

.SUFFIXES:
.SUFFIXES:      .c .o

#

$(OBJ_DIR)  :
	mkdir -p $(OBJ_DIR)
$(DEPS_DIR) :
	mkdir -p $(DEPS_DIR)

# Subdirectories, in random order

include         pdfread/module.mk
include         pdfdoc/module.mk
include         pdfdraw/module.mk
include         zlib/module.mk
include         utils/module.mk

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

.PHONY:         clean
clean:
	- rm -f $(CLEAN) $(TGT_LIB)
	- rm -rf $(OBJ_DIR) $(DEPS_DIR)

.PHONY:         install
install:        targets
	$(INST) $(TGT_BIN) -m 755 -d $(DIR_BIN)
	$(CMD_INSTBIN)
	$(INST) $(TGT_SBIN) -m 750 -d $(DIR_SBIN)
	$(CMD_INSTSBIN)
ifeq ($(wildcard $(DIR_ETC)/*),)
	$(INST) $(TGT_ETC) -m 644 -d $(DIR_ETC)
	$(CMD_INSTETC)
else
	@echo Configuration directory $(DIR_ETC) already present -- skipping
endif
	$(INST) $(TGT_LIB) -m 750 -d $(DIR_LIB)
	$(CMD_INSTLIB)


# Prevent make from removing any build targets, including intermediate ones

.SECONDARY:     $(CLEAN)

