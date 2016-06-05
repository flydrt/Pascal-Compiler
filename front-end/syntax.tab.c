/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 6 "syntax.y" /* yacc.c:339  */

#include <stdio.h>
#include "tree.h"
extern FILE * yyin;
static pTree root;

#line 73 "syntax.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "syntax.tab.h".  */
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
#line 1 "syntax.y" /* yacc.c:355  */

#include "tree.h"
#define YYSTYPE pTree

#line 108 "syntax.tab.c" /* yacc.c:355  */

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
    MOD = 311,
    AND = 312,
    SYS_FUNCT = 313,
    NOT = 314
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

/* Copy the second part of user declarations.  */

#line 191 "syntax.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   353

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  263

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    24,    24,    32,    37,    44,    51,    61,    64,    67,
      70,    82,    89,    90,    91,    92,    93,    96,    99,   102,
     109,   114,   121,   122,   123,   126,   133,   138,   141,   144,
     151,   154,   157,   158,   162,   166,   171,   177,   184,   191,
     194,   197,   200,   203,   210,   221,   232,   235,   238,   241,
     248,   256,   263,   270,   273,   276,   283,   288,   293,   300,
     303,   306,   309,   320,   323,   328,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   342,   347,   353,   361,   362,
     363,   364,   365,   368,   371,   379,   382,   385,   392,   399,
     406,   415,   422,   429,   434,   439,   446,   452,   455,   458,
     463,   468,   473,   478,   483,   488,   493,   498,   503,   508,
     513,   518,   523,   528,   533,   538,   539,   544,   545,   546,
     547,   548,   549,   550,   551,   554,   557
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DOT", "PROGRAM", "ID", "SEMI", "CONST",
  "EQUAL", "INTEGER", "REAL", "CHAR", "STRING", "SYS_CON", "TYPE", "ARRAY",
  "LB", "RB", "OF", "RECORD", "END", "COLON", "COMMA", "SYS_TYPE", "LP",
  "RP", "DOTDOT", "MINUS", "VAR", "FUNCTION", "PROCEDURE", "ASSIGN",
  "SYS_PROC", "READ", "PBEGIN", "IF", "THEN", "ELSE", "REPEAT", "UNTIL",
  "WHILE", "DO", "FOR", "TO", "DOWNTO", "CASE", "GOTO", "GE", "GT", "LE",
  "LT", "UNEQUAL", "PLUS", "OR", "MUL", "DIV", "MOD", "AND", "SYS_FUNCT",
  "NOT", "$accept", "program", "program_head", "routine", "sub_routine",
  "routine_head", "label_part", "const_part", "const_expr_list",
  "const_value", "type_part", "type_decl_list", "type_definition",
  "type_decl", "array_type_decl", "record_type_decl", "field_decl_list",
  "field_decl", "name_list", "simple_type_decl", "var_part",
  "var_decl_list", "var_decl", "routine_part", "function_decl",
  "function_head", "procedure_decl", "procedure_head", "parameters",
  "para_decl_list", "para_type_list", "var_para_list", "val_para_list",
  "routine_body", "stmt_list", "stmt", "non_label_stmt", "assign_stmt",
  "proc_stmt", "compound_stmt", "if_stmt", "else_clause", "repeat_stmt",
  "while_stmt", "for_stmt", "case_stmt", "case_expr_list", "case_expr",
  "goto_stmt", "expression_list", "expression", "expr", "term", "factor",
  "args_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF -171

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-171)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,    16,    23,  -171,    26,  -171,    83,    56,    55,  -171,
    -171,  -171,  -171,  -171,    89,   104,   198,   112,   118,   119,
     103,    10,   117,  -171,   115,   124,    37,  -171,    37,   137,
      37,   156,   160,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,   236,   164,   166,   119,  -171,   170,   -14,
     184,    37,    37,    37,   261,    37,    37,     6,  -171,  -171,
    -171,  -171,  -171,    37,    37,   167,    37,  -171,     4,    -8,
     102,  -171,   230,    85,   159,    64,  -171,  -171,   187,   236,
     299,  -171,  -171,    36,   170,  -171,   195,   196,   -14,  -171,
     202,  -171,   203,   171,   113,   176,     3,   176,  -171,    13,
     176,   185,   212,    37,    37,   120,  -171,    37,  -171,    37,
     245,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,   245,    37,   141,  -171,   213,   194,
     205,   170,  -171,   170,   236,   208,   216,  -171,  -171,  -171,
     299,   223,  -171,   217,   217,  -171,  -171,  -171,  -171,    37,
     206,    37,  -171,    37,  -171,  -171,  -171,   132,    41,  -171,
      63,    -8,   192,    -8,    -8,    -8,    -8,    -8,   102,   102,
     102,  -171,  -171,  -171,  -171,   176,  -171,    59,   221,   231,
     328,  -171,  -171,   248,   319,    60,  -171,    95,    67,   225,
     236,  -171,   254,  -171,    28,   240,  -171,   265,    56,   268,
     176,    37,   176,   176,  -171,  -171,  -171,   245,  -171,    37,
      37,   245,   245,  -171,  -171,  -171,   250,  -171,  -171,   299,
    -171,   246,  -171,  -171,   170,   259,    18,  -171,   263,   267,
     319,  -171,  -171,  -171,   176,  -171,   147,   165,   276,   280,
     271,   286,   236,  -171,   259,    28,  -171,   319,   319,  -171,
     245,   245,  -171,  -171,   299,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     7,     0,     1,     0,     0,     9,     3,
       2,    63,     4,    61,     0,    18,     0,     0,     8,     0,
      40,    78,     0,    83,    80,     0,     0,    63,     0,     0,
       0,     0,     0,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,     0,     0,     0,    17,    20,     0,    48,
       0,     0,     0,     0,     0,     0,     0,   115,    12,    13,
      14,    15,    16,     0,     0,   117,     0,   119,     0,   105,
     109,   114,     0,     0,     0,     0,    96,    62,     0,     0,
       0,    19,    31,     0,    39,    42,     0,     0,     6,    46,
       0,    47,     0,     0,     0,   126,     0,    75,    64,     0,
      98,     0,     0,     0,     0,     0,   122,     0,   121,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,    33,
       0,     0,    32,     0,     0,     0,     0,    23,    24,    22,
       0,     0,    41,    54,    54,    44,    45,     7,     7,     0,
       0,     0,    79,     0,    81,    82,   124,     0,     0,   120,
       0,   103,    86,    99,   100,   101,   102,   104,   107,   106,
     108,   110,   111,   112,   113,    87,    88,     0,     0,     0,
       0,    93,    10,     0,     0,     0,    28,     0,     0,     0,
       0,    21,     0,    30,     0,     0,    52,     0,     0,     0,
      77,     0,   125,    97,   123,   116,   118,     0,    84,     0,
       0,     0,     0,    91,    92,    38,     0,    26,    27,     0,
      34,     0,    35,    43,     0,    60,     0,    56,     0,     0,
       0,    49,     5,    51,    76,    85,     0,     0,     0,     0,
       0,     0,     0,    36,    59,     0,    53,     0,     0,    50,
       0,     0,    95,    94,     0,    29,    37,    55,    57,    58,
      89,    90,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -171,  -171,  -171,  -171,   149,   295,  -171,  -171,  -171,   -43,
    -171,  -171,   256,  -132,  -171,  -171,  -171,   128,  -126,  -170,
    -171,  -171,   232,  -171,   227,  -171,   229,  -171,   161,  -171,
      74,  -171,  -171,   122,   273,  -107,   281,  -171,  -171,    -6,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,   145,  -171,  -171,
     -24,   238,   -47,   -46,   -23
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,   197,   198,     8,    15,    18,    67,
      20,    46,    47,   136,   137,   138,   185,   186,    83,   139,
      49,    84,    85,    88,    89,    90,    91,    92,   195,   226,
     227,   228,   229,    12,    16,    32,    33,    34,    35,    36,
      37,   208,    38,    39,    40,    41,   180,   181,    42,    99,
      95,    69,    70,    71,    96
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      78,    13,    68,   162,    73,   187,    75,   188,   192,   102,
     101,     1,   109,    50,   216,    86,    87,   176,   106,   116,
     108,     4,   103,     5,   245,   151,    51,    94,   152,    97,
     104,   100,     9,    82,    52,   153,   128,   135,   154,   105,
     110,    53,    57,   246,   117,   118,    58,    59,    60,    61,
      62,   111,   112,   113,   114,   115,   224,   140,   141,   187,
     249,    63,    14,   151,    64,    82,   205,   109,   225,   168,
     169,   170,   109,   171,   172,   173,   174,   258,   259,   157,
     217,   158,   126,   179,   160,   151,    10,   241,   206,   141,
      11,   189,   220,   109,    17,    65,    66,   135,   244,   175,
     235,   177,   209,   210,   238,   239,   111,   112,   113,   114,
     115,   111,   112,   113,   114,   115,   219,   141,    19,   225,
      43,   109,   262,    44,    45,   200,   124,   202,   109,   203,
     150,    48,   111,   112,   113,   114,   115,   179,    54,    55,
     109,   135,    74,   260,   261,   159,   178,   222,    56,   204,
      58,    59,    60,    61,    62,   109,   119,   120,   121,   122,
     111,   112,   113,   114,   115,    76,    77,   111,   112,   113,
     114,   115,    79,   109,    80,    82,   135,   234,   243,   111,
     112,   113,   114,   115,   109,   236,   237,   135,   250,    93,
     125,   107,    13,   127,   111,   112,   113,   114,   115,   256,
     143,   144,   149,    21,   135,   135,   251,    22,   147,   148,
     155,   135,   111,   112,   113,   114,   115,   156,    23,   182,
     183,   184,   191,   111,   112,   113,   114,   115,   193,   207,
      24,    25,    11,    26,   190,    21,    27,   201,    28,    22,
      29,   194,   211,    30,    31,    58,    59,    60,    61,    62,
      21,   221,   212,   215,    22,    58,    59,    60,    61,    62,
     223,   230,    24,    25,    11,    26,    21,   240,    27,   123,
      28,   231,    29,   242,   233,    30,    31,    24,    25,    11,
      26,   141,   252,    27,   247,    28,   253,    29,   248,   254,
      30,    31,   255,    24,    25,    11,    26,   199,     7,    27,
      72,    28,    81,    29,   129,   196,    30,    31,    58,    59,
      60,    61,    62,   218,   130,   145,   142,   146,   131,   257,
     232,     0,   132,   133,   129,   214,   134,     0,    58,    59,
      60,    61,    62,   178,     0,    98,     0,    58,    59,    60,
      61,    62,   132,   133,     0,     0,   134,   161,   213,   163,
     164,   165,   166,   167
};

static const yytype_int16 yycheck[] =
{
      43,     7,    26,   110,    28,   131,    30,   133,   140,     3,
      56,     4,     8,     3,   184,    29,    30,   124,    64,    27,
      66,     5,    16,     0,     6,    22,    16,    51,    25,    53,
      24,    55,     6,     5,    24,    22,    79,    80,    25,    63,
      36,    31,     5,    25,    52,    53,     9,    10,    11,    12,
      13,    47,    48,    49,    50,    51,    28,    21,    22,   185,
     230,    24,     7,    22,    27,     5,    25,     8,   194,   116,
     117,   118,     8,   119,   120,   121,   122,   247,   248,   103,
      20,   104,    18,   126,   107,    22,     3,   219,    25,    22,
      34,   134,    25,     8,     5,    58,    59,   140,   224,   123,
     207,   125,    43,    44,   211,   212,    47,    48,    49,    50,
      51,    47,    48,    49,    50,    51,    21,    22,    14,   245,
       8,     8,   254,     5,     5,   149,    41,   151,     8,   153,
      17,    28,    47,    48,    49,    50,    51,   180,    21,    24,
       8,   184,     5,   250,   251,    25,     5,   190,    24,    17,
       9,    10,    11,    12,    13,     8,    54,    55,    56,    57,
      47,    48,    49,    50,    51,     9,     6,    47,    48,    49,
      50,    51,     8,     8,     8,     5,   219,   201,   221,    47,
      48,    49,    50,    51,     8,   209,   210,   230,    41,     5,
      31,    24,   198,     6,    47,    48,    49,    50,    51,   242,
       5,     5,    31,     5,   247,   248,    41,     9,     6,     6,
      25,   254,    47,    48,    49,    50,    51,     5,    20,     6,
      26,    16,     6,    47,    48,    49,    50,    51,     5,    37,
      32,    33,    34,    35,    26,     5,    38,    31,    40,     9,
      42,    24,    21,    45,    46,     9,    10,    11,    12,    13,
       5,    26,    21,     5,     9,     9,    10,    11,    12,    13,
       6,    21,    32,    33,    34,    35,     5,    17,    38,    39,
      40,     6,    42,    27,     6,    45,    46,    32,    33,    34,
      35,    22,     6,    38,    21,    40,     6,    42,    21,    18,
      45,    46,     6,    32,    33,    34,    35,   148,     3,    38,
      27,    40,    46,    42,     5,   144,    45,    46,     9,    10,
      11,    12,    13,   185,    15,    88,    84,    88,    19,   245,
     198,    -1,    23,    24,     5,   180,    27,    -1,     9,    10,
      11,    12,    13,     5,    -1,    54,    -1,     9,    10,    11,
      12,    13,    23,    24,    -1,    -1,    27,   109,    20,   111,
     112,   113,   114,   115
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    61,    62,     5,     0,    63,    65,    66,     6,
       3,    34,    93,    99,     7,    67,    94,     5,    68,    14,
      70,     5,     9,    20,    32,    33,    35,    38,    40,    42,
      45,    46,    95,    96,    97,    98,    99,   100,   102,   103,
     104,   105,   108,     8,     5,     5,    71,    72,    28,    80,
       3,    16,    24,    31,    21,    24,    24,     5,     9,    10,
      11,    12,    13,    24,    27,    58,    59,    69,   110,   111,
     112,   113,    94,   110,     5,   110,     9,     6,    69,     8,
       8,    72,     5,    78,    81,    82,    29,    30,    83,    84,
      85,    86,    87,     5,   110,   110,   114,   110,    96,   109,
     110,   113,     3,    16,    24,   110,   113,    24,   113,     8,
      36,    47,    48,    49,    50,    51,    27,    52,    53,    54,
      55,    56,    57,    39,    41,    31,    18,     6,    69,     5,
      15,    19,    23,    24,    27,    69,    73,    74,    75,    79,
      21,    22,    82,     5,     5,    84,    86,     6,     6,    31,
      17,    22,    25,    22,    25,    25,     5,   110,   114,    25,
     114,   111,    95,   111,   111,   111,   111,   111,   112,   112,
     112,   113,   113,   113,   113,   110,    95,   110,     5,    69,
     106,   107,     6,    26,    16,    76,    77,    78,    78,    69,
      26,     6,    73,     5,    24,    88,    88,    64,    65,    64,
     110,    31,   110,   110,    17,    25,    25,    37,   101,    43,
      44,    21,    21,    20,   107,     5,    79,    20,    77,    21,
      25,    26,    69,     6,    28,    78,    89,    90,    91,    92,
      21,     6,    93,     6,   110,    95,   110,   110,    95,    95,
      17,    73,    27,    69,    78,     6,    25,    21,    21,    79,
      41,    41,     6,     6,    18,     6,    69,    90,    79,    79,
      95,    95,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    63,    64,    65,    66,    67,    67,
      68,    68,    69,    69,    69,    69,    69,    70,    70,    71,
      71,    72,    73,    73,    73,    74,    75,    76,    76,    77,
      78,    78,    79,    79,    79,    79,    79,    79,    79,    80,
      80,    81,    81,    82,    83,    83,    83,    83,    83,    84,
      85,    86,    87,    88,    88,    89,    89,    90,    90,    91,
      92,    93,    94,    94,    95,    95,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    97,    97,    97,    98,    98,
      98,    98,    98,    99,   100,   101,   101,   102,   103,   104,
     104,   105,   106,   106,   107,   107,   108,   109,   109,   110,
     110,   110,   110,   110,   110,   110,   111,   111,   111,   111,
     112,   112,   112,   112,   112,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   114,   114
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     2,     5,     0,     2,     0,
       5,     4,     1,     1,     1,     1,     1,     2,     0,     2,
       1,     4,     1,     1,     1,     6,     3,     2,     1,     4,
       3,     1,     1,     1,     3,     3,     4,     5,     3,     2,
       0,     2,     1,     4,     2,     2,     1,     1,     0,     4,
       5,     4,     3,     3,     0,     3,     1,     3,     3,     2,
       1,     1,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     6,     5,     1,     4,
       1,     4,     4,     3,     5,     2,     0,     4,     4,     8,
       8,     5,     2,     1,     4,     4,     2,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     1,     4,     1,     4,     1,
       3,     2,     2,     4,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 24 "syntax.y" /* yacc.c:1661  */
    {
			(yyval) = newTreeNode(tPROGRAM);
			(yyval)->child[1] = (yyvsp[-2]);
			(yyval)->child[2] = (yyvsp[-1]);
            root = (yyval);
		}
#line 1484 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 3:
#line 32 "syntax.y" /* yacc.c:1661  */
    {
				(yyval) = (yyvsp[-1]);
			 }
#line 1492 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 4:
#line 37 "syntax.y" /* yacc.c:1661  */
    {
			(yyval) = newTreeNode(tROUTINE);
			(yyval)->child[1] = (yyvsp[-1]);
			(yyval)->child[2] = (yyvsp[0]);
		}
#line 1502 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 44 "syntax.y" /* yacc.c:1661  */
    {
				(yyval) = newTreeNode(tSUB_ROUTINE);
				(yyval)->child[1] = (yyvsp[-1]);
				(yyval)->child[2] = (yyvsp[0]);
			}
#line 1512 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 51 "syntax.y" /* yacc.c:1661  */
    {
			 	(yyval) = newTreeNode(tROUTINE_HEAD);
				(yyval)->child[0] = (yyvsp[-4]);
				(yyval)->child[1] = (yyvsp[-3]);
				(yyval)->child[2] = (yyvsp[-2]);
				(yyval)->child[3] = (yyvsp[-1]);
				(yyval)->child[4] = (yyvsp[0]);
			 }
#line 1525 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 61 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 1531 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 64 "syntax.y" /* yacc.c:1661  */
    {
		       (yyval) = (yyvsp[0]);
		   }
#line 1539 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 67 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 1545 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 70 "syntax.y" /* yacc.c:1661  */
    {
					pTree temp = newTreeNode(CONST_DECL);
					temp->child[1] = (yyvsp[-3]);
					temp->child[2] = (yyvsp[-1]);
					
					pTree p = (yyvsp[-4]);
					while(p->child[0])
						p = p->child[0];
					p->child[0] = temp;

					(yyval) = (yyvsp[-4]);
				}
#line 1562 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 82 "syntax.y" /* yacc.c:1661  */
    {
					(yyval) = newTreeNode(CONST_DECL);
					(yyval)->child[1] = (yyvsp[-3]);
					(yyval)->child[2] = (yyvsp[-1]);
				}
#line 1572 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 89 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1578 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 90 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1584 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 91 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1590 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 92 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1596 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 93 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1602 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 96 "syntax.y" /* yacc.c:1661  */
    {
		      (yyval) = (yyvsp[0]);
		  }
#line 1610 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 99 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 1616 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 102 "syntax.y" /* yacc.c:1661  */
    {
			       pTree p = (yyvsp[-1]);
				   while(p->child[0])
				       p = p->child[0];
				   p->child[0] = (yyvsp[0]);
				   (yyval) = (yyvsp[-1]);
			   }
#line 1628 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 109 "syntax.y" /* yacc.c:1661  */
    {
			       (yyval) = (yyvsp[0]);
			   }
#line 1636 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 114 "syntax.y" /* yacc.c:1661  */
    {
					(yyval) = newTreeNode(TYPE_DECL);
					(yyval)->child[1] = (yyvsp[-3]);
					(yyval)->child[2] = (yyvsp[-1]);
				}
#line 1646 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 121 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1652 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 122 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1658 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 123 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1664 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 126 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = newTreeNode(ARRAY_DECL);
                    (yyval)->child[1] = (yyvsp[-3]);
                    (yyval)->child[2] = (yyvsp[0]);
                }
#line 1674 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 133 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = (yyvsp[-1]);
                 }
#line 1682 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 138 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = createList((yyvsp[-1]), (yyvsp[0]));
                }
#line 1690 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 141 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1696 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 144 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(FIELD_DECL);
               (yyval)->child[1] = (yyvsp[-3]);
               (yyval)->child[2] = (yyvsp[-1]);
           }
#line 1706 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 151 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = createList((yyvsp[-2]), (yyvsp[0]));
          }
#line 1714 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 154 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1720 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 157 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1726 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 158 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = (yyvsp[0]);
                    (yyval)->type = tSIMPLE_ID;
                 }
#line 1735 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 162 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = newTreeNode(tSIMPLE_ENUM);
                    (yyval)->child[1] = (yyvsp[-1]);
                 }
#line 1744 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 166 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = newTreeNode(tSIMPLE_SUBRANGE);
                    (yyval)->child[1] = (yyvsp[-2]);
                    (yyval)->child[2] = (yyvsp[0]);
                 }
#line 1754 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 171 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = newTreeNode(tSIMPLE_SUBRANGE);
                    (yyval)->child[1] = (yyvsp[-2]);
                    ((yyval)->child[1]->data).intVal *= -1;
                    (yyval)->child[2] = (yyvsp[0]);
                 }
#line 1765 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 177 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) =newTreeNode(tSIMPLE_SUBRANGE);
                    (yyval)->child[1] = (yyvsp[-3]);
                    ((yyval)->child[1]->data).intVal *= -1;
                    (yyval)->child[2] = (yyvsp[0]);
                    ((yyval)->child[2]->data).intVal *= -1;
                 }
#line 1777 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 184 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) =newTreeNode(tSIMPLE_SUBRANGE_ID);
                    (yyval)->child[1] = (yyvsp[-2]);
                    (yyval)->child[2] = (yyvsp[0]);
                 }
#line 1787 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 191 "syntax.y" /* yacc.c:1661  */
    {
             (yyval) = (yyvsp[0]);
         }
#line 1795 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 194 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 1801 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 197 "syntax.y" /* yacc.c:1661  */
    {
                  (yyval) = createList((yyvsp[-1]), (yyvsp[0]));
              }
#line 1809 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 200 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1815 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 203 "syntax.y" /* yacc.c:1661  */
    {
            (yyval) = newTreeNode(VAR_DECL);
            (yyval)->child[1] = (yyvsp[-3]);
            (yyval)->child[2] = (yyvsp[-1]);
         }
#line 1825 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 210 "syntax.y" /* yacc.c:1661  */
    {
                pTree p = (yyvsp[-1]);
                if(p) {
                    while(p->child[0])
                        p = p->child[0];
                    p->child[0] = (yyvsp[0]);
                    (yyval) = (yyvsp[-1]);
                }
                else
                    (yyval) = (yyvsp[0]);
			 }
#line 1841 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 221 "syntax.y" /* yacc.c:1661  */
    {
                pTree p = (yyvsp[-1]);
                if(p) {
                    while(p->child[0])
                        p = p->child[0];
                    p->child[0] = (yyvsp[0]);
                    (yyval) = (yyvsp[-1]);
                }
                else
                    (yyval) = (yyvsp[0]);
             }
#line 1857 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 232 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = (yyvsp[0]);
             }
#line 1865 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 235 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = (yyvsp[0]);
             }
#line 1873 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 238 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 1879 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 241 "syntax.y" /* yacc.c:1661  */
    {
                  (yyval) = newTreeNode(FUNCTION_DECL);
                  (yyval)->child[1] = (yyvsp[-3]);
                  (yyval)->child[2] = (yyvsp[-1]);
              }
#line 1889 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 248 "syntax.y" /* yacc.c:1661  */
    {
                  (yyval) = newTreeNode(FUNCTION_HEAD);
                  (yyval)->child[1] = (yyvsp[-3]);
                  (yyval)->child[2] = (yyvsp[-2]);
                  (yyval)->child[3] = (yyvsp[0]);
              }
#line 1900 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 256 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = newTreeNode(PROCEDURE_DECL);
                   (yyval)->child[1] = (yyvsp[-3]);
                   (yyval)->child[2] = (yyvsp[-1]);
               }
#line 1910 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 263 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = newTreeNode(PROCEDURE_HEAD);
                   (yyval)->child[1] = (yyvsp[-1]);
                   (yyval)->child[2] = (yyvsp[0]);
               }
#line 1920 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 270 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = (yyvsp[-1]);
           }
#line 1928 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 273 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 1934 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 276 "syntax.y" /* yacc.c:1661  */
    {
                   pTree p = (yyvsp[-2]);
                   while(p->child[0])
                       p = p->child[0];
                   p->child[0] = (yyvsp[0]);
                   (yyval) = (yyvsp[-2]);
               }
#line 1946 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 283 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = (yyvsp[0]);
               }
#line 1954 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 288 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = newTreeNode(VAR_PARA);
                   (yyval)->child[1] = (yyvsp[-2]);
                   (yyval)->child[2] = (yyvsp[0]);
               }
#line 1964 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 293 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = newTreeNode(VAL_PARA);
                   (yyval)->child[1] = (yyvsp[-2]);
                   (yyval)->child[2] = (yyvsp[0]);
               }
#line 1974 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 300 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1980 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 303 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1986 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 306 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1992 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 309 "syntax.y" /* yacc.c:1661  */
    {
              pTree p = (yyvsp[-2]);
              if(p) {
                  while(p->child[0])
                      p = p->child[0];
                  p->child[0] = (yyvsp[-1]);
                  (yyval) = (yyvsp[-2]);
              }
              else
                  (yyval) = (yyvsp[-1]);
          }
#line 2008 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 320 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 2014 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 323 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(LABEL_STMT);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2024 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 328 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2030 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 331 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2036 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 332 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2042 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 333 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2048 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 334 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2054 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 335 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2060 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 336 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2066 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 337 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2072 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 338 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2078 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 339 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2084 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 342 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = newTreeNode(ASSIGN_STMT_1);
                (yyval)->child[1] = (yyvsp[-2]);
                (yyval)->child[2] = (yyvsp[0]);
            }
#line 2094 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 347 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = newTreeNode(ASSIGN_STMT_2);
                (yyval)->child[1] = (yyvsp[-5]);
                (yyval)->child[2] = (yyvsp[-3]);
                (yyval)->child[3] = (yyvsp[0]);
            }
#line 2105 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 353 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = newTreeNode(ASSIGN_STMT_3);
                (yyval)->child[1] = (yyvsp[-4]);
                (yyval)->child[2] = (yyvsp[-2]);
                (yyval)->child[3] = (yyvsp[0]);
            }
#line 2116 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 368 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); }
#line 2122 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 371 "syntax.y" /* yacc.c:1661  */
    {
            (yyval) = newTreeNode(IF_STMT);
            (yyval)->child[1] = (yyvsp[-3]);
            (yyval)->child[2] = (yyvsp[-1]);
            (yyval)->child[3] = (yyvsp[0]);
        }
#line 2133 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 379 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = (yyvsp[0]);
            }
#line 2141 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 382 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 2147 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 385 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = newTreeNode(REPEAT_STMT);
                (yyval)->child[1] = (yyvsp[-2]);
                (yyval)->child[2] = (yyvsp[0]);
            }
#line 2157 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 392 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(WHILE_STMT);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2167 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 399 "syntax.y" /* yacc.c:1661  */
    {
            (yyval) = newTreeNode(FOR_STMT_TO);
            (yyval)->child[1] = (yyvsp[-6]);
            (yyval)->child[2] = (yyvsp[-4]);
            (yyval)->child[3] = (yyvsp[-2]);
            (yyval)->child[4] = (yyvsp[0]);
         }
#line 2179 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 406 "syntax.y" /* yacc.c:1661  */
    {
            (yyval) = newTreeNode(FOR_STMT_DOWNTO);
            (yyval)->child[1] = (yyvsp[-6]);
            (yyval)->child[2] = (yyvsp[-4]);
            (yyval)->child[3] = (yyvsp[-2]);
            (yyval)->child[4] = (yyvsp[0]);
         }
#line 2191 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 415 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(CASE_STMT);
              (yyval)->child[1] = (yyvsp[-3]);
              (yyval)->child[2] = (yyvsp[-1]);
          }
#line 2201 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 422 "syntax.y" /* yacc.c:1661  */
    {
                   pTree p = (yyvsp[-1]);
                   while(p->child[0])
                       p = p->child[0];
                   p->child[0] = (yyvsp[0]);
                   (yyval) = (yyvsp[-1]);
               }
#line 2213 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 429 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = (yyvsp[0]);
               }
#line 2221 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 434 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(CASE_EXPR_CONST);
              (yyval)->child[1] = (yyvsp[-3]);
              (yyval)->child[2] = (yyvsp[-1]);
          }
#line 2231 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 439 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(CASE_EXPR_ID);
              (yyval)->child[1] = (yyvsp[-3]);
              (yyval)->child[2] = (yyvsp[-1]);
          }
#line 2241 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 446 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(GOTO_STMT);
              (yyval)->child[1] = (yyvsp[0]);
          }
#line 2250 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 452 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = createList((yyvsp[-2]), (yyvsp[0]));
                }
#line 2258 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 455 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2264 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 458 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(eGE);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2274 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 463 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(eGT);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2284 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 468 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(eLE);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2294 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 473 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(eLT);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2304 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 478 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(eEQUAL);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2314 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 483 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(eUNEQUAL);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2324 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 488 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = (yyvsp[0]);
           }
#line 2332 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 493 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(ePLUS);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2342 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 498 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(eMINUS);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2352 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 503 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(eOR);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2362 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 508 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = (yyvsp[0]);
     }
#line 2370 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 110:
#line 513 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(eMUL);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2380 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 111:
#line 518 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(eDIV);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2390 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 523 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(eMOD);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2400 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 113:
#line 528 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(eAND);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2410 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 114:
#line 533 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = (yyvsp[0]);
     }
#line 2418 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 115:
#line 538 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2424 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 116:
#line 539 "syntax.y" /* yacc.c:1661  */
    {
           (yyval) = newTreeNode(FACTOR_FUNC);
           (yyval)->child[1] = (yyvsp[-3]);
           (yyval)->child[2] = (yyvsp[-1]);
       }
#line 2434 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 125:
#line 554 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = createList((yyvsp[-2]), (yyvsp[0]));
          }
#line 2442 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 126:
#line 557 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2448 "syntax.tab.c" /* yacc.c:1661  */
    break;


#line 2452 "syntax.tab.c" /* yacc.c:1661  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 560 "syntax.y" /* yacc.c:1906  */


/*
int main() {
	char FILENAME[100];
    printf("Please input the test file: ");
    scanf("%s", FILENAME);
    FILE* file = fopen(FILENAME, "r");
    yyin = file;

	yyparse();

    return 0;
}
*/

pTree parse() {
    FILE* file = fopen("txt", "r");
    yyin = file;
    
    yyparse();

    return root;
}

int yyerror(char* s) {
	fprintf(stderr, "%s\n", s);
}
