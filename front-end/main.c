#include "tree.h"
#include "symtab.h"

TypeAttr tempTypeAttr;
pTypeAttr tempTA = &tempTypeAttr;
SymNode tempSymNode;
pSymNode tempSN = &tempSymNode;

extern struct stack symTabStack;

int main() {
	initSymTabStack();
	pTree p = parse();
	traverseSyntaxTree(p);

	printSymTab();

	return 0;
}