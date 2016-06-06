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

			pSymNode p = newEmptySymbol();
			p->type = TYPE_PROG;
			strcpy(p->name, (root->child[1]->data).stringVal);
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
			traverseSyntaxTree(root->child[0]);
			traverseSyntaxTree(root->child[1]);
			traverseSyntaxTree(root->child[2]);
			traverseSyntaxTree(root->child[3]);
			traverseSyntaxTree(root->child[4]);
			break;
		}

		case FUNCTION_DECL: {
			pSymNode *hashtab = newHashTab();
			pushSymTab(hashtab);
			traverseSyntaxTree(root->child[1]);
			traverseSyntaxTree(root->child[2]);
			popSymTab();
			traverseSyntaxTree(root->child[0]);
			break;
		}
		case PROCEDURE_DECL: {
			pSymNode *hashtab = newHashTab();
			pushSymTab(hashtab);
			traverseSyntaxTree(root->child[1]);
			traverseSyntaxTree(root->child[2]);
			popSymTab();
			traverseSyntaxTree(root->child[0]);
			break;
		}

		case FUNCTION_HEAD: {
			pSymNode p = traverseSyntaxTree(root->child[3]);
			p->type = TYPE_FUNC;
			strcpy(p->name, root->child[1]->data.stringVal);

			pTree temp = root->child[2];
			pSymNode last = NULL;
			while (temp) {
				pSymNode t = traverseSyntaxTree(temp);

				if (p->argc == 0) {
					p->next_link = t;
				}
				else {
					last->next_link = t;
				}

				p->argc += t->argc;

				while (t->next_link) {
					t = t->next_link;
				}
				last = t;

				temp = temp->child[0];
			}
			if (insertSymNode(p)) {
				//To do
			}
			if (insertSymNode2PreviousTab(p)) {
				//To do
			}
			break;
		}
		case VAR_PARA:
		case VAL_PARA: {
			pSymNode varParaType = traverseSyntaxTree(root->child[2]);
			pTree temp = root->child[1];
			pSymNode first = NULL, last = NULL;
			while (temp) {
				pSymNode p = newEmptySymbol();
				p->type = (root->type == VAR_PARA)? TYPE_VARPARA : TYPE_VALPARA;
				p->attr = varParaType->attr;
				p->link = varParaType->link;
				strcpy(p->name, temp->data.stringVal);

				if (first == NULL) {
					first = p;
				}

				first->argc++;
				if (first->argc > 1) {
					last->next_link = p;
				}

				if (insertSymNode(p)) {
					//To do
				}

				last = p;
				temp = temp->child[0];
			}
			return first;
		}

		//decl
		case CONST_DECL: {
			pSymNode p = newEmptySymbol();
			p->type = TYPE_CONST;
			strcpy(p->name, (root->child[1]->data).stringVal);
			switch(root->child[2]->type) {
				case tINTEGER: {
					p->attr = ATTR_INTEGER;
					(p->v).i = (root->child[2]->data).intVal;
					break;
				}
				case tREAL: {
					p->attr = ATTR_REAL;
					(p->v).d = (root->child[2]->data).realVal;
					break;
				}
				case tCHAR: {
					p->attr = ATTR_CHAR;
					(p->v).c = (root->child[2]->data).charVal;
					break;
				}
				case tSTRING: {
					p->attr = ATTR_STRING;
					(p->v).s = (root->child[2]->data).stringVal;
					break;
				}
				default: break;
			}
			if(insertSymNode(p)) {
				//double define error
				//To do
			}
			traverseSyntaxTree(root->child[0]);
			break;
		}
		case TYPE_DECL: {
			pSymNode p = traverseSyntaxTree(root->child[2]);
			p->type = TYPE_TYPE;
			strcpy(p->name, root->child[1]->data.stringVal);
			if (insertSymNode(p)) {
				//To do
			}
		 	traverseSyntaxTree(root->child[0]);
		 	break;
		}
		case VAR_DECL: {
		 	pSymNode varType = traverseSyntaxTree(root->child[2]);
			pTree temp = root->child[1];
			while (temp) {
				pSymNode p = newEmptySymbol();
				p->type = TYPE_VAR;
				p->attr = varType->attr;
				p->link = varType->link;
				strcpy(p->name, temp->data.stringVal);
				if (insertSymNode(p)) {
					//To do
				}
				temp = temp->child[0];
			}
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
			pSymNode p = newEmptySymbol();
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
			pSymNode userType = searchID(root->data.stringVal);
			if (userType) {
				pSymNode p = newEmptySymbol();
				p->link = userType->link;
				p->attr = userType->attr;
				return p;
			}
			else {
				//can't find type identifier
			}
		}
		case tSIMPLE_ENUM: {
			pSymNode symbol = newEmptySymbol();
			symbol->attr = ATTR_ENUM;
			root = root->child[1];

			pSymNode last = NULL;
			while (root) {
				pSymNode p = newEmptySymbol();
				p->type = TYPE_ENUM;
				strcpy(p->name, (root->data).stringVal);
				// can assign p->v
				if (insertSymNode(p)) {
					//To do
				}

				symbol->link->num++;
				if (symbol->link->num == 1) {
					symbol->link->first = p;
				}
				else {
					last->next_link = p;
				}

				last = p;
				root = root->child[0];
			}
			return symbol;
		}
		case tSIMPLE_SUBRANGE: {
			pSymNode symbol = newEmptySymbol();
			symbol->attr = ATTR_SUBR;
			symbol->link->num = 2;

			pSymNode p = newEmptySymbol();
			switch(root->child[1]->type) {
				case tINTEGER: {
					(p->v).i = (root->child[1]->data).intVal;
					break;
				}
				case tREAL: {
					(p->v).d = (root->child[1]->data).realVal;
					break;
				}
				case tCHAR: {
					(p->v).c = (root->child[1]->data).charVal;
					break;
				}
				case tSTRING: {
					(p->v).s = (root->child[1]->data).stringVal;
					break;
				}
				default: break;
			}
			symbol->link->first = p;

			p = newEmptySymbol();
			switch(root->child[2]->type) {
				case tINTEGER: {
					(p->v).i = (root->child[2]->data).intVal;
					break;
				}
				case tREAL: {
					(p->v).d = (root->child[2]->data).realVal;
					break;
				}
				case tCHAR: {
					(p->v).c = (root->child[2]->data).charVal;
					break;
				}
				case tSTRING: {
					(p->v).s = (root->child[2]->data).stringVal;
					break;
				}
				default: break;
			}
			symbol->link->last = p;

			return symbol;
		}
		case tSIMPLE_SUBRANGE_ID: {
			pSymNode symbol = newEmptySymbol();
			symbol->attr = ATTR_SUBR;
			symbol->link->num = 2;

			pSymNode p1 = searchID(root->child[1]->data.stringVal);
			pSymNode p2 = searchID(root->child[2]->data.stringVal);

			if (p1 && p2) {
				if (p1->type == TYPE_CONST && p2->type == TYPE_CONST) {
					symbol->link->first = p1;
					symbol->link->last = p2;
				}
				else {
					//ID is not const
					//To do
				}
			}
			else {
				//can't find ID
				//To do
			}

			return symbol;
		}

		//array_type_decl
		case ARRAY_DECL: {
			pSymNode symbol = traverseSyntaxTree(root->child[1]);
			symbol->attr = ATTR_ARRAY;

			pSymNode arrayType = traverseSyntaxTree(root->child[2]);
			symbol->link->attr = arrayType->attr;
			switch (arrayType->attr) {
				case ATTR_INTEGER:
				case ATTR_REAL:
				case ATTR_CHAR:
				case ATTR_STRING: {
					break;
				}
				default: {
					symbol->link->attrLink = arrayType->link;
					break;
				}
			}

			return symbol;
		}

		//record_type_decl
		case FIELD_DECL: {
			pSymNode symbol = newEmptySymbol();
			symbol->attr = ATTR_RECORD;

			pSymNode last = NULL;
			while(root) {
				pSymNode fieldType = traverseSyntaxTree(root->child[2]);
				pTree temp = root->child[1];
				while(temp) {
					pSymNode p = newEmptySymbol();
					p->type = TYPE_RECORD;
					p->attr = fieldType->attr;
					p->link = fieldType->link;
					strcpy(p->name, temp->data.stringVal);

					symbol->link->num++;
					if (symbol->link->num == 1) {
						symbol->link->first = p;
					}
					else {
						last->next_link = p;
					}

					last = p;
					temp = temp->child[0];
				}
				root = root->child[0];
			}

			return symbol;
		}

		default: break;
	}

	return NULL;
}

pSymNode searchID(char * name) {
	pTabNode tempTab = symTabStack.top;

	while (tempTab) {
		pSymNode temp = tempTab->node[hash(name)];

		while (temp) {
			if (!strcmp(temp->name, name))
				return temp;
			temp = temp->next;
		}

		tempTab = tempTab->next;
	}

	return NULL;
}

pSymNode newEmptySymbol() {
	pSymNode result = (pSymNode) malloc(sizeof(SymNode));
	result->next = NULL;
	result->type = TYPE_UNKNOWN;
	result->argc = 0;
	result->next_link = NULL;
	result->link = (pTypeAttr)malloc(sizeof(TypeAttr));
	result->link->num = 0;
	result->link->first = NULL;
	result->link->last = NULL;

	return result;
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
	//temp should be free or enter a queue
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

int insertSymNode2PreviousTab(pSymNode p) {
	pTabNode tempTab = symTabStack.top->next;
	pSymNode temp = (tempTab->node)[hash(p->name)];

	if (temp) {
		if(isDoubleDefined(temp, p))
			return 1;

		p->next = temp;
		(tempTab->node)[hash(p->name)] = p;

	}
	else {
		(tempTab->node)[hash(p->name)] = p;
	}

	return 0;
}