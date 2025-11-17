#include <stdio.h>

int main(){
    int FE=0,FI=0,FT=0,FF=0;   // FIRST flags for '(', id

    // F -> (E) | id
    FF = FI = 1;

    // T -> F  (so FIRST(T)=FIRST(F))
    FT = FF;
    FI = FI; // (id already set)

    // E -> T  (so FIRST(E)=FIRST(T))
    FE = FT;

    printf("FIRST(E) = { (, id }\n");
    printf("FIRST(T) = { (, id }\n");
    printf("FIRST(F) = { (, id }\n");
}
sample input and output
