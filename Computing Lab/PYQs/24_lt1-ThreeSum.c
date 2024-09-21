#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap(char *xp, char *yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSortDesc(char *s, int len)
{
    int i, j;
    bool swapped;
    for (i = 0; i < len - 1; i++)
    {
        swapped = false;
        for (j = 0; j < len - i - 1; j++)
        {
            if (s[j] < s[j + 1])
            {
                swap(&s[j], &s[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

int main()
{
    char *s = (char *)malloc(1001 * sizeof(char));
    scanf("%1000s", s);
    int s_len = strlen(s);

    bubbleSortDesc(s, s_len);
    int total_sum = 0;
    for (int i = 0; i < s_len; i++)
    {
        total_sum += (s[i] - '0');
    }

    if (total_sum % 3 == 0)
    {
        printf("%s\n", s);
    }
    else
    {
        int removed[2] = {-1, -1};
        int diff = total_sum % 3;
        int flag = 1;
        // Try to remove one digit
        for (int i = s_len - 1; i >= 0; i--)
        {
            if ((s[i] - '0') % 3 == diff)
            {
                s[i] = 'X'; // Mark for removal
                flag = 0;
                break;
            }
        }

        // If no single digit removed, try to remove two digits
        int count = 0;
        if (flag != 0)
        {
            for (int i = s_len - 1; i >= 0; i--)
            {
                if ((s[i] - '0') % 3 == (3 - diff) % 3)
                {
                    s[i] = 'X'; // Mark for removal
                    count++;
                }
                if (count == 2)
                    break;
            }
        }

        // Print result excluding marked digits
        bool printed = false;
        for (int i = 0; i < s_len; i++)
        {
            if (s[i] != 'X')
            {
                printf("%c", s[i]);
                printed = true;
            }
        }
        if (!printed)
            printf("0");
        printf("\n");
    }
    free(s);
    return 0;
}
