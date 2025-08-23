#include <stdio.h>
#include <string.h>

int isSingleLineComment(char *line) {
    if (line[0] == '/' && line[1] == '/')
        return 1;
    return 0;
}

int isMultiLineCommentStart(char *line) {
    if (line[0] == '/' && line[1] == '*')
        return 1;
    return 0;
}

int isMultiLineCommentEnd(char *line) {
    int len = strlen(line);
    if (len >= 2 && line[len - 2] == '*' && line[len - 1] == '/')
        return 1;
    return 0;
}

int main() {
    char line[1000];
    int insideMultiline = 0;

    printf("Enter lines of C code (type END to stop):\n");

    while (fgets(line, sizeof(line), stdin)) {
        if (strncmp(line, "END", 3) == 0)
            break;

        line[strcspn(line, "\n")] = '\0';

        if (insideMultiline) {
            printf("Comment: %s\n", line);
            if (isMultiLineCommentEnd(line)) {
                insideMultiline = 0;
            }
        }
        else if (isSingleLineComment(line)) {
            printf("Comment: %s\n", line);
        }
        else if (isMultiLineCommentStart(line)) {
            printf("Comment: %s\n", line);
            if (!isMultiLineCommentEnd(line)) {
                insideMultiline = 1;
            }
        }
        else {
            printf("Not a comment: %s\n", line);
        }
    }
    return 0;
}
