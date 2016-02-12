%option noyywrap


%{
#include <stdio.h>
#include <stdint.h>
int linenum = 1;
%}



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
DECINT [1-9]{1}{D}*{SINT}


/*************** Character Constant ***************/ 
NEWLINE \n
ES \\(x{HEX}{2})|[\'\"\?\\abfnrtv]|({OCT}{0,3})
CHARCONST \'({ES}|[^\\'\n])*\'

/*************** String Literal ***************/ 
STRINGLIT \"({ES}|[^\\"\n])*\"

%%

[ \t\r]
{NEWLINE} linenum++;

auto		printf("%s Keyword TAuto %i\n",yytext,linenum);
double		printf("%s Keyword TDouble %i\n",yytext,linenum);
int			printf("%s Keyword TInt %i\n",yytext,linenum);
struct		printf("%s Keyword TStruct %i\n",yytext,linenum);
break		printf("%s Keyword TBreak %i\n",yytext,linenum);
else		printf("%s Keyword TElse %i\n",yytext,linenum);
long		printf("%s Keyword TLong %i\n",yytext,linenum);
switch		printf("%s Keyword TSwitch %i\n",yytext,linenum);
case		printf("%s Keyword TCase %i\n",yytext,linenum);
enum		printf("%s Keyword TEnum %i\n",yytext,linenum);
register	printf("%s Keyword TRegister %i\n",yytext,linenum);
typedef		printf("%s Keyword TTypedef %i\n",yytext,linenum);
char		printf("%s Keyword TChar %i\n",yytext,linenum);
extern		printf("%s Keyword TExtern %i\n",yytext,linenum);
return		printf("%s Keyword TReturn %i\n",yytext,linenum);
union		printf("%s Keyword TUnion %i\n",yytext,linenum);
const		printf("%s Keyword TConst %i\n",yytext,linenum);
float		printf("%s Keyword TFloat %i\n",yytext,linenum);
short		printf("%s Keyword TShort %i\n",yytext,linenum);
unsigned	printf("%s Keyword TUnsigned %i\n",yytext,linenum);
continue	printf("%s Keyword TContinue %i\n",yytext,linenum);
for			printf("%s Keyword TFor %i\n",yytext,linenum);
signed		printf("%s Keyword TSigned %i\n",yytext,linenum);
void		printf("%s Keyword TVoid %i\n",yytext,linenum);
default		printf("%s Keyword TDefault %i\n",yytext,linenum);
goto		printf("%s Keyword TGoto %i\n",yytext,linenum);

volatile	printf("%s Keyword TVolatile %i\n",yytext,linenum);
do			printf("%s Keyword TDo %i\n",yytext,linenum);
if			printf("%s Keyword TIf %i\n",yytext,linenum);
static		printf("%s Keyword TStatic %i\n",yytext,linenum);
while		printf("%s Keyword TWhile %i\n",yytext,linenum);



sizeof	printf("%s Operator TSizeof %i\n",yytext,linenum);
\[		printf("%s Operator TOpenSqBracket %i\n",yytext ,linenum);
\]		printf("%s Operator TCloseSqBracket %i\n",yytext ,linenum);
\(		printf("%s Operator TOpenBracket %i\n",yytext ,linenum);
\)		printf("%s Operator TCloseBracket %i\n",yytext ,linenum);
\.		printf("%s Operator TDot %i\n",yytext ,linenum);
\&		printf("%s Operator TBitwiseAnd %i\n",yytext ,linenum);
\*		printf("%s Operator TStar %i\n",yytext ,linenum);
\+		printf("%s Operator TPlus %i\n",yytext ,linenum);
\-		printf("%s Operator TMinus %i\n",yytext ,linenum);
\~		printf("%s Operator TTilde %i\n",yytext ,linenum);
\!		printf("%s Operator TBang %i\n",yytext ,linenum);
\/		printf("%s Operator TSlash %i\n",yytext ,linenum);
\% 		printf("%s Operator TPercent %i\n",yytext ,linenum);
\<		printf("%s Operator TGreater %i\n",yytext ,linenum);
\>		printf("%s Operator TLess %i\n",yytext ,linenum);
\^		printf("%s Operator TCarat %i\n",yytext ,linenum);
\|		printf("%s Operator TPipe %i\n",yytext ,linenum);
\?		printf("%s Operator TQuestion %i\n",yytext ,linenum);
\:		printf("%s Operator TColon %i\n",yytext ,linenum);
\=		printf("%s Operator TAssign %i\n",yytext ,linenum);
\,		printf("%s Operator TComma %i\n",yytext ,linenum);
\-\>	printf("%s Operator TArrow %i\n",yytext ,linenum);
\+\+	printf("%s Operator TIncrement %i\n",yytext ,linenum);
\-\-	printf("%s Operator TDecrement %i\n",yytext ,linenum);
\<\<	printf("%s Operator TLeftShift %i\n",yytext ,linenum);
\>\>	printf("%s Operator TRightShift %i\n",yytext ,linenum);
\<\=	printf("%s Operator TLessEqual %i\n",yytext ,linenum);
\>\=	printf("%s Operator TGreaterEqual %i\n",yytext ,linenum);
\=\=	printf("%s Operator TEquals %i\n",yytext ,linenum);
\!\=	printf("%s Operator TNotEqual %i\n",yytext ,linenum);
\&\&	printf("%s Operator TLogicalAnd %i\n",yytext ,linenum);
\|\|	printf("%s Operator TLogicalOr %i\n",yytext ,linenum);
\*\=	printf("%s Operator TStarEquals %i\n",yytext ,linenum);
\/\=	printf("%s Operator TSlashEquals %i\n",yytext ,linenum);
\%\=	printf("%s Operator TPercentEquals %i\n",yytext ,linenum);
\+\=	printf("%s Operator TPlusEquals %i\n",yytext ,linenum);
\-\=	printf("%s Operator TMinusEquals %i\n",yytext ,linenum);
\<\<\=	printf("%s Operator TLeftShiftEquals %i\n",yytext ,linenum);
\>\>\=	printf("%s Operator TRightShiftEquals %i\n",yytext ,linenum);
\&\=	printf("%s Operator TAndEquals %i\n",yytext ,linenum);
\^\=	printf("%s Operator TCaratEquals %i\n",yytext ,linenum);
\|\=	printf("%s Operator TPipeEquals %i\n",yytext ,linenum);
\{		printf("%s Operator TOpenCurlyBrace %i\n",yytext ,linenum);
\}		printf("%s Operator TCloseCurlyBrace %i\n",yytext ,linenum);
\;		printf("%s Operator TSemicolon %i\n",yytext ,linenum);
\.\.\.	printf("%s Operator TEllipsis %i\n",yytext ,linenum);


{CHARCONST} 	printf("%s Constant TCharConstant %i\n",yytext,linenum);
{HEXINT} 		printf("%s Constant THexInteger %i\n",yytext,linenum);
{OCTINT} 		printf("%s Constant TOctInteger %i\n",yytext,linenum);
{DECINT} 		printf("%s Constant TDecInteger %i\n",yytext,linenum);
{FPCONSTANT} 	printf("%s Constant TFloatingPoint %i\n",yytext,linenum);

{STRINGLIT} 	printf("%s StringLiteral TStringLiteral %i\n",yytext,linenum);

{IDENTIFIER} 	printf("%s Identifier TIdentifier %i\n",yytext,linenum);

[^({IDENTIFIER}|{STRINGLIT}|{FPCONSTANT}|{DECINT}|{OCTINT}|{HEXINT}|{HEXINT}] printf("%s Invalid TInvalid %i\n",yytext,linenum);

%%



int main()
{

    yylex();
           
    return 0;
}



