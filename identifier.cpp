#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *keywords[] = {
    "auto","break","case","char","const","continue","default","do","double",
    "else","enum","extern","float","for","goto","if","int","long","register",
    "return","short","signed","sizeof","static","struct","switch","typedef",
    "union","unsigned","void","volatile","while"
};
int keywordCount = 32;

int isKeyword(char *str) {
    for (int i = 0; i < keywordCount; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isValidIdentifier(char *str) {
    if (!(isalpha(str[0]) || str[0] == '_'))
        return 0;

    for (int i = 1; str[i] != '\0'; i++) {
        if (!(isalnum(str[i]) || str[i] == '_'))
            return 0;
    }

    if (isKeyword(str))
        return 0;

    return 1;
}

int main() {
    char str[100];
    printf("Enter an identifier: ");
    scanf("%s", str);

    if (isValidIdentifier(str))
        printf("Valid Identifier: %s\n", str);
    else
        printf("Invalid Identifier: %s\n", str);

    return 0;
}
