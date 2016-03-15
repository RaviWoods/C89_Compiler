/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 15 "src/c_parser.y" /* yacc.c:1909  */

  char* string;
  int num;
  double floatnum;
  class Expression* ExpPtr;
  class Statement* StatPtr;
  class StatList* StatListPtr;
  class CompoundStatement* CompoundStatPtr;
  class Declarator* DecPtr;
  class Parameter* ParamPtr;
  class DecList* DecListPtr;
  class FuncDef* FuncDefPtr;

#line 155 "bin/c_parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BIN_C_PARSER_TAB_HPP_INCLUDED  */
