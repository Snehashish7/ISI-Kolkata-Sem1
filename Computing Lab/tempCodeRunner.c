#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(){

    char *str = (char *)malloc(100*sizeof(char));
    int c;
    char prev_char = '0';
    int count = 0;
    while(EOF != (c = fgetc(stdin))){
        if(isdigit(c)){
            printf("%c",c);
        }
    }
    return 0;
}