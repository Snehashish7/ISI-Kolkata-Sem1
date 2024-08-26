/*Consider 2 sequences of letters (a–z), A and B, stored in arrays.
 (a) Write a program to find the number of (possibly overlapping) occurrences of the
 sequence B in A. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int main()
{
    char *A = (char *)malloc(100 * sizeof(char));
    char *B = (char *)malloc(100 * sizeof(char));
    fgets(A, 100, stdin);
    fgets(B, 100, stdin);
    int lenA = strlen(A) - 1; //-1 for \n
    int lenB = strlen(B) - 1;
    int count = 0;
    for (int i = 0; i < lenA; i++)
    {
        for (int j = 0; j < lenB; j++)
        {
            if (A[i + j] != B[j])
                break;
            if (j == lenB - 1)
                count++;
        }
    }
    printf("%d", count);
    return 0;
}
