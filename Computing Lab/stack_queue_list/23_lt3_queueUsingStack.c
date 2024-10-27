#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct
{
    int top, capacity;
    int *elements;
} STACK;

typedef struct
{
    STACK F, B;
} QUEUE;

void create_stack(STACK *s)
{
    s->capacity = 0;
    s->top = -1;
    s->elements = NULL;
}

void Push(STACK *s, int elem)
{
    if (s->top == s->capacity - 1)
    {
        s->elements = (int *)realloc(s->elements, 2 * sizeof(int) * (s->capacity + 1)); // if overflow then double the size
        s->capacity = 2 * (s->capacity + 1);
    }
    s->top += 1;
    s->elements[s->top] = elem;
}

void Pop(STACK *s)
{

    if (s->top == -1)
    {
        printf("Buffer Underflow\n");
        return;
    }
    s->top -= 1;
}

void print(STACK *s)
{
    printf("Current capacity = %d\n", s->capacity);
    printf("Current top = %d\n", s->top);
    printf("Current elements:\n");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->elements[i]);
    }
    printf("\n");
}

// we will always choose the arbitrary break-point as 0. push at B pop from F.
void QINIT(STACK *F, STACK *B)
{
    create_stack(F);
    create_stack(B);
}

void B2F(STACK *F, STACK *B)
{
    while (B->top != -1)
    {
        Push(F, B->elements[B->top]);
        Pop(B);
    }
}
void ENQUEUE(STACK *F, STACK *B, int x)
{
    Push(B, x);
}

void DEQUEUE(STACK *F, STACK *B)
{
    if (F->top == -1) // empty
    {
        B2F(F, B);
    }
    Pop(F);
}

void QPRN(STACK *F, STACK *B)
{ // print reverse of F then regular B
    printf("[ ");
    for (int i = F->top; i >= 0; i--)
    {
        printf("%d ", F->elements[i]);
    }
    for (int i = 0; i <= B->top; i++)
    {
        printf("%d ", B->elements[i]);
    }
    printf("]\n");
}

int main()
{
    QUEUE Q;
    STACK F, B;
    QINIT(&F, &B);
    while (1)
    {
        int op, data;
        scanf("%d", &op);
        if (op == -1)
            break;
        if (op == 0)
        {
            scanf("%d", &data);
            ENQUEUE(&F, &B, data);
        }
        else
        {
            DEQUEUE(&F, &B);
        }
        QPRN(&F, &B);
    }
    return 0;
}
/*
0 505
1
0 149
0 736
0 939
0 373
0 172
0 317
0 649
0 166
1
1
0 143
1
1
1
1
1
1
1
-1
*/