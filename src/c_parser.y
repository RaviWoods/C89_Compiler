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

%token TAuto TDouble TInt TStruct TBreak TElse TLong TSwitch TCase TEnum TRegister TTypedef TChar TExtern TReturn TUnion TConst TFloat TShort TUnsigned TContinue TFor TSigned TVoid TDefault TGoto TVolatile TDo TIf TStatic TWhile TSizeof TOpenSqBracket TCloseSqBracket TOpenBracket TCloseBracket TDot TBitwiseAnd TStar TPlus TMinus TTilde TBang TSlash TPercent TGreater TLess TCarat TPipe TQuestion TColon TAssign TComma TArrow TIncrement TDecrement TLeftShift TRightShift TLessEqual TGreaterEqual TEquals TNotEqual TLogicalAnd TLogicalOr TStarEquals TSlashEquals TPercentEquals TPlusEquals TMinusEquals TLeftShiftEquals TRightShiftEquals TAndEquals TCaratEquals TPipeEquals TOpenCurlyBrace TCloseCurlyBrace TSemicolon TEllipsis TCharConstVal TIntVal TFloatVal TStringLit TIdentifier TNewline

%type <string> TIdentifier
%type <num> TIntVal
%type <string> TIncrement
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

/************* EXPRESSIONS - START *************/


Expression : AssignmentExpression {cout << "exp" << endl;}| Expression TComma AssignmentExpression;

AssignmentExpression : ConditionalExpression | UnaryExpression AssignmentOperator AssignmentExpression;

AssignmentOperator : TAssign | TStarEquals | TSlashEquals | TPercentEquals | TPlusEquals | TMinusEquals | TLeftShiftEquals | TRightShiftEquals | TAndEquals | TCaratEquals | TPipeEquals;

ConditionalExpression : LogicalOrExp | LogicalOrExp TQuestion Expression TColon ConditionalExpression;

LogicalOrExp : LogicalAndExp | LogicalOrExp TLogicalOr LogicalAndExp;

LogicalAndExp : InclusiveOrExp | LogicalAndExp TLogicalAnd InclusiveOrExp;

InclusiveOrExp : ExclusiveOrExp | InclusiveOrExp TPipe ExclusiveOrExp;

ExclusiveOrExp : AndExp | ExclusiveOrExp TCarat AndExp;

AndExp : EqualityExp | AndExp TBitwiseAnd EqualityExp;

EqualityExp : RelationalExp | EqualityExp TEquals RelationalExp | EqualityExp TNotEqual RelationalExp;

RelationalExp : ShiftExp | RelationalExp TGreater ShiftExp | RelationalExp TGreater TLess | RelationalExp TLessEqual ShiftExp | RelationalExp TGreaterEqual ShiftExp;

ShiftExp : AdditiveExp | ShiftExp TLeftShift AdditiveExp | ShiftExp TRightShift AdditiveExp;

AdditiveExp : MultExp | AdditiveExp TPlus MultExp | AdditiveExp TMinus MultExp;

MultExp : CastExp | MultExp TStar CastExp | MultExp TSlash CastExp | MultExp TPercent CastExp;

CastExp : UnaryExpression | TOpenBracket TypeName TCloseBracket CastExp;

UnaryExpression : PostFixExp | TIncrement UnaryExpression | TDecrement UnaryExpression | UnaryOp CastExp | TSizeof UnaryExpression | TSizeof TOpenBracket TypeName TCloseBracket;

UnaryOp : TStar | TPlus | TMinus | TTilde | TBang;

PostFixExp : PrimaryExpression | PostFixExp TOpenSqBracket Expression TCloseSqBracket | PostFixExp TOpenBracket TCloseBracket | PostFixExp TOpenBracket ArgumentExpList TCloseBracket | PostFixExp TDot TIdentifier | PostFixExp TArrow TIdentifier | PostFixExp TIncrement | PostFixExp TDecrement;

PrimaryExpression : TIdentifier | Constant | TStringLit | TOpenBracket Expression TCloseBracket;

ArgumentExpList : AssignmentExpression | ArgumentExpList TComma AssignmentExpression;

Constant : TFloatVal | TIntVal | TCharConstVal;

TypeName : TInt;

/************* EXPRESSIONS - END *************/

%%

int yyerror(const char* s){ 
    std::cout << s << std::endl;
    return -1;
}

int main(void) {
  yyparse();
}
