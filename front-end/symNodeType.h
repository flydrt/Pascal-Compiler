#ifndef SYMNODETYPE_H
#define SYMNODETYPE_H

typedef enum idType {
    TYPE_UNKNOWN, TYPE_CONST, TYPE_VAR,
    TYPE_PROG, TYPE_PROC, TYPE_FUNC,
    TYPE_ENUM, TYPE_SUBR, TYPE_RECORD,
    TYPE_TYPE, TYPE_VALPARA, TYPE_VARPARA
} IDType;

typedef enum idAttr {
    ATTR_INTEGER, ATTR_REAL, ATTR_CHAR, ATTR_STRING, ATTR_BOOL,
    ATTR_ENUM, ATTR_SUBR,
    ATTR_ARRAY, ATTR_RECORD
} IDAttr;

#endif