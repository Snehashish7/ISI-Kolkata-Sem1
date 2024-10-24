#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

void init_arr(char arr[])
{
    for (int i = 0; i < 25; i++)
    {
        arr[i] = '_';
    }
}
void printStack(char arr[])
{
    for (int i = 0; i < 25; i++)
    {
        printf("%c", arr[i]);
    }
    printf("\n");
}
int main()
{
    char arr[25];
    int strategy;  // 0: odd-even, 1: colliding
    init_arr(arr); // init arr with: ________

    scanf("%d", &strategy);
    if (strategy == 1)
    {
        int start = 0, end = 24;
        while (1)
        {
            if (start > end)
            {
                printf("Stack Overflow!!\n");
                break;
            }
            int push_pop; // 0:push, 1:pop
            scanf("%d", &push_pop);

            if (push_pop == -1)
                break;

            int stackIdentifier; // 1: stack1(left), 2: stack2(right)
            char data;
            if (push_pop == 0)
            {
                scanf("%d %c", &stackIdentifier, &data);
                if (stackIdentifier == 1)
                {
                    arr[start] = data;
                    start += 1;
                }
                else
                {
                    arr[end] = data;
                    end -= 1;
                }
            }
            else
            {
                if (start < 0 || end > 25)
                    printf("Invalod pop operation.\n");
                scanf("%d", &stackIdentifier);
                if (stackIdentifier == 1)
                {
                    arr[start] = '_';
                    start -= 1;
                }
                else
                {
                    arr[end] = '_';
                    end += 1;
                }
            }
            printStack(arr);
        }
    }

    else if (strategy == 0)
    {
        int start_even = 0, start_odd = 1;
        while (1)
        {
            if (start_even > 24 || start_odd > 24)
            {
                printf("Stack Overflow!!\n");
                break;
            }
            int push_pop; // 0:push, 1:pop
            scanf("%d", &push_pop);

            if (push_pop == -1)
                break;

            int stackIdentifier; // 1: stack1(even), 2: stack2(odd)
            char data;
            if (push_pop == 0)
            {
                scanf("%d %c", &stackIdentifier, &data);
                if (stackIdentifier == 1)
                {
                    arr[start_even] = data;
                    start_even += 2;
                }
                else
                {
                    arr[start_odd] = data;
                    start_odd += 2;
                }
            }
            else
            {
                if (start_even < 0 || start_odd < 1)
                    printf("Invalod pop operation.\n");
                scanf("%d", &stackIdentifier);
                if (stackIdentifier == 1)
                {
                    arr[start_even] = '_';
                    start_even -= 2;
                }
                else
                {
                    arr[start_odd] = '_';
                    start_odd -= 2;
                }
            }
            printStack(arr);
        }
    }
    return 0;
}

/*
1
0 1 p 0 2 Q 0 1 h 0 1 e 0 1 v 0 1 a 0 2 M 0 1 p 0 2 B 0 1 n 0 1 k 0 1 a 0 1 g 0 1 w 0 1 f 1 2 0 1 g 0 1 v 1 1 0 1 j 1 2 0 1 t 0 1 r 1 1 0 1 d 0 1 n 0 2 G 1 2 1 1 1 2 0 2 U 1 2 0 1 n 0 1 j 0 1 a 0 1 e 0 2 L 0 1 n 0 2 R 0 1 b 20 1 h 0 1 k -1
*/