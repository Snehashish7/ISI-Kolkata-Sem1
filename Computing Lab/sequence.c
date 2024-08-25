#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){

    int a;
    // int arr[100];
    int i = 0;
    int arr[5];
    while(scanf("%d", &a) != EOF){
        arr[i%6] = a;
        int max = 0;
        if(i>=5){
            for(int j = 0; j < 6; j++){
                if(max < arr[j]){
                    max = arr[j];
                }
            }
            printf("%d",max);
        }
        i++;
    }
    int k = i%5;
    int l=0;
    int k1 = k;
    while(k1--){
        int max= 0;
        for(i = l;i <= k; i++){
            if(max < arr[i]){
                max = arr[i];
            }
        }
        printf("%d", max);
        l++;
    }

    // printf("Printing max...\n");
    // for(int j = 0; j < i; j++){
    //     int max = 0;
    //     for(int k = 0; k <= 4; k++){
    //         if((j+k) < i){
    //             if(arr[j+k] > max)
    //                 max = arr[j+k];
    //         }
    //     }
    //     printf("%d\n", max);
    // }
    return 0;
}