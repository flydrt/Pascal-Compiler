%option caseless

%{
#include "tree.h"
#include "syntax.tab.h"
%}

digit [0-9]
real {digit}+\.{digit}+
number {digit}+
letter [a-zA-Z]
identifier {letter}+
newline \n
whitespace [ \t]+
char \'.\'
string \".*\"

sys_funct "abs"|"chr"|"odd"|"ord"|"pred"|"sqr"|"sqrt"|"succ"
sys_con "maxint"|"maxlongint"|"true"|"false"|"nil"
sys_type "shortint"|"smallint"|"longint"|"int64"|"integer"|"single"|"double"|"extended"|"comp"|"currency"|"real"|"ansichar"|"widechar"|"char"|"string"|"bytebool"|"wordbool"|"longbool"|"boolean"|"byte"|"word"|"dword"|"longword"|"cardinal"|"file"|"text"|"TDateTime"
sys_proc "write"|"writeln"

%%

{sys_funct} { return SYS_FUNCT; }
{sys_con} { return SYS_CON; }
{sys_type} {
    yylval = newTreeNode(tSYS_TYPE);
	(yylval->data).stringVal = copyString(yytext);
    return SYS_TYPE;
}
{sys_proc} { return SYS_PROC; }

"program"   {return PROGRAM;}
"if"        {return IF;}
"then"      {return THEN;}
"else"      {return ELSE;}
"repeat"    {return REPEAT;}
"until"     {return UNTIL;}
"while"     {return WHILE;}
"do"        {return DO;}
"case"      {return CASE;}
"to"        {return TO;}
"downto"    {return DOWNTO;}
"for"       {return FOR;}
"read"      {return READ;}

"["         {return LB;}
"]"         {return RB;}
";"         {return SEMI;}
".."        {return DOTDOT;}
"."         {return DOT;}
"("         {return LP;}
")"         {return RP;}
","         {return COMMA;}
":"         {return COLON;}

":="        {return ASSIGN;}
"="         {return EQUAL;}
"+"         {return PLUS;}
"-"         {return MINUS;}
"or"        {return OR;}
"<>"        {return UNEQUAL;}
">="        {return GE;}
">"         {return GT;}
"<="        {return LE;}
"<"         {return LT;}
"*"         {return MUL;}
"/"         {return DIV;}
"mod"       {return MOD;}
"and"       {return AND;}
"not"       {return NOT;}

"goto"      {return GOTO;}
"array"     {return ARRAY;}
"of"        {return OF;}
"record"    {return RECORD;}
"begin"     {return PBEGIN;}
"end"       {return END;}
"const"     {return CONST;}
"type"      {return TYPE;}
"var"       {return VAR;}
"function"  {return FUNCTION;}
"procedure" {return PROCEDURE;}

{number}    {
    yylval = newTreeNode(tINTEGER);
	(yylval->data).intVal = atoi(yytext);
    return INTEGER;
}
{real}      {
    yylval = newTreeNode(tREAL);
	(yylval->data).realVal = atof(yytext);
    return REAL;
}
{char}      {
    yylval = newTreeNode(tCHAR);
	(yylval->data).charVal = yytext[1];
    return CHAR;
}
{string}    {
    yylval = newTreeNode(tSTRING);
    char temp[255];
    strcpy(temp, yytext+1);
    temp[strlen(yytext) - 2] = '\0';
	(yylval->data).stringVal = copyString(temp);
    return STRING;
}

{identifier} {
	yylval = newTreeNode(tID);
	(yylval->data).stringVal = copyString(yytext);
	return ID;
}



{newline}   {/*lineno++;*/}
{whitespace}    {
/*
"write"     {return WRITE;}
"writeln"   {return WRITELN;}
"abs"       {return ABS;}
"chr"       {return CHR;}
"odd"       {return ODD;}
"ord"       {return ORD;}
"pred"      {return PRED;}
"sqr"       {return SQR;}
"sqrt"      {return SQRT;}
"succ"      {return SUCC;}
"integer"   {return INTEGER;}
"boolean"   {return BOOLEAN;}
"true"      {return TRUE;}
"false"     {return FALSE;}
"maxint"    {return MAXINT;}
*/
}
%%

int yywrap() {
	return 1;
}
