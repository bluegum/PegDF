# Environment
DEBUG ?= 0
SYSTEM := $(shell uname -s)


#
LIB_TGT         =
OBJ_DIR        := obj
OUT_DIR         = bin
BIN_DIR         = /usr/local/bin
LIB_DIR         = /usr/lib
DEPS_DIR        = deps
LIB_OBJS       := pegdf
OBJS           :=

### Build flags for all targets
#
PKGS_DIR       := pkgs
INCLUDE_ALL     = -I . -I include -I src -I $(PKGS_DIR)/openssl/include -I $(PKGS_DIR)/openssl/include/openssl -I $(PKGS_DIR)/openssl -I $(PKGS_DIR)/zlib
CF_ALL          = -Wall -fPIC -I . $(INCLUDE_ALL)
LF_ALL          = -lm -lcrypto -L pkgs/openssl -ldl
LL_ALL          =
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


### Build tools
#
CC              = gcc
COMP            = $(CC) $(CF_ALL) $(CF_TGT) -o $@ -c $<
LINK            = $(CC) -o $@ $< $(LIBS)  $(LF_ALL)
COMPLINK        = $(CC) $(CF_ALL) $(CF_TGT) $(LF_ALL) $(LF_TGT) -o $@ $< $(LL_TGT)
ARCHIVE         = $(AR) $(ARFLAGS) $@ $^
MAKE            = make
#
vpath           %.h . src pkgs/zlib
# GLOBALS TARGETS
LIB_CRYPTO      = pkgs/openssl/libcrypto.a
LIBS	       :=
APP             =
CLEAN          :=
PKG_CLEAN       =
COMMON_HEADERS := *.h

LIBS           += $(LIB_CRYPTO)

LIB_TGT         += $(addprefix $(OBJ_DIR)/,$(addprefix $(LIB_PREFIX),$(addsuffix $(LIB_SUFFIX),$(LIB_OBJS))))

CLEAN          += $(LIB_TGT)
#######




# Standard stuff

.SUFFIXES:
.SUFFIXES:      .c .o

#





.PHONY    : all

all       :


.PHONY    :  realclean clean release

release: all
release: CF_ALL += -O3

# General rules
include Rules.mk

# Subdirectories, in random order

include         src/module.mk
include         utils/module.mk
include         pkgs/module.mk

all         : $(APP) $(LIB_TGT)

$(OBJ_DIR)  :
	mkdir -p $(OBJ_DIR)
$(DEPS_DIR) :
	mkdir -p $(DEPS_DIR)
$(OUT_DIR) :
	mkdir -p $(OUT_DIR)




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

## openssl/libcrypto.a
$(LIB_CRYPTO) :  $(PKGS_DIR)/openssl/include/openssl/evp.h
	@cd $(PKGS_DIR)/openssl; $(MAKE) clean; ./config shared $(OPENSSL_DEBUG);  $(MAKE) depend; $(MAKE) build_crypto; cd ..;
$(PKGS_DIR)/openssl/include/openssl/evp.h :
	@cd openssl; ./config shared $(OPENSSL_DEBUG); $(MAKE) build_crypto; cd ..;

realclean : clean
	- @cd $(PKGS_DIR)/openssl; if test -e Makefile ; then $(MAKE) clean; rm -f Makefile; rm crypto/opensslconf.h; rm include/openssl/evp.h; fi; cd ..;
	- @rm $(GLYPH_NAME_TO_UNI) $(LIB_CRYTO)
	- @rm $(PKG_CLEAN)
	$(MAKE) -C peg spotless


.PHONY    : install install_strip

$(BIN_DIR)/% : $(OUT_DIR)/%
	$(INSTALL)

install :: $(LIB_TGT)
	$(INSTALL) $^ $(LIB_DIR)

install :: $(addprefix $(OUT_DIR)/, $(notdir $(APP)))
	$(INSTALL) $^ $(BIN_DIR)

install_strip   : $(addprefix $(OUT_DIR)/, $(notdir $(APP)))
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
	$(CC) -shared -o $@ $(LL_ALL) -Wl,--whole-archive $(LIBS) -Wl,--no-whole-archive $(LIB_CRYPTO)  $(LIB_ALL) 

$(APP)  : $(LIB_TGT)

debug   : 	CF_ALL += -DDEBUG -pg -g
debug   : 	OPENSSL_DEBUG = -d
debug   : 	LF_ALL += -pg
debug   : 	LL_ALL += -pg
debug   :       $(LIB_TGT) $(APP)
debug   :       DEBUG = 1



