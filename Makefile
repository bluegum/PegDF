CFLAGS += -g

APP = readpdf

all : $(APP)

readpdf : pdf.o readpdf.o

readpdf.o : readpdf.c

pdf.o  : pdf.c

pegdict.c  : pdf.peg
	peg -o pdf.c pdf.peg
clean: 
	rm *.o $(APP)