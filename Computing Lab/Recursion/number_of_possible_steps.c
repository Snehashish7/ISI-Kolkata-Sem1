#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int grid_walk(int n, int k)
{
    if (n == 1 || k == 0)
    {
        return 2 * k + 1;
    }
    int sum = 0;
    for (int i = 0; i <= k; i++)
    {
        if (i == 0)
            sum += grid_walk(n - 1, k - i);
        else
            sum += 2 * grid_walk(n - 1, k - i); //covering both front and back.
    }
    return sum;
}

int main()
{
    printf("Enter a number n <= 5\n");
    int n;
    scanf("%d", &n);
    printf("Enter a number k <= 100\n");
    int k;
    scanf("%d", &k);
    int steps = grid_walk(n, k);
    printf("Number of steps for n = %d, k = %d: %d", n, k, steps);
    return 0;
}