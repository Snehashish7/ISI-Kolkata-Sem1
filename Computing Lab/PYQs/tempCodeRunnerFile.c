#include <stdio.h>
#include <string.h>

int main() {
    char line[1000];  // Buffer to hold each line of input

    // Read input line by line
    while (fgets(line, sizeof(line), stdin) != NULL) {
        // Process each line
        // Here, you can tokenize the line or handle formatting

        // For now, we just print the line (after stripping any extra newlines or spaces)
        printf("%s", line);
    }

    return 0;
}
