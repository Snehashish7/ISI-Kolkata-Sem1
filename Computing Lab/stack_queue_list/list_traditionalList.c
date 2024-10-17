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
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createNode(int num)
{
    Node *head;
    head = (Node *)malloc(sizeof(Node));
    head->data = num;
    head->next = NULL;
    return head;
}

void insert(Node *head, int num)
{

    Node *temp = head;
    Node *prev = head;
    Node *newNode = createNode(num);
    while (temp != NULL)
    {
        if (temp->data <= num && temp->next != NULL) // if num is not greater than temp -> data just pass.
        {
            prev = temp;
            temp = temp->next;
        }
        else if (temp->data <= num && temp->next == NULL) ////if num is not greater than temp -> data but
        // there is no next element so we just paste the new element as last element..
        {

            temp->next = newNode;
            newNode->next = NULL;
            temp = temp->next;
        }
        else if (temp->data > num)
        {
            newNode->next = temp;
            prev->next = newNode;
            break;
        }
    }
}

void display(Node *head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data != -1)
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int N;
    scanf("%d", &N);
    Node *head = createNode(-1);
    srand(time(NULL));
    while (N--)
    {
        int rand_num = rand() % 10000 + 1;
        insert(head, rand_num);
        display(head);
    }
    return 0;
}