// Given a binary tree with integer-valued nodes, and a
// target value, determine whether there exists a root-to-leaf path in the tree such that
// the sum of all node values along that path equals the target.
// Modify your program to consider all paths, not just root-to-leaf paths.

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
    printf("Enter Capacity:\n");
    scanf("%d", &capacity);
    T->capacity = capacity;
    T->num_nodes = 0;
    T->nodelist = (TNODE *)malloc(capacity * sizeof(TNODE));
    T->nodelist[0].parent = -1;
    printf("Enter the tree (data left_index right_index):\n");
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

// using Backtracking:
int pathSum(TREE *T, int nodeIndex, int target)
{
    if(nodeIndex == -1)
        return 0;
    if (target-T->nodelist[nodeIndex].data == 0)
        return 1;

    int left = pathSum(T, T->nodelist[nodeIndex].left, target - T->nodelist[nodeIndex].data);
    int right = pathSum(T, T->nodelist[nodeIndex].right, target - T->nodelist[nodeIndex].data);

    return left || right;
}

int main()
{

    TREE T;
    // T = (TREE *)malloc(sizeof(TREE));
    int target;
    printf("Enter Target:\n");
    scanf("%d", &target);

    read_tree(&T);
    print_tree(&T);

    printf("Preorder Traversal:\n");
    
    if (pathSum(&T, 0, target))
    { // Tree, current node index, target
        printf("There is a path which sums to the target\n");
    }
    else
        printf("There is no path which sums to the target\n");
    return 0;
}