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
#line 5 "mini_l.y" /* yacc.c:339  */

	#define YY_NO_UNPUT

	#include <stdio.h>
	#include <stdlib.h>
	int yyerror (char* s);
	int yylex(void);
	extern int curPos;
	extern int curLine;
	extern char* yytext;
	FILE* inputFile;

#line 79 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FUNCTION = 258,
    BEGIN_PARAMS = 259,
    END_PARAMS = 260,
    BEGIN_LOCALS = 261,
    END_LOCALS = 262,
    BEGIN_BODY = 263,
    END_BODY = 264,
    INTEGER = 265,
    ARRAY = 266,
    OF = 267,
    IF = 268,
    THEN = 269,
    ENDIF = 270,
    ELSE = 271,
    WHILE = 272,
    DO = 273,
    FOREACH = 274,
    IN = 275,
    BEGINLOOP = 276,
    ENDLOOP = 277,
    CONTINUE = 278,
    READ = 279,
    WRITE = 280,
    TRUE = 281,
    FALSE = 282,
    SEMICOLON = 283,
    COLON = 284,
    COMMA = 285,
    ASSIGN = 286,
    RETURN = 287,
    AND = 288,
    OR = 289,
    NUMBER = 290,
    IDENT = 291,
    L_PAREN = 292,
    R_PAREN = 293,
    L_SQUARE_BRACKET = 294,
    R_SQUARE_BRACKET = 295,
    MULT = 296,
    DIV = 297,
    MOD = 298,
    ADD = 299,
    SUB = 300,
    LT = 301,
    LTE = 302,
    GT = 303,
    GTE = 304,
    EQ = 305,
    NEQ = 306,
    NOT = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "mini_l.y" /* yacc.c:355  */

	int val;
	char* op_val;

#line 177 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 194 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   171

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    41,    41,    42,    45,    48,    49,    51,    52,    54,
      55,    58,    59,    62,    63,    66,    69,    70,    73,    74,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    88,
      91,    92,    95,    98,   101,   104,   107,   110,   113,   116,
     117,   120,   121,   124,   125,   128,   129,   132,   133,   136,
     137,   138,   139,   142,   143,   144,   145,   146,   147,   150,
     151,   154,   155,   158,   159,   161,   162,   165,   166,   167,
     168,   169,   170,   173,   174,   175,   178,   179,   180,   183,
     184,   187,   188
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNCTION", "BEGIN_PARAMS", "END_PARAMS",
  "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER",
  "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "FOREACH",
  "IN", "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE", "TRUE",
  "FALSE", "SEMICOLON", "COLON", "COMMA", "ASSIGN", "RETURN", "AND", "OR",
  "NUMBER", "IDENT", "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET",
  "R_SQUARE_BRACKET", "MULT", "DIV", "MOD", "ADD", "SUB", "LT", "LTE",
  "GT", "GTE", "EQ", "NEQ", "NOT", "$accept", "program", "function",
  "function_chunk_a", "function_chunk_b", "function_chunk_c",
  "declaration_s", "statement_ns", "declaration", "identifier_ns",
  "arrayint", "statement", "a_statement", "b_statement", "c_statement",
  "d_statement", "e_statement", "f_statement", "g_statement",
  "h_statement", "i_statement", "var", "var_ns", "bool_expr",
  "relation_and_expr", "relation_expr", "rexpr", "comp", "expression",
  "exprsum_s", "exprsum", "multiplicative_expr", "term_s", "term",
  "upterm", "termidentifier", "termexpression", YY_NULLPTR
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
     305,   306,   307
};
# endif

#define YYPACT_NINF -68

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-68)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -20,    42,   -68,    15,   -68,   -68,    28,     0,    41,
     -68,    26,    74,    53,    54,    -1,    78,    63,   -68,    63,
      57,   -68,    98,    46,   -68,   -68,   -68,   -68,    61,   -68,
     -68,   -68,   -18,   -18,    81,    67,   -68,    71,    71,   -25,
      70,   104,    87,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,    89,    84,   -68,   -68,   -68,    23,   -18,   -12,
      95,   -68,   109,    94,   100,   -68,    96,    32,     8,   -68,
     106,    93,   121,   118,   -68,   -68,   -25,   -68,   -25,   -68,
      93,   -25,   110,    -7,   -68,   111,    88,   -68,   -68,    72,
     -18,   -18,   -68,   -68,   -68,   -68,   -68,   -68,   -25,   -25,
     -25,   -68,    32,   -25,   -25,   -25,   -68,    93,   129,   116,
      71,   115,   114,   -68,   -68,   143,   -68,   126,   119,   -68,
     -68,    93,   144,   -68,   -68,   -68,   -68,   -68,   -68,     8,
       8,     8,   136,   145,   139,   -68,   -68,   151,   -25,   -68,
     148,   -68,   -68,   -68,   -68,   -68,   -18,    93,   -68,   -68,
     -68,   -68,   142,   -68
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     0,     1,     2,     0,     0,     0,
       6,    17,     0,     0,     0,     0,     0,     0,     5,    12,
       0,     8,     0,     0,     4,    16,    11,    18,     0,    15,
       7,    10,     0,     0,     0,     0,    37,     0,     0,     0,
      39,     0,     0,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,    50,    51,    77,    39,     0,     0,
       0,    76,     0,    43,    45,    48,     0,    60,    66,    73,
       0,     0,     0,    42,    35,    36,     0,    38,     0,     9,
      14,     0,     0,     0,    75,     0,     0,    74,    47,     0,
       0,     0,    55,    57,    56,    58,    53,    54,     0,     0,
       0,    59,    62,     0,     0,     0,    65,     0,     0,     0,
       0,     0,     0,    13,    29,     0,    80,    81,     0,    52,
      78,     0,     0,    44,    46,    49,    63,    64,    61,    68,
      70,    72,     0,     0,     0,    41,    40,     0,     0,    79,
       0,    30,    67,    69,    71,    32,     0,     0,    19,    82,
      31,    33,     0,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   163,   -68,   -68,   -68,    18,   -67,   -68,   149,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -23,   -35,   -32,    76,   -68,   108,   -68,   -37,    68,
     -68,   -47,   -57,   -11,   112,   -68,    31
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     9,    16,    24,    12,    41,    13,    14,
      29,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    61,    74,    62,    63,    64,    65,    98,    66,   101,
     102,    67,   106,    68,    69,    84,   118
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      52,    70,    77,    75,   108,    10,    21,     1,    54,    55,
      56,    57,    76,   113,    73,    73,     4,    56,    57,    58,
      59,    86,   122,    56,    40,    76,    85,    59,    56,    57,
      76,   116,     8,    22,    60,    11,    11,    26,    59,   111,
     132,   112,     5,     7,   114,     1,   117,    15,    52,   103,
     104,   105,   126,   127,   140,    31,    17,    52,   123,    32,
      83,   125,    78,    33,    34,    35,    52,    27,    28,    36,
      37,    38,   142,   143,   144,   135,    99,   100,    39,    18,
     152,    19,    40,    20,    52,    32,    23,    73,   121,    33,
      34,    35,   129,   130,   131,    36,    37,    38,    52,    11,
      53,   117,    71,    72,    39,    30,    32,    40,    40,    78,
      33,    34,    35,    79,   151,    80,    36,    37,    38,    82,
      81,    54,    55,    89,    52,    39,   120,   107,    90,    40,
      56,    57,    58,    91,    92,    93,    94,    95,    96,    97,
      59,   109,    92,    93,    94,    95,    96,    97,   110,   119,
     115,   133,   134,   120,   136,   137,   138,   139,   145,   141,
     147,   148,   146,   150,   153,     6,    25,   124,    88,   149,
     128,    87
};

static const yytype_uint8 yycheck[] =
{
      23,    33,    39,    38,    71,     5,     7,     3,    26,    27,
      35,    36,    37,    80,    37,    38,    36,    35,    36,    37,
      45,    58,    89,    35,    36,    37,    58,    45,    35,    36,
      37,    38,     4,    15,    52,    36,    36,    19,    45,    76,
     107,    78,     0,    28,    81,     3,    83,     6,    71,    41,
      42,    43,    99,   100,   121,     9,    30,    80,    90,    13,
      37,    98,    39,    17,    18,    19,    89,    10,    11,    23,
      24,    25,   129,   130,   131,   110,    44,    45,    32,     5,
     147,    28,    36,    29,   107,    13,     8,   110,    16,    17,
      18,    19,   103,   104,   105,    23,    24,    25,   121,    36,
      39,   138,    21,    36,    32,     7,    13,    36,    36,    39,
      17,    18,    19,     9,   146,    28,    23,    24,    25,    35,
      31,    26,    27,    14,   147,    32,    38,    21,    34,    36,
      35,    36,    37,    33,    46,    47,    48,    49,    50,    51,
      45,    20,    46,    47,    48,    49,    50,    51,    30,    38,
      40,    22,    36,    38,    40,    12,    30,    38,    22,    15,
      21,    10,    17,    15,    22,     2,    17,    91,    60,   138,
     102,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    54,    55,    36,     0,    55,    28,     4,    56,
       5,    36,    59,    61,    62,     6,    57,    30,     5,    28,
      29,     7,    59,     8,    58,    62,    59,    10,    11,    63,
       7,     9,    13,    17,    18,    19,    23,    24,    25,    32,
      36,    60,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    39,    26,    27,    35,    36,    37,    45,
      52,    74,    76,    77,    78,    79,    81,    84,    86,    87,
      76,    21,    36,    74,    75,    75,    37,    81,    39,     9,
      28,    31,    35,    37,    88,    76,    81,    87,    79,    14,
      34,    33,    46,    47,    48,    49,    50,    51,    80,    44,
      45,    82,    83,    41,    42,    43,    85,    21,    60,    20,
      30,    81,    81,    60,    81,    40,    38,    81,    89,    38,
      38,    16,    60,    76,    77,    81,    84,    84,    82,    86,
      86,    86,    60,    22,    36,    75,    40,    12,    30,    38,
      60,    15,    85,    85,    85,    22,    17,    21,    10,    89,
      15,    76,    60,    22
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    60,    61,    62,    62,    63,    63,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    65,
      66,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    78,    78,    79,
      79,    79,    79,    80,    80,    80,    80,    80,    80,    81,
      81,    82,    82,    83,    83,    84,    84,    85,    85,    85,
      85,    85,    85,    86,    86,    86,    87,    87,    87,    88,
      88,    89,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     6,     3,     2,     3,     2,     3,
       2,     3,     2,     3,     2,     3,     3,     1,     1,     6,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       5,     6,     5,     6,     7,     2,     2,     1,     2,     1,
       4,     3,     1,     1,     3,     1,     3,     2,     1,     3,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     1,     2,     2,     2,     1,     3,     2,     3,
       2,     3,     2,     1,     2,     2,     1,     1,     3,     3,
       2,     1,     3
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
#line 41 "mini_l.y" /* yacc.c:1646  */
    { printf("program -> function program\n"); }
#line 1392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 42 "mini_l.y" /* yacc.c:1646  */
    { printf("program -> function\n"); }
#line 1398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 45 "mini_l.y" /* yacc.c:1646  */
    { printf(" FUNCTION IDENT SEMICOLON function_chunk_a function_chunk_b function_chunk_c \n"); }
#line 1404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 48 "mini_l.y" /* yacc.c:1646  */
    { printf("function_chunk_a -> BEGIN_PARAMS declaration_s END_PARAMS \n"); }
#line 1410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 49 "mini_l.y" /* yacc.c:1646  */
    { printf("function_chunk_a -> BEGIN_PARAMS END_PARAMS \n"); }
#line 1416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 51 "mini_l.y" /* yacc.c:1646  */
    { printf("function_chunk_b -> BEGIN_LOCALS declaration_s END_LOCALS\n"); }
#line 1422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 52 "mini_l.y" /* yacc.c:1646  */
    { printf("function_chunk_b -> BEGIN_LOCALS END_LOCALS\n"); }
#line 1428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 54 "mini_l.y" /* yacc.c:1646  */
    { printf("function_chunk_c -> BEGIN_BODY statement_ns END_BODY \n"); }
#line 1434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 55 "mini_l.y" /* yacc.c:1646  */
    { printf("function_chunk_c -> BEGIN_BODY END_BODY \n"); }
#line 1440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 58 "mini_l.y" /* yacc.c:1646  */
    { printf("declaration_s -> declaration semicolon declaration_s \n"); }
#line 1446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 59 "mini_l.y" /* yacc.c:1646  */
    { printf("declaration_s -> declaration\n"); }
#line 1452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 62 "mini_l.y" /* yacc.c:1646  */
    { printf("statement SEMICOLON statement_ns \n"); }
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 63 "mini_l.y" /* yacc.c:1646  */
    { printf("statement_ns -> statement SEMICOLON \n"); }
#line 1464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 66 "mini_l.y" /* yacc.c:1646  */
    { printf("declaration -> identifier_ns COLON arrayint \n"); }
#line 1470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 69 "mini_l.y" /* yacc.c:1646  */
    { printf("identifier_ns -> IDENT COMMA identifier_ns \n"); }
#line 1476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 70 "mini_l.y" /* yacc.c:1646  */
    { printf("identifier_ns -> IDENT \n"); }
#line 1482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 73 "mini_l.y" /* yacc.c:1646  */
    { printf("arrayint -> INTEGER \n"); }
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 74 "mini_l.y" /* yacc.c:1646  */
    { printf("arrayint -> ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER \n"); }
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 77 "mini_l.y" /* yacc.c:1646  */
    { printf("statement -> a_statement \n"); }
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 78 "mini_l.y" /* yacc.c:1646  */
    { printf("statement -> b_statement \n"); }
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 79 "mini_l.y" /* yacc.c:1646  */
    { printf("statement -> c_statement \n"); }
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 80 "mini_l.y" /* yacc.c:1646  */
    { printf("statement -> d_statement \n"); }
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 81 "mini_l.y" /* yacc.c:1646  */
    { printf("statement -> e_statement \n"); }
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 82 "mini_l.y" /* yacc.c:1646  */
    { printf("statement -> f_statement \n"); }
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 83 "mini_l.y" /* yacc.c:1646  */
    { printf("statement -> g_statement \n"); }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 84 "mini_l.y" /* yacc.c:1646  */
    { printf("statement -> h_statement \n"); }
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 85 "mini_l.y" /* yacc.c:1646  */
    { printf("statement -> i_statement \n"); }
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 88 "mini_l.y" /* yacc.c:1646  */
    { printf("a_statement -> var ASSIGN expression \n"); }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 91 "mini_l.y" /* yacc.c:1646  */
    { printf("b_statement -> IF bool_expr THEN statement_ns ENDIF \n"); }
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 92 "mini_l.y" /* yacc.c:1646  */
    { printf("b_statement -> IF bool_expr THEN ELSE statement_ns ENDIF \n"); }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 95 "mini_l.y" /* yacc.c:1646  */
    { printf("c_statement -> WHILE bool_expr BEGINLOOP statement_ns ENDLOOP \n"); }
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 98 "mini_l.y" /* yacc.c:1646  */
    { printf("d_statement -> DO BEGINLOOP statement_ns ENDLOOP WHILE bool_expr \n"); }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 101 "mini_l.y" /* yacc.c:1646  */
    { printf("e_statement -> FOREACH IDENT IN IDENT BEGINLOOP statement_ns ENDLOOP \n"); }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 104 "mini_l.y" /* yacc.c:1646  */
    { printf("f_statement -> READ var_ns \n"); }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 107 "mini_l.y" /* yacc.c:1646  */
    { printf("g_statement -> WRITE var_ns \n"); }
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 110 "mini_l.y" /* yacc.c:1646  */
    { printf("h_statement -> CONTINUE \n"); }
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 113 "mini_l.y" /* yacc.c:1646  */
    { printf("i_statement -> RETURN expression \n"); }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 116 "mini_l.y" /* yacc.c:1646  */
    { printf("var -> IDENT \n"); }
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 117 "mini_l.y" /* yacc.c:1646  */
    { printf("var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET \n"); }
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 120 "mini_l.y" /* yacc.c:1646  */
    { printf("var_ns -> var COMMA var_ns \n"); }
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 121 "mini_l.y" /* yacc.c:1646  */
    { printf("var_ns -> var \n"); }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 124 "mini_l.y" /* yacc.c:1646  */
    { printf("bool_expr -> relation_and_expr \n"); }
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 125 "mini_l.y" /* yacc.c:1646  */
    { printf("bool_expr -> relation_and_expr OR bool_expr \n"); }
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 128 "mini_l.y" /* yacc.c:1646  */
    { printf("relation_and_expr -> relation_expr \n"); }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 129 "mini_l.y" /* yacc.c:1646  */
    { printf("relation_and_expr -> relation_expr AND relation_and_expr \n"); }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 132 "mini_l.y" /* yacc.c:1646  */
    { printf("relation_expr -> NOT rexpr \n"); }
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 133 "mini_l.y" /* yacc.c:1646  */
    { printf("relation_expr -> rexpr \n"); }
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 136 "mini_l.y" /* yacc.c:1646  */
    { printf("rexpr -> expression comp expression \n"); }
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 137 "mini_l.y" /* yacc.c:1646  */
    { printf("rexpr -> TRUE \n"); }
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 138 "mini_l.y" /* yacc.c:1646  */
    { printf("rexpr -> FALSE \n"); }
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 139 "mini_l.y" /* yacc.c:1646  */
    { printf("rexpr -> L_PAREN bool_expr R_PAREN \n"); }
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 142 "mini_l.y" /* yacc.c:1646  */
    { printf("comp -> EQ \n"); }
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 143 "mini_l.y" /* yacc.c:1646  */
    { printf("comp -> NEQ \n"); }
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 144 "mini_l.y" /* yacc.c:1646  */
    { printf("comp -> LT \n"); }
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 145 "mini_l.y" /* yacc.c:1646  */
    { printf("comp -> GT \n"); }
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 146 "mini_l.y" /* yacc.c:1646  */
    { printf("comp -> LTE \n"); }
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 147 "mini_l.y" /* yacc.c:1646  */
    { printf("comp -> GTE \n"); }
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 150 "mini_l.y" /* yacc.c:1646  */
    { printf("expression -> multiplicative_expr exprsum_s \n"); }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 151 "mini_l.y" /* yacc.c:1646  */
    { printf("expression -> multiplicative_expr \n"); }
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 154 "mini_l.y" /* yacc.c:1646  */
    { printf("exprsum_s -> exprsum exprsum_s \n"); }
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 155 "mini_l.y" /* yacc.c:1646  */
    { printf("exprsum_s -> exprsum \n"); }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 158 "mini_l.y" /* yacc.c:1646  */
    { printf("exprsum -> ADD multiplicative_expr \n"); }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 159 "mini_l.y" /* yacc.c:1646  */
    { printf("exprsum -> SUB multiplicative_expr \n"); }
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 161 "mini_l.y" /* yacc.c:1646  */
    { printf("multiplicative_expr -> term term_s \n"); }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 162 "mini_l.y" /* yacc.c:1646  */
    { printf("multiplicative_expr -> term \n"); }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 165 "mini_l.y" /* yacc.c:1646  */
    { printf("term_s -> MULT term term_s \n"); }
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 166 "mini_l.y" /* yacc.c:1646  */
    { printf("term_s -> MULT term \n"); }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 167 "mini_l.y" /* yacc.c:1646  */
    { printf("term_s -> DIV term term_s \n"); }
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 168 "mini_l.y" /* yacc.c:1646  */
    { printf("term_s -> DIV term \n"); }
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 169 "mini_l.y" /* yacc.c:1646  */
    { printf("term_s -> MOD term term_s \n"); }
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 170 "mini_l.y" /* yacc.c:1646  */
    { printf("term_s -> MOD term \n"); }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 173 "mini_l.y" /* yacc.c:1646  */
    { printf("term -> upterm \n"); }
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 174 "mini_l.y" /* yacc.c:1646  */
    { printf("term -> SUB upterm \n"); }
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 175 "mini_l.y" /* yacc.c:1646  */
    { printf("term -> IDENT termidentifier \n"); }
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 178 "mini_l.y" /* yacc.c:1646  */
    { printf("upterm -> var \n"); }
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 179 "mini_l.y" /* yacc.c:1646  */
    { printf("upterm -> NUMBER \n"); }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 180 "mini_l.y" /* yacc.c:1646  */
    { printf("upterm -> L_PAREN expression R_PAREN \n"); }
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 183 "mini_l.y" /* yacc.c:1646  */
    { printf("termidentifier -> L_PAREN termexpression R_PAREN \n"); }
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 184 "mini_l.y" /* yacc.c:1646  */
    { printf("termidentifier -> L_PAREN R_PAREN \n"); }
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 187 "mini_l.y" /* yacc.c:1646  */
    { printf("termexpression -> expression \n"); }
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 188 "mini_l.y" /* yacc.c:1646  */
    { printf("termexpression -> expression COMMA termexpression \n"); }
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1876 "y.tab.c" /* yacc.c:1646  */
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
#line 190 "mini_l.y" /* yacc.c:1906  */


int main(int argc, char ** argv) {
  if(argc > 1) {
      inputFile = fopen(argv[1], "r");
      if(!inputFile) {
         inputFile = stdin;
      }
   }
   else {
      inputFile = stdin;
   }
   
   yyparse();
  
  return 0;
}

int yyerror(char* s) {
  printf("Error at line %d, column %d: Error at \"%s\" \n", curLine, curPos, s);
  exit(1);
}

