#include <stdio.h>
#include <ctype.h>
#include <string.h>

int oncelik(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixToPostfix(char* infix) {
    char stack[100];
    int top = -1;
    
    printf("Postfix Ifade: ");

    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            printf("%c", c);
        } 
        else if (c == '(') {
            stack[++top] = c;
        } 
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", stack[top--]);
            }
            top--; 
        } 
        else {
            while (top != -1 && oncelik(stack[top]) >= oncelik(c)) {
                printf("%c", stack[top--]);
            }
            stack[++top] = c;
        }
    }

    while (top != -1) {
        printf("%c", stack[top--]);
    }
    printf("\n");
}

int main() {
    char ifade[] = "a+b*(c^d-e)";
    printf("Infix: %s\n", ifade);
    infixToPostfix(ifade);
    return 0;
}
