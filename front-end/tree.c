#include "tree.h"

pTree newTreeNode(Type type) {
	pTree p = (pTree)malloc(sizeof(struct treeNode));
	
	int i;
	for (i = 0; i < 5; ++i)
	{
		p->child[i] = NULL;
	}

	p->type = type;
	switch(type) {
		case tPROGRAM: p->num = 2; break;
		case tPROGRAM_HEAD: p->num = 3; break;
		default : break;
	}
	
	return p;
}

char * copyString(char * str) {
	char * result = (char *)malloc(strlen(str) + 1);
	strcpy(result, str);
	return result;
}