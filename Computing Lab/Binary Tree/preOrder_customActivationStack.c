#include <stdio.h>
#include <stdlib.h>

#define NEW 1
#define LEFT_DONE 2
#define RIGHT_DONE 3

typedef struct {
    int data;
    int left;
    int right;
} TreeNode;

typedef struct {
    int index;
    int state;
} StackNode;

typedef struct {
    int top;
    StackNode *nodes;
    int capacity;
} Stack;

typedef struct {
    TreeNode *nodelist;
    int root;
    int size;
} TREE;

void initStack(Stack *stack, int capacity) {
    stack->top = -1;
    stack->capacity = capacity;
    stack->nodes = (StackNode *)malloc(capacity * sizeof(StackNode));
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int index, int state) {
    stack->nodes[++stack->top].index = index;
    stack->nodes[stack->top].state = state;
}

StackNode pop(Stack *stack) {
    return stack->nodes[stack->top--];
}

StackNode peek(Stack *stack) {
    return stack->nodes[stack->top];
}

void preorder(TREE *T) {
    Stack stack;
    initStack(&stack, T->size);
    
    if (T->root == -1) return;
    
    push(&stack, T->root, NEW);
    
    while (!isEmpty(&stack)) {
        StackNode x = pop(&stack);
        
        switch (x.state) {
            case NEW:
                push(&stack, x.index, LEFT_DONE);
                if (T->nodelist[x.index].left != -1)
                    push(&stack, T->nodelist[x.index].left, NEW);
                printf("%d -> ", T->nodelist[x.index].data);
                break;
                
            case LEFT_DONE:
                push(&stack, x.index, RIGHT_DONE);
                if (T->nodelist[x.index].right != -1)
                    push(&stack, T->nodelist[x.index].right, NEW);
                break;
                
            case RIGHT_DONE:
                break;
        }
    }
    printf("DONE");
    free(stack.nodes);
}

int main() {
    // Example tree setup
    TREE T;
    T.size = 5;
    T.nodelist = (TreeNode *)malloc(T.size * sizeof(TreeNode));
    T.root = 0;
    
    // Initialize nodes (example)
    T.nodelist[0] = (TreeNode){1, 1, 2};
    T.nodelist[1] = (TreeNode){2, 3, 4};
    T.nodelist[2] = (TreeNode){3, -1, -1};
    T.nodelist[3] = (TreeNode){4, -1, -1};
    T.nodelist[4] = (TreeNode){5, -1, -1};
    
    // Perform postorder traversal
    preorder(&T);
    
    free(T.nodelist);
    return 0;
}
