### Build flags for all targets
#
CF_ALL          = -g -Wall -I .
LF_ALL          =
LL_ALL          =

CFLAGS += -g -Wall
LDFLAGS += -lz
### Build tools
#
CC              = gcc
COMP            = $(CC) $(CF_ALL) $(CF_TGT) -o $@ -c $<
LINK            = $(CC) $(LF_ALL) $(LF_TGT) -o $@ $^ $(LL_TGT) $(LL_ALL)
COMPLINK        = $(CC) $(CF_ALL) $(CF_TGT) $(LF_ALL) $(LF_TGT) -o $@ $< $(LL_TGT) $(LL_ALL)
ARCHIVE			= $(AR) $(ARFLAGS) $@ $^
#
vpath %.h .
# GLOBALS TARGETS
TGT_LIB	=

ifeq	"$(DEBUG)" "y"
	CFLAGS += -DYY_DEBUG
endif

APP = readpdf
CLEAN = $(APP) pdf_peg.c

COMMON_HEADERS := *.h
#######

all :

# sub dirs
# General dir rules
include Rules.mk

.PHONY: all
all : $(APP)

.PHONY: libraries

libraries: $(TGT_LIB)

pdf_peg.c  : pdf.peg
	peg -v -o $(@) $(<)

pdf.c	: pdf_peg.c

readpdf : pdf.o readpdf.o tst.o dict.o bplustree.o pdfindex.o $(TGT_LIB)

test	:	readpdf
	@./readpdf examples/simpledict.pdf
	@if [ "$$?" -eq 0 ] ;\
	then \
		echo "passed test"; \
	else \
		echo "failed test"; \
	fi
