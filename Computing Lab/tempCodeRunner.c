#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{

    char str[] = "Abc DEf Ghii";
    const char delim[] = " ";
    char *word = strtok(str, delim);
    while (word != NULL)
    {
        printf("%s\n", word);
        word = strtok(NULL, delim);
    }
    return 0;
}