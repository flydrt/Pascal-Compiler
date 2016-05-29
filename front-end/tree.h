#ifndef TREE_H
#define TREE_H

#include <stdio.h>

typedef enum Type {
	tPROGRAM, tPROGRAM_HEAD, tROUTINE, tSUB_ROUTINE, tROUTINE_HEAD,
	tID,
	DECL_CONST, DECL_TYPE
} Type;

typedef struct treeNode {
	Type type;
	int num;
	union {
		int intVal;
		double realVal;
		char charVal;
		char * stringVal;
	} data;
	struct treeNode * child[5];
} Tree, *pTree;

pTree newTreeNode(Type type);
char * copyString(char * str);

#endif
