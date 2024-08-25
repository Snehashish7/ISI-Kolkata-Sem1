#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char *str = (char *)malloc(80*sizeof(char));
    char **str_arr = (char **)malloc(800*sizeof(char *));
    int c;
    int i = 0;
    while(EOF != (c = fgetc(stdin))){
        if(strcmp(str," ") && strcmp(str,"\n")){
            str_arr[i] = (char *)malloc(strlen(str)*sizeof(char));
            str_arr[i] = str;
            i++;
            str = "";
        }
        else{
            str += (char)c;
        }
    }
    for(int j = 0; j< i; j++){
        printf("%s",str_arr[j]);
    }
    return 0;
}