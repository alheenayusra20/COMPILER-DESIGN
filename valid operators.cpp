#include <stdio.h>

int main() {
    char ch;

    printf("Enter operators (type q to quit):\n");

    while (1) {
        scanf(" %c", &ch);

        if (ch == 'q') {
            break;
        }

        switch (ch) {
            case '+':
                printf("Valid Operator: PLUS (+)\n");
                break;
            case '-':
                printf("Valid Operator: MINUS (-)\n");
                break;
            case '*':
                printf("Valid Operator: MULTIPLY (*)\n");
                break;
            case '/':
                printf("Valid Operator: DIVIDE (/)\n");
                break;
            default:
                printf("Invalid Operator or Character: %c\n", ch);
        }
    }

    return 0;
}
