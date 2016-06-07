#ifndef ERROR_H
#define ERROR_H

typedef enum errorType {
    UNDECL_TYPE, UNDECL_ID,
    DUPLICATE,
    NOT_FUNC,
    FUNC_ARGS_NOT_MATCH, FUNC_ARGS_NUM_NOT_MATCH
} ErrorType;

void parseError(ErrorType et, int no, char *name);

#endif
