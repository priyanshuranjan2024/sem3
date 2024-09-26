#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the stack

int stack[MAX];
int top = -1;

// Stack operations
int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

void push(int item) {
    if (isFull()) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = item;
}

int pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to insert an element at the bottom of the stack
void insertAtBottom(int item) {
    if (isEmpty()) {
        push(item);
    } else {
        // Recursively pop all items and hold them in function call stack
        int temp = pop();
        insertAtBottom(item);
        // Push the held items back after inserting at the bottom
        push(temp);
    }
}

// Function to reverse the stack using recursion
void reverseStack() {
    if (!isEmpty()) {
        // Hold all items in function call stack until we reach the end
        int temp = pop();
        reverseStack();
        // Insert each popped item at the bottom of the reversed stack
        insertAtBottom(temp);
    }
}

// Function to print the stack
void printStack() {
    if (isEmpty()) {
        return;
    }
    int temp = pop();
    printf("%d ", temp);
    printStack();
    push(temp); // Restore stack after printing
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    printf("Original Stack: ");
    printStack();
    printf("\n");

    reverseStack();

    printf("Reversed Stack: ");
    printStack();
    printf("\n");

    return 0;
}
