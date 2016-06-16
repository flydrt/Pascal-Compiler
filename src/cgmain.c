#include "tree.h"
#include "symtab.h"
#include "util.h"
#include "dag.h"

extern struct stack symTabStack;

int main() {
	FILE * file = fopen("hello.pas", "r");

	initSymTabStack();
	pTree p = parse(file);
	traverseSyntaxTree(p);
	pTree dag = traverse(p);
	CG_main(dag,"result.s");
//	printSymTab();

	return 0;
}
