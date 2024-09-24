#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
bool isAnagram(char *s, char *t)
{
    int len_s = strlen(s);
    int len_t = strlen(t);
    if (len_s != len_t)
    {
        return false;
    }
    int arr[27] = {0};

    for (int i = 0; i < len_s; i++)
    {
        arr[(int)s[i] - 97]++;
    }
    for (int i = 0; i < len_s; i++)
    {
        arr[(int)t[i] - 97]--;
    }
    for (int i = 0; i < len_s; i++)
    {
        if (arr[i] != 0)
            return false;
    }
    return true;
}
int main()
{
    printf("%d", isAnagram("nc", "xl"));
    return 0;
}