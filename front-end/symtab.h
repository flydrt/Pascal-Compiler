#ifndef SYMTAB_H
#define SYMTAB_H

#include "tree.h"

typedef enum idType {
	TYPE_UNKNOWN, TYPE_CONST, TYPE_VAR,
	TYPE_PROG, TYPE_PROC, TYPE_FUNC,
	TYPE_ENUM, TYPE_SUBR, TYPE_RECORD,
	TYPE_TYPE
} IDType;

typedef enum idAttr {
	ATTR_INTEGER, ATTR_REAL, ATTR_CHAR, ATTR_STRING,
	ATTR_ENUM, ATTR_SUBR,
	ATTR_ARRAY, ATTR_RECORD
} IDAttr;

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
	IDAttr attr;
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

pSymNode traverseSyntaxTree(pTree root);
pSymNode searchID(char * name);
pSymNode newSymNode(pTree ptr, IDType t);
void newAndInsertSymNode(pTree ptr, IDType t, pSymNode temp);

void initSymTabStack();
void pushSymTab(pSymNode * p);
void popSymTab();

pSymNode * newHashTab();
int hash(char *s);
int isDoubleDefined(pSymNode t, pSymNode p);
int insertSymNode(pSymNode p);
void printSymTab();

#endif