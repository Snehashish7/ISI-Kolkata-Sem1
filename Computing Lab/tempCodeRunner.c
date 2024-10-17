#include <stdio.h>

int main()
{
    // your code goes here
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int N, a, b;
        scanf("%d", &N);
        scanf("%d", &a);
        scanf("%d", &b);
        int arr[N];
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        int turn = 0;  // 0: Bob, 1: Alice
        int winF = -1; // win flag
        while (1)
        {
            if (turn == 0)
            {
                int remF = 0;
                for (int i = 0; i < N; i++)
                {
                    if (arr[i] && arr[i] % a == 0)
                    {
                        remF = 1; // atleat one element removed
                        sum -= arr[i];
                        arr[i] = 0; // vacating the pos
                    }
                }
                if (remF == 0)
                {
                    winF = 1;
                    break;
                }
                else if (sum == 0)
                {
                    winF = 0;
                    break;
                }
                turn = 1;
            }
            else if (turn == 1)
            {
                int remF = 0;
                for (int i = 0; i < N; i++)
                {
                    if (arr[i] && arr[i] % b == 0)
                    {
                        remF = 1; // atleat one element removed
                        sum -= arr[i];
                        arr[i] = 0;
                    }
                }
                if (remF == 0)
                {
                    winF = 0;
                    break;
                }
                else if (sum == 0)
                {
                    winF = 1;
                    break;
                }
                turn = 0;
            }
        }
        if (winF == 0)
            printf("BOB\n");
        else
            printf("ALICE\n");
    }
}
