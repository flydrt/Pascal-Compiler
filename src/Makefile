# Makefile for lpc compiler.
#
FLEX=flex
FLEXFLAGS=
BISONFLAGS=-d
BISON=bison
COMPILER_DIST=pascalCompiler
CC=gcc
CFLAGS=-g -Wall
LDFLAGS=-g -Wall
CVS=cvs

COMPILER_HEADER=symtab.h \
				tree.h \
				dag.h \
				util.h \
				cg.h \
				symNodeType.h \
				error.h \
				syntax.tab.h \

COMPILER_SOURCE=cgmain.c \
				symtab.c \
				symtab.h \
				tree.c \
				tree.h \
				dag.h \
				lex.yy.c \
				dag.c \
				util.c \
				cg.c \
				error.c \
				syntax.tab.c \
	

COMPILER_OBJS=cgmain.o \
			  symtab.o \
			  tree.o \
			  dag.o \
			  util.o \
			  cg.o \
			  lex.yy.o \
			  error.o \
			  syntax.tab.o \

# COMPILER_AUTOFILES=y.tab.c \
# 				   lex.yy.c \
# 				   rule.c \
# 				   h.tab.h \
# 				   rule.h

.SUFFIXES:.c

all: $(COMPILER_DIST)

# dag.o: dag.c dag.h
# 	$(CC) $(CFLAGS) -c $<


%.o:%.c $(COMPILER_HEADER)
	$(CC) $(CFLAGS) -c $<


$(COMPILER_DIST):$(COMPILER_OBJS) $(COMPILER_HEADER)
	gcc -o $(COMPILER_DIST) $(LDFLAGS) $(COMPILER_OBJS)

clean:
	rm -f *.o
	rm -f $(COMPILER_DIST)
	rm -f $(COMPILER_AUTOFILES)

