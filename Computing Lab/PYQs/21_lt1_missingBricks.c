/* Suppose a number of cubical bricks of equal sizes are set up in succession in a row.
In some of the positions in the said row, there can be multiple bricks perfectly aligned
each other (as shown in the f igure). There are additional bricks of the same shape to
continue the construction. However, due to shortage of bricks for further construction,
you have been asked to fill some space with quick-setting cement (to be poured onto that
row) so that no cement spills over. Your only goal is to save maximum number of cubical
bricks by pouring quick-setting cement. The rest of the things will be managed by the
construction team. Write a program that takes the number of bricks already set up on
the row and return the number of maximum bricks you can save by pouring quick-setting
cement.
Input Format : The input (to be read from stdin) comprises a series of non-negative integers
representing the number of bricks aligned over each other as they successively appear in the
row.
Output Format: The output (to be printed to stdout) shows the maximum number of bricks
that can be saved by pouring quick-setting cement.
Sample Input 0:  0 1 0 2 1 0 1 3 2 1 2 1
Sample Output 0: 6


Brick Saving Logic: The number of bricks that can be saved at each position is the difference
between the smaller of the left_max and right_max at that position and the actual height of
bricks at that position.
Detailed Steps:
For each position i in the row, the number of bricks saved is calculated by:
saved_bricks[𝑖]=min(left_max[𝑖],right_max[𝑖])−heights[𝑖]

 */

#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int max_bricks_saved(int heights[], int n)
{
    if (n == 0)
    {
        return 0;
    }

    int left_max[n], right_max[n];

    // Initialize left_max and right_max arrays
    left_max[0] = heights[0];
    for (int i = 1; i < n; i++)
    {
        left_max[i] = max(left_max[i - 1], heights[i]);
    }

    right_max[n - 1] = heights[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right_max[i] = max(right_max[i + 1], heights[i]);
    }

    // Calculate the maximum bricks that can be saved
    int total_saved = 0;
    for (int i = 0; i < n; i++)
    {
        total_saved += min(left_max[i], right_max[i]) - heights[i];
    }

    return total_saved;
}

int main()
{
    int n;

    // Read the number of positions
    scanf("%d", &n);

    int heights[n];

    // Read the heights of bricks
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &heights[i]);
    }

    // Compute and print the result
    int result = max_bricks_saved(heights, n);
    printf("%d\n", result);

    return 0;
}
