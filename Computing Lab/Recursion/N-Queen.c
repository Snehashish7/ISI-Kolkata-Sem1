#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8 // Define board size; you can change this value for different sizes

void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

// Check if it's safe to place a queen at board[row][col]
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }

    // Check the upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }

    // Check the lower diagonal on the left side
    for (i = row, j = col; i < N && j >= 0; i++, j--)
    {
        if (board[i][j])
            return false;
    }

    return true;
}

// Recursive utility function to solve N-Queen problem
bool solveNQUtil(int board[N][N], int col)
{
    if (col >= N)
    { // All queens are placed
        printSolution(board);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        { // Place queen if safe
            board[i][col] = 1;
            res = solveNQUtil(board, col + 1) || res;
            board[i][col] = 0; // Backtrack
        }
    }
    return res;
}

// Solves the N-Queen problem and prints all solutions
void solveNQ()
{
    int board[N][N] = {0};

    if (!solveNQUtil(board, 0))
    {
        printf("Solution does not exist\n");
    }
}

int main()
{
    solveNQ();
    return 0;
}
