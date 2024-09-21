#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main()
{

    char *s = (char *)malloc(10000 * sizeof(char));
    scanf("%s", s);
    int no_of0 = 0;
    int no_of1 = 0;
    int q_mark = 0;
    int len_s = strlen(s);
    for (int i = 0; i < len_s; i++)
    {
        if (s[i] == '1')
            no_of1++;
        else if (s[i] == '0')
        {
            no_of0++;
        }
        else
            q_mark++;
    }
    int mid = floor(len_s / 2);
    int no_of0_max = no_of0;
    int no_of1_max = no_of1;
    if (no_of1 == len_s || no_of0 == len_s)
    {
        printf("0.0000 0.0000\n");
        exit(0);
    }
    else
    {
        // min shanon-entrophy:
        if (no_of1 >= no_of0)
        {
            if (q_mark != 0)
            {
                int lacking = mid - no_of0;
                int av = q_mark;
                if (lacking > av)
                {
                    no_of0 += av;
                }
                else
                {
                    no_of0 += lacking;
                    no_of1 += av - lacking;
                }
            }
        }
        else
        {
            if (q_mark != 0)
            {
                int lacking = mid - no_of1;
                int av = q_mark;
                if (lacking > av)
                {
                    no_of1 += av;
                }
                else
                {
                    no_of1 += lacking;
                    no_of0 += av - lacking;
                }
            }
        }
        // max shanon-entrophy:
        if (no_of1_max >= no_of0_max)
        {
            if (q_mark != 0)
            {
                no_of1_max += q_mark;
            }
        }
        else
        {
            if (q_mark != 0)
            {
                no_of0_max += q_mark;
            }
        }
    }
    // Now find the shanon entrophy using the 0,1's in min and max part.
    printf("Min Shanon entrophy 0,1's: %d %d\n", no_of0, no_of1);
    printf("Max Shanon entrophy 0,1's: %d %d", no_of0_max, no_of1_max);
    return 0;
}