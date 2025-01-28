#include <stdio.h>
#define N 100
int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';   /* terminates string */
    return i;        /* number of characters stored */
}

int isDelimiter(char ch, const char* delimiters) {
    while (*delimiters) {
        if (*delimiters == ch) {
            return 1;  // Character is a delimiter
        }
        delimiters++;
    }
    return 0;  // Character is not a delimiter
}

int CutString(char* substr[], char* str, char* cut) {
    int index = 0;
    int inSubstring = 0;  // Flag to indicate whether the current character is part of a substring

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isDelimiter(str[i], cut)) {
            if (!inSubstring) {
                substr[index++] = &str[i];
                inSubstring = 1;  // Set flag to indicate that we are now inside a substring
            }
        } else {
            str[i] = '\0';  // Replace delimiter with null terminator to terminate the current substring
            inSubstring = 0;  // Reset flag since we are now outside a substring
        }
    }

    return index;
}

int main() {
    char str[N];
    char cut[N];
    char* substr[N];

    printf("Enter a string: ");
    read_line(str, N);

    printf("Enter a delimiter: ");
    read_line(cut, N);

    int n = CutString(substr, str, cut);

    printf("Substrings:\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", substr[i]);

    return 0;
}
