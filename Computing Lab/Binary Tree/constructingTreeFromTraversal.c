// construct BT from inorder and postorder traversal.
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
    for (int i = 0; i < T->capacity; i++)
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

void postorder(TREE *T, int *postord, int root, int *curr_index_ptr)
{

    if (root == -1)
        return;
    postorder(T, postord, T->nodelist[root].left, curr_index_ptr);
    postorder(T, postord, T->nodelist[root].right, curr_index_ptr);
    postord[(*curr_index_ptr)++] = T->nodelist[root].data;
}

void inorder(TREE *T, int *inord, int root, int *curr_index_ptr)
{

    if (root == -1)
        return;
    inorder(T, inord, T->nodelist[root].left, curr_index_ptr);
    inord[(*curr_index_ptr)++] = T->nodelist[root].data;
    inorder(T, inord, T->nodelist[root].right, curr_index_ptr);
}

int search(int *arr, int start, int end, int data)
{ // returns index of data in array
    // int len =sizeof(arr)/sizeof(int);
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == data)
            return i;
    }
}

int constructTree(TREE *T, int *inorder, int *postorder, int *postEnd, int inStrt, int inEnd)
{
    if(inStrt > inEnd){
        return -1;
    }
    if(inStrt == inEnd)
        return inStrt;
    *postEnd = *postEnd - 1;
    int curr_rootIndex = search(inorder, inStrt, inEnd, postorder[*postEnd]);    
    int curr_rootValue = postorder[*postEnd];
    T->nodelist[curr_rootIndex].data = curr_rootValue;
    T->nodelist[curr_rootIndex].left =  constructTree(T, inorder, postorder, postEnd, inStrt, curr_rootIndex-1);
    T->nodelist[curr_rootIndex].right =  constructTree(T, inorder, postorder, postEnd, curr_rootIndex+1, inEnd);

    return curr_rootIndex;
} 

int main()
{

    TREE T;
    // T = (TREE *)malloc(sizeof(TREE));
    // printf("Enter the capacity of tree\n");
    int cap;
    scanf("%d", &cap);
    T.capacity = cap;
    T.num_nodes = 0;
    T.nodelist = (TNODE *)malloc(cap * sizeof(TNODE));
    T.nodelist[0].parent = -1;
    read_tree(&T);
    // print_tree(&T);
    // int capacity;
    // scanf("%d", &capacity);
    

    int *postord = (int *)malloc(T.capacity * sizeof(int));
    int *inord = (int *)malloc(T.capacity * sizeof(int));
    int index = 0;
    int *curr_index = &index;
    postorder(&T, postord, 0, curr_index); // tree, root of the tree, curr_index_ptr
    // for(int i = 0 ;i < T.capacity; i++){
    //     printf("%d ", postord[i]);
    // }
    *curr_index = 0;
    inorder(&T, inord, 0, curr_index);

    // T.root = search(postorder, 0, cap-1, postord[cap-1]); //index of root.
    TREE T1;
    T1.capacity = cap;
    T1.num_nodes = 0;
    T1.nodelist = (TNODE *)malloc(cap * sizeof(TNODE));
    int root_index = constructTree(&T1, inord, postord, &cap, 0, 0);
    print_tree(&T1);

    return 0;
}

/*
1 1 2
2 3 4
3 -1 -1
4 -1 -1
5 5 -1
6 6 -1
7 7 -1
8 -1 -1
*/