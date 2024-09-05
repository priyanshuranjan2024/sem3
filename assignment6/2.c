#include <stdio.h>

void insertAtBottom(int x, int *stack, int *top) {
    if (*top == -1) {
        *stack = x;
        (*top)++;
    } else {
        int temp = *stack;
        (*top)--;
        insertAtBottom(x, stack, top);
        *stack = temp;
        (*top)++;
    }
}

void reverseStack(int *stack, int *top) {
    if (*top != -1) {
        int x = *stack;
        (*top)--;
        reverseStack(stack, top);
        insertAtBottom(x, stack, top);
    }
}

void printStack(int *stack, int top) {
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int stack[5] = {1, 2, 3, 4, 5};
    int top = 4;

    printf("Original stack: ");
    printStack(stack, top);

    reverseStack(stack, &top);

    printf("Reversed stack: ");
    printStack(stack, top);

    return 0;
}