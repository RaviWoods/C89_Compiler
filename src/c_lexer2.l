%option noyywrap

%{
#include <stdio.h>

%}

LOWERCASE [a-z]

UPPERCASE [A-Z]

NONDIGIT _|{LOWERCASE}|{UPPERCASE}

DIGIT [0-9]

KEYWORD auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|float|short|unsigned|continue|for|signed|void|default|goto|sizeof|volatile|do|if|static|while

IDENTIFIER {NONDIGIT}({DIGIT}|{NONDIGIT})*

%%
KEYWORD printf("A keyword"); 
IDENTIFIER printf("An identifier"); 

%%


int main()
{
	yylex();
    
    return 0;
}

