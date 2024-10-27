#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// Stack implementation
typedef struct
{
    char data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *stack)
{
    stack->top = -1;
}

bool isStackEmpty(Stack *stack)
{
    return stack->top == -1;
}

bool push(Stack *stack, char value)
{
    if (stack->top < MAX_SIZE - 1)
    {
        stack->data[++stack->top] = value;
        return true;
    }
    return false;
}

char pop(Stack *stack)
{
    if (!isStackEmpty(stack))
    {
        return stack->data[stack->top--];
    }
    return '\0'; // Return null character if stack is empty
}

char peek(Stack *stack)
{
    if (!isStackEmpty(stack))
    {
        return stack->data[stack->top];
    }
    return '\0';
}

bool isValidParenthesis(const char *str)
{
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < strlen(str); i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            // Push opening brackets onto the stack
            push(&stack, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            // Check for matching closing bracket
            if (isStackEmpty(&stack))
            {
                return false; // Unmatched closing bracket
            }

            char top = pop(&stack);
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                return false; // Mismatched brackets
            }
        }
    }

    // If stack is empty, all parentheses are matched
    return isStackEmpty(&stack);
}

int main()
{
    char str[MAX_SIZE];

    printf("Enter a string with parentheses: ");
    scanf("%s", str);

    if (isValidParenthesis(str))
    {
        printf("The parentheses are valid.\n");
    }
    else
    {
        printf("The parentheses are not valid.\n");
    }

    return 0;
}
