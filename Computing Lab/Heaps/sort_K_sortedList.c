#include <stdio.h>
#include <stdlib.h>
#define INIT_HEAP_SIZE 1000

typedef struct list
{
    int data;
    struct list *next;
} NODE;

typedef struct
{
    unsigned int num_allocated, num_used;
    NODE *array;
} INT_HEAP;

static void swapUp(INT_HEAP *h, int k)
{
    NODE tmp;
    while (k > 0 && h->array[(k - 1) / 2].data > h->array[k].data)
    {
        tmp = h->array[(k - 1) / 2];
        h->array[(k - 1) / 2] = h->array[k];
        h->array[k] = tmp;
        k = (k - 1) / 2;
    }
}

static void swapDown(INT_HEAP *h, int k)
{
    NODE tmp;
    while (2 * k + 1 < h->num_used)
    {
        int j = 2 * k + 1;
        if (j + 1 < h->num_used && h->array[j].data > h->array[j + 1].data)
            j++;
        if (h->array[k].data <= h->array[j].data)
            break;
        tmp = h->array[k];
        h->array[k] = h->array[j];
        h->array[j] = tmp;
        k = j;
    }
}

void initHeap(INT_HEAP *h)
{
    h->num_allocated = INIT_HEAP_SIZE;
    h->num_used = 0;
    h->array = malloc(h->num_allocated * sizeof(NODE));
    if (!h->array)
    {
        perror("initHeap: out of memory");
        exit(-1);
    }
}

void insert(INT_HEAP *h, NODE x)
{
    if (h->num_used == h->num_allocated)
    {
        h->num_allocated *= 2;
        h->array = realloc(h->array, h->num_allocated * sizeof(NODE));
        if (!h->array)
        {
            perror("initHeap: out of memory");
            exit(-1);
        }
    }
    h->array[h->num_used] = x;
    swapUp(h, h->num_used);
    h->num_used++;
}

NODE deleteMin(INT_HEAP *h)
{
    NODE min = h->array[0];
    h->array[0] = h->array[--h->num_used];
    swapDown(h, 0);
    return min;
}

void buildheap(INT_HEAP *h)
{
    for (int k = h->num_used / 2 - 1; k >= 0; k--)
        swapDown(h, k);
}

void inputKList(NODE **ptr, int k)
{
    for (int i = 0; i < k; i++)
    {
        int n;
        scanf("%d", &n);
        NODE *prev_node = NULL;
        for (int j = 0; j < n; j++)
        {
            int data;
            scanf("%d", &data);
            NODE *node = malloc(sizeof(NODE));
            node->data = data;
            node->next = NULL;
            if (!prev_node)
            {
                ptr[i] = node;
            }
            else
            {
                prev_node->next = node;
            }
            prev_node = node;
        }
    }
}

int main()
{
    int k;
    scanf("%d", &k);
    NODE *ptr[k];

    inputKList(ptr, k);

    int *res = malloc(100 * sizeof(int));
    INT_HEAP h;
    h.num_allocated = k;
    // when we do not use buildheap and just insert one by one we set num_used to 0.
    //  but when we use buildheap we insert the whole array in the heap so num_used = n.
    h.num_used = k;
    h.array = malloc(h.num_allocated * sizeof(NODE));

    for (int i = 0; i < k; i++)
    {
        if (ptr[i])
        {
            h.array[i] = *ptr[i];
        }
    }
    buildheap(&h);
    int i = 0;
    while (h.num_used > 0)
    {
        NODE min = deleteMin(&h);
        if (min.next)
        {
            insert(&h, *min.next);
        }
        res[i++] = min.data;
    }

    for (int j = 0; j < i; j++)
    {
        printf("%d ", res[j]);
    }
    printf("\n");

    free(res);
    free(h.array);
    return 0;
}
/*
4
3 10 20 30
2 1 2
5 5 15 25 30 35
4 3 9 27 81
*/