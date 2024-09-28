// // C code to implement the
// // matrix chain multiplication using recursion

// #include <stdio.h>
// #include <limits.h>

// // Matrix Ai has dimension arr[i-1] x arr[i]
// int minMultRec(int arr[], int i, int j) {            //O(2^n)

//     // If there is only one matrix
//     if (i + 1 == j)
//         return 0;

//     int res = INT_MAX;

//     // Place the first bracket at different
//     // positions or k and for every placed
//     // first bracket, recursively compute
//     // minimum cost for remaining brackets
//     // (or subproblems)
//     for (int k = i + 1; k < j; k++) {
//         int curr = minMultRec(arr, i, k)
//                   + minMultRec(arr, k, j)
//                   + arr[i] * arr[k] * arr[j];

//         if (curr < res)
//             res = curr;
//     }

//     // Return minimum count
//     return res;
// }

// int minMult(int arr[], int n) {
//     return minMultRec(arr, 0, n - 1);
// }

// int main() {
//     int arr[] = {1, 2, 3, 4, 3};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     printf("%d", minMult(arr, n));
//     return 0;
// }

// using memoisation:

#include <stdio.h>
#include <limits.h>

// Matrix Ai has dimension arr[i-1] x arr[i]
int minMultRec(int arr[], int i, int j, int dp[][100])
{ // O(2^n)

    // If there is only one matrix
    if (i + 1 == j)
        return 0;

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int res = INT_MAX;

    // Place the first bracket at different
    // positions or k and for every placed
    // first bracket, recursively compute
    // minimum cost for remaining brackets
    // (or subproblems)
    for (int k = i + 1; k < j; k++)
    {
        dp[i][j] = minMultRec(arr, i, k, dp) + minMultRec(arr, k, j, dp) + arr[i] * arr[k] * arr[j];

        if (dp[i][j] < res)
            res = dp[i][j];
    }

    // Return minimum count
    return res;
}

int minMult(int arr[], int n)
{
    int dp[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }
    return minMultRec(arr, 0, n - 1, dp);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d", minMult(arr, n));
    return 0;
}
