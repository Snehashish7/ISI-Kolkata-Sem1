// C Program to create a Linked List
#include <stdio.h>
#include <stdlib.h>

// Define the structure of Node
typedef struct Node
{

    // Data field. Can add more data according to our need
    int data;

    // Pointer to the next node
    struct Node *next;
} Node;

// A function that creates a new node and returns the
// pointer to it
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    // Initially assigning the next pointer to NULL
    newNode->next = NULL;

    return newNode;
}

int main()
{

    // Create, initializing and linking all done in the
    // same step using the createNode() function
    // This will create: 10 -> NULL
    Node *first = createNode(10);

    // This will create: 10 -> 20 -> NULL
    first->next = createNode(20);

    // This will create: 10 -> 20 -> 30 -> NULL
    first->next->next = createNode(30);

    printf("Linked List: ");
    Node *temp = first;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
