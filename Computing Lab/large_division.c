#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Helper function to check if a is greater than or equal to b
int is_greater_or_equal(char *a, char *b)
{
    int lenA = strlen(a);
    int lenB = strlen(b);

    if (lenA > lenB)
        return 1;
    if (lenA < lenB)
        return 0;

    for (int i = 0; i < lenA; i++)
    {
        if (a[i] > b[i])
            return 1;
        if (a[i] < b[i])
            return 0;
    }
    return 1;
}

// Helper function to subtract b from a (a >= b)
void subtract(char *a, char *b)
{
    int lenA = strlen(a);
    int lenB = strlen(b);
    int borrow = 0;

    for (int i = 0; i < lenB; i++)
    {
        int sub = (a[lenA - 1 - i] - '0') - (b[lenB - 1 - i] - '0') - borrow;
        if (sub < 0)
        {
            sub += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        a[lenA - 1 - i] = sub + '0';
    }

    for (int i = lenB; i < lenA; i++)
    {
        if (borrow == 0)
            break;
        int sub = (a[lenA - 1 - i] - '0') - borrow;
        if (sub < 0)
        {
            sub += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        a[lenA - 1 - i] = sub + '0';
    }

    // Remove leading zeros from a
    for (int i = 0; i < lenA; i++)
    {
        if (a[i] != '0')
        {
            strcpy(a, &a[i]);
            return;
        }
    }
    strcpy(a, "0");
}

// Division function using long division algorithm
void divide(char *num1, char *num2, char *result)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    if (strcmp(num2, "0") == 0)
    {
        printf("Error: Division by zero.\n");
        return;
    }

    if (len1 < len2 || (len1 == len2 && strcmp(num1, num2) < 0))
    {
        strcpy(result, "0");
        return;
    }

    char temp[1000] = "";
    int idx = 0;
    result[0] = '\0';

    for (int i = 0; i < len1; i++)
    {
        // Append the current digit to temp
        int lenTemp = strlen(temp);
        temp[lenTemp] = num1[i];
        temp[lenTemp + 1] = '\0';

        // Remove leading zeros from temp
        while (temp[0] == '0' && strlen(temp) > 1)
        {
            memmove(temp, temp + 1, strlen(temp));
        }

        int quotient = 0;

        // While temp >= num2, subtract num2 from temp and increase quotient
        while (is_greater_or_equal(temp, num2))
        {
            subtract(temp, num2);
            quotient++;
        }

        // Add the quotient for this digit
        result[idx++] = quotient + '0';
    }

    result[idx] = '\0';

    // Remove leading zeros from the result
    for (int i = 0; i < idx; i++)
    {
        if (result[i] != '0')
        {
            strcpy(result, &result[i]);
            return;
        }
    }
    strcpy(result, "0");
}

int main()
{
    char num1[1000], num2[1000], result[1000];

    // Example large numbers
    strcpy(num1, "12345678901234567890");
    strcpy(num2, "9876543210");

    divide(num1, num2, result);

    printf("Result of division: %s\n", result);

    return 0;
}
