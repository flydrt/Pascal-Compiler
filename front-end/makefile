ast: tree.h tree.c syntax.tab.h syntax.tab.c lex.yy.c
	gcc tree.c syntax.tab.c lex.yy.c -o ast
main:  tree.h tree.c syntax.tab.h syntax.tab.c symtab.h symtab.c lex.yy.c main.c
	gcc tree.c syntax.tab.c symtab.c lex.yy.c main.c -o main
