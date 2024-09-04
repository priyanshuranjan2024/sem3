#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a specific position
void insertNode(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* temp = *head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to delete a node at a specific position
void deleteNode(Node** head, int position) {
    if (position == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    } else {
        Node* temp = *head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        free(nodeToDelete);
    }
}

// Function to count the number of nodes in the linked list
int countNodes(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to traverse the linked list
void traverseList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertNode(&head, data, i);
    }

    int choice;
    while (1) {
        printf("Menu:\n");
        printf("1. Insert a node at a specific position\n");
        printf("2. Delete a node at a specific position\n");
        printf("3. Count nodes\n");
        printf("4. Traverse the linked list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int data, position;
                printf("Enter data for new node: ");
                scanf("%d", &data);
                printf("Enter position for new node: ");
                scanf("%d", &position);
                insertNode(&head, data, position);
                break;
            }
            case 2: {
                int position;
                printf("Enter position for node to delete: ");
                scanf("%d", &position);
                deleteNode(&head, position);
                break;
            }
            case 3: {
                int count = countNodes(head);
                printf("Number of nodes: %d\n", count);
                break;
            }
            case 4: {
                traverseList(head);
                break;
            }
            case 5: {
                return 0;
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    }

    return 0;
}