#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct _customer
{
    int c;  // customer number
    int at; // arrival time.
    int tr; // time required to complete job
    int st; // starting time
    int wt; // waiting time = st - at
} Customer;

int hh_mm_to_minutes(char *at)
{
    int minutes = 0;
    int hrs = ((int)at[0] - 48) * 10 + ((int)at[1] - 48);
    int min = ((int)at[3] - 48) * 10 + ((int)at[4] - 48);
    minutes = hrs * 60 + min;
    return minutes;
}
void sortAT_structArr(Customer *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        Customer key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j].at > key.at)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void sortWT_structArr(Customer *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        Customer key = arr[i];
        int j = i - 1;

        // Descending order.
        while (j >= 0 && arr[j].wt < key.wt)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int temp = n;
    int n1 = n;
    Customer arr[n];
    int i = 0;
    while (temp--)
    {
        char at[5]; // arrival time
        int tr;     // time required to complete job
        scanf("%s %d", at, &tr);
        int x = hh_mm_to_minutes(at);
        // printf("%d", x);
        arr[i].at = x;
        arr[i].c = i + 1;
        arr[i].tr = tr;
        i++;
    }
    sortAT_structArr(arr, n1);
    // // print customers acc to at:
    // for (int i = 0; i < n1; i++)
    // {
    //     printf("%d %d\n", arr[i].c, arr[i].at);
    // }

    arr[0].st = arr[0].at;
    arr[0].wt = 0;
    for (int i = 1; i < n1; i++)
    {
        if (arr[i - 1].st + arr[i - 1].tr < arr[i].at)
        {
            arr[i].wt = 0;
            arr[i].st = arr[i].at;
        }
        else
        {
            arr[i].st = arr[i - 1].st + arr[i - 1].tr;
            arr[i].wt = arr[i].st - arr[i].at;
        }
    }
    sortWT_structArr(arr, n1);
    // print customers acc to wt:
    for (int i = 0; i < n1; i++)
    {
        printf("%d %d\n", arr[i].c, arr[i].wt);
    }
    return 0;
}
/*
3
10:24 3
18:30 3
10:00 24

*/