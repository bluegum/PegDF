### Build flags for all targets
#
INCLUDE_ALL     = -I . -I pdfdraw -I pdfdoc -I pdfread -I openssl/include -I openssl/include/openssl -I openssl -I zlib
CF_ALL          = -Wall -I . $(INCLUDE_ALL)
LF_ALL          = -pg -lm -lcrypto -L openssl -ldl
LL_ALL          =
OPENSSL_DEBUG   =
INSTALL = /usr/bin/install -c
ifeq	"$(YYDEBUG)" "y"
	CF_ALL += -DYY_DEBUG
endif
ifeq    "$(DEBUG_STM)" "y"
	DEBUG := "y"
endif
ifeq	"$(DEBUG)" "y"
	CF_ALL += -g -DDEBUG
	OPENSSL_DEBUG = -d
else
	CF_ALL += -O3
endif
### Build tools
#
CC              = gcc
COMP            = $(CC) $(CF_ALL) $(CF_TGT) -o $@ -c $<
LINK            = $(CC) -o $@ $^  $(LL_ALL) $(LF_ALL)
COMPLINK        = $(CC) $(CF_ALL) $(CF_TGT) $(LF_ALL) $(LF_TGT) -o $@ $< $(LL_TGT) $(LL_ALL)
ARCHIVE         = $(AR) $(ARFLAGS) $@ $^
MAKE            = make
#
vpath %.h . pdfdoc zlib
#
OBJ_DIR         = obj
DEPS_DIR        = deps
BIN_DIR         = bin
INSTALL_DIR     = /usr/local/bin
# GLOBALS TARGETS
LIB_CRYPTO      = openssl/libcrypto.a
TGT_LIB	        =
APP             =
CLEAN           =

COMMON_HEADERS := *.h
#######

.PHONY : all realclean clean

all :
# sub dirs
# General dir rules
include Rules.mk

$(APP) : $(targets)


test	:	$(APP)
	@bin/readpdf examples/simpledict.pdf
	@if [ "$$?" -eq 0 ] ;\
	then \
		echo "passed test"; \
	else \
		echo "failed test"; \
	fi
## openssl/libcrypto.a
$(LIB_CRYPTO) :  openssl/include/openssl/evp.h
	@cd openssl; ./config $(OPENSSL_DEBUG); $(MAKE) build_crypto; cd ..;
openssl/include/openssl/evp.h :
	@cd openssl; ./config $(OPENSSL_DEBUG); $(MAKE) build_crypto; cd ..;

realclean : clean
	- @cd openssl; if test -e Makefile ; then $(MAKE) clean; rm -f Makefile; rm crypto/opensslconf.h; rm include/openssl/evp.h; fi; cd ..;
	- @rm $(GLYPH_NAME_TO_UNI) $(LIB_CRYTO)
	$(MAKE) -C peg spotless
.PHONY    : all
all       :  $(APP)

.PHONY    : install
$(INSTALL_DIR)/% : $(BIN_DIR)/%
	cp -p $< $@
	strip $@

install   : $(INSTALL_DIR)/picker $(INSTALL_DIR)/pedal
