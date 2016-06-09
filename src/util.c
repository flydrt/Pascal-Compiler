#include "util.h"

void printSymTab() {
    int i;
    pTabNode tempTab = symTabStack.top;
    while (tempTab) {
        for (i = 0; i < HASHTAB_SIZE; i++) {
            pSymNode temp = tempTab->node[i];
            while (temp) {
                printSymNode(temp, 0);
                printf("\n");
                temp = temp->next;
            }
        }
        printf("\n");
        tempTab = tempTab->next;
    }
}

void printSymNode(pSymNode temp, int indent) {
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
                case ATTR_BOOL:
                    if (temp->v.b == true)
                        printf(" true");
                    else
                        printf(" false");
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
                printSymLink(temp->attr, temp->link, indent);
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
            printf(" %d ", temp->argc);
            printAttr(temp->attr);
            if (temp->next_link)
                temp = temp->next_link;
            indent++;
            while (temp) {
                printIndent(indent);
                printSymNode(temp, indent);
                temp = temp->next_link;
            }
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
                printSymLink(temp->attr, temp->link, indent);
            }
            break;
        }
        case TYPE_TYPE: {
            printf("TYPE ");
            printAttr(temp->attr);
            if (!isSimpleType(temp->attr)) {
                printSymLink(temp->attr, temp->link, indent);
            }
            break;
        }
        case TYPE_VARPARA: {
            printf("VAR_PARA ");
            printAttr(temp->attr);
            if (!isSimpleType(temp->attr)) {
                printSymLink(temp->attr, temp->link, indent);
            }
            break;
        }
        case TYPE_VALPARA: {
            printf("VAL_PARA ");
            printAttr(temp->attr);
            if (!isSimpleType(temp->attr)) {
                printSymLink(temp->attr, temp->link, indent);
            }
            break;
        }
        default: break;
    }
}

void printAttr(IDAttr attr) {
    switch (attr) {
        case ATTR_INTEGER: printf("integer"); break;
        case ATTR_REAL: printf("real"); break;
        case ATTR_CHAR: printf("char"); break;
        case ATTR_STRING: printf("string"); break;
        case ATTR_BOOL: printf("boolean"); break;
        case ATTR_ENUM: printf("enum"); break;
        case ATTR_SUBR: printf("subr"); break;
        case ATTR_ARRAY: printf("array"); break;
        case ATTR_RECORD: printf("record"); break;
    }
}

int isSimpleType(IDAttr attr) {
    if (attr == ATTR_INTEGER || attr == ATTR_REAL || attr == ATTR_CHAR || attr == ATTR_STRING || attr == ATTR_BOOL)
        return 1;
    else
        return 0;
}

void printSymLink(IDAttr attr, pTypeAttr link, int indent) {
    switch (attr) {
        case ATTR_ENUM: {
            pSymNode temp = link->first;
            indent++;
            while (temp) {
                printIndent(indent);
                printSymNode(temp, indent);
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
            printSymNode(link->first, indent);
            printSymNode(link->last, indent);
            break;
        }
        case ATTR_RECORD: {
            pSymNode temp = link->first;
            indent++;
            while (temp) {
                printIndent(indent);
                printSymNode(temp, indent);
                temp = temp->next_link;
            }
            break;
        }
        default: break;
    }
}

void printIndent(int indent) {
    if (indent)
        printf("\n");
    while (indent) {
        printf("--- ");
        indent--;
    }
}