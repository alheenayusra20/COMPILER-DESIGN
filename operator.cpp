#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_ID_LEN 30

// Function to check if a character is an operator
int isOperator(char c) {
    char operators[] = "+-*/%=<>&|!^";
    for (int i = 0; operators[i]; i++) {
        if (c == operators[i])
            return 1;
    }
    return 0;
}

// Function to check if string is identifier
int isIdentifier(char *str) {
    if (!isalpha(str[0]) && str[0] != '_')
        return 0;
    for (int i = 1; str[i]; i++) {
        if (!isalnum(str[i]) && str[i] != '_')
            return 0;
    }
    return 1;
}

// Function to check if string is a number
int isNumber(char *str) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

int main() {
    char ch, buffer[100];
    int i;

    printf("Enter C program code (Ctrl+Z then Enter to stop on Windows, Ctrl+D on Linux):\n");

    while ((ch = getchar()) != EOF) {
        // Skip spaces, tabs, newlines
        if (ch == ' ' || ch == '\t' || ch == '\n')
            continue;

        // Skip comments
        if (ch == '/') {
            char next = getchar();
            if (next == '/') {
                // single line comment
                while ((ch = getchar()) != EOF && ch != '\n');
                continue;
            }
            else if (next == '*') {
                // multi line comment
                while ((ch = getchar()) != EOF) {
                    if (ch == '*') {
                        char next2 = getchar();
                        if (next2 == '/')
                            break;
                        else
                            ungetc(next2, stdin);
                    }
                }
                continue;
            } else {
                ungetc(next, stdin); // put back
            }
        }

        // Identifiers / Numbers
        if (isalnum(ch) || ch == '_') {
            i = 0;
            buffer[i++] = ch;
            while ((ch = getchar()) != EOF && (isalnum(ch) || ch == '_')) {
                if (i < MAX_ID_LEN)
                    buffer[i++] = ch; // restrict length
            }
            buffer[i] = '\0';
            ungetc(ch, stdin); // put back last read

            if (isNumber(buffer))
                printf("Constant: %s\n", buffer);
            else if (isIdentifier(buffer))
                printf("Identifier: %s\n", buffer);
        }
        // Operators
        else if (isOperator(ch)) {
            printf("Operator: %c\n", ch);
        }
        // Symbols (punctuation, brackets, etc.)
        else {
            printf("Symbol: %c\n", ch);
        }
    }

    return 0;
}
