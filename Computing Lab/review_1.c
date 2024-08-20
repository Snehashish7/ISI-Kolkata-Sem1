#include <stdio.h>
#include <string.h>
int main(){

char str0[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
char str1[8] = { 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q' };
char str2[8] = { 'z', 'y', 'x', 'w', 'v', 'u', 't', 's' };
strcpy(str1, "abcdefghijklmnop");
printf("%s\n", str1);
for (int i=0; i<10; i++) printf("%c\n", str1[i]);
strcpy(str1, "abcdefghijklmnop");
for (int i=0; i<8; i++) printf("%c\n", str1[i]);
return 0;}