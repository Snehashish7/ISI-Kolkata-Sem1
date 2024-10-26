// https://www.geeksforgeeks.org/find-paths-from-corner-cell-to-middle-cell-in-maze/?ref=lbp
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int find_path(int maze[9][9], int row, int col, int n, int visited[9][9]) // n:dimension
{
    if (row < 0 || row >= n || col < 0 || col >= n || visited[row][col])
        return 0;
    if (row == n / 2 && col == n / 2)
    {
        printf(" MID <- (%d,%d)", row, col);
        return 1;
    }
    visited[row][col] = 1;
    int found_centre = find_path(maze, row, col + maze[row][col], n, visited) ||
                       find_path(maze, row, col - maze[row][col], n, visited) ||
                       find_path(maze, row + maze[row][col], col, n, visited) ||
                       find_path(maze, row - maze[row][col], col, n, visited);

    if (found_centre == 1)
    {
        printf(" <- (%d,%d)", row, col);
        return 1;
    }
    // visited[row][col] = 0;
    return 0;
}

int main()
{
    // printf("Enter the dimension of the maze(odd)\n");
    // int n;
    // scanf("%d", &n);
    // int maze[n][n];
    // printf("Enter the values of the maze\n");
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         scanf("%d", maze[i][j]);
    //     }
    // }
    int N = 9;
    int maze[9][9] =
        {
            {3, 5, 4, 4, 7, 3, 4, 6, 3},
            {6, 7, 5, 6, 6, 2, 6, 6, 2},
            {3, 3, 4, 3, 2, 5, 4, 7, 2},
            {6, 5, 5, 1, 2, 3, 6, 5, 6},
            {3, 3, 4, 3, 0, 1, 4, 3, 4},
            {3, 5, 4, 3, 2, 2, 3, 3, 5},
            {3, 5, 4, 3, 2, 6, 4, 4, 3},
            {3, 5, 1, 3, 7, 5, 3, 6, 4},
            {6, 2, 4, 3, 4, 5, 4, 5, 1}};
    int visited[9][9] = {0};
    find_path(maze, 0, 0, N, visited);
    return 0;
}