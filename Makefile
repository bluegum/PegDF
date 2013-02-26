### Build flags for all targets
#
INCLUDE_ALL     = -I . -I pdfdraw -I pdfdoc -I pdfread -I openssl/include -I openssl/include/openssl -I openssl -I zlib
CF_ALL          = -Wall -I . $(INCLUDE_ALL)
#LF_ALL          = -lz -lm -lcrypto -L openssl -ldl
### -lz is omitted because zlib is static now
LF_ALL          = -lm -lcrypto -L openssl -ldl
LL_ALL          =
OPENSSL_DEBUG   =
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
LINK            = $(CC) $(LF_TGT) -o $@ $^ $(LL_TGT) $(LL_ALL) $(LF_ALL)
COMPLINK        = $(CC) $(CF_ALL) $(CF_TGT) $(LF_ALL) $(LF_TGT) -o $@ $< $(LL_TGT) $(LL_ALL)
ARCHIVE         = $(AR) $(ARFLAGS) $@ $^
MAKE            = make
#
vpath %.h . pdfdoc zlib
#
OBJ_DIR         = obj
DEPS_DIR        = deps
APP_DIR         = utils
# GLOBALS TARGETS
LIB_CRYPTO  = openssl/libcrypto.a
TGT_LIB	=
GLYPH_NAME_TO_UNI = glyph_name_to_uni.c
APP = $(APP_DIR)/readpdf
CLEAN = pegx $(subst .c,.o,$(GLYPH_NAME_TO_UNI))

COMMON_HEADERS := *.h
#######

all :  $(APP)
# sub dirs
# General dir rules
include Rules.mk

$(APP) : $(targets)

.PHONY: all realclean clean

pegx    :
	$(MAKE) -C peg
	-@cp peg/peg $@

test	:	$(APP)
	@$(APP) examples/simpledict.pdf
	@if [ "$$?" -eq 0 ] ;\
	then \
		echo "passed test"; \
	else \
		echo "failed test"; \
	fi
## openssl/libcrypto.a
$(LIB_CRYPTO) :
	@cd openssl; ./config $(OPENSSL_DEBUG); $(MAKE) build_crypto; cd ..;

realclean : clean
	- @cd openssl; if test -e Makefile ; then $(MAKE) clean; rm -f Makefile; rm crypto/opensslconf.h; rm include/openssl/evp.h; fi; cd ..;
	- @rm $(GLYPH_NAME_TO_UNI) $(LIB_CRYTO)
	$(MAKE) -C peg spotless

$(GLYPH_NAME_TO_UNI) :
	gperf -CGD -L ANSI-C -e ';' -t -N glyph_name_to_uni -H glyph_name_hash glyphlist.txt --output-file=$(GLYPH_NAME_TO_UNI)

