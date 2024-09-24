#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 10 // Max length for strings including null terminator

// Define the LIST structure
typedef struct {
    int size;      // Size of the list
    char **arr;    // Dynamically allocated array of strings
} LIST;

// (a) create_list(void): returns an empty list
LIST create_list() {
    LIST l;
    l.size = 0;
    l.arr = NULL; // No elements yet
    return l;
}

// (b) print_list(LIST L): print the elements of the list separated by spaces
void print_list(LIST L) {
    for (int i = 0; i < L.size; i++) {
        printf("%s ", L.arr[i]);
    }
    printf("\n");
}

// (c) append(LIST L, char *a): appends the string to the end of the list
LIST append(LIST L, char *a) {
    L.arr = (char **)realloc(L.arr, (L.size + 1) * sizeof(char *));
    L.arr[L.size] = (char *)malloc(MAX_STR_LEN * sizeof(char));
    strncpy(L.arr[L.size], a, MAX_STR_LEN);
    L.size++;
    return L;
}

// (d) prepend(LIST L, char *a): prepends the string to the beginning of the list
LIST prepend(LIST L, char *a) {
    L.arr = (char **)realloc(L.arr, (L.size + 1) * sizeof(char *));
    for (int i = L.size; i > 0; i--) {
        L.arr[i] = L.arr[i - 1];
    }
    L.arr[0] = (char *)malloc(MAX_STR_LEN * sizeof(char));
    strncpy(L.arr[0], a, MAX_STR_LEN);
    L.size++;
    return L;
}

// (e) deletelast(LIST L): deletes the last string of the list
LIST deletelast(LIST L) {
    if (L.size == 0) {
        return L;
    }
    free(L.arr[L.size - 1]);
    L.size--;
    L.arr = (char **)realloc(L.arr, L.size * sizeof(char *));
    return L;
}

// (f) deletefirst(LIST L): deletes the first string of the list
LIST deletefirst(LIST L) {
    if (L.size == 0) {
        return L;
    }
    free(L.arr[0]);
    for (int i = 1; i < L.size; i++) {
        L.arr[i - 1] = L.arr[i];
    }
    L.size--;
    L.arr = (char **)realloc(L.arr, L.size * sizeof(char *));
    return L;
}

// (g) deleteall(LIST L, char *a): deletes all occurrences of the string a
LIST deleteall(LIST L, char *a) {
    for (int i = 0; i < L.size; ) {
        if (strcmp(L.arr[i], a) == 0) {
            free(L.arr[i]);
            for (int j = i + 1; j < L.size; j++) {
                L.arr[j - 1] = L.arr[j];
            }
            L.size--;
            L.arr = (char **)realloc(L.arr, L.size * sizeof(char *));
        } else {
            i++;
        }
    }
    return L;
}

// Test the implementation
int main() {
    LIST myList = create_list();
    myList = append(myList, "Apple");
    myList = append(myList, "Apple");
    myList = append(myList, "Apple");
    myList = append(myList, "Apple");
    myList = append(myList, "Apple");
    myList = append(myList, "Apple");
    myList = append(myList, "Apple");
    myList = append(myList, "Apple");
    myList = append(myList, "Apple");
    myList = prepend(myList,"lemon");
    print_list(myList);
    free(myList.arr);

    return 0;
}
