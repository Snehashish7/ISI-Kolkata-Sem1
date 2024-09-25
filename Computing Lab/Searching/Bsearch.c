// Syntax of bsearch() in C
// void* bsearch(key, base, num, size, compare);

// Parameters of bsearch()
// The bsearch() function takes five parameters:

// key: Pointer to the element to search for.
// base: Pointer to the first element of the array.
// num: Number of elements in the array.
// size: Size of each element in an array.
// compare: Function pointer to a comparison function that compares the matching element.
// Return Value of bsearch()
// The bsearch() function returns two values:

// The pointer to the matching element in the array if the key is found.
// If the key is not found, it returns a NULL pointer.

#include <stdio.h>
#include <stdlib.h>

// Comparison function for bsearch()
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    // Initialize array
    int arr[] = {1, 2, 3, 4, 5};

    // Calculate the number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Define the key to search for
    int key = 3;

    // Declare a pointer to hold the result of the search
    int *item;

    // Sort the array using qsort()
    qsort(arr, n, sizeof(int), compare);

    // Search for the key in the array using bsearch()
    item = (int *)bsearch(&key, arr, n, sizeof(int), compare);

    // If the key is found, print its value and index
    // If not found, print a message indicating it was not
    // found
    if (item != NULL)
    {
        printf("%d Found at index %ld\n", *item,
               item - arr);
    }
    else
    {
        printf("Key = %d is not found\n", key);
    }
    return 0;
}