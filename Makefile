# Environment
DEBUG ?= 0
SYSTEM := $(shell uname -s)
# Makefile variables
VPATH          :=
#
LIB_TGT         =
OBJ_DIR        := obj
BIN_DIR         = bin
LIB_DIR         = /usr/lib
INC_DIR         = . include src
DEPS_DIR        = deps
LIB_OBJS       := pegdf
OBJS           :=
TEST_TGTS      :=
### Build flags for all targets
#
PKGS_DIR       := pkgs
CF_ALL          = -Wall -fPIC $(foreach inc, $(INC_DIR), -I$(inc))
LF_ALL          = -L pkgs/openssl
LL_ALL          =  -lm -ldl
OPENSSL_DEBUG   =
INSTALL         = /usr/bin/install -c
LIB_ALL         =
LIB_SUFFIX      =
LIB_PREFIX      =

ifneq (, $(findstring MINGW, $(SYSTEM)))
	LF_ALL += -lgdi32
	LIB_ALL += -lgdi32
	LIB_SUFFIX := .dll
	LIB_DIR := /c/Windows/System32
else
	LIB_SUFFIX := .so
	LIB_PREFIX := lib
endif

ifeq	"$(YYDEBUG)" "y"
	CF_ALL += -DYY_DEBUG
endif

ifeq    "$(DEBUG_STM)" "y"
	DEBUG := "1"
endif

ifeq	($(DEBUG), 1)
	CF_ALL += -pg -g -DDEBUG
	OPENSSL_DEBUG = -d
	LF_ALL += -pg
	LL_ALL += -pg
endif

CF_ALL += -DUSE_OPENSSL

### Build tools
#
CC              = gcc
COMP            = $(CC) $(CF_ALL) -o $@ -c $<
LINK            = $(CC) -o $@ $< $(LIBS)  $(LF_ALL)
COMPLINK        = $(CC) $(CF_ALL) $(LF_ALL) $(LF_TGT) -o $@ $< $(LL_TGT)
ARCHIVE         = $(AR) $(ARFLAGS) $@ $^
MAKE            = make
#
vpath           %.h . src pkgs/zlib
# GLOBALS TARGETS
LIB_CRYPTO      = $(PKGS_DIR)/openssl/libcrypto.a
LIBS	       :=
APP             =
CLEAN          :=
PKG_CLEAN       =
COMMON_HEADERS := *.h
LIBS           += $(LIB_CRYPTO)
LIB_TGT        += $(addprefix $(OBJ_DIR)/,$(addprefix $(LIB_PREFIX),$(addsuffix $(LIB_SUFFIX),$(LIB_OBJS))))

CLEAN          += $(LIB_TGT)
#######


# General directory independent rules

%.o:            %.c  | $(OBJ_DIR)
	$(COMP)

%:              %.o
	$(LINK)

%:              %.c
	$(COMPLINK)

%.a:    %.o
	$(AR) r $% $*.o

VPATH           := $(VPATH) tests utils src

$(DEPS_DIR)/%.d: %.c | $(DEPS_DIR)
	-@rm -f $@
	$(CC) -MM -MT $(subst .c,.o,$(subst src/, $(OBJ_DIR)/, $<)) $(foreach inc, $(INC_DIR), -I$(inc)) $< >> $@

$(OBJ_DIR)/%.o:   %.c  | $(OBJ_DIR)
	$(COMP)

$(BIN_DIR)/% : %.o $(LIBS) | $(BIN_DIR)
	@echo $(LIBS)
	$(LINK) $(LIBS) $(LL_ALL)

# Standard stuff
.SUFFIXES:
.SUFFIXES:      .c .o

# PHONY Targets
.PHONY    : all
.PHONY    : realclean clean release
.PHONY    : install install_strip
all       :
release: all
release: CF_ALL += -O3

# Subdirectories, in random order

include         pkgs/module.mk
include         src/module.mk
include         utils/module.mk
include         tests/module.mk

all         : $(APP) $(LIB_TGT) $(TEST_TGTS)

$(OBJ_DIR)  :
	mkdir -p $(OBJ_DIR)
$(DEPS_DIR) :
	mkdir -p $(DEPS_DIR)
$(BIN_DIR) :
	mkdir -p $(BIN_DIR)


$(APP) : $(targets)

test	:	$(APP)
	@bin/readpdf examples/simpledict.pdf
	@if [ "$$?" -eq 0 ] ;\
	then \
		echo "passed test"; \
	else \
		echo "failed test"; \
	fi
	bin/picker -io X examples/Google.pdf
	@if [ "$$?" -eq 0 ] ; then echo "passed test"; else echo "failed test"; fi


realclean : clean
	- @cd $(PKGS_DIR)/openssl; if test -e Makefile ; then $(MAKE) clean; rm -f Makefile; rm crypto/opensslconf.h; rm include/openssl/evp.h; fi; cd ..;
	- @rm $(GLYPH_NAME_TO_UNI) $(LIB_CRYTO)
	- @rm $(PKG_CLEAN)
	$(MAKE) -C peg spotless


$(BIN_DIR)/% : $(BIN_DIR)/%
	$(INSTALL)

install :: $(LIB_TGT)
	$(INSTALL) $^ $(LIB_DIR)

install :: $(addprefix $(BIN_DIR)/, $(notdir $(APP)))
	$(INSTALL) $^ $(BIN_DIR)

install_strip   : $(addprefix $(BIN_DIR)/, $(notdir $(APP)))
	$(INSTALL) $^ $(BIN_DIR)
	strip $^


.PHONY    : clean

clean:
	- rm -f $(CLEAN)
	- rm -rf $(DEPS_DIR)

check-syntax:
	$(CC) -o nul -S ${CHK_SOURCES}


$(LIB_TGT) : $(LIBS) $(LIB_CRYPTO)
	@echo -n "Making shared object: "
	@echo $@
	$(CC) -shared -o $@ -Wl,--whole-archive $(LIBS) -Wl,--no-whole-archive $(LIB_CRYPTO)  $(LIB_ALL) $(LL_ALL)

$(APP)  : $(LIB_TGT)

debug   : 	CF_ALL += -DDEBUG -pg -g
debug   : 	OPENSSL_DEBUG = -d
debug   : 	LF_ALL += -pg
debug   : 	LL_ALL += -pg
debug   :   $(LIB_TGT) $(APP) $(TEST_TGTS)
debug   :   DEBUG = 1

