#include "tree.h"
#include "symtab.h"
#include "util.h"

extern struct stack symTabStack;

int main() {
	FILE * file = fopen("wrong.pas", "r");

	initSymTabStack();
	pTree p = parse(file);
	traverseSyntaxTree(p);

//	printSymTab(symTabStack.top);

	return 0;
}