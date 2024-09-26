#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void func(int *arr){
    arr[2] = 3;
}
int main()
{
    int len = 5;
    int arr[len];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 4;
    arr[3] = 4;
    arr[4] = 5;
    func(arr);
    printf("%d", arr[2]);
    return 0;
}