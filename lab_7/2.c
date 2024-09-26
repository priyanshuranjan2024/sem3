#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Global front and rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to check if the queue is empty
int isEmpty() {
    return (front == NULL);
}

// Function to add an element to the queue (Enqueue)
void enqueue(int element) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;

    // If queue is empty, both front and rear are the same
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        // Add the new node at the rear and update the rear pointer
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d\n", element);
}

// Function to remove an element from the queue (Dequeue)
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        struct Node* temp = front;
        printf("Dequeued %d\n", front->data);
        front = front->next;

        // Free the old front node
        free(temp);

        // If the queue becomes empty after dequeue, reset rear to NULL
        if (front == NULL) {
            rear = NULL;
        }
    }
}

// Function to traverse and display the queue
void traverse() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        struct Node* temp = front;
        printf("Queue: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, element;

    // Menu-driven program
    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                enqueue(element);
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
                traverse();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option, please try again\n");
        }
    }

    return 0;
}
