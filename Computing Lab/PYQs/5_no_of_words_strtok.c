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

// or,

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <ctype.h>
// int main()
// {

//     char str[] = "Abc DEf Ghii";
//     const char delim[] = " ";
//     char *word = strtok(str, delim);
//     while (word != NULL)
//     {
//         printf("%s\n", word);
//         word = strtok(NULL, delim);
//     }
//     return 0;
// }