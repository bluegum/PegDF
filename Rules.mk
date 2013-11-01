
# Standard stuff

.SUFFIXES:
.SUFFIXES:      .c .o

#

$(OBJ_DIR)  :
	mkdir -p $(OBJ_DIR)
$(DEPS_DIR) :
	mkdir -p $(DEPS_DIR)
$(BIN_DIR) :
	mkdir -p $(BIN_DIR)

# Subdirectories, in random order

include         src/module.mk
include         utils/module.mk
include         pkgs/module.mk

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
$(OBJ_DIR)/%.o : utils/%.c | $(OBJ_DIR)
	$(CC) -c $(INCLUDE_ALL) -o $@ $< $(CF_ALL)
$(OBJ_DIR)/%.o : src/%.c | $(OBJ_DIR)
	echo $(CF_ALL)
	$(CC) -c $(INCLUDE_ALL) -o $@ $< $(CF_ALL)

# The variables TGT_*, CLEAN and CMD_INST* may be added to by the Makefile
# fragments in the various subdirectories.

.PHONY:         targets
targets:        $(TGT_BIN) $(TGT_SBIN) $(TGT_ETC) $(TGT_LIB)

.PHONY:         clean
clean:
	- rm -f $(CLEAN) $(TGT_LIB)
	- rm -rf $(DEPS_DIR)

#.PHONY:         install
#install:        targets
#	$(INST) $(TGT_BIN) -m 755 -d $(DIR_BIN)
#	$(CMD_INSTBIN)
#	$(INST) $(TGT_SBIN) -m 750 -d $(DIR_SBIN)
#	$(CMD_INSTSBIN)
#ifeq ($(wildcard $(DIR_ETC)/*),)
#	$(INST) $(TGT_ETC) -m 644 -d $(DIR_ETC)
#	$(CMD_INSTETC)
#else
#	@echo Configuration directory $(DIR_ETC) already present -- skipping
#endif
#	$(INST) $(TGT_LIB) -m 750 -d $(DIR_LIB)
#	$(CMD_INSTLIB)


# Prevent make from removing any build targets, including intermediate ones

.SECONDARY:     $(CLEAN)

