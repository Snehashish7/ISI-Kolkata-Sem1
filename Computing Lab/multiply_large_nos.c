#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
int main()
{
    char *num1 = (char *)malloc(102 * sizeof(char));
    char *num2 = (char *)malloc(102 * sizeof(char));

    fgets(num1, 102, stdin);
    fgets(num2, 102, stdin);
    int res[100][200] = {0};
    int curr_col = 0, curr_row = 0;
    for (int i = strlen(num2) - 2; i >= 0; i--) // excluding \n
    {
        int carry = 0;
        int itr = 0;
        for (int j = strlen(num1) - 2; j >= 0; j--)
        {
            int temp = ((int)num2[i] - 48) * ((int)num1[j] - 48) + carry;
            int ones = temp % 10;
            carry = temp / 10;
            res[curr_row][199 - itr - curr_col] = ones;
            itr++;
        }
        if (carry)
            res[curr_row][199 - itr - curr_col] = carry;
        curr_row++;
        curr_col++;
        itr = 0;
    }
    int res_arr[200];
    int itr = 199;
    int carry = 0;
    for (int i = 200 - 1; i >= 0; i--) // cols
    {
        int sum = 0;
        for (int j = 0; j < 100; j++) // rows
        {
            sum += res[j][i];
        }
        sum += carry;
        carry = sum / 10;
        res_arr[itr] = sum % 10;
        itr--;
    }
    int flag = 0;
    for (int i = 0; i < 200; i++)
    {
        if (res_arr[i] > 0 && flag == 0)
        {
            flag = 1;
        }
        if (flag == 1)
        {
            printf("%d", res_arr[i]);
        }
    }
    return 0;
}