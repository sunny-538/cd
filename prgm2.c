#include <stdio.h>
#include <ctype.h>

int main() {
    char s[50];
    printf("Enter token: ");
    scanf("%s", s);

    if (isalpha(s[0]))
        printf("Identifier\n");
    else if (isdigit(s[0]))
        printf("Constant\n");
    else if (s[0]=='+' || s[0]=='-' || s[0]=='*' || s[0]=='/')
        printf("Operator\n");
    else
        printf("Unknown Token\n");

    return 0;
}
