// 1. String Manipulation Functions
// char *strcpy(char *dest, const char *src);

// Copies the string from src to dest.
// char *strncpy(char *dest, const char *src, size_t n);

// Copies up to n characters from src to dest.
// char *strcat(char *dest, const char *src);

// Appends the string src to the end of the string dest.
// char *strncat(char *dest, const char *src, size_t n);

// Appends up to n characters from src to dest.
// char *strdup(const char *s);

// Duplicates the string s by allocating new memory and copying the content.
// size_t strlen(const char *s);

// Returns the length of the string s (excluding the null-terminator).

//-----------------------------------------------------------------------------------------------------------------

// 2. String Comparison Functions
// int strcmp(const char *s1, const char *s2);
// Compares the two strings s1 and s2. Returns 0 if they are equal,
// a negative value if s1 is less than s2, and a positive value if s1 is greater than s2.

// int strncmp(const char *s1, const char *s2, size_t n);
// Compares up to n characters from the strings s1 and s2.

// int strcoll(const char *s1, const char *s2);
// Compares two strings according to the current locale.

// size_t strxfrm(char *dest, const char *src, size_t n);
// Transforms the string src into a form that is suitable for strcoll,
// storing the result in dest.