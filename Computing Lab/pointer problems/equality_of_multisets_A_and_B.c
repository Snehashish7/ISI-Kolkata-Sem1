/*Problem Statement (b):
The task is to determine if two sequences of letters, A and B, are equal when viewed as
multisets.

What is a Multiset?
A multiset is a generalization of a set that allows for multiple occurrences of the same
element. Unlike a regular set, where each element can appear only once, a multiset keeps
track of how many times each element appears.

Example:
Consider the sequences:

A = "aabbcc"
B = "baccab"
When viewed as multisets:

Multiset of A: {a: 2, b: 2, c: 2}
Multiset of B: {a: 2, b: 2, c: 2}
Here, both A and B contain the same characters with the same frequencies, so they
are equal as multisets.*/
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
    int flag = 0;
    int dictnA[27] = {0};
    int dictnB[27] = {0};
    for (int i = 0; i < lenA; i++)
        dictnA[(int)A[i] - 97]++;

    for (int i = 0; i < lenA; i++)
        dictnB[(int)A[i] - 97]++;

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (dictnA[i] != dictnB[i])
            {
                flag = 1;
                break;
            }
        }
    }
    if (!flag)
        printf("equal");
    else
        printf("Unequal");
    return 0;
}
