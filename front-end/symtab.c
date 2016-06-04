#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "symtab.h"

pSymNode traverseSyntaxTree(pTree root) {
	if (root == NULL)
		return NULL;

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
			// if(root->child[2] == NULL)
			// 	printf("NO!");
			traverseSyntaxTree(root->child[2]);
			break;
		}
		case tROUTINE_HEAD: {
			// if(root->child[0] == NULL)
			// 	printf("0");
			// if(root->child[1] == NULL)
			// 	printf("1");
			// if(root->child[2] == NULL)
			// 	printf("2");
			// if(root->child[3] == NULL)
			// 	printf("3");
			// if(root->child[4] == NULL)
			// 	printf("4");
			traverseSyntaxTree(root->child[0]);
			traverseSyntaxTree(root->child[1]);
			traverseSyntaxTree(root->child[2]);
			traverseSyntaxTree(root->child[3]);
			traverseSyntaxTree(root->child[4]);
			break;
		}
		case CONST_DECL: {
			pSymNode p = newSymNode(root, TYPE_CONST);
			if(insertSymNode(p)) {
				//double define error
				//To do
			}
			traverseSyntaxTree(root->child[0]);
			break;
		}
		case TYPE_DECL: {
			pSymNode temp = traverseSyntaxTree(root->child[2]);
			newAndInsertSymNode(root->child[1], TYPE_TYPE, temp);
		 	traverseSyntaxTree(root->child[0]);
		 	break;
		}
		case VAR_DECL: {
		 	pSymNode temp = traverseSyntaxTree(root->child[2]);
		 	newAndInsertSymNode(root->child[1], TYPE_VAR, temp);
		 	traverseSyntaxTree(root->child[0]);
		 	break;
		}
		case tSUB_ROUTINE: {
		 	traverseSyntaxTree(root->child[1]);
			traverseSyntaxTree(root->child[2]);
		 	break;
		}

		//simple_type_decl
		case tSYS_TYPE: {
			pSymNode p = (pSymNode)malloc(sizeof(SymNode));
			char * s = (root->data).stringVal;
			if(!strcmp(s, "integer"))
				p->attr = ATTR_INTEGER;
			else if(!strcmp(s, "real"))
				p->attr = ATTR_REAL;
			else if(!strcmp(s, "char"))
				p->attr = ATTR_CHAR;
			else if(!strcmp(s, "string"))
				p->attr = ATTR_STRING;
			return p;
		}
		case tSIMPLE_ID: {
			// if(searchID((root->data).stringVal)) {
			// 	;
			// }
			// else {
			// 	//can't find type identifier
			// }
			// return p;
		}

		default: break;
	}

	return NULL;
}

pSymNode searchID(char * name) {
	return NULL;
}

pSymNode newSymNode(pTree ptr, IDType t) {
	pSymNode p = (pSymNode)malloc(sizeof(SymNode));
	p->next = NULL;
	p->type = t;

	switch(t) {
		case TYPE_UNKNOWN: {
			//To do
			break;
		}
		case TYPE_CONST: {
			strcpy(p->name, (ptr->child[1]->data).stringVal);
			// printf("%s\n", p->name);
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
		case TYPE_VAR: {

		}
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

void newAndInsertSymNode(pTree ptr, IDType t, pSymNode temp) {
	while (ptr) {
		pSymNode p = (pSymNode)malloc(sizeof(SymNode));
		p->next = NULL;
		strcpy(p->name, (ptr->data).stringVal);
		p->type = t;
		p->attr = temp->attr;
		if(insertSymNode(p)) {
			//double define error
			//To do
		}
		ptr = ptr->child[0];
	}
	free(temp);
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
	int x = 0;

	for (; *s; s++)
	{
		x = x * 7 + *s;
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
	else {
		((symTabStack.top)->node)[hash(p->name)] = p;
	}

	return 0;
}

void printSymTab() {
	int i;
	for (i = 0; i < HASHTAB_SIZE; i++) {
		pSymNode temp = (symTabStack.top)->node[i];
		while(temp) {
			printf("%s ", temp->name);
			switch (temp->type) {
				case TYPE_UNKNOWN: printf("UNKNOWN"); break;
				case TYPE_CONST: printf("CONST"); break;
				case TYPE_VAR: printf("VAR "); printAttr(temp->attr); break;
				case TYPE_PROG: printf("PROG"); break;
				case TYPE_PROC: printf("PROC"); break;
				case TYPE_FUNC: printf("FUNC"); break;
				case TYPE_ENUM: printf("ENUM"); break;
				case TYPE_SUBR: printf("SUBR"); break;
				case TYPE_RECORD: printf("RECORD"); break;
				case TYPE_TYPE: printf("TYPE "); printAttr(temp->attr); break;
				default: break;
			}
			printf("\n");
			temp = temp->next;
		}
	}
}

void printAttr(IDAttr attr) {
	switch (attr) {
		case ATTR_INTEGER: printf("integer"); break;
		case ATTR_REAL: printf("real"); break;
		case ATTR_CHAR: printf("char"); break;
		case ATTR_STRING: printf("string"); break;
		case ATTR_ENUM: printf("enum"); break;
		case ATTR_SUBR: printf("subr"); break;
		case ATTR_ARRAY: printf("array"); break;
		case ATTR_RECORD: printf("record"); break;
	}
}