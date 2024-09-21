#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int main()
{
    char *str = (char *)malloc(1000 * sizeof(char));
    int count = 0;
    while (EOF != scanf("%s", str))
    {
        printf("%d\n", ++count);
    }
    return 0;
}