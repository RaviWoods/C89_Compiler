%{
#include <iostream>
#include <cstdlib>
#include <string>
#include "../src/ast.hpp"

int yylex();
int yyerror(const char* s);
using namespace std;
Context cont = Context();
Node* topNode;
%}

%start FunctionDef

%union{
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
}

%token TAuto TDouble TInt TStruct TBreak TElse TLong TSwitch TCase TEnum TRegister TTypedef TChar TExtern TReturn TUnion TConst TFloat TShort TUnsigned TContinue TFor TSigned TVoid TDefault TGoto TVolatile TDo TIf TStatic TWhile TSizeof TOpenSqBracket TCloseSqBracket TOpenBracket TCloseBracket TDot TBitwiseAnd TStar TPlus TMinus TTilde TBang TSlash TPercent TGreater TLess TCarat TPipe TQuestion TColon TAssign TComma TArrow TIncrement TDecrement TLeftShift TRightShift TLessEqual TGreaterEqual TEquals TNotEqual TLogicalAnd TLogicalOr TStarEquals TSlashEquals TPercentEquals TPlusEquals TMinusEquals TLeftShiftEquals TRightShiftEquals TAndEquals TCaratEquals TPipeEquals TOpenCurlyBrace TCloseCurlyBrace TSemicolon TEllipsis TCharConstVal TIntVal TFloatVal TStringLit TIdentifier TNewline 

%type <string> TIdentifier
%type <num> TIntVal
%type <ExpPtr> PrimaryExp Exp AssignmentExp AdditiveExp MultExp LogicalOrExp LogicalAndExp InclusiveOrExp ExclusiveOrExp AndExp EqualityExp RelationalExp ShiftExp
%type <StatPtr> ExpStat JumpStat Statement
%type <DecPtr> Declarator
%type <StatListPtr> Statementlist
%type <DecListPtr> Declaratorlist
%type <FuncDefPtr> FunctionDef
%type <CompoundStatPtr> CompoundStat
%type <ParamPtr> ParamDec
%%


FunctionDef: TInt TIdentifier TOpenBracket ParamDec TComma ParamDec TCloseBracket CompoundStat {
  $$ = new FuncDef("int", $2, $4, $6, $8);
  topNode = $$;
}

ParamDec: TInt TIdentifier {
  $$ =  new Parameter("int",$2);
}

CompoundStat: 
TOpenCurlyBrace Declaratorlist Statementlist TCloseCurlyBrace {
  $$ = new CompoundStatement($3,$2);
  
} | TOpenCurlyBrace Statementlist TCloseCurlyBrace {
  $$ = new CompoundStatement($2,NULL);
} | TOpenCurlyBrace Declaratorlist TCloseCurlyBrace {
  $$ = new CompoundStatement(NULL,$2);
}

Statementlist : 
Statement {
  $$ = new StatList();
  $$->addToList($1);
}
| Statementlist Statement {
  $$->addToList($2);
};

Declaratorlist : 
Declarator {
  $$ = new DecList();
  $$->addToList($1);
}
| Declaratorlist Declarator {
  $$->addToList($2);
};

Declarator : 
TInt TIdentifier TSemicolon {
  $$ =  new Declarator("int",$2, NULL);
}
| TInt TIdentifier TAssign Exp TSemicolon {
  $$ =  new Declarator("int", $2, $4);
}

Statement : JumpStat | ExpStat ;

JumpStat : 
TReturn Exp TSemicolon { 
  $$ =  new JumpStatement("return",$2);
} 
| TReturn TSemicolon { 
  $$ =  new JumpStatement("return", NULL);
} 

ExpStat: 
Exp TSemicolon { 
  $$ =  new ExpStatement($1);
}
| TSemicolon { 
  $$ =  new ExpStatement(NULL);
};

Exp: AssignmentExp;

AssignmentExp : 
TIdentifier TAssign AssignmentExp { 
  $$ =  new AssignmentExp($1,"=", $3);
} 
| LogicalOrExp;

LogicalOrExp : 
LogicalAndExp 
| 
LogicalOrExp TLogicalOr LogicalAndExp  {
  $$ = new BinaryExpression($1,"^", $3);
} ;

LogicalAndExp : 
InclusiveOrExp 
| 
LogicalAndExp TLogicalAnd InclusiveOrExp {
  $$ = new BinaryExpression($1,"^", $3);
} ;

InclusiveOrExp : 
ExclusiveOrExp 
| 
InclusiveOrExp TPipe ExclusiveOrExp  {
  $$ = new BinaryExpression($1,"^", $3);
} ;

ExclusiveOrExp : 
AndExp 
| 
ExclusiveOrExp TCarat AndExp TBitwiseAnd EqualityExp {
  $$ = new BinaryExpression($1,"^", $3);
} ;

AndExp : 
EqualityExp 
| 
AndExp TBitwiseAnd EqualityExp {
  $$ = new BinaryExpression($1,"&", $3);
} ;

EqualityExp : 
RelationalExp 
| 
EqualityExp TEquals RelationalExp  {
  $$ = new BinaryExpression($1,"==", $3);
}  
| 
EqualityExp TNotEqual RelationalExp {
  $$ = new BinaryExpression($1,"!=", $3);
}  ;

RelationalExp : 
ShiftExp 
| 
RelationalExp TGreater ShiftExp  {
  $$ = new BinaryExpression($1,">", $3);
}  
| 
RelationalExp TLess ShiftExp  {
  $$ = new BinaryExpression($1,"<", $3);
} 
| 
RelationalExp TLessEqual ShiftExp  {
  $$ = new BinaryExpression($1,"<=", $3);
} 
| 
RelationalExp TGreaterEqual ShiftExp {
  $$ = new BinaryExpression($1,">=", $3);
} ;

ShiftExp : 
AdditiveExp TLeftShift ShiftExp {
  $$ = new BinaryExpression($1,"<<", $3);
} 
| AdditiveExp TRightShift ShiftExp {
  $$ = new BinaryExpression($1,">>", $3);
} |
AdditiveExp;

AdditiveExp :  
MultExp TPlus AdditiveExp {
  $$ = new BinaryExpression($1,"+", $3);
} 
| MultExp TMinus AdditiveExp {
  $$ = new BinaryExpression($1,"-", $3);
} 
| MultExp;

MultExp :  
PrimaryExp TStar MultExp {
	$$ = new BinaryExpression($1,"*", $3);
} 
| PrimaryExp TSlash MultExp {
  $$ = new BinaryExpression($1,"/", $3);
} 
| PrimaryExp TPercent MultExp {
  $$ = new BinaryExpression($1,"%", $3);
} 
| PrimaryExp;

PrimaryExp :  
TIdentifier  { 
  $$ =  new Identifier(string($1));
} 
| TIntVal {
  $$ =  new ConstantValue($1);  
}

%%

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
