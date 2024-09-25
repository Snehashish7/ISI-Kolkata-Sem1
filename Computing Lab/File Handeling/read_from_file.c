#include <stdio.h>

int main() {
    FILE *fp;
    char ch;

    // Open file for reading
    fp = fopen("file.txt", "r");

    if (fp == NULL) {
        printf("Error: File not found\n");
        return 1;
    }

    // Read file character by character
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch); // Print character to the console
    }

    fclose(fp); // Close file
    return 0;
}
