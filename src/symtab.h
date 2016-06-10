#ifndef SYMTAB_H
#define SYMTAB_H

#include "tree.h"
#include "symNodeType.h"

struct stack {
	pTabNode top;
} symTabStack;

pSymNode traverseSyntaxTree(pTree root);
pSymNode searchID(char * name);
pSymNode newEmptySymbol();

void initSymTabStack();
pTabNode pushSymTab(pSymNode * p);
void popSymTab();

pSymNode * newHashTab();
int hash(char *s);
int isDoubleDefined(pSymNode t, pSymNode p);
int insertSymNode(pSymNode p);
int insertSymNode2PreviousTab(pSymNode p);
IDAttr getAttr(pSymNode p);
void initRname(pTabNode p);

//Interface for code generation
pSymNode searchIDWithinScope(char * name, pTabNode symtab, int * ip);

#endif