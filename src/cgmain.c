#include "tree.h"
#include "symtab.h"
#include "util.h"
#include "dag.h"

extern struct stack symTabStack;

int main(int argc,char const * argv[]) {
	FILE* file;
	if(argc > 1){
		file = fopen(argv[1],"r");
	}
	else
		file = fopen("hello.pas", "r");
	initSymTabStack();
	pTree p = parse(file);
	pTree dag = traverse(p);
	traverseSyntaxTree(dag);
	CG_main(dag,"result.s");
	return 0;
}
