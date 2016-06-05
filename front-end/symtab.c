#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "symtab.h"
#include "tree.h"

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
			switch (arrayType->attr) {
				case ATTR_INTEGER:
				case ATTR_REAL:
				case ATTR_CHAR:
				case ATTR_STRING:{
					symbol->link->attr = arrayType->attr;
					break;
				}
				default: break;
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
	pSymNode temp = ((symTabStack.top)->node)[hash(name)];

	while (temp) {
		if (!strcmp(temp->name, name))
			return temp;
		temp = temp->next;
	}

	return NULL;
}

pSymNode newEmptySymbol() {
	pSymNode result = (pSymNode) malloc(sizeof(SymNode));
	result->next = NULL;
	result->type = TYPE_UNKNOWN;
	result->link = (pTypeAttr)malloc(sizeof(TypeAttr));
	result->link->num = 0;
	result->link->first = NULL;
	result->link->last = NULL;

	return result;
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
					p->attr = ATTR_INTEGER;
					(p->v).i = (ptr->child[2]->data).intVal;
					break;
				}
				case tREAL: {
					p->attr = ATTR_REAL;
					(p->v).d = (ptr->child[2]->data).realVal;
					break;
				}
				case tCHAR: {
					p->attr = ATTR_CHAR;
					(p->v).c = (ptr->child[2]->data).charVal;
					break;
				}
				case tSTRING: {
					p->attr = ATTR_STRING;
					(p->v).s = (ptr->child[2]->data).stringVal;
					break;
				}
				default: break;
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

//void newAndInsertSymNode(pTree ptr, IDType t) {
//	while (ptr) {
//		pSymNode p = (pSymNode)malloc(sizeof(SymNode));
//		p->next = NULL;
//		strcpy(p->name, (ptr->data).stringVal);
//		p->type = t;
//		p->attr = tempSN->attr;
//		if(insertSymNode(p)) {
//			//double define error
//			//To do
//		}
//		ptr = ptr->child[0];
//	}
//}

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
			printSymNode(temp);
			printf("\n");
			temp = temp->next;
		}
	}
}

void printSymNode(pSymNode temp) {
	printf("%s ", temp->name);
	switch (temp->type) {
		case TYPE_UNKNOWN: {
			printf("UNKNOWN ");
			printf("%d", temp->v.i);
			break;
		}
		case TYPE_CONST: {
			printf("CONST ");
			printAttr(temp->attr);
			switch (temp->attr) {
				case ATTR_INTEGER:
					printf(" %d", temp->v.i);
					break;
				case ATTR_REAL:
					printf(" %f", temp->v.d);
					break;
				case ATTR_CHAR:
					printf(" %c", temp->v.c);
					break;
				case ATTR_STRING:
					printf(" %s", temp->v.s);
					break;
				default:
					break;
			}
			break;
		}
		case TYPE_VAR: {
			printf("VAR ");
			printAttr(temp->attr);
			if (!isSimpleType(temp->attr)) {
				printSymLink(temp->attr, temp->link);
			}
			break;
		}
		case TYPE_PROG: {
			printf("PROG");
			break;
		}
		case TYPE_PROC: {
			printf("PROC");
			break;
		}
		case TYPE_FUNC: {
			printf("FUNC");
			break;
		}
		case TYPE_ENUM: {
			printf("ENUM");
			break;
		}
		case TYPE_SUBR: {
			printf("SUBR");
			break;
		}
		case TYPE_RECORD: {
			printf("RECORD ");
			printAttr(temp->attr);
			if (!isSimpleType(temp->attr)) {
				printSymLink(temp->attr, temp->link);
			}
			break;
		}
		case TYPE_TYPE: {
			printf("TYPE ");
			printAttr(temp->attr);
			if (!isSimpleType(temp->attr)) {
				printSymLink(temp->attr, temp->link);
			}
			break;
		}
		default:
			break;
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

int isSimpleType(IDAttr attr) {
	if (attr == ATTR_INTEGER || attr == ATTR_REAL || attr == ATTR_CHAR || attr == ATTR_STRING)
		return 1;
	else
		return 0;
}

void printSymLink(IDAttr attr, pTypeAttr link) {
	switch (attr) {
		case ATTR_ENUM: {
			pSymNode temp = link->first;
			while (temp) {
				printf("\n--- ");
				printSymNode(temp);
				temp = temp->next_link;
			}
			break;
		}
		case ATTR_SUBR: {
			break;
		}
		case ATTR_ARRAY: {
			printf(" ");
			printAttr(link->attr);
			printSymNode(link->first);
			printSymNode(link->last);
			break;
		}
		case ATTR_RECORD: {
			pSymNode temp = link->first;
			while (temp) {
				printf("\n--- ");
				printSymNode(temp);
				temp = temp->next_link;
			}
			break;
		}
		default: break;
	}
}