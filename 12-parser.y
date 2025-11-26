%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(const char *s);
%}

%token NUMBER ID
%left '+' '-'
%left '*' '/'
%left '(' ')'

%%

E : T        { printf("value is %d\n", $$ = $1); exit(0); }
  ;

T : T '+' T  { $$ = $1 + $3; }
  | T '-' T  { $$ = $1 - $3; }
  | T '*' T  { $$ = $1 * $3; }
  | T '/' T  { $$ = $1 / $3; }
  | '(' T ')' { $$ = $2; }
  | NUMBER   { $$ = $1; }
  | ID       { $$ = $1; }
  ;

%%

void yyerror(const char *s)
{
    printf("\nExpression is invalid\n");
    exit(0);
}

int main()
{
    printf("Enter the expression\n");
    yyparse();
    printf("Expression is valid\n");
    return 0;
}
