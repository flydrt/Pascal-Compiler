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
	traverseSyntaxTree(p);
	pTree dag = traverse(p);
	CG_main(p,"result.s");
	return 0;
}
