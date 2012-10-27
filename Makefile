### Build flags for all targets
#
INCLUDE_ALL     = -I . -I pdfdoc -I pdfread -I openssl/include/openssl -I openssl
CF_ALL          = -g -Wall -I . $(INCLUDE_ALL)
LF_ALL          = -lz -lm -lcrypto -L openssl -ldl
LL_ALL          =
OPENSSL_DEBUG   =
ifeq	"$(YYDEBUG)" "y"
	CF_ALL += -DYY_DEBUG
endif
ifeq	"$(DEBUG)" "y"
	CF_ALL +=  -DDEBUG
	OPENSSL_DEBUG = -d
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
vpath %.h . pdfdoc
# GLOBALS TARGETS
LIB_CRYPTO  = openssl/libcrypto.a
TGT_LIB	=

APP = readpdf
CLEAN = $(APP) readpdf.o pegx

COMMON_HEADERS := *.h
#######

all :

# sub dirs
# General dir rules
include Rules.mk

.PHONY: all realclean clean
all :  $(APP)
$(APP) : $(LIB_CRYPTO)

readpdf : readpdf.o $(TGT_LIB) $(LIB_CRYPTO)

pegx    :
	$(MAKE) -C peg
	-@cp peg/peg $@

test	:	readpdf
	@./readpdf examples/simpledict.pdf
	@if [ "$$?" -eq 0 ] ;\
	then \
		echo "passed test"; \
	else \
		echo "failed test"; \
	fi
# a hack to force build libcrypto.a first
pdfdoc/pdfcrypto.d : $(LIB_CRYPTO)
## openssl/libcrypto.a
$(LIB_CRYPTO) :
	@cd openssl; ./config $(OPENSSL_DEBUG); $(MAKE) build_crypto; cd ..;

realclean: clean
	@cd openssl; if test -e Makefile ; then $(MAKE) clean; rm -f Makefile; rm crypto/opensslconf.h; rm include/openssl/evp.h; fi; cd ..;
	$(MAKE) -C peg spotless
