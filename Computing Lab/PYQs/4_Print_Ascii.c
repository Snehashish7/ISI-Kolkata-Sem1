#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int main()
{
    int c;
    while (EOF != (c = fgetc(stdin)))
    {
        if ((char)c != '\n' && (char)c != ' ')
            printf("%c - %d\n", c, c);
    }
    return 0;
}