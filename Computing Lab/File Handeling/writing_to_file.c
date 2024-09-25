#include <stdio.h>

int main() {
    FILE *fp;

    // Open file for writing
    fp = fopen("file.txt", "w");

    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    // Write to file
    fputs("Hello, File Handling!\n", fp);

    fclose(fp); // Close file
    return 0;
}
