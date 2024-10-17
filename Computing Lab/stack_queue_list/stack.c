#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int top, capacity;
    int *elements;
} STACK;

STACK create_stack(STACK s)
{
    s.capacity = 0;
    s.top = -1;
    s.elements = NULL;
    return s;
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

int main()
{

    STACK s;
    s = create_stack(s);
    Push(&s, 87);
    Push(&s, 16);
    Push(&s, 36);
    Pop(&s);
    Pop(&s);
    Pop(&s);
    Pop(&s);
    print(&s);
    return 0;
}