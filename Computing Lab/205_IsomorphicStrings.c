#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
bool isIsomorphic(char* s, char* t) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    int *arr_s = (int *)malloc(150*sizeof(int));
    int *arr_t = (int *)malloc(150*sizeof(int));
    for(int i = 0; i < 150; i++){
        arr_s[i] = 0;
        arr_t[i] = 0;
    }
    for(int i = 0; i < len_s; i++){
        arr_s[s[i] - '0']++;
    }
    for(int i = 0; i < len_t; i++){
        arr_t[t[i] - '0']++;
    }
    int flag1 = 0;
    for(int i = 65; i < 123; i++){
        int flag2 = 0;
        for(int j = 65; j < 123; j++){
            if(arr_s[i] == arr_t[j]){
                flag2 = 1;
                arr_t[j] = -1;
                break;
            }
        }
        if(flag2 == 0){
            flag1 = 1;
            break;
        }
    }
    if(flag1 == 0)
        return true;
    return false;
}

int main(){

    char *s = "paper";
    char *t = "title";
    printf("%d", isIsomorphic(s,t));
    return 0;
}