
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "syn.y"

#include<stdio.h>
#include"lex.yy.c"
#include"gtree.h"    
#include"midcode.h"
//void yyerror(const char *s);


/* Line 189 of yacc.c  */
#line 82 "syn.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     FLOAT = 259,
     IDENTIFIER = 260,
     SEMI = 261,
     COMMA = 262,
     ASSIGNOP = 263,
     RELOP = 264,
     ADD = 265,
     SUB = 266,
     MUL = 267,
     DIV = 268,
     AND = 269,
     OR = 270,
     DOT = 271,
     NOT = 272,
     TYPE = 273,
     LP = 274,
     RP = 275,
     LB = 276,
     RB = 277,
     LC = 278,
     RC = 279,
     STRUCT = 280,
     RETURN = 281,
     IF = 282,
     ELSE = 283,
     WHILE = 284
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 10 "syn.y"
struct ast *a;double d;


/* Line 214 of yacc.c  */
#line 151 "syn.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
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


/* Line 264 of yacc.c  */
#line 176 "syn.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   230

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    13,    16,    20,    24,
      26,    30,    32,    34,    40,    47,    50,    52,    53,    55,
      57,    62,    67,    71,    75,    77,    80,    85,    91,    94,
      95,    98,   102,   104,   108,   113,   119,   127,   133,   136,
     137,   141,   146,   148,   152,   154,   158,   162,   166,   170,
     174,   178,   182,   186,   190,   194,   197,   200,   205,   209,
     214,   218,   220,   222,   224,   228
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      31,     0,    -1,    32,    -1,    33,    32,    -1,    -1,    35,
      34,     6,    -1,    35,     6,    -1,    35,     1,     6,    -1,
      35,    40,    43,    -1,    39,    -1,    39,     7,    34,    -1,
      18,    -1,    36,    -1,    25,    37,    23,    46,    24,    -1,
      25,    37,    23,    46,     1,    24,    -1,    25,    38,    -1,
       5,    -1,    -1,     5,    -1,     5,    -1,    39,    21,     3,
      22,    -1,     5,    19,    41,    20,    -1,     5,    19,    20,
      -1,    42,     7,    41,    -1,    42,    -1,    35,    39,    -1,
      23,    46,    44,    24,    -1,    23,    46,    44,     1,    24,
      -1,    45,    44,    -1,    -1,    50,     6,    -1,    50,     1,
       6,    -1,    43,    -1,    26,    50,     6,    -1,    26,    50,
       1,     6,    -1,    27,    19,    50,    20,    45,    -1,    27,
      19,    50,    20,    45,    28,    45,    -1,    29,    19,    50,
      20,    45,    -1,    47,    46,    -1,    -1,    35,    48,     6,
      -1,    35,    48,     1,     6,    -1,    49,    -1,    49,     7,
      48,    -1,    39,    -1,    39,     8,    50,    -1,    50,     8,
      50,    -1,    50,    14,    50,    -1,    50,    15,    50,    -1,
      50,     9,    50,    -1,    50,    10,    50,    -1,    50,    11,
      50,    -1,    50,    12,    50,    -1,    50,    13,    50,    -1,
      19,    50,    20,    -1,    11,    50,    -1,    17,    50,    -1,
       5,    19,    51,    20,    -1,     5,    19,    20,    -1,    50,
      21,    50,    22,    -1,    50,    16,     5,    -1,     5,    -1,
       3,    -1,     4,    -1,    50,     7,    51,    -1,    50,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    33,    33,    49,    50,    54,    55,    56,    57,    61,
      62,    67,    68,    72,    73,    74,    78,    79,    83,    87,
      88,    92,    93,    97,    98,   102,   107,   108,   112,   113,
     117,   118,   119,   120,   121,   122,   123,   124,   129,   130,
     134,   135,   139,   140,   144,   145,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   171,   172
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "IDENTIFIER", "SEMI",
  "COMMA", "ASSIGNOP", "RELOP", "ADD", "SUB", "MUL", "DIV", "AND", "OR",
  "DOT", "NOT", "TYPE", "LP", "RP", "LB", "RB", "LC", "RC", "STRUCT",
  "RETURN", "IF", "ELSE", "WHILE", "$accept", "program", "ext_def_list",
  "ext_def", "ext_dec_list", "specifier", "struct_specifier", "opt_tag",
  "tag", "var_dec", "fun_dec", "var_list", "param_dec", "comp_st",
  "stmt_list", "stmt", "def_list", "def", "dec_list", "dec", "exp", "args", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    33,    33,    34,
      34,    35,    35,    36,    36,    36,    37,    37,    38,    39,
      39,    40,    40,    41,    41,    42,    43,    43,    44,    44,
      45,    45,    45,    45,    45,    45,    45,    45,    46,    46,
      47,    47,    48,    48,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    51,    51
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     3,     1,
       3,     1,     1,     5,     6,     2,     1,     0,     1,     1,
       4,     4,     3,     3,     1,     2,     4,     5,     2,     0,
       2,     3,     1,     3,     4,     5,     7,     5,     2,     0,
       3,     4,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     4,     3,     4,
       3,     1,     1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    11,    17,     0,     2,     4,     0,    12,    18,     0,
      15,     1,     3,     0,    19,     6,     0,     9,     0,    39,
       7,     0,     5,     0,     0,    39,     8,     0,     0,    39,
      22,     0,     0,    24,    19,    10,     0,    29,    44,     0,
      42,     0,    13,    38,    25,    21,     0,    20,    62,    63,
      61,     0,     0,     0,     0,     0,     0,    32,     0,    29,
       0,     0,     0,    40,     0,    14,    23,     0,    55,    56,
       0,     0,     0,     0,     0,    26,    28,     0,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
      41,    43,    58,    65,     0,    54,     0,    33,     0,     0,
      27,    31,    46,    49,    50,    51,    52,    53,    47,    48,
      60,     0,     0,    57,    34,     0,     0,    59,    64,    35,
      37,     0,    36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    16,    27,     7,     9,    10,    17,
      18,    32,    33,    57,    58,    59,    28,    29,    39,    40,
      60,    94
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -68
static const yytype_int16 yypact[] =
{
      -1,   -68,     1,    20,   -68,    -1,    51,   -68,     3,    22,
     -68,   -68,   -68,    52,    41,   -68,    60,    -2,    44,    -1,
     -68,   205,   -68,    77,    67,    -1,   -68,    77,    12,    -1,
     -68,    77,    48,    76,   -68,   -68,    92,    36,     6,    17,
     121,    75,   -68,   -68,   108,   -68,    -1,   -68,   -68,   -68,
     112,    98,    98,    98,    98,   123,   124,   -68,    14,    36,
      63,    98,   138,   -68,    77,   -68,   -68,    93,    30,    65,
     140,    79,    98,    98,   106,   -68,   -68,   139,   -68,    98,
      98,    98,    98,    98,    98,    98,    98,   152,    98,   182,
     -68,   -68,   -68,   111,   151,   -68,   153,   -68,   154,   168,
     -68,   -68,   182,    95,    30,    30,    65,    65,   208,   195,
     -68,   125,    98,   -68,   -68,    36,    36,   -68,   -68,   130,
     -68,    36,   -68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   167,   -68,   150,     4,   -68,   -68,   -68,   -20,
     -68,   141,   -68,   181,   126,   -67,   -17,   -68,   122,   -68,
     -51,    88
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -17
static const yytype_int8 yytable[] =
{
      68,    69,    70,    71,     6,    23,     8,    38,    37,     6,
      89,    44,    43,    41,    61,    74,    93,     1,    62,    24,
      11,    98,    99,    63,     2,    31,   -16,    24,   102,   103,
     104,   105,   106,   107,   108,   109,    42,   111,    75,    48,
      49,    50,    83,    84,    38,    19,    87,    51,   119,   120,
      31,    88,    13,    52,   122,    53,    14,    15,    20,    25,
      21,    93,    54,    55,    77,    56,    22,    25,    45,    78,
      36,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      96,    87,    34,    46,    88,    97,    88,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    48,    49,    50,    65,
      88,    48,    49,    50,    51,    81,    82,    83,    84,    51,
      52,    87,    53,    92,    47,    52,    88,    53,   112,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    64,    24,
     100,    67,    88,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    72,    73,    90,   101,    88,   117,    79,    80,
      81,    82,    83,    84,    85,    86,    87,   110,   121,   114,
      95,    88,    79,    80,    81,    82,    83,    84,    85,    86,
      87,   113,    12,    35,   115,    88,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    76,    91,    66,   116,    88,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    26,
     118,     0,     0,    88,    80,    81,    82,    83,    84,    85,
       0,    87,     0,     0,     0,     0,    88,    80,    81,    82,
      83,    84,     0,     1,    87,    30,     0,     0,     0,    88,
       2
};

static const yytype_int8 yycheck[] =
{
      51,    52,    53,    54,     0,     7,     5,    27,    25,     5,
      61,    31,    29,     1,     8,     1,    67,    18,     1,    21,
       0,    72,    73,     6,    25,    21,    23,    21,    79,    80,
      81,    82,    83,    84,    85,    86,    24,    88,    24,     3,
       4,     5,    12,    13,    64,    23,    16,    11,   115,   116,
      46,    21,     1,    17,   121,    19,     5,     6,     6,    23,
      19,   112,    26,    27,     1,    29,     6,    23,    20,     6,
       3,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       1,    16,     5,     7,    21,     6,    21,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     3,     4,     5,    24,
      21,     3,     4,     5,    11,    10,    11,    12,    13,    11,
      17,    16,    19,    20,    22,    17,    21,    19,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     7,    21,
      24,    19,    21,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    19,    19,     6,     6,    21,    22,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     5,    28,     6,
      20,    21,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    20,     5,    23,    20,    21,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    59,    64,    46,    20,    21,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    18,
     112,    -1,    -1,    21,     9,    10,    11,    12,    13,    14,
      -1,    16,    -1,    -1,    -1,    -1,    21,     9,    10,    11,
      12,    13,    -1,    18,    16,    20,    -1,    -1,    -1,    21,
      25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    25,    31,    32,    33,    35,    36,     5,    37,
      38,     0,    32,     1,     5,     6,    34,    39,    40,    23,
       6,    19,     6,     7,    21,    23,    43,    35,    46,    47,
      20,    35,    41,    42,     5,    34,     3,    46,    39,    48,
      49,     1,    24,    46,    39,    20,     7,    22,     3,     4,
       5,    11,    17,    19,    26,    27,    29,    43,    44,    45,
      50,     8,     1,     6,     7,    24,    41,    19,    50,    50,
      50,    50,    19,    19,     1,    24,    44,     1,     6,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    21,    50,
       6,    48,    20,    50,    51,    20,     1,     6,    50,    50,
      24,     6,    50,    50,    50,    50,    50,    50,    50,    50,
       5,    50,     7,    20,     6,    20,    20,    22,    51,    45,
      45,    28,    45
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 34 "syn.y"
    {
            (yyval.a)=newast("program",1,(yyvsp[(1) - (1)].a));
            (yyval.a)->number=1101;
            if(!g_i){
                //printf("Type syntax tree:>\n");
                //DepthT($$,0);
                //printf("<Finish\n");
                eval_c((yyval.a));
                //eval($$,0);
                //print();
            }
        ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 49 "syn.y"
    {(yyval.a)=newast("ext_def_list",2,(yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));(yyval.a)->number=1201;;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 50 "syn.y"
    {(yyval.a)=newast("ext_def_list",0,-1);(yyval.a)->number=1202;;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 54 "syn.y"
    {(yyval.a)=newast("ext_def",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=1301;;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 55 "syn.y"
    {(yyval.a)=newast("ext_def",2,(yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));(yyval.a)->number=1302;;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 56 "syn.y"
    {g_i=1;;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 57 "syn.y"
    {(yyval.a)=newast("ext_def",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=1303;;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 61 "syn.y"
    {(yyval.a)=newast("ext_dec_list",1,(yyvsp[(1) - (1)].a));(yyval.a)->number=1401;;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 62 "syn.y"
    {(yyval.a)=newast("ext_dec_list",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=1402;;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 67 "syn.y"
    {(yyval.a)=newast("specifier",1,(yyvsp[(1) - (1)].a));(yyval.a)->number=2101;;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 68 "syn.y"
    {(yyval.a)=newast("specifier",1,(yyvsp[(1) - (1)].a));(yyval.a)->number=2102;;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 72 "syn.y"
    {(yyval.a)=newast("struct_specifier",5,(yyvsp[(1) - (5)].a),(yyvsp[(2) - (5)].a),(yyvsp[(3) - (5)].a),(yyvsp[(4) - (5)].a),(yyvsp[(5) - (5)].a));(yyval.a)->number=2201;;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 73 "syn.y"
    {g_i=1;;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 74 "syn.y"
    {(yyval.a)=newast("struct_specifier",2,(yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));(yyval.a)->number=2202;;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 78 "syn.y"
    {(yyval.a)=newast("opt_tag",1,(yyvsp[(1) - (1)].a));(yyval.a)->number=2301;;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 79 "syn.y"
    {(yyval.a)=newast("opt_tag",0,-1);(yyval.a)->number=2302;;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 83 "syn.y"
    {(yyval.a)=newast("tag",1,(yyvsp[(1) - (1)].a));(yyval.a)->number=2401;;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 87 "syn.y"
    {(yyval.a)=newast("var_dec",1,(yyvsp[(1) - (1)].a));(yyval.a)->tag=VAR;/*普通变量*/(yyval.a)->number=3101;;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 88 "syn.y"
    {(yyval.a)=newast("var_dec",4,(yyvsp[(1) - (4)].a),(yyvsp[(2) - (4)].a),(yyvsp[(3) - (4)].a),(yyvsp[(4) - (4)].a));(yyval.a)->tag=ARR;/*数组*/(yyval.a)->number=3102;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 92 "syn.y"
    {(yyval.a)=newast("fun_dec",4,(yyvsp[(1) - (4)].a),(yyvsp[(2) - (4)].a),(yyvsp[(3) - (4)].a),(yyvsp[(4) - (4)].a));(yyval.a)->number=3201;;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 93 "syn.y"
    {(yyval.a)=newast("fun_dec",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=3202;;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 97 "syn.y"
    {(yyval.a)=newast("var_list",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=3301;;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 98 "syn.y"
    {(yyval.a)=newast("var_list",1,(yyvsp[(1) - (1)].a));(yyval.a)->number=3302;;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 102 "syn.y"
    {(yyval.a)=newast("param_dec",2,(yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));pnum++;(yyval.a)->number=3401;;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 107 "syn.y"
    {(yyval.a)=newast("comp_st",4,(yyvsp[(1) - (4)].a),(yyvsp[(2) - (4)].a),(yyvsp[(3) - (4)].a),(yyvsp[(4) - (4)].a));(yyval.a)->number=4101;;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 108 "syn.y"
    {g_i=1;;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 112 "syn.y"
    {(yyval.a)=newast("stmt_list",2,(yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));(yyval.a)->number=4201;;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 113 "syn.y"
    {(yyval.a)=newast("stmt_list",0,-1);(yyval.a)->number=4202;;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 117 "syn.y"
    {(yyval.a)=newast("stmt",2,(yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));(yyval.a)->number=4301;;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 118 "syn.y"
    {g_i=1;;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 119 "syn.y"
    {(yyval.a)=newast("stmt",1,(yyvsp[(1) - (1)].a));(yyval.a)->number=4302;;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 120 "syn.y"
    {(yyval.a)=newast("stmt",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=4303;;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 121 "syn.y"
    {g_i=1;;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 122 "syn.y"
    {(yyval.a)=newast("stmt",5,(yyvsp[(1) - (5)].a),(yyvsp[(2) - (5)].a),(yyvsp[(3) - (5)].a),(yyvsp[(4) - (5)].a),(yyvsp[(5) - (5)].a));(yyval.a)->number=4304;;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 123 "syn.y"
    {(yyval.a)=newast("stmt",7,(yyvsp[(1) - (7)].a),(yyvsp[(2) - (7)].a),(yyvsp[(3) - (7)].a),(yyvsp[(4) - (7)].a),(yyvsp[(5) - (7)].a),(yyvsp[(6) - (7)].a),(yyvsp[(7) - (7)].a));(yyval.a)->number=4305;;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 124 "syn.y"
    {(yyval.a)=newast("stmt",5,(yyvsp[(1) - (5)].a),(yyvsp[(2) - (5)].a),(yyvsp[(3) - (5)].a),(yyvsp[(4) - (5)].a),(yyvsp[(5) - (5)].a));(yyval.a)->number=4306;;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 129 "syn.y"
    {(yyval.a)=newast("def_list",2,(yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));(yyval.a)->number=5101;;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 130 "syn.y"
    {(yyval.a)=newast("def_list",0,-1);(yyval.a)->number=5102;;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 134 "syn.y"
    {(yyval.a)=newast("def",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=5201;;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 135 "syn.y"
    {g_i=1;;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 139 "syn.y"
    {(yyval.a)=newast("dec_list",1,(yyvsp[(1) - (1)].a));(yyval.a)->number=5301;;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 140 "syn.y"
    {(yyval.a)=newast("dec_list",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=5302;;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 144 "syn.y"
    {(yyval.a)=newast("dec",1,(yyvsp[(1) - (1)].a));(yyval.a)->number=5401;;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 145 "syn.y"
    {(yyval.a)=newast("dec",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=5402;;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 150 "syn.y"
    {(yyval.a)=newast("exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=6101;;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 151 "syn.y"
    {(yyval.a)=newast("exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=6102;;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 152 "syn.y"
    {(yyval.a)=newast("exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=6103;;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 153 "syn.y"
    {(yyval.a)=newast("exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=6104;;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 154 "syn.y"
    {(yyval.a)=newast("exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=6105;;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 155 "syn.y"
    {(yyval.a)=newast("exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=6106;;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 156 "syn.y"
    {(yyval.a)=newast("exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=6107;;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 157 "syn.y"
    {(yyval.a)=newast("exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=6108;;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 158 "syn.y"
    {(yyval.a)=newast("exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=6109;;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 159 "syn.y"
    {(yyval.a)=newast("exp",2,(yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));   (yyval.a)->number=6110;;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 160 "syn.y"
    {(yyval.a)=newast("exp",2,(yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));   (yyval.a)->number=6111;;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 161 "syn.y"
    {(yyval.a)=newast("exp",4,(yyvsp[(1) - (4)].a),(yyvsp[(2) - (4)].a),(yyvsp[(3) - (4)].a),(yyvsp[(4) - (4)].a));(yyval.a)->number=6112;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 162 "syn.y"
    {(yyval.a)=newast("exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=6113;;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 163 "syn.y"
    {(yyval.a)=newast("exp",4,(yyvsp[(1) - (4)].a),(yyvsp[(2) - (4)].a),(yyvsp[(3) - (4)].a),(yyvsp[(4) - (4)].a));(yyval.a)->number=6114;;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 164 "syn.y"
    {(yyval.a)=newast("exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=6115;;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 165 "syn.y"
    {(yyval.a)=newast("exp",1,(yyvsp[(1) - (1)].a));      (yyval.a)->number=6116;;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 166 "syn.y"
    {(yyval.a)=newast("exp",1,(yyvsp[(1) - (1)].a));      (yyval.a)->number=6117;;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 167 "syn.y"
    {(yyval.a)=newast("exp",1,(yyvsp[(1) - (1)].a));      (yyval.a)->number=6118;;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 171 "syn.y"
    {(yyval.a)=newast("args",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));(yyval.a)->number=6201;;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 172 "syn.y"
    {(yyval.a)=newast("args",1,(yyvsp[(1) - (1)].a));(yyval.a)->number=6202;;}
    break;



/* Line 1455 of yacc.c  */
#line 1991 "syn.tab.c"
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

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 175 "syn.y"



