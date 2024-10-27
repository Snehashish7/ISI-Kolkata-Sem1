#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct tnode
{
    int li, ui; // lower-interval, upper-interval
    int left, right;
    int parent;
} TNODE;

typedef struct
{
    int capacity, num_nodes, root;
    TNODE *nodelist;
} TREE;

void read_tree(TREE *T, int capacity)
{
    T->capacity = capacity;
    T->num_nodes = 0;
    T->nodelist = (TNODE *)malloc(capacity * sizeof(TNODE));
    T->nodelist[0].parent = -1;
    for (int i = 0; i < capacity; i++)
    {
        TNODE node;
        scanf("%d %d %d %d", &node.li, &node.ui, &node.left, &node.right);
        T->nodelist[i].li = node.li;
        T->nodelist[i].ui = node.ui;
        T->nodelist[i].left = node.left;
        T->nodelist[i].right = node.right;
        if (T->nodelist[i].left != -1)
            T->nodelist[T->nodelist[i].left].parent = i;

        if (T->nodelist[i].right != -1)
            T->nodelist[T->nodelist[i].right].parent = i;
    }
}

void print_tree(TREE *T)
{
    for (int i = 0; i < T->capacity; i++)
    {
        printf("%d %d %d %d", T->nodelist[i].li, T->nodelist[i].ui, T->nodelist[i].left, T->nodelist[i].right);
        printf("\n");
    }
}

// void preorder(TREE *T, int root)
// {

//     if (root == -1)
//         return;
//     printf("%d ", T->nodelist[root].data);
//     preorder(T, T->nodelist[root].left);
//     preorder(T, T->nodelist[root].right);
// }

void find_span(TREE *T, int index)
{
    if (T->nodelist[index].left == -1 && T->nodelist[index].right == -1)
        return; // the bounds remain same

    if (T->nodelist[index].left != -1)
    {
        find_span(T, T->nodelist[index].left);
        T->nodelist[index].li = MIN(T->nodelist[T->nodelist[index].left].li, T->nodelist[index].li);
        T->nodelist[index].ui = MAX(T->nodelist[T->nodelist[index].left].ui, T->nodelist[index].ui);
    }
    if (T->nodelist[index].right != -1)
    {
        find_span(T, T->nodelist[index].right);
        T->nodelist[index].li = MIN(T->nodelist[T->nodelist[index].right].li, T->nodelist[index].li);
        T->nodelist[index].ui = MAX(T->nodelist[T->nodelist[index].right].ui, T->nodelist[index].ui);
    }
}

int main()
{

    TREE T;
    // T = (TREE *)malloc(sizeof(TREE));
    int capacity;
    scanf("%d", &capacity);
    read_tree(&T, capacity);
    find_span(&T, 0);
    print_tree(&T);
    return 0;
}
/*
7
8 8 -1 1
1 20 2 3
19 30 4 5
5 15 6 -1
5 6 -1 -1
2 10 -1 -1
8 21 -1 -1
*/