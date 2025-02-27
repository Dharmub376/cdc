#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isValidIdentifier(char *str) {
    if (str[0] == '\0') return 0;
    if (!(isalpha(str[0]) || str[0] == '_')) return 0;
    for (int i = 1; i < strlen(str); i++) {
        if (!(isalnum(str[i]) || str[i] == '_')) return 0;
    }
    return 1;
}

int main() {
    char identifier[100];
    printf("Enter an identifier: ");
    fgets(identifier, sizeof(identifier), stdin);
    identifier[strcspn(identifier, "\n")] = 0;
    if (isValidIdentifier(identifier)) printf("%s' is a valid identifier.\n", identifier);
    else printf("%s' is not a valid identifier.\n", identifier);
    return 0;
}