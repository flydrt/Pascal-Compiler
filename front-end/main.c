#include "tree.h"
#include "symtab.h"

extern struct stack symTabStack;

int main() {
	initSymTabStack();
	pTree p = parse();
	traverseSyntaxTree(p);

	printSymTab();

	return 0;
}