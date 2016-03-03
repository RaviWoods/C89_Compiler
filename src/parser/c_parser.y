%{
#include <iostream>
#include <cstdlib>
#include <string>
int yylex();
int yyerror(const char* s);

using namespace std;
int spaceNo = 0;
char* nextID;
void printSpaces (int spaceNo) {
	for(int i = 0; i < (4*spaceNo); i++) {
		cout << " ";
	} 
}

%}

%start TranslationUnit

%union{
  char* string;
  int num;
  double floatnum;
}

%token TAuto TDouble TInt TStruct TBreak TElse TLong TSwitch TCase TEnum TRegister TTypedef TChar TExtern TReturn TUnion TConst TFloat TShort TUnsigned TContinue TFor TSigned TVoid TDefault TGoto TVolatile TDo TIf TStatic TWhile TSizeof TOpenSqBracket TCloseSqBracket TOpenBracket TCloseBracket TDot TBitwiseAnd TStar TPlus TMinus TTilde TBang TSlash TPercent TGreater TLess TCarat TPipe TQuestion TColon TAssign TComma TArrow TIncrement TDecrement TLeftShift TRightShift TLessEqual TGreaterEqual TEquals TNotEqual TLogicalAnd TLogicalOr TStarEquals TSlashEquals TPercentEquals TPlusEquals TMinusEquals TLeftShiftEquals TRightShiftEquals TAndEquals TCaratEquals TPipeEquals TOpenCurlyBrace TCloseCurlyBrace TSemicolon TEllipsis TCharConstVal TIntVal TFloatVal TStringLit TIdentifier TNewline

%type <string> TIdentifier
%type <num> TIntVal

%%

/************* FUNCTIONS - START *************/

TranslationUnit : ExternalDec | TranslationUnit ExternalDec;

ExternalDec : Declaration | FuncDef;

FuncDef : TypeName Declarator | Declarator | DecList CompoundStat | CompoundStat;

/************* FUNCTIONS - END *************/

/************* STATEMENTS - START *************/

Stat : LabelledStat | CompoundStat | ExpStat | SelectStat | IterStat | JumpStat;

LabelledStat : TIdentifier TColon Stat | TCase ConditionalExpression TComma Stat | TDefault TComma Stat;

CompoundStat : StartScope DecList StatList EndScope | StartScope DecList EndScope | StartScope StatList EndScope | StartScope EndScope;
StartScope : TOpenCurlyBrace {
								printSpaces(spaceNo);
								cout << "SCOPE" << endl; 	
								spaceNo++;
							 }	 
EndScope : TCloseCurlyBrace {
								spaceNo--;
							} 
SelectStat : TIf TOpenBracket Expression TCloseBracket Stat | TIf TOpenBracket Expression TCloseBracket Stat TElse Stat | TSwitch TOpenBracket Expression TCloseBracket;

ExpStat : Expression TSemicolon | TSemicolon;

IterStat : TWhile TOpenBracket Expression TCloseBracket Stat | TDo Stat TWhile TOpenBracket Expression TCloseBracket | ForStat;

ForStat : 
TFor TOpenBracket Expression TSemicolon Expression TSemicolon Expression TCloseBracket Stat | 
TFor TOpenBracket Expression TSemicolon Expression TSemicolon TCloseBracket Stat | 
TFor TOpenBracket Expression TSemicolon TSemicolon Expression TCloseBracket Stat | 
TFor TOpenBracket TSemicolon Expression TSemicolon Expression TCloseBracket Stat | 
TFor TOpenBracket Expression TSemicolon TSemicolon TCloseBracket Stat | 
TFor TOpenBracket TSemicolon Expression TSemicolon TCloseBracket Stat | 
TFor TOpenBracket TSemicolon TSemicolon Expression TCloseBracket Stat;

DecList : Declaration | DecList Declaration;

StatList : Stat | StatList Stat;

JumpStat : TGoto TIdentifier TSemicolon | TContinue TSemicolon | TBreak TSemicolon | TReturn TSemicolon | TReturn Expression TSemicolon

/************* STATEMENTS - START *************/


/************* DECLARATIONS - START *************/

Declaration : TypeName InitDecList TSemicolon { 
													printSpaces(spaceNo);
													cout << "VARIABLE : " << nextID << endl;
											  }
			| TypeName TSemicolon;

InitDecList : InitDec | InitDecList TComma InitDec

InitDec : Declarator | Declarator TAssign AssignmentExpression;

ParamTypeList : ParamList | ParamList TComma TEllipsis;

ParamList : ParamDec | ParamList TComma ParamDec;

ParamDec : TypeName ParamName;

IdList : Declarator | IdList TComma Declarator;

IdDec : TIdentifier {nextID = $1;}

ParamName : TIdentifier { 
							printSpaces(spaceNo);
							cout << "    PARAMETER : " << $1 << endl;
						}

FuncStart : TOpenBracket { 
							printSpaces(spaceNo);
							cout << "FUNCTION : " << nextID << endl;
						}

Declarator : IdDec | TOpenBracket Declarator TCloseBracket | Declarator FuncStart ParamTypeList TCloseBracket | Declarator FuncStart IdList TCloseBracket | Declarator FuncStart TCloseBracket;

/************* DECLARATIONS - END *************/


/************* EXPRESSIONS - START *************/


Expression : AssignmentExpression | Expression TComma AssignmentExpression;

AssignmentExpression : ConditionalExpression | UnaryExpression AssignmentOperator AssignmentExpression;

AssignmentOperator : TAssign | TStarEquals | TSlashEquals | TPercentEquals | TPlusEquals | TMinusEquals | TLeftShiftEquals | TRightShiftEquals | TAndEquals | TCaratEquals | TPipeEquals;

ConditionalExpression : LogicalOrExp | LogicalOrExp TQuestion Expression TColon ConditionalExpression;

LogicalOrExp : LogicalAndExp | LogicalOrExp TLogicalOr LogicalAndExp;

LogicalAndExp : InclusiveOrExp | LogicalAndExp TLogicalAnd InclusiveOrExp;

InclusiveOrExp : ExclusiveOrExp | InclusiveOrExp TPipe ExclusiveOrExp;

ExclusiveOrExp : AndExp | ExclusiveOrExp TCarat AndExp;

AndExp : EqualityExp | AndExp TBitwiseAnd EqualityExp;

EqualityExp : RelationalExp | EqualityExp TEquals RelationalExp | EqualityExp TNotEqual RelationalExp;

RelationalExp : ShiftExp | RelationalExp TGreater ShiftExp | RelationalExp TLess ShiftExp | RelationalExp TLessEqual ShiftExp | RelationalExp TGreaterEqual ShiftExp;

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
