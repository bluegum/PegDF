CFLAGS += -g

ifeq	"$(DEBUG)" "y"
	CFLAGS += -DYY_DEBUG
endif

APP = readpdf

all : $(APP)

readpdf : pdf.o readpdf.o tst.o dict.o

pdf.peg.c  : pdf.peg
	peg -v -o pdf.peg.c pdf.peg

pdf.c	: pdf.peg.c

clean: 
	rm *.o $(APP) pdf.peg.c
