/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "syntax.y" /* yacc.c:1915  */

#include "tree.h"
#define YYSTYPE pTree

#line 49 "syntax.tab.h" /* yacc.c:1915  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DOT = 258,
    PROGRAM = 259,
    ID = 260,
    SEMI = 261,
    CONST = 262,
    EQUAL = 263,
    INTEGER = 264,
    REAL = 265,
    CHAR = 266,
    STRING = 267,
    SYS_CON = 268,
    TYPE = 269,
    ARRAY = 270,
    LB = 271,
    RB = 272,
    OF = 273,
    RECORD = 274,
    END = 275,
    COLON = 276,
    COMMA = 277,
    SYS_TYPE = 278,
    LP = 279,
    RP = 280,
    DOTDOT = 281,
    MINUS = 282,
    VAR = 283,
    FUNCTION = 284,
    PROCEDURE = 285,
    ASSIGN = 286,
    SYS_PROC = 287,
    READ = 288,
    PBEGIN = 289,
    IF = 290,
    THEN = 291,
    ELSE = 292,
    REPEAT = 293,
    UNTIL = 294,
    WHILE = 295,
    DO = 296,
    FOR = 297,
    TO = 298,
    DOWNTO = 299,
    CASE = 300,
    GOTO = 301,
    GE = 302,
    GT = 303,
    LE = 304,
    LT = 305,
    UNEQUAL = 306,
    PLUS = 307,
    OR = 308,
    MUL = 309,
    DIV = 310,
    RDIV = 311,
    MOD = 312,
    AND = 313,
    SYS_FUNCT = 314,
    NOT = 315
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */