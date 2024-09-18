#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
typedef struct list list; // typedef existing_name alias_name;
struct list
{
    int size;
    int *arr;
};
list createList()
{
    struct list L;
    L.size = 0;
    L.arr = NULL;
    return L;
}

list append(list L, int a)
{
    L.arr = (int *)realloc(L.arr, (L.size + 1) * sizeof(int));
    L.arr[L.size] = a;
    L.size++;
    return L;
}
int main()
{
    struct list L = createList();
    L = append(L, 10);
    printf("%d", L.arr[0]);
    return 0;
}