#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symNodeType.h"

typedef enum Type {
	tPROGRAM, tROUTINE, tSUB_ROUTINE, tROUTINE_HEAD,
	CONST_DECL, TYPE_DECL, ARRAY_DECL, FIELD_DECL, VAR_DECL,
	FUNCTION_DECL, FUNCTION_HEAD, PROCEDURE_DECL, PROCEDURE_HEAD,
	VAR_PARA, VAL_PARA,
	LABEL_STMT, ASSIGN_STMT_1, ASSIGN_STMT_2, ASSIGN_STMT_3,
	IF_STMT, REPEAT_STMT, WHILE_STMT, FOR_STMT_TO, FOR_STMT_DOWNTO,
	CASE_STMT, CASE_EXPR_CONST, CASE_EXPR_ID, GOTO_STMT,
	eGE, eGT, eLE, eLT, eEQUAL, eUNEQUAL,
	ePLUS, eMINUS, eOR, eMUL, eDIV, eMOD, eAND,
	FACTOR_ID, FACTOR_FUNC, FACTOR_SYS_FUNC_ARGS, FACTOR_CONST, FACTOR_NOT, FACTOR_MINUS, FACTOR_ARRAY, FACTOR_RECORD,
	PROC_STMT_ID, PROC_STMT_ID_ARGS, PROC_STMT_SYS_EXPR, PROC_STMT_READ,
	tSYS_TYPE, tSYS_FUNCT, tSYS_CON, tSYS_PROC,
	tSIMPLE_ID, tSIMPLE_ENUM, tSIMPLE_SUBRANGE, tSIMPLE_SUBRANGE_ID,
	tINTEGER, tREAL, tCHAR, tSTRING, tID
} Type;

typedef struct treeNode {
	Type type;
	int lineno;
	IDAttr attr;
	// int num;
	union {
		int intVal;
		double realVal;
		char charVal;
		char * stringVal;
	} data;
	struct treeNode * child[5];
} Tree, *pTree;

extern int lineno;

pTree newTreeNode(Type type);
char * copyString(char * str);
pTree createList(pTree p1, pTree p2);
void printSyntaxTree(pTree root);
pTree parse(FILE * file);

#endif
