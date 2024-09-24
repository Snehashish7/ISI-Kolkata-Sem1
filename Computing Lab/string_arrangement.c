// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int main(){
//     char *str = (char *)malloc(80*sizeof(char));
//     char **str_arr = (char **)malloc(800*sizeof(char *));
//     int c;
//     int i = 0;
//     while(EOF != (c = fgetc(stdin))){
//         if(strcmp(str," ") && strcmp(str,"\n")){
//             str_arr[i] = (char *)malloc(strlen(str)*sizeof(char));
//             str_arr[i] = str;
//             i++;
//             str = "";
//         }
//         else{
//             str += (char)c;
//         }
//     }
//     for(int j = 0; j< i; j++){
//         printf("%s",str_arr[j]);
//     }
//     return 0;
// }

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 80

// Function to process and print the properly formatted text
void formatText() {
    char word[81];  // Each word can be up to 80 characters, plus null terminator
    char line[MAX_LINE_LENGTH + 1];  // Line buffer (80 characters + null terminator)
    int line_length = 0;  // Current length of the line
    int word_length;
    
    line[0] = '\0';  // Initialize the line to an empty string

    // Read the input word by word
    while (scanf("%80s", word) != EOF) {
        word_length = strlen(word);

        // Check if the current word can fit in the current line
        if (line_length + word_length + 1 > MAX_LINE_LENGTH) {
            // Print the current line if adding the word exceeds the limit
            printf("%s\n", line);
            line[0] = '\0';  // Reset the line
            line_length = 0;  // Reset the line length
        }

        // Add a space before appending the word if it's not the first word in the line
        if (line_length > 0) {
            strcat(line, " ");
            line_length++;
        }

        // Append the word to the line
        strcat(line, word);
        line_length += word_length;
    }

    // Print the last line if there's anything in it
    if (line_length > 0) {
        printf("%s\n", line);
    }
}

int main() {
    formatText();
    return 0;
}
