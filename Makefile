# Environment
DEBUG ?= 0
SYSTEM := $(shell uname -s)

### Build flags for all targets
#
PKGS_DIR       := pkgs
INCLUDE_ALL     = -I . -I include -I src -I $(PKGS_DIR)/openssl/include -I $(PKGS_DIR)/openssl/include/openssl -I $(PKGS_DIR)/openssl -I $(PKGS_DIR)/zlib
CF_ALL          = -Wall -fPIC -I . $(INCLUDE_ALL)
LF_ALL          = -lm -lcrypto -L pkgs/openssl -ldl
LL_ALL          =
OPENSSL_DEBUG   =
INSTALL         = /usr/bin/install -c
SO_ALL          =
SO_SUFFIX       =

ifneq (, $(findstring MINGW, $(SYSTEM)))
	LF_ALL += -lgdi32
	SO_ALL += -lgdi32
	SO_SUFFIX := .dll
else
	SO_SUFFIX := .so
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
LINK            = $(CC) -o $@ $^  $(LF_ALL)
COMPLINK        = $(CC) $(CF_ALL) $(CF_TGT) $(LF_ALL) $(LF_TGT) -o $@ $< $(LL_TGT)
ARCHIVE         = $(AR) $(ARFLAGS) $@ $^
MAKE            = make
#
vpath           %.h . src pkgs/zlib
#
SO_TGT          =
SHARED_OBJS    := pegdf
OBJ_DIR        := obj
DEPS_DIR        = deps
BIN_DIR         = bin
INSTALL_DIR     = /usr/local/bin
# GLOBALS TARGETS
LIB_CRYPTO      = pkgs/openssl/libcrypto.a
TGT_LIB	        =
APP             =
CLEAN           = $(SO_TGT)
PKG_CLEAN       =
COMMON_HEADERS := *.h


SO_TGT         += $(addprefix $(OBJ_DIR)/,$(addprefix lib,$(addsuffix $(SO_SUFFIX),$(SHARED_OBJS))))


CLEAN          += $(SO_TGT)
#######

.PHONY : all realclean clean release

release: all
release: CF_ALL += -O3

all    :

# sub dirs
# General dir rules
include Rules.mk

#$(APP) : $(targets)

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
	@cd $(PKGS_DIR)/openssl; ./config $(OPENSSL_DEBUG); $(MAKE) build_crypto; cd ..;
$(PKGS_DIR)/openssl/include/openssl/evp.h :
	@cd openssl; ./config $(OPENSSL_DEBUG); $(MAKE) build_crypto; cd ..;

realclean : clean
	- @cd $(PKGS_DIR)/openssl; if test -e Makefile ; then $(MAKE) clean; rm -f Makefile; rm crypto/opensslconf.h; rm include/openssl/evp.h; fi; cd ..;
	- @rm $(GLYPH_NAME_TO_UNI) $(LIB_CRYTO)
	- @rm $(PKG_CLEAN)
	$(MAKE) -C peg spotless

.PHONY    : all

all       : $(APP) $(SO_TGT)

.PHONY    : install

$(INSTALL_DIR)/% : $(BIN_DIR)/%
	cp -p $< $@
	strip $@

install   : $(INSTALL_DIR)/picker $(INSTALL_DIR)/pedal $(INSTALL_DIR)/readpdf

check-syntax:
	$(CC) -o nul -S ${CHK_SOURCES}


$(SO_TGT) : $(TGT_LIB) $(LIB_CRYPTO)
	@echo -n "Making shared object: "
	@echo $<
	$(CC) -shared -o $@ $(LL_ALL) -Wl,--whole-archive $(TGT_LIB) -Wl,--no-whole-archive $(LIB_CRYPTO)  $(SO_ALL) 

$(APP)  : $(SO_TGT)

debug   : 	CF_ALL += -DDEBUG -pg -g
debug   : 	OPENSSL_DEBUG = -d
debug   : 	LF_ALL += -pg
debug   : 	LL_ALL += -pg -lgmon
debug   :       $(SO_TGT) $(APP)
debug   :       DEBUG = 1
