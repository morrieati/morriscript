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
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_LITERAL = 258,
     DOUBLE_LITERAL = 259,
     STRING_LITERAL = 260,
     IDENTIFIER = 261,
     GLOBAL_T = 262,
     LET = 263,
     FUNCTION = 264,
     CLASS = 265,
     RETURN_T = 266,
     IF = 267,
     ELSE = 268,
     ELSIF = 269,
     TRUE_T = 270,
     FALSE_T = 271,
     NULL_T = 272,
     FOR = 273,
     WHILE = 274,
     BREAK = 275,
     CONTINUE = 276,
     LP = 277,
     RP = 278,
     LB = 279,
     RB = 280,
     LC = 281,
     RC = 282,
     SEMICOLON = 283,
     COMMA = 284,
     CLOSURE = 285,
     DOT = 286,
     LOGICAL_AND = 287,
     LOGICAL_OR = 288,
     ASSIGN = 289,
     EQ = 290,
     NE = 291,
     GT = 292,
     GE = 293,
     LT = 294,
     LE = 295,
     ADD = 296,
     SUB = 297,
     MUL = 298,
     DIV = 299,
     MOD = 300,
     NEW = 301
   };
#endif
/* Tokens.  */
#define INT_LITERAL 258
#define DOUBLE_LITERAL 259
#define STRING_LITERAL 260
#define IDENTIFIER 261
#define GLOBAL_T 262
#define LET 263
#define FUNCTION 264
#define CLASS 265
#define RETURN_T 266
#define IF 267
#define ELSE 268
#define ELSIF 269
#define TRUE_T 270
#define FALSE_T 271
#define NULL_T 272
#define FOR 273
#define WHILE 274
#define BREAK 275
#define CONTINUE 276
#define LP 277
#define RP 278
#define LB 279
#define RB 280
#define LC 281
#define RC 282
#define SEMICOLON 283
#define COMMA 284
#define CLOSURE 285
#define DOT 286
#define LOGICAL_AND 287
#define LOGICAL_OR 288
#define ASSIGN 289
#define EQ 290
#define NE 291
#define GT 292
#define GE 293
#define LT 294
#define LE 295
#define ADD 296
#define SUB 297
#define MUL 298
#define DIV 299
#define MOD 300
#define NEW 301




/* Copy the first part of user declarations.  */
#line 1 "morriscript.y"

    #include "morriscript.h"
    #define YYDEBUG 1

    void yyerror(char *);
    int yylex();


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
#line 9 "morriscript.y"
{
    char                *identifier;
    ParameterList       *parameter_list;
    ArgumentList        *argument_list;
    Expression          *expression;
    Statement           *statement;
    StatementList       *statement_list;
    Block               *block;
    Elsif               *elsif;
    IdentifierList      *identifier_list;
}
/* Line 193 of yacc.c.  */
#line 208 "morriscript.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 221 "morriscript.tab.c"

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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  68
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   449

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  167

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
       0,     0,     3,     5,     8,    10,    12,    14,    21,    27,
      31,    34,    39,    41,    45,    47,    50,    52,    56,    59,
      61,    65,    67,    71,    73,    77,    81,    83,    87,    91,
      95,    99,   101,   105,   109,   111,   115,   119,   123,   125,
     128,   133,   137,   142,   146,   151,   155,   157,   159,   161,
     163,   165,   167,   169,   171,   177,   182,   185,   187,   189,
     191,   193,   195,   197,   199,   201,   205,   209,   211,   216,
     220,   226,   234,   241,   250,   252,   255,   261,   267,   277,
     278,   280,   284,   287,   290,   294,   297
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    -1,    48,    49,    -1,    50,    -1,
      51,    -1,    65,    -1,     9,     6,    22,    52,    23,    78,
      -1,     9,     6,    22,    23,    78,    -1,    10,     6,    78,
      -1,     8,     6,    -1,     8,     6,    29,    52,    -1,    55,
      -1,    53,    29,    55,    -1,    65,    -1,    54,    65,    -1,
      56,    -1,    63,    34,    55,    -1,     1,    23,    -1,    57,
      -1,    56,    33,    57,    -1,    58,    -1,    57,    32,    58,
      -1,    59,    -1,    58,    35,    59,    -1,    58,    36,    59,
      -1,    60,    -1,    59,    37,    60,    -1,    59,    38,    60,
      -1,    59,    39,    60,    -1,    59,    40,    60,    -1,    61,
      -1,    60,    41,    61,    -1,    60,    42,    61,    -1,    62,
      -1,    61,    43,    62,    -1,    61,    44,    62,    -1,    61,
      45,    62,    -1,    63,    -1,    42,    62,    -1,     6,    22,
      53,    23,    -1,     6,    22,    23,    -1,     6,    24,    63,
      25,    -1,     6,    31,     6,    -1,    46,     6,    22,    23,
      -1,    22,    55,    23,    -1,     6,    -1,     3,    -1,     4,
      -1,     5,    -1,    15,    -1,    16,    -1,    17,    -1,    64,
      -1,    22,    52,    23,    30,    78,    -1,    22,    23,    30,
      78,    -1,    55,    28,    -1,    66,    -1,    67,    -1,    69,
      -1,    72,    -1,    73,    -1,    75,    -1,    76,    -1,    77,
      -1,     7,    68,    28,    -1,     8,    68,    28,    -1,     6,
      -1,     6,    24,     3,    25,    -1,    68,    29,     6,    -1,
      12,    22,    55,    23,    78,    -1,    12,    22,    55,    23,
      78,    13,    78,    -1,    12,    22,    55,    23,    78,    70,
      -1,    12,    22,    55,    23,    78,    70,    13,    78,    -1,
      71,    -1,    70,    71,    -1,    14,    22,    55,    23,    78,
      -1,    19,    22,    55,    23,    78,    -1,    18,    22,    74,
      28,    74,    28,    74,    23,    78,    -1,    -1,    55,    -1,
      11,    74,    28,    -1,    20,    28,    -1,    21,    28,    -1,
      26,    54,    27,    -1,    26,    27,    -1,     1,    27,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    49,    52,    53,    54,    61,    65,    71,
      77,    81,    87,    91,    97,   101,   107,   108,   112,   118,
     119,   125,   126,   132,   133,   137,   143,   144,   148,   152,
     156,   162,   163,   167,   173,   174,   178,   182,   188,   189,
     195,   199,   203,   207,   211,   215,   219,   223,   224,   225,
     226,   230,   234,   238,   241,   245,   251,   255,   256,   257,
     258,   259,   260,   261,   262,   265,   271,   277,   281,   285,
     291,   295,   299,   303,   309,   310,   316,   322,   328,   335,
     338,   341,   347,   353,   359,   363,   367
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_LITERAL", "DOUBLE_LITERAL",
  "STRING_LITERAL", "IDENTIFIER", "GLOBAL_T", "LET", "FUNCTION", "CLASS",
  "RETURN_T", "IF", "ELSE", "ELSIF", "TRUE_T", "FALSE_T", "NULL_T", "FOR",
  "WHILE", "BREAK", "CONTINUE", "LP", "RP", "LB", "RB", "LC", "RC",
  "SEMICOLON", "COMMA", "CLOSURE", "DOT", "LOGICAL_AND", "LOGICAL_OR",
  "ASSIGN", "EQ", "NE", "GT", "GE", "LT", "LE", "ADD", "SUB", "MUL", "DIV",
  "MOD", "NEW", "$accept", "translation_unit", "definition_or_statement",
  "function_definition", "class_definition", "parameter_list",
  "argument_list", "statement_list", "expression", "logical_or_expression",
  "logical_and_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "primary_expression", "closure_definition", "statement",
  "global_statement", "let_statement", "identifier_list", "if_statement",
  "elsif_list", "elsif", "while_statement", "for_statement",
  "expression_opt", "return_statement", "break_statement",
  "continue_statement", "block", 0
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
       0,    47,    48,    48,    49,    49,    49,    50,    50,    51,
      52,    52,    53,    53,    54,    54,    55,    55,    55,    56,
      56,    57,    57,    58,    58,    58,    59,    59,    59,    59,
      59,    60,    60,    60,    61,    61,    61,    61,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    64,    64,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    67,    68,    68,    68,
      69,    69,    69,    69,    70,    70,    71,    72,    73,    74,
      74,    75,    76,    77,    78,    78,    78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     6,     5,     3,
       2,     4,     1,     3,     1,     2,     1,     3,     2,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       4,     3,     4,     3,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     4,     3,
       5,     7,     6,     8,     1,     2,     5,     5,     9,     0,
       1,     3,     2,     2,     3,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    47,    48,    49,    46,     0,     0,     0,     0,
       0,     0,    50,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     4,     5,     0,    16,    19,    21,
      23,    26,    31,    34,    38,    53,     6,    57,    58,    59,
      60,    61,    62,    63,    64,    18,     0,     0,     0,    67,
       0,     0,     0,     0,    80,     0,     0,     0,     0,    82,
      83,     0,     0,     0,     0,    39,    38,     0,     1,     3,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,    12,     0,    43,
       0,    65,     0,    66,     0,     0,     0,     9,    81,     0,
       0,     0,    10,     0,     0,    45,     0,    20,    22,    24,
      25,    27,    28,    29,    30,    32,    33,    35,    36,    37,
      17,    40,     0,    42,     0,    69,     0,     0,    86,    85,
       0,    14,     0,     0,     0,     0,    55,     0,    44,    13,
      68,     8,     0,    84,    15,    70,     0,    77,    11,    54,
       7,     0,     0,    72,    74,     0,    71,     0,     0,    75,
       0,     0,    73,     0,     0,    78,    76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,    23,    24,    25,    63,    86,   130,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    50,    39,   153,   154,    40,    41,    55,    42,    43,
      44,    97
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -93
static const yytype_int16 yypact[] =
{
     165,   -12,   -93,   -93,   -93,   -14,    15,    15,    24,    31,
     280,    23,   -93,   -93,   -93,    30,    49,    45,    47,   257,
     380,    70,   121,   -93,   -93,   -93,    51,    52,    54,   -16,
     -24,    -9,    -4,   -93,    50,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   308,   403,    81,    65,
       6,    14,    68,     5,   -93,    63,   359,   280,   359,   -93,
     -93,    86,    64,    72,    73,   -93,   -93,    71,   -93,   -93,
     -93,   380,   380,   380,   380,   380,   380,   380,   380,   380,
     380,   380,   380,   380,   359,   -93,   -11,   -93,    75,   -93,
      95,   -93,    96,   -93,    -1,    74,   197,   -93,   -93,    80,
      77,    83,    78,     5,    84,   -93,    85,    54,   -16,   -24,
     -24,    -9,    -9,    -9,    -9,    -4,    -4,   -93,   -93,   -93,
     -93,   -93,   359,   -93,    88,   -93,     5,    92,   -93,   -93,
     229,   -93,     5,   280,     5,   103,   -93,     5,   -93,   -93,
     -93,   -93,     5,   -93,   -93,    37,    89,   -93,   -93,   -93,
     -93,     5,    94,    56,   -93,   336,   -93,   359,     5,   -93,
      97,   111,   -93,     5,     5,   -93,   -93
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   113,   -93,   -93,   -91,   -93,   -93,   -10,   -93,
      48,    46,   -46,   -52,     2,   -15,   -18,   -93,   -92,   -93,
     -93,   137,   -93,   -93,    -7,   -93,   -93,   -56,   -93,   -93,
     -93,   -54
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -80
static const yytype_int16 yytable[] =
{
      54,   100,    66,   127,   131,    65,    95,    61,    46,    64,
      47,    45,   121,    75,    76,    77,    78,    48,   122,    73,
      74,    49,   126,   111,   112,   113,   114,   109,   110,    88,
      52,    96,    79,    80,    91,    92,    87,    53,   144,    81,
      82,    83,    93,    92,   148,    56,    99,    54,   101,   136,
     151,   152,    57,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,   117,   118,   119,   158,
     152,    58,   141,    59,   120,    60,    67,   146,   145,    70,
     147,   115,   116,   149,    84,    71,    72,    89,   150,    90,
      94,    98,   102,   106,   103,   104,   105,   156,   124,   160,
     123,   128,   125,   132,   162,   133,   134,   135,   138,   165,
     166,    61,   139,   140,   137,   142,   157,   155,   108,   107,
     163,    68,     1,    54,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,   164,    69,    12,    13,    14,    15,
      16,    17,    18,    19,    51,    54,   159,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,     0,     0,     1,    21,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,     0,     0,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       2,     3,     4,     5,     6,     7,     0,    20,    10,    11,
       0,    21,    12,    13,    14,    15,    16,    17,    18,    19,
       0,     0,     0,     0,   129,     0,     0,     0,     0,     0,
       1,     0,     2,     3,     4,     5,     6,     7,     0,    20,
      10,    11,     0,    21,    12,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,     0,   143,     0,     1,     0,
       2,     3,     4,     5,     0,    61,     0,     0,     0,     0,
       0,    20,    12,    13,    14,    21,     0,     0,     0,    19,
      62,     1,     0,     2,     3,     4,     5,     0,     0,     0,
       0,     0,     0,     0,     0,    12,    13,    14,     0,    20,
       0,     0,    19,    21,     0,     0,     0,     0,   -79,     1,
       0,     2,     3,     4,     5,     0,     0,     0,     0,     0,
       0,     0,    20,    12,    13,    14,    21,     0,     0,     0,
      19,    85,     0,     0,     0,     0,     0,     1,     0,     2,
       3,     4,     5,     0,     0,     0,     0,     0,     0,     0,
      20,    12,    13,    14,    21,     0,     0,     0,    19,   -79,
       1,     0,     2,     3,     4,     5,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    13,    14,     0,    20,     0,
       0,    19,    21,     2,     3,     4,     5,     0,     0,     0,
       0,     0,     0,     0,     0,    12,    13,    14,     0,     0,
       0,    20,    19,     0,     0,    21,     2,     3,     4,     5,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    13,
      14,     0,    20,     0,     0,    19,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21
};

static const yytype_int16 yycheck[] =
{
      10,    57,    20,    94,    96,    20,     1,     8,    22,    19,
      24,    23,    23,    37,    38,    39,    40,    31,    29,    35,
      36,     6,    23,    75,    76,    77,    78,    73,    74,    47,
       6,    26,    41,    42,    28,    29,    46,     6,   130,    43,
      44,    45,    28,    29,   135,    22,    56,    57,    58,   103,
      13,    14,    22,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    81,    82,    83,    13,
      14,    22,   126,    28,    84,    28,     6,   133,   132,    28,
     134,    79,    80,   137,    34,    33,    32,     6,   142,    24,
      22,    28,     6,    22,    30,    23,    23,   151,     3,   155,
      25,    27,     6,    23,   158,    28,    23,    29,    23,   163,
     164,     8,   122,    25,    30,    23,    22,    28,    72,    71,
      23,     0,     1,   133,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    23,    22,    15,    16,    17,    18,
      19,    20,    21,    22,     7,   155,   153,   157,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,     1,    46,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    42,    11,    12,
      -1,    46,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    42,
      11,    12,    -1,    46,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    27,    -1,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    42,    15,    16,    17,    46,    -1,    -1,    -1,    22,
      23,     1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    42,
      -1,    -1,    22,    46,    -1,    -1,    -1,    -1,    28,     1,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    15,    16,    17,    46,    -1,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    15,    16,    17,    46,    -1,    -1,    -1,    22,    23,
       1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    42,    -1,
      -1,    22,    46,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,
      -1,    42,    22,    -1,    -1,    46,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    42,    -1,    -1,    22,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    15,    16,    17,    18,    19,    20,    21,    22,
      42,    46,    48,    49,    50,    51,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    69,
      72,    73,    75,    76,    77,    23,    22,    24,    31,     6,
      68,    68,     6,     6,    55,    74,    22,    22,    22,    28,
      28,     8,    23,    52,    55,    62,    63,     6,     0,    49,
      28,    33,    32,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    34,    23,    53,    55,    63,     6,
      24,    28,    29,    28,    22,     1,    26,    78,    28,    55,
      74,    55,     6,    30,    23,    23,    22,    57,    58,    59,
      59,    60,    60,    60,    60,    61,    61,    62,    62,    62,
      55,    23,    29,    25,     3,     6,    23,    52,    27,    27,
      54,    65,    23,    28,    23,    29,    78,    30,    23,    55,
      25,    78,    23,    27,    65,    78,    74,    78,    52,    78,
      78,    13,    14,    70,    71,    28,    78,    22,    13,    71,
      74,    55,    78,    23,    23,    78,    78
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
#line 55 "morriscript.y"
    {
        MS_Interpreter *inter = ms_get_interpreter();
        inter->statement_list = ms_chain_statement_list(inter->statement_list, (yyvsp[(1) - (1)].statement));
    ;}
    break;

  case 7:
#line 62 "morriscript.y"
    {
        ms_create_function(MS_FALSE, (yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].parameter_list), (yyvsp[(6) - (6)].block));
    ;}
    break;

  case 8:
#line 66 "morriscript.y"
    {
        ms_create_function(MS_FALSE, (yyvsp[(2) - (5)].identifier), NULL, (yyvsp[(5) - (5)].block));
    ;}
    break;

  case 9:
#line 72 "morriscript.y"
    {
        ms_create_class((yyvsp[(2) - (3)].identifier), (yyvsp[(3) - (3)].block));
    ;}
    break;

  case 10:
#line 78 "morriscript.y"
    {
        (yyval.parameter_list) = ms_create_parameter((yyvsp[(2) - (2)].identifier), MS_FALSE, MS_FALSE);
    ;}
    break;

  case 11:
#line 82 "morriscript.y"
    {
        (yyval.parameter_list) = ms_chain_parameter((yyvsp[(2) - (4)].identifier), (yyvsp[(4) - (4)].parameter_list));
    ;}
    break;

  case 12:
#line 88 "morriscript.y"
    {
        (yyval.argument_list) = ms_create_argument_list((yyvsp[(1) - (1)].expression));
    ;}
    break;

  case 13:
#line 92 "morriscript.y"
    {
        (yyval.argument_list) = ms_chain_argument_list((yyvsp[(1) - (3)].argument_list), (yyvsp[(3) - (3)].expression));
    ;}
    break;

  case 14:
#line 98 "morriscript.y"
    {
        (yyval.statement_list) = ms_create_statement_list((yyvsp[(1) - (1)].statement));
    ;}
    break;

  case 15:
#line 102 "morriscript.y"
    {
        (yyval.statement_list) = ms_chain_statement_list((yyvsp[(1) - (2)].statement_list), (yyvsp[(2) - (2)].statement));
    ;}
    break;

  case 17:
#line 109 "morriscript.y"
    {
        (yyval.expression) = ms_create_assign_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    ;}
    break;

  case 18:
#line 113 "morriscript.y"
    {
        yyerrok;
    ;}
    break;

  case 20:
#line 120 "morriscript.y"
    {
        (yyval.expression) = ms_create_binary_expression(LOGICAL_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    ;}
    break;

  case 22:
#line 127 "morriscript.y"
    {
        (yyval.expression) = ms_create_binary_expression(LOGICAL_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    ;}
    break;

  case 24:
#line 134 "morriscript.y"
    {
        (yyval.expression) = ms_create_binary_expression(EQ_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    ;}
    break;

  case 25:
#line 138 "morriscript.y"
    {
        (yyval.expression) = ms_create_binary_expression(NE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    ;}
    break;

  case 27:
#line 145 "morriscript.y"
    {
        (yyval.expression) = ms_create_binary_expression(GT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    ;}
    break;

  case 28:
#line 149 "morriscript.y"
    {
        (yyval.expression) = ms_create_binary_expression(GE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    ;}
    break;

  case 29:
#line 153 "morriscript.y"
    {
        (yyval.expression) = ms_create_binary_expression(LT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    ;}
    break;

  case 30:
#line 157 "morriscript.y"
    {
        (yyval.expression) = ms_create_binary_expression(LE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    ;}
    break;

  case 32:
#line 164 "morriscript.y"
    {
        (yyval.expression) = ms_create_binary_expression(ADD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    ;}
    break;

  case 33:
#line 168 "morriscript.y"
    {
        (yyval.expression) = ms_create_binary_expression(SUB_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    ;}
    break;

  case 35:
#line 175 "morriscript.y"
    {
        (yyval.expression) = ms_create_binary_expression(MUL_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    ;}
    break;

  case 36:
#line 179 "morriscript.y"
    {
        (yyval.expression) = ms_create_binary_expression(DIV_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    ;}
    break;

  case 37:
#line 183 "morriscript.y"
    {
        (yyval.expression) = ms_create_binary_expression(MOD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    ;}
    break;

  case 39:
#line 190 "morriscript.y"
    {
        (yyval.expression) = ms_create_minus_expression((yyvsp[(2) - (2)].expression));
    ;}
    break;

  case 40:
#line 196 "morriscript.y"
    {
        (yyval.expression) = ms_create_function_call_expression((yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].argument_list));
    ;}
    break;

  case 41:
#line 200 "morriscript.y"
    {
        (yyval.expression) = ms_create_function_call_expression((yyvsp[(1) - (3)].identifier), NULL);
    ;}
    break;

  case 42:
#line 204 "morriscript.y"
    {
        (yyval.expression) = ms_create_array_use_expression((yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].expression));
    ;}
    break;

  case 43:
#line 208 "morriscript.y"
    {
        (yyval.expression) = ms_create_class_use_expression((yyvsp[(1) - (3)].identifier), (yyvsp[(3) - (3)].identifier));
    ;}
    break;

  case 44:
#line 212 "morriscript.y"
    {
        (yyval.expression) = ms_create_class_new_expression((yyvsp[(2) - (4)].identifier));
    ;}
    break;

  case 45:
#line 216 "morriscript.y"
    {
        (yyval.expression) = (yyvsp[(2) - (3)].expression);
    ;}
    break;

  case 46:
#line 220 "morriscript.y"
    {
        (yyval.expression) = ms_create_identifier_expression((yyvsp[(1) - (1)].identifier));
    ;}
    break;

  case 50:
#line 227 "morriscript.y"
    {
        (yyval.expression) = ms_create_boolean_expression(MS_TRUE);
    ;}
    break;

  case 51:
#line 231 "morriscript.y"
    {
        (yyval.expression) = ms_create_boolean_expression(MS_FALSE);
    ;}
    break;

  case 52:
#line 235 "morriscript.y"
    {
        (yyval.expression) = ms_create_null_expression();
    ;}
    break;

  case 54:
#line 242 "morriscript.y"
    {
        (yyval.expression) = ms_create_closure_definition((yyvsp[(2) - (5)].parameter_list), (yyvsp[(5) - (5)].block));
    ;}
    break;

  case 55:
#line 246 "morriscript.y"
    {
        (yyval.expression) = ms_create_closure_definition(NULL, (yyvsp[(4) - (4)].block));
    ;}
    break;

  case 56:
#line 252 "morriscript.y"
    {
        (yyval.statement) = ms_create_expression_statement((yyvsp[(1) - (2)].expression));
    ;}
    break;

  case 65:
#line 266 "morriscript.y"
    {
        (yyval.statement) = ms_create_global_statement((yyvsp[(2) - (3)].identifier_list));
    ;}
    break;

  case 66:
#line 272 "morriscript.y"
    {
        (yyval.statement) = ms_create_let_statement((yyvsp[(2) - (3)].identifier_list));
    ;}
    break;

  case 67:
#line 278 "morriscript.y"
    {
        (yyval.identifier_list) = ms_create_global_identifier((yyvsp[(1) - (1)].identifier), MS_FALSE, MS_FALSE);
    ;}
    break;

  case 68:
#line 282 "morriscript.y"
    {
        (yyval.identifier_list) = ms_create_global_identifier((yyvsp[(1) - (4)].identifier), MS_FALSE, MS_TRUE);
    ;}
    break;

  case 69:
#line 286 "morriscript.y"
    {
        (yyval.identifier_list) = ms_chain_identifier((yyvsp[(1) - (3)].identifier_list), (yyvsp[(3) - (3)].identifier));
    ;}
    break;

  case 70:
#line 292 "morriscript.y"
    {
        (yyval.statement) = ms_create_if_statement((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].block), NULL, NULL);
    ;}
    break;

  case 71:
#line 296 "morriscript.y"
    {
        (yyval.statement) = ms_create_if_statement((yyvsp[(3) - (7)].expression), (yyvsp[(5) - (7)].block), NULL, (yyvsp[(7) - (7)].block));
    ;}
    break;

  case 72:
#line 300 "morriscript.y"
    {
        (yyval.statement) = ms_create_if_statement((yyvsp[(3) - (6)].expression), (yyvsp[(5) - (6)].block), (yyvsp[(6) - (6)].elsif), NULL);
    ;}
    break;

  case 73:
#line 304 "morriscript.y"
    {
        (yyval.statement) = ms_create_if_statement((yyvsp[(3) - (8)].expression), (yyvsp[(5) - (8)].block), (yyvsp[(6) - (8)].elsif), (yyvsp[(8) - (8)].block));
    ;}
    break;

  case 75:
#line 311 "morriscript.y"
    {
        (yyval.elsif) = ms_chain_elsif_list((yyvsp[(1) - (2)].elsif), (yyvsp[(2) - (2)].elsif));
    ;}
    break;

  case 76:
#line 317 "morriscript.y"
    {
        (yyval.elsif) = ms_create_elsif((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].block));
    ;}
    break;

  case 77:
#line 323 "morriscript.y"
    {
        (yyval.statement) = ms_create_while_statement((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].block));
    ;}
    break;

  case 78:
#line 329 "morriscript.y"
    {
        (yyval.statement) = ms_create_for_statement((yyvsp[(3) - (9)].expression), (yyvsp[(5) - (9)].expression), (yyvsp[(7) - (9)].expression), (yyvsp[(9) - (9)].block));
    ;}
    break;

  case 79:
#line 335 "morriscript.y"
    {
        (yyval.expression) = NULL;
    ;}
    break;

  case 81:
#line 342 "morriscript.y"
    {
        (yyval.statement) = ms_create_return_statement((yyvsp[(2) - (3)].expression));
    ;}
    break;

  case 82:
#line 348 "morriscript.y"
    {
        (yyval.statement) = ms_create_break_statement();
    ;}
    break;

  case 83:
#line 354 "morriscript.y"
    {
        (yyval.statement) = ms_create_continue_statement();
    ;}
    break;

  case 84:
#line 360 "morriscript.y"
    {
        (yyval.block) = ms_create_block((yyvsp[(2) - (3)].statement_list));
    ;}
    break;

  case 85:
#line 364 "morriscript.y"
    {
        (yyval.block) = ms_create_block(NULL);
    ;}
    break;

  case 86:
#line 368 "morriscript.y"
    {
        yyerrok;
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2040 "morriscript.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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
		      yytoken, &yylval);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 372 "morriscript.y"


