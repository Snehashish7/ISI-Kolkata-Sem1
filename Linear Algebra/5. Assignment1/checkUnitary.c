#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *conjugate(char str[])
{
    int complexFlagIndex = -1;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'i')
        {
            complexFlagIndex = i;
            break;
        }
    }
    // char *real = (char *)malloc(50*sizeof(char));
    if (complexFlagIndex > -1 && str[complexFlagIndex - 1] == '+')
    {
        str[complexFlagIndex - 1] = '-';
    }
    else if (complexFlagIndex > -1 && str[complexFlagIndex - 1] == '-')
    {
        str[complexFlagIndex - 1] = '+';
    }
    return str; // no need of returning as str is modified in place.
    // //getting the real part:
    // for(int i = 0; i < complexFlagIndex-1; i++){ //going upto "+i"
    //     real[i] = str[i];
    // }

    // char *imgn = (char *)malloc(50*sizeof(char));
    // //getting the imaginary part:
    // for(int i = complexFlagIndex+1; i < len; i++){ //going after "+i"
    //     imgn[i] = str[i];
    // }
}

void transpose(char *U[50][50], int row, int col)
{
    // Transposing a matrix needs a temporary variable for swapping
    for (int i = 0; i < row; i++)
    {
        for (int j = i + 1; j < col; j++)
        {
            // Swap U[i][j] and U[j][i]
            char *temp = U[i][j];
            U[i][j] = U[j][i];
            U[j][i] = temp;
        }
    }
}
void printMat(char *U[50][50], int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%s ", U[i][j]);
        }
        printf("\n");
    }
}
int main()
{

    int row = 2;
    int col = 2;
    // char str[] = "a-ib";
    // printf("%s", conjugate(str));
    char *U[50][50];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            U[i][j] = (char *)malloc(50 * sizeof(char));
            scanf("%s", U[i][j]);
            U[i][j] = conjugate(U[i][j]);
        }
    }
    transpose(U, row, col); // at this point we get the conjugate transpose.
    printMat(U, row, col);
    return 0;
}