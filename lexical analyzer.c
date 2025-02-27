#include <stdio.h>
#include <ctype.h>
#include <string.h>

void lexicalAnalyzer(char *input) {
    int i = 0;
    while (input[i] != '\0') {
        if (isspace(input[i])) { i++; continue; }
        if (isdigit(input[i])) {
            printf("Number: ");
            while (isdigit(input[i])) putchar(input[i++]);
            printf("\n");
        } else if (isalpha(input[i])) {
            printf("Identifier: ");
            while (isalnum(input[i])) putchar(input[i++]);
            printf("\n");
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            printf("Operator: %c\n", input[i++]);
        } else {
            printf("Invalid character: %c\n", input[i++]);
        }
    }
}

int main() {
    char input[100];
    printf("Enter an expression: ");
    fgets(input, sizeof(input), stdin);
    lexicalAnalyzer(input);
    return 0;
}