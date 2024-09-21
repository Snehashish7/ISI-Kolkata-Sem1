#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int inp = 0;
    int inps[10];
    int max = 0;
    int min = 0;
    while (inp < 10)
    {
        int temp;
        scanf("%d", &temp);
        inps[inp] = temp;
        if (temp >= 0 && temp > max)
            max = temp;
        else if (temp < 0 && temp < min)
            min = temp;
        inp++;
    }
    char mat[max - min][10];
    int rows_max = max;
    for (int i = 0; i < rows_max; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (inps[j] == max)
            {
                mat[i][j] = '#';
                inps[j]--;
            }
            else
            {
                mat[i][j] = ' ';
            }
        }
        max--;
    }
    int rows_min = 0;
    rows_min -= min; //(0 - (-2) = 2)
    for (int i = rows_max; i < rows_max + rows_min; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (inps[j] < 0)
            {
                mat[i][j] = '#';
                inps[j]++;
            }
            else
            {
                mat[i][j] = ' ';
            }
        }
        min++;
    }
    printf("\n\n");
    for (int i = 0; i < rows_max + rows_min; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}