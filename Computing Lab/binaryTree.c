#include <stdio.h>
#include <stdlib.h>
typedef struct tnode{
    int data;
    int left, right;
    int parent;
} TNODE;

typedef struct {
    int capacity, num_nodes, root;
    TNODE *nodelist;
} TREE;


void read_tree(TREE *T){
    int capacity;
    scanf("%d", &capacity);
    T->capacity = capacity;
    T->num_nodes = 0;
    T->nodelist = (TNODE *)malloc(capacity*sizeof(TNODE));
    T->nodelist[0].parent = -1;
    for(int i = 0; i < capacity; i++){
        TNODE node;
        scanf("%d %d %d %d", &node.data, &node.left, &node.right);
        T->nodelist[i] = node;
        T->nodelist[T->nodelist->left].parent = node.data;
        T->nodelist[T->nodelist->right].parent = node.data;
    }
}

void print_tree(TREE *T){
    for(int i = 0; i < T->capacity; i++){
        printf("%d %d %d %d",T->nodelist[i].data, T->nodelist[i].left, T->nodelist[i].right, T->nodelist[i].parent);
        printf("\n");
    }
}

int main(){

    TREE T;
    // T = (TREE *)malloc(sizeof(TREE));
    read_tree(&T);
    print_tree(&T);
    return 0;
}