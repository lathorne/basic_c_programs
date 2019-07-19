CC=gcc
CFLAGS=-Wall -O1 -g
LCFLAGS=-O1
LEX = flex
YACC=bison
LEXLIB =
YAS=./yas

all: yis yas

# These are implicit rules for making .yo files from .ys files.
# E.g., make sum.yo
.SUFFIXES: .ys .yo
.ys.yo:
	$(YAS) $*.ys

# These are the explicit rules for making yis yas and hcl2c and hcl2v
yas-grammar.o: yas-grammar.c
	$(CC) $(LCFLAGS) -c yas-grammar.c

yas-grammar.c: yas-grammar.lex
	$(LEX) yas-grammar.lex
	mv lex.yy.c yas-grammar.c

isa.o: isa.c isa.h
	$(CC) $(CFLAGS) -c isa.c

yas.o: yas.c yas.h isa.h
	$(CC) $(CFLAGS) -c yas.c

yas: yas.o yas-grammar.o isa.o
	$(CC) $(CFLAGS) yas-grammar.o yas.o isa.o ${LEXLIB} -o yas

yis.o: yis.c isa.h
	$(CC) $(CFLAGS) -c yis.c

yis: yis.o isa.o
	$(CC) $(CFLAGS) yis.o isa.o -o yis

clean:
	rm -f *.o *.yo *.exe yis yas hcl2c mux4 *~ core.* 
	rm -f hcl.tab.c hcl.tab.h lex.yy.c yas-grammar.c

