#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int *arr = (int *)malloc((n+1)*sizeof(int));
    for(int i = 1; i <= n; i++){
        int count = 0;
        for(int j = 1; j <= i; j++){
            if(i%j == 0){
                count++;
            }
        }
        arr[i] = count;
    }

    for(int i = 1; i <= n; i++){
        if(arr[i] % 2 != 0){
            printf("%d\n",i);
        }
    }
}