/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     STRING = 258,
     ID = 259,
     INT = 260,
     COMMA = 261,
     COLON = 262,
     SEMICOLON = 263,
     LPAREN = 264,
     RPAREN = 265,
     LBRACK = 266,
     RBRACK = 267,
     LBRACE = 268,
     RBRACE = 269,
     DOT = 270,
     PLUS = 271,
     MINUS = 272,
     TIMES = 273,
     DIVIDE = 274,
     EQ = 275,
     NEQ = 276,
     LT = 277,
     LE = 278,
     GT = 279,
     GE = 280,
     AND = 281,
     OR = 282,
     ASSIGN = 283,
     ARRAY = 284,
     IF = 285,
     THEN = 286,
     ELSE = 287,
     WHILE = 288,
     FOR = 289,
     TO = 290,
     DO = 291,
     LET = 292,
     IN = 293,
     END = 294,
     OF = 295,
     BREAK = 296,
     NIL = 297,
     FUNCTION = 298,
     VAR = 299,
     TYPE = 300,
     UMINUS = 301
   };
#endif
/* Tokens.  */
#define STRING 258
#define ID 259
#define INT 260
#define COMMA 261
#define COLON 262
#define SEMICOLON 263
#define LPAREN 264
#define RPAREN 265
#define LBRACK 266
#define RBRACK 267
#define LBRACE 268
#define RBRACE 269
#define DOT 270
#define PLUS 271
#define MINUS 272
#define TIMES 273
#define DIVIDE 274
#define EQ 275
#define NEQ 276
#define LT 277
#define LE 278
#define GT 279
#define GE 280
#define AND 281
#define OR 282
#define ASSIGN 283
#define ARRAY 284
#define IF 285
#define THEN 286
#define ELSE 287
#define WHILE 288
#define FOR 289
#define TO 290
#define DO 291
#define LET 292
#define IN 293
#define END 294
#define OF 295
#define BREAK 296
#define NIL 297
#define FUNCTION 298
#define VAR 299
#define TYPE 300
#define UMINUS 301




/* Copy the first part of user declarations.  */
#line 1 "tiger.y"

#include <stdio.h>
#include "util.h"
#include "errormsg.h"
#include "absyn.h"
#include "symbol.h"

int yylex(void); /* function prototype */

A_exp absyn_root;

void yyerror(char *s)
{
 EM_error(EM_tokPos, "%s", s);
}


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 20 "tiger.y"
{
  int pos;
  int ival;
  struct
  {
      string sval;
      int pos; // type of EM_tokPos
  }idval;
  string sval;
  A_var var;
  A_exp exp;
  A_expList explist;
  A_efieldList efieldlist;
  A_dec dec;
  A_ty ty;
  A_fieldList fieldList;
  S_symbol symbol;
  A_nametyList nametyList;
  A_namety namety;
  A_fundecList fundecList;
  A_decList decList;
  A_fundec fundec;
}
/* Line 193 of yacc.c.  */
#line 229 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 254 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   193

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  164

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    18,
      20,    23,    25,    30,    32,    36,    40,    42,    43,    49,
      53,    58,    65,    73,    83,    85,    89,    94,    99,   101,
     103,   105,   107,   109,   111,   113,   117,   121,   125,   129,
     133,   137,   141,   145,   149,   153,   156,   160,   164,   166,
     168,   170,   177,   182,   184,   185,   191,   195,   199,   203,
     205,   207,   210,   212,   214,   216,   218,   220,   222,   224,
     229,   231,   232,   236,   238,   242,   247,   254,   259,   268,
     270,   276,   280,   284,   286,   288,   289,   293
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    60,    -1,    50,    49,    -1,    -1,    52,
      -1,    57,    -1,    51,    -1,    58,    51,    -1,    58,    -1,
      53,    52,    -1,    53,    -1,    45,    68,    20,    54,    -1,
      68,    -1,    13,    55,    14,    -1,    29,    40,    68,    -1,
      56,    -1,    -1,    56,     6,     4,     7,    68,    -1,     4,
       7,    68,    -1,    44,     4,    28,    60,    -1,    44,     4,
       7,    68,    28,    60,    -1,    43,     4,     9,    55,    10,
      20,    60,    -1,    43,     4,     9,    55,    10,     7,    68,
      20,    60,    -1,     4,    -1,    59,    15,     4,    -1,    59,
      11,    60,    12,    -1,     4,    11,    60,    12,    -1,    61,
      -1,    59,    -1,    69,    -1,    42,    -1,    67,    -1,     5,
      -1,     3,    -1,    61,    16,    61,    -1,    61,    17,    61,
      -1,    61,    18,    61,    -1,    61,    19,    61,    -1,    61,
      20,    61,    -1,    61,    21,    61,    -1,    61,    22,    61,
      -1,    61,    23,    61,    -1,    61,    24,    61,    -1,    61,
      25,    61,    -1,    17,    61,    -1,    61,    26,    61,    -1,
      61,    27,    61,    -1,    66,    -1,    63,    -1,    62,    -1,
       4,    11,    60,    12,    40,    60,    -1,     4,    13,    64,
      14,    -1,    65,    -1,    -1,     4,    20,    60,     6,    65,
      -1,     4,    20,    60,    -1,     9,    60,    10,    -1,     9,
      80,    10,    -1,     4,    -1,    70,    -1,     9,    10,    -1,
      73,    -1,    74,    -1,    75,    -1,    76,    -1,    78,    -1,
      77,    -1,    79,    -1,     4,     9,    71,    10,    -1,    72,
      -1,    -1,    60,     6,    72,    -1,    60,    -1,    59,    28,
      60,    -1,    30,    60,    31,    60,    -1,    30,    60,    31,
      60,    32,    60,    -1,    33,    60,    36,    60,    -1,    34,
       4,    28,    60,    35,    60,    36,    60,    -1,    41,    -1,
      37,    49,    38,    82,    39,    -1,    60,     8,    81,    -1,
      60,     8,    81,    -1,    60,    -1,    83,    -1,    -1,    60,
       8,    83,    -1,    60,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    88,    89,    92,    93,    94,    97,    98,
     101,   102,   104,   107,   108,   109,   112,   113,   116,   119,
     124,   127,   133,   135,   139,   140,   141,   144,   150,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   172,   174,   176,   177,
     178,   181,   185,   190,   191,   194,   198,   202,   205,   208,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   222,
     227,   228,   231,   232,   235,   238,   241,   245,   248,   256,
     259,   262,   265,   266,   269,   270,   273,   274
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "ID", "INT", "COMMA", "COLON",
  "SEMICOLON", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE",
  "DOT", "PLUS", "MINUS", "TIMES", "DIVIDE", "EQ", "NEQ", "LT", "LE", "GT",
  "GE", "AND", "OR", "ASSIGN", "ARRAY", "IF", "THEN", "ELSE", "WHILE",
  "FOR", "TO", "DO", "LET", "IN", "END", "OF", "BREAK", "NIL", "FUNCTION",
  "VAR", "TYPE", "UMINUS", "$accept", "program", "decs", "dec", "fundecs",
  "tydecs", "tydec", "ty", "tyfields", "tyfields_opt", "vardec", "fundec",
  "lvalue", "exp", "expr", "array_crt", "rec_crt", "rec_list",
  "rec_list_opt", "paren", "seq", "type_id", "novalue", "func_call",
  "exp_list", "exp_list_opt", "assignment", "if_then", "if_then_else",
  "while_", "for_", "break_", "let_", "seq_list", "seq_list_opt", "expseq",
  "expseq_opt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    51,    51,
      52,    52,    53,    54,    54,    54,    55,    55,    56,    56,
      57,    57,    58,    58,    59,    59,    59,    59,    60,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    62,    63,    64,    64,    65,    65,    66,    67,    68,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    70,
      71,    71,    72,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    81,    82,    82,    83,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     2,     1,
       2,     1,     4,     1,     3,     3,     1,     0,     5,     3,
       4,     6,     7,     9,     1,     3,     4,     4,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     1,     1,
       1,     6,     4,     1,     0,     5,     3,     3,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     0,     3,     1,     3,     4,     6,     4,     8,     1,
       5,     3,     3,     1,     1,     0,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    34,    24,    33,     0,     0,     0,     0,     0,     4,
      79,    31,     0,    29,     2,    28,    50,    49,    48,    32,
      30,    60,    62,    63,    64,    65,    67,    66,    68,    71,
       0,    54,    61,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     4,     7,     5,    11,     6,     9,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,     0,    70,     0,     0,
       0,    53,     0,    57,    58,     0,     0,     0,     0,     0,
      59,     0,    85,     3,    10,     8,     0,    25,    74,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    46,
      47,     0,    69,    27,     0,    52,    83,    81,    75,    77,
       0,    17,     0,     0,     0,    87,     0,    84,    26,    72,
       0,    56,     0,     0,     0,     0,     0,    16,     0,    20,
      17,     0,    12,    13,     0,    80,    51,     0,    82,    76,
       0,     0,     0,     0,     0,     0,     0,    86,    55,     0,
      19,     0,     0,     0,    21,    14,    15,    78,     0,    22,
       0,     0,    18,    23
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    42,    43,    44,    45,    46,   132,   126,   127,
      47,    48,    13,    65,    15,    16,    17,    70,    71,    18,
      19,    81,    20,    21,    66,    67,    22,    23,    24,    25,
      26,    27,    28,    34,   107,   116,   117
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -110
static const yytype_int16 yypact[] =
{
      75,  -110,     8,  -110,     6,    75,    75,    75,    -2,   -18,
    -110,  -110,    29,    13,  -110,   146,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,    75,
      75,    27,  -110,    10,    34,  -110,    14,    17,    18,    45,
      50,    51,    30,   -18,  -110,  -110,    24,  -110,    28,  -110,
      75,    66,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    67,    64,  -110,    69,    63,
      71,  -110,    75,  -110,  -110,    75,    75,    75,    78,     5,
    -110,    68,    75,  -110,  -110,  -110,    74,  -110,  -110,    16,
      16,  -110,  -110,   158,   158,   158,   158,   158,   158,   168,
      77,    75,  -110,    49,    75,  -110,    82,  -110,    59,  -110,
      72,   102,    51,    75,     9,   103,    76,  -110,  -110,  -110,
      75,   104,    75,    75,    75,   107,   108,   113,    93,  -110,
     102,    85,  -110,  -110,    75,  -110,  -110,    27,  -110,  -110,
      90,    51,    -6,   123,    75,   114,    51,  -110,  -110,    75,
    -110,    51,    75,   122,  -110,  -110,  -110,  -110,   110,  -110,
      51,    75,  -110,  -110
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -110,  -110,    88,  -110,    84,    87,  -110,  -110,     7,  -110,
    -110,  -110,  -110,     0,     3,  -110,  -110,  -110,    -1,  -110,
    -110,  -109,  -110,  -110,  -110,    37,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,    19,  -110,     1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      14,   151,    38,   128,    33,   133,    36,    37,    35,     1,
       2,     3,   112,    80,   152,     4,    32,    29,    72,    30,
      73,    31,   130,     5,    50,    39,    40,    41,    51,    49,
      68,    69,   150,   113,    55,    56,     6,   156,   131,     7,
       8,    52,   158,     9,    74,    75,    77,    10,    11,    78,
      86,   162,    88,    76,    79,    80,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    82,    41,
      87,    39,   106,   101,   102,   108,   109,   110,     1,     2,
       3,   103,   115,   104,     4,   105,   118,   111,   114,   120,
     122,   123,     5,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,   121,     6,   125,   124,     7,     8,
     137,   134,     9,   129,   141,   135,    10,    11,   142,   143,
     136,   144,   106,   139,   140,   146,   149,   153,   155,   160,
     161,    83,    85,    84,   115,   147,   148,   145,   119,     0,
       0,   138,     0,     0,   154,     0,     0,     0,     0,   157,
       0,     0,   159,     0,     0,     0,     0,     0,     0,     0,
       0,   163,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62
};

static const yytype_int16 yycheck[] =
{
       0,     7,     4,   112,     4,   114,     6,     7,     5,     3,
       4,     5,     7,     4,    20,     9,    10,     9,     8,    11,
      10,    13,    13,    17,    11,    43,    44,    45,    15,     0,
      30,     4,   141,    28,    18,    19,    30,   146,    29,    33,
      34,    28,   151,    37,    10,    31,    28,    41,    42,     4,
      50,   160,    52,    36,     4,     4,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    38,    45,
       4,    43,    72,     6,    10,    75,    76,    77,     3,     4,
       5,    12,    82,    20,     9,    14,    12,     9,    20,    40,
       8,    32,    17,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   104,    30,     4,    35,    33,    34,
       6,     8,    37,   113,     7,    39,    41,    42,    10,     6,
     120,    28,   122,   123,   124,    40,    36,     4,    14,     7,
      20,    43,    48,    46,   134,   134,   137,   130,   101,    -1,
      -1,   122,    -1,    -1,   144,    -1,    -1,    -1,    -1,   149,
      -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     9,    17,    30,    33,    34,    37,
      41,    42,    48,    59,    60,    61,    62,    63,    66,    67,
      69,    70,    73,    74,    75,    76,    77,    78,    79,     9,
      11,    13,    10,    60,    80,    61,    60,    60,     4,    43,
      44,    45,    49,    50,    51,    52,    53,    57,    58,     0,
      11,    15,    28,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    60,    71,    72,    60,     4,
      64,    65,     8,    10,    10,    31,    36,    28,     4,     4,
       4,    68,    38,    49,    52,    51,    60,     4,    60,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,     6,    10,    12,    20,    14,    60,    81,    60,    60,
      60,     9,     7,    28,    20,    60,    82,    83,    12,    72,
      40,    60,     8,    32,    35,     4,    55,    56,    68,    60,
      13,    29,    54,    68,     8,    39,    60,     6,    81,    60,
      60,     7,    10,     6,    28,    55,    40,    83,    65,    36,
      68,     7,    20,     4,    60,    14,    68,    60,    68,    60,
       7,    20,    68,    60
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
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
     `$$ = $1'.

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
#line 85 "tiger.y"
    { absyn_root = (yyvsp[(1) - (1)].exp) ; }
    break;

  case 3:
#line 88 "tiger.y"
    { (yyval.decList) = A_DecList( (yyvsp[(1) - (2)].dec) , (yyvsp[(2) - (2)].decList) ) ; }
    break;

  case 4:
#line 89 "tiger.y"
    { (yyval.decList) = NULL ; }
    break;

  case 5:
#line 92 "tiger.y"
    { (yyval.dec) = A_TypeDec( EM_tokPos , (yyvsp[(1) - (1)].nametyList) ) ; }
    break;

  case 6:
#line 93 "tiger.y"
    { (yyval.dec) = (yyvsp[(1) - (1)].dec) ; }
    break;

  case 7:
#line 94 "tiger.y"
    { (yyval.dec) = A_FunctionDec( EM_tokPos , (yyvsp[(1) - (1)].fundecList) ) ; }
    break;

  case 8:
#line 97 "tiger.y"
    { (yyval.fundecList) = A_FundecList( (yyvsp[(1) - (2)].fundec) , (yyvsp[(2) - (2)].fundecList) ) ; }
    break;

  case 9:
#line 98 "tiger.y"
    { (yyval.fundecList) = A_FundecList( (yyvsp[(1) - (1)].fundec) , NULL ) ; }
    break;

  case 10:
#line 101 "tiger.y"
    { (yyval.nametyList) = A_NametyList( (yyvsp[(1) - (2)].namety) , (yyvsp[(2) - (2)].nametyList) ) ; }
    break;

  case 11:
#line 102 "tiger.y"
    { (yyval.nametyList) = A_NametyList( (yyvsp[(1) - (1)].namety) , NULL ) ; }
    break;

  case 12:
#line 104 "tiger.y"
    { (yyval.namety) = A_Namety( (yyvsp[(2) - (4)].symbol) , (yyvsp[(4) - (4)].ty) ) ; }
    break;

  case 13:
#line 107 "tiger.y"
    { (yyval.ty) = A_NameTy( EM_tokPos , (yyvsp[(1) - (1)].symbol) ) ; }
    break;

  case 14:
#line 108 "tiger.y"
    { (yyval.ty) = A_RecordTy( EM_tokPos , (yyvsp[(2) - (3)].fieldList) ) ; }
    break;

  case 15:
#line 109 "tiger.y"
    { (yyval.ty) = A_ArrayTy( EM_tokPos , (yyvsp[(3) - (3)].symbol) ) ; }
    break;

  case 16:
#line 112 "tiger.y"
    { (yyval.fieldList) = (yyvsp[(1) - (1)].fieldList) ; }
    break;

  case 17:
#line 113 "tiger.y"
    { (yyval.fieldList) = NULL ; }
    break;

  case 18:
#line 116 "tiger.y"
    { 
  (yyval.fieldList) = A_FieldList( A_Field ( (yyvsp[(3) - (5)].idval).pos , S_Symbol( (yyvsp[(3) - (5)].idval).sval ) , (yyvsp[(5) - (5)].symbol) ) ,
	    (yyvsp[(1) - (5)].fieldList) ) ; }
    break;

  case 19:
#line 119 "tiger.y"
    { (yyval.fieldList) = A_FieldList( A_Field ( (yyvsp[(1) - (3)].idval).pos , S_Symbol( (yyvsp[(1) - (3)].idval).sval ) ,
    (yyvsp[(3) - (3)].symbol) ) ,
    NULL ) ; }
    break;

  case 20:
#line 124 "tiger.y"
    { (yyval.dec) = A_VarDec( (yyvsp[(2) - (4)].idval).pos , S_Symbol( (yyvsp[(2) - (4)].idval).sval ) ,
					 NULL ,
					 (yyvsp[(4) - (4)].exp) ) ; }
    break;

  case 21:
#line 127 "tiger.y"
    { (yyval.dec) = A_VarDec( (yyvsp[(2) - (6)].idval).pos ,
						 S_Symbol( (yyvsp[(2) - (6)].idval).sval ),
						 (yyvsp[(4) - (6)].symbol),
						 (yyvsp[(6) - (6)].exp) ) ; }
    break;

  case 22:
#line 133 "tiger.y"
    {
  (yyval.fundec) = A_Fundec( (yyvsp[(2) - (7)].idval).pos , S_Symbol( (yyvsp[(2) - (7)].idval).sval ) , (yyvsp[(4) - (7)].fieldList) , NULL , (yyvsp[(7) - (7)].exp) ) ; }
    break;

  case 23:
#line 135 "tiger.y"
    {
  (yyval.fundec) = A_Fundec( (yyvsp[(2) - (9)].idval).pos , S_Symbol( (yyvsp[(2) - (9)].idval).sval ) , (yyvsp[(4) - (9)].fieldList) , (yyvsp[(7) - (9)].symbol) , (yyvsp[(9) - (9)].exp) ) ; }
    break;

  case 24:
#line 139 "tiger.y"
    { (yyval.var) = A_SimpleVar( (yyvsp[(1) - (1)].idval).pos, S_Symbol( (yyvsp[(1) - (1)].idval).sval ) ); }
    break;

  case 25:
#line 140 "tiger.y"
    { (yyval.var) = A_FieldVar( (yyvsp[(3) - (3)].idval).pos, (yyvsp[(1) - (3)].var), S_Symbol((yyvsp[(3) - (3)].idval).sval) ); }
    break;

  case 26:
#line 141 "tiger.y"
    {
    (yyval.var) = A_SubscriptVar( EM_tokPos, (yyvsp[(1) - (4)].var), (yyvsp[(3) - (4)].exp) ); }
    break;

  case 27:
#line 144 "tiger.y"
    { (yyval.var) =
        A_SubscriptVar(EM_tokPos,
        A_SimpleVar( (yyvsp[(1) - (4)].idval).pos, S_Symbol((yyvsp[(1) - (4)].idval).sval) ),
        (yyvsp[(3) - (4)].exp)); }
    break;

  case 28:
#line 150 "tiger.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp) ; }
    break;

  case 29:
#line 153 "tiger.y"
    { (yyval.exp) = A_VarExp( EM_tokPos , (yyvsp[(1) - (1)].var) ) ; }
    break;

  case 30:
#line 154 "tiger.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp) ; }
    break;

  case 31:
#line 155 "tiger.y"
    { (yyval.exp) = A_NilExp(EM_tokPos); }
    break;

  case 32:
#line 156 "tiger.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp) ; }
    break;

  case 33:
#line 157 "tiger.y"
    { (yyval.exp) = A_IntExp( EM_tokPos , (yyvsp[(1) - (1)].ival) ) ; }
    break;

  case 34:
#line 158 "tiger.y"
    { (yyval.exp) = A_StringExp( EM_tokPos, (yyvsp[(1) - (1)].sval) ); }
    break;

  case 35:
#line 159 "tiger.y"
    { (yyval.exp) = A_OpExp( EM_tokPos , A_plusOp , (yyvsp[(1) - (3)].exp) , (yyvsp[(3) - (3)].exp) ) ; }
    break;

  case 36:
#line 160 "tiger.y"
    { (yyval.exp) = A_OpExp( EM_tokPos , A_minusOp , (yyvsp[(1) - (3)].exp) , (yyvsp[(3) - (3)].exp) ) ; }
    break;

  case 37:
#line 161 "tiger.y"
    { (yyval.exp) = A_OpExp( EM_tokPos , A_timesOp , (yyvsp[(1) - (3)].exp) , (yyvsp[(3) - (3)].exp) ) ; }
    break;

  case 38:
#line 162 "tiger.y"
    { (yyval.exp) = A_OpExp( EM_tokPos , A_divideOp , (yyvsp[(1) - (3)].exp) , (yyvsp[(3) - (3)].exp) ) ; }
    break;

  case 39:
#line 163 "tiger.y"
    { (yyval.exp) = A_OpExp( EM_tokPos , A_eqOp , (yyvsp[(1) - (3)].exp) , (yyvsp[(3) - (3)].exp) ) ; }
    break;

  case 40:
#line 164 "tiger.y"
    { (yyval.exp) = A_OpExp( EM_tokPos , A_neqOp , (yyvsp[(1) - (3)].exp) , (yyvsp[(3) - (3)].exp) ) ; }
    break;

  case 41:
#line 165 "tiger.y"
    { (yyval.exp) = A_OpExp( EM_tokPos , A_ltOp , (yyvsp[(1) - (3)].exp) , (yyvsp[(3) - (3)].exp) ) ; }
    break;

  case 42:
#line 166 "tiger.y"
    { (yyval.exp) = A_OpExp( EM_tokPos , A_leOp , (yyvsp[(1) - (3)].exp) , (yyvsp[(3) - (3)].exp) ) ; }
    break;

  case 43:
#line 167 "tiger.y"
    { (yyval.exp) = A_OpExp( EM_tokPos , A_gtOp , (yyvsp[(1) - (3)].exp) , (yyvsp[(3) - (3)].exp) ) ; }
    break;

  case 44:
#line 168 "tiger.y"
    { (yyval.exp) = A_OpExp( EM_tokPos , A_geOp , (yyvsp[(1) - (3)].exp) , (yyvsp[(3) - (3)].exp) ) ; }
    break;

  case 45:
#line 169 "tiger.y"
    { (yyval.exp) = A_OpExp( EM_tokPos , A_minusOp ,
					  A_IntExp(EM_tokPos,0) ,
					  (yyvsp[(2) - (2)].exp) ) ; }
    break;

  case 46:
#line 172 "tiger.y"
    { (yyval.exp) = A_IfExp( EM_tokPos , (yyvsp[(1) - (3)].exp) , (yyvsp[(3) - (3)].exp) ,
				A_IntExp( EM_tokPos , 0 ) ) ; }
    break;

  case 47:
#line 174 "tiger.y"
    { (yyval.exp) = A_IfExp( EM_tokPos , (yyvsp[(1) - (3)].exp) ,
			       A_IntExp( EM_tokPos , 1 ) , (yyvsp[(3) - (3)].exp) ) ; }
    break;

  case 48:
#line 176 "tiger.y"
    { (yyval.exp) = A_NilExp(EM_tokPos) ; }
    break;

  case 49:
#line 177 "tiger.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp) ; }
    break;

  case 50:
#line 178 "tiger.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp) ; }
    break;

  case 51:
#line 181 "tiger.y"
    {
  (yyval.exp) = A_ArrayExp( (yyvsp[(1) - (6)].idval).pos , S_Symbol( (yyvsp[(1) - (6)].idval).sval ) , (yyvsp[(3) - (6)].exp) , (yyvsp[(6) - (6)].exp) ) ; }
    break;

  case 52:
#line 185 "tiger.y"
    {
    (yyval.exp) = A_RecordExp( (yyvsp[(1) - (4)].idval).pos , S_Symbol( (yyvsp[(1) - (4)].idval).sval ) , (yyvsp[(3) - (4)].efieldlist) ) ;
}
    break;

  case 53:
#line 190 "tiger.y"
    { (yyval.efieldlist) = (yyvsp[(1) - (1)].efieldlist) ; }
    break;

  case 54:
#line 191 "tiger.y"
    { (yyval.efieldlist) = NULL ;}
    break;

  case 55:
#line 194 "tiger.y"
    { 
  (yyval.efieldlist) = A_EfieldList(
	       A_Efield( S_Symbol( (yyvsp[(1) - (5)].idval).sval ) ,(yyvsp[(3) - (5)].exp) ) ,
	       (yyvsp[(5) - (5)].efieldlist) ) ; }
    break;

  case 56:
#line 198 "tiger.y"
    { (yyval.efieldlist) = A_EfieldList( A_Efield( S_Symbol( (yyvsp[(1) - (3)].idval).sval ) , (yyvsp[(3) - (3)].exp) ) ,
				 NULL ) ; }
    break;

  case 58:
#line 205 "tiger.y"
    { (yyval.exp) = A_SeqExp( EM_tokPos , (yyvsp[(2) - (3)].explist) ) ; }
    break;

  case 59:
#line 208 "tiger.y"
    { (yyval.symbol) = S_Symbol( (yyvsp[(1) - (1)].idval).sval ) ; }
    break;

  case 60:
#line 211 "tiger.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp) ; }
    break;

  case 61:
#line 212 "tiger.y"
    { (yyval.exp) = NULL ; }
    break;

  case 62:
#line 213 "tiger.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp) ; }
    break;

  case 63:
#line 214 "tiger.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp) ; }
    break;

  case 64:
#line 215 "tiger.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp) ; }
    break;

  case 65:
#line 216 "tiger.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp) ; }
    break;

  case 66:
#line 217 "tiger.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp) ; }
    break;

  case 67:
#line 218 "tiger.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp) ; }
    break;

  case 68:
#line 219 "tiger.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp) ; }
    break;

  case 69:
#line 222 "tiger.y"
    { (yyval.exp) = A_CallExp( EM_tokPos,
						       S_Symbol((yyvsp[(1) - (4)].idval).sval),
						       (yyvsp[(3) - (4)].explist)); }
    break;

  case 70:
#line 227 "tiger.y"
    { (yyval.explist) = (yyvsp[(1) - (1)].explist) ; }
    break;

  case 71:
#line 228 "tiger.y"
    { (yyval.explist) = NULL ; }
    break;

  case 72:
#line 231 "tiger.y"
    { (yyval.explist) = A_ExpList( (yyvsp[(1) - (3)].exp) , (yyvsp[(3) - (3)].explist) ) ; }
    break;

  case 73:
#line 232 "tiger.y"
    { (yyval.explist) = A_ExpList( (yyvsp[(1) - (1)].exp) , NULL ) ;}
    break;

  case 74:
#line 235 "tiger.y"
    { (yyval.exp) = A_AssignExp( EM_tokPos , (yyvsp[(1) - (3)].var) , (yyvsp[(3) - (3)].exp) ) ; }
    break;

  case 75:
#line 238 "tiger.y"
    { (yyval.exp) = A_IfExp( EM_tokPos , (yyvsp[(2) - (4)].exp) , (yyvsp[(4) - (4)].exp) , NULL ) ; }
    break;

  case 76:
#line 241 "tiger.y"
    { (yyval.exp) = A_IfExp ( EM_tokPos , 
							(yyvsp[(2) - (6)].exp) , (yyvsp[(4) - (6)].exp) , (yyvsp[(6) - (6)].exp) ); }
    break;

  case 77:
#line 245 "tiger.y"
    { (yyval.exp) = A_WhileExp( EM_tokPos , (yyvsp[(2) - (4)].exp) , (yyvsp[(4) - (4)].exp) ) ; }
    break;

  case 78:
#line 248 "tiger.y"
    {
  (yyval.exp) = A_ForExp( (yyvsp[(2) - (8)].idval).pos ,
		 S_Symbol( (yyvsp[(2) - (8)].idval).sval ) ,
		 (yyvsp[(4) - (8)].exp) ,
		 (yyvsp[(6) - (8)].exp) ,
		 (yyvsp[(8) - (8)].exp) ) ; }
    break;

  case 79:
#line 256 "tiger.y"
    { (yyval.exp) = A_BreakExp ( EM_tokPos ) ; }
    break;

  case 80:
#line 259 "tiger.y"
    { (yyval.exp) = A_LetExp( EM_tokPos , (yyvsp[(2) - (5)].decList) , (yyvsp[(4) - (5)].explist) ) ; }
    break;

  case 81:
#line 262 "tiger.y"
    { (yyval.explist) = A_ExpList( (yyvsp[(1) - (3)].exp) , (yyvsp[(3) - (3)].explist) ) ; }
    break;

  case 82:
#line 265 "tiger.y"
    { (yyval.explist) = A_ExpList( (yyvsp[(1) - (3)].exp) , (yyvsp[(3) - (3)].explist) ) ; }
    break;

  case 83:
#line 266 "tiger.y"
    { (yyval.explist) = A_ExpList( (yyvsp[(1) - (1)].exp) , NULL ) ; }
    break;

  case 84:
#line 269 "tiger.y"
    { (yyval.explist) = (yyvsp[(1) - (1)].explist) ; }
    break;

  case 85:
#line 270 "tiger.y"
    { (yyval.explist) = NULL ; }
    break;

  case 86:
#line 273 "tiger.y"
    { (yyval.explist) = A_ExpList( (yyvsp[(1) - (3)].exp) , (yyvsp[(3) - (3)].explist) ) ; }
    break;

  case 87:
#line 274 "tiger.y"
    { (yyval.explist) = A_ExpList( (yyvsp[(1) - (1)].exp) , NULL ) ; }
    break;


/* Line 1267 of yacc.c.  */
#line 2088 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



