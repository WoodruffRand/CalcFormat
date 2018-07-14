CC = gcc
CFLAGS = -g -Wall
COMPILE = $(CC) $(CFLAGS)


all: calc format

calc: calc.o binary.o
	$(COMPILE) -o calc calc.o binary.o

calc.o: calc.c
	$(COMPILE) -c calc.c calc.h 

format: format.o binary.o  intToDecASCII.o
	$(COMPILE) -o format format.o binary.o intToDecASCII.o

format.o: format.c binary.o intToDecASCII.o
	$(COMPILE) -c format.c format.h intToDecASCII.o

binary.o: binary.h binary.c
	$(COMPILE) -c binary.c binary.h

intToDecASCII.o: intToDecASCII.h intToDecASCII.c
	$(COMPILE) -c intToDecASCII.c intToDecASCII.h

clean: 
	rm -f core calc format calc.o format.o binary.o intToDecASCII.o #for the love of god don't put .c files here!!
