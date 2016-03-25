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
#line 1 "src/c_parser.y" /* yacc.c:339  */

#include <iostream>
#include <cstdlib>
#include <string>
#include "../src/ast.hpp"

int yylex();
int yyerror(const char* s);
using namespace std;
Context cont = Context();
Node* topNode;

#line 79 "bin/c_parser.tab.cpp" /* yacc.c:339  */

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
   by #include "c_parser.tab.hpp".  */
#ifndef YY_YY_BIN_C_PARSER_TAB_HPP_INCLUDED
# define YY_YY_BIN_C_PARSER_TAB_HPP_INCLUDED
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
    TAuto = 258,
    TDouble = 259,
    TInt = 260,
    TStruct = 261,
    TBreak = 262,
    TElse = 263,
    TLong = 264,
    TSwitch = 265,
    TCase = 266,
    TEnum = 267,
    TRegister = 268,
    TTypedef = 269,
    TChar = 270,
    TExtern = 271,
    TReturn = 272,
    TUnion = 273,
    TConst = 274,
    TFloat = 275,
    TShort = 276,
    TUnsigned = 277,
    TContinue = 278,
    TFor = 279,
    TSigned = 280,
    TVoid = 281,
    TDefault = 282,
    TGoto = 283,
    TVolatile = 284,
    TDo = 285,
    TIf = 286,
    TStatic = 287,
    TWhile = 288,
    TSizeof = 289,
    TOpenSqBracket = 290,
    TCloseSqBracket = 291,
    TOpenBracket = 292,
    TCloseBracket = 293,
    TDot = 294,
    TBitwiseAnd = 295,
    TStar = 296,
    TPlus = 297,
    TMinus = 298,
    TTilde = 299,
    TBang = 300,
    TSlash = 301,
    TPercent = 302,
    TGreater = 303,
    TLess = 304,
    TCarat = 305,
    TPipe = 306,
    TQuestion = 307,
    TColon = 308,
    TAssign = 309,
    TComma = 310,
    TArrow = 311,
    TIncrement = 312,
    TDecrement = 313,
    TLeftShift = 314,
    TRightShift = 315,
    TLessEqual = 316,
    TGreaterEqual = 317,
    TEquals = 318,
    TNotEqual = 319,
    TLogicalAnd = 320,
    TLogicalOr = 321,
    TStarEquals = 322,
    TSlashEquals = 323,
    TPercentEquals = 324,
    TPlusEquals = 325,
    TMinusEquals = 326,
    TLeftShiftEquals = 327,
    TRightShiftEquals = 328,
    TAndEquals = 329,
    TCaratEquals = 330,
    TPipeEquals = 331,
    TOpenCurlyBrace = 332,
    TCloseCurlyBrace = 333,
    TSemicolon = 334,
    TEllipsis = 335,
    TCharConstVal = 336,
    TIntVal = 337,
    TFloatVal = 338,
    TStringLit = 339,
    TIdentifier = 340,
    TNewline = 341
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "src/c_parser.y" /* yacc.c:355  */

  char* string;
  int num;
  double floatnum;
  class Expression* ExpPtr;
  class Statement* StatPtr;
  class StatList* StatListPtr;
  class PaList* ParamListPtr;
  class Declarator* DecPtr;
  class Parameter* ParamPtr;
  class DecList* DecListPtr;
  class FuncDef* FuncDefPtr;

#line 220 "bin/c_parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BIN_C_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 237 "bin/c_parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   223

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   341

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    45,    45,    51,    54,    58,    63,    65,    67,    72,
      76,    81,    85,    90,    93,    97,    97,    97,    97,    99,
     104,   107,   112,   115,   119,   122,   125,   130,   135,   140,
     145,   150,   155,   160,   165,   170,   175,   182,   189,   196,
     203,   206,   209,   212,   215,   218,   221,   224,   227,   230,
     233,   236,   239,   242,   245,   248,   251,   254,   257,   260,
     263,   266,   269,   272,   275,   279,   282,   285,   288,   291,
     293,   295,   298,   301,   303
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TAuto", "TDouble", "TInt", "TStruct",
  "TBreak", "TElse", "TLong", "TSwitch", "TCase", "TEnum", "TRegister",
  "TTypedef", "TChar", "TExtern", "TReturn", "TUnion", "TConst", "TFloat",
  "TShort", "TUnsigned", "TContinue", "TFor", "TSigned", "TVoid",
  "TDefault", "TGoto", "TVolatile", "TDo", "TIf", "TStatic", "TWhile",
  "TSizeof", "TOpenSqBracket", "TCloseSqBracket", "TOpenBracket",
  "TCloseBracket", "TDot", "TBitwiseAnd", "TStar", "TPlus", "TMinus",
  "TTilde", "TBang", "TSlash", "TPercent", "TGreater", "TLess", "TCarat",
  "TPipe", "TQuestion", "TColon", "TAssign", "TComma", "TArrow",
  "TIncrement", "TDecrement", "TLeftShift", "TRightShift", "TLessEqual",
  "TGreaterEqual", "TEquals", "TNotEqual", "TLogicalAnd", "TLogicalOr",
  "TStarEquals", "TSlashEquals", "TPercentEquals", "TPlusEquals",
  "TMinusEquals", "TLeftShiftEquals", "TRightShiftEquals", "TAndEquals",
  "TCaratEquals", "TPipeEquals", "TOpenCurlyBrace", "TCloseCurlyBrace",
  "TSemicolon", "TEllipsis", "TCharConstVal", "TIntVal", "TFloatVal",
  "TStringLit", "TIdentifier", "TNewline", "$accept", "FunctionDef",
  "Paraml", "ParamDec", "CompoundStat", "Statementlist", "Declaratorlist",
  "Declarator", "Statement", "IterStat", "JumpStat", "ExpStat", "Exp",
  "AssignmentExp", "LogicalOrExp", "LogicalAndExp", "OrExp", "XorExp",
  "AndExp", "EqualityExp", "RelationalExp", "ShiftExp", "AdditiveExp",
  "MultExp", "UnaryExp", "PrimaryExp", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341
};
# endif

#define YYPACT_NINF -74

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-74)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -73,    19,   -12,   -74,    18,   -53,   -20,   -74,   -74,
     -38,    18,    56,   -74,   -74,   -44,    94,     6,   -13,    87,
      87,   -29,   -29,   -74,   -74,   -74,   -74,    68,     9,   -74,
     -74,   -74,   -74,   -74,   -32,   -74,   -74,    -1,   -16,    17,
      20,    50,   -27,   -28,    -5,    53,   -74,   134,   -48,   -74,
      21,   -13,    59,   -74,   -19,   -74,   -74,   -74,   -74,   -74,
     -74,    85,   -74,   -74,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,   -13,   -74,   -74,   -13,   -13,   -13,   -13,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,   -74,   -74,    70,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
      30,   -38,   -74,   -74
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     3,     5,
       0,     0,     0,     2,     4,     0,     0,     0,     0,     0,
       0,     0,     0,    23,    73,    72,    18,     0,     0,    11,
       9,    17,    15,    16,     0,    24,    40,    42,    44,    46,
      48,    50,    53,    58,    61,    64,    68,    71,     0,    21,
       0,     0,     0,    70,    71,    69,    37,    38,     7,    10,
       8,     0,    12,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    20,     0,    74,
       6,    41,    43,    45,    47,    49,    51,    52,    54,    55,
      57,    56,    59,    60,    62,    63,    65,    66,    67,    25,
      27,    28,    29,    26,    30,    31,    32,    33,    34,    35,
       0,     0,    14,    19
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   101,   -10,    89,   -74,    91,   -23,   -74,
     -74,   -74,    -3,   129,    75,    55,    57,    65,    66,    34,
     -14,    31,    38,   -17,   -74,   -11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     8,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    54
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      13,    47,    53,    55,    59,    47,    95,    47,    18,     1,
      56,    57,     3,    50,    15,    52,    47,    47,    10,     4,
      71,    72,    79,     6,    18,     5,    16,    80,    81,    19,
      20,    96,     9,    73,    74,    11,    69,    70,    59,    12,
      47,    48,    17,    51,    21,    22,    18,    63,    98,    65,
      47,    19,    20,    24,    75,    76,    25,   108,   109,   110,
     111,    15,   116,   117,   118,    64,    21,    22,    66,    24,
      67,    47,    25,    16,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    16,    12,    60,    23,    17,
      68,    24,   130,    18,    25,    77,    78,    99,    19,    20,
      97,    17,    16,   106,   107,    18,   112,   113,   131,   132,
      19,    20,    14,    21,    22,   114,   115,    61,    17,    62,
     102,   133,    18,   103,    18,    21,    22,    19,    20,    19,
      20,    18,   104,    12,   105,    23,    19,    20,    24,   101,
       0,    25,    21,    22,     0,    12,    58,    23,     0,     0,
      24,    21,    22,    25,     0,     0,     0,     0,     0,     0,
       0,     0,    12,   100,    23,     0,     0,    24,     0,    24,
      25,     0,    25,    49,     0,    79,    24,     0,     0,    25,
      80,    81,     0,     0,     0,     0,     0,     0,    82,     0,
       0,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,   119,     0,     0,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129
};

static const yytype_int16 yycheck[] =
{
      10,    12,    19,    20,    27,    16,    54,    18,    37,     5,
      21,    22,    85,    16,     5,    18,    27,    28,    38,     0,
      48,    49,    41,     5,    37,    37,    17,    46,    47,    42,
      43,    79,    85,    61,    62,    55,    63,    64,    61,    77,
      51,    85,    33,    37,    57,    58,    37,    79,    51,    65,
      61,    42,    43,    82,    59,    60,    85,    71,    72,    73,
      74,     5,    79,    80,    81,    66,    57,    58,    51,    82,
      50,    82,    85,    17,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    17,    77,    78,    79,    33,
      40,    82,    95,    37,    85,    42,    43,    38,    42,    43,
      79,    33,    17,    69,    70,    37,    75,    76,    38,    79,
      42,    43,    11,    57,    58,    77,    78,    28,    33,    28,
      65,   131,    37,    66,    37,    57,    58,    42,    43,    42,
      43,    37,    67,    77,    68,    79,    42,    43,    82,    64,
      -1,    85,    57,    58,    -1,    77,    78,    79,    -1,    -1,
      82,    57,    58,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    82,    -1,    82,
      85,    -1,    85,    79,    -1,    41,    82,    -1,    -1,    85,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    82,    -1,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    88,    85,     0,    37,     5,    89,    90,    85,
      38,    55,    77,    91,    90,     5,    17,    33,    37,    42,
      43,    57,    58,    79,    82,    85,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    85,    79,
      99,    37,    99,   110,   112,   110,   112,   112,    78,    95,
      78,    92,    94,    79,    66,    65,    51,    50,    40,    63,
      64,    48,    49,    61,    62,    59,    60,    42,    43,    41,
      46,    47,    54,    57,    58,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    54,    79,    79,    99,    38,
      78,   101,   102,   103,   104,   105,   106,   106,   107,   107,
     107,   107,   108,   108,   109,   109,   110,   110,   110,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
      99,    38,    79,    91
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    89,    89,    90,    91,    91,    91,    92,
      92,    93,    93,    94,    94,    95,    95,    95,    95,    96,
      97,    97,    98,    98,    99,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   101,   101,   102,   102,   103,   103,   104,   104,   105,
     105,   106,   106,   106,   107,   107,   107,   107,   107,   108,
     108,   108,   109,   109,   109,   110,   110,   110,   110,   111,
     111,   111,   112,   112,   112
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     1,     3,     2,     4,     3,     3,     1,
       2,     1,     2,     3,     5,     1,     1,     1,     1,     5,
       3,     2,     2,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       2,     1,     1,     1,     3
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
#line 45 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.FuncDefPtr) = new FuncDef("int", (yyvsp[-4].string), (yyvsp[-2].ParamListPtr), (yyvsp[0].StatPtr));
  topNode = (yyval.FuncDefPtr);
}
#line 1449 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 51 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ParamListPtr) = new PaList();
  (yyval.ParamListPtr)->addToList((yyvsp[0].ParamPtr));
}
#line 1458 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 54 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ParamListPtr)->addToList((yyvsp[0].ParamPtr));
}
#line 1466 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 58 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ParamPtr) =  new Parameter("int",(yyvsp[0].string));
}
#line 1474 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 63 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.StatPtr) = new CompoundStatement((yyvsp[-1].StatListPtr),(yyvsp[-2].DecListPtr));
}
#line 1482 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 65 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.StatPtr) = new CompoundStatement((yyvsp[-1].StatListPtr),NULL);
}
#line 1490 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 67 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.StatPtr) = new CompoundStatement(NULL,(yyvsp[-1].DecListPtr));
}
#line 1498 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 72 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.StatListPtr) = new StatList();
  (yyval.StatListPtr)->addToList((yyvsp[0].StatPtr));
}
#line 1507 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 76 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.StatListPtr)->addToList((yyvsp[0].StatPtr));
}
#line 1515 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 81 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.DecListPtr) = new DecList();
  (yyval.DecListPtr)->addToList((yyvsp[0].DecPtr));
}
#line 1524 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 85 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.DecListPtr)->addToList((yyvsp[0].DecPtr));
}
#line 1532 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 90 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.DecPtr) =  new Declarator("int",(yyvsp[-1].string), NULL);
}
#line 1540 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 93 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.DecPtr) =  new Declarator("int", (yyvsp[-3].string), (yyvsp[-1].ExpPtr));
}
#line 1548 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 99 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.StatPtr) = new WhileStat((yyvsp[-2].ExpPtr),(yyvsp[0].StatPtr));
}
#line 1556 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 104 "src/c_parser.y" /* yacc.c:1646  */
    { 
  (yyval.StatPtr) =  new JumpStatement("return",(yyvsp[-1].ExpPtr));
}
#line 1564 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 107 "src/c_parser.y" /* yacc.c:1646  */
    { 
  (yyval.StatPtr) =  new JumpStatement("return", NULL);
}
#line 1572 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 112 "src/c_parser.y" /* yacc.c:1646  */
    { 
  (yyval.StatPtr) =  new ExpStatement((yyvsp[-1].ExpPtr));
}
#line 1580 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 115 "src/c_parser.y" /* yacc.c:1646  */
    { 
  (yyval.StatPtr) =  new ExpStatement(NULL);
}
#line 1588 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 122 "src/c_parser.y" /* yacc.c:1646  */
    { 
  (yyval.ExpPtr) =  new AssignmentExp((yyvsp[-2].ExpPtr), (yyvsp[0].ExpPtr));
}
#line 1596 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 125 "src/c_parser.y" /* yacc.c:1646  */
    { 
  Expression* right;
  right = new BinaryExpression((yyvsp[-2].ExpPtr),"+", (yyvsp[0].ExpPtr));
  (yyval.ExpPtr) = new AssignmentExp((yyvsp[-2].ExpPtr), right);
}
#line 1606 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 130 "src/c_parser.y" /* yacc.c:1646  */
    { 
  Expression* right;
  right = new BinaryExpression((yyvsp[-2].ExpPtr),"*", (yyvsp[0].ExpPtr));
  (yyval.ExpPtr) = new AssignmentExp((yyvsp[-2].ExpPtr), right);
}
#line 1616 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 135 "src/c_parser.y" /* yacc.c:1646  */
    { 
  Expression* right;
  right = new BinaryExpression((yyvsp[-2].ExpPtr),"/", (yyvsp[0].ExpPtr));
  (yyval.ExpPtr) = new AssignmentExp((yyvsp[-2].ExpPtr), right);
}
#line 1626 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 140 "src/c_parser.y" /* yacc.c:1646  */
    { 
  Expression* right;
  right = new BinaryExpression((yyvsp[-2].ExpPtr),"%", (yyvsp[0].ExpPtr));
  (yyval.ExpPtr) = new AssignmentExp((yyvsp[-2].ExpPtr), right);
}
#line 1636 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 145 "src/c_parser.y" /* yacc.c:1646  */
    { 
  Expression* right;
  right = new BinaryExpression((yyvsp[-2].ExpPtr),"-", (yyvsp[0].ExpPtr));
  (yyval.ExpPtr) = new AssignmentExp((yyvsp[-2].ExpPtr), right);
}
#line 1646 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 150 "src/c_parser.y" /* yacc.c:1646  */
    { 
  Expression* right;
  right = new BinaryExpression((yyvsp[-2].ExpPtr),"<<", (yyvsp[0].ExpPtr));
  (yyval.ExpPtr) = new AssignmentExp((yyvsp[-2].ExpPtr), right);
}
#line 1656 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 155 "src/c_parser.y" /* yacc.c:1646  */
    { 
  Expression* right;
  right = new BinaryExpression((yyvsp[-2].ExpPtr),">>", (yyvsp[0].ExpPtr));
  (yyval.ExpPtr) = new AssignmentExp((yyvsp[-2].ExpPtr), right);
}
#line 1666 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 160 "src/c_parser.y" /* yacc.c:1646  */
    { 
  Expression* right;
  right = new BinaryExpression((yyvsp[-2].ExpPtr),"&", (yyvsp[0].ExpPtr));
  (yyval.ExpPtr) = new AssignmentExp((yyvsp[-2].ExpPtr), right);
}
#line 1676 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 165 "src/c_parser.y" /* yacc.c:1646  */
    { 
  Expression* right;
  right = new BinaryExpression((yyvsp[-2].ExpPtr),"^", (yyvsp[0].ExpPtr));
  (yyval.ExpPtr) = new AssignmentExp((yyvsp[-2].ExpPtr), right);
}
#line 1686 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 170 "src/c_parser.y" /* yacc.c:1646  */
    { 
  Expression* right;
  right = new BinaryExpression((yyvsp[-2].ExpPtr),"|", (yyvsp[0].ExpPtr));
  (yyval.ExpPtr) = new AssignmentExp((yyvsp[-2].ExpPtr), right);
}
#line 1696 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 175 "src/c_parser.y" /* yacc.c:1646  */
    {
  Expression* right;
  Expression* one;
  one = new ConstantValue(1); 
  right = new BinaryExpression((yyvsp[-1].ExpPtr),"+", one);
  (yyval.ExpPtr) = new AssignmentExp((yyvsp[-1].ExpPtr), right);
}
#line 1708 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 182 "src/c_parser.y" /* yacc.c:1646  */
    {
  Expression* right;
  Expression* one;
  one = new ConstantValue(1); 
  right = new BinaryExpression((yyvsp[0].ExpPtr),"+", one);
  (yyval.ExpPtr) = new AssignmentExp((yyvsp[0].ExpPtr), right);
}
#line 1720 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 189 "src/c_parser.y" /* yacc.c:1646  */
    {
  Expression* right;
  Expression* one;
  one = new ConstantValue(1); 
  right = new BinaryExpression((yyvsp[0].ExpPtr),"-", one);
  (yyval.ExpPtr) = new AssignmentExp((yyvsp[0].ExpPtr), right);
}
#line 1732 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 196 "src/c_parser.y" /* yacc.c:1646  */
    {
  Expression* right;
  Expression* one;
  one = new ConstantValue(1); 
  right = new BinaryExpression((yyvsp[-1].ExpPtr),"-", one);
  (yyval.ExpPtr) = new AssignmentExp((yyvsp[-1].ExpPtr), right);
}
#line 1744 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 206 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) = new BinaryExpression((yyvsp[-2].ExpPtr),"||", (yyvsp[0].ExpPtr));
}
#line 1752 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 212 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) = new BinaryExpression((yyvsp[-2].ExpPtr),"&&", (yyvsp[0].ExpPtr));
}
#line 1760 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 218 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) = new BinaryExpression((yyvsp[-2].ExpPtr),"|", (yyvsp[0].ExpPtr));
}
#line 1768 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 224 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) = new BinaryExpression((yyvsp[-2].ExpPtr),"^", (yyvsp[0].ExpPtr));
}
#line 1776 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 230 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) = new BinaryExpression((yyvsp[-2].ExpPtr),"&", (yyvsp[0].ExpPtr));
}
#line 1784 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 236 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) = new BinaryExpression((yyvsp[-2].ExpPtr),"==", (yyvsp[0].ExpPtr));
}
#line 1792 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 239 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) = new BinaryExpression((yyvsp[-2].ExpPtr),"!=", (yyvsp[0].ExpPtr));
}
#line 1800 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 245 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) = new BinaryExpression((yyvsp[-2].ExpPtr),"<", (yyvsp[0].ExpPtr));
}
#line 1808 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 248 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) = new BinaryExpression((yyvsp[-2].ExpPtr),">", (yyvsp[0].ExpPtr));
}
#line 1816 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 251 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) = new BinaryExpression((yyvsp[-2].ExpPtr),">=", (yyvsp[0].ExpPtr));
}
#line 1824 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 254 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) = new BinaryExpression((yyvsp[-2].ExpPtr),"<=", (yyvsp[0].ExpPtr));
}
#line 1832 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 260 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) = new BinaryExpression((yyvsp[-2].ExpPtr),"<<", (yyvsp[0].ExpPtr));
}
#line 1840 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 263 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) = new BinaryExpression((yyvsp[-2].ExpPtr),">>", (yyvsp[0].ExpPtr));
}
#line 1848 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 269 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) = new BinaryExpression((yyvsp[-2].ExpPtr),"+", (yyvsp[0].ExpPtr));
}
#line 1856 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 272 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) = new BinaryExpression((yyvsp[-2].ExpPtr),"-", (yyvsp[0].ExpPtr));
}
#line 1864 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 279 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) = new BinaryExpression((yyvsp[-2].ExpPtr),"*", (yyvsp[0].ExpPtr));
}
#line 1872 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 282 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) = new BinaryExpression((yyvsp[-2].ExpPtr),"/", (yyvsp[0].ExpPtr));
}
#line 1880 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 285 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) = new BinaryExpression((yyvsp[-2].ExpPtr),"%", (yyvsp[0].ExpPtr));
}
#line 1888 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 291 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) = new UnaryExpression("-", (yyvsp[0].ExpPtr));
}
#line 1896 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 293 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) = new UnaryExpression("+", (yyvsp[0].ExpPtr));
}
#line 1904 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 298 "src/c_parser.y" /* yacc.c:1646  */
    { 
  (yyval.ExpPtr) =  new Identifier(string((yyvsp[0].string)));
}
#line 1912 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 301 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) =  new ConstantValue((yyvsp[0].num));  
}
#line 1920 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 303 "src/c_parser.y" /* yacc.c:1646  */
    {
  (yyval.ExpPtr) =  (yyvsp[-1].ExpPtr);
}
#line 1928 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 1932 "bin/c_parser.tab.cpp" /* yacc.c:1646  */
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
#line 307 "src/c_parser.y" /* yacc.c:1906  */


int yyerror(const char* s){ 
    std::cout << s << std::endl;
    return -1;
}

int main(void) {
  int success = yyparse();
  if (success == 0) {
    cout << topNode->codeprint(cont) << endl;
  }
}
