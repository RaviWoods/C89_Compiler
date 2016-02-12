%option noyywrap

%{
#include <stdio.h>
#include <stdint.h>
#include <string>
char* sourceFile = "\"\"";
int linenum = 1;
int sourceLineNo = 1;
std::string sourceLine;
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

/*************** Preprocessor Line***************/ 
PREPROCESS #[ ]{D}+[ ]\"(.)*\"([ ][1-4]){0,4}$

%%

[ \t\r]
{NEWLINE} linenum++; sourceLineNo++;

auto		printf("%s Keyword TAuto %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
double		printf("%s Keyword TDouble %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
int			printf("%s Keyword TInt %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
struct		printf("%s Keyword TStruct %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
break		printf("%s Keyword TBreak %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
else		printf("%s Keyword TElse %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
long		printf("%s Keyword TLong %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
switch		printf("%s Keyword TSwitch %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
case		printf("%s Keyword TCase %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
enum		printf("%s Keyword TEnum %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
register	printf("%s Keyword TRegister %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
typedef		printf("%s Keyword TTypedef %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
char		printf("%s Keyword TChar %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
extern		printf("%s Keyword TExtern %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
return		printf("%s Keyword TReturn %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
union		printf("%s Keyword TUnion %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
const		printf("%s Keyword TConst %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
float		printf("%s Keyword TFloat %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
short		printf("%s Keyword TShort %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
unsigned	printf("%s Keyword TUnsigned %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
continue	printf("%s Keyword TContinue %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
for			printf("%s Keyword TFor %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
signed		printf("%s Keyword TSigned %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
void		printf("%s Keyword TVoid %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
default		printf("%s Keyword TDefault %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
goto		printf("%s Keyword TGoto %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
volatile	printf("%s Keyword TVolatile %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
do			printf("%s Keyword TDo %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
if			printf("%s Keyword TIf %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
static		printf("%s Keyword TStatic %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
while		printf("%s Keyword TWhile %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);



sizeof	printf("%s Operator TSizeof %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\[		printf("%s Operator TOpenSqBracket %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\]		printf("%s Operator TCloseSqBracket %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\(		printf("%s Operator TOpenBracket %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\)		printf("%s Operator TCloseBracket %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\.		printf("%s Operator TDot %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\&		printf("%s Operator TBitwiseAnd %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\*		printf("%s Operator TStar %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\+		printf("%s Operator TPlus %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\-		printf("%s Operator TMinus %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\~		printf("%s Operator TTilde %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\!		printf("%s Operator TBang %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\/		printf("%s Operator TSlash %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\% 		printf("%s Operator TPercent %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\<		printf("%s Operator TGreater %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\>		printf("%s Operator TLess %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\^		printf("%s Operator TCarat %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\|		printf("%s Operator TPipe %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\?		printf("%s Operator TQuestion %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\:		printf("%s Operator TColon %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\=		printf("%s Operator TAssign %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\,		printf("%s Operator TComma %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\-\>	printf("%s Operator TArrow %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\+\+	printf("%s Operator TIncrement %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\-\-	printf("%s Operator TDecrement %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\<\<	printf("%s Operator TLeftShift %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\>\>	printf("%s Operator TRightShift %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\<\=	printf("%s Operator TLessEqual %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\>\=	printf("%s Operator TGreaterEqual %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\=\=	printf("%s Operator TEquals %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\!\=	printf("%s Operator TNotEqual %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\&\&	printf("%s Operator TLogicalAnd %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\|\|	printf("%s Operator TLogicalOr %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\*\=	printf("%s Operator TStarEquals %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\/\=	printf("%s Operator TSlashEquals %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\%\=	printf("%s Operator TPercentEquals %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\+\=	printf("%s Operator TPlusEquals %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\-\=	printf("%s Operator TMinusEquals %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\<\<\=	printf("%s Operator TLeftShiftEquals %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\>\>\=	printf("%s Operator TRightShiftEquals %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\&\=	printf("%s Operator TAndEquals %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\^\=	printf("%s Operator TCaratEquals %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\|\=	printf("%s Operator TPipeEquals %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\{		printf("%s Operator TOpenCurlyBrace %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\}		printf("%s Operator TCloseCurlyBrace %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\;		printf("%s Operator TSemicolon %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
\.\.\.	printf("%s Operator TEllipsis %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);


{CHARCONST} 	printf("%s Constant TCharConstant %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
{HEXINT} 		printf("%s Constant THexInteger %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
{OCTINT} 		printf("%s Constant TOctInteger %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
{DECINT} 		printf("%s Constant TDecInteger %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);
{FPCONSTANT} 	printf("%s Constant TFloatingPoint %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);

{STRINGLIT} 	printf("%s StringLiteral TStringLiteral %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);

{IDENTIFIER} 	printf("%s Identifier TIdentifier %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);


{PREPROCESS}	{ 
					sourceLine = yytext; 	
					sourceLineNo = atoi(&yytext[2])-1; 							
					size_t startOfFileName = sourceLine.find_first_of('"'); 								
					size_t endOfFileName = sourceLine.find_last_of('"'); 								
					size_t fileNameSize = endOfFileName - startOfFileName; 								
					sourceFile = strdup(sourceLine.substr(startOfFileName,fileNameSize+1).c_str()); 															
				}

[^({IDENTIFIER}|{STRINGLIT}|{FPCONSTANT}|{DECINT}|{OCTINT}|{HEXINT}|{PREPROCESS}|{OPERATOR}|{KEYWORD}] printf("%s Invalid TInvalid %i %s %i\n",yytext ,linenum, sourceFile, sourceLineNo);

%%


int main()
{

    yylex();
           
    return 0;
}



