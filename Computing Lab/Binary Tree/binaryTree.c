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

void preorder(TREE *T, int root)
{

    if (root == -1)
        return;
    printf("%d ", T->nodelist[root].data);
    preorder(T, T->nodelist[root].left);
    preorder(T, T->nodelist[root].right);
}
int main()
{

    TREE T;
    // T = (TREE *)malloc(sizeof(TREE));
    read_tree(&T);
    print_tree(&T);
    printf("Preorder Traversal:\n");
    preorder(&T, 0); // tree, root of the tree
    // similarly we can do inorder and postorder traversal.
    return 0;
}