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
        case DUPLICATE:
            fprintf(stderr, "\tDuplicate identifier \"%s\"\n\n", name);
            break;
        case NOT_FUNC:
            fprintf(stderr, "\t\"%s\" is not function\n\n", name);
            break;
        case FUNC_ARGS_NOT_MATCH:
            fprintf(stderr, "\t\"%s\" wrong type\n\n", name);
            break;
        case FUNC_ARGS_NUM_NOT_MATCH:
            fprintf(stderr, "\t wrong argc\n\n");
            break;
        default: break;
    }
}