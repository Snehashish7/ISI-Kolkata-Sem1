#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char *ptr[100];
    int c;
    char *str = (char *)malloc(81*sizeof(char));
    int i = 0,j = 0;
    int n = 3;
    while(EOF != (c = fgetc(stdin))){
        if(c == '\n'){
            str[j] = '\0';
            ptr[i] = (char *)malloc(81*sizeof(char));
            strcpy(ptr[i], str);
            i++;
            j = 0;
            continue;
        }
        str[j] = (char)c;
        j++;
    }
    int parityF = 0, revF = 0;
    printf("Odd lines: 0, even lines: 1\n");
    scanf("%d",&parityF);
    printf("Reverse: 0, Straight: 1\n");
    scanf("%d",&revF);
    for(int k = 0; k < i; k++){
        if(parityF && k%2 == 0){
            printf("%s\n", ptr[k]);
        }
        
    } 
}