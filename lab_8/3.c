#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Size of the Deque

int deque[SIZE];
int front = -1, rear = -1;

// Check if the deque is full
int isFull() {
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

// Check if the deque is empty
int isEmpty() {
    return front == -1;
}

// Insert at the rear (right) side
void insertAtRight(int element) {
    if (isFull()) {
        printf("Deque is full!\n");
        return;
    }

    if (front == -1) { // First insertion
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0; // Wrap around
    } else {
        rear++;
    }
    deque[rear] = element;
    printf("%d inserted at right.\n", element);
}

// Delete from the front (left) side
void deleteFromLeft() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }

    int deletedElement = deque[front];
    if (front == rear) { // Deque has only one element
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0; // Wrap around
    } else {
        front++;
    }
    printf("%d deleted from left.\n", deletedElement);
}

// Delete from the rear (right) side
void deleteFromRight() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }

    int deletedElement = deque[rear];
    if (front == rear) { // Deque has only one element
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1; // Wrap around
    } else {
        rear--;
    }
    printf("%d deleted from right.\n", deletedElement);
}

// Display the deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deque: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE; // Move circularly
    }
    printf("\n");
}

// Main function
int main() {
    int choice, element;

    while (1) {
        printf("\nInput Restricted Deque Menu\n");
        printf("1. Insert at right\n");
        printf("2. Delete from left\n");
        printf("3. Delete from right\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                insertAtRight(element);
                break;
            case 2:
                deleteFromLeft();
                break;
            case 3:
                deleteFromRight();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
