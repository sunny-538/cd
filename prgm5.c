%{
int words = 0, lines = 0;
%}

%%
\n      { lines++; }
[ \t]+  { }          /* ignore spaces */
[^ \t\n]+ { words++; }
%%

int main(){
    yylex();
    printf("Lines = %d\nWords = %d\n", lines, words);
    return 0;
}

int yywrap(){ return 1; }
