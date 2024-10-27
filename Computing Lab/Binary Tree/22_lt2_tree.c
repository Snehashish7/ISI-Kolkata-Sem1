#include <stdio.h>
#include <stdlib.h>
typedef struct tnode
{
    int data;
    int left, right, level;
    int parent;
} TNODE;

typedef struct
{
    int capacity, num_nodes, root;
    TNODE *nodelist;
} TREE;

void read_tree(TREE *T, int k, int index, int level, int *nodeArr)
{
    if (k == 0 && level == 3) // at leaf
    {
        T->nodelist[index].data = nodeArr[0] | !(nodeArr[1]);
        T->nodelist[index].left = -1;
        T->nodelist[index].right = -1;
        T->nodelist[index].level = level;
        return;
    }
    if (k == 0 && level == 4)
    {
        T->nodelist[index].data = (nodeArr[0] * (nodeArr[1])) | (!(nodeArr[1]) * nodeArr[2]);
        T->nodelist[index].left = -1;
        T->nodelist[index].right = -1;
        T->nodelist[index].level = level;
        return;
    }
    T->nodelist[index].data = level;
    T->nodelist[index].left = 2 * index + 1;
    T->nodelist[index].right = 2 * index + 2;
    T->nodelist[index].level = level;
    nodeArr[level - 1] = 0;
    read_tree(T, k - 1, 2 * index + 1, level + 1, nodeArr); // to left
    nodeArr[level - 1] = 1;
    read_tree(T, k - 1, 2 * index + 2, level + 1, nodeArr); // to right

    return;
}

void print_tree(TREE *T, int k)
{
    for (int i = 0; i < (1 << (k + 1)) - 1; i++)
    {
        printf("%d %d %d %d", T->nodelist[i].data, T->nodelist[i].left, T->nodelist[i].right, T->nodelist[i].level);
        printf("\n");
    }
}

int main()
{
    printf("Enter k\n");
    int k;
    scanf("%d", &k);
    int *nodeArr = (int *)malloc(k * sizeof(int));
    TREE T;
    T.nodelist = (TNODE *)malloc(1 << (k + 1) * sizeof(TNODE));
    // // T = (TREE *)malloc(sizeof(TREE));
    int index = 0;
    read_tree(&T, k, index, 1, nodeArr);
    print_tree(&T, k);
    // printf("Preorder Traversal:\n");
    // preorder(&T, 0); // tree, root of the tree
    // // similarly we can do inorder and postorder traversal.
    return 0;
}