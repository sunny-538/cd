#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char in[100];
int i=0;

void E(), Ep(), T(), Tp(), F();

void match(char c){
    if(in[i]==c) i++;
    else { printf("Error at %c\n", in[i]); exit(1); }
}

void E(){ T(); Ep(); }

void Ep(){
    while(in[i]=='+'){ match('+'); T(); }
}

void T(){ F(); Tp(); }

void Tp(){
    while(in[i]=='*'){ match('*'); F(); }
}

void F(){
    if(in[i]=='('){ match('('); E(); match(')'); }
    else if(isalpha(in[i])) match(in[i]);
    else { printf("Invalid symbol %c\n", in[i]); exit(1); }
}

int main(){
    scanf("%s", in);
    E();
    if(in[i]=='\0') printf("Parsing successful!");
    else printf("Parsing failed at %c", in[i]);
}
