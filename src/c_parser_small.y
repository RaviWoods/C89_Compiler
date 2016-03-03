%{
#include <iostream>
#include <cstdlib>
#include <string>
int yylex();
int yyerror(const char* s);
%}

%start Exp

%union{
  char* string;
  int num;
  double floatnum;
}

%token TAuto TDouble TInt TStruct TBreak TElse TLong TSwitch TCase TEnum TRegister TTypedef TChar TExtern TReturn TUnion TConst TFloat TShort TUnsigned TContinue TFor TSigned TVoid TDefault TGoto TVolatile TDo TIf TStatic TWhile TSizeof TOpenSqBracket TCloseSqBracket TOpenBracket TCloseBracket TDot TBitwiseAnd TStar TPlus TMinus TTilde TBang TSlash TPercent TGreater TLess TCarat TPipe TQuestion TColon TAssign TComma TArrow TIncrement TDecrement TLeftShift TRightShift TLessEqual TGreaterEqual TEquals TNotEqual TLogicalAnd TLogicalOr TStarEquals TSlashEquals TPercentEquals TPlusEquals TMinusEquals TLeftShiftEquals TRightShiftEquals TAndEquals TCaratEquals TPipeEquals TOpenCurlyBrace TCloseCurlyBrace TSemicolon TEllipsis TCharConstVal TIntVal TFloatVal TStringLit TIdentifier TNewline

%type <string> TIdentifier
%type <num> TIntVal

%%

Exp :  AdditiveExp | TIdentifier | Constant;

AdditiveExp : MultExp | AdditiveExp TPlus MultExp | AdditiveExp TMinus MultExp;

MultExp : MultExp TStar Exp | MultExp TSlash Exp | MultExp TPercent Exp;

Constant : TIntVal;

%%

int yyerror(const char* s){ 
    std::cout << s << std::endl;
    return -1;
}

int main(void) {
  yyparse();
}
