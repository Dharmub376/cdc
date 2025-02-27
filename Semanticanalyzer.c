#include <stdio.h>
#include <string.h>

typedef struct { char name[50]; } Variable;
Variable symbolTable[100]; 
int symbolCount = 0;

void declareVariable(char *name) {
    for (int i = 0; i < symbolCount; i++) 
        if (!strcmp(symbolTable[i].name, name)) { 
            printf("Error: '%s' already declared.\n", name); return; 
        }
    strcpy(symbolTable[symbolCount++].name, name);
}

int isDeclared(char *name) {
    for (int i = 0; i < symbolCount; i++) 
        if (!strcmp(symbolTable[i].name, name)) return 1;
    return 0;
}

int semanticAnalyzer(char *expr) {
    char token[50]; int i = 0, j = 0;
    while (isalnum(expr[i])) token[j++] = expr[i++]; token[j] = '\0';

    if (!isDeclared(token)) { printf("Error: '%s' undeclared.\n", token); return 0; }

    while (isspace(expr[i])) i++;
    if (!strchr("+-*/", expr[i])) { printf("Error: Expected operator.\n"); return 0; }

    return 1;
}

int main() {
    declareVariable("x"); declareVariable("y");

    char input[100]; 
    printf("Enter an expression: "); fgets(input, sizeof(input), stdin);

    printf(semanticAnalyzer(input) ? "Passed.\n" : "Error.\n");
    return 0;
}