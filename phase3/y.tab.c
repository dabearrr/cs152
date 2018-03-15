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
	#include "Vars.h"
	#include "MilCode.h"
	#include "SymbolTable.h"
	#include "Attribute.h"
	#include "Utils.h"
	
	#include <iostream>
	#include <fstream>
	#include <vector>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string>
	#include <typeinfo>
	#include <map>
	#include <stack>
	#include <regex>
	
	using namespace std;
	
	int yyerror (const char* s);
	int yylex(void);
	string intToString(int x);
	void printCode();
	string charToString(char*);
	void p(string);
	void pushToOutputAndClear();
	string checkForExtraSpace(string);
	
	struct Function {
		string name;
		Function() : name() {}
		Function(string n) : name(n){}
	};
	
	enum symbol_type {INT, INTARRAY, FUNC};
	struct Symbol {
		int val;
		int size;
		string name;
		symbol_type type;
		
		Symbol() : val(0), size(0), name(), type() {}
		Symbol(int iv, int is, string sn, symbol_type st) : val(iv), size(is), name(sn), type(st) {}
		
	};
	
	void addFunction(Function);
	void addSymbol(Symbol);
	
	void checkDeclaredFunction(string);
	void checkDeclaredSymbol(string);
	
	extern int curPos;
	extern int curLine;
	extern char* yytext;
	FILE* inputFile;
	int val;
	char* op_val;
	
	int testCounter = 0;
	vector<string> codeToWrite;
	MilCode mc;
	Utils utils;
	Vars tempGen;
	
	int ATTR_INTEGER_TYPE = 0;
	int ATTR_LIST_TYPE = 1;
	int ATTR_FUNC_TYPE = 2;
	int NUMBER_TYPE = 3;
	
	stack<string> identStack;
	stack<string> varStack;
	stack<string> expStack;
	stack<string> paramStack;
	stack<string> labelStack;
	
	stringstream codeStream;
	ostringstream outputCodeStream;
	
	int paramCount = 0;
	
	map<string, Function> functionTable;
	map<string, Symbol> symbolTable;
	bool mainExists = false;

#line 154 "y.tab.c" /* yacc.c:339  */

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
    L_PAREN = 290,
    R_PAREN = 291,
    L_SQUARE_BRACKET = 292,
    R_SQUARE_BRACKET = 293,
    MULT = 294,
    DIV = 295,
    MOD = 296,
    ADD = 297,
    SUB = 298,
    LT = 299,
    LTE = 300,
    GT = 301,
    GTE = 302,
    EQ = 303,
    NEQ = 304,
    NOT = 305,
    NUMBER = 306,
    IDENT = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 93 "mini_l.y" /* yacc.c:355  */

  int val;
  char* op_val;
  Attribute* attr;

#line 253 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 270 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   166

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
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
static const yytype_uint16 yyrline[] =
{
       0,   120,   120,   122,   123,   126,   126,   126,   148,   149,
     152,   153,   156,   168,   182,   186,   189,   198,   198,   214,
     214,   242,   242,   256,   259,   272,   285,   295,   304,   314,
     337,   338,   338,   347,   348,   353,   359,   365,   371,   377,
     381,   389,   396,   403,   410,   416,   417,   418,   419,   420,
     421,   424,   431,   438,   445,   452,   459,   466,   473,   502,
     518,   535,   549,   561,   562,   576,   586,   589
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
  "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "MULT",
  "DIV", "MOD", "ADD", "SUB", "LT", "LTE", "GT", "GTE", "EQ", "NEQ", "NOT",
  "NUMBER", "IDENT", "$accept", "start_here", "program", "function", "$@1",
  "$@2", "declaration_s", "statement_ns", "declaration", "identifier_ns",
  "statement", "$@3", "$@4", "$@5", "var", "else_ns", "$@6", "var_ns",
  "bool_expr", "relation_and_expr", "relation_expr", "rexpr", "comp",
  "expression", "multiplicative_expr", "term", "exp_s", YY_NULLPTR
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

#define YYPACT_NINF -85

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-85)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,   -29,    26,   -85,    13,   -85,   -85,   -85,     1,    27,
     -20,    14,   -85,    25,    22,    36,    70,   -20,    14,    47,
      73,   -85,   -85,   -85,    52,   -20,    33,    88,    58,    91,
      99,    24,   103,    42,    42,    93,    63,   -85,    66,    66,
       3,    85,   111,    95,   108,   -85,   -85,   -85,    42,     0,
      74,   -85,   -18,   -85,   -10,   107,   -85,   -85,    89,    65,
     -85,    -7,   -85,   104,   112,   112,     3,   -85,     3,   -85,
      24,     3,    54,    83,     3,   -85,   -85,   -85,   -30,   -85,
      42,    42,   -85,   -85,   -85,   -85,   -85,   -85,     3,     3,
       3,     3,     3,     3,   -85,    24,    92,    66,   -85,   -85,
     105,   109,   -85,   -85,   -85,   -85,   110,   -85,   113,    24,
     107,   -85,   -85,   -85,   -85,   -85,    21,    21,    24,   117,
     127,   112,   -85,   -85,     3,   114,   121,   123,    24,    24,
     -85,   113,   -85,    24,    24,   130,   125,   -85,   138,   133,
     139,    24,   -85,   142,   -85,    42,   136,    24,   -85,   126,
     -85,   131,    24,   -85
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     3,     5,     1,     4,     0,     0,
       8,    15,     6,     0,     0,     0,     0,     8,    15,     0,
       0,     9,    14,    12,     0,     8,     0,     0,     0,     0,
       0,    10,     0,     0,     0,     0,     0,    26,     0,     0,
       0,    28,     0,     0,     0,    13,    42,    43,     0,     0,
       0,    61,    28,    59,     0,    36,    38,    39,     0,    53,
      57,     0,    21,     0,    33,    33,     0,    27,     0,     7,
      10,     0,     0,     0,     0,    60,    58,    40,     0,    17,
       0,     0,    47,    49,    48,    50,    45,    46,     0,     0,
       0,     0,     0,     0,    19,     0,     0,     0,    24,    25,
       0,     0,    11,    16,    44,    63,     0,    65,    67,     0,
      35,    37,    41,    54,    55,    56,    51,    52,     0,     0,
       0,    33,    29,    62,     0,     0,     0,     0,    10,     0,
      34,    67,    64,    10,    10,     0,     0,    66,    30,     0,
       0,    10,    31,     0,    20,     0,     0,     0,    18,    22,
      23,     0,    10,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -85,   -85,   157,   -85,   -85,   -85,    -5,   -61,   -85,   144,
     -84,   -85,   -85,   -85,   -31,   -85,   -85,   -62,   -33,    84,
      82,   115,   -85,   -38,   -22,    -8,    35
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     8,    16,    12,    42,    13,    15,
      43,   109,   118,    95,    53,   143,   147,    98,    54,    55,
      56,    57,    88,    58,    59,    60,   125
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      44,    61,    67,    99,    79,    66,   107,    64,    65,   102,
      73,   119,    21,    49,    94,    72,     1,    78,    76,    68,
      27,    51,    52,     5,    80,   126,     6,    80,   100,     9,
     101,    10,    11,   103,   127,    74,   106,    33,    66,    44,
     108,    34,    35,    36,    14,   136,    49,    37,    38,    39,
     112,    75,    41,    17,    51,    52,    40,    23,    24,   130,
      89,    90,    91,   151,    44,    19,   121,   135,    46,    47,
     116,   117,   138,   139,    18,    20,    41,    48,    44,    25,
     146,   113,   114,   115,    28,    49,   131,    44,    80,    26,
     104,   153,    50,    51,    52,    29,    30,    44,    44,    31,
      46,    47,    44,    44,    89,    90,    91,    92,    93,    48,
      44,    32,   149,    45,    62,    63,    44,    49,    41,   105,
      69,    44,    68,    70,    96,    51,    52,    82,    83,    84,
      85,    86,    87,    82,    83,    84,    85,    86,    87,    71,
      81,   105,    97,   124,   120,   128,   123,   122,   129,   133,
     132,   134,   140,   141,   142,   144,   145,   148,   150,   152,
      80,     7,    22,   111,   110,    77,   137
};

static const yytype_uint8 yycheck[] =
{
      31,    34,    40,    65,    14,    35,    36,    38,    39,    70,
      48,    95,    17,    43,    21,    48,     3,    35,    49,    37,
      25,    51,    52,    52,    34,   109,     0,    34,    66,    28,
      68,     4,    52,    71,   118,    35,    74,    13,    35,    70,
      78,    17,    18,    19,    30,   129,    43,    23,    24,    25,
      88,    51,    52,    28,    51,    52,    32,    10,    11,   121,
      39,    40,    41,   147,    95,    29,    97,   128,    26,    27,
      92,    93,   133,   134,    52,     5,    52,    35,   109,     6,
     141,    89,    90,    91,    51,    43,   124,   118,    34,    37,
      36,   152,    50,    51,    52,     7,    38,   128,   129,     8,
      26,    27,   133,   134,    39,    40,    41,    42,    43,    35,
     141,    12,   145,    10,    21,    52,   147,    43,    52,    36,
       9,   152,    37,    28,    20,    51,    52,    44,    45,    46,
      47,    48,    49,    44,    45,    46,    47,    48,    49,    31,
      33,    36,    30,    30,    52,    28,    36,    38,    21,    28,
      36,    28,    22,    28,    16,    22,    17,    15,    22,    28,
      34,     4,    18,    81,    80,    50,   131
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    54,    55,    56,    52,     0,    55,    57,    28,
       4,    52,    59,    61,    30,    62,    58,    28,    52,    29,
       5,    59,    62,    10,    11,     6,    37,    59,    51,     7,
      38,     8,    12,    13,    17,    18,    19,    23,    24,    25,
      32,    52,    60,    63,    67,    10,    26,    27,    35,    43,
      50,    51,    52,    67,    71,    72,    73,    74,    76,    77,
      78,    71,    21,    52,    67,    67,    35,    76,    37,     9,
      28,    31,    71,    76,    35,    51,    67,    74,    35,    14,
      34,    33,    44,    45,    46,    47,    48,    49,    75,    39,
      40,    41,    42,    43,    21,    66,    20,    30,    70,    70,
      76,    76,    60,    76,    36,    36,    76,    36,    76,    64,
      72,    73,    76,    78,    78,    78,    77,    77,    65,    63,
      52,    67,    38,    36,    30,    79,    63,    63,    28,    21,
      70,    76,    36,    28,    28,    60,    63,    79,    60,    60,
      22,    28,    16,    68,    22,    17,    60,    69,    15,    71,
      22,    63,    28,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    57,    58,    56,    59,    59,
      60,    60,    61,    61,    62,    62,    63,    64,    63,    65,
      63,    66,    63,    63,    63,    63,    63,    63,    67,    67,
      68,    69,    68,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    74,    74,    75,    75,    75,    75,    75,
      75,    76,    76,    76,    77,    77,    77,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     0,     0,    14,     0,     3,
       0,     3,     4,     9,     3,     0,     3,     0,     9,     0,
       8,     0,     9,     9,     3,     3,     1,     2,     1,     4,
       0,     0,     5,     0,     3,     3,     1,     3,     1,     1,
       2,     3,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     3,     3,     3,     1,     2,     1,
       2,     1,     4,     3,     5,     3,     3,     0
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
#line 120 "mini_l.y" /* yacc.c:1646  */
    { if (!mainExists) { yyerror("Error: main does not exist"); } }
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 126 "mini_l.y" /* yacc.c:1646  */
    { codeStream << "func " << (yyvsp[0].op_val) << endl; }
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 126 "mini_l.y" /* yacc.c:1646  */
    {
	while(!paramStack.empty()) {
		codeStream << "= " << paramStack.top() << ", " << "$" << paramCount++ << endl;
		paramStack.pop();
	}
}
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 132 "mini_l.y" /* yacc.c:1646  */
    {
	outputCodeStream << "endfunc\n";
	symbolTable.clear();
	if (utils.charToString((yyvsp[-12].op_val)) == "main") {
		mainExists = true;
	}
	
	Function f((yyvsp[-12].op_val));
	addFunction(f);
	while(!paramStack.empty()) {
		paramStack.pop();
	}
	
}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 156 "mini_l.y" /* yacc.c:1646  */
    {
		identStack.push((yyvsp[-3].op_val));
		paramStack.push((yyvsp[-3].op_val));
		
		while(!identStack.empty()) {
			string temp = identStack.top();
			Symbol tempSymbol(0, 0, temp, INT);
			addSymbol(tempSymbol);
			codeStream << ". " << temp << endl;
			identStack.pop();
		}
}
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 168 "mini_l.y" /* yacc.c:1646  */
    {
		identStack.push((yyvsp[-8].op_val));
		paramStack.push((yyvsp[-8].op_val));
		
		while(!identStack.empty()) {
			string temp = identStack.top();
			Symbol tempSymbol(0, (yyvsp[-3].val), temp, INTARRAY);
			addSymbol(tempSymbol);
			codeStream << ".[] " << temp << ", " << (yyvsp[-3].val) << endl;
			identStack.pop();
		}
}
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 182 "mini_l.y" /* yacc.c:1646  */
    {
	identStack.push((yyvsp[-1].op_val));
	paramStack.push((yyvsp[-1].op_val));
}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 189 "mini_l.y" /* yacc.c:1646  */
    {
	if ((yyvsp[-2].attr)->type == ATTR_INTEGER_TYPE) {
		codeStream << mc.copyElement((yyvsp[-2].attr)->name, (yyvsp[0].attr)->name) << endl;
	} else {
		codeStream << mc.arrayAccessAssignTo((yyvsp[-2].attr)->name, (yyvsp[-2].attr)->index, (yyvsp[0].attr)->name) << endl;
	}
	
	pushToOutputAndClear();
}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 198 "mini_l.y" /* yacc.c:1646  */
    {
	string st = tempGen.getLabel();
	string en = tempGen.getLabel();
	labelStack.push(en);
	
	codeStream << mc.condGotoLabel(st, (yyvsp[-1].attr)->name) << endl;
	codeStream << mc.gotoLabel(en) << endl;
	codeStream << mc.label(st) << endl;

}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 208 "mini_l.y" /* yacc.c:1646  */
    {
	codeStream << mc.label(labelStack.top()) << endl;
	labelStack.pop();
	
	pushToOutputAndClear();
}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 214 "mini_l.y" /* yacc.c:1646  */
    {
	string cond = tempGen.getLabel();
	string endLabel = tempGen.getLabel();
	string start = tempGen.getLabel();
	outputCodeStream << mc.label(start) << endl;
	
	pushToOutputAndClear();
	
	codeStream << mc.condGotoLabel(cond, (yyvsp[-1].attr)->name) << endl;
	codeStream << mc.gotoLabel(endLabel) << endl;
	codeStream << mc.label(cond) << endl;
	
	labelStack.push(start);
	labelStack.push(endLabel);
}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 229 "mini_l.y" /* yacc.c:1646  */
    {
	pushToOutputAndClear();
	
	string endLabel = labelStack.top();
	labelStack.pop();
	string start = labelStack.top();
	labelStack.pop();
	
	codeStream << mc.gotoLabel(start) << endl;
	codeStream << mc.label(endLabel) << endl;
	
	pushToOutputAndClear();
}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 242 "mini_l.y" /* yacc.c:1646  */
    {
	string start = tempGen.getLabel();
	labelStack.push(start);
	
	outputCodeStream << mc.label(start) << endl;
	pushToOutputAndClear();
}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 249 "mini_l.y" /* yacc.c:1646  */
    {
	string start = labelStack.top();
	codeStream << mc.condGotoLabel(start, (yyvsp[0].attr)->name) << endl;
	labelStack.pop();
	
	pushToOutputAndClear();
}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 256 "mini_l.y" /* yacc.c:1646  */
    {
				//give up
}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 259 "mini_l.y" /* yacc.c:1646  */
    {
	varStack.push((yyvsp[-1].attr)->name);
	while(!varStack.empty()) {
		if((yyvsp[-1].attr)->type == ATTR_INTEGER_TYPE) {
			codeStream << mc.readIntoDest(varStack.top()) << endl;
			varStack.pop();
		} else {
			codeStream << mc.readIntoDestArray(varStack.top(), (yyvsp[-1].attr)->index) << endl;
			varStack.pop();
		}
	pushToOutputAndClear();
	}
}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 272 "mini_l.y" /* yacc.c:1646  */
    {
	varStack.push((yyvsp[-1].attr)->name);
	while(!varStack.empty()) {
		if((yyvsp[-1].attr)->type == ATTR_INTEGER_TYPE) {
			codeStream << mc.writeSourceToOut(varStack.top()) << endl;
			varStack.pop();
		} else {
			codeStream << mc.writeSourceArrayToOut(varStack.top(), (yyvsp[-1].attr)->index) << endl;
			varStack.pop();
		}
	pushToOutputAndClear();
	}
}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 285 "mini_l.y" /* yacc.c:1646  */
    { 
	if(!labelStack.empty()) {
		codeStream << mc.gotoLabel(labelStack.top()) << endl;
		outputCodeStream << codeStream.rdbuf();
		codeStream.clear();
		codeStream.str(" ");
	} else {
		yyerror("Cannot use CONTINUE outside of a loop");
	}
}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 295 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	(yyval.attr)->number_val = (yyvsp[0].attr)->number_val;
	(yyval.attr)->name = (yyvsp[0].attr)->name;
	codeStream << mc.ret((yyvsp[0].attr)->name) << endl;
	pushToOutputAndClear();
}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 304 "mini_l.y" /* yacc.c:1646  */
    {
	checkDeclaredSymbol((yyvsp[0].op_val));
	if (symbolTable[(yyvsp[0].op_val)].type == INTARRAY) {
		yyerror("Symbol is actually an int array type");
	}
	(yyval.attr) = new Attribute();
	(yyval.attr)->type = ATTR_INTEGER_TYPE;
	(yyval.attr)->name = utils.charToString((yyvsp[0].op_val));
	p("var here: " + (yyval.attr)->toString());
}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 314 "mini_l.y" /* yacc.c:1646  */
    {
	
	if (symbolTable[(yyvsp[-3].op_val)].type == INT) {
		yyerror("Symbol is actually an int type");
	}
	if((yyvsp[-1].attr)->type == ATTR_LIST_TYPE) {
		string temp = tempGen.getTemp();
		(yyval.attr) = new Attribute();
		(yyval.attr)->type = ATTR_LIST_TYPE;
		(yyval.attr)->index = temp;
		(yyval.attr)->name = utils.charToString((yyvsp[-3].op_val));
		
		codeStream << mc.varName(temp) << endl;
		codeStream << mc.arrayAccessAssignFrom(temp, (yyvsp[-1].attr)->name, (yyvsp[-1].attr)->index) << endl;
	} else {
		(yyval.attr) = new Attribute();
		(yyval.attr)->name = utils.charToString((yyvsp[-3].op_val));
		(yyval.attr)->type = ATTR_LIST_TYPE;
		(yyval.attr)->index = (yyvsp[-1].attr)->name;
	}
}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 338 "mini_l.y" /* yacc.c:1646  */
    {
			string label = tempGen.getLabel();
			codeStream << mc.gotoLabel(label) << endl;
			codeStream << mc.label(labelStack.top()) << endl;
			labelStack.pop();
			labelStack.push(label);
		}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 348 "mini_l.y" /* yacc.c:1646  */
    {
	varStack.push((yyvsp[-1].attr)->name);
}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 353 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	string temp = tempGen.getTemp();
	(yyval.attr)->name = temp;
	codeStream << mc.logicalBinary("||", temp, (yyvsp[-2].attr)->name, (yyvsp[0].attr)->name) << endl;
}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 359 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	(yyval.attr)->name = (yyvsp[0].attr)->name;
}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 365 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	string temp = tempGen.getTemp();
	(yyval.attr)->name = temp;
	codeStream << mc.logicalBinary("&&", temp, (yyvsp[-2].attr)->name, (yyvsp[0].attr)->name) << endl;
}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 371 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	(yyval.attr)->name = (yyvsp[0].attr)->name;
}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 377 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	(yyval.attr)->name = (yyvsp[0].attr)->name;
}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 381 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	string temp = tempGen.getTemp();
	(yyval.attr)->name = temp;
	codeStream << mc.logicalNot(temp, (yyvsp[0].attr)->name) << endl;
}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 389 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	string temp = tempGen.getTemp();
	(yyval.attr)->name = temp;
	codeStream << mc.varName(temp) << endl;
	codeStream << mc.logicalBinary((yyvsp[-1].op_val), temp, (yyvsp[-2].attr)->name, (yyvsp[0].attr)->name) << endl;
}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 396 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	string temp = tempGen.getTemp();
	(yyval.attr)->name = temp;
	codeStream << mc.varName(temp) << endl;
	codeStream << mc.copyElement(temp, "1") << endl;
}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 403 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	string temp = tempGen.getTemp();
	(yyval.attr)->name = temp;
	codeStream << mc.varName(temp) << endl;
	codeStream << mc.copyElement(temp, "0") << endl;
}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 410 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	(yyval.attr)->name = (yyvsp[-1].attr)->name;
}
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 416 "mini_l.y" /* yacc.c:1646  */
    { (yyval.op_val) = const_cast<char*>("=="); }
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 417 "mini_l.y" /* yacc.c:1646  */
    { (yyval.op_val) = const_cast<char*>("!="); }
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 418 "mini_l.y" /* yacc.c:1646  */
    { (yyval.op_val) = const_cast<char*>("<"); }
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 419 "mini_l.y" /* yacc.c:1646  */
    { (yyval.op_val) = const_cast<char*>(">"); }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 420 "mini_l.y" /* yacc.c:1646  */
    { (yyval.op_val) = const_cast<char*>("<="); }
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 421 "mini_l.y" /* yacc.c:1646  */
    { (yyval.op_val) = const_cast<char*>(">="); }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 424 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	string temp = tempGen.getTemp();
	codeStream << mc.varName(temp) << endl;
	codeStream << mc.arithmatic("+", temp, (yyvsp[-2].attr)->name, (yyvsp[0].attr)->name) << endl;
	(yyval.attr)->name = temp;
}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 431 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	string temp = tempGen.getTemp();
	codeStream << mc.varName(temp) << endl;
	codeStream << mc.arithmatic("-", temp, (yyvsp[-2].attr)->name, (yyvsp[0].attr)->name) << endl;
	(yyval.attr)->name = temp;
}
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 438 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	(yyval.attr)->name = (yyvsp[0].attr)->name;
	(yyvsp[0].attr)->type = (yyvsp[0].attr)->type;
}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 445 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	string temp = tempGen.getTemp();
	codeStream << mc.varName(temp) << endl;
	codeStream << mc.arithmatic("*", temp, (yyvsp[-2].attr)->name, (yyvsp[0].attr)->name) << endl;
	(yyval.attr)->name = temp;
}
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 452 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	string temp = tempGen.getTemp();
	codeStream << mc.varName(temp) << endl;
	codeStream << mc.arithmatic("/", temp, (yyvsp[-2].attr)->name, (yyvsp[0].attr)->name) << endl;
	(yyval.attr)->name = temp;
}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 459 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	string temp = tempGen.getTemp();
	codeStream << mc.varName(temp) << endl;
	codeStream << mc.arithmatic("%", temp, (yyvsp[-2].attr)->name, (yyvsp[0].attr)->name) << endl;
	(yyval.attr)->name = temp;
}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 466 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	(yyval.attr)->name = (yyvsp[0].attr)->name;
	(yyvsp[0].attr)->type = (yyvsp[0].attr)->type;
}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 473 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	(yyval.attr)->number_val = (yyvsp[0].attr)->number_val * -1;
	(yyval.attr)->type = (yyvsp[0].attr)->type;
	if ((yyvsp[0].attr)->type != ATTR_LIST_TYPE) {
		string tempZero = tempGen.getTemp();
		string tempNum = tempGen.getTemp();;
		codeStream << mc.varName(tempZero) << endl;
		codeStream << mc.copyElement(tempZero, "0") << endl;
		codeStream << mc.varName(tempNum) << endl;
		codeStream << mc.copyElement(tempNum, (yyvsp[0].attr)->name) << endl;
		
		(yyval.attr)->name = tempGen.getTemp();
		codeStream << mc.varName((yyval.attr)->name) << endl;
		codeStream << mc.arithmatic("-", (yyval.attr)->name, tempZero, tempNum) << endl;
	} else {
		string tempZero = tempGen.getTemp();
		string tempNum = tempGen.getTemp();
		codeStream << mc.varName(tempZero) << endl;
		codeStream << mc.copyElement(tempZero, "0") << endl;
		codeStream << mc.varName(tempNum) << endl;
		codeStream << mc.arrayAccessAssignFrom(tempNum, (yyvsp[0].attr)->name, (yyvsp[0].attr)->index) << endl;
		
		(yyval.attr)->name = tempGen.getTemp();
		codeStream << mc.varName((yyval.attr)->name) << endl;
		codeStream << mc.arithmatic("-", (yyval.attr)->name, tempZero, tempNum) << endl;
		
	}
}
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 502 "mini_l.y" /* yacc.c:1646  */
    { 
	p("term, var: " + (yyvsp[0].attr)->toString());
	(yyval.attr) = new Attribute();
	(yyval.attr)->number_val = (yyvsp[0].attr)->number_val;
	(yyval.attr)->type = (yyvsp[0].attr)->type;
	if((yyvsp[0].attr)->type != ATTR_LIST_TYPE) {
		(yyval.attr)->name = tempGen.getTemp();
		(yyval.attr)->index = (yyval.attr)->name;
		codeStream << mc.varName((yyval.attr)->name) << endl;
		codeStream << mc.copyElement((yyval.attr)->name, (yyvsp[0].attr)->name) << endl;
	} else {
		(yyval.attr)->name = tempGen.getTemp();
		codeStream << mc.varName((yyval.attr)->name) << endl;
		codeStream << mc.arrayAccessAssignFrom((yyval.attr)->name, (yyvsp[0].attr)->name, (yyvsp[0].attr)->index) << endl;
	}
}
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 518 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	(yyval.attr)->number_val = (yyvsp[0].val) * -1;
	(yyval.attr)->type = ATTR_INTEGER_TYPE;
	string tempZero = tempGen.getTemp();
	string tempNum = tempGen.getTemp();
	
	codeStream << mc.varName(tempZero) << endl;
	codeStream << mc.copyElement(tempZero, "0") << endl;
	codeStream << mc.varName(tempNum) << endl;
	codeStream << mc.copyElement(tempNum, (yyvsp[0].val)) << endl;
	
	(yyval.attr)->name = tempGen.getTemp();
	codeStream << mc.varName((yyval.attr)->name) << endl;
	codeStream << mc.copyElement((yyval.attr)->name, (yyval.attr)->number_val) << endl;
	
		}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 535 "mini_l.y" /* yacc.c:1646  */
    { 
	p("NUMBER, value is: " + utils.intToString((yyvsp[0].val)));
	(yyval.attr) = new Attribute();
	(yyval.attr)->number_val = (yyvsp[0].val); 
	(yyval.attr)->type = ATTR_INTEGER_TYPE;
	
	(yyval.attr)->name = tempGen.getTemp();
	(yyval.attr)->index = (yyval.attr)->name;
	
	(yyval.attr)->list.push_back(utils.intToString((yyvsp[0].val)));
	
	codeStream << mc.varName((yyval.attr)->name) << endl;
	codeStream << mc.copyElement((yyval.attr)->name, (yyval.attr)->number_val) << endl;
}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 549 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.attr) = new Attribute();
	string tempZero = tempGen.getTemp();
	
	codeStream << mc.varName(tempZero) << endl;
	codeStream << mc.copyElement(tempZero, "0") << endl;
	
	(yyval.attr)->name = tempGen.getTemp();
	
	codeStream << mc.varName((yyval.attr)->name) << endl;
	codeStream << mc.arithmatic("-", (yyval.attr)->name, tempZero, (yyvsp[-1].attr)->name) << endl;
}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 561 "mini_l.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attribute() ; (yyval.attr)->name = (yyvsp[-1].attr)->name; }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 562 "mini_l.y" /* yacc.c:1646  */
    {
	// check for function
	(yyval.attr) = new Attribute();
	expStack.push((yyvsp[-2].attr)->name);
	while(!expStack.empty()) {
		codeStream << mc.param(expStack.top()) << endl;
		expStack.pop();
	}
	
	string temp = tempGen.getTemp();
	codeStream << mc.varName(temp) << endl;
	codeStream << mc.call((yyvsp[-4].op_val), temp) << endl;
	(yyval.attr)->name = temp;
}
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 576 "mini_l.y" /* yacc.c:1646  */
    {
	// check for function
	(yyval.attr) = new Attribute();
	string temp = tempGen.getTemp();
	codeStream << mc.varName(temp) << endl;
	codeStream << mc.call((yyvsp[-2].op_val), temp) << endl;
	(yyval.attr)->name = temp;
}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 586 "mini_l.y" /* yacc.c:1646  */
    {
                   expStack.push((yyvsp[-1].attr)->name); 
                 }
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2151 "y.tab.c" /* yacc.c:1646  */
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
#line 591 "mini_l.y" /* yacc.c:1906  */


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
   
	p("before yyparse\n");
	yyparse();
	p("after yyparse\n");
	
	string theCode = outputCodeStream.str();
	
	cout << "Code is: " << theCode << endl;

	ofstream file;
	file.open("mil_code.mil");
	file << theCode;
	file.close();
  
  return 0;
}

int yyerror(const char* s) {
  printf("Error at line %d, column %d: Error is: \"%s\" \n", curLine, curPos, s);
  exit(1);
  return 0;
}

void p(string log) {
	cout << "Logger #" << testCounter++ << " " << log << endl;
}

void checkDeclaredFunction(string f) {
	if(functionTable.find(f) == functionTable.end()) {
		string error = "Function " + f + " has not been declared";
		yyerror(error.c_str());
	}
}
void checkDeclaredSymbol(string s) {
	if(symbolTable.find(s) == symbolTable.end()) {
		string error = "Symbol " + s + " has not been declared";
		yyerror(error.c_str());
	}
}

void addFunction(Function f) {
	if(functionTable.find(f.name) == functionTable.end()) {
		functionTable[f.name] = f;
	} else {
		string error = "Function " + f.name + " has already been declared";
		yyerror(error.c_str());
	}
}

void addSymbol(Symbol s) {
	if(symbolTable.find(s.name) == symbolTable.end()) {
		symbolTable[s.name] = s;
	} else {
		string error = "Symbol " + s.name + " has already been declared";
		yyerror(error.c_str());
	}
}

void pushToOutputAndClear() {
	outputCodeStream << codeStream.rdbuf();
	codeStream.clear();
	codeStream.str(" ");
}

string checkForExtraSpace(string s) {
	string temp = " endfunc";
	string temp2 = "endfunc";
	return regex_replace(s, regex(temp), temp2);
}
