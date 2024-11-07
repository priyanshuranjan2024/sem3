#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* newNode(int data, int priority) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

// Function to enqueue a node based on its priority
void enqueue(int data, int priority) {
    struct Node* temp = newNode(data, priority);

    if (head == NULL || priority < head->priority) {
        temp->next = head;
        head = temp;
    } else {
        struct Node* start = head;
        while (start->next != NULL && start->next->priority <= priority) {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
    printf("Element %d with priority %d enqueued successfully.\n", data, priority);
}

// Function to dequeue the highest priority element
void dequeue() {
    if (head == NULL) {
        printf("Priority queue is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Element %d with priority %d dequeued.\n", temp->data, temp->priority);
    free(temp);
}

// Function to display the elements of the priority queue
void traverse() {
    if (head == NULL) {
        printf("Priority queue is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Priority Queue: \n");
    while (temp != NULL) {
        printf("Data: %d, Priority: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

// Main menu-driven program
int main() {
    int choice, data, priority;
    while (1) {
        printf("\nPriority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(data, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
