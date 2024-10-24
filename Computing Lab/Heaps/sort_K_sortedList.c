/*
One-based indexing (SEDGEWICK AND WAYNE)
■Children of node at i are at 2i and 2i + 1
■ Parent of node at i is at floor(i/2)

Zero-based indexing
■Children of node at i are at 2i+1 and 2i + 2
Parent of node at i is at floor((i-1)/2)
*/
 //MIN Heap
#include <stdio.h>
#include <stdlib.h>
#define INIT_HEAP_SIZE 1000
typedef struct
{
    unsigned int num_allocated, num_used;
    int *array;
} INT_HEAP;

typedef struct list
{
    int data;
    struct list *next;
} NODE;

static void swapUp(INT_HEAP *h, int k)
{
    int tmp;
    while (k > 1 && (h->array[(k - 1) / 2] > h->array[k])) // if parent node < then child then swap.
    {
        tmp = h->array[(k - 1) / 2], h->array[(k - 1) / 2] = h->array[k], h->array[k] = tmp;
        k = (k - 1) / 2; // go to parent to check validity.
    }
    return;
}
static void swapDown(INT_HEAP *h, int k)
{
    int tmp;
    while (2 * k + 1 <= h->num_used)
    {
        int j = 2 * k + 1;
        /* choose child with larger key. */
        if (j < h->num_used && (h->array[j] > h->array[j + 1]))
            j++;
        if (h->array[k] <= h->array[j])
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

int deleteMin(INT_HEAP *h)
{
    int min;
    min = h->array[0];
    h->array[0] = h->array[h->num_used];
    h->num_used--;
    swapDown(h, 0);
    return min;
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
    h.num_allocated = h.num_used = N - 1;
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

void displayList(NODE *head)
{

    NODE *temp = head;
    while (temp != NULL)
    {
        if (temp->data != -1)
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void inputKList(NODE **ptr, int k){
    for (int i = 0; i < k; i++)
    {
        int n; // number of elements
        int flag = 0;
        scanf("%d", &n);
        NODE *prev_node = NULL;
        while (n--)
        {
            int data;
            scanf("%d", &data);
            if (flag == 0)
            {
                NODE *head = (NODE *)malloc(sizeof(NODE));
                head->data = data;
                head->next = NULL;
                flag = 1;
                prev_node = head;
                ptr[i] = head;
            }
            else{
                NODE *node = (NODE *)malloc(sizeof(NODE));
                prev_node->next = node;
                node->data = data;
                node->next = NULL;
                prev_node = node;
            }
        }
    }
}
int main()
{
    int k; // no. of sorted list
    scanf("%d", &k);
    NODE *ptr[k];

    inputKList(ptr, k);

    for (int i = 0; i < k; i++)
    {
        displayList(ptr[i]);
    }
    // for(int i = 0; i < 10; i++){
    //     printf("%d ", arr[i]);
    // }
    return 0;
}
/*
4 
3 10 20 30 
2 1 2
5 5 15 25 30 35 
4 3 9 27 81 
*/