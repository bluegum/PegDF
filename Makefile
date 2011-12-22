CFLAGS += -g -Wall
LDFLAGS += -lz

ifeq	"$(DEBUG)" "y"
	CFLAGS += -DYY_DEBUG
endif

APP = readpdf

all : $(APP)

pdf_peg.c  : pdf.peg
	peg -v -o $(@) $(<)

pdf.c	: pdf_peg.c

readpdf : pdf.o readpdf.o tst.o dict.o

test	:	readpdf
	@./readpdf examples/simpledict.pdf
	@if [ "$$?" -eq 0 ] ;\
	then \
		echo "passed test"; \
	else \
		echo "failed test"; \
	fi

clean: 
	-rm *.o $(APP) pdf_peg.c
