#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char c) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isValid(char* s) {
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            push(')');
        } else if (s[i] == '{') {
            push('}');
        } else if (s[i] == '[') {
            push(']');
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (top == -1 || stack[top] != s[i]) {
                return 0;
            }
            pop();
        }
    }
    return top == -1;
}

int main() {
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);
    if (isValid(s)) {
        printf("Valid string\n");
    } else {
        printf("Invalid string\n");
    }
    return 0;
}