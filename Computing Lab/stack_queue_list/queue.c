// implement using circular array
//  rear:insertion, front: deletion
//  full: (rear+1)mod n == front
//  empty: rear == front.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
    int capacity, num_elements, front, rear;
    int elements[5];
} QUEUE;

// Circular-queue implementation.
QUEUE create_queue()
{
    QUEUE s;
    s.capacity = 5;
    s.num_elements = 0;
    s.front = 0;
    s.rear = 0;
    // s.elements = (int *)malloc(100 * sizeof(int));
    return s;
}

void enqueue(QUEUE *s, int elem)
{
    if ((s->rear + 1) % (s->capacity) == s->front)
    {
        printf("Buffer overflow");
        return;
    }
    s->elements[s->rear] = elem;
    s->rear = (s->rear + 1) % (s->capacity);
    s->num_elements += 1;
}

void deque(QUEUE *s)
{

    if (s->rear == s->front)
    {
        printf("Buffer Underflow\n");
        return;
    }
    s->front = (s->front + 1) % (s->capacity);
    s->num_elements -= 1;
}

void print(QUEUE *s)
{
    printf("Current capacity = %d\n", s->capacity);
    printf("Current rear = %d\n", s->rear);
    printf("Current front = %d\n", s->front);
    printf("Current elements:\n");
    int cnt = s->num_elements;
    int i = s->front;
    while (cnt)
    {
        printf("%d ", s->elements[i]);
        i = (i + 1) % (s->capacity);
        cnt--;
    }
    printf("\n");
}

int main()
{

    QUEUE s;
    s = create_queue();
    enqueue(&s, 50);
    enqueue(&s, 50);
    enqueue(&s, 50);
    enqueue(&s, 50);
    enqueue(&s, 50);
    deque(&s);
    enqueue(&s, 50);
    deque(&s);
    print(&s);
    return 0;
}