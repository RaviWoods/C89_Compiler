%{
#include <iostream>
#include <cstdlib>

int yylex();
int yyerror(const char* s);
%}

%union{
    double num;
}

%token <num> NUM 
%token ADDOP MULTOP LBRACKET RBRACKET EOLINE
%type <num> line expr term factor

/* in order to evaluate the expressions on decimal numbers
we need to include a field of type double in the C union holding the values
and to declare some of the symbols as represented by that field
*/


%%

file   : line file
       | line
       ;
line   : expr EOLINE { std::cout << "Expr value: " <<  $1 << std::endl;  }
       ;
expr   : expr ADDOP term { $$ = $1 + $3;}
       | term 
       ; 
term   : term MULTOP factor { $$ = $1 * $3; } 
       | factor 
       ;
factor : LBRACKET expr RBRACKET { $$ = $2;}
       | NUM { 
            $$ = $1 ;
        }
       ;

%%

int yyerror(const char* s){ 
    std::cout << s << std::endl;
    return -1;
}

int main(void) {
  yyparse();
}
