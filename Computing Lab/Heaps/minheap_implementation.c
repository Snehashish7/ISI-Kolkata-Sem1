#include <stdio.h>
#include <stdlib.h>
#define INIT_HEAP_SIZE 1000

typedef struct {
    unsigned int num_allocated, num_used;
    int *array;
} INT_HEAP;

static void swapUp(INT_HEAP *h, int k) {
    int tmp;
    while (k > 0 && (h->array[(k - 1) / 2] > h->array[k])) { // if parent > child, swap
        tmp = h->array[(k - 1) / 2];
        h->array[(k - 1) / 2] = h->array[k];
        h->array[k] = tmp;
        k = (k - 1) / 2; // go to parent
    }
}

static void swapDown(INT_HEAP *h, int k) {
    int tmp;
    while (2 * k + 1 < h->num_used) {
        int j = 2 * k + 1;
        // Choose child with smaller key
        if (j + 1 < h->num_used && (h->array[j] > h->array[j + 1])) {
            j++;
        }
        if (h->array[k] <= h->array[j]) {
            break;
        }
        tmp = h->array[k];
        h->array[k] = h->array[j];
        h->array[j] = tmp;
        k = j;
    }
}

void initHeap(INT_HEAP *h, int size) {
    h->num_allocated = size > 0 ? size : INIT_HEAP_SIZE;
    h->num_used = 0;
    h->array = malloc(h->num_allocated * sizeof(int));
    if (!h->array) {
        perror("initHeap: out of memory");
        exit(-1);
    }
}

void insert(INT_HEAP *h, int x) {
    if (h->num_used == h->num_allocated) {
        h->num_allocated *= 2;
        h->array = realloc(h->array, h->num_allocated * sizeof(int));
        if (!h->array) {
            perror("initHeap: out of memory");
            exit(-1);
        }
    }
    h->array[h->num_used] = x;
    swapUp(h, h->num_used);
    h->num_used++;
}

int deleteMin(INT_HEAP *h) {
    if (h->num_used == 0) {
        fprintf(stderr, "Heap underflow\n");
        exit(-1);
    }
    int min = h->array[0];
    h->array[0] = h->array[h->num_used - 1];
    h->num_used--;
    swapDown(h, 0);
    return min;
}

void buildHeap(INT_HEAP *h) {
    for (int k = h->num_used / 2 - 1; k >= 0; k--) {
        swapDown(h, k);
    }
}

// Heapsort using min-heap to get sorted in ascending order
void heapSort(int *a, int N) {
    INT_HEAP h;
    initHeap(&h, N);
    for (int i = 0; i < N; i++) {
        insert(&h, a[i]);
    }

    for (int i = 0; i < N; i++) {
        a[i] = deleteMin(&h);
    }

    free(h.array);
}

int main() {
    int arr[10] = {5, 8, 4, 3, 1, 8, 7, 9, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
