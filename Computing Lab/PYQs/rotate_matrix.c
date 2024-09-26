#include <stdio.h>

// Function to print the matrix
void printMatrix(int n, int mat[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to rotate the matrix 90 degrees clockwise
void rotate90Clockwise(int n, int mat[n][n])
{
    // Step 1: Transpose the matrix (swap mat[i][j] with mat[j][i])
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    // Step 2: Reverse each row........ For counter-clockwise rotation, reverse each column.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[i][n - j - 1];
            mat[i][n - j - 1] = temp;
        }
    }
}

int main()
{
    int n = 3;
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    printf("Original matrix:\n");
    printMatrix(n, mat);

    rotate90Clockwise(n, mat);

    printf("\nRotated matrix by 90 degrees clockwise:\n");
    printMatrix(n, mat);

    return 0;
}
