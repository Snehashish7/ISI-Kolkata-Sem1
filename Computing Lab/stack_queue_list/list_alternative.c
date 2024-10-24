#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct _node{
    int data, next;
}Node;

typedef struct _list{
    int capacity, num_nodes, head;
    Node *nodelist;
}List;

void initList(List *list){
    list->capacity = 0;
    list->head = -1;
    list->nodelist = NULL;
    list->num_nodes = 0;
}

int main()
{
    
    return 0;
}