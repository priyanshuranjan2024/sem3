#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the double linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert an element at a specific position
void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (*head == NULL || position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
    } else {
        Node* temp = *head;
        int i = 0;
        while (temp != NULL && i < position - 1) {
            temp = temp->next;
            i++;
        }
        if (temp != NULL) {
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }
    }
}

// Function to delete an element from a specific position
void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    int i = 0;
    while (temp != NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }
    if (temp != NULL) {
        Node* nodeToDelete = temp->next;
        if (nodeToDelete != NULL) {
            temp->next = nodeToDelete->next;
            if (nodeToDelete->next != NULL) {
                nodeToDelete->next->prev = temp;
            }
            free(nodeToDelete);
        }
    }
}

// Function to traverse the list
void traverseList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("1. Insert an element at a specific position\n");
        printf("2. Delete an element from a specific position\n");
        printf("3. Traverse the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 2:
                printf("Enter the position: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 3:
                traverseList(head);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}