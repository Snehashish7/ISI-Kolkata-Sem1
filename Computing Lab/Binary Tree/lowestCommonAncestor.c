/*
Given a binary tree stored in an array (as in the Alternative
Implementation), and the indices of two nodes in the tree, find the
index of the node that is the lowest common ancestor of the given
nodes

Approach: try top-down instead of bottom-up
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct tnode
{
    int data;
    int left, right;
    int parent;
} TNODE;

typedef struct
{
    int capacity, num_nodes, root;
    TNODE *nodelist;
} TREE;

void read_tree(TREE *T)
{
    int capacity;
    scanf("%d", &capacity);
    T->capacity = capacity;
    T->num_nodes = 0;
    T->nodelist = (TNODE *)malloc(capacity * sizeof(TNODE));
    T->nodelist[0].parent = -1;
    for (int i = 0; i < capacity; i++)
    {
        TNODE node;
        scanf("%d %d %d", &node.data, &node.left, &node.right);
        T->nodelist[i].data = node.data;
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
        printf("%d %d %d %d", T->nodelist[i].data, T->nodelist[i].left, T->nodelist[i].right, T->nodelist[i].parent);
        printf("\n");
    }
}

// idea:
/*
go left, go right. If both return > 0 then the required nodes are on curr_index's either side, so curr_index
is the LCA.
*/
int LCA(TREE *T, int node1_index, int node2_index, int curr_index)
{

    if (curr_index == -1)
        return 0;
    if (curr_index == node1_index || curr_index == node2_index)
        return curr_index; // returns > 0 value

    int left = LCA(T, node1_index, node2_index, T->nodelist[curr_index].left);
    int right = LCA(T, node1_index, node2_index, T->nodelist[curr_index].right);

    if (left > 0 && right > 0)
    {
        return curr_index;
    }
    else
        return left + right; // 0 + right = right, left + 0 = left.
}

int main()
{

    TREE T;
    // T = (TREE *)malloc(sizeof(TREE));
    read_tree(&T);
    // print_tree(&T);
    int node1_index, node2_index;
    printf("Enter the node1 index and node2 index\n");
    scanf("%d %d", &node1_index, &node2_index);
    printf("%d", LCA(&T, node1_index, node2_index, 0)); // LCA(&T): returns the index of lca.
    return 0;
}