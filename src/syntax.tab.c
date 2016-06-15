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
#define YYLAST   373

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  143
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  286

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
       0,    28,    28,    34,    37,    40,    43,    50,    57,    67,
      70,    73,    76,    88,    93,    94,    97,    98,    99,   100,
     101,   104,   107,   110,   117,   122,   127,   130,   131,   132,
     135,   142,   145,   148,   151,   154,   159,   162,   165,   168,
     169,   173,   177,   182,   188,   195,   202,   205,   208,   211,
     214,   219,   222,   233,   244,   247,   250,   253,   258,   261,
     269,   274,   277,   284,   287,   290,   297,   300,   303,   308,
     315,   318,   321,   324,   335,   336,   339,   344,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   358,   363,   369,
     377,   381,   386,   387,   392,   398,   399,   402,   410,   413,
     416,   423,   430,   437,   446,   451,   454,   461,   466,   471,
     476,   477,   480,   486,   489,   492,   497,   502,   507,   512,
     517,   522,   527,   532,   537,   542,   547,   552,   557,   562,
     567,   572,   577,   581,   586,   587,   592,   596,   597,   601,
     605,   610,   617,   620
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

#define YYPACT_NINF -186

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-186)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      29,   108,    70,  -186,    22,  -186,   101,   -20,    89,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,   128,   115,   117,    84,
     130,   139,   141,  -186,    10,   137,  -186,   167,   175,    38,
    -186,    38,   162,    38,   204,    24,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,   355,   214,   215,   139,
    -186,   226,    -8,   227,    38,    38,    38,   280,    38,    38,
       8,  -186,  -186,  -186,  -186,  -186,    38,    38,   209,    38,
    -186,    91,   -17,   315,  -186,   249,   123,   203,    59,  -186,
    -186,  -186,    63,   355,   251,  -186,  -186,    33,   226,  -186,
     241,   242,    -8,  -186,    65,  -186,    77,   217,   158,   202,
     -10,   202,  -186,    99,   202,   230,   252,    38,    38,   168,
    -186,    38,  -186,    38,   264,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,   264,
      38,   350,  -186,  -186,    78,   233,   255,   226,  -186,   226,
     355,   239,    87,  -186,  -186,  -186,   251,   262,  -186,   244,
     244,  -186,  -186,  -186,  -186,  -186,  -186,    38,   245,    38,
    -186,    38,  -186,  -186,  -186,   177,   131,  -186,   143,   -17,
     235,   -17,   -17,   -17,   -17,   -17,   315,   315,   315,  -186,
    -186,  -186,  -186,  -186,   202,  -186,     9,   256,   258,   338,
    -186,  -186,  -186,   275,   318,    85,  -186,   124,   164,   260,
     355,  -186,  -186,   111,  -186,    14,   269,  -186,   291,   -20,
     287,   299,   295,   202,    38,   202,   202,  -186,  -186,  -186,
     264,  -186,    38,    38,   264,   264,  -186,  -186,  -186,  -186,
     286,  -186,  -186,  -186,   251,  -186,   171,  -186,  -186,  -186,
     226,   283,    62,  -186,   290,   296,   318,  -186,  -186,  -186,
    -186,  -186,   202,  -186,   189,   194,   113,   119,   289,   122,
     355,  -186,   283,    14,    14,  -186,   318,   318,  -186,   264,
     264,  -186,  -186,  -186,  -186,   251,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,  -186
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     9,     0,     1,     0,     0,    11,     5,
       4,     3,     2,    74,     6,    72,     0,    22,     0,     0,
      10,     0,    47,    96,    90,     0,    95,    92,     0,     0,
      74,     0,     0,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,    21,
      24,     0,    56,     0,     0,     0,     0,     0,     0,     0,
     132,    16,    17,    18,    19,    20,     0,     0,   134,     0,
     136,     0,   121,   125,   131,     0,     0,     0,     0,   112,
      75,    73,     0,     0,     0,    23,    38,     0,    46,    49,
       0,     0,     8,    54,     0,    55,     0,     0,     0,   143,
       0,    87,    76,     0,   114,     0,     0,     0,     0,     0,
     139,     0,   138,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    13,     0,    40,     0,     0,    39,     0,
       0,     0,     0,    28,    29,    27,     0,     0,    48,    64,
      64,    52,    53,     9,     9,     9,     9,     0,     0,     0,
      91,     0,    93,    94,   141,     0,     0,   137,     0,   119,
      99,   115,   116,   117,   118,   120,   123,   122,   124,   126,
     128,   127,   129,   130,   100,   101,     0,     0,     0,     0,
     107,    14,    12,     0,     0,     0,    34,     0,     0,     0,
       0,    26,    25,     0,    37,     0,     0,    62,     0,     0,
       0,     0,     0,    89,     0,   142,   113,   140,   133,   135,
       0,    97,     0,     0,     0,     0,   105,   104,   106,    45,
       0,    32,    31,    33,     0,    41,     0,    42,    51,    50,
       0,    71,     0,    66,     0,     0,     0,    58,     7,    57,
      61,    60,    88,    98,     0,     0,     0,     0,     0,     0,
       0,    43,    70,     0,     0,    63,     0,     0,    59,     0,
       0,   111,   109,   110,   108,     0,    36,    35,    44,    67,
      65,    68,    69,   102,   103,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -186,  -186,  -186,  -186,  -110,   305,  -186,  -186,  -186,   -46,
    -186,  -186,   267,  -139,  -186,  -186,  -186,   126,   -48,  -185,
    -186,  -186,   231,  -186,   232,  -186,   248,  -186,   183,  -186,
     -52,  -186,  -186,   135,   316,  -109,   297,  -186,  -186,    -6,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,   163,  -186,  -186,
     -27,   219,    57,   -51,    93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,   208,   209,     8,    17,    20,    70,
      22,    49,    50,   142,   143,   144,   195,   196,   241,   145,
      52,    88,    89,    92,    93,    94,    95,    96,   206,   242,
     243,   244,   245,    14,    18,    35,    36,    37,    38,    39,
      40,   221,    41,    42,    43,    44,   189,   190,    45,   103,
      99,    72,    73,    74,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      82,    15,    71,    87,    76,   170,    78,   203,   105,   230,
     120,   106,   159,    53,    13,   160,   110,   113,   112,    86,
     185,    90,    91,     9,   107,    80,    54,    98,    10,   101,
      81,   104,   108,     1,    55,   121,   122,   134,   141,   109,
      87,    56,   240,    60,   210,   211,   212,    61,    62,    63,
      64,    65,   222,   223,   146,   147,   115,   116,   117,   118,
     119,   268,    66,   263,   132,    67,   153,   113,   264,   133,
       5,   154,   179,   180,   181,   182,   183,   131,   155,   191,
     165,   281,   282,   156,   192,   188,   231,   265,   201,   197,
      86,   198,    46,   202,   199,   259,    16,    68,    69,   113,
     141,   184,    11,   186,    12,   232,   115,   116,   117,   118,
     119,   253,   238,     4,   271,   256,   257,   239,    23,   272,
     273,   161,    24,   276,   162,   274,    25,   114,   277,    21,
     213,   113,   215,    19,   216,    47,   285,    26,   115,   116,
     117,   118,   119,   188,    48,   234,   147,   197,   141,    27,
      28,    13,    29,   159,   237,    30,   218,    31,    57,    32,
     283,   284,    33,    34,   129,   159,   113,    77,   219,    51,
     115,   116,   117,   118,   119,   158,   113,   176,   177,   178,
      61,    62,    63,    64,    65,   113,   147,   252,   141,   235,
     261,    58,   262,   167,   217,   254,   255,   113,   260,    59,
     141,   166,   113,    15,   168,   115,   116,   117,   118,   119,
     113,   279,   280,    79,   278,   115,   116,   117,   118,   119,
     141,   141,    83,    84,   115,   116,   117,   118,   119,   141,
     269,    86,    97,   111,   130,   270,   115,   116,   117,   118,
     119,   115,   116,   117,   118,   119,   149,   150,   157,   115,
     116,   117,   118,   119,    24,   163,   135,   164,    25,   193,
      61,    62,    63,    64,    65,   200,   136,   204,   205,    24,
     137,   194,   220,    25,   138,   139,   214,   224,   140,   225,
     229,    27,    28,    13,    29,    24,   236,    30,   128,    31,
     246,    32,   247,   249,    33,    34,    27,    28,    13,    29,
     250,   251,    30,   258,    31,   147,    32,   275,     7,    33,
      34,   266,    27,    28,    13,    29,    85,   267,    30,   148,
      31,   233,    32,   135,   151,    33,    34,    61,    62,    63,
      64,    65,   169,   207,   171,   172,   173,   174,   175,   226,
     152,   138,   139,   187,   248,   140,    75,    61,    62,    63,
      64,    65,   228,     0,   102,   187,     0,     0,   227,    61,
      62,    63,    64,    65,    61,    62,    63,    64,    65,   123,
     124,   125,   126,   127
};

static const yytype_int16 yycheck[] =
{
      46,     7,    29,    51,    31,   114,    33,   146,    59,   194,
      27,     3,    22,     3,    34,    25,    67,     8,    69,     5,
     129,    29,    30,     1,    16,     1,    16,    54,     6,    56,
       6,    58,    24,     4,    24,    52,    53,    83,    84,    66,
      88,    31,    28,     5,   154,   155,   156,     9,    10,    11,
      12,    13,    43,    44,    21,    22,    47,    48,    49,    50,
      51,   246,    24,     1,     1,    27,     1,     8,     6,     6,
       0,     6,   123,   124,   125,   126,   127,    18,     1,     1,
     107,   266,   267,     6,     6,   131,     1,    25,     1,   137,
       5,   139,     8,     6,   140,   234,     7,    59,    60,     8,
     146,   128,     1,   130,     3,    20,    47,    48,    49,    50,
      51,   220,     1,     5,     1,   224,   225,     6,     1,     6,
       1,    22,     5,     1,    25,     6,     9,    36,     6,    14,
     157,     8,   159,     5,   161,     5,   275,    20,    47,    48,
      49,    50,    51,   189,     5,    21,    22,   195,   194,    32,
      33,    34,    35,    22,   200,    38,    25,    40,    21,    42,
     269,   270,    45,    46,    41,    22,     8,     5,    25,    28,
      47,    48,    49,    50,    51,    17,     8,   120,   121,   122,
       9,    10,    11,    12,    13,     8,    22,   214,   234,    25,
     236,    24,   240,    25,    17,   222,   223,     8,    27,    24,
     246,   108,     8,   209,   111,    47,    48,    49,    50,    51,
       8,   263,   264,     9,   260,    47,    48,    49,    50,    51,
     266,   267,     8,     8,    47,    48,    49,    50,    51,   275,
      41,     5,     5,    24,    31,    41,    47,    48,    49,    50,
      51,    47,    48,    49,    50,    51,     5,     5,    31,    47,
      48,    49,    50,    51,     5,    25,     5,     5,     9,    26,
       9,    10,    11,    12,    13,    26,    15,     5,    24,     5,
      19,    16,    37,     9,    23,    24,    31,    21,    27,    21,
       5,    32,    33,    34,    35,     5,    26,    38,    39,    40,
      21,    42,     1,     6,    45,    46,    32,    33,    34,    35,
       1,     6,    38,    17,    40,    22,    42,    18,     3,    45,
      46,    21,    32,    33,    34,    35,    49,    21,    38,    88,
      40,   195,    42,     5,    92,    45,    46,     9,    10,    11,
      12,    13,   113,   150,   115,   116,   117,   118,   119,     1,
      92,    23,    24,     5,   209,    27,    30,     9,    10,    11,
      12,    13,   189,    -1,    57,     5,    -1,    -1,    20,     9,
      10,    11,    12,    13,     9,    10,    11,    12,    13,    54,
      55,    56,    57,    58
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
      73,    28,    81,     3,    16,    24,    31,    21,    24,    24,
       5,     9,    10,    11,    12,    13,    24,    27,    59,    60,
      70,   111,   112,   113,   114,    95,   111,     5,   111,     9,
       1,     6,    70,     8,     8,    73,     5,    79,    82,    83,
      29,    30,    84,    85,    86,    87,    88,     5,   111,   111,
     115,   111,    97,   110,   111,   114,     3,    16,    24,   111,
     114,    24,   114,     8,    36,    47,    48,    49,    50,    51,
      27,    52,    53,    54,    55,    56,    57,    58,    39,    41,
      31,    18,     1,     6,    70,     5,    15,    19,    23,    24,
      27,    70,    74,    75,    76,    80,    21,    22,    83,     5,
       5,    85,    87,     1,     6,     1,     6,    31,    17,    22,
      25,    22,    25,    25,     5,   111,   115,    25,   115,   112,
      96,   112,   112,   112,   112,   112,   113,   113,   113,   114,
     114,   114,   114,   114,   111,    96,   111,     5,    70,   107,
     108,     1,     6,    26,    16,    77,    78,    79,    79,    70,
      26,     1,     6,    74,     5,    24,    89,    89,    65,    66,
      65,    65,    65,   111,    31,   111,   111,    17,    25,    25,
      37,   102,    43,    44,    21,    21,     1,    20,   108,     5,
      80,     1,    20,    78,    21,    25,    26,    70,     1,     6,
      28,    79,    90,    91,    92,    93,    21,     1,    94,     6,
       1,     6,   111,    96,   111,   111,    96,    96,    17,    74,
      27,    70,    79,     1,     6,    25,    21,    21,    80,    41,
      41,     1,     6,     1,     6,    18,     1,     6,    70,    91,
      91,    80,    80,    96,    96,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    62,    63,    63,    64,    65,    66,    67,
      68,    68,    69,    69,    69,    69,    70,    70,    70,    70,
      70,    71,    71,    72,    72,    73,    73,    74,    74,    74,
      75,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    81,    81,    82,    82,
      83,    83,    84,    84,    84,    84,    84,    85,    85,    86,
      87,    87,    88,    89,    89,    90,    90,    90,    91,    91,
      92,    93,    94,    95,    95,    95,    96,    96,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    98,    98,    98,
      99,    99,    99,    99,    99,   100,   100,   101,   102,   102,
     103,   104,   105,   105,   106,   106,   107,   107,   108,   108,
     108,   108,   109,   110,   110,   111,   111,   111,   111,   111,
     111,   111,   112,   112,   112,   112,   113,   113,   113,   113,
     113,   113,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   115,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     3,     3,     2,     2,     5,     0,
       2,     0,     5,     4,     5,     4,     1,     1,     1,     1,
       1,     2,     0,     2,     1,     4,     4,     1,     1,     1,
       6,     3,     3,     2,     1,     4,     4,     3,     1,     1,
       1,     3,     3,     4,     5,     3,     2,     0,     2,     1,
       4,     4,     2,     2,     1,     1,     0,     4,     4,     5,
       4,     4,     3,     3,     0,     3,     1,     3,     3,     3,
       2,     1,     1,     3,     0,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     6,     5,
       1,     4,     1,     4,     4,     3,     3,     5,     2,     0,
       4,     4,     8,     8,     5,     5,     2,     1,     4,     4,
       4,     4,     2,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     1,     1,     4,     1,     4,     1,     3,     2,     2,
       4,     3,     3,     1
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
#line 1613 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 4:
#line 37 "syntax.y" /* yacc.c:1661  */
    {
				(yyval) = (yyvsp[-1]);
			 }
#line 1621 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 43 "syntax.y" /* yacc.c:1661  */
    {
			(yyval) = newTreeNode(tROUTINE);
			(yyval)->child[1] = (yyvsp[-1]);
			(yyval)->child[2] = (yyvsp[0]);
		}
#line 1631 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 50 "syntax.y" /* yacc.c:1661  */
    {
				(yyval) = newTreeNode(tSUB_ROUTINE);
				(yyval)->child[1] = (yyvsp[-1]);
				(yyval)->child[2] = (yyvsp[0]);
			}
#line 1641 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 57 "syntax.y" /* yacc.c:1661  */
    {
			 	(yyval) = newTreeNode(tROUTINE_HEAD);
				(yyval)->child[0] = (yyvsp[-4]);
				(yyval)->child[1] = (yyvsp[-3]);
				(yyval)->child[2] = (yyvsp[-2]);
				(yyval)->child[3] = (yyvsp[-1]);
				(yyval)->child[4] = (yyvsp[0]);
			 }
#line 1654 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 67 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 1660 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 70 "syntax.y" /* yacc.c:1661  */
    {
		       (yyval) = (yyvsp[0]);
		   }
#line 1668 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 73 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 1674 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 76 "syntax.y" /* yacc.c:1661  */
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
#line 1691 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 88 "syntax.y" /* yacc.c:1661  */
    {
					(yyval) = newTreeNode(CONST_DECL);
					(yyval)->child[1] = (yyvsp[-3]);
					(yyval)->child[2] = (yyvsp[-1]);
				}
#line 1701 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 97 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1707 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 98 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1713 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 99 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1719 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 100 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1725 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 101 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1731 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 104 "syntax.y" /* yacc.c:1661  */
    {
		      (yyval) = (yyvsp[0]);
		  }
#line 1739 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 107 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 1745 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 110 "syntax.y" /* yacc.c:1661  */
    {
			       pTree p = (yyvsp[-1]);
				   while(p->child[0])
				       p = p->child[0];
				   p->child[0] = (yyvsp[0]);
				   (yyval) = (yyvsp[-1]);
			   }
#line 1757 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 117 "syntax.y" /* yacc.c:1661  */
    {
			       (yyval) = (yyvsp[0]);
			   }
#line 1765 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 122 "syntax.y" /* yacc.c:1661  */
    {
					(yyval) = newTreeNode(TYPE_DECL);
					(yyval)->child[1] = (yyvsp[-3]);
					(yyval)->child[2] = (yyvsp[-1]);
				}
#line 1775 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 130 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1781 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 131 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1787 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 132 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1793 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 135 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = newTreeNode(ARRAY_DECL);
                    (yyval)->child[1] = (yyvsp[-3]);
                    (yyval)->child[2] = (yyvsp[0]);
                }
#line 1803 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 142 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = (yyvsp[-1]);
                 }
#line 1811 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 148 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = createList((yyvsp[-1]), (yyvsp[0]));
                }
#line 1819 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 151 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1825 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 154 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(FIELD_DECL);
               (yyval)->child[1] = (yyvsp[-3]);
               (yyval)->child[2] = (yyvsp[-1]);
           }
#line 1835 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 162 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = createList((yyvsp[-2]), (yyvsp[0]));
          }
#line 1843 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 165 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1849 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 168 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1855 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 169 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = (yyvsp[0]);
                    (yyval)->type = tSIMPLE_ID;
                 }
#line 1864 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 173 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = newTreeNode(tSIMPLE_ENUM);
                    (yyval)->child[1] = (yyvsp[-1]);
                 }
#line 1873 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 177 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = newTreeNode(tSIMPLE_SUBRANGE);
                    (yyval)->child[1] = (yyvsp[-2]);
                    (yyval)->child[2] = (yyvsp[0]);
                 }
#line 1883 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 182 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = newTreeNode(tSIMPLE_SUBRANGE);
                    (yyval)->child[1] = (yyvsp[-2]);
                    ((yyval)->child[1]->data).intVal *= -1;
                    (yyval)->child[2] = (yyvsp[0]);
                 }
#line 1894 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 188 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) =newTreeNode(tSIMPLE_SUBRANGE);
                    (yyval)->child[1] = (yyvsp[-3]);
                    ((yyval)->child[1]->data).intVal *= -1;
                    (yyval)->child[2] = (yyvsp[0]);
                    ((yyval)->child[2]->data).intVal *= -1;
                 }
#line 1906 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 195 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) =newTreeNode(tSIMPLE_SUBRANGE_ID);
                    (yyval)->child[1] = (yyvsp[-2]);
                    (yyval)->child[2] = (yyvsp[0]);
                 }
#line 1916 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 202 "syntax.y" /* yacc.c:1661  */
    {
             (yyval) = (yyvsp[0]);
         }
#line 1924 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 205 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 1930 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 208 "syntax.y" /* yacc.c:1661  */
    {
                  (yyval) = createList((yyvsp[-1]), (yyvsp[0]));
              }
#line 1938 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 211 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1944 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 214 "syntax.y" /* yacc.c:1661  */
    {
            (yyval) = newTreeNode(VAR_DECL);
            (yyval)->child[1] = (yyvsp[-3]);
            (yyval)->child[2] = (yyvsp[-1]);
         }
#line 1954 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 222 "syntax.y" /* yacc.c:1661  */
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
#line 1970 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 233 "syntax.y" /* yacc.c:1661  */
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
#line 1986 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 244 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = (yyvsp[0]);
             }
#line 1994 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 247 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = (yyvsp[0]);
             }
#line 2002 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 250 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 2008 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 253 "syntax.y" /* yacc.c:1661  */
    {
                  (yyval) = newTreeNode(FUNCTION_DECL);
                  (yyval)->child[1] = (yyvsp[-3]);
                  (yyval)->child[2] = (yyvsp[-1]);
              }
#line 2018 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 261 "syntax.y" /* yacc.c:1661  */
    {
                  (yyval) = newTreeNode(FUNCTION_HEAD);
                  (yyval)->child[1] = (yyvsp[-3]);
                  (yyval)->child[2] = (yyvsp[-2]);
                  (yyval)->child[3] = (yyvsp[0]);
              }
#line 2029 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 269 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = newTreeNode(PROCEDURE_DECL);
                   (yyval)->child[1] = (yyvsp[-3]);
                   (yyval)->child[2] = (yyvsp[-1]);
               }
#line 2039 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 277 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = newTreeNode(PROCEDURE_HEAD);
                   (yyval)->child[1] = (yyvsp[-1]);
                   (yyval)->child[2] = (yyvsp[0]);
               }
#line 2049 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 284 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = (yyvsp[-1]);
           }
#line 2057 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 287 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 2063 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 290 "syntax.y" /* yacc.c:1661  */
    {
                   pTree p = (yyvsp[-2]);
                   while(p->child[0])
                       p = p->child[0];
                   p->child[0] = (yyvsp[0]);
                   (yyval) = (yyvsp[-2]);
               }
#line 2075 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 297 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = (yyvsp[0]);
               }
#line 2083 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 303 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = newTreeNode(VAR_PARA);
                   (yyval)->child[1] = (yyvsp[-2]);
                   (yyval)->child[2] = (yyvsp[0]);
               }
#line 2093 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 308 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = newTreeNode(VAL_PARA);
                   (yyval)->child[1] = (yyvsp[-2]);
                   (yyval)->child[2] = (yyvsp[0]);
               }
#line 2103 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 315 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2109 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 318 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2115 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 321 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2121 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 324 "syntax.y" /* yacc.c:1661  */
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
#line 2137 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 335 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 2143 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 339 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(LABEL_STMT);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2153 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 344 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2159 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 347 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2165 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 348 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2171 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 349 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2177 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 350 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2183 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 351 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2189 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 352 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2195 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 353 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2201 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 354 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2207 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 355 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2213 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 358 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = newTreeNode(ASSIGN_STMT_1);
                (yyval)->child[1] = (yyvsp[-2]);
                (yyval)->child[2] = (yyvsp[0]);
            }
#line 2223 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 363 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = newTreeNode(ASSIGN_STMT_2);
                (yyval)->child[1] = (yyvsp[-5]);
                (yyval)->child[2] = (yyvsp[-3]);
                (yyval)->child[3] = (yyvsp[0]);
            }
#line 2234 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 369 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = newTreeNode(ASSIGN_STMT_3);
                (yyval)->child[1] = (yyvsp[-4]);
                (yyval)->child[2] = (yyvsp[-2]);
                (yyval)->child[3] = (yyvsp[0]);
            }
#line 2245 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 377 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = (yyvsp[0]);
              (yyval)->type = PROC_STMT_ID;
          }
#line 2254 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 381 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(PROC_STMT_ID_ARGS);
              (yyval)->child[1] = (yyvsp[-3]);
              (yyval)->child[2] = (yyvsp[-1]);
          }
#line 2264 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 386 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2270 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 387 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(PROC_STMT_SYS_EXPR);
              (yyval)->child[1] = (yyvsp[-3]);
              (yyval)->child[3] = (yyvsp[-1]);
          }
#line 2280 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 392 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(PROC_STMT_READ);
              (yyval)->child[1] = (yyvsp[-1]);
          }
#line 2289 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 398 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); }
#line 2295 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 402 "syntax.y" /* yacc.c:1661  */
    {
            (yyval) = newTreeNode(IF_STMT);
            (yyval)->child[1] = (yyvsp[-3]);
            (yyval)->child[2] = (yyvsp[-1]);
            (yyval)->child[3] = (yyvsp[0]);
        }
#line 2306 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 410 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = (yyvsp[0]);
            }
#line 2314 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 413 "syntax.y" /* yacc.c:1661  */
    { (yyval) = NULL; }
#line 2320 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 416 "syntax.y" /* yacc.c:1661  */
    {
                (yyval) = newTreeNode(REPEAT_STMT);
                (yyval)->child[1] = (yyvsp[-2]);
                (yyval)->child[2] = (yyvsp[0]);
            }
#line 2330 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 423 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(WHILE_STMT);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2340 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 430 "syntax.y" /* yacc.c:1661  */
    {
            (yyval) = newTreeNode(FOR_STMT_TO);
            (yyval)->child[1] = (yyvsp[-6]);
            (yyval)->child[2] = (yyvsp[-4]);
            (yyval)->child[3] = (yyvsp[-2]);
            (yyval)->child[4] = (yyvsp[0]);
         }
#line 2352 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 437 "syntax.y" /* yacc.c:1661  */
    {
            (yyval) = newTreeNode(FOR_STMT_DOWNTO);
            (yyval)->child[1] = (yyvsp[-6]);
            (yyval)->child[2] = (yyvsp[-4]);
            (yyval)->child[3] = (yyvsp[-2]);
            (yyval)->child[4] = (yyvsp[0]);
         }
#line 2364 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 446 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(CASE_STMT);
              (yyval)->child[1] = (yyvsp[-3]);
              (yyval)->child[2] = (yyvsp[-1]);
          }
#line 2374 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 454 "syntax.y" /* yacc.c:1661  */
    {
                   pTree p = (yyvsp[-1]);
                   while(p->child[0])
                       p = p->child[0];
                   p->child[0] = (yyvsp[0]);
                   (yyval) = (yyvsp[-1]);
               }
#line 2386 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 461 "syntax.y" /* yacc.c:1661  */
    {
                   (yyval) = (yyvsp[0]);
               }
#line 2394 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 466 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(CASE_EXPR_CONST);
              (yyval)->child[1] = (yyvsp[-3]);
              (yyval)->child[2] = (yyvsp[-1]);
          }
#line 2404 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 471 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(CASE_EXPR_ID);
              (yyval)->child[1] = (yyvsp[-3]);
              (yyval)->child[2] = (yyvsp[-1]);
          }
#line 2414 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 480 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = newTreeNode(GOTO_STMT);
              (yyval)->child[1] = (yyvsp[0]);
          }
#line 2423 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 113:
#line 486 "syntax.y" /* yacc.c:1661  */
    {
                    (yyval) = createList((yyvsp[-2]), (yyvsp[0]));
                }
#line 2431 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 114:
#line 489 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2437 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 115:
#line 492 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(eGE);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2447 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 116:
#line 497 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(eGT);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2457 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 117:
#line 502 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(eLE);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2467 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 118:
#line 507 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(eLT);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2477 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 119:
#line 512 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(eEQUAL);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2487 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 120:
#line 517 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = newTreeNode(eUNEQUAL);
               (yyval)->child[1] = (yyvsp[-2]);
               (yyval)->child[2] = (yyvsp[0]);
           }
#line 2497 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 121:
#line 522 "syntax.y" /* yacc.c:1661  */
    {
               (yyval) = (yyvsp[0]);
           }
#line 2505 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 122:
#line 527 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(ePLUS);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2515 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 123:
#line 532 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(eMINUS);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2525 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 124:
#line 537 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(eOR);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2535 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 125:
#line 542 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = (yyvsp[0]);
     }
#line 2543 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 126:
#line 547 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(eMUL);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2553 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 127:
#line 552 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(eRDIV);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2563 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 128:
#line 557 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(eDIV);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2573 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 129:
#line 562 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(eMOD);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2583 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 130:
#line 567 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = newTreeNode(eAND);
        (yyval)->child[1] = (yyvsp[-2]);
        (yyval)->child[2] = (yyvsp[0]);
     }
#line 2593 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 131:
#line 572 "syntax.y" /* yacc.c:1661  */
    {
        (yyval) = (yyvsp[0]);
     }
#line 2601 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 132:
#line 577 "syntax.y" /* yacc.c:1661  */
    {
           (yyval) = (yyvsp[0]);
           (yyval)->type = FACTOR_ID;
       }
#line 2610 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 133:
#line 581 "syntax.y" /* yacc.c:1661  */
    {
           (yyval) = newTreeNode(FACTOR_FUNC);
           (yyval)->child[1] = (yyvsp[-3]);
           (yyval)->child[2] = (yyvsp[-1]);
       }
#line 2620 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 134:
#line 586 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2626 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 135:
#line 587 "syntax.y" /* yacc.c:1661  */
    {
           (yyval) = newTreeNode(FACTOR_SYS_FUNC_ARGS);
           (yyval)->child[1] = (yyvsp[-3]);
           (yyval)->child[2] = (yyvsp[-1]);
       }
#line 2636 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 136:
#line 592 "syntax.y" /* yacc.c:1661  */
    {
           (yyval) = newTreeNode(FACTOR_CONST);
           (yyval)->child[1] = (yyvsp[0]);
       }
#line 2645 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 137:
#line 596 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); }
#line 2651 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 138:
#line 597 "syntax.y" /* yacc.c:1661  */
    {
           (yyval) = newTreeNode(FACTOR_NOT);
           (yyval)->child[1] = (yyvsp[0]);
       }
#line 2660 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 139:
#line 601 "syntax.y" /* yacc.c:1661  */
    {
           (yyval) = newTreeNode(FACTOR_MINUS);
           (yyval)->child[1] = (yyvsp[0]);
       }
#line 2669 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 140:
#line 605 "syntax.y" /* yacc.c:1661  */
    {
           (yyval) = newTreeNode(FACTOR_ARRAY);
           (yyval)->child[1] = (yyvsp[-3]);
           (yyval)->child[2] = (yyvsp[-1]);
       }
#line 2679 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 141:
#line 610 "syntax.y" /* yacc.c:1661  */
    {
           (yyval) = newTreeNode(FACTOR_RECORD);
           (yyval)->child[1] = (yyvsp[-2]);
           (yyval)->child[2] = (yyvsp[0]);
       }
#line 2689 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 142:
#line 617 "syntax.y" /* yacc.c:1661  */
    {
              (yyval) = createList((yyvsp[-2]), (yyvsp[0]));
          }
#line 2697 "syntax.tab.c" /* yacc.c:1661  */
    break;

  case 143:
#line 620 "syntax.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 2703 "syntax.tab.c" /* yacc.c:1661  */
    break;


#line 2707 "syntax.tab.c" /* yacc.c:1661  */
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
#line 623 "syntax.y" /* yacc.c:1906  */


pTree parse(FILE * file) {
    yyin = file;
    
    yyparse();

    return root;
}

int yyerror(char* s) {
    errorno++;
	fprintf(stderr, "%s near line %d\n", s, yylineno);
}
