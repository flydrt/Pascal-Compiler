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
#line 1 "syntax.y" /* yacc.c:339  */

#include <stdio.h>
#include "tree.h"
extern FILE * yyin;
static pTree root;
extern int yylineno;
extern int errorno;

#line 75 "syntax.tab.c" /* yacc.c:339  */

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
#line 10 "syntax.y" /* yacc.c:355  */

#include "tree.h"
#define YYSTYPE pTree

#line 110 "syntax.tab.c" /* yacc.c:355  */

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

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 208 "syntax.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   456

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  171
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  338

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    28,    28,    34,    42,    45,    50,    57,    64,    74,
      77,    80,    83,    95,   100,   112,   119,   120,   121,   122,
     123,   126,   129,   132,   139,   144,   149,   156,   157,   158,
     161,   166,   171,   178,   181,   186,   189,   192,   197,   202,
     209,   212,   215,   216,   220,   224,   229,   235,   242,   249,
     252,   255,   258,   261,   266,   271,   278,   289,   300,   303,
     306,   309,   314,   319,   326,   332,   340,   345,   350,   357,
     364,   367,   368,   373,   380,   383,   392,   397,   402,   407,
     414,   417,   420,   423,   434,   435,   448,   453,   454,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   472,   477,
     483,   489,   495,   501,   507,   514,   518,   523,   524,   529,
     533,   538,   543,   549,   550,   553,   561,   564,   567,   572,
     579,   584,   591,   598,   605,   614,   619,   624,   631,   638,
     643,   648,   653,   658,   665,   669,   675,   678,   679,   684,
     689,   694,   699,   704,   709,   714,   719,   724,   729,   734,
     739,   744,   749,   754,   759,   764,   769,   773,   778,   779,
     784,   788,   789,   793,   797,   802,   807,   812,   817,   818,
     825,   828
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
  "LT", "UNEQUAL", "PLUS", "OR", "MUL", "DIV", "RDIV", "MOD", "AND",
  "SYS_FUNCT", "NOT", "$accept", "program", "program_head", "routine",
  "sub_routine", "routine_head", "label_part", "const_part",
  "const_expr_list", "const_value", "type_part", "type_decl_list",
  "type_definition", "type_decl", "array_type_decl", "record_type_decl",
  "field_decl_list", "field_decl", "name_list", "simple_type_decl",
  "var_part", "var_decl_list", "var_decl", "routine_part", "function_decl",
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315
};
# endif

#define YYPACT_NINF -209

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-209)))

#define YYTABLE_NINF -106

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,    34,    62,  -209,    90,  -209,    50,    45,    81,  -209,
    -209,  -209,  -209,  -209,  -209,  -209,   110,   105,   244,   121,
     133,   183,   181,  -209,   337,    68,  -209,   199,   247,    63,
    -209,    63,   276,    63,    29,   165,  -209,  -209,  -209,  -209,
    -209,  -209,  -209,  -209,  -209,  -209,   438,   162,   310,   183,
    -209,   321,   185,    63,   334,    63,    63,    63,   331,   331,
      63,    63,   204,  -209,  -209,  -209,  -209,  -209,    63,    63,
     317,    63,  -209,   208,   -17,   398,  -209,   282,     7,     1,
      77,  -209,  -209,  -209,  -209,   207,   438,   370,  -209,  -209,
      96,   321,  -209,   339,   340,   185,  -209,   216,  -209,   228,
     155,    13,   136,   155,    25,   155,  -209,  -209,    91,   155,
      18,   345,    63,    63,   131,  -209,    63,  -209,    63,   314,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,   314,   314,    63,    63,   426,
     426,  -209,  -209,   266,   226,   335,   321,  -209,   321,   438,
     329,   279,  -209,  -209,  -209,   370,   370,   352,  -209,   338,
     338,  -209,  -209,  -209,  -209,  -209,  -209,    63,    63,   327,
      15,  -209,    63,  -209,    63,    63,  -209,  -209,  -209,  -209,
     142,   130,  -209,  -209,   132,   -17,   330,   -17,   -17,   -17,
     -17,   -17,   398,   398,   398,  -209,  -209,  -209,  -209,  -209,
     155,   155,  -209,  -209,   150,    16,   349,   351,   414,  -209,
     230,  -209,  -209,   373,   390,   246,  -209,   139,    80,   358,
     438,  -209,  -209,   384,   287,  -209,    17,   113,  -209,   385,
      45,   293,   386,   294,   155,   155,    63,    63,    63,   155,
     155,   155,  -209,  -209,  -209,  -209,  -209,  -209,   314,  -209,
      63,    63,    63,   314,   314,  -209,  -209,  -209,  -209,  -209,
      60,  -209,  -209,  -209,   370,   370,  -209,   395,  -209,  -209,
    -209,  -209,   321,   374,    27,  -209,   144,   146,   390,   390,
    -209,  -209,  -209,  -209,  -209,  -209,  -209,   155,   155,   155,
    -209,   257,   262,   284,   295,   296,   380,    19,   403,   336,
     438,  -209,   374,    17,    17,  -209,   390,   390,   390,   390,
    -209,  -209,   314,   314,   314,  -209,  -209,  -209,  -209,   370,
     370,   370,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,
    -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     9,     0,     1,     0,     0,    11,     5,
       4,     3,     2,    84,     6,    82,     0,    22,     0,     0,
      10,     0,    50,   114,     0,     0,   113,   107,     0,     0,
      84,     0,     0,     0,     0,     0,    87,    89,    90,    91,
      92,    93,    94,    95,    96,    97,     0,     0,     0,    21,
      24,     0,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,    16,    17,    18,    19,    20,     0,     0,
     158,     0,   160,     0,   145,   149,   155,     0,     0,     0,
       0,   135,   134,    85,    83,     0,     0,     0,    23,    41,
       0,    49,    52,     0,     0,     8,    58,     0,    59,     0,
     104,     0,     0,   171,     0,    98,    88,    86,     0,   137,
       0,     0,     0,     0,     0,   163,     0,   162,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    13,     0,    43,     0,     0,    42,     0,     0,
       0,     0,    28,    29,    27,     0,     0,     0,    51,    71,
      71,    56,    57,     9,     9,     9,     9,     0,     0,     0,
       0,   110,     0,   106,   111,     0,   108,   112,   109,   165,
       0,     0,   168,   161,     0,   143,   117,   139,   140,   141,
     142,   144,   147,   146,   148,   150,   152,   151,   153,   154,
     119,   118,   121,   120,     0,     0,     0,     0,     0,   129,
       0,    14,    12,     0,     0,     0,    36,     0,     0,     0,
       0,    26,    25,     0,     0,    40,     0,     0,    69,     0,
       0,     0,     0,     0,   103,   100,     0,     0,     0,   170,
     138,   136,   169,   164,   166,   157,   167,   159,     0,   115,
       0,     0,     0,     0,     0,   127,   128,   126,   125,    48,
       0,    34,    33,    35,     0,     0,    44,     0,    45,    55,
      54,    53,     0,    81,     0,    74,     0,     0,     0,     0,
      62,     7,    63,    61,    67,    68,    66,   101,   102,    99,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,    80,    72,     0,    70,     0,     0,     0,     0,
      65,    64,     0,     0,     0,   133,   131,   132,   130,     0,
       0,     0,    39,    38,    37,    47,    75,    73,    78,    76,
      79,    77,   124,   122,   123,    32,    31,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -209,  -209,  -209,  -209,    72,   407,  -209,  -209,  -209,   -46,
    -209,  -209,   362,  -144,  -209,  -209,  -209,   197,   -42,  -208,
    -209,  -209,   324,  -209,   323,  -209,   325,  -209,   256,  -209,
     -35,  -209,  -209,   191,   399,  -118,   271,  -209,  -209,    -3,
    -209,  -209,  -209,  -209,  -209,  -209,   288,    38,  -209,  -209,
     -26,   322,   261,   -48,    56
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,   229,   230,     8,    17,    20,    72,
      22,    49,    50,   151,   152,   153,   215,   216,   273,   154,
      52,    91,    92,    95,    96,    97,    98,    99,   227,   274,
     275,   276,   277,    14,    18,    35,    36,    37,    38,    39,
      40,   249,    41,    42,    43,    44,   208,   209,    45,   108,
     103,    74,    75,    76,   104
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      85,   186,   137,    73,    15,    78,   260,    80,   135,    90,
     125,   223,   224,   110,   167,   118,   237,   202,   203,   177,
     320,   115,    89,   117,   118,     1,   171,   100,   303,   102,
      81,   105,   138,   304,   109,   126,   127,   321,    82,     4,
     143,   150,   114,   178,   168,   272,   238,   172,   136,    90,
     173,    11,   305,    12,   120,   121,   122,   123,   124,   251,
     252,   296,     5,   120,   121,   122,   123,   124,    62,    58,
     310,   311,    63,    64,    65,    66,    67,   297,   139,    13,
     195,   196,   197,   198,   199,   118,   180,    68,    16,    59,
      69,     9,   174,   207,   207,   140,    10,   155,   328,   329,
     330,   331,   157,   219,   217,   266,   218,   200,   201,   150,
     150,   204,   205,   175,   278,    19,   176,   156,   157,    21,
     298,   299,    70,    71,   120,   121,   122,   123,   124,    46,
     290,   244,   182,   246,   279,   294,   295,   169,    47,   118,
     264,   234,   235,   242,   118,   306,   239,   308,   240,   241,
     118,   250,   172,   170,   172,   245,   183,   247,   118,   243,
     265,   157,   207,   118,   207,   307,    83,   309,   150,   181,
      86,    84,   184,   217,   268,   335,   336,   337,   120,   121,
     122,   123,   124,   120,   121,   122,   123,   124,    48,   120,
     121,   122,   123,   124,   332,   333,   334,   120,   121,   122,
     123,   124,   120,   121,   122,   123,   124,   111,   141,    51,
     287,   288,   289,   142,    93,    94,   118,   163,   150,   150,
     112,   301,   164,    60,   291,   292,   293,    15,   113,   165,
     302,   257,   150,   150,   166,   206,   231,   232,   233,    63,
      64,    65,    66,    67,   119,    23,   256,   261,   256,    24,
     258,    89,   213,    25,   325,   120,   121,   122,   123,   124,
     150,   150,   150,   150,    26,   118,   262,   211,   326,   327,
     118,    61,   212,   150,   150,   150,    27,    28,    13,    29,
     221,    79,    30,   133,    31,   222,    32,    24,   270,    33,
      34,    25,   118,   271,   282,   285,   315,   317,   312,   283,
     286,   316,   318,   313,   120,   121,   122,   123,   124,   120,
     121,   122,   123,   124,    27,    28,    13,    29,    87,    24,
      30,   134,    31,    25,    32,   314,    89,    33,    34,   106,
     107,   120,   121,   122,   123,   124,    24,   323,    53,   101,
      54,   116,   324,  -105,   159,   160,    27,    28,    13,    29,
     179,   214,    30,    55,    31,   220,    32,   225,   236,    33,
      34,    56,   226,    27,    28,    13,    29,   248,    57,    30,
     253,    31,   254,    32,  -105,   144,    33,    34,   259,    63,
      64,    65,    66,    67,   267,   145,   192,   193,   194,   146,
     269,   280,   284,   147,   148,   144,   157,   149,   319,    63,
      64,    65,    66,    67,    63,    64,    65,    66,    67,   322,
       7,    88,   263,   147,   148,   158,   228,   149,   161,   206,
     162,   281,   300,    63,    64,    65,    66,    67,   210,    77,
       0,   206,     0,     0,   255,    63,    64,    65,    66,    67,
     185,     0,   187,   188,   189,   190,   191,    63,    64,    65,
      66,    67,   128,   129,   130,   131,   132
};

static const yytype_int16 yycheck[] =
{
      46,   119,     1,    29,     7,    31,   214,    33,     1,    51,
      27,   155,   156,    61,     1,     8,     1,   135,   136,     1,
       1,    69,     5,    71,     8,     4,     1,    53,     1,    55,
       1,    57,    31,     6,    60,    52,    53,    18,     9,     5,
      86,    87,    68,    25,    31,    28,    31,    22,    41,    91,
      25,     1,    25,     3,    47,    48,    49,    50,    51,    43,
      44,     1,     0,    47,    48,    49,    50,    51,     5,     1,
     278,   279,     9,    10,    11,    12,    13,    17,     1,    34,
     128,   129,   130,   131,   132,     8,   112,    24,     7,    21,
      27,     1,     1,   139,   140,    18,     6,     1,   306,   307,
     308,   309,    22,   149,   146,    25,   148,   133,   134,   155,
     156,   137,   138,    22,     1,     5,    25,    21,    22,    14,
     264,   265,    59,    60,    47,    48,    49,    50,    51,     8,
     248,     1,     1,     1,    21,   253,   254,     1,     5,     8,
       1,   167,   168,     1,     8,     1,   172,     1,   174,   175,
       8,     1,    22,    17,    22,    25,    25,    25,     8,    17,
      21,    22,   208,     8,   210,    21,     1,    21,   214,   113,
       8,     6,   116,   215,   220,   319,   320,   321,    47,    48,
      49,    50,    51,    47,    48,    49,    50,    51,     5,    47,
      48,    49,    50,    51,   312,   313,   314,    47,    48,    49,
      50,    51,    47,    48,    49,    50,    51,     3,     1,    28,
     236,   237,   238,     6,    29,    30,     8,     1,   264,   265,
      16,   267,     6,    24,   250,   251,   252,   230,    24,     1,
     272,     1,   278,   279,     6,     5,   164,   165,   166,     9,
      10,    11,    12,    13,    36,     1,   208,     1,   210,     5,
      20,     5,    26,     9,   300,    47,    48,    49,    50,    51,
     306,   307,   308,   309,    20,     8,    20,     1,   303,   304,
       8,    24,     6,   319,   320,   321,    32,    33,    34,    35,
       1,     5,    38,     1,    40,     6,    42,     5,     1,    45,
      46,     9,     8,     6,     1,     1,     1,     1,    41,     6,
       6,     6,     6,    41,    47,    48,    49,    50,    51,    47,
      48,    49,    50,    51,    32,    33,    34,    35,     8,     5,
      38,    39,    40,     9,    42,    41,     5,    45,    46,    58,
      59,    47,    48,    49,    50,    51,     5,     1,     1,     5,
       3,    24,     6,     6,     5,     5,    32,    33,    34,    35,
       5,    16,    38,    16,    40,    26,    42,     5,    31,    45,
      46,    24,    24,    32,    33,    34,    35,    37,    31,    38,
      21,    40,    21,    42,    37,     5,    45,    46,     5,     9,
      10,    11,    12,    13,    26,    15,   125,   126,   127,    19,
       6,     6,     6,    23,    24,     5,    22,    27,    18,     9,
      10,    11,    12,    13,     9,    10,    11,    12,    13,     6,
       3,    49,   215,    23,    24,    91,   160,    27,    95,     5,
      95,   230,    27,     9,    10,    11,    12,    13,   140,    30,
      -1,     5,    -1,    -1,    20,     9,    10,    11,    12,    13,
     118,    -1,   120,   121,   122,   123,   124,     9,    10,    11,
      12,    13,    54,    55,    56,    57,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    62,    63,     5,     0,    64,    66,    67,     1,
       6,     1,     3,    34,    94,   100,     7,    68,    95,     5,
      69,    14,    71,     1,     5,     9,    20,    32,    33,    35,
      38,    40,    42,    45,    46,    96,    97,    98,    99,   100,
     101,   103,   104,   105,   106,   109,     8,     5,     5,    72,
      73,    28,    81,     1,     3,    16,    24,    31,     1,    21,
      24,    24,     5,     9,    10,    11,    12,    13,    24,    27,
      59,    60,    70,   111,   112,   113,   114,    95,   111,     5,
     111,     1,     9,     1,     6,    70,     8,     8,    73,     5,
      79,    82,    83,    29,    30,    84,    85,    86,    87,    88,
     111,     5,   111,   111,   115,   111,    97,    97,   110,   111,
     114,     3,    16,    24,   111,   114,    24,   114,     8,    36,
      47,    48,    49,    50,    51,    27,    52,    53,    54,    55,
      56,    57,    58,     1,    39,     1,    41,     1,    31,     1,
      18,     1,     6,    70,     5,    15,    19,    23,    24,    27,
      70,    74,    75,    76,    80,     1,    21,    22,    83,     5,
       5,    85,    87,     1,     6,     1,     6,     1,    31,     1,
      17,     1,    22,    25,     1,    22,    25,     1,    25,     5,
     111,   115,     1,    25,   115,   112,    96,   112,   112,   112,
     112,   112,   113,   113,   113,   114,   114,   114,   114,   114,
     111,   111,    96,    96,   111,   111,     5,    70,   107,   108,
     107,     1,     6,    26,    16,    77,    78,    79,    79,    70,
      26,     1,     6,    74,    74,     5,    24,    89,    89,    65,
      66,    65,    65,    65,   111,   111,    31,     1,    31,   111,
     111,   111,     1,    17,     1,    25,     1,    25,    37,   102,
       1,    43,    44,    21,    21,    20,   108,     1,    20,     5,
      80,     1,    20,    78,     1,    21,    25,    26,    70,     6,
       1,     6,    28,    79,    90,    91,    92,    93,     1,    21,
       6,    94,     1,     6,     6,     1,     6,   111,   111,   111,
      96,   111,   111,   111,    96,    96,     1,    17,    74,    74,
      27,    70,    79,     1,     6,    25,     1,    21,     1,    21,
      80,    80,    41,    41,    41,     1,     6,     1,     6,    18,
       1,    18,     6,     1,     6,    70,    91,    91,    80,    80,
      80,    80,    96,    96,    96,    74,    74,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    62,    63,    63,    64,    65,    66,    67,
      68,    68,    69,    69,    69,    69,    70,    70,    70,    70,
      70,    71,    71,    72,    72,    73,    73,    74,    74,    74,
      75,    75,    75,    76,    76,    77,    77,    78,    78,    78,
      79,    79,    80,    80,    80,    80,    80,    80,    80,    81,
      81,    82,    82,    83,    83,    83,    84,    84,    84,    84,
      84,    85,    85,    85,    86,    86,    87,    87,    87,    88,
      89,    89,    89,    90,    90,    90,    91,    91,    91,    91,
      92,    93,    94,    95,    95,    95,    96,    96,    96,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    98,    98,
      98,    98,    98,    98,    98,    99,    99,    99,    99,    99,
      99,    99,    99,   100,   100,   101,   102,   102,   103,   103,
     104,   104,   105,   105,   105,   106,   106,   106,   107,   107,
     108,   108,   108,   108,   109,   109,   110,   110,   110,   111,
     111,   111,   111,   111,   111,   111,   112,   112,   112,   112,
     113,   113,   113,   113,   113,   113,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     115,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     3,     3,     2,     2,     5,     0,
       2,     0,     5,     4,     5,     4,     1,     1,     1,     1,
       1,     2,     0,     2,     1,     4,     4,     1,     1,     1,
       6,     6,     6,     3,     3,     2,     1,     4,     4,     4,
       3,     1,     1,     1,     3,     3,     4,     5,     3,     2,
       0,     2,     1,     4,     4,     4,     2,     2,     1,     1,
       0,     4,     4,     4,     5,     5,     4,     4,     4,     3,
       3,     0,     3,     3,     1,     3,     3,     3,     3,     3,
       2,     1,     1,     3,     0,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     6,
       5,     6,     6,     5,     3,     1,     4,     1,     4,     4,
       4,     4,     4,     3,     3,     5,     2,     0,     4,     4,
       4,     4,     8,     8,     8,     5,     5,     5,     2,     1,
       4,     4,     4,     4,     2,     2,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     1,     1,     4,     1,     4,
       1,     3,     2,     2,     4,     3,     4,     4,     3,     4,
       3,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 28 "syntax.y" /* yacc.c:1661  */
    {
			(yyval) = newTreeNode(tPROGRAM);
			(yyval)->child[1] = (yyvsp[-2]);
			(yyval)->child[2] = (yyvsp[-1]);
            root = (yyval);
		}
#line 1653 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 3:
#line 34 "syntax.y" /* yacc.c:1661  */
    {
			(yyval) = newTreeNode(tPROGRAM);
			(yyval)->child[1] = (yyvsp[-2]);
			(yyval)->child[2] = (yyvsp[-1]);
            root = (yyval);
		}
#line 1664 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 4:
#line 42 "syntax.y" /* yacc.c:1661  */
    {
				(yyval) = (yyvsp[-1]);
			 }
#line 1672 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 45 "syntax.y" /* yacc.c:1661  */
    {
				(yyval) = (yyvsp[-1]);
			 }
#line 1680 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 50 "syntax.y" /* yacc.c:1661  */
    {
			(yyval) = newTreeNode(tROUTINE);
			(yyval)->child[1] = (yyvsp[-1]);
			(yyval)->child[2] = (yyvsp[0]);
		}
#line 1690 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 57 "syntax.y" /* yacc.c:1661  */
    {
				(yyval) = newTreeNode(tSUB_ROUTINE);
				(yyval)->child[1] = (yyvsp[-1]);
				(yyval)->child[2] = (yyvsp[0]);
			}
#line 1700 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 64 "syntax.y" /* yacc.c:1661  */
    {
			 	(yyval) = newTreeNode(tROUTINE_HEAD);
				(yyval)->child[0] = (yyvsp[-4]);
				(yyval)->child[1] = (yyvsp[-3]);
				(yyval)->child[2] = (yyvsp[-2]);
				(yyval)->child[3] = (yyvsp[-1]);
				(yyval)->child[4] = (yyvsp[0]);
			 }
#line 1713 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 74 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 1719 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 77 "syntax.y" /* yacc.c:1661  */
    {
		       (yyval) = (yyvsp[0]);
		   }
#line 1727 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 80 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 1733 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 83 "syntax.y" /* yacc.c:1661  */
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
#line 1750 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 95 "syntax.y" /* yacc.c:1661  */
    {
					(yyval) = newTreeNode(CONST_DECL);
					(yyval)->child[1] = (yyvsp[-3]);
					(yyval)->child[2] = (yyvsp[-1]);
				}
#line 1760 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 100 "syntax.y" /* yacc.c:1661  */
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
#line 1777 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 112 "syntax.y" /* yacc.c:1661  */
    {
					(yyval) = newTreeNode(CONST_DECL);
					(yyval)->child[1] = (yyvsp[-3]);
					(yyval)->child[2] = (yyvsp[-1]);
				}
#line 1787 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 119 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1793 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 120 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1799 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 121 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1805 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 122 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1811 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 123 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1817 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 126 "syntax.y" /* yacc.c:1661  */
    {
		      (yyval) = (yyvsp[0]);
		  }
#line 1825 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 129 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 1831 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 132 "syntax.y" /* yacc.c:1661  */
    {
			       pTree p = (yyvsp[-1]);
				   while(p->child[0])
				       p = p->child[0];
				   p->child[0] = (yyvsp[0]);
				   (yyval) = (yyvsp[-1]);
			   }
#line 1843 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 139 "syntax.y" /* yacc.c:1661  */
    {
			       (yyval) = (yyvsp[0]);
			   }
#line 1851 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 144 "syntax.y" /* yacc.c:1661  */
    {
					(yyval) = newTreeNode(TYPE_DECL);
					(yyval)->child[1] = (yyvsp[-3]);
					(yyval)->child[2] = (yyvsp[-1]);
				}
#line 1861 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 149 "syntax.y" /* yacc.c:1661  */
    {
					(yyval) = newTreeNode(TYPE_DECL);
					(yyval)->child[1] = (yyvsp[-3]);
					(yyval)->child[2] = (yyvsp[-1]);
				}
#line 1871 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 156 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1877 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 157 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1883 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 158 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1889 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 161 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = newTreeNode(ARRAY_DECL);
                    (yyval)->child[1] = (yyvsp[-3]);
                    (yyval)->child[2] = (yyvsp[0]);
                }
#line 1899 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 166 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = newTreeNode(ARRAY_DECL);
                    (yyval)->child[1] = (yyvsp[-3]);
                    (yyval)->child[2] = (yyvsp[0]);
                }
#line 1909 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 171 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = newTreeNode(ARRAY_DECL);
                    (yyval)->child[1] = (yyvsp[-3]);
                    (yyval)->child[2] = (yyvsp[0]);
                }
#line 1919 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 178 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = (yyvsp[-1]);
                 }
#line 1927 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 181 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = (yyvsp[-1]);
                 }
#line 1935 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 186 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = createList((yyvsp[-1]), (yyvsp[0]));
                }
#line 1943 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 189 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1949 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 192 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(FIELD_DECL);
               (yyval)->child[1] = (yyvsp[-3]);
               (yyval)->child[2] = (yyvsp[-1]);
           }
#line 1959 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 197 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(FIELD_DECL);
               (yyval)->child[1] = (yyvsp[-3]);
               (yyval)->child[2] = (yyvsp[-1]);
           }
#line 1969 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 202 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(FIELD_DECL);
               (yyval)->child[1] = (yyvsp[-3]);
               (yyval)->child[2] = (yyvsp[-1]);
           }
#line 1979 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 209 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = createList((yyvsp[-2]), (yyvsp[0]));
          }
#line 1987 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 212 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1993 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 215 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1999 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 216 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = (yyvsp[0]);
                    (yyval)->type = tSIMPLE_ID;
                 }
#line 2008 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 220 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = newTreeNode(tSIMPLE_ENUM);
                    (yyval)->child[1] = (yyvsp[-1]);
                 }
#line 2017 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 224 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = newTreeNode(tSIMPLE_SUBRANGE);
                    (yyval)->child[1] = (yyvsp[-2]);
                    (yyval)->child[2] = (yyvsp[0]);
                 }
#line 2027 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 229 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = newTreeNode(tSIMPLE_SUBRANGE);
                    (yyval)->child[1] = (yyvsp[-2]);
                    ((yyval)->child[1]->data).intVal *= -1;
                    (yyval)->child[2] = (yyvsp[0]);
                 }
#line 2038 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 235 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) =newTreeNode(tSIMPLE_SUBRANGE);
                    (yyval)->child[1] = (yyvsp[-3]);
                    ((yyval)->child[1]->data).intVal *= -1;
                    (yyval)->child[2] = (yyvsp[0]);
                    ((yyval)->child[2]->data).intVal *= -1;
                 }
#line 2050 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 242 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) =newTreeNode(tSIMPLE_SUBRANGE_ID);
                    (yyval)->child[1] = (yyvsp[-2]);
                    (yyval)->child[2] = (yyvsp[0]);
                 }
#line 2060 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 249 "syntax.y" /* yacc.c:1661  */
    {
             (yyval) = (yyvsp[0]);
         }
#line 2068 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 252 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 2074 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 255 "syntax.y" /* yacc.c:1661  */
    {
                  (yyval) = createList((yyvsp[-1]), (yyvsp[0]));
              }
#line 2082 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 258 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2088 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 261 "syntax.y" /* yacc.c:1661  */
    {
            (yyval) = newTreeNode(VAR_DECL);
            (yyval)->child[1] = (yyvsp[-3]);
            (yyval)->child[2] = (yyvsp[-1]);
         }
#line 2098 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 266 "syntax.y" /* yacc.c:1661  */
    {
            (yyval) = newTreeNode(VAR_DECL);
            (yyval)->child[1] = (yyvsp[-3]);
            (yyval)->child[2] = (yyvsp[-1]);
         }
#line 2108 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 271 "syntax.y" /* yacc.c:1661  */
    {
            (yyval) = newTreeNode(VAR_DECL);
            (yyval)->child[1] = (yyvsp[-3]);
            (yyval)->child[2] = (yyvsp[-1]);
         }
#line 2118 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 278 "syntax.y" /* yacc.c:1661  */
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
#line 2134 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 289 "syntax.y" /* yacc.c:1661  */
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
#line 2150 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 300 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = (yyvsp[0]);
             }
#line 2158 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 303 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = (yyvsp[0]);
             }
#line 2166 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 306 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 2172 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 309 "syntax.y" /* yacc.c:1661  */
    {
                  (yyval) = newTreeNode(FUNCTION_DECL);
                  (yyval)->child[1] = (yyvsp[-3]);
                  (yyval)->child[2] = (yyvsp[-1]);
              }
#line 2182 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 314 "syntax.y" /* yacc.c:1661  */
    {
                  (yyval) = newTreeNode(FUNCTION_DECL);
                  (yyval)->child[1] = (yyvsp[-3]);
                  (yyval)->child[2] = (yyvsp[-1]);
              }
#line 2192 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 319 "syntax.y" /* yacc.c:1661  */
    {
                  (yyval) = newTreeNode(FUNCTION_DECL);
                  (yyval)->child[1] = (yyvsp[-3]);
                  (yyval)->child[2] = (yyvsp[-1]);
              }
#line 2202 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 326 "syntax.y" /* yacc.c:1661  */
    {
                  (yyval) = newTreeNode(FUNCTION_HEAD);
                  (yyval)->child[1] = (yyvsp[-3]);
                  (yyval)->child[2] = (yyvsp[-2]);
                  (yyval)->child[3] = (yyvsp[0]);
              }
#line 2213 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 332 "syntax.y" /* yacc.c:1661  */
    {
                  (yyval) = newTreeNode(FUNCTION_HEAD);
                  (yyval)->child[1] = (yyvsp[-3]);
                  (yyval)->child[2] = (yyvsp[-2]);
                  (yyval)->child[3] = (yyvsp[0]);
              }
#line 2224 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 340 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = newTreeNode(PROCEDURE_DECL);
                   (yyval)->child[1] = (yyvsp[-3]);
                   (yyval)->child[2] = (yyvsp[-1]);
               }
#line 2234 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 345 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = newTreeNode(PROCEDURE_DECL);
                   (yyval)->child[1] = (yyvsp[-3]);
                   (yyval)->child[2] = (yyvsp[-1]);
               }
#line 2244 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 350 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = newTreeNode(PROCEDURE_DECL);
                   (yyval)->child[1] = (yyvsp[-3]);
                   (yyval)->child[2] = (yyvsp[-1]);
               }
#line 2254 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 357 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = newTreeNode(PROCEDURE_HEAD);
                   (yyval)->child[1] = (yyvsp[-1]);
                   (yyval)->child[2] = (yyvsp[0]);
               }
#line 2264 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 364 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = (yyvsp[-1]);
           }
#line 2272 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 367 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 2278 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 368 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = (yyvsp[-1]);
           }
#line 2286 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 373 "syntax.y" /* yacc.c:1661  */
    {
                   pTree p = (yyvsp[-2]);
                   while(p->child[0])
                       p = p->child[0];
                   p->child[0] = (yyvsp[0]);
                   (yyval) = (yyvsp[-2]);
               }
#line 2298 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 380 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = (yyvsp[0]);
               }
#line 2306 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 383 "syntax.y" /* yacc.c:1661  */
    {
                   pTree p = (yyvsp[-2]);
                   while(p->child[0])
                       p = p->child[0];
                   p->child[0] = (yyvsp[0]);
                   (yyval) = (yyvsp[-2]);
               }
#line 2318 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 392 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = newTreeNode(VAR_PARA);
                   (yyval)->child[1] = (yyvsp[-2]);
                   (yyval)->child[2] = (yyvsp[0]);
               }
#line 2328 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 397 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = newTreeNode(VAL_PARA);
                   (yyval)->child[1] = (yyvsp[-2]);
                   (yyval)->child[2] = (yyvsp[0]);
               }
#line 2338 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 402 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = newTreeNode(VAR_PARA);
                   (yyval)->child[1] = (yyvsp[-2]);
                   (yyval)->child[2] = (yyvsp[0]);
               }
#line 2348 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 407 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = newTreeNode(VAL_PARA);
                   (yyval)->child[1] = (yyvsp[-2]);
                   (yyval)->child[2] = (yyvsp[0]);
               }
#line 2358 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 414 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2364 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 417 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2370 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 420 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2376 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 423 "syntax.y" /* yacc.c:1661  */
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
#line 2392 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 434 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 2398 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 435 "syntax.y" /* yacc.c:1661  */
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
#line 2414 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 448 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(LABEL_STMT);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2424 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 453 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2430 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 454 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(LABEL_STMT);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2440 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 461 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2446 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 462 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2452 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 463 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2458 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 464 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2464 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 465 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2470 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 466 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2476 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 467 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2482 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 468 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2488 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 469 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2494 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 472 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = newTreeNode(ASSIGN_STMT_1);
                (yyval)->child[1] = (yyvsp[-2]);
                (yyval)->child[2] = (yyvsp[0]);
            }
#line 2504 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 477 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = newTreeNode(ASSIGN_STMT_2);
                (yyval)->child[1] = (yyvsp[-5]);
                (yyval)->child[2] = (yyvsp[-3]);
                (yyval)->child[3] = (yyvsp[0]);
            }
#line 2515 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 483 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = newTreeNode(ASSIGN_STMT_3);
                (yyval)->child[1] = (yyvsp[-4]);
                (yyval)->child[2] = (yyvsp[-2]);
                (yyval)->child[3] = (yyvsp[0]);
            }
#line 2526 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 489 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = newTreeNode(ASSIGN_STMT_2);
                (yyval)->child[1] = (yyvsp[-5]);
                (yyval)->child[2] = (yyvsp[-3]);
                (yyval)->child[3] = (yyvsp[0]);
            }
#line 2537 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 495 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = newTreeNode(ASSIGN_STMT_2);
                (yyval)->child[1] = (yyvsp[-5]);
                (yyval)->child[2] = (yyvsp[-3]);
                (yyval)->child[3] = (yyvsp[0]);
            }
#line 2548 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 501 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = newTreeNode(ASSIGN_STMT_3);
                (yyval)->child[1] = (yyvsp[-4]);
                (yyval)->child[2] = (yyvsp[-2]);
                (yyval)->child[3] = (yyvsp[0]);
            }
#line 2559 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 507 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = newTreeNode(ASSIGN_STMT_1);
                (yyval)->child[1] = (yyvsp[-2]);
                (yyval)->child[2] = (yyvsp[0]);
            }
#line 2569 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 514 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = (yyvsp[0]);
              (yyval)->type = PROC_STMT_ID;
          }
#line 2578 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 518 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(PROC_STMT_ID_ARGS);
              (yyval)->child[1] = (yyvsp[-3]);
              (yyval)->child[2] = (yyvsp[-1]);
          }
#line 2588 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 523 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2594 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 524 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(PROC_STMT_SYS_EXPR);
              (yyval)->child[1] = (yyvsp[-3]);
              (yyval)->child[3] = (yyvsp[-1]);
          }
#line 2604 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 529 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(PROC_STMT_READ);
              (yyval)->child[1] = (yyvsp[-1]);
          }
#line 2613 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 110:
#line 533 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(PROC_STMT_ID_ARGS);
              (yyval)->child[1] = (yyvsp[-3]);
              (yyval)->child[2] = (yyvsp[-1]);
          }
#line 2623 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 111:
#line 538 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(PROC_STMT_SYS_EXPR);
              (yyval)->child[1] = (yyvsp[-3]);
              (yyval)->child[3] = (yyvsp[-1]);
          }
#line 2633 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 543 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(PROC_STMT_READ);
              (yyval)->child[1] = (yyvsp[-1]);
          }
#line 2642 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 113:
#line 549 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); }
#line 2648 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 114:
#line 550 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); }
#line 2654 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 115:
#line 553 "syntax.y" /* yacc.c:1661  */
    {
            (yyval) = newTreeNode(IF_STMT);
            (yyval)->child[1] = (yyvsp[-3]);
            (yyval)->child[2] = (yyvsp[-1]);
            (yyval)->child[3] = (yyvsp[0]);
        }
#line 2665 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 116:
#line 561 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = (yyvsp[0]);
            }
#line 2673 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 117:
#line 564 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 2679 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 118:
#line 567 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = newTreeNode(REPEAT_STMT);
                (yyval)->child[1] = (yyvsp[-2]);
                (yyval)->child[2] = (yyvsp[0]);
            }
#line 2689 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 119:
#line 572 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = newTreeNode(REPEAT_STMT);
                (yyval)->child[1] = (yyvsp[-2]);
                (yyval)->child[2] = (yyvsp[0]);
            }
#line 2699 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 120:
#line 579 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(WHILE_STMT);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2709 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 121:
#line 584 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(WHILE_STMT);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2719 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 122:
#line 591 "syntax.y" /* yacc.c:1661  */
    {
            (yyval) = newTreeNode(FOR_STMT_TO);
            (yyval)->child[1] = (yyvsp[-6]);
            (yyval)->child[2] = (yyvsp[-4]);
            (yyval)->child[3] = (yyvsp[-2]);
            (yyval)->child[4] = (yyvsp[0]);
         }
#line 2731 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 123:
#line 598 "syntax.y" /* yacc.c:1661  */
    {
            (yyval) = newTreeNode(FOR_STMT_DOWNTO);
            (yyval)->child[1] = (yyvsp[-6]);
            (yyval)->child[2] = (yyvsp[-4]);
            (yyval)->child[3] = (yyvsp[-2]);
            (yyval)->child[4] = (yyvsp[0]);
         }
#line 2743 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 124:
#line 605 "syntax.y" /* yacc.c:1661  */
    {
            (yyval) = newTreeNode(FOR_STMT_TO);
            (yyval)->child[1] = (yyvsp[-6]);
            (yyval)->child[2] = (yyvsp[-4]);
            (yyval)->child[3] = (yyvsp[-2]);
            (yyval)->child[4] = (yyvsp[0]);
         }
#line 2755 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 125:
#line 614 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(CASE_STMT);
              (yyval)->child[1] = (yyvsp[-3]);
              (yyval)->child[2] = (yyvsp[-1]);
          }
#line 2765 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 126:
#line 619 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(CASE_STMT);
              (yyval)->child[1] = (yyvsp[-3]);
              (yyval)->child[2] = (yyvsp[-1]);
          }
#line 2775 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 127:
#line 624 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(CASE_STMT);
              (yyval)->child[1] = (yyvsp[-3]);
              (yyval)->child[2] = (yyvsp[-1]);
          }
#line 2785 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 128:
#line 631 "syntax.y" /* yacc.c:1661  */
    {
                   pTree p = (yyvsp[-1]);
                   while(p->child[0])
                       p = p->child[0];
                   p->child[0] = (yyvsp[0]);
                   (yyval) = (yyvsp[-1]);
               }
#line 2797 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 129:
#line 638 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = (yyvsp[0]);
               }
#line 2805 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 130:
#line 643 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(CASE_EXPR_CONST);
              (yyval)->child[1] = (yyvsp[-3]);
              (yyval)->child[2] = (yyvsp[-1]);
          }
#line 2815 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 131:
#line 648 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(CASE_EXPR_ID);
              (yyval)->child[1] = (yyvsp[-3]);
              (yyval)->child[2] = (yyvsp[-1]);
          }
#line 2825 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 132:
#line 653 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(CASE_EXPR_CONST);
              (yyval)->child[1] = (yyvsp[-3]);
              (yyval)->child[2] = (yyvsp[-1]);
          }
#line 2835 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 133:
#line 658 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(CASE_EXPR_ID);
              (yyval)->child[1] = (yyvsp[-3]);
              (yyval)->child[2] = (yyvsp[-1]);
          }
#line 2845 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 134:
#line 665 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(GOTO_STMT);
              (yyval)->child[1] = (yyvsp[0]);
          }
#line 2854 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 135:
#line 669 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(GOTO_STMT);
              (yyval)->child[1] = NULL;
          }
#line 2863 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 136:
#line 675 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = createList((yyvsp[-2]), (yyvsp[0]));
                }
#line 2871 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 137:
#line 678 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2877 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 138:
#line 679 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = createList((yyvsp[-2]), (yyvsp[0]));
                }
#line 2885 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 139:
#line 684 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(eGE);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2895 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 140:
#line 689 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(eGT);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2905 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 141:
#line 694 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(eLE);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2915 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 142:
#line 699 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(eLT);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2925 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 143:
#line 704 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(eEQUAL);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2935 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 144:
#line 709 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(eUNEQUAL);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2945 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 145:
#line 714 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = (yyvsp[0]);
           }
#line 2953 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 146:
#line 719 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(ePLUS);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2963 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 147:
#line 724 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(eMINUS);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2973 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 148:
#line 729 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(eOR);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2983 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 149:
#line 734 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = (yyvsp[0]);
     }
#line 2991 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 150:
#line 739 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(eMUL);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 3001 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 151:
#line 744 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(eRDIV);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 3011 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 152:
#line 749 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(eDIV);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 3021 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 153:
#line 754 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(eMOD);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 3031 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 154:
#line 759 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(eAND);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 3041 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 155:
#line 764 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = (yyvsp[0]);
     }
#line 3049 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 156:
#line 769 "syntax.y" /* yacc.c:1661  */
    {
           (yyval) = (yyvsp[0]);
           (yyval)->type = FACTOR_ID;
       }
#line 3058 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 157:
#line 773 "syntax.y" /* yacc.c:1661  */
    {
           (yyval) = newTreeNode(FACTOR_FUNC);
           (yyval)->child[1] = (yyvsp[-3]);
           (yyval)->child[2] = (yyvsp[-1]);
       }
#line 3068 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 158:
#line 778 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 3074 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 159:
#line 779 "syntax.y" /* yacc.c:1661  */
    {
           (yyval) = newTreeNode(FACTOR_SYS_FUNC_ARGS);
           (yyval)->child[1] = (yyvsp[-3]);
           (yyval)->child[2] = (yyvsp[-1]);
       }
#line 3084 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 160:
#line 784 "syntax.y" /* yacc.c:1661  */
    {
           (yyval) = newTreeNode(FACTOR_CONST);
           (yyval)->child[1] = (yyvsp[0]);
       }
#line 3093 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 161:
#line 788 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); }
#line 3099 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 162:
#line 789 "syntax.y" /* yacc.c:1661  */
    {
           (yyval) = newTreeNode(FACTOR_NOT);
           (yyval)->child[1] = (yyvsp[0]);
       }
#line 3108 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 163:
#line 793 "syntax.y" /* yacc.c:1661  */
    {
           (yyval) = newTreeNode(FACTOR_MINUS);
           (yyval)->child[1] = (yyvsp[0]);
       }
#line 3117 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 164:
#line 797 "syntax.y" /* yacc.c:1661  */
    {
           (yyval) = newTreeNode(FACTOR_ARRAY);
           (yyval)->child[1] = (yyvsp[-3]);
           (yyval)->child[2] = (yyvsp[-1]);
       }
#line 3127 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 165:
#line 802 "syntax.y" /* yacc.c:1661  */
    {
           (yyval) = newTreeNode(FACTOR_RECORD);
           (yyval)->child[1] = (yyvsp[-2]);
           (yyval)->child[2] = (yyvsp[0]);
       }
#line 3137 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 166:
#line 807 "syntax.y" /* yacc.c:1661  */
    {
           (yyval) = newTreeNode(FACTOR_FUNC);
           (yyval)->child[1] = (yyvsp[-3]);
           (yyval)->child[2] = (yyvsp[-1]);
       }
#line 3147 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 167:
#line 812 "syntax.y" /* yacc.c:1661  */
    {
           (yyval) = newTreeNode(FACTOR_SYS_FUNC_ARGS);
           (yyval)->child[1] = (yyvsp[-3]);
           (yyval)->child[2] = (yyvsp[-1]);
       }
#line 3157 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 168:
#line 817 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); }
#line 3163 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 169:
#line 818 "syntax.y" /* yacc.c:1661  */
    {
           (yyval) = newTreeNode(FACTOR_ARRAY);
           (yyval)->child[1] = (yyvsp[-3]);
           (yyval)->child[2] = (yyvsp[-1]);
       }
#line 3173 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 170:
#line 825 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = createList((yyvsp[-2]), (yyvsp[0]));
          }
#line 3181 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 171:
#line 828 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 3187 "syntax.tab.c" /* yacc.c:1661  */
    break;


#line 3191 "syntax.tab.c" /* yacc.c:1661  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 831 "syntax.y" /* yacc.c:1906  */


pTree parse(FILE * file) {
    yyin = file;
    
    yyparse();

    return root;
}

int yyerror(char* s) {
    errorno++;
	fprintf(stderr, "%s near line %d\n", s, yylineno);
}
