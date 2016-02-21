%{
#include <iostream>
#include <cstdlib>
#include <string>
int yylex();
int yyerror(const char* s);

using namespace std;
%}

%union{
  char* string;
  int num;
  double floatnum;
}

%token TAuto TDouble TInt TStruct TBreak TElse TLong TSwitch TCase TEnum TRegister TTypedef TChar TExtern TReturn TUnion TConst TFloat TShort TUnsigned TContinue TFor TSigned TVoid TDefault TGoto TVolatile TDo TIf TStatic TWhile TSizeof TOpenSqBracket TCloseSqBracket TOpenBracket TCloseBracket TDot TBitwiseAnd TStar TPlus TMinus TTilde TBang TSlash TPercent TGreater TLess TCarat TPipe TQuestion TColon TAssign TComma TArrow TIncrement TDecrement TLeftShift TRightShift TLessEqual TGreaterEqual TEquals TNotEqual TLogicalAnd TLogicalOr TStarEquals TSlashEquals TPercentEquals TPlusEquals TMinusEquals TLeftShiftEquals TRightShiftEquals TAndEquals TCaratEquals TPipeEquals TOpenCurlyBrace TCloseCurlyBrace TSemicolon TEllipsis TCharConstVal TIntVal TFloatVal TStringLit TIdentifier

%type <string> TIdentifier

/*
the tokens for the language 

below: the grammar production rules
non-terminating symbols are lowercase
terminating symbols (tokens) are uppercase

the : is used instead of the BNF -> (or ::=) symbol
(the | is still a |, rules are terminated by a ;)

next to the rules there are "semantic actions" which are triggered
when a grammar rule matches 

$$ is the value taken by the left hand side of the rules
$1...$n are the n values of the n components of the rule rhs
*/

%%

intline    : TInt TIdentifier {cout << "ID = " << $2 << endl;};
%%

int yyerror(const char* s){ 
    std::cout << s << std::endl;
    return -1;
}

int main(void) {
  yyparse();
}
