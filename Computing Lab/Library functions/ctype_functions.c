// Character Classification Functions
// These functions check whether a given character falls into a specific class (like alphanumeric, digit, space, etc.). Each function takes an int (typically representing a character) and returns a non-zero value if the condition is true, and 0 otherwise.

// int isalnum(int c);

// Checks if c is an alphanumeric character (either a digit or a letter).
// Equivalent to: isalpha(c) || isdigit(c).
// int isalpha(int c);

// Checks if c is an alphabetic letter (uppercase or lowercase).
// int isdigit(int c);

// Checks if c is a decimal digit (0 to 9).
// int isxdigit(int c);

// Checks if c is a hexadecimal digit (0-9, a-f, or A-F).
// int islower(int c);

// Checks if c is a lowercase letter (a-z).
// int isupper(int c);

// Checks if c is an uppercase letter (A-Z).
// int isspace(int c);

// Checks if c is a whitespace character (e.g., space, tab, newline, vertical tab, form feed, or carriage return).
// int ispunct(int c);

// Checks if c is a punctuation character (neither a control nor alphanumeric character).
// int iscntrl(int c);

// Checks if c is a control character (like \n, \t, etc.).
// int isprint(int c);

// Checks if c is a printable character (any character except control characters).
// int isgraph(int c);

// Checks if c is any printable character except space.
// Character Conversion Functions
// These functions are used to convert characters to a specific case.

// int tolower(int c);

// Converts c to its lowercase equivalent if it is an uppercase letter. If c is not an uppercase letter, it is returned unchanged.
// int toupper(int c);

// Converts c to its uppercase equivalent if it is a lowercase letter. If c is not a lowercase letter, it is returned unchanged.
// Additional Functions
// int isascii(int c);

// Checks if c is an ASCII character (i.e., in the range 0-127).
// int toascii(int c);

// Converts c to a valid 7-bit ASCII character by clearing the high-order bits. This is typically used to ensure compatibility with 7-bit systems.
// Summary:
// Character classification functions are useful for determining the type of a character (e.g., isalpha, isdigit).
// Character conversion functions are used to transform characters between cases (tolower, toupper).
// All of these functions are designed to handle unsigned char values passed as int. Therefore, when passing char values directly, it's important to ensure they are cast correctly, especially if negative char values are involved.