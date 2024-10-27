/*
Write a program that takes a single positive integer (say N) as a command line argument, generates
N random integers between 0 and 10,000 one by one, and inserts them (one by one) into an initially
empty list in sorted order.Example:
Generated elements: 10, 3, 7, 1
List: 10 -> 3,10 -> 3,7,10 -> 1,3,7,10.

Use the following in turn to store the list:
(a) an array; //easy(not implementing now)
(b) a “traditional” linked list;
(c) an array implementation of a linked list.
Run your program 5 times each for N = 100, 500, 1000, 2000,3000,. . .,10000.
Print the sorted list to standard output, and the time taken (followed by a single tab, but no newline)
to standard error. Find the average time taken for each value of N and for each implementation method given above
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct _node
{
    int data;
    int next;
} Node;

typedef struct _list
{
    int capacity;
    int num_nodes;
    int head;
    Node *nodelist;
} List;

void initList(List *list)
{
    list->capacity = 0;
    list->head = -1;
    list->nodelist = NULL;
    list->num_nodes = 0;
}

void display(List *L, int head)
{
    int temp = head;
    while (temp != -1) // Traverse till end (-1 indicates end)
    {
        printf("%d ", L->nodelist[temp].data);
        temp = L->nodelist[temp].next;
    }
    printf("\n");
}

int main()
{
    List L;
    initList(&L);
    L.nodelist = (Node *)malloc(100 * sizeof(Node)); // Allocate space for 100 nodes

    int flag = 0;
    int i = 0;
    int prevNode = -1; // index of previous node.
    char str[100];

    fgets(str, 100, stdin); // Input a line of numbers
    int len = strlen(str);

    char num[20]; // buffer for storing the digits of each number
    int numIdx = 0;

    for (int j = 0; j < len; j++)
    {
        if (isdigit(str[j]))
        {
            num[numIdx++] = str[j]; // accumulate digits
        }
        else if (str[j] == ' ' || str[j] == '\n') // delimiter or end of input
        {
            if (numIdx > 0)
            {
                num[numIdx] = '\0'; // null-terminate the number string
                // Note: atoi does not work with string array that has non-digit elements.
                int number = atoi(num); // convert the number string to int

                // Add the new number to the list
                if (flag == 0)
                {
                    L.nodelist[i].data = number;
                    L.nodelist[i].next = -1;
                    prevNode = i;
                    L.head = i;
                    flag = 1;
                }
                else
                {
                    L.nodelist[i].data = number;
                    L.nodelist[i].next = -1;
                    L.nodelist[prevNode].next = i;
                    prevNode = i;
                }
                i++;        // move to next node index
                numIdx = 0; // reset number buffer
            }
        }
    }

    // Display the linked list
    display(&L, L.head);

    // Free the memory
    free(L.nodelist);

    return 0;
}
