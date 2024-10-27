#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

void z_curve(int top_left_row, int top_left_column, int bottom_right_row, int bottom_right_column, int **matrix)
{
    /* Base case */
    if (top_left_row == bottom_right_row &&
        top_left_column == bottom_right_column)
    {
        printf("%d", matrix[top_left_row][top_left_column]);
        return;
    }
    /*    Recurse */
    /* upper-left sub-square    */
    z_curve(top_left_row, top_left_column, (top_left_row + bottom_right_row) / 2, (top_left_column + bottom_right_column) / 2,
            matrix);

    /* upper-right sub-square */
    z_curve(top_left_row,
            (top_left_column + bottom_right_column) / 2 + 1, (top_left_row + bottom_right_row) / 2,
            bottom_right_column,
            matrix);
    /* lower-left sub-square */
    z_curve((top_left_row + bottom_right_row) / 2 + 1,
            top_left_column,
            bottom_right_row,
            (top_left_column + bottom_right_column) / 2,
            matrix);
    /* lower-right sub-square */
    z_curve((top_left_row + bottom_right_row) / 2 + 1,
            (top_left_column + bottom_right_column) / 2 + 1,
            bottom_right_row, bottom_right_column,
            matrix);
    return;
}

int main()
{
    return 0;
}