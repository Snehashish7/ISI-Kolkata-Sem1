#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct _node
{
    int data;
    struct _node *next;
} node;

void displayList(node *head)
{

    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data != -1)
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int cyclelen(node *head)
{
    int visited[100] = {0};
    node *temp = head;
    int count1 = 0, count2 = 0;
    node *ptr; // points to the cycle starting position.
    while (1)
    {
        if(visited[temp->data] == 1){
            
            ptr = temp;
            break;
        }
        visited[temp->data] = 1;
        temp = temp->next;
        count1 += 1;
    }
    temp = head;
    while (1)
    {
        if(temp == ptr)
            break;
        temp = temp->next;
        count2 += 1;
    }
    return count1-count2;
}

node *genrho(int M, int X)
{
    int flag = 0;
    node *head, *prev_ptr;
    int visited[1000] = {0};
    while (1)
    {
        if (visited[X] == 1)
        {
            node *temp = head;
            while (temp)
            {
                if (temp->data == X)
                {
                    prev_ptr->next = temp;
                    break;
                }
                temp = temp->next;
            }
            printf("%d: Cycle detected... breaking...\n", X);
            break;
        }

        visited[X] = 1;
        node *temp = (node *)malloc(sizeof(node));
        if (flag == 0)
        {
            head = temp;
            head->data = X;
            head->next = NULL;
            prev_ptr = head;
            flag = 1;
        }
        else
        {
            prev_ptr->next = temp;
            temp->data = X;
            temp->next = NULL;
            prev_ptr = temp;
        }
        printf("%d: Inserted... continuing...\n", X);
        int X1 = (X * X + 1) % M;
        X = X1;
    }
    return head;
}

int main()
{
    // int M = 50, X = 11;
    int M = 100, X = 5;
    node *head = genrho(M, X);
    printf("cycle length = %d", cyclelen(head));
    return 0;
}