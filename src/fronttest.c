#include "tree.h"
#include "symtab.h"
#include "util.h"

extern int errorno;

extern struct stack symTabStack;

int main() {
	FILE * file = fopen("wrong.pas", "r");

	initSymTabStack();
	pTree p = parse(file);
	traverseSyntaxTree(p);

//	printSymTab(symTabStack.top);

//	printf("Error number: %d\n", errorno);

	return 0;
}