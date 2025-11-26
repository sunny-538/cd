%{
#include <stdio.h>
#include "y.tab.h"
int yylval;
%}

%%
[0-9]+     { yylval = atoi(yytext); return NUMBER; }
[a-zA-Z]+  { return ID; }
[-+*/()]   { return yytext[0]; }
[ \t]+     { /* ignore whitespace */ }

%%

int yywrap()
{
    return 1;
}

