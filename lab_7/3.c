#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Global variables for the queue
int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull(int size) {
    return (front == (rear + 1) % size);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to add an element to the queue (Enqueue)
void enqueue(int element, int size) {
    if (isFull(size)) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = 0;  // Set front to 0 if it's the first element
        }
        rear = (rear + 1) % size;  // Circular increment of rear
        queue[rear] = element;
        printf("Enqueued %d\n", element);
    }
}

// Function to remove an element from the queue (Dequeue)
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Dequeued %d\n", queue[front]);
        if (front == rear) {  // Only one element in the queue
            front = rear = -1;  // Reset queue
        } else {
            front = (front + 1) % rear;  // Circular increment of front
        }
    }
}

// Function to traverse and display the queue
void traverse(int size) {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % size;
        }
        printf("%d\n", queue[rear]);  // Print the last element (rear)
    }
}

// Main function
int main() {
    int size, choice, element;

    // Get queue size from user
    printf("Enter the size of Queue: ");
    scanf("%d", &size);

    // Menu-driven program
    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                enqueue(element, size);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                if (isEmpty()) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 4:
                if (isFull(size)) {
                    printf("Queue is full\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;
            case 5:
                traverse(size);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option, please try again\n");
        }
    }

    return 0;
}
