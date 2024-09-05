#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the single linked list
typedef struct Node {
    int row;
    int col;
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int row, int col, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the single linked list
void insertNode(Node** head, int row, int col, int data) {
    Node* newNode = createNode(row, col, data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the sparse matrix using the single linked list
void displayMatrix(Node* head, int numRows, int numCols) {
    int i, j;
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < numCols; j++) {
            Node* temp = head;
            int found = 0;
            while (temp != NULL) {
                if (temp->row == i && temp->col == j) {
                    printf("%d ", temp->data);
                    found = 1;
                    break;
                }
                temp = temp->next;
            }
            if (!found) {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    Node* head = NULL;
    int numRows, numCols, numElements;
    int i, row, col, data;

    // Get the number of rows, columns, and non-zero elements
    printf("Enter the number of rows: ");
    scanf("%d", &numRows);
    printf("Enter the number of columns: ");
    scanf("%d", &numCols);
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &numElements);

    // Create the sparse matrix using the single linked list
    for (i = 0; i < numElements; i++) {
        printf("Enter row, column, and data for element %d: ", i+1);
        scanf("%d %d %d", &row, &col, &data);
        insertNode(&head, row, col, data);
    }

    // Display the sparse matrix
    printf("Sparse matrix:\n");
    displayMatrix(head, numRows, numCols);

    return 0;
}