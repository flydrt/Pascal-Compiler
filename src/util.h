#ifndef UTIL_H
#define UTIL_H

#include "symtab.h"

void printSymTab();
void printSymNode(pSymNode temp, int indent);
void printAttr(IDAttr attr);
int isSimpleType(IDAttr attr);
void printSymLink(IDAttr attr, pTypeAttr link, int indent);
void printIndent(int indent);

#endif
