#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_word(char *s, int i, int len_s){
    while(s[i] != ' ' && i <= len_s-1){
        printf("%c",s[i]);
        i++;
    }
    printf(" ");
}
int main() {
    char s[128];
    fgets(s, sizeof(s), stdin);
    int len_s = strlen(s);
    if (s[len_s-1] == '\n'){
        s[len_s-1] = '\0';
        len_s--;
    }
    int space_index = -1;
    for(int i = len_s-1; i >= 0; i--){
        if(s[i] == ' '){
            print_word(s,i+1, len_s);
        }
        else if(i == 0){
            print_word(s,0, len_s);
        }
    }
    return 0;
}
