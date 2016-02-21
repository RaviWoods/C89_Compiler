%{
/* exercise: include the right header */
%}

%option noyywrap

/* exercise: declare the regex aliases here */

%%
{integer}|{real} { 
                    yylval.num = /* exercise: enter the rhs of the assignment instruction */
                    /* the num field of the yylval C union variable contains the value associated to the token */
                    return NUM; 
                }
"+"             { return ADDOP; }
"*"             { return MULTOP; }
"("             { return LBRACKET; }
")"             { return RBRACKET; }
\n              { return EOLINE; }

