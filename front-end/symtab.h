#ifndef SYMTAB_H
#define SYMTAB_H

#include "tree.h"

typedef enum idType {
	TYPE_UNKNOWN, TYPE_CONST, TYPE_VAR,
	TYPE_PROG, TYPE_PROC, TYPE_FUNC,
	TYPE_ENUM, TYPE_SUBR, TYPE_RECORD,
	TYPE_TYPE
} IDType;

#define NAME_LEN 255
#define HASHTAB_SIZE 101
typedef enum { false, true } bool;

typedef union value {
	char c;
	char *s;
	int i;
	double d;
	bool b;
} Value;

typedef struct symNode {
	char name[NAME_LEN];
	IDType type;
	Value v;
	struct symNode * next;
} SymNode, *pSymNode;

typedef struct tabNode {
	pSymNode * node;
	struct tabNode * next;
} TabNode, *pTabNode;

struct stack {
	pTabNode top;
} symTabStack;

void initSymTabStack();
void pushSymTab(pSymNode * p);
void popSymTab();
void traverseSyntaxTree(pTree root);
pSymNode newSymNode(pTree ptr, IDType t);
pSymNode * newHashTab();
int hash(char *s);
void insertSymNode(pSymNode p);

//interface for code generation

//end

#endif