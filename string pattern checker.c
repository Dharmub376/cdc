#include <stdio.h>
#include <string.h>

void checkPattern(char *str) {
    if (strcmp(str, "a") == 0) {
        printf("The string matches the pattern 'a'.\n");
    } 
    else if (str[strlen(str) - 1] == 'b') {
        int valid = 1;
        for (int i = 0; i < strlen(str) - 1; i++) {
            if (str[i] != 'a') {
                valid = 0;
                break;
            }
        }
        if (valid) {
            printf("The string matches the pattern 'a*b'.\n");
            return;
        }
    } 
    else if (strcmp(str, "abb") == 0) {
        printf("The string matches the pattern 'abb'.\n");
    } 
    else {
        printf("The string does not match any pattern.\n");
    }
}

int main() {
    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    checkPattern(input);
    return 0;
}