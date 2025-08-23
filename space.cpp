#include <stdio.h>

int main() {
    char ch;
    int whitespaces = 0, newlines = 0;

    printf("Enter text (press Ctrl+D / Ctrl+Z to stop):\n");

    while ((ch = getchar()) != EOF) {
        if (ch == ' ')
            whitespaces++;
        else if (ch == '\n')
            newlines++;
    }

    printf("\nNumber of whitespaces: %d\n", whitespaces);
    printf("Number of newlines: %d\n", newlines);

    return 0;
}
