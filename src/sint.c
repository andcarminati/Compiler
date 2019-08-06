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
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     SIZEOF = 261,
     PTR_OP = 262,
     INC_OP = 263,
     DEC_OP = 264,
     LEFT_OP = 265,
     RIGHT_OP = 266,
     LE_OP = 267,
     GE_OP = 268,
     EQ_OP = 269,
     NE_OP = 270,
     AND_OP = 271,
     OR_OP = 272,
     MUL_ASSIGN = 273,
     DIV_ASSIGN = 274,
     MOD_ASSIGN = 275,
     ADD_ASSIGN = 276,
     SUB_ASSIGN = 277,
     LEFT_ASSIGN = 278,
     RIGHT_ASSIGN = 279,
     AND_ASSIGN = 280,
     XOR_ASSIGN = 281,
     OR_ASSIGN = 282,
     TYPE_NAME = 283,
     TYPEDEF = 284,
     EXTERN = 285,
     STATIC = 286,
     AUTO = 287,
     REGISTER = 288,
     CHAR = 289,
     SHORT = 290,
     INT = 291,
     LONG = 292,
     SIGNED = 293,
     UNSIGNED = 294,
     FLOAT = 295,
     DOUBLE = 296,
     VOID = 297,
     STRUCT = 298,
     UNION = 299,
     ENUM = 300,
     ELLIPSIS = 301,
     CASE = 302,
     DEFAULT = 303,
     IF = 304,
     ELSE = 305,
     SWITCH = 306,
     WHILE = 307,
     DO = 308,
     FOR = 309,
     GOTO = 310,
     CONTINUE = 311,
     BREAK = 312,
     RETURN = 313
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define STRING_LITERAL 260
#define SIZEOF 261
#define PTR_OP 262
#define INC_OP 263
#define DEC_OP 264
#define LEFT_OP 265
#define RIGHT_OP 266
#define LE_OP 267
#define GE_OP 268
#define EQ_OP 269
#define NE_OP 270
#define AND_OP 271
#define OR_OP 272
#define MUL_ASSIGN 273
#define DIV_ASSIGN 274
#define MOD_ASSIGN 275
#define ADD_ASSIGN 276
#define SUB_ASSIGN 277
#define LEFT_ASSIGN 278
#define RIGHT_ASSIGN 279
#define AND_ASSIGN 280
#define XOR_ASSIGN 281
#define OR_ASSIGN 282
#define TYPE_NAME 283
#define TYPEDEF 284
#define EXTERN 285
#define STATIC 286
#define AUTO 287
#define REGISTER 288
#define CHAR 289
#define SHORT 290
#define INT 291
#define LONG 292
#define SIGNED 293
#define UNSIGNED 294
#define FLOAT 295
#define DOUBLE 296
#define VOID 297
#define STRUCT 298
#define UNION 299
#define ENUM 300
#define ELLIPSIS 301
#define CASE 302
#define DEFAULT 303
#define IF 304
#define ELSE 305
#define SWITCH 306
#define WHILE 307
#define DO 308
#define FOR 309
#define GOTO 310
#define CONTINUE 311
#define BREAK 312
#define RETURN 313




/* Copy the first part of user declarations.  */
#line 1 "sintatic.yacc"
 
#include <stdio.h>
#include "../include/compiler.h" 
#include "../include/semantic.h"

char *id;
char *str;
int erro = 0;

TRANSLATION_UNIT *aa;


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
#line 13 "sintatic.yacc"
{
	int ivalue;		/* integer value */
	char sIndex;	/* symbol table index */
	char *str;
	void *nPtr;		/* node pointer */
}
/* Line 187 of yacc.c.  */
#line 231 "sint.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 244 "sint.c"

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
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   823

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  167
/* YYNRULES -- Number of states.  */
#define YYNSTATES  280

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,     2,     2,     2,    72,    65,     2,
      59,    60,    66,    67,    64,    68,    63,    71,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    81,    78,
      73,    77,    74,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,    75,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    79,    76,    80,    69,     2,     2,     2,
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
      55,    56,    57,    58
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    20,    24,
      29,    33,    37,    40,    43,    45,    49,    51,    54,    57,
      62,    64,    66,    68,    70,    72,    74,    76,    80,    84,
      88,    90,    94,    98,   100,   104,   108,   110,   114,   118,
     122,   126,   128,   132,   136,   138,   142,   144,   148,   150,
     154,   156,   160,   162,   166,   168,   170,   174,   176,   178,
     180,   182,   184,   186,   190,   192,   195,   199,   201,   204,
     206,   210,   212,   216,   218,   220,   222,   224,   226,   228,
     234,   239,   242,   244,   246,   248,   251,   255,   258,   260,
     262,   266,   268,   271,   275,   278,   280,   282,   286,   291,
     295,   300,   305,   309,   311,   314,   316,   318,   322,   325,
     328,   330,   332,   336,   338,   341,   343,   345,   348,   352,
     355,   359,   363,   368,   371,   375,   379,   384,   386,   390,
     395,   397,   401,   403,   405,   407,   409,   411,   413,   415,
     419,   424,   428,   431,   435,   439,   444,   446,   449,   451,
     454,   456,   459,   462,   468,   476,   482,   490,   494,   497,
     500,   503,   507,   509,   512,   514,   516,   521
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     136,     0,    -1,     3,    -1,     4,    -1,     5,    -1,    59,
     101,    60,    -1,    83,    -1,    84,    61,   101,    62,    -1,
      84,    59,    60,    -1,    84,    59,    85,    60,    -1,    84,
      63,     3,    -1,    84,     7,     3,    -1,    84,     8,    -1,
      84,     9,    -1,    99,    -1,    85,    64,    99,    -1,    84,
      -1,    87,    86,    -1,     6,    86,    -1,     6,    59,   122,
      60,    -1,    65,    -1,    66,    -1,    67,    -1,    68,    -1,
      69,    -1,    70,    -1,    86,    -1,    88,    66,    86,    -1,
      88,    71,    86,    -1,    88,    72,    86,    -1,    88,    -1,
      89,    67,    88,    -1,    89,    68,    88,    -1,    89,    -1,
      90,    10,    89,    -1,    90,    11,    89,    -1,    90,    -1,
      91,    73,    90,    -1,    91,    74,    90,    -1,    91,    12,
      90,    -1,    91,    13,    90,    -1,    91,    -1,    92,    14,
      91,    -1,    92,    15,    91,    -1,    92,    -1,    93,    65,
      92,    -1,    93,    -1,    94,    75,    93,    -1,    94,    -1,
      95,    76,    94,    -1,    95,    -1,    96,    16,    95,    -1,
      96,    -1,    97,    17,    96,    -1,    97,    -1,    98,    -1,
      86,   100,    99,    -1,    77,    -1,    18,    -1,    19,    -1,
      21,    -1,    22,    -1,    99,    -1,   101,    64,    99,    -1,
      98,    -1,   104,    78,    -1,   104,   105,    78,    -1,   107,
      -1,   107,   104,    -1,   106,    -1,   105,    64,   106,    -1,
     115,    -1,   115,    77,   125,    -1,    42,    -1,    34,    -1,
      36,    -1,    40,    -1,   108,    -1,    28,    -1,   109,     3,
      79,   110,    80,    -1,   109,    79,   110,    80,    -1,   109,
       3,    -1,    43,    -1,    44,    -1,   111,    -1,   110,   111,
      -1,   112,   113,    78,    -1,   107,   112,    -1,   107,    -1,
     114,    -1,   113,    64,   114,    -1,   115,    -1,    81,   102,
      -1,   115,    81,   102,    -1,   117,   116,    -1,   116,    -1,
       3,    -1,    59,   115,    60,    -1,   116,    61,     4,    62,
      -1,   116,    61,    62,    -1,   116,    59,   118,    60,    -1,
     116,    59,   121,    60,    -1,   116,    59,    60,    -1,    66,
      -1,    66,   117,    -1,   119,    -1,   120,    -1,   119,    64,
     120,    -1,   104,   115,    -1,   104,   123,    -1,   104,    -1,
       3,    -1,   121,    64,     3,    -1,   112,    -1,   112,   123,
      -1,   117,    -1,   124,    -1,   117,   124,    -1,    59,   123,
      60,    -1,    61,    62,    -1,    61,   102,    62,    -1,   124,
      61,    62,    -1,   124,    61,   102,    62,    -1,    59,    60,
      -1,    59,   118,    60,    -1,   124,    59,    60,    -1,   124,
      59,   118,    60,    -1,    99,    -1,    79,   126,    80,    -1,
      79,   126,    64,    80,    -1,   125,    -1,   126,    64,   125,
      -1,   128,    -1,   129,    -1,   132,    -1,   133,    -1,   138,
      -1,   134,    -1,   135,    -1,     3,    81,   127,    -1,    47,
     102,    81,   127,    -1,    48,    81,   127,    -1,    79,    80,
      -1,    79,   131,    80,    -1,    79,   130,    80,    -1,    79,
     130,   131,    80,    -1,   103,    -1,   130,   103,    -1,   127,
      -1,   131,   127,    -1,    78,    -1,   101,    78,    -1,     1,
      78,    -1,    49,    59,   101,    60,   127,    -1,    49,    59,
     101,    60,   127,    50,   127,    -1,    52,    59,   101,    60,
     127,    -1,    53,   127,    52,    59,   101,    60,    78,    -1,
      55,     3,    78,    -1,    56,    78,    -1,    57,    78,    -1,
      58,    78,    -1,    58,   101,    78,    -1,   137,    -1,   136,
     137,    -1,   138,    -1,   103,    -1,   104,   115,   130,   129,
      -1,   104,   115,   129,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    92,    92,   104,   116,   129,   144,   154,   164,   173,
     183,   193,   203,   213,   225,   234,   247,   257,   268,   278,
     290,   299,   308,   317,   326,   335,   347,   358,   370,   383,
     400,   412,   425,   440,   451,   462,   477,   489,   501,   513,
     525,   540,   553,   565,   580,   591,   606,   617,   632,   644,
     658,   669,   683,   694,   709,   721,   732,   748,   758,   768,
     778,   788,   800,   810,   824,   836,   847,   863,   874,   887,
     898,   912,   923,   938,   949,   960,   971,   982,   993,  1007,
    1021,  1033,  1049,  1059,  1071,  1072,  1076,  1080,  1089,  1101,
    1102,  1106,  1107,  1108,  1112,  1123,  1137,  1155,  1166,  1178,
    1190,  1202,  1214,  1230,  1240,  1253,  1265,  1275,  1287,  1300,
    1305,  1313,  1325,  1340,  1349,  1360,  1361,  1362,  1366,  1367,
    1368,  1369,  1370,  1371,  1372,  1373,  1374,  1378,  1388,  1389,
    1393,  1403,  1417,  1428,  1439,  1450,  1461,  1472,  1483,  1497,
    1509,  1521,  1535,  1547,  1558,  1569,  1584,  1595,  1607,  1618,
    1630,  1639,  1651,  1655,  1665,  1678,  1689,  1705,  1717,  1729,
    1741,  1753,  1768,  1779,  1792,  1797,  1806,  1823
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "VOID",
  "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE",
  "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN",
  "'('", "')'", "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'",
  "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'='", "';'",
  "'{'", "'}'", "':'", "$accept", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "type_specifier", "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "declarator", "direct_declarator", "pointer",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "statement", "labeled_statement", "compound_statement",
  "declaration_list", "statement_list", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,    40,
      41,    91,    93,    46,    44,    38,    42,    43,    45,   126,
      33,    47,    37,    60,    62,    94,   124,    61,    59,   123,
     125,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    83,    83,    83,    84,    84,    84,    84,
      84,    84,    84,    84,    85,    85,    86,    86,    86,    86,
      87,    87,    87,    87,    87,    87,    88,    88,    88,    88,
      89,    89,    89,    90,    90,    90,    91,    91,    91,    91,
      91,    92,    92,    92,    93,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    98,    99,    99,   100,   100,   100,
     100,   100,   101,   101,   102,   103,   103,   104,   104,   105,
     105,   106,   106,   107,   107,   107,   107,   107,   107,   108,
     108,   108,   109,   109,   110,   110,   111,   112,   112,   113,
     113,   114,   114,   114,   115,   115,   116,   116,   116,   116,
     116,   116,   116,   117,   117,   118,   119,   119,   120,   120,
     120,   121,   121,   122,   122,   123,   123,   123,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   125,   125,   125,
     126,   126,   127,   127,   127,   127,   127,   127,   127,   128,
     128,   128,   129,   129,   129,   129,   130,   130,   131,   131,
     132,   132,   132,   133,   133,   134,   134,   135,   135,   135,
     135,   135,   136,   136,   137,   137,   138,   138
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     3,     1,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     5,
       4,     2,     1,     1,     1,     2,     3,     2,     1,     1,
       3,     1,     2,     3,     2,     1,     1,     3,     4,     3,
       4,     4,     3,     1,     2,     1,     1,     3,     2,     2,
       1,     1,     3,     1,     2,     1,     1,     2,     3,     2,
       3,     3,     4,     2,     3,     3,     4,     1,     3,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     3,     3,     4,     1,     2,     1,     2,
       1,     2,     2,     5,     7,     5,     7,     3,     2,     2,
       2,     3,     1,     2,     1,     1,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    78,    74,    75,    76,    73,    82,    83,   165,     0,
      67,    77,     0,     0,   162,   164,    96,     0,   103,    65,
       0,    69,    71,    95,     0,    68,    81,     0,     1,   163,
       0,   104,     0,    66,     0,     0,   146,     0,   167,     0,
       0,     0,    94,     0,    88,     0,    84,     0,    97,    70,
      71,     2,     3,     4,     0,     0,    20,    21,    22,    23,
      24,    25,     0,     6,    16,    26,     0,    30,    33,    36,
      41,    44,    46,    48,    50,    52,    54,    55,   127,    72,
       0,     2,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   150,   142,    62,     0,   148,   132,   133,     0,     0,
     134,   135,   137,   138,   136,   147,   166,   111,   102,   110,
       0,   105,   106,     0,     0,    99,     0,    87,    80,    85,
       0,     0,    89,    91,     0,    18,     0,   130,     0,     0,
      12,    13,     0,     0,     0,    58,    59,    60,    61,    57,
       0,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     152,     0,    26,    64,     0,     0,     0,     0,     0,     0,
       0,   158,   159,   160,     0,     0,   151,   144,     0,   143,
     149,     0,     0,   108,   115,   109,   116,   100,     0,   101,
       0,    98,    79,    92,     0,    86,     0,   113,     0,     5,
       0,   128,    11,     8,     0,    14,     0,    10,    56,    27,
      28,    29,    31,    32,    34,    35,    39,    40,    37,    38,
      42,    43,    45,    47,    49,    51,    53,   139,     0,   141,
       0,     0,     0,     0,   157,   161,    63,   145,   123,     0,
       0,   119,     0,   117,     0,     0,   107,   112,    90,    93,
       0,   115,   114,    19,   129,   131,     9,     0,     7,   140,
       0,     0,     0,   124,   118,   120,   125,     0,   121,     0,
      15,   153,   155,     0,   126,   122,     0,     0,   154,   156
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    63,    64,   204,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    93,   140,    94,
     164,    36,   168,    20,    21,    10,    11,    12,    45,    46,
      47,   121,   122,    30,    23,    24,   239,   111,   112,   113,
     198,   240,   186,    79,   128,    95,    96,    97,    39,    99,
     100,   101,   102,   103,    13,    14,   104
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -148
static const yytype_int16 yypact[] =
{
     779,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,    85,
     779,  -148,    18,   721,  -148,  -148,  -148,    15,   -43,  -148,
     -16,  -148,   716,    89,    16,  -148,   -51,   779,  -148,  -148,
     -22,  -148,    15,  -148,   233,   215,  -148,    85,  -148,   156,
     675,    22,    89,   779,   779,   698,  -148,    14,  -148,  -148,
     -23,  -148,  -148,  -148,   452,   620,  -148,  -148,  -148,  -148,
    -148,  -148,   233,  -148,   315,    38,   620,   100,    -4,    36,
      40,    56,   -34,    42,    13,   104,   132,  -148,  -148,  -148,
      67,    79,   620,    86,   117,   135,   495,   194,   127,   129,
     303,  -148,  -148,  -148,    -9,  -148,  -148,  -148,   285,   355,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,    46,
     146,   151,  -148,   -28,   155,  -148,   703,  -148,  -148,  -148,
     620,    -6,  -148,   141,   578,  -148,    98,  -148,   -37,   220,
    -148,  -148,   381,   620,   223,  -148,  -148,  -148,  -148,  -148,
     620,  -148,   620,   620,   620,   620,   620,   620,   620,   620,
     620,   620,   620,   620,   620,   620,   620,   620,   620,   620,
    -148,   495,  -148,  -148,   147,   495,   620,   620,    15,   175,
     152,  -148,  -148,  -148,    78,   620,  -148,  -148,   425,  -148,
    -148,   664,   590,  -148,    93,  -148,   128,  -148,   779,  -148,
     226,  -148,  -148,  -148,    14,  -148,   620,    50,   171,  -148,
     510,  -148,  -148,  -148,   110,  -148,    95,  -148,  -148,  -148,
    -148,  -148,   100,   100,    -4,    -4,    36,    36,    36,    36,
      40,    40,    56,   -34,    42,    13,   104,  -148,   495,  -148,
     113,   118,   156,   181,  -148,  -148,  -148,  -148,  -148,   174,
     182,  -148,   179,   128,   756,   604,  -148,  -148,  -148,  -148,
     745,   134,  -148,  -148,  -148,  -148,  -148,   620,  -148,  -148,
     495,   495,   620,  -148,  -148,  -148,  -148,   185,  -148,   184,
    -148,   197,  -148,   119,  -148,  -148,   495,   170,  -148,  -148
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,  -148,  -148,  -148,   -21,  -148,   -63,   -46,    60,    49,
      97,   105,    96,   102,   106,  -148,   -41,   -32,  -148,   -48,
    -105,    12,     0,  -148,   222,    23,  -148,  -148,   213,   -29,
     -30,  -148,    72,    -3,   -15,   -17,   -36,  -148,    81,  -148,
    -148,  -104,  -147,   -54,  -148,   -75,  -148,   -19,   240,   178,
    -148,  -148,  -148,  -148,  -148,   264,    65
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
       9,    31,    78,    38,   110,   185,    22,   126,   127,    42,
      25,   169,     8,     9,   117,   193,   119,    16,    16,    16,
     106,    26,    37,    18,   180,     8,   114,   200,    43,    50,
      78,   155,   189,   125,    50,     9,   190,   243,    48,    37,
     109,   163,   174,   201,   123,   141,   147,   148,    32,    16,
      44,   105,   149,   150,    34,   175,   135,   136,   194,   137,
     138,   162,    33,   145,   146,    15,    44,    44,    44,   176,
     153,   154,   195,    17,    17,    17,   126,   242,    15,   163,
      18,    18,   212,   213,   115,   206,   227,   119,    16,   157,
     229,   249,   184,   252,   197,   120,    16,    27,     9,   162,
     205,   214,   215,   180,   243,   181,   183,   182,   208,   250,
     105,   182,    18,   151,   152,   139,    18,   156,   230,   231,
     158,   209,   210,   211,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,    44,
     269,   163,   175,   236,    17,   160,   255,    44,    40,   159,
      41,    18,   181,   259,   182,   163,   235,   258,   199,   175,
     161,   162,   175,    19,   184,   232,   142,   165,    78,    42,
     256,   143,   144,   260,   257,   162,   166,   175,   261,   277,
     251,   109,   175,   175,     1,   271,   272,   244,   109,   245,
       2,   123,     3,   250,   167,   182,     4,   170,     5,     6,
       7,   278,   220,   221,   163,   171,   187,   172,   267,   216,
     217,   218,   219,    38,   273,   188,    80,   191,    81,    52,
      53,    54,   196,   202,   162,   270,   207,   233,   228,   247,
     234,   253,    37,   251,   263,    35,    51,    52,    53,    54,
     262,   265,   264,     1,   109,   274,   275,   276,   279,     2,
     109,     3,   222,   224,    49,     4,   116,     5,     6,     7,
     225,   223,    82,    83,    84,   226,   248,    85,    86,   246,
      87,    88,    89,    90,    55,    98,   178,    29,     0,     0,
      56,    57,    58,    59,    60,    61,    80,     0,    81,    52,
      53,    54,    55,    91,    35,    92,     0,     0,    56,    57,
      58,    59,    60,    61,     0,     0,    51,    52,    53,    54,
       0,     0,    62,     1,     0,     0,     0,     0,     0,     2,
       0,     3,   129,   130,   131,     4,     0,     5,     6,     7,
       0,     0,    82,    83,    84,     0,     0,    85,    86,     0,
      87,    88,    89,    90,    55,     0,     0,     0,     0,     0,
      56,    57,    58,    59,    60,    61,    80,     0,    81,    52,
      53,    54,    55,    91,    35,   177,     0,     0,    56,    57,
      58,    59,    60,    61,   132,     0,   133,     0,   134,     0,
       0,   173,     0,     1,    51,    52,    53,    54,     0,     2,
       0,     3,     0,     0,     0,     4,     0,     5,     6,     7,
       0,     0,    82,    83,    84,     0,     0,    85,    86,     0,
      87,    88,    89,    90,    55,     0,     0,     0,     0,     0,
      56,    57,    58,    59,    60,    61,    80,     0,    81,    52,
      53,    54,     0,    91,    35,   179,     0,     0,     0,     0,
      55,   203,     0,     0,     0,     0,    56,    57,    58,    59,
      60,    61,     0,     1,     0,    51,    52,    53,    54,     2,
       0,     3,     0,     0,     0,     4,     0,     5,     6,     7,
       0,     0,    82,    83,    84,     0,     0,    85,    86,     0,
      87,    88,    89,    90,    55,     0,     0,     0,     0,     0,
      56,    57,    58,    59,    60,    61,    80,     0,    81,    52,
      53,    54,     0,    91,    35,   237,     0,     0,     0,     0,
       0,   124,     0,    51,    52,    53,    54,    56,    57,    58,
      59,    60,    61,     1,     0,     0,     0,     0,     0,     2,
       0,     3,     0,     0,     0,     4,     0,     5,     6,     7,
       0,     0,    82,    83,    84,     0,     0,    85,    86,     0,
      87,    88,    89,    90,    55,     0,     0,     0,     0,     0,
      56,    57,    58,    59,    60,    61,     0,     0,     0,    55,
       0,     0,     0,    91,    35,    56,    57,    58,    59,    60,
      61,    51,    52,    53,    54,     0,     0,     0,     0,    62,
     254,     0,     0,    51,    52,    53,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,    51,    52,    53,
      54,     0,     2,     0,     3,     0,     0,     0,     4,     0,
       5,     6,     7,    51,    52,    53,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
       0,     0,     0,    56,    57,    58,    59,    60,    61,    55,
       0,     0,   241,     0,     0,    56,    57,    58,    59,    60,
      61,     0,     0,    55,     0,     0,   268,    16,     0,    56,
      57,    58,    59,    60,    61,     0,     0,     0,   107,    55,
       0,     0,     0,     0,     0,    56,    57,    58,    59,    60,
      61,     0,     1,     0,     0,     0,     0,     0,     2,     0,
       3,     0,     0,     1,     4,     0,     5,     6,     7,     2,
       0,     3,     0,     0,     0,     4,     0,     5,     6,     7,
       0,    28,     0,   181,   238,   182,     1,     0,     0,     0,
      18,     1,     2,     0,     3,   108,     0,     2,     4,     3,
       5,     6,     7,     4,     1,     5,     6,     7,     0,     1,
       2,     0,     3,     0,     0,     2,     4,     3,     5,     6,
       7,     4,     0,     5,     6,     7,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     0,     0,   118,     2,
       0,     3,     0,   192,     1,     4,     0,     5,     6,     7,
       2,     0,     3,    34,     0,    35,     4,     0,     5,     6,
       7,     0,     0,     0,   250,   238,   182,     1,     0,     0,
       0,    18,     0,     2,     0,     3,   266,     0,     0,     4,
       0,     5,     6,     7
};

static const yytype_int16 yycheck[] =
{
       0,    18,    34,    22,    40,   109,     9,    55,    62,    24,
      10,    86,     0,    13,    44,   120,    45,     3,     3,     3,
      39,     3,    22,    66,    99,    13,     4,    64,    79,    32,
      62,    65,    60,    54,    37,    35,    64,   184,    60,    39,
      40,    82,    90,    80,    47,    66,    10,    11,    64,     3,
      27,    39,    12,    13,    77,    64,    18,    19,    64,    21,
      22,    82,    78,    67,    68,     0,    43,    44,    45,    78,
      14,    15,    78,    59,    59,    59,   124,   182,    13,   120,
      66,    66,   145,   146,    62,   133,   161,   116,     3,    76,
     165,   196,   109,   197,   124,    81,     3,    79,    98,   120,
     132,   147,   148,   178,   251,    59,   109,    61,   140,    59,
      98,    61,    66,    73,    74,    77,    66,    75,   166,   167,
      16,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   116,
     245,   182,    64,   175,    59,    78,   200,   124,    59,    17,
      61,    66,    59,   228,    61,   196,    78,    62,    60,    64,
      81,   182,    64,    78,   181,   168,    66,    81,   200,   184,
      60,    71,    72,    60,    64,   196,    59,    64,    60,    60,
     197,   181,    64,    64,    28,   260,   261,    59,   188,    61,
      34,   194,    36,    59,    59,    61,    40,     3,    42,    43,
      44,   276,   153,   154,   245,    78,    60,    78,   244,   149,
     150,   151,   152,   232,   262,    64,     1,    62,     3,     4,
       5,     6,    81,     3,   245,   257,     3,    52,    81,     3,
      78,    60,   232,   250,    60,    79,     3,     4,     5,     6,
      59,    62,    60,    28,   244,    60,    62,    50,    78,    34,
     250,    36,   155,   157,    32,    40,    43,    42,    43,    44,
     158,   156,    47,    48,    49,   159,   194,    52,    53,   188,
      55,    56,    57,    58,    59,    35,    98,    13,    -1,    -1,
      65,    66,    67,    68,    69,    70,     1,    -1,     3,     4,
       5,     6,    59,    78,    79,    80,    -1,    -1,    65,    66,
      67,    68,    69,    70,    -1,    -1,     3,     4,     5,     6,
      -1,    -1,    79,    28,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    36,     7,     8,     9,    40,    -1,    42,    43,    44,
      -1,    -1,    47,    48,    49,    -1,    -1,    52,    53,    -1,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    69,    70,     1,    -1,     3,     4,
       5,     6,    59,    78,    79,    80,    -1,    -1,    65,    66,
      67,    68,    69,    70,    59,    -1,    61,    -1,    63,    -1,
      -1,    78,    -1,    28,     3,     4,     5,     6,    -1,    34,
      -1,    36,    -1,    -1,    -1,    40,    -1,    42,    43,    44,
      -1,    -1,    47,    48,    49,    -1,    -1,    52,    53,    -1,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    69,    70,     1,    -1,     3,     4,
       5,     6,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,    -1,    65,    66,    67,    68,
      69,    70,    -1,    28,    -1,     3,     4,     5,     6,    34,
      -1,    36,    -1,    -1,    -1,    40,    -1,    42,    43,    44,
      -1,    -1,    47,    48,    49,    -1,    -1,    52,    53,    -1,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    69,    70,     1,    -1,     3,     4,
       5,     6,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,
      -1,    59,    -1,     3,     4,     5,     6,    65,    66,    67,
      68,    69,    70,    28,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    36,    -1,    -1,    -1,    40,    -1,    42,    43,    44,
      -1,    -1,    47,    48,    49,    -1,    -1,    52,    53,    -1,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    78,    79,    65,    66,    67,    68,    69,
      70,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    79,
      80,    -1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,     3,     4,     5,
       6,    -1,    34,    -1,    36,    -1,    -1,    -1,    40,    -1,
      42,    43,    44,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    69,    70,    59,
      -1,    -1,    62,    -1,    -1,    65,    66,    67,    68,    69,
      70,    -1,    -1,    59,    -1,    -1,    62,     3,    -1,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,     3,    59,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    -1,    28,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      36,    -1,    -1,    28,    40,    -1,    42,    43,    44,    34,
      -1,    36,    -1,    -1,    -1,    40,    -1,    42,    43,    44,
      -1,     0,    -1,    59,    60,    61,    28,    -1,    -1,    -1,
      66,    28,    34,    -1,    36,    60,    -1,    34,    40,    36,
      42,    43,    44,    40,    28,    42,    43,    44,    -1,    28,
      34,    -1,    36,    -1,    -1,    34,    40,    36,    42,    43,
      44,    40,    -1,    42,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    80,    34,
      -1,    36,    -1,    80,    28,    40,    -1,    42,    43,    44,
      34,    -1,    36,    77,    -1,    79,    40,    -1,    42,    43,
      44,    -1,    -1,    -1,    59,    60,    61,    28,    -1,    -1,
      -1,    66,    -1,    34,    -1,    36,    60,    -1,    -1,    40,
      -1,    42,    43,    44
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    34,    36,    40,    42,    43,    44,   103,   104,
     107,   108,   109,   136,   137,   138,     3,    59,    66,    78,
     105,   106,   115,   116,   117,   104,     3,    79,     0,   137,
     115,   117,    64,    78,    77,    79,   103,   104,   129,   130,
      59,    61,   116,    79,   107,   110,   111,   112,    60,   106,
     115,     3,     4,     5,     6,    59,    65,    66,    67,    68,
      69,    70,    79,    83,    84,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   125,
       1,     3,    47,    48,    49,    52,    53,    55,    56,    57,
      58,    78,    80,    99,   101,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   138,   103,   129,     3,    60,   104,
     118,   119,   120,   121,     4,    62,   110,   112,    80,   111,
      81,   113,   114,   115,    59,    86,   101,   125,   126,     7,
       8,     9,    59,    61,    63,    18,    19,    21,    22,    77,
     100,    86,    66,    71,    72,    67,    68,    10,    11,    12,
      13,    73,    74,    14,    15,    65,    75,    76,    16,    17,
      78,    81,    86,    98,   102,    81,    59,    59,   104,   127,
       3,    78,    78,    78,   101,    64,    78,    80,   131,    80,
     127,    59,    61,   115,   117,   123,   124,    60,    64,    60,
      64,    62,    80,   102,    64,    78,    81,   112,   122,    60,
      64,    80,     3,    60,    85,    99,   101,     3,    99,    86,
      86,    86,    88,    88,    89,    89,    90,    90,    90,    90,
      91,    91,    92,    93,    94,    95,    96,   127,    81,   127,
     101,   101,   115,    52,    78,    78,    99,    80,    60,   118,
     123,    62,   102,   124,    59,    61,   120,     3,   114,   102,
      59,   117,   123,    60,    80,   125,    60,    64,    62,   127,
      60,    60,    59,    60,    60,    62,    60,   118,    62,   102,
      99,   127,   127,   101,    60,    62,    50,    60,   127,    78
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
        case 2:
#line 93 "sintatic.yacc"
    {
		PRIMARY_EXPRESSION1 *e = malloc(sizeof(PRIMARY_EXPRESSION1));
		((DEFAULT_NODE *) e)->type = PRIMARY_EXPRESSION_CODE;
		((DEFAULT_NODE *) e)->subtype = PRIMARY_EXPRESSION1_CODE;
		
		e->identifier = (yyvsp[(1) - (1)].str);
	
		(yyval.nPtr) = e;
		
	;}
    break;

  case 3:
#line 105 "sintatic.yacc"
    {
		PRIMARY_EXPRESSION2 *e = malloc(sizeof(PRIMARY_EXPRESSION2));
		((DEFAULT_NODE *) e)->type = PRIMARY_EXPRESSION_CODE;
		((DEFAULT_NODE *) e)->subtype = PRIMARY_EXPRESSION2_CODE;
		
		e->constant = (yyvsp[(1) - (1)].ivalue);
		
		(yyval.nPtr) = e;
		
	;}
    break;

  case 4:
#line 117 "sintatic.yacc"
    {
		PRIMARY_EXPRESSION3 *e = malloc(sizeof(PRIMARY_EXPRESSION3));
		((DEFAULT_NODE *) e)->type = PRIMARY_EXPRESSION_CODE;
		((DEFAULT_NODE *) e)->subtype = PRIMARY_EXPRESSION3_CODE;
		
		e->string_literal = (yyvsp[(1) - (1)].str);
		//puts(e->string_literal);
		
		(yyval.nPtr) = e;
		
	;}
    break;

  case 5:
#line 130 "sintatic.yacc"
    {
		PRIMARY_EXPRESSION4 *e = malloc(sizeof(PRIMARY_EXPRESSION4));
		((DEFAULT_NODE *) e)->type = PRIMARY_EXPRESSION_CODE;
		((DEFAULT_NODE *) e)->subtype = PRIMARY_EXPRESSION4_CODE;
		
		e->expression = (yyvsp[(2) - (3)].nPtr);
		
		(yyval.nPtr) = e;
		
	;}
    break;

  case 6:
#line 145 "sintatic.yacc"
    {
		POSTFIX_ESPRESSION1 *e = malloc(sizeof(POSTFIX_ESPRESSION1));
		((POSTFIX_ESPRESSION *) e)->type = POSTFIX_ESPRESSION_CODE;
		((POSTFIX_ESPRESSION *) e)->subtype = POSTFIX_ESPRESSION1_CODE;
		e->primary_expression = (yyvsp[(1) - (1)].nPtr);
		(yyval.nPtr) = e;
	
	;}
    break;

  case 7:
#line 155 "sintatic.yacc"
    {
		POSTFIX_ESPRESSION2 *e = malloc(sizeof(POSTFIX_ESPRESSION2));
		((POSTFIX_ESPRESSION *) e)->type = POSTFIX_ESPRESSION_CODE;
		((POSTFIX_ESPRESSION *) e)->subtype = POSTFIX_ESPRESSION2_CODE;
		e->postfix_expression = (yyvsp[(1) - (4)].nPtr);
		e->expression = (yyvsp[(3) - (4)].nPtr);
		(yyval.nPtr) = e;
	;}
    break;

  case 8:
#line 165 "sintatic.yacc"
    {
		POSTFIX_ESPRESSION3 *e = malloc(sizeof(POSTFIX_ESPRESSION3));
		((POSTFIX_ESPRESSION *) e)->type = POSTFIX_ESPRESSION_CODE;
		((POSTFIX_ESPRESSION *) e)->subtype = POSTFIX_ESPRESSION3_CODE;
		e->postfix_expression = (yyvsp[(1) - (3)].nPtr);
		(yyval.nPtr) = e;
	;}
    break;

  case 9:
#line 174 "sintatic.yacc"
    {
		POSTFIX_ESPRESSION4 *e = malloc(sizeof(POSTFIX_ESPRESSION4));
		((POSTFIX_ESPRESSION *) e)->type = POSTFIX_ESPRESSION_CODE;
		((POSTFIX_ESPRESSION *) e)->subtype = POSTFIX_ESPRESSION4_CODE;
		e->postfix_expression = (yyvsp[(1) - (4)].nPtr);
		e->argument_expression_list = (yyvsp[(3) - (4)].nPtr);
		(yyval.nPtr) = e;
	;}
    break;

  case 10:
#line 184 "sintatic.yacc"
    {
		POSTFIX_ESPRESSION5 *e = malloc(sizeof(POSTFIX_ESPRESSION5));
		((POSTFIX_ESPRESSION *) e)->type = POSTFIX_ESPRESSION_CODE;
		((POSTFIX_ESPRESSION *) e)->subtype = POSTFIX_ESPRESSION5_CODE;
		e->postfix_expression = (yyvsp[(1) - (3)].nPtr);
		e->identifier = (yyvsp[(3) - (3)].str);
		(yyval.nPtr) = e;
	;}
    break;

  case 11:
#line 194 "sintatic.yacc"
    {
		POSTFIX_ESPRESSION6 *e = malloc(sizeof(POSTFIX_ESPRESSION6));
		((POSTFIX_ESPRESSION *) e)->type = POSTFIX_ESPRESSION_CODE;
		((POSTFIX_ESPRESSION *) e)->subtype = POSTFIX_ESPRESSION6_CODE;
		e->postfix_expression = (yyvsp[(1) - (3)].nPtr);
		e->identifier = (yyvsp[(3) - (3)].str);
		(yyval.nPtr) = e;
	;}
    break;

  case 12:
#line 204 "sintatic.yacc"
    {
		POSTFIX_ESPRESSION7 *e = malloc(sizeof(POSTFIX_ESPRESSION7));
		((POSTFIX_ESPRESSION *) e)->type = POSTFIX_ESPRESSION_CODE;
		((POSTFIX_ESPRESSION *) e)->subtype = POSTFIX_ESPRESSION7_CODE;
		e->postfix_expression = (yyvsp[(1) - (2)].nPtr);
		e->op = INC_OP;
		(yyval.nPtr) = e;
	;}
    break;

  case 13:
#line 214 "sintatic.yacc"
    {
		POSTFIX_ESPRESSION8 *e = malloc(sizeof(POSTFIX_ESPRESSION8));
		((POSTFIX_ESPRESSION *) e)->type = POSTFIX_ESPRESSION_CODE;
		((POSTFIX_ESPRESSION *) e)->subtype = POSTFIX_ESPRESSION8_CODE;
		e->postfix_expression = (yyvsp[(1) - (2)].nPtr);
		e->op = DEC_OP;
		(yyval.nPtr) = e;
	;}
    break;

  case 14:
#line 226 "sintatic.yacc"
    {
		ARGUMENT_EXPRESSION_LIST *ael = malloc(sizeof(ARGUMENT_EXPRESSION_LIST));
		((DEFAULT_NODE *) ael)->type = ARGUMENT_EXPRESSION_LIST_CODE;
		ael->assignment_expression = (yyvsp[(1) - (1)].nPtr);
		ael->argument_expression_list = NULL;
		
		(yyval.nPtr) = ael;
	;}
    break;

  case 15:
#line 235 "sintatic.yacc"
    {
		ARGUMENT_EXPRESSION_LIST *ael = malloc(sizeof(ARGUMENT_EXPRESSION_LIST));
		((DEFAULT_NODE *) ael)->type = ARGUMENT_EXPRESSION_LIST_CODE;
		ael->assignment_expression = (yyvsp[(3) - (3)].nPtr);
		ael->argument_expression_list = (yyvsp[(1) - (3)].nPtr);
		
		(yyval.nPtr) = ael;
	
	;}
    break;

  case 16:
#line 248 "sintatic.yacc"
    {
		UNARY_EXPRESSION1 *e = malloc(sizeof(UNARY_EXPRESSION1));
		((DEFAULT_NODE *) e)->type = UNARY_EXPRESSION_CODE;
		((DEFAULT_NODE *) e)->subtype = UNARY_EXPRESSION1_CODE;
		e->postfix_expression = (yyvsp[(1) - (1)].nPtr);
		
		(yyval.nPtr) = e;
	;}
    break;

  case 17:
#line 258 "sintatic.yacc"
    {
		UNARY_EXPRESSION2 *e = malloc(sizeof(UNARY_EXPRESSION2));
		((DEFAULT_NODE *) e)->type = UNARY_EXPRESSION_CODE;
		((DEFAULT_NODE *) e)->subtype = UNARY_EXPRESSION2_CODE;
		e->unary_operator = (yyvsp[(1) - (2)].nPtr);
		e->unary_expression = (yyvsp[(2) - (2)].nPtr);
		
		(yyval.nPtr) = e;	
	;}
    break;

  case 18:
#line 269 "sintatic.yacc"
    {
		UNARY_EXPRESSION3 *e = malloc(sizeof(UNARY_EXPRESSION3));
		((DEFAULT_NODE *) e)->type = UNARY_EXPRESSION_CODE;
		((DEFAULT_NODE *) e)->subtype = UNARY_EXPRESSION3_CODE;
		e->unary_expression = (yyvsp[(2) - (2)].nPtr);
		
		(yyval.nPtr) = e;	
	;}
    break;

  case 19:
#line 279 "sintatic.yacc"
    {
		UNARY_EXPRESSION4 *e = malloc(sizeof(UNARY_EXPRESSION4));
		((DEFAULT_NODE *) e)->type = UNARY_EXPRESSION_CODE;
		((DEFAULT_NODE *) e)->subtype = UNARY_EXPRESSION4_CODE;
		e->type_name = (yyvsp[(3) - (4)].nPtr);
		
		(yyval.nPtr) = e;	
	;}
    break;

  case 20:
#line 291 "sintatic.yacc"
    {
		UNARY_OPERATOR *uop = malloc(sizeof(UNARY_OPERATOR));
		((DEFAULT_NODE *) uop)->type = UNARY_OPERATOR_CODE;
		uop->op = '&';
		
		(yyval.nPtr) = uop;
	;}
    break;

  case 21:
#line 300 "sintatic.yacc"
    {
		UNARY_OPERATOR *uop = malloc(sizeof(UNARY_OPERATOR));
		((DEFAULT_NODE *) uop)->type = UNARY_OPERATOR_CODE;
		uop->op = '*';
		
		(yyval.nPtr) = uop;
	;}
    break;

  case 22:
#line 309 "sintatic.yacc"
    {
		UNARY_OPERATOR *uop = malloc(sizeof(UNARY_OPERATOR));
		((DEFAULT_NODE *) uop)->type = UNARY_OPERATOR_CODE;
		uop->op = '+';
		
		(yyval.nPtr) = uop;
	;}
    break;

  case 23:
#line 318 "sintatic.yacc"
    {
		UNARY_OPERATOR *uop = malloc(sizeof(UNARY_OPERATOR));
		((DEFAULT_NODE *) uop)->type = UNARY_OPERATOR_CODE;
		uop->op = '-';
		
		(yyval.nPtr) = uop;
	;}
    break;

  case 24:
#line 327 "sintatic.yacc"
    {
		UNARY_OPERATOR *uop = malloc(sizeof(UNARY_OPERATOR));
		((DEFAULT_NODE *) uop)->type = UNARY_OPERATOR_CODE;
		uop->op = '~';
		
		(yyval.nPtr) = uop;
	;}
    break;

  case 25:
#line 336 "sintatic.yacc"
    {
		UNARY_OPERATOR *uop = malloc(sizeof(UNARY_OPERATOR));
		((DEFAULT_NODE *) uop)->type = UNARY_OPERATOR_CODE;
		uop->op = '!';
		
		(yyval.nPtr) = uop;
	;}
    break;

  case 26:
#line 348 "sintatic.yacc"
    {
		MULTIPLICATIVE_EXPRESSION *me = malloc(sizeof(MULTIPLICATIVE_EXPRESSION));
		((DEFAULT_NODE *) me)->type = MULTIPLICATIVE_EXPRESSION_CODE;
		me->unary_expression = (yyvsp[(1) - (1)].nPtr);
		me->multiplicative_expression = NULL;
		me->op = 0;
		
		(yyval.nPtr) = me;
	;}
    break;

  case 27:
#line 359 "sintatic.yacc"
    {
		MULTIPLICATIVE_EXPRESSION *me = malloc(sizeof(MULTIPLICATIVE_EXPRESSION));
		((DEFAULT_NODE *) me)->type = MULTIPLICATIVE_EXPRESSION_CODE;
		
		me->multiplicative_expression = (yyvsp[(1) - (3)].nPtr);
		me->op = '*';
		me->unary_expression = (yyvsp[(3) - (3)].nPtr);
		
		(yyval.nPtr) = me;
	;}
    break;

  case 28:
#line 371 "sintatic.yacc"
    {
		MULTIPLICATIVE_EXPRESSION *me = malloc(sizeof(MULTIPLICATIVE_EXPRESSION));
		((DEFAULT_NODE *) me)->type = MULTIPLICATIVE_EXPRESSION_CODE;
		
		me->multiplicative_expression = (yyvsp[(1) - (3)].nPtr);
		me->op = '/';
		me->unary_expression = (yyvsp[(3) - (3)].nPtr);
		
		(yyval.nPtr) = me;
	;}
    break;

  case 29:
#line 384 "sintatic.yacc"
    {
		MULTIPLICATIVE_EXPRESSION *me = malloc(sizeof(MULTIPLICATIVE_EXPRESSION));
		((DEFAULT_NODE *) me)->type = MULTIPLICATIVE_EXPRESSION_CODE;
		
		me->multiplicative_expression = (yyvsp[(1) - (3)].nPtr);
		me->op = '%';
		me->unary_expression = (yyvsp[(3) - (3)].nPtr);
		
		(yyval.nPtr) = me;
	;}
    break;

  case 30:
#line 401 "sintatic.yacc"
    {
		//puts("aqui");
		ADDITIVE_EXPRESSION *ae = malloc(sizeof(ADDITIVE_EXPRESSION));
		((DEFAULT_NODE *) ae)->type = ADDITIVE_EXPRESSION_CODE;
		ae->additive_expression = NULL;
		ae->multiplicative_expression = (yyvsp[(1) - (1)].nPtr);
		ae->op = 0;
		
		(yyval.nPtr) = ae;
	;}
    break;

  case 31:
#line 413 "sintatic.yacc"
    {
		//puts("aqui");
		ADDITIVE_EXPRESSION *ae = malloc(sizeof(ADDITIVE_EXPRESSION));
		((DEFAULT_NODE *) ae)->type = ADDITIVE_EXPRESSION_CODE;
		ae->additive_expression = (yyvsp[(1) - (3)].nPtr);
		ae->op = '+';
		ae->multiplicative_expression = (yyvsp[(3) - (3)].nPtr);
		
		
		(yyval.nPtr) = ae;
	;}
    break;

  case 32:
#line 426 "sintatic.yacc"
    {
		//puts("aqui");
		ADDITIVE_EXPRESSION *ae = malloc(sizeof(ADDITIVE_EXPRESSION));
		((DEFAULT_NODE *) ae)->type = ADDITIVE_EXPRESSION_CODE;
		ae->additive_expression = (yyvsp[(1) - (3)].nPtr);
		ae->op = '-';
		ae->multiplicative_expression = (yyvsp[(3) - (3)].nPtr);
		
		
		(yyval.nPtr) = ae;
	;}
    break;

  case 33:
#line 441 "sintatic.yacc"
    {
		SHIFT_EXPRESSION *se = malloc(sizeof(SHIFT_EXPRESSION));
		((DEFAULT_NODE *) se)->type = SHIFT_EXPRESSION_CODE;
		se->shift_expression = NULL;
		se->op = 0;
		se->additive_expression = (yyvsp[(1) - (1)].nPtr);
		
		(yyval.nPtr) = se;
	;}
    break;

  case 34:
#line 452 "sintatic.yacc"
    {
		SHIFT_EXPRESSION *se = malloc(sizeof(SHIFT_EXPRESSION));
		((DEFAULT_NODE *) se)->type = SHIFT_EXPRESSION_CODE;
		se->shift_expression = (yyvsp[(1) - (3)].nPtr);
		se->op = LEFT_OP;
		se->additive_expression = (yyvsp[(3) - (3)].nPtr);
		
		(yyval.nPtr) = se;
	;}
    break;

  case 35:
#line 463 "sintatic.yacc"
    {
		SHIFT_EXPRESSION *se = malloc(sizeof(SHIFT_EXPRESSION));
		((DEFAULT_NODE *) se)->type = SHIFT_EXPRESSION_CODE;
		se->shift_expression = (yyvsp[(1) - (3)].nPtr);
		se->op = RIGHT_OP;
		se->additive_expression = (yyvsp[(3) - (3)].nPtr);
		
		(yyval.nPtr) = se;
	;}
    break;

  case 36:
#line 478 "sintatic.yacc"
    {
		RELATIONAL_EXPRESSION *se = malloc(sizeof(RELATIONAL_EXPRESSION));
		((DEFAULT_NODE *) se)->type = RELATIONAL_EXPRESSION_CODE;
		se->relational_expression = NULL;
		se->op = 0;
		se->shift_expression = (yyvsp[(1) - (1)].nPtr);
		
		
		(yyval.nPtr) = se;
	;}
    break;

  case 37:
#line 490 "sintatic.yacc"
    {
		RELATIONAL_EXPRESSION *se = malloc(sizeof(RELATIONAL_EXPRESSION));
		((DEFAULT_NODE *) se)->type = RELATIONAL_EXPRESSION_CODE;
		se->relational_expression = (yyvsp[(1) - (3)].nPtr);
		se->op = '<';
		se->shift_expression = (yyvsp[(3) - (3)].nPtr);
		
		
		(yyval.nPtr) = se;
	;}
    break;

  case 38:
#line 502 "sintatic.yacc"
    {
		RELATIONAL_EXPRESSION *se = malloc(sizeof(RELATIONAL_EXPRESSION));
		((DEFAULT_NODE *) se)->type = RELATIONAL_EXPRESSION_CODE;
		se->relational_expression = (yyvsp[(1) - (3)].nPtr);
		se->op = '>';
		se->shift_expression = (yyvsp[(3) - (3)].nPtr);
		
		
		(yyval.nPtr) = se;
	;}
    break;

  case 39:
#line 514 "sintatic.yacc"
    {
		RELATIONAL_EXPRESSION *se = malloc(sizeof(RELATIONAL_EXPRESSION));
		((DEFAULT_NODE *) se)->type = RELATIONAL_EXPRESSION_CODE;
		se->relational_expression = (yyvsp[(1) - (3)].nPtr);
		se->op = LE_OP;
		se->shift_expression = (yyvsp[(3) - (3)].nPtr);
		
		
		(yyval.nPtr) = se;
	;}
    break;

  case 40:
#line 526 "sintatic.yacc"
    {
		RELATIONAL_EXPRESSION *se = malloc(sizeof(RELATIONAL_EXPRESSION));
		((DEFAULT_NODE *) se)->type = RELATIONAL_EXPRESSION_CODE;
		se->relational_expression = (yyvsp[(1) - (3)].nPtr);
		se->op = GE_OP;
		se->shift_expression = (yyvsp[(3) - (3)].nPtr);
		
		
		(yyval.nPtr) = se;
	;}
    break;

  case 41:
#line 541 "sintatic.yacc"
    {
		EQUALITY_EXPRESSION *se = malloc(sizeof(EQUALITY_EXPRESSION));
		((DEFAULT_NODE *) se)->type = EQUALITY_EXPRESSION_CODE;
		se->equality_expression = NULL;
		se->op = 0;
		se->relational_expression = (yyvsp[(1) - (1)].nPtr);
		
		
		(yyval.nPtr) = se;
	;}
    break;

  case 42:
#line 554 "sintatic.yacc"
    {
		EQUALITY_EXPRESSION *se = malloc(sizeof(EQUALITY_EXPRESSION));
		((DEFAULT_NODE *) se)->type = EQUALITY_EXPRESSION_CODE;
		se->equality_expression = (yyvsp[(1) - (3)].nPtr);
		se->op = EQ_OP;
		se->relational_expression = (yyvsp[(3) - (3)].nPtr);
		
		
		(yyval.nPtr) = se;
	;}
    break;

  case 43:
#line 566 "sintatic.yacc"
    {
		EQUALITY_EXPRESSION *se = malloc(sizeof(EQUALITY_EXPRESSION));
		((DEFAULT_NODE *) se)->type = EQUALITY_EXPRESSION_CODE;
		se->equality_expression = (yyvsp[(1) - (3)].nPtr);
		se->op = NE_OP;
		se->relational_expression = (yyvsp[(3) - (3)].nPtr);
		
		
		(yyval.nPtr) = se;
	;}
    break;

  case 44:
#line 581 "sintatic.yacc"
    {
		AND_EXPRESSION *se = malloc(sizeof(AND_EXPRESSION));
		((DEFAULT_NODE *) se)->type = AND_EXPRESSION_CODE;
		se->equality_expression = (yyvsp[(1) - (1)].nPtr);
		se->and_expression = NULL;
		
		
		(yyval.nPtr) = se;
	;}
    break;

  case 45:
#line 593 "sintatic.yacc"
    {
		AND_EXPRESSION *se = malloc(sizeof(AND_EXPRESSION));
		((DEFAULT_NODE *) se)->type = AND_EXPRESSION_CODE;
		se->and_expression = (yyvsp[(1) - (3)].nPtr);
		se->equality_expression = (yyvsp[(3) - (3)].nPtr);
		
		
		(yyval.nPtr) = se;
	;}
    break;

  case 46:
#line 607 "sintatic.yacc"
    {
		EXCLUSIVE_OR_EXPRESSION *se = malloc(sizeof(EXCLUSIVE_OR_EXPRESSION));
		((DEFAULT_NODE *) se)->type = EXCLUSIVE_OR_EXPRESSION_CODE;
		se->exclusive_or_expression = NULL;
		se->and_expression = (yyvsp[(1) - (1)].nPtr);
		
		
		(yyval.nPtr) = se;
	;}
    break;

  case 47:
#line 618 "sintatic.yacc"
    {
		EXCLUSIVE_OR_EXPRESSION *se = malloc(sizeof(EXCLUSIVE_OR_EXPRESSION));
		((DEFAULT_NODE *) se)->type = EXCLUSIVE_OR_EXPRESSION_CODE;
		se->exclusive_or_expression = (yyvsp[(1) - (3)].nPtr);
		se->and_expression = (yyvsp[(3) - (3)].nPtr);
		
		
		(yyval.nPtr) = se;
	;}
    break;

  case 48:
#line 633 "sintatic.yacc"
    {
		INCLUSIVE_OR_EXPRESSION *se = malloc(sizeof(INCLUSIVE_OR_EXPRESSION));
		((DEFAULT_NODE *) se)->type = INCLUSIVE_OR_EXPRESSION_CODE;
		se->inclusive_or_expression = NULL;
		se->exclusive_or_expression = (yyvsp[(1) - (1)].nPtr);	
		
		
		(yyval.nPtr) = se;
	;}
    break;

  case 49:
#line 645 "sintatic.yacc"
    {
		INCLUSIVE_OR_EXPRESSION *se = malloc(sizeof(INCLUSIVE_OR_EXPRESSION));
		((DEFAULT_NODE *) se)->type = INCLUSIVE_OR_EXPRESSION_CODE;
		se->inclusive_or_expression = (yyvsp[(1) - (3)].nPtr);
		se->exclusive_or_expression = (yyvsp[(3) - (3)].nPtr);	
		
		
		(yyval.nPtr) = se;
	;}
    break;

  case 50:
#line 659 "sintatic.yacc"
    {
		LOGICAL_AND_EXPRESSION *se = malloc(sizeof(LOGICAL_AND_EXPRESSION));
		((DEFAULT_NODE *) se)->type = LOGICAL_AND_EXPRESSION_CODE;
		se->logical_and_expression = NULL;
		se->inclusive_or_expression = (yyvsp[(1) - (1)].nPtr);	
		
		
		(yyval.nPtr) = se;
	;}
    break;

  case 51:
#line 670 "sintatic.yacc"
    {
		LOGICAL_AND_EXPRESSION *se = malloc(sizeof(LOGICAL_AND_EXPRESSION));
		((DEFAULT_NODE *) se)->type = LOGICAL_AND_EXPRESSION_CODE;
		se->logical_and_expression = (yyvsp[(1) - (3)].nPtr);
		se->inclusive_or_expression = (yyvsp[(3) - (3)].nPtr);	
		
		
		(yyval.nPtr) = se;
	;}
    break;

  case 52:
#line 684 "sintatic.yacc"
    {
		LOGICAL_OR_EXPRESSION *se = malloc(sizeof(LOGICAL_OR_EXPRESSION));
		((DEFAULT_NODE *) se)->type = LOGICAL_OR_EXPRESSION_CODE;
		se->logical_or_expression = NULL;
		se->logical_and_expression = (yyvsp[(1) - (1)].nPtr);	
		
		
		(yyval.nPtr) = se;
	;}
    break;

  case 53:
#line 695 "sintatic.yacc"
    {
		LOGICAL_OR_EXPRESSION *se = malloc(sizeof(LOGICAL_OR_EXPRESSION));
		((DEFAULT_NODE *) se)->type = LOGICAL_OR_EXPRESSION_CODE;
		se->logical_or_expression = (yyvsp[(1) - (3)].nPtr);
		se->logical_and_expression = (yyvsp[(3) - (3)].nPtr);	
		
		
		(yyval.nPtr) = se;
	;}
    break;

  case 54:
#line 710 "sintatic.yacc"
    {
		CONDITIONAL_EXPRESSION *se = malloc(sizeof(CONDITIONAL_EXPRESSION));
		((DEFAULT_NODE *) se)->type = CONDITIONAL_EXPRESSION_CODE;
		se->logical_or_expression = (yyvsp[(1) - (1)].nPtr);	
		
		
		(yyval.nPtr) = se;
	;}
    break;

  case 55:
#line 722 "sintatic.yacc"
    {
		ASSIGNMENT_EXPRESSION1 *se = malloc(sizeof(ASSIGNMENT_EXPRESSION1));
		((DEFAULT_NODE *) se)->type = ASSIGNMENT_EXPRESSION_CODE;
		((DEFAULT_NODE *) se)->subtype = ASSIGNMENT_EXPRESSION1_CODE;
		
		se->conditional_expression = (yyvsp[(1) - (1)].nPtr);
		
		(yyval.nPtr) = se;
	;}
    break;

  case 56:
#line 733 "sintatic.yacc"
    {
		ASSIGNMENT_EXPRESSION2 *se = malloc(sizeof(ASSIGNMENT_EXPRESSION2));
		((DEFAULT_NODE *) se)->type = ASSIGNMENT_EXPRESSION_CODE;
		((DEFAULT_NODE *) se)->subtype = ASSIGNMENT_EXPRESSION2_CODE;
		
		se->unary_expression = (yyvsp[(1) - (3)].nPtr);
		se->assignment_operator = (yyvsp[(2) - (3)].nPtr);
		se->assignment_expression = (yyvsp[(3) - (3)].nPtr);
		
		(yyval.nPtr) = se;
	;}
    break;

  case 57:
#line 749 "sintatic.yacc"
    {
		ASSIGNMENT_OPERATOR *se = malloc(sizeof(ASSIGNMENT_OPERATOR));
		((DEFAULT_NODE *) se)->type = ASSIGNMENT_OPERATOR_CODE;
		
		se->op = '=';
		
		(yyval.nPtr) = se;
	;}
    break;

  case 58:
#line 759 "sintatic.yacc"
    {
		ASSIGNMENT_OPERATOR *se = malloc(sizeof(ASSIGNMENT_OPERATOR));
		((DEFAULT_NODE *) se)->type = ASSIGNMENT_OPERATOR_CODE;
		
		se->op = MUL_ASSIGN;
		
		(yyval.nPtr) = se;
	;}
    break;

  case 59:
#line 769 "sintatic.yacc"
    {
		ASSIGNMENT_OPERATOR *se = malloc(sizeof(ASSIGNMENT_OPERATOR));
		((DEFAULT_NODE *) se)->type = ASSIGNMENT_OPERATOR_CODE;
		
		se->op = DIV_ASSIGN;
		
		(yyval.nPtr) = se;
	;}
    break;

  case 60:
#line 779 "sintatic.yacc"
    {
		ASSIGNMENT_OPERATOR *se = malloc(sizeof(ASSIGNMENT_OPERATOR));
		((DEFAULT_NODE *) se)->type = ASSIGNMENT_OPERATOR_CODE;
		
		se->op = ADD_ASSIGN;
		
		(yyval.nPtr) = se;
	;}
    break;

  case 61:
#line 789 "sintatic.yacc"
    {
		ASSIGNMENT_OPERATOR *se = malloc(sizeof(ASSIGNMENT_OPERATOR));
		((DEFAULT_NODE *) se)->type = ASSIGNMENT_OPERATOR_CODE;
		
		se->op = SUB_ASSIGN;
		
		(yyval.nPtr) = se;
	;}
    break;

  case 62:
#line 801 "sintatic.yacc"
    {	
		EXPRESSION *se = malloc(sizeof(EXPRESSION));
		((DEFAULT_NODE *) se)->type = EXPRESSION_CODE;
		
		se->assignment_expression = (yyvsp[(1) - (1)].nPtr);
		
		(yyval.nPtr) = se;
	;}
    break;

  case 63:
#line 811 "sintatic.yacc"
    {	
		EXPRESSION *se = malloc(sizeof(EXPRESSION));
		((DEFAULT_NODE *) se)->type = EXPRESSION_CODE;
		
		se->expression = (yyvsp[(1) - (3)].nPtr);
		se->assignment_expression = (yyvsp[(3) - (3)].nPtr);
		
		(yyval.nPtr) = se;
	;}
    break;

  case 64:
#line 825 "sintatic.yacc"
    {	
		CONSTANT_EXPRESSION *se = malloc(sizeof(CONSTANT_EXPRESSION));
		((DEFAULT_NODE *) se)->type = CONSTANT_EXPRESSION_CODE;
		
		se->conditional_expression = (yyvsp[(1) - (1)].nPtr);
		
		(yyval.nPtr) = se;
	;}
    break;

  case 65:
#line 837 "sintatic.yacc"
    {
		DECLARATION *se = malloc(sizeof(DECLARATION));
		((DEFAULT_NODE *) se)->type = DECLARATION_CODE;
		
		se->declaration_specifiers = (yyvsp[(1) - (2)].nPtr);
		se->init_declarator_list = NULL;
	
		(yyval.nPtr) = se;
	;}
    break;

  case 66:
#line 848 "sintatic.yacc"
    {
		DECLARATION *se = malloc(sizeof(DECLARATION));
		((DEFAULT_NODE *) se)->type = DECLARATION_CODE;
		
		se->declaration_specifiers = (yyvsp[(1) - (3)].nPtr);
		se->init_declarator_list = (yyvsp[(2) - (3)].nPtr);
	
		(yyval.nPtr) = se;
	;}
    break;

  case 67:
#line 864 "sintatic.yacc"
    {
		DECLARATION_SPECIFIERS *se = malloc(sizeof(DECLARATION_SPECIFIERS));
		((DEFAULT_NODE *) se)->type = DECLARATION_SPECIFIERS_CODE;
		
		se->type_specifier = (yyvsp[(1) - (1)].nPtr);
		se->declaration_specifiers = NULL;
	
		(yyval.nPtr) = se;
	;}
    break;

  case 68:
#line 875 "sintatic.yacc"
    {
		DECLARATION_SPECIFIERS *se = malloc(sizeof(DECLARATION_SPECIFIERS));
		((DEFAULT_NODE *) se)->type = DECLARATION_SPECIFIERS_CODE;
		
		se->type_specifier = (yyvsp[(1) - (2)].nPtr);
		se->declaration_specifiers = (yyvsp[(2) - (2)].nPtr);
	
		(yyval.nPtr) = se;
	;}
    break;

  case 69:
#line 888 "sintatic.yacc"
    {
		INIT_DECLARATOR_LIST *se = malloc(sizeof(INIT_DECLARATOR_LIST));
		((DEFAULT_NODE *) se)->type = INIT_DECLARATOR_LIST_CODE;
		
		se->init_declarator_list = NULL;
		se->init_declarator = (yyvsp[(1) - (1)].nPtr);
		
		(yyval.nPtr) = se;
	;}
    break;

  case 70:
#line 899 "sintatic.yacc"
    {
		INIT_DECLARATOR_LIST *se = malloc(sizeof(INIT_DECLARATOR_LIST));
		((DEFAULT_NODE *) se)->type = INIT_DECLARATOR_LIST_CODE;
		
		se->init_declarator_list = (yyvsp[(1) - (3)].nPtr);
		se->init_declarator = (yyvsp[(3) - (3)].nPtr);
		
		(yyval.nPtr) = se;
	;}
    break;

  case 71:
#line 913 "sintatic.yacc"
    {
		INIT_DECLARATOR *se = malloc(sizeof(INIT_DECLARATOR));
		((DEFAULT_NODE *) se)->type = INIT_DECLARATOR_CODE;
		
		se->declarator = (yyvsp[(1) - (1)].nPtr);
		se->initializer = NULL;
		
		(yyval.nPtr) = se;
	;}
    break;

  case 72:
#line 924 "sintatic.yacc"
    {
		INIT_DECLARATOR *se = malloc(sizeof(INIT_DECLARATOR));
		((DEFAULT_NODE *) se)->type = INIT_DECLARATOR_CODE;
		
		se->declarator = (yyvsp[(1) - (3)].nPtr);
		se->initializer = (yyvsp[(3) - (3)].nPtr);
		
		(yyval.nPtr) = se;
	;}
    break;

  case 73:
#line 939 "sintatic.yacc"
    {
		TYPE_SPECIFIER *se = malloc(sizeof(TYPE_SPECIFIER));
		((DEFAULT_NODE *) se)->type = TYPE_SPECIFIER_CODE;
		
		se->datatype = VOID;
		se->struct_or_union_specifier = NULL;
		
		(yyval.nPtr) = se;
	;}
    break;

  case 74:
#line 950 "sintatic.yacc"
    {
		TYPE_SPECIFIER *se = malloc(sizeof(TYPE_SPECIFIER));
		((DEFAULT_NODE *) se)->type = TYPE_SPECIFIER_CODE;
		
		se->datatype = CHAR;
		se->struct_or_union_specifier = NULL;
		
		(yyval.nPtr) = se;
	;}
    break;

  case 75:
#line 961 "sintatic.yacc"
    {
		TYPE_SPECIFIER *se = malloc(sizeof(TYPE_SPECIFIER));
		((DEFAULT_NODE *) se)->type = TYPE_SPECIFIER_CODE;
		
		se->datatype = INT;
		se->struct_or_union_specifier = NULL;
		
		(yyval.nPtr) = se;
	;}
    break;

  case 76:
#line 972 "sintatic.yacc"
    {
		TYPE_SPECIFIER *se = malloc(sizeof(TYPE_SPECIFIER));
		((DEFAULT_NODE *) se)->type = TYPE_SPECIFIER_CODE;
		
		se->datatype = FLOAT;
		se->struct_or_union_specifier = NULL;
		
		(yyval.nPtr) = se;
	;}
    break;

  case 77:
#line 983 "sintatic.yacc"
    {
		TYPE_SPECIFIER *se = malloc(sizeof(TYPE_SPECIFIER));
		((DEFAULT_NODE *) se)->type = TYPE_SPECIFIER_CODE;
		
		se->datatype = 0;
		se->struct_or_union_specifier = (yyvsp[(1) - (1)].nPtr);
		
		(yyval.nPtr) = se;
	;}
    break;

  case 78:
#line 994 "sintatic.yacc"
    {
		TYPE_SPECIFIER *se = malloc(sizeof(TYPE_SPECIFIER));
		((DEFAULT_NODE *) se)->type = TYPE_SPECIFIER_CODE;
		
		se->datatype = TYPE_NAME;
		se->struct_or_union_specifier = NULL;
		
		(yyval.nPtr) = se;
	;}
    break;

  case 79:
#line 1008 "sintatic.yacc"
    {
		STRUCT_OR_UNION_SPECIFIER1 *se = malloc(sizeof(STRUCT_OR_UNION_SPECIFIER1));
		((DEFAULT_NODE *) se)->type = STRUCT_OR_UNION_SPECIFIER_CODE;
		((DEFAULT_NODE *) se)->subtype = STRUCT_OR_UNION_SPECIFIER1_CODE;
		
		se->struct_or_union = (yyvsp[(1) - (5)].nPtr);
		se->identifier = (yyvsp[(2) - (5)].str);
		se->struct_declaration_list = (yyvsp[(4) - (5)].nPtr);
		
		(yyval.nPtr) = se;
	;}
    break;

  case 80:
#line 1022 "sintatic.yacc"
    {
		STRUCT_OR_UNION_SPECIFIER2 *se = malloc(sizeof(STRUCT_OR_UNION_SPECIFIER2));
		((DEFAULT_NODE *) se)->type = STRUCT_OR_UNION_SPECIFIER_CODE;
		((DEFAULT_NODE *) se)->subtype = STRUCT_OR_UNION_SPECIFIER2_CODE;
		
		se->struct_or_union = (yyvsp[(1) - (4)].nPtr);
		se->struct_declaration_list = (yyvsp[(3) - (4)].nPtr);
		
		(yyval.nPtr) = se;
	;}
    break;

  case 81:
#line 1034 "sintatic.yacc"
    {
		STRUCT_OR_UNION_SPECIFIER3 *se = malloc(sizeof(STRUCT_OR_UNION_SPECIFIER3));
		((DEFAULT_NODE *) se)->type = STRUCT_OR_UNION_SPECIFIER_CODE;
		((DEFAULT_NODE *) se)->subtype = STRUCT_OR_UNION_SPECIFIER3_CODE;
		
		se->struct_or_union = (yyvsp[(1) - (2)].nPtr);
		se->identifier = (yyvsp[(2) - (2)].str);
		
		(yyval.nPtr) = se;
	;}
    break;

  case 82:
#line 1050 "sintatic.yacc"
    {
		STRUCT_OR_UNION *s = malloc(sizeof(STRUCT_OR_UNION));
		((DEFAULT_NODE *) s)->type = STRUCT_OR_UNION_CODE;
		
		s->datatype = STRUCT;
		
		(yyval.nPtr) = s;
	;}
    break;

  case 83:
#line 1060 "sintatic.yacc"
    {
		STRUCT_OR_UNION *s = malloc(sizeof(STRUCT_OR_UNION));
		((DEFAULT_NODE *) s)->type = STRUCT_OR_UNION_CODE;
		
		s->datatype = UNION;
		
		(yyval.nPtr) = s;
	;}
    break;

  case 87:
#line 1081 "sintatic.yacc"
    {
		SPECIFIER_QUALIFIER_LIST *s = malloc(sizeof(SPECIFIER_QUALIFIER_LIST));
		((DEFAULT_NODE *) s)->type = SPECIFIER_QUALIFIER_LIST_CODE;
		
		s->type_specifier = (yyvsp[(1) - (2)].nPtr);
		s->specifier_qualifier_list = (yyvsp[(2) - (2)].nPtr);
	;}
    break;

  case 88:
#line 1090 "sintatic.yacc"
    {
		SPECIFIER_QUALIFIER_LIST *s = malloc(sizeof(SPECIFIER_QUALIFIER_LIST));
		((DEFAULT_NODE *) s)->type = SPECIFIER_QUALIFIER_LIST_CODE;
		
		s->type_specifier = (yyvsp[(1) - (1)].nPtr);
		s->specifier_qualifier_list = NULL;;
	;}
    break;

  case 94:
#line 1113 "sintatic.yacc"
    {	
		DECLARATOR *s = malloc(sizeof(DECLARATOR));
		((DEFAULT_NODE *) s)->type = DECLARATOR_CODE;
		
		s->pointer = (yyvsp[(1) - (2)].nPtr);
		s->direct_declarator = (yyvsp[(2) - (2)].nPtr);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 95:
#line 1124 "sintatic.yacc"
    {	
		DECLARATOR *s = malloc(sizeof(DECLARATOR));
		((DEFAULT_NODE *) s)->type = DECLARATOR_CODE;
		
		s->pointer = NULL;
		s->direct_declarator = (yyvsp[(1) - (1)].nPtr);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 96:
#line 1138 "sintatic.yacc"
    {	
		DIRECT_DECLARATOR1 *s = malloc(sizeof(DIRECT_DECLARATOR1));
		((DEFAULT_NODE *) s)->type = DIRECT_DECLARATOR_CODE;
		((DEFAULT_NODE *) s)->subtype = DIRECT_DECLARATOR1_CODE;
		
		int len = strlen((yyvsp[(1) - (1)].str));
		
		//char *str = malloc(len);
		//strcpy(str, $1);
		
		s->identifier = (yyvsp[(1) - (1)].str);
		
		//puts(str);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 97:
#line 1156 "sintatic.yacc"
    {	
		DIRECT_DECLARATOR2 *s = malloc(sizeof(DIRECT_DECLARATOR2));
		((DEFAULT_NODE *) s)->type = DIRECT_DECLARATOR_CODE;
		((DEFAULT_NODE *) s)->subtype = DIRECT_DECLARATOR2_CODE;
		
		s->declarator = (yyvsp[(2) - (3)].nPtr);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 98:
#line 1167 "sintatic.yacc"
    {	
		DIRECT_DECLARATOR3 *s = malloc(sizeof(DIRECT_DECLARATOR3));
		((DEFAULT_NODE *) s)->type = DIRECT_DECLARATOR_CODE;
		((DEFAULT_NODE *) s)->subtype = DIRECT_DECLARATOR3_CODE;
		
		s->direct_declarator = (yyvsp[(1) - (4)].nPtr);
		s->constant = (yyvsp[(3) - (4)].ivalue);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 99:
#line 1179 "sintatic.yacc"
    {	
		DIRECT_DECLARATOR3 *s = malloc(sizeof(DIRECT_DECLARATOR3));
		((DEFAULT_NODE *) s)->type = DIRECT_DECLARATOR_CODE;
		((DEFAULT_NODE *) s)->subtype = DIRECT_DECLARATOR3_CODE;
		
		s->direct_declarator = (yyvsp[(1) - (3)].nPtr);
		s->constant = 0;
		
		(yyval.nPtr) = s;
	;}
    break;

  case 100:
#line 1191 "sintatic.yacc"
    {	
		DIRECT_DECLARATOR4 *s = malloc(sizeof(DIRECT_DECLARATOR4));
		((DEFAULT_NODE *) s)->type = DIRECT_DECLARATOR_CODE;
		((DEFAULT_NODE *) s)->subtype = DIRECT_DECLARATOR4_CODE;
		
		s->direct_declarator = (yyvsp[(1) - (4)].nPtr);
		s->parameter_type_list = (yyvsp[(3) - (4)].nPtr);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 101:
#line 1203 "sintatic.yacc"
    {	
		DIRECT_DECLARATOR5 *s = malloc(sizeof(DIRECT_DECLARATOR5));
		((DEFAULT_NODE *) s)->type = DIRECT_DECLARATOR_CODE;
		((DEFAULT_NODE *) s)->subtype = DIRECT_DECLARATOR5_CODE;
		
		s->direct_declarator = (yyvsp[(1) - (4)].nPtr);
		s->identifier_list = (yyvsp[(3) - (4)].nPtr);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 102:
#line 1215 "sintatic.yacc"
    {	
		DIRECT_DECLARATOR4 *s = malloc(sizeof(DIRECT_DECLARATOR4));
		((DEFAULT_NODE *) s)->type = DIRECT_DECLARATOR_CODE;
		((DEFAULT_NODE *) s)->subtype = DIRECT_DECLARATOR4_CODE;
		
		//puts("aqui");
		s->direct_declarator = (yyvsp[(1) - (3)].nPtr);
		s->parameter_type_list = NULL;
		
		(yyval.nPtr) = s;
	;}
    break;

  case 103:
#line 1231 "sintatic.yacc"
    {
		POINTER *s = malloc(sizeof(POINTER));
		((DEFAULT_NODE *) s)->type = POINTER_CODE;
		
		s->pointer = NULL;
		
		(yyval.nPtr) = s;
	;}
    break;

  case 104:
#line 1241 "sintatic.yacc"
    {
		POINTER *s = malloc(sizeof(POINTER));
		((DEFAULT_NODE *) s)->type = POINTER_CODE;
		
		s->pointer = (yyvsp[(2) - (2)].nPtr);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 105:
#line 1254 "sintatic.yacc"
    {
		PARAMETER_TYPE_LIST *s = malloc(sizeof(PARAMETER_TYPE_LIST));
		((DEFAULT_NODE *) s)->type = PARAMETER_TYPE_LIST_CODE;
		
		s->parameter_list = (yyvsp[(1) - (1)].nPtr);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 106:
#line 1266 "sintatic.yacc"
    {
		PARAMETER_LIST *p = malloc(sizeof(PARAMETER_LIST));
		((DEFAULT_NODE *) p)->type = PARAMETER_LIST_CODE;
		p->parameter_declaration = (yyvsp[(1) - (1)].nPtr);
		p->parameter_list = NULL;
		
		(yyval.nPtr) = p;
	
	;}
    break;

  case 107:
#line 1276 "sintatic.yacc"
    {
		PARAMETER_LIST *p = malloc(sizeof(PARAMETER_LIST));
		((DEFAULT_NODE *) p)->type = PARAMETER_LIST_CODE;
		p->parameter_declaration = (yyvsp[(3) - (3)].nPtr);
		p->parameter_list = (yyvsp[(1) - (3)].nPtr);
		
		(yyval.nPtr) = p;
	;}
    break;

  case 108:
#line 1288 "sintatic.yacc"
    {
		PARAMETER_DECLARATION1 *p = malloc(sizeof(PARAMETER_DECLARATION1));
		((DEFAULT_NODE *) p)->type = PARAMETER_DECLARATION_CODE;
		((DEFAULT_NODE *) p)->subtype = PARAMETER_DECLARATION1_CODE;
		
		p->declaration_specifiers = (yyvsp[(1) - (2)].nPtr);
		p->declarator = (yyvsp[(2) - (2)].nPtr);
	
		//puts("Este1");
		(yyval.nPtr) = p;
	
	;}
    break;

  case 109:
#line 1301 "sintatic.yacc"
    {
		
		//puts("Este2");
	;}
    break;

  case 110:
#line 1306 "sintatic.yacc"
    {
	
		//puts("Este3");
	;}
    break;

  case 111:
#line 1314 "sintatic.yacc"
    {
		IDENTIFIER_LIST *s = malloc(sizeof(IDENTIFIER_LIST));
		((DEFAULT_NODE *) s)->type = IDENTIFIER_LIST_CODE;
		
		s->identifier = (yyvsp[(1) - (1)].str);
		s->identifier_list = NULL;
		
		(yyval.nPtr) = s;
		
	;}
    break;

  case 112:
#line 1326 "sintatic.yacc"
    {
		IDENTIFIER_LIST *s = malloc(sizeof(IDENTIFIER_LIST));
		((DEFAULT_NODE *) s)->type = IDENTIFIER_LIST_CODE;
		
		s->identifier = (yyvsp[(3) - (3)].str);
		s->identifier_list = (yyvsp[(1) - (3)].nPtr);
		
		(yyval.nPtr) = s;
		
	;}
    break;

  case 113:
#line 1341 "sintatic.yacc"
    {
		TYPE_NAMEi *s = malloc(sizeof(TYPE_NAMEi));
		((DEFAULT_NODE *) s)->type = TYPE_NAMEi_CODE;
		
		s->specifier_qualifier_list  = (yyvsp[(1) - (1)].nPtr);
		s->abstract_declarator = NULL;
	;}
    break;

  case 114:
#line 1350 "sintatic.yacc"
    {
		TYPE_NAMEi *s = malloc(sizeof(TYPE_NAMEi));
		((DEFAULT_NODE *) s)->type = TYPE_NAMEi_CODE;
		
		s->specifier_qualifier_list  = (yyvsp[(1) - (2)].nPtr);
		s->abstract_declarator = (yyvsp[(2) - (2)].nPtr);
	;}
    break;

  case 127:
#line 1379 "sintatic.yacc"
    {
		INITIALIZER1 *i = malloc(sizeof(INITIALIZER1));
		((DEFAULT_NODE *) i)->type = INITIALIZER_CODE;
		((DEFAULT_NODE *) i)->subtype = INITIALIZER1_CODE;
		
		i->assignment_expression = (yyvsp[(1) - (1)].nPtr);
	
		(yyval.nPtr) = i;
	;}
    break;

  case 130:
#line 1394 "sintatic.yacc"
    {
		INITIALIZER_LIST *s = malloc(sizeof(INITIALIZER_LIST));
		((DEFAULT_NODE *) s)->type = INITIALIZER_LIST_CODE;
		
		s->initializer_list = NULL;
		s->initializer = (yyvsp[(1) - (1)].nPtr);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 131:
#line 1404 "sintatic.yacc"
    {
		INITIALIZER_LIST *s = malloc(sizeof(INITIALIZER_LIST));
		((DEFAULT_NODE *) s)->type = INITIALIZER_LIST_CODE;
		
		s->initializer_list = (yyvsp[(1) - (3)].nPtr);
		s->initializer = (yyvsp[(3) - (3)].nPtr);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 132:
#line 1418 "sintatic.yacc"
    {
		STATEMENT1 *s = malloc(sizeof(STATEMENT1));
		((DEFAULT_NODE *) s)->type = STATEMENT_CODE;
		((DEFAULT_NODE *) s)->subtype = STATEMENT1_CODE;
		
		s->labeled_statement = (yyvsp[(1) - (1)].nPtr);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 133:
#line 1429 "sintatic.yacc"
    {
		STATEMENT2 *s = malloc(sizeof(STATEMENT2));
		((DEFAULT_NODE *) s)->type = STATEMENT_CODE;
		((DEFAULT_NODE *) s)->subtype = STATEMENT2_CODE;
		
		s->compound_statement = (yyvsp[(1) - (1)].nPtr);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 134:
#line 1440 "sintatic.yacc"
    {
		STATEMENT3 *s = malloc(sizeof(STATEMENT3));
		((DEFAULT_NODE *) s)->type = STATEMENT_CODE;
		((DEFAULT_NODE *) s)->subtype = STATEMENT3_CODE;
		
		s->expression_statement = (yyvsp[(1) - (1)].nPtr);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 135:
#line 1451 "sintatic.yacc"
    {
		STATEMENT4 *s = malloc(sizeof(STATEMENT4));
		((DEFAULT_NODE *) s)->type = STATEMENT_CODE;
		((DEFAULT_NODE *) s)->subtype = STATEMENT4_CODE;
		
		s->selection_statement = (yyvsp[(1) - (1)].nPtr);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 136:
#line 1462 "sintatic.yacc"
    {
		STATEMENT5 *s = malloc(sizeof(STATEMENT5));
		((DEFAULT_NODE *) s)->type = STATEMENT_CODE;
		((DEFAULT_NODE *) s)->subtype = STATEMENT5_CODE;
		
		s->function_definition = (yyvsp[(1) - (1)].nPtr);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 137:
#line 1473 "sintatic.yacc"
    {
		STATEMENT6 *s = malloc(sizeof(STATEMENT6));
		((DEFAULT_NODE *) s)->type = STATEMENT_CODE;
		((DEFAULT_NODE *) s)->subtype = STATEMENT6_CODE;
		
		s->iteration_statement = (yyvsp[(1) - (1)].nPtr);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 138:
#line 1484 "sintatic.yacc"
    {
		STATEMENT7 *s = malloc(sizeof(STATEMENT7));
		((DEFAULT_NODE *) s)->type = STATEMENT_CODE;
		((DEFAULT_NODE *) s)->subtype = STATEMENT7_CODE;
		
		s->jump_statement = (yyvsp[(1) - (1)].nPtr);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 139:
#line 1498 "sintatic.yacc"
    {
		LABELED_STATEMENT1 *s = malloc(sizeof(LABELED_STATEMENT1));
		((DEFAULT_NODE *) s)->type = LABELED_STATEMENT_CODE;
		((DEFAULT_NODE *) s)->subtype = LABELED_STATEMENT1_CODE;
		
		s->identifier = (yyvsp[(1) - (3)].str);
		s->statement = (yyvsp[(3) - (3)].nPtr);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 140:
#line 1510 "sintatic.yacc"
    {
		LABELED_STATEMENT2 *s = malloc(sizeof(LABELED_STATEMENT2));
		((DEFAULT_NODE *) s)->type = LABELED_STATEMENT_CODE;
		((DEFAULT_NODE *) s)->subtype = LABELED_STATEMENT2_CODE;
		
		s->constant_expression = (yyvsp[(2) - (4)].nPtr);
		s->statement = (yyvsp[(4) - (4)].nPtr);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 141:
#line 1522 "sintatic.yacc"
    {
		LABELED_STATEMENT3 *s = malloc(sizeof(LABELED_STATEMENT3));
		((DEFAULT_NODE *) s)->type = LABELED_STATEMENT_CODE;
		((DEFAULT_NODE *) s)->subtype = LABELED_STATEMENT3_CODE;
		
		s->statement = (yyvsp[(3) - (3)].nPtr);
		
		(yyval.nPtr) = s;
	;}
    break;

  case 142:
#line 1536 "sintatic.yacc"
    {
		COMPOUND_STATEMENT *s = malloc(sizeof(COMPOUND_STATEMENT));
		((DEFAULT_NODE *) s)->type = COMPOUND_STATEMENT_CODE;
		
		s->statement_list = NULL;
		s->declaration_list = NULL;
		//puts("aqui");
		
		(yyval.nPtr) = s;
	;}
    break;

  case 143:
#line 1548 "sintatic.yacc"
    {
		COMPOUND_STATEMENT *s = malloc(sizeof(COMPOUND_STATEMENT));
		((DEFAULT_NODE *) s)->type = COMPOUND_STATEMENT_CODE;
		
		s->statement_list = (yyvsp[(2) - (3)].nPtr);
		s->declaration_list = NULL;
		//puts("aqui1");
		(yyval.nPtr) = s;
	;}
    break;

  case 144:
#line 1559 "sintatic.yacc"
    {
		COMPOUND_STATEMENT *s = malloc(sizeof(COMPOUND_STATEMENT));
		((DEFAULT_NODE *) s)->type = COMPOUND_STATEMENT_CODE;
		
		s->statement_list = NULL;
		s->declaration_list = (yyvsp[(2) - (3)].nPtr);
		//puts("aqui2");
		(yyval.nPtr) = s;
	;}
    break;

  case 145:
#line 1571 "sintatic.yacc"
    {
		COMPOUND_STATEMENT *s = malloc(sizeof(COMPOUND_STATEMENT));
		((DEFAULT_NODE *) s)->type = COMPOUND_STATEMENT_CODE;
		
		s->statement_list = (yyvsp[(3) - (4)].nPtr);
		s->declaration_list = (yyvsp[(2) - (4)].nPtr);
		//puts("aqui3");
		(yyval.nPtr) = s;
	;}
    break;

  case 146:
#line 1585 "sintatic.yacc"
    {
		DECLARATION_LIST *sel = malloc(sizeof(DECLARATION_LIST));
		((DEFAULT_NODE *) sel)->type = DECLARATION_LIST_CODE;
		sel->declaration = (yyvsp[(1) - (1)].nPtr);
		sel->declaration_list = NULL;
		
		(yyval.nPtr) = sel;
	;}
    break;

  case 147:
#line 1596 "sintatic.yacc"
    {
		DECLARATION_LIST *sel = malloc(sizeof(DECLARATION_LIST));
		((DEFAULT_NODE *) sel)->type = DECLARATION_LIST_CODE;
		sel->declaration = (yyvsp[(2) - (2)].nPtr);
		sel->declaration_list = (yyvsp[(1) - (2)].nPtr);
		
		(yyval.nPtr) = sel;
	;}
    break;

  case 148:
#line 1608 "sintatic.yacc"
    {
		STATEMENT_LIST *sel = malloc(sizeof(STATEMENT_LIST));
		((DEFAULT_NODE *) sel)->type = STATEMENT_LIST_CODE;
		sel->statement = (yyvsp[(1) - (1)].nPtr);
		sel->statement_list = NULL;
		
		(yyval.nPtr) = sel;
	;}
    break;

  case 149:
#line 1619 "sintatic.yacc"
    {
		STATEMENT_LIST *sel = malloc(sizeof(STATEMENT_LIST));
		((DEFAULT_NODE *) sel)->type = STATEMENT_LIST_CODE;
		sel->statement = (yyvsp[(2) - (2)].nPtr);
		sel->statement_list = (yyvsp[(1) - (2)].nPtr);
		
		(yyval.nPtr) = sel;
	;}
    break;

  case 150:
#line 1631 "sintatic.yacc"
    {
		EXPRESSION_STATEMENT *sel = malloc(sizeof(EXPRESSION_STATEMENT));
		((DEFAULT_NODE *) sel)->type = EXPRESSION_STATEMENT_CODE;
		sel->expression = NULL;
		
		(yyval.nPtr) = sel;
	;}
    break;

  case 151:
#line 1640 "sintatic.yacc"
    {
		//puts("esp....");
		EXPRESSION_STATEMENT *sel = malloc(sizeof(EXPRESSION_STATEMENT));
		((DEFAULT_NODE *) sel)->type = EXPRESSION_STATEMENT_CODE;
		sel->expression = (yyvsp[(1) - (2)].nPtr);
		
		(yyval.nPtr) = sel;
		
		
	;}
    break;

  case 153:
#line 1656 "sintatic.yacc"
    {
		SELECTION_STATEMENT *sel = malloc(sizeof(SELECTION_STATEMENT));
		((DEFAULT_NODE *) sel)->type = SELECTION_STATEMENT_CODE;
		sel->expression = (yyvsp[(3) - (5)].nPtr);
		sel->statement = (yyvsp[(5) - (5)].nPtr);
		sel->statement2 = NULL;
		
		(yyval.nPtr) = sel;
	;}
    break;

  case 154:
#line 1666 "sintatic.yacc"
    {
		SELECTION_STATEMENT *sel = malloc(sizeof(SELECTION_STATEMENT));
		((DEFAULT_NODE *) sel)->type = SELECTION_STATEMENT_CODE;
		sel->expression = (yyvsp[(3) - (7)].nPtr);
		sel->statement = (yyvsp[(5) - (7)].nPtr);
		sel->statement2 = (yyvsp[(7) - (7)].nPtr);
		
		(yyval.nPtr) = sel;
	;}
    break;

  case 155:
#line 1679 "sintatic.yacc"
    {
		//puts("WHILE NODE1");
		ITERATION_STATEMENT *it = malloc(sizeof(ITERATION_STATEMENT));
		((POSTFIX_ESPRESSION *) it)->type = ITERATION_STATEMENT_CODE;
		((POSTFIX_ESPRESSION *) it)->subtype = WHILE;
		it->expression = (yyvsp[(3) - (5)].nPtr);
		it->statement = (yyvsp[(5) - (5)].nPtr);
		
		(yyval.nPtr) = it;
	;}
    break;

  case 156:
#line 1690 "sintatic.yacc"
    {
		//puts("DO WHILE NODE");
		ITERATION_STATEMENT *it = malloc(sizeof(ITERATION_STATEMENT));
		((POSTFIX_ESPRESSION *) it)->type = ITERATION_STATEMENT_CODE;
		((POSTFIX_ESPRESSION *) it)->subtype = DO+WHILE;
		it->expression = (yyvsp[(5) - (7)].nPtr);
		it->statement = (yyvsp[(2) - (7)].nPtr);
		
		(yyval.nPtr) = it;
	;}
    break;

  case 157:
#line 1706 "sintatic.yacc"
    {
		JUMP_STATEMENT *jmp = malloc(sizeof(JUMP_STATEMENT));
		((DEFAULT_NODE *) jmp)->type = JUMP_STATEMENT_CODE;
		
		jmp->jump = GOTO;
		jmp->identifier = (yyvsp[(2) - (3)].str);
		jmp->expression = NULL;
		
		(yyval.nPtr) = jmp;
	;}
    break;

  case 158:
#line 1718 "sintatic.yacc"
    {
		JUMP_STATEMENT *jmp = malloc(sizeof(JUMP_STATEMENT));
		((DEFAULT_NODE *) jmp)->type = JUMP_STATEMENT_CODE;
		
		jmp->jump = CONTINUE;
		jmp->identifier = NULL;
		jmp->expression = NULL;
		
		(yyval.nPtr) = jmp;
	;}
    break;

  case 159:
#line 1730 "sintatic.yacc"
    {
		JUMP_STATEMENT *jmp = malloc(sizeof(JUMP_STATEMENT));
		((DEFAULT_NODE *) jmp)->type = JUMP_STATEMENT_CODE;
		
		jmp->jump = BREAK;
		jmp->identifier = NULL;
		jmp->expression = NULL;
		
		(yyval.nPtr) = jmp;
	;}
    break;

  case 160:
#line 1742 "sintatic.yacc"
    {
		JUMP_STATEMENT *jmp = malloc(sizeof(JUMP_STATEMENT));
		((DEFAULT_NODE *) jmp)->type = JUMP_STATEMENT_CODE;
		
		jmp->jump = RETURN;
		jmp->identifier = NULL;
		jmp->expression = NULL;
		
		(yyval.nPtr) = jmp;
	;}
    break;

  case 161:
#line 1754 "sintatic.yacc"
    {
		JUMP_STATEMENT *jmp = malloc(sizeof(JUMP_STATEMENT));
		((DEFAULT_NODE *) jmp)->type = JUMP_STATEMENT_CODE;
		
		jmp->jump = RETURN;
		jmp->identifier = NULL;
		jmp->expression = (yyvsp[(2) - (3)].nPtr);
		
		(yyval.nPtr) = jmp;
	;}
    break;

  case 162:
#line 1769 "sintatic.yacc"
    { 
		//puts("\nTU1");
		TRANSLATION_UNIT *a =  malloc(sizeof(TRANSLATION_UNIT));
		a->ext_decl = (yyvsp[(1) - (1)].nPtr);
		a->trans_unit = NULL;
		(yyval.nPtr) = a;
		//semantic_entry(a);
		aa = a;
								
	;}
    break;

  case 163:
#line 1780 "sintatic.yacc"
    {
		//puts("\nTU2 NODE");
		TRANSLATION_UNIT *a =  malloc(sizeof(TRANSLATION_UNIT));
		a->ext_decl = (yyvsp[(2) - (2)].nPtr);
		a->trans_unit = (yyvsp[(1) - (2)].nPtr);
		(yyval.nPtr) = a;
		//semantic_entry(a);
		aa = a;
	;}
    break;

  case 164:
#line 1793 "sintatic.yacc"
    {
		//puts("Montando EXTERNAL DECLARATION1 NODE");
		(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
	;}
    break;

  case 165:
#line 1798 "sintatic.yacc"
    {
		//puts("Montando EXTERNAL DECLARATION2 NODE");
		(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
	;}
    break;

  case 166:
#line 1807 "sintatic.yacc"
    {//1
		//puts("FUNCTION_DEFINITION1 NODE");
		
		FUNCTION_DEFINITION1 *f = malloc(sizeof(FUNCTION_DEFINITION1));
		//((EXTERNAL_DECLARATION*) f)->type = EXTERNAL_DECLARATION_CODE;
		//((EXTERNAL_DECLARATION*) f)->subtype = FUNCTION1_DEFINITION_CODE;
		((EXTERNAL_DECLARATION*) f)->type = FUNCTION_DEFINITION_CODE;
		((EXTERNAL_DECLARATION*) f)->subtype = FUNCTION1_DEFINITION_CODE;
		
		
		f->dec_specifier = (yyvsp[(1) - (4)].nPtr);
		f->declarator = (yyvsp[(2) - (4)].nPtr);
		f->declaration_list = (yyvsp[(3) - (4)].nPtr);
		f->compound_statement = (yyvsp[(4) - (4)].nPtr);
		(yyval.nPtr) = f;
	;}
    break;

  case 167:
#line 1824 "sintatic.yacc"
    { 
		//puts("FUNCTION_DEFINITION2 NODE");
		
		FUNCTION_DEFINITION2 *f = malloc(sizeof(FUNCTION_DEFINITION2));
		((EXTERNAL_DECLARATION*) f)->type = FUNCTION_DEFINITION_CODE;
		((EXTERNAL_DECLARATION*) f)->subtype = FUNCTION2_DEFINITION_CODE;
		
		
		f->dec_specifier = (yyvsp[(1) - (3)].nPtr);
		f->declarator = (yyvsp[(2) - (3)].nPtr);
		f->compound_statement = (yyvsp[(3) - (3)].nPtr);
		
		//printf("%d \n", f->compound_statement->type);
		
		(yyval.nPtr) = f;
	;}
    break;


/* Line 1267 of yacc.c.  */
#line 3694 "sint.c"
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


#line 1843 "sintatic.yacc"

#include <stdio.h>
#include "../include/compiler.h"


//extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
	erro = 1;
}

