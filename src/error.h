#ifndef ERROR_H
#define ERROR_H

typedef enum errorType {
    UNDECL_TYPE, UNDECL_ID,
    DUPLICATE,
    SUBR_TYPE_ERROR, SUBR_TYPE_NOT_MATCH, SUBR_OVER,
    ARRAY_INDEX_TYPE_NOT_MATCH, ARRAY_TYPE_NOT_MATCH,

    //not something
    NOT_FUNC, NOT_VAR, NOT_RECORD, NOT_RECORD_MEMBER,
    NOT_CONST,

    //is something
    IS_TYPE,

    //stmt
    IF_STMT_NOT_BOOL, REPEAT_STMT_NOT_BOOL, WHILE_STMT_NOT_BOOL,
    FOR_STMT_ERROR, CASE_STMT_ERROR, CASE_STMT_NOT_MATCH,

    //expression
    EXPR_TYPE_ERROR,

    FUNC_ARGS_NOT_MATCH, FUNC_ARGS_NUM_NOT_MATCH,
    ASSIGN_TYPE_NOT_MATCH
} ErrorType;

void parseError(ErrorType et, int no, char *name);

#endif
