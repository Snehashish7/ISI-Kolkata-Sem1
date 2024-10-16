#include <stdio.h>

void swap(int *m, int *n){
    int temp = *m;
    *m = *n;
    *n = temp; 
}

void permute(int arr[], int index, int len){
    if(index == len){
        for(int i = 0; i < len; i++){
            printf("%d",arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i = index; i < len; i++){
        swap(&arr[0], &arr[i]);
        permute(arr, index+1, len); // not i+1 since at each level index should increase by one only.
        swap(&arr[i],&arr[0]);
    }

}

int main(){

    int n;
    scanf("%d",&n);
    int arr[100];
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    permute(arr,0,n);
    return 0;
}