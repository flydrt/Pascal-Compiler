#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util.h"
#include "symtab.h"
#include "error.h"
#include "tree.h"

int rnameCount = 0;

pSymNode traverseSyntaxTree(pTree root) {
	if (root == NULL)
		return NULL;

	switch(root->type) {
		case tPROGRAM: {
			pSymNode *hashtab = newHashTab();
			root->symtab = pushSymTab(hashtab);

			pSymNode p = newEmptySymbol();
			p->type = TYPE_PROG;
			strcpy(p->name, (root->child[1]->data).stringVal);
			if(insertSymNode(p)) {
				//double define error
				//To do
				//nothing?
			}
			traverseSyntaxTree(root->child[2]);
			initRname(root->symtab);
			break;
		}
		case tROUTINE: {
			traverseSyntaxTree(root->child[1]);
			traverseSyntaxTree(root->child[2]);
			break;
		}
		case tSUB_ROUTINE: {
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
			root->symtab = pushSymTab(hashtab);
			traverseSyntaxTree(root->child[1]);
			traverseSyntaxTree(root->child[2]);
//			printSymTab(root->symtab);
			popSymTab();
			initRname(root->symtab);
			traverseSyntaxTree(root->child[0]);
			break;
		}
		case PROCEDURE_DECL: {
			pSymNode *hashtab = newHashTab();
			root->symtab = pushSymTab(hashtab);
			traverseSyntaxTree(root->child[1]);
			traverseSyntaxTree(root->child[2]);
			popSymTab();
			initRname(root->symtab);
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
				parseError(DUPLICATE, root->child[1]->lineno, p->name);
			}
			break;
		}
		case PROCEDURE_HEAD: {
			pSymNode p = newEmptySymbol();
			p->type = TYPE_PROC;
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
				parseError(DUPLICATE, root->child[1]->lineno, p->name);
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
					parseError(DUPLICATE, temp->lineno, p->name);
				}

				last = p;
				temp = temp->child[0];
			}
			return first;
		}

		//stmt
		case LABEL_STMT: {
			traverseSyntaxTree(root->child[2]);
			traverseSyntaxTree(root->child[0]);
			break;
		}
		case ASSIGN_STMT_1: {
			pSymNode p = searchID(root->child[1]->data.stringVal);
			if (!p) {
				//can't find id
				parseError(UNDECL_ID, root->child[1]->lineno, root->child[1]->data.stringVal);

				traverseSyntaxTree(root->child[0]);
				return NULL;
			}
			if (p->type != TYPE_VAR && p->type != TYPE_VALPARA && p->type != TYPE_VARPARA && p->type != TYPE_FUNC) {
				parseError(ASSIGN_TYPE_ERROR, root->child[1]->lineno, root->child[1]->data.stringVal);

				traverseSyntaxTree(root->child[0]);
				return NULL;
			}
			IDAttr attr = getAttr(p);
			if (attr == ATTR_NONE) {
				//To do
				//nothing?
			}
			traverseSyntaxTree(root->child[2]);
			if (root->child[2]->attr == attr) {
				//nothing
			}
			else if (attr == ATTR_REAL && root->child[2]->attr == ATTR_INTEGER) {
				//nothing
				//integer to real
			}
			else {
				//To do
				parseError(ASSIGN_TYPE_NOT_MATCH, root->child[1]->lineno, NULL);
			}

			traverseSyntaxTree(root->child[0]);
			break;
		}
		case ASSIGN_STMT_2: {
			pSymNode p = searchID(root->child[1]->data.stringVal);
			if (!p) {
				//can't find id
				parseError(UNDECL_ID, root->child[1]->lineno, root->child[1]->data.stringVal);

				traverseSyntaxTree(root->child[0]);
				return NULL;
			}
//			if (p->type != TYPE_VAR) {
//				//p is not var
//				parseError(NOT_VAR, root->child[1]->lineno, root->child[1]->data.stringVal);
//
//				traverseSyntaxTree(root->child[0]);
//				return NULL;
//			}
			if (p->type != TYPE_VAR && p->type != TYPE_VALPARA && p->type != TYPE_VARPARA && p->type != TYPE_FUNC) {
				parseError(ASSIGN_TYPE_ERROR, root->child[1]->lineno, root->child[1]->data.stringVal);

				traverseSyntaxTree(root->child[0]);
				return NULL;
			}
			IDAttr attr = getAttr(p);
			if (attr == ATTR_NONE) {
				//To do
				//nothing?
			}
			traverseSyntaxTree(root->child[2]);
			if (root->child[2]->attr != p->link->first->attr) {
				parseError(ARRAY_INDEX_TYPE_NOT_MATCH, root->child[2]->lineno, NULL);
			}

			traverseSyntaxTree(root->child[3]);
			if (root->child[3]->attr != attr) {
				//To do
				parseError(ARRAY_TYPE_NOT_MATCH, root->child[1]->lineno, NULL);
			}

			traverseSyntaxTree(root->child[0]);
			break;
		}
		case ASSIGN_STMT_3: {
			pSymNode p = searchID(root->child[1]->data.stringVal);
			char * name = root->child[2]->data.stringVal;
			if (!p) {
				//can't find id
				parseError(UNDECL_ID, root->child[1]->lineno, root->child[1]->data.stringVal);

				traverseSyntaxTree(root->child[0]);
				return NULL;
			}
//			if (p->type != TYPE_VAR) {
//				//p is not var
//				parseError(NOT_VAR, root->child[1]->lineno, root->child[1]->data.stringVal);
//
//				traverseSyntaxTree(root->child[0]);
//				return NULL;
//			}
			if (p->type != TYPE_VAR && p->type != TYPE_VALPARA && p->type != TYPE_VARPARA && p->type != TYPE_FUNC) {
				parseError(ASSIGN_TYPE_ERROR, root->child[1]->lineno, root->child[1]->data.stringVal);

				traverseSyntaxTree(root->child[0]);
				return NULL;
			}
			if (p->attr != ATTR_RECORD) {
				//To do
				parseError(NOT_RECORD, root->child[1]->lineno, root->child[1]->data.stringVal);

				traverseSyntaxTree(root->child[0]);
				return NULL;
			}

			pSymNode temp = p->link->first;
			while (temp) {
				if (!strcmp(temp->name, name)) {
					break;
				}
				temp = temp->next_link;
			}
			if (temp == NULL) {
				//To do
				//can't find record member
				parseError(NOT_RECORD_MEMBER, root->child[2]->lineno, name);

				traverseSyntaxTree(root->child[0]);
				return NULL;
			}

			IDAttr attr = getAttr(temp);
			traverseSyntaxTree(root->child[3]);
			if (attr != root->child[3]->attr) {
				//To do
				parseError(ASSIGN_TYPE_NOT_MATCH, root->child[3]->lineno, NULL);
			}

			traverseSyntaxTree(root->child[0]);
			break;
		}
		case PROC_STMT_ID: {
			pSymNode p = searchID(root->data.stringVal);
			if (p) {
				if (p->type != TYPE_PROC) {
					parseError(NOT_PROC, root->lineno, root->data.stringVal);

					traverseSyntaxTree(root->child[0]);
					return NULL;
				}
				if (p->next_link != NULL) {
					parseError(PROC_ARGS_LOST, root->lineno, root->data.stringVal);
				}
			}
			else {
				//can't find id
				parseError(UNDECL_ID, root->lineno, root->data.stringVal);
			}

			traverseSyntaxTree(root->child[0]);
			break;
		}
		case PROC_STMT_ID_ARGS: {
			pSymNode p = searchID(root->child[1]->data.stringVal);
			if (p) {
				if (p->type != TYPE_PROC) {
					parseError(NOT_PROC, root->child[1]->lineno, root->child[1]->data.stringVal);
				}

				pTree temp = root->child[2];
				pSymNode tempSym = p->next_link;
				while (temp && tempSym) {
					traverseSyntaxTree(temp);
					if (temp->attr != getAttr(tempSym)) {
						//args not match
						//To do
						if (temp->attr == ATTR_INTEGER && getAttr(tempSym) == ATTR_REAL) {
							//nothing
						}
						else {
							parseError(PROC_ARGS_NOT_MATCH, temp->lineno, tempSym->name);
						}
					}

					tempSym = tempSym->next_link;
					temp = temp->child[0];
				}
				if (temp || tempSym) {
					//num not match
					parseError(PROC_ARGS_NUM_NOT_MATCH, root->child[2]->lineno, NULL);
				}
			}
			else {
				//can't find id
				parseError(UNDECL_ID, root->child[1]->lineno, root->child[1]->data.stringVal);
			}

			traverseSyntaxTree(root->child[0]);
			break;
		}
		case tSYS_PROC: {
			//To do
			traverseSyntaxTree(root->child[0]);
			break;
		}
		case PROC_STMT_SYS_EXPR: {
			//To do
			traverseSyntaxTree(root->child[3]);
			traverseSyntaxTree(root->child[0]);
			break;
		}
		case PROC_STMT_READ: {
			//To do
			traverseSyntaxTree(root->child[1]);
			traverseSyntaxTree(root->child[0]);
			break;
		}
		case IF_STMT: {
			traverseSyntaxTree(root->child[1]);
			if (root->child[1]->attr != ATTR_BOOL) {
				//To do
				parseError(IF_STMT_NOT_BOOL, root->child[1]->lineno, NULL);
			}
			traverseSyntaxTree(root->child[2]);
			traverseSyntaxTree(root->child[3]);
			traverseSyntaxTree(root->child[0]);
			break;
		}
		case REPEAT_STMT: {
			traverseSyntaxTree(root->child[1]);
			traverseSyntaxTree(root->child[2]);
			if (root->child[2]->attr != ATTR_BOOL) {
				//To do
				parseError(REPEAT_STMT_NOT_BOOL, root->child[1]->lineno, NULL);
			}
			traverseSyntaxTree(root->child[0]);
			break;
		}
		case WHILE_STMT: {
			traverseSyntaxTree(root->child[1]);
			if (root->child[1]->attr != ATTR_BOOL) {
				//To do
				parseError(WHILE_STMT_NOT_BOOL, root->child[1]->lineno, NULL);
			}
			traverseSyntaxTree(root->child[2]);
			traverseSyntaxTree(root->child[0]);
			break;
		}
		case FOR_STMT_DOWNTO:
		case FOR_STMT_TO: {
			pSymNode p = searchID(root->child[1]->data.stringVal);
			if (!p) {
				//can't find id
				parseError(UNDECL_ID, root->child[1]->lineno, root->child[1]->data.stringVal);

				traverseSyntaxTree(root->child[0]);
				return NULL;
			}
//			if (p->type != TYPE_VAR) {
//				//p is not var
//				parseError(NOT_VAR, root->child[1]->lineno, root->child[1]->data.stringVal);
//
//				traverseSyntaxTree(root->child[0]);
//				return NULL;
//			}
			if (p->type != TYPE_VAR && p->type != TYPE_VALPARA && p->type != TYPE_VARPARA && p->type != TYPE_FUNC) {
				parseError(ASSIGN_TYPE_ERROR, root->child[1]->lineno, root->child[1]->data.stringVal);

				traverseSyntaxTree(root->child[0]);
				return NULL;
			}
			IDAttr attr = getAttr(p);
			if (attr != ATTR_INTEGER) {
				//To do
				parseError(FOR_STMT_ERROR, root->child[1]->lineno, NULL);
			}

			traverseSyntaxTree(root->child[2]);
			if (root->child[2]->attr != ATTR_INTEGER) {
				//To do
				parseError(FOR_STMT_ERROR, root->child[1]->lineno, NULL);
			}

			traverseSyntaxTree(root->child[3]);
			if (root->child[3]->attr != ATTR_INTEGER) {
				//To do
				parseError(FOR_STMT_ERROR, root->child[1]->lineno, NULL);
			}

			traverseSyntaxTree(root->child[4]);
			traverseSyntaxTree(root->child[0]);
			break;
		}
		case CASE_STMT: {
			traverseSyntaxTree(root->child[1]);
			if (root->child[1]->attr != ATTR_INTEGER && root->child[1]->attr != ATTR_CHAR) {
				//To do
				parseError(CASE_STMT_ERROR, root->child[1]->lineno, NULL);

				traverseSyntaxTree(root->child[0]);
				break;
			}
			IDAttr attr = root->child[1]->attr;

			pTree temp = root->child[2];
			while (temp) {
				traverseSyntaxTree(temp);

				if (attr != temp->attr) {
					//To do
					parseError(CASE_STMT_NOT_MATCH, temp->lineno, NULL);
					break;
				}
				temp = temp->child[0];
			}

			traverseSyntaxTree(root->child[0]);
			break;
		}
		case CASE_EXPR_CONST: {
			switch (root->child[1]->type) {
				case tINTEGER: {
					root->attr = ATTR_INTEGER;
					break;
				}
				case tCHAR: {
					root->attr = ATTR_CHAR;
					break;
				}
				default: {
					//To do
					parseError(CASE_STMT_ERROR, root->child[1]->lineno, NULL);
					break;
				}
			}
			traverseSyntaxTree(root->child[2]);
			break;
		}
		case CASE_EXPR_ID: {
			pSymNode p = searchID(root->child[1]->data.stringVal);
			if (p) {
				if (p->type != TYPE_CONST) {
					//To do
					parseError(NOT_CONST, root->child[1]->lineno, root->child[1]->data.stringVal);
				}
				else {
					if (p->attr == ATTR_INTEGER || p->attr == ATTR_CHAR) {
						root->attr = p->attr;
					}
					else {
						//To do
						parseError(CASE_STMT_ERROR, root->child[1]->lineno, NULL);
					}
				}
			}
			else {
				parseError(UNDECL_ID, root->child[1]->lineno, root->child[1]->data.stringVal);
			}
			traverseSyntaxTree(root->child[2]);
			break;
		}

		//expression
		case eGE:
		case eGT:
		case eLE:
		case eLT:
		case eEQUAL:
		case eUNEQUAL: {
			traverseSyntaxTree(root->child[1]);
			traverseSyntaxTree(root->child[2]);
			if (root->child[1]->attr == root->child[2]->attr) {
				root->attr = ATTR_BOOL;
			}
			else if ((root->child[1]->attr == ATTR_INTEGER && root->child[2]->attr == ATTR_REAL) ||
					(root->child[2]->attr == ATTR_INTEGER && root->child[1]->attr == ATTR_REAL)) {
				root->attr = ATTR_BOOL;
			}
			else if ((root->child[1]->attr == ATTR_CHAR && root->child[2]->attr == ATTR_STRING) ||
					 (root->child[2]->attr == ATTR_CHAR && root->child[1]->attr == ATTR_STRING)) {
				root->attr = ATTR_BOOL;
			}
			else {
				//To do
				parseError(EXPR_TYPE_ERROR, root->child[1]->lineno, NULL);
			}
			traverseSyntaxTree(root->child[0]);
			break;
		}
		case ePLUS: {
			traverseSyntaxTree(root->child[1]);
			traverseSyntaxTree(root->child[2]);
			if (root->child[1]->attr == root->child[2]->attr) {
				root->attr = root->child[1]->attr;
			}
			else if ((root->child[1]->attr == ATTR_INTEGER && root->child[2]->attr == ATTR_REAL) ||
					 (root->child[2]->attr == ATTR_INTEGER && root->child[1]->attr == ATTR_REAL)) {
				root->attr = ATTR_REAL;
			}
			else if ((root->child[1]->attr == ATTR_CHAR && root->child[2]->attr == ATTR_STRING) ||
					 (root->child[2]->attr == ATTR_CHAR && root->child[1]->attr == ATTR_STRING)) {
				root->attr = ATTR_STRING;
			}
			else {
				//To do
				parseError(EXPR_TYPE_ERROR, root->child[1]->lineno, NULL);
			}
			break;
		}
		case eMINUS: {
			traverseSyntaxTree(root->child[1]);
			traverseSyntaxTree(root->child[2]);
			if ((root->child[1]->attr == root->child[2]->attr) &&
					(root->child[1]->attr == ATTR_REAL || root->child[1]->attr == ATTR_INTEGER)) {
				root->attr = root->child[1]->attr;
			}
			else if ((root->child[1]->attr == ATTR_INTEGER && root->child[2]->attr == ATTR_REAL) ||
					 (root->child[2]->attr == ATTR_INTEGER && root->child[1]->attr == ATTR_REAL)) {
				root->attr = ATTR_REAL;
			}
			else {
				//To do
				parseError(EXPR_TYPE_ERROR, root->child[1]->lineno, NULL);
			}
			break;
		}
		case eOR:
		case eAND: {
			traverseSyntaxTree(root->child[1]);
			traverseSyntaxTree(root->child[2]);
			if (root->child[1]->attr == root->child[2]->attr) {
				if (root->child[1]->attr == ATTR_INTEGER) {
					root->attr = ATTR_INTEGER;
				}
				else if (root->child[1]->attr == ATTR_BOOL) {
					root->attr = ATTR_BOOL;
				}
				else {
					//string-string, char-char, real-real
					//To do
					parseError(EXPR_TYPE_ERROR, root->child[1]->lineno, NULL);
				}
			}
			else {
				//To do
				parseError(EXPR_TYPE_ERROR, root->child[1]->lineno, NULL);
			}
			break;
		}
		case eMUL: {
			traverseSyntaxTree(root->child[1]);
			traverseSyntaxTree(root->child[2]);
			if ((root->child[1]->attr == root->child[2]->attr) &&
				(root->child[1]->attr == ATTR_REAL || root->child[1]->attr == ATTR_INTEGER)) {
				root->attr = root->child[1]->attr;
			}
			else if ((root->child[1]->attr == ATTR_INTEGER && root->child[2]->attr == ATTR_REAL) ||
					 (root->child[2]->attr == ATTR_INTEGER && root->child[1]->attr == ATTR_REAL)) {
				root->attr = ATTR_REAL;
			}
			else {
				//To do
				parseError(EXPR_TYPE_ERROR, root->child[1]->lineno, NULL);
			}
			break;
		}
		case eRDIV: {
			traverseSyntaxTree(root->child[1]);
			traverseSyntaxTree(root->child[2]);
			if ((root->child[1]->attr == ATTR_REAL || root->child[1]->attr == ATTR_INTEGER) &&
				(root->child[2]->attr == ATTR_REAL || root->child[2]->attr == ATTR_INTEGER)) {
				root->attr = ATTR_REAL;
			}
			else {
				//To do
				parseError(EXPR_TYPE_ERROR, root->child[1]->lineno, NULL);
			}
			break;
		}
		case eDIV:
		case eMOD: {
			traverseSyntaxTree(root->child[1]);
			traverseSyntaxTree(root->child[2]);
			if (root->child[1]->attr == root->child[2]->attr && root->child[1]->attr == ATTR_INTEGER) {
				root->attr = ATTR_INTEGER;
			}
			else {
				//To do
				parseError(EXPR_TYPE_ERROR, root->child[1]->lineno, NULL);
			}
			break;
		}

		//factor
		case FACTOR_ID: {
			pSymNode p = searchID(root->data.stringVal);
			if (p) {
				if (p->type == TYPE_TYPE) {
					parseError(IS_TYPE, root->lineno, root->data.stringVal);
					root->attr = ATTR_NONE;
					return NULL;
				}
				if (p->type == TYPE_FUNC && p->next_link != NULL) {
					parseError(FUNC_ARGS_LOST, root->lineno, root->data.stringVal);
				}
				root->attr = getAttr(p);
			}
			else {
				//can't find id
				parseError(UNDECL_ID, root->lineno, root->data.stringVal);
			}
			break;
		}
		case FACTOR_FUNC: {
			pSymNode p = searchID(root->child[1]->data.stringVal);
			if (p) {
				if (p->type != TYPE_FUNC) {
					parseError(NOT_FUNC, root->child[1]->lineno, root->child[1]->data.stringVal);
				}
				root->attr = p->attr;

				// To do with child[2]
				pTree temp = root->child[2];
				pSymNode tempSym = p->next_link;
				while (temp && tempSym) {
					traverseSyntaxTree(temp);
					if (temp->attr != getAttr(tempSym)) {
						//args not match
						//To do
						if (temp->attr == ATTR_INTEGER && getAttr(tempSym) == ATTR_REAL) {
							//nothing
						}
						else {
							parseError(FUNC_ARGS_NOT_MATCH, temp->lineno, tempSym->name);
						}
					}

					tempSym = tempSym->next_link;
					temp = temp->child[0];
				}
				if (temp || tempSym) {
					//num not match
					parseError(FUNC_ARGS_NUM_NOT_MATCH, root->child[2]->lineno, NULL);
				}
			}
			else {
				//can't find id
				parseError(UNDECL_ID, root->child[1]->lineno, root->child[1]->data.stringVal);
			}
			break;
		}
		case tSYS_FUNCT: {
			//To do
			break;
		}
		case FACTOR_SYS_FUNC_ARGS: {
			//To do
			traverseSyntaxTree(root->child[2]);
			break;
		}
		case FACTOR_CONST: {
			switch (root->child[1]->type) {
				case tINTEGER: root->attr = root->child[1]->attr = ATTR_INTEGER; break;
				case tREAL: root->attr = root->child[1]->attr = ATTR_REAL; break;
				case tCHAR: root->attr = root->child[1]->attr = ATTR_CHAR; break;
				case tSTRING: root->attr = root->child[1]->attr = ATTR_STRING; break;
				case tSYS_CON: {
					char *temp = root->child[1]->data.stringVal;
					if (!strcmp(temp, "true") || !strcmp(temp, "false")) {
						root->attr = root->child[1]->attr = ATTR_BOOL;
					}
					break;
				}
				default: root->attr = root->child[1]->attr = ATTR_NONE; break;
			}
			break;
		}
		case FACTOR_NOT: {
			traverseSyntaxTree(root->child[1]);
			if (root->child[1]->attr == ATTR_BOOL || root->child[1]->attr == ATTR_INTEGER) {
				root->attr = root->child[1]->attr;
			}
			else if (root->child[1]->attr == ATTR_CHAR) {
				root->attr = ATTR_INTEGER;
			}
			else {
				//To do
				parseError(EXPR_TYPE_ERROR, root->child[1]->lineno, NULL);
			}
			break;
		}
		case FACTOR_MINUS: {
			traverseSyntaxTree(root->child[1]);
			if (root->child[1]->attr == ATTR_INTEGER || root->child[1]->attr == ATTR_REAL) {
				root->attr = root->child[1]->attr;
			}
			else {
				//To do
				parseError(EXPR_TYPE_ERROR, root->child[1]->lineno, NULL);
			}
			break;
		}
		case FACTOR_ARRAY: {
			pSymNode p = searchID(root->child[1]->data.stringVal);
			if (!p) {
				//can't find id
				parseError(UNDECL_ID, root->child[1]->lineno, root->child[1]->data.stringVal);
				return NULL;
			}
//			if (p->type != TYPE_VAR) {
//				//p is not var
//				parseError(NOT_VAR, root->child[1]->lineno, root->child[1]->data.stringVal);
//				return NULL;
//			}
			if (p->type != TYPE_VAR && p->type != TYPE_VALPARA && p->type != TYPE_VARPARA && p->type != TYPE_FUNC) {
				parseError(ASSIGN_TYPE_ERROR, root->child[1]->lineno, root->child[1]->data.stringVal);

				traverseSyntaxTree(root->child[0]);
				return NULL;
			}
			IDAttr attr = getAttr(p);
			if (attr == ATTR_NONE) {
				//To do
				//nothing?
			}
			traverseSyntaxTree(root->child[2]);
			if (root->child[2]->attr != p->link->first->attr) {
				parseError(ARRAY_INDEX_TYPE_NOT_MATCH, root->child[2]->lineno, NULL);
			}

			root->attr = attr;

			break;
		}
		case FACTOR_RECORD: {
			pSymNode p = searchID(root->child[1]->data.stringVal);
			char * name = root->child[2]->data.stringVal;
			if (p) {
//				if (p->type != TYPE_VAR) {
//					//p is not var
//					parseError(NOT_VAR, root->child[1]->lineno, root->child[1]->data.stringVal);
//					return NULL;
//				}
				if (p->type != TYPE_VAR && p->type != TYPE_VALPARA && p->type != TYPE_VARPARA && p->type != TYPE_FUNC) {
					parseError(ASSIGN_TYPE_ERROR, root->child[1]->lineno, root->child[1]->data.stringVal);

					traverseSyntaxTree(root->child[0]);
					return NULL;
				}
				if (p->attr != ATTR_RECORD) {
					//To do
					parseError(NOT_RECORD, root->child[1]->lineno, root->child[1]->data.stringVal);
					return NULL;
				}
				pSymNode temp = p->link->first;
				while (temp) {
					if (!strcmp(temp->name, name)) {
						root->attr = getAttr(temp);
						return NULL;
					}
					temp = temp->next_link;
				}
				//To do
				//can't find record
				parseError(NOT_RECORD_MEMBER, root->child[2]->lineno, name);
			}
			else {
				parseError(UNDECL_ID, root->child[1]->lineno, root->child[1]->data.stringVal);
			}
			break;
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
				case tSYS_CON: {
					char * temp = root->child[2]->data.stringVal;
					if (!strcmp(temp, "true") || !strcmp(temp, "false")) {
						p->attr = ATTR_BOOL;
						(p->v).b = !strcmp(temp, "true") ? true : false;
					}
					break;
				}
				default: break;
			}
			if(insertSymNode(p)) {
				//double define error
				//To do
				parseError(DUPLICATE, root->child[1]->lineno, p->name);
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
				parseError(DUPLICATE, root->child[1]->lineno, p->name);
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
					parseError(DUPLICATE, temp->lineno, p->name);
				}
				temp = temp->child[0];
			}
		 	traverseSyntaxTree(root->child[0]);
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
			else if(!strcmp(s, "boolean"))
				p->attr = ATTR_BOOL;
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
				parseError(UNDECL_TYPE, root->lineno, root->data.stringVal);
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
					parseError(DUPLICATE, root->lineno, root->data.stringVal);
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

			pSymNode p1 = newEmptySymbol();
			switch(root->child[1]->type) {
				case tINTEGER: {
					p1->attr = ATTR_INTEGER;
					(p1->v).i = (root->child[1]->data).intVal;
					break;
				}
				case tCHAR: {
					p1->attr = ATTR_CHAR;
					(p1->v).c = (root->child[1]->data).charVal;
					break;
				}
				case tSYS_CON: {
					char *temp = root->child[1]->data.stringVal;
					if (!strcmp(temp, "true")) {
						p1->attr = ATTR_BOOL;
						p1->v.b = true;
					}
					else if (!strcmp(temp, "false")) {
						p1->attr = ATTR_BOOL;
						p1->v.b = false;
					}
					break;
				}
				default: {
					//To do
					parseError(SUBR_TYPE_ERROR, root->child[1]->lineno, NULL);
					break;
				}
			}
			symbol->link->first = p1;

			pSymNode p2 = newEmptySymbol();
			switch(root->child[2]->type) {
				case tINTEGER: {
					p2->attr = ATTR_INTEGER;
					(p2->v).i = (root->child[2]->data).intVal;
					break;
				}
				case tCHAR: {
					p2->attr = ATTR_CHAR;
					(p2->v).c = (root->child[2]->data).charVal;
					break;
				}
				case tSYS_CON: {
					char *temp = root->child[2]->data.stringVal;
					if (!strcmp(temp, "true")) {
						p2->attr = ATTR_BOOL;
						p2->v.b = true;
					}
					else if (!strcmp(temp, "false")) {
						p2->attr = ATTR_BOOL;
						p2->v.b = false;
					}
					break;
				}
				default: {
					//To do
					parseError(SUBR_TYPE_ERROR, root->child[2]->lineno, NULL);
					break;
				}
			}
			symbol->link->last = p2;

			if (p1->attr != p2->attr) {
				//To do
				parseError(SUBR_TYPE_NOT_MATCH, root->child[1]->lineno, NULL);
			}
			else {
				//To do
				//compare
				switch (p1->attr) {
					case ATTR_INTEGER:
						if (p1->v.i > p2->v.i) {
							//To do
							parseError(SUBR_OVER, root->child[1]->lineno, NULL);
						}
						break;
					case ATTR_CHAR:
						if (p1->v.c > p2->v.c) {
							//To do
							parseError(SUBR_OVER, root->child[1]->lineno, NULL);
						}
						break;
					case ATTR_BOOL:
						if (p1->v.b > p2->v.b) {
							//To do
							parseError(SUBR_OVER, root->child[1]->lineno, NULL);
						}
						break;
					default: break;
				}
			}

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
					if (p1->type != TYPE_CONST) {
						fprintf(stderr, "Error at line %d:\n", root->child[1]->lineno);
						fprintf(stderr, "\t\"%s\" should be const type\n\n", root->child[1]->data.stringVal);
					}
					if (p2->type != TYPE_CONST) {
						fprintf(stderr, "Error at line %d:\n", root->child[2]->lineno);
						fprintf(stderr, "\t\"%s\" should be const type\n\n", root->child[2]->data.stringVal);
					}
				}
			}
			else {
				//can't find ID
				//To do
				if (!p1) {
					parseError(UNDECL_ID, root->child[1]->lineno, root->child[1]->data.stringVal);
				}
				if (!p2) {
					parseError(UNDECL_ID, root->child[2]->lineno, root->child[2]->data.stringVal);
				}
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
				case ATTR_BOOL:
				case ATTR_INTEGER:
				case ATTR_CHAR: {
					break;
				}
				case ATTR_REAL:
				case ATTR_STRING: {
					//To do
					//has been done before
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

pSymNode searchIDWithinScope(char * name, pTabNode symtab, int * ip) {
	pTabNode tempTab = symtab;
	*ip = 0;

	while (tempTab) {
		pSymNode temp = tempTab->node[hash(name)];

		while (temp) {
			if (!strcmp(temp->name, name))
				return temp;
			temp = temp->next;
		}

		(*ip)++;
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

pTabNode pushSymTab(pSymNode * p) {
	pTabNode temp = (pTabNode)malloc(sizeof(TabNode));
	temp->node = p;
	temp->next = symTabStack.top;
	symTabStack.top = temp;
	return temp;
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

IDAttr getAttr(pSymNode p) {
	switch (p->attr) {
		case ATTR_INTEGER:
		case ATTR_REAL:
		case ATTR_CHAR:
		case ATTR_STRING:
		case ATTR_BOOL:
			return p->attr;
		case ATTR_ENUM:
			return p->attr;
		case ATTR_SUBR:
			return p->link->first->attr;
		case ATTR_ARRAY: {
			pTypeAttr temp = p->link;
			while (temp) {
				if (temp->attr == ATTR_INTEGER || temp->attr == ATTR_REAL || temp->attr == ATTR_CHAR ||
					temp->attr == ATTR_STRING || temp->attr == ATTR_BOOL)
					return temp->attr;
				else
					temp = temp->attrLink;
			}
		}
		case ATTR_RECORD:
			return p->attr;
		default: break;
	}

	return ATTR_NONE;
}

void initRname(pTabNode p) {
	int i;
	pTabNode tempTab = p;
	char tempBuf[NAME_LEN];
	while (tempTab) {
		for (i = 0; i < HASHTAB_SIZE; i++) {
			pSymNode temp = tempTab->node[i];
			while (temp) {
				sprintf(tempBuf, "%s%d", temp->name, rnameCount++);
				strcpy(temp->rname, tempBuf);
				temp = temp->next;
			}
		}
		tempTab = tempTab->next;
	}
}