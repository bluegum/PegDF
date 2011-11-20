CFLAGS += -g

APP = readpdf

all : $(APP)

readpdf : pdf.o readpdf.o

readpdf.o : readpdf.c

pdf.o  : pdf.c

pdf.c  : pdf.peg
	peg -v -o pdf.c pdf.peg
clean: 
	rm *.o $(APP) pdf.c