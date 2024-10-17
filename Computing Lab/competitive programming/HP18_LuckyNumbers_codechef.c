// https://www.codechef.com/problems/HP18?tab=statement

#include <stdio.h>

int main(void)
{

    int T, N, a, b, alice, bob, num, overlap;
    scanf("%d", &T);

    while (T--)
    {

        // Reading sequence length and lucky numbers
        scanf("%d %d %d", &N, &a, &b);

        // Setting multiple counters, overlap flag
        bob = 0, alice = 0, overlap = 0;

        while (N--)
        {

            // Parsing the sequence by node
            scanf("%d", &num);

            // Incrementing multiple counters
            if (num % a == 0)
                bob += 1;
            if (num % b == 0)
                alice += 1;

            // Checking if any multiples are common
            if (overlap == 0)
            {
                if (num % a == 0 && num % b == 0)
                    overlap = 1;
            }
        }

        // Reporting the correct winner
        if (bob > alice)
            printf("BOB\n");
        else if (bob < alice)
            printf("ALICE\n");
        else if (overlap == 1)
            printf("BOB\n");
        else
            printf("ALICE\n");
    }
}