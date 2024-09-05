#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; // circular link
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head; // circular link
    }
}

// Function to display the elements of the circular linked list
void displayList(Node* head) {
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node* head = NULL;
    int data;

    // Create a circular linked list with 5 nodes
    for (int i = 0; i < 5; i++) {
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &data);
        insertNode(&head, data);
    }

    // Display the elements of the circular linked list
    printf("Elements of the circular linked list: ");
    displayList(head);

    return 0;
}