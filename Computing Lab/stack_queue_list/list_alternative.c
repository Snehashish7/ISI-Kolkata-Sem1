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
