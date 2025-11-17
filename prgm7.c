#include <stdio.h>
#include <stdlib.h>

char in[200];
int i = 0;

void S(), L(), Lp();

void match(char c){
    if(in[i] == c) i++;
    else { printf("Error at %c\n", in[i]); exit(1); }
}

void S(){
    if(in[i]=='('){
        match('('); L(); match(')');
    }
    else if(in[i]=='a'){
        match('a');
    }
    else { printf("Invalid %c\n", in[i]); exit(1); }
}

void L(){
    S();
    Lp();
}

void Lp(){
    if(in[i]==','){
        match(','); S(); Lp();
    }
}

int main(){
    scanf("%s", in);
    S();
    if(in[i]=='\0') printf("Parsing successful!\n");
    else printf("Parsing failed at %c\n", in[i]);
}
