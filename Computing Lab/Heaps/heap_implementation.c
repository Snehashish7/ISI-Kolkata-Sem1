/*
One-based indexing (SEDGEWICK AND WAYNE)
■Children of node at i are at 2i and 2i + 1
■ Parent of node at i is at floor(i/2)

Zero-based indexing
■Children of node at i are at 2i+1 and 2i + 2
Parent of node at i is at floor((i-1)/2)
*/

#include <stdio.h>
#include <stdlib.h>
#define INIT_HEAP_SIZE 1000
typedef struct
{
    unsigned int num_allocated, num_used;
    int *array;
} INT_HEAP;

static void swapUp(INT_HEAP *h, int k)
{
    int tmp;
    while (k > 1 && (h->array[(k-1) / 2] < h->array[k])) // if parent node < then child then swap.
    {
        tmp = h->array[(k-1) / 2], h->array[(k-1) / 2] = h->array[k], h->array[k] = tmp;
        k = (k-1) / 2; //go to parent to check validity.
    }
    return;
}
static void swapDown(INT_HEAP *h, int k)
{
    int tmp;
    while (2 *k + 1 <= h->num_used)
    {
        int j = 2 *k + 1;
        /* choose child with larger key. */
        if (j < h->num_used && (h->array[j] < h->array[j + 1]))
            j++;
        if (h->array[k] >= h->array[j])
            break;
        tmp = h->array[k], h->array[k] = h->array[j], h->array[j] = tmp;
        k = j;
    }
    return;
}

void initHeap(INT_HEAP *h)
{
    h->num_allocated = INIT_HEAP_SIZE;
    h->num_used = 0;
    if (NULL == (h->array = malloc(h->num_allocated * sizeof(int))))
    {
        perror("initHeap: out of memory");
        exit(-1);
    }
    return;
}

void insert(INT_HEAP *h, int x)
{
    if (h->num_used + 1 == h->num_allocated)
    {
        h->num_allocated *= 2;
        if (NULL == (h->array = realloc(h->array, h->num_allocated * sizeof(int))))
        {
            perror("initHeap: out of memory");
            exit(-1);
        }
    }
    h->num_used++;
    h->array[h->num_used] = x;
    swapUp(h, h->num_used);
    return;
}

int deleteMax(INT_HEAP *h)
{
    int max;
    max = h->array[1];
    h->array[1] = h->array[h->num_used];
    h->num_used--;
    swapDown(h, 1);
    return max;
}

void buildheap(INT_HEAP *h)
{
    int k;
    for (k = (h->num_used / 2); k >= 0; k--)
        swapDown(h, k);
    return;
}

void heapsort(int *a, int N)
{
    int tmp;
    INT_HEAP h;
    h.num_allocated = h.num_used = N-1;
    h.array = a;
    // make heap out of array:
    buildheap(&h);
    // sort by successive delete max.
    while (h.num_used > 0)
    {
        tmp = h.array[0],
        h.array[0] = h.array[h.num_used],
        h.array[h.num_used] = tmp;
        // move max to end
        h.num_used--;
        swapDown(&h, 0);
    }
    return;
}

int main(){

    int arr[10] = {5,8,4,3,1,8,7,9,5,10};
    // arr[11] = arr[0];
    // arr[0] = -1;
    heapsort(arr, 10);
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
