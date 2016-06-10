#include "error.h"
#include <stdio.h>

int errorno = 0;

void parseError(ErrorType et, int no, char *name) {
    errorno++;
    fprintf(stderr, "Error at line %d:\n", no);

    switch (et) {
        case UNDECL_TYPE:
            fprintf(stderr, "\tUndeclared type name \"%s\"\n\n", name);
            break;
        case UNDECL_ID:
            fprintf(stderr, "\tUndeclared identifier \"%s\"\n\n", name);
            break;
//        case UNDECL_RECORD_ID:
//            fprintf(stderr, "\tUndeclared record identifier \"%s\"\n\n", name);
//            break;
        case DUPLICATE:
            fprintf(stderr, "\tDuplicate identifier \"%s\"\n\n", name);
            break;

        case SUBR_TYPE_ERROR:
            fprintf(stderr, "\tSubrange types error(only char, integer, boolean)\n\n");
            break;
        case SUBR_TYPE_NOT_MATCH:
            fprintf(stderr, "\tSubrange types don't match\n\n");
            break;
        case SUBR_OVER:
            fprintf(stderr, "\tSubrange over error \"High range limit < Low range limit\"\n\n");
            break;

        case ARRAY_INDEX_TYPE_NOT_MATCH:
            fprintf(stderr, "\tArray index types don't match\n\n");
            break;
        case ARRAY_TYPE_NOT_MATCH:
            fprintf(stderr, "\tArray elements' types don't match\n\n");
            break;

        case NOT_FUNC:
            fprintf(stderr, "\t\"%s\" is not function\n\n", name);
            break;
        case NOT_VAR:
            fprintf(stderr, "\t\"%s\" is not var\n\n", name);
            break;
        case NOT_RECORD:
            fprintf(stderr, "\t\"%s\" is not a record var\n\n", name);
            break;
        case NOT_RECORD_MEMBER:
            fprintf(stderr, "\t\"%s\" is not a record member\n\n", name);
            break;
        case NOT_CONST:
            fprintf(stderr, "\t\"%s\" is not const\n\n", name);
            break;

        case IS_TYPE:
            fprintf(stderr, "\t\"%s\" is a TYPE identifier\n\n", name);
            break;

        //stmt
        case IF_STMT_NOT_BOOL:
            fprintf(stderr, "\tIF-STMT condition is not boolean\n\n");
            break;
        case REPEAT_STMT_NOT_BOOL:
            fprintf(stderr, "\tREPEAT-STMT condition is not boolean\n\n");
            break;
        case WHILE_STMT_NOT_BOOL:
            fprintf(stderr, "\tWHILE-STMT condition is not boolean\n\n");
            break;
        case FOR_STMT_ERROR:
            fprintf(stderr, "\tFOR-STMT type error\n\n");
            break;
        case CASE_STMT_ERROR:
            fprintf(stderr, "\tCASE-STMT type error\n\n");
            break;
        case CASE_STMT_NOT_MATCH:
            fprintf(stderr, "\tCASE-STMT types don't match\n\n");
            break;

        case EXPR_TYPE_ERROR:
            fprintf(stderr, "\tExpression types don't match\n\n");
            break;

        case FUNC_ARGS_NOT_MATCH:
            fprintf(stderr, "\t\"%s\" wrong type\n\n", name);
            break;
        case FUNC_ARGS_NUM_NOT_MATCH:
            fprintf(stderr, "\twrong argc\n\n");
            break;
        case ASSIGN_TYPE_NOT_MATCH:
            fprintf(stderr, "\tAssign failed, type not match\n\n");
            break;
        default: break;
    }
}