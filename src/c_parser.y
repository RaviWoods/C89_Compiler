%{
#include <iostream>
#include <cstdlib>
#include <string>
#include "../src/ast.hpp"
int yylex();
int yyerror(const char* s);
using namespace std;

Node* topNode;
%}

%start AssignmentExp

%union{
  char* string;
  int num;
  double floatnum;
  class Expression* ExpPtr;
}

%token TAuto TDouble TInt TStruct TBreak TElse TLong TSwitch TCase TEnum TRegister TTypedef TChar TExtern TReturn TUnion TConst TFloat TShort TUnsigned TContinue TFor TSigned TVoid TDefault TGoto TVolatile TDo TIf TStatic TWhile TSizeof TOpenSqBracket TCloseSqBracket TOpenBracket TCloseBracket TDot TBitwiseAnd TStar TPlus TMinus TTilde TBang TSlash TPercent TGreater TLess TCarat TPipe TQuestion TColon TAssign TComma TArrow TIncrement TDecrement TLeftShift TRightShift TLessEqual TGreaterEqual TEquals TNotEqual TLogicalAnd TLogicalOr TStarEquals TSlashEquals TPercentEquals TPlusEquals TMinusEquals TLeftShiftEquals TRightShiftEquals TAndEquals TCaratEquals TPipeEquals TOpenCurlyBrace TCloseCurlyBrace TSemicolon TEllipsis TCharConstVal TIntVal TFloatVal TStringLit TIdentifier TNewline

%type <string> TIdentifier
%type <num> TIntVal
%type <ExpPtr> AssignmentExp AdditiveExp MultExp Exp

%%

AssignmentExp : 
Exp TAssign AssignmentExp { 
  $$ =  new AssignmentExp($1,"=", $3);
  topNode = $$;
} |
AdditiveExp;

AdditiveExp :  
MultExp TPlus AdditiveExp {
  $$ = new BinaryExpression($1,"+", $3);
  topNode = $$;
} 
| MultExp TMinus AdditiveExp {
  $$ = new BinaryExpression($1,"-", $3);
  topNode = $$;
} 
| MultExp;

MultExp :  
Exp TStar MultExp {
	$$ = new BinaryExpression($1,"*", $3);
	topNode = $$;
} 
| Exp TSlash MultExp {
  $$ = new BinaryExpression($1,"/", $3);
  topNode = $$;
} 
| Exp TPercent MultExp {
  $$ = new BinaryExpression($1,"%", $3);
  topNode = $$;
} 
| Exp;

Exp :  
TIdentifier  { 
  $$ =  new Identifier(string($1));
}| TIntVal {
  $$ =  new ConstantValue($1);  
};

%%

int yyerror(const char* s){ 
    std::cout << s << std::endl;
    return -1;
}

int main(void) {
  int success = yyparse();
  if (success == 0) {
  	cout << topNode->cprint() << endl;
  }
}
