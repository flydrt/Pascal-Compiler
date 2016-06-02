#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "symtab.h"

void traverseSyntaxTree(pTree root) {
	initSymTabStack();

	switch(root->type) {
		case tPROGRAM: {
			pSymNode *hashtab = newHashTab();
			pushSymTab(hashtab);

			pSymNode p = newSymNode(root->child[1], TYPE_PROG);
			if(insertSymNode(p)) {
				//double define error
				//To do
			}
			traverseSyntaxTree(root->child[2]);
			break;
		}
		case tROUTINE: {
			traverseSyntaxTree(root->child[1]);
			traverseSyntaxTree(root->child[2]);
			break;
		}
		case tROUTINE_HEAD: {
			if (root->child[0])
				traverseSyntaxTree(root->child[0]);
			if (root->child[1])
				traverseSyntaxTree(root->child[1]);
			if (root->child[2])
				traverseSyntaxTree(root->child[2]);
			if (root->child[3])
				traverseSyntaxTree(root->child[3]);
			if (root->child[4])
				traverseSyntaxTree(root->child[4]);
			break;
		}
		case CONST_DECL: {
			pSymNode p = newSymNode(root, TYPE_CONST);
			if(insertSymNode(p)) {
				//double define error
				//To do
			}
			if (root->child[0])
				traverseSyntaxTree(root->child[0]);
			break;
		}
		case TYPE_DECL: {
			//To do
			pSymNode p = newSymNode(root, TYPE_TYPE);
			if(insertSymNode(p)) {
				//double define error
				//To do
			}
			if (root->child[0])
				traverseSyntaxTree(root->child[0]);
			break;
		}
		case tSUB_ROUTINE: {
			traverseSyntaxTree(root->child[1]);
			traverseSyntaxTree(root->child[2]);
			break;
		}
		default: break;
	}
}

pSymNode newSymNode(pTree ptr, IDType t) {
	pSymNode p = (pSymNode)malloc(sizeof(SymNode));
	p->type = t;

	switch(t) {
		case TYPE_UNKNOWN: {
			//To do
			break;
		}
		case TYPE_CONST: {
			strcpy(p->name, (ptr->child[1]->data).stringVal);
			switch(ptr->child[2]->type) {
				case tINTEGER: {
					(p->v).i = (ptr->child[2]->data).intVal;
					break;
				}
				case tREAL: {
					(p->v).d = (ptr->child[2]->data).realVal;
					break;
				}
				case tCHAR: {
					(p->v).c = (ptr->child[2]->data).charVal;
					break;
				}
				case tSTRING: {
					(p->v).s = (ptr->child[2]->data).stringVal;
					break;
				}
			}
			break;
		}
		case TYPE_VAR:
		case TYPE_PROG: {
			strcpy(p->name, (ptr->data).stringVal);
			break;
		}
		case TYPE_PROC:
		case TYPE_FUNC:
		case TYPE_ENUM:
		case TYPE_SUBR:
		case TYPE_RECORD:
		case TYPE_TYPE:
		default: break;
	}

	return p;
}

void initSymTabStack() {
	symTabStack.top = NULL;
}

void pushSymTab(pSymNode * p) {
	pTabNode temp = (pTabNode)malloc(sizeof(TabNode));
	temp->node = p;
	temp->next = symTabStack.top;
	symTabStack.top = temp;
}
void popSymTab() {
	pTabNode temp = symTabStack.top;
	symTabStack.top = (symTabStack.top)->next;
	//temp should be free or enter queue
	//To do
}

pSymNode * newHashTab() {
	pSymNode *p = (pSymNode *)malloc(sizeof(pSymNode) * HASHTAB_SIZE);

	int i;
	for (i = 0; i < HASHTAB_SIZE; i++)
	{
		p[i] = NULL;
	}

	return p;
}

int hash(char *s) {
	int x;

	for (; *s; s++)
	{
		x = x * 31 + *s;
	}

	return x % HASHTAB_SIZE;
}

int isDoubleDefined(pSymNode t, pSymNode p) {
	while (1) {
		if(t == NULL)
			break;
		else if(strcmp(t->name, p->name))
			t = t->next;
		else
			return 1;
	}

	return 0;
}

int insertSymNode(pSymNode p) {
	pSymNode temp = ((symTabStack.top)->node)[hash(p->name)];

	if (temp) {
		if(isDoubleDefined(temp, p))
			return 1;

		p->next = temp;
		((symTabStack.top)->node)[hash(p->name)] = p;
	}
	else
		((symTabStack.top)->node)[hash(p->name)] = p;

	return 0;
}

int main() {
	pSymNode *p = newHashTab();
	SymNode s;
	p[3] = &s;
	strcpy(p[3]->name, "zzz\n");
	printf("%s", p[3]->name);
}