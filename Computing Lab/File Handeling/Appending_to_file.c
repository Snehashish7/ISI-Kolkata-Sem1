#include <stdio.h>

int main() {
    FILE *fp;

    // Open file for appending
    fp = fopen("file.txt", "a");

    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    // Append text to file
    fputs("Appended Text\n", fp);

    fclose(fp); // Close file
    return 0;
}
