%{
#include "../bin/c_parser.tab.hpp"
#include <stdio.h>
#include <stdint.h>
#include <string>
#include <iostream>
%}

%option noyywrap
D [0-9]
OCT [0-7]
HEX [0-9a-fA-F]
INVALID [^ \n\t\r]+

/*************** Identifier***************/ 
ND [A-Za-z_]
IDENTIFIER {ND}({ND}|{D})*


/*************** Floating Point Constant ***************/ 
P [eE][\+\-]?{D}+
A (({D}[\.])|([\.]{D})){D}*
B ({D}[\.]|[\.{D}]|{D}){D}*{P}
SFP [f|F|l|L]
FPCONSTANT {D}*({B}|{A}){SFP}?


/*************** Integer Constant ***************/ 
SINT ([u|U]?[l|L]?)|(([i][6][4])?)
HEXINT 0[x|X]{HEX}+{SINT}
OCTINT 0{OCT}+{SINT}
DECINT (([1-9]{1}{D})|0)*{SINT}

/*************** Keyword Constant ***************/ 
KEYWORD auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|float|short|unsigned|continue|for|signed|void|default|goto|volatile|do|if|static|while

/*************** Operator Constant ***************/ 
OPERATOR \[|\]|\(|\)|\.|\&|\*|\+|\-|\~|\!|\/|\%|\<|\>|\^|\||\?|\:|\=|\,|\-\>|\+\+|\-\-|<<|>>|\<\=|\>\=|\=\=|\!\=|\&\&|\|\||\*\=|\/\=|\%\=|\+\=|\-\=|\<\<\=|\>\>\=|\&\=|\^\=|\|\=|

/*************** Character Constant ***************/ 
NEWLINE \n
ES \\(x{HEX}{2})|[\'\"\?\\abfnrtv]|({OCT}{1,3})
CHARCONST \'({ES}[^'\\\n])+\'

/*************** String Literal ***************/ 
STRINGLIT \"({ES}[^"\\\n])*\"

%%

[ \t\r]

auto		{ return TAuto; }
double		{ return TDouble; }
int			{ return TInt; }
struct		{ return TStruct; }
break		{ return TBreak; }
else		{ return TElse; }
long		{ return TLong; }
switch		{ return TSwitch; }
case		{ return TCase; }
enum		{ return TEnum; }
register	{ return TRegister; }
typedef		{ return TTypedef; }
char		{ return TChar; }
extern		{ return TExtern; }
return		{ return TReturn; }
union		{ return TUnion; }
const		{ return TConst; }
float		{ return TFloat; }
short		{ return TShort; }
unsigned	{ return TUnsigned; }
continue	{ return TContinue; }
for			{ return TFor; }
signed		{ return TSigned; }
void		{ return TVoid; }
default		{ return TDefault; }
goto		{ return TGoto; }
volatile	{ return TVolatile; }
do			{ return TDo; }
if			{ return TIf; }
static		{ return TStatic; }
while		{ return TWhile; }



sizeof	{ return TSizeof; }
\[		{ return TOpenSqBracket; }
\]		{ return TCloseSqBracket; }
\(		{ return TOpenBracket; }
\)		{ return TCloseBracket; }
\.		{ return TDot; }
\&		{ return TBitwiseAnd; }
\*		{ return TStar; }
\+		{ return TPlus; }
\-		{ return TMinus; }
\~		{ return TTilde; }
\!		{ return TBang; }
\/		{ return TSlash; }
\% 		{ return TPercent; }
\<		{ return TGreater; }
\>		{ return TLess; }
\^		{ return TCarat; }
\|		{ return TPipe; }
\?		{ return TQuestion; }
\:		{ return TColon; }
\=		{ return TAssign; }
\,		{ return TComma; }
\-\>	{ return TArrow; }
\+\+	{ return TIncrement; }
\-\-	{ return TDecrement; }
\<\<	{ return TLeftShift; }
\>\>	{ return TRightShift; }
\<\=	{ return TLessEqual; }
\>\=	{ return TGreaterEqual; }
\=\=	{ return TEquals; }
\!\=	{ return TNotEqual; }
\&\&	{ return TLogicalAnd; }
\|\|	{ return TLogicalOr; }
\*\=	{ return TStarEquals; }
\/\=	{ return TSlashEquals; }
\%\=	{ return TPercentEquals; }
\+\=	{ return TPlusEquals; }
\-\=	{ return TMinusEquals; }
\<\<\=	{ return TLeftShiftEquals; }
\>\>\=	{ return TRightShiftEquals; }
\&\=	{ return TAndEquals; }
\^\=	{ return TCaratEquals; }
\|\=	{ return TPipeEquals; }
\{		{ return TOpenCurlyBrace; }
\}		{ return TCloseCurlyBrace; }
\;		{ return TSemicolon; }
\.\.\.	{ return TEllipsis; }


{CHARCONST} 	{
					yylval.string = yytext;
					return TCharConstVal;
				}

{HEXINT} 		{
					yylval.num = strtol(yytext, NULL, 16);
					return TIntVal;
				}

{OCTINT} 		{
					yylval.num = strtol(yytext, NULL, 8);
					return TIntVal;
				}

{DECINT} 		{
					yylval.num = atoi(yytext);
					return TIntVal;
				}

{FPCONSTANT} 	{
					yylval.floatnum = atof(yytext);
					return TFloatVal;
				}

{STRINGLIT} 	{
					yylval.string = yytext;
					return TStringLit;
				}

{IDENTIFIER} 	{
					yylval.string = yytext;
					return TIdentifier;
				}


[^({IDENTIFIER}|{STRINGLIT}|{FPCONSTANT}|{DECINT}|{OCTINT}|{HEXINT}|{PREPROCESS}|{OPERATOR}|{KEYWORD}]

%%





