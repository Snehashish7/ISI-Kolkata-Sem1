#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{

    char str[] = "Abc";
    str[1] = 'c';
    printf("%s", str);
    return 0;
}