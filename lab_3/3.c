#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coefficient, int exponent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: unable to allocate memory\n");
        return NULL;
    }
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of the linked list
void addNode(Node** head, int coefficient, int exponent) {
    Node* newNode = createNode(coefficient, exponent);
    if (newNode == NULL) {
        return;
    }
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

// Function to print the polynomial equation
void printPolynomial(Node* head) {
    while (head != NULL) {
        printf("%dx^%d", head->coefficient, head->exponent);
        if (head->next != NULL) {
            printf(" + ");
        }
        head = head->next;
    }
    printf("\n");
}

// Function to add two polynomial equations
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* temp1 = poly1;
    Node* temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exponent > temp2->exponent) {
            addNode(&result, temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        } else if (temp1->exponent < temp2->exponent) {
            addNode(&result, temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        } else {
            int coefficient = temp1->coefficient + temp2->coefficient;
            addNode(&result, coefficient, temp1->exponent);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL) {
        addNode(&result, temp1->coefficient, temp1->exponent);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        addNode(&result, temp2->coefficient, temp2->exponent);
        temp2 = temp2->next;
    }

    return result;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    printf("Enter the first polynomial equation:\n");
    int n1;
    printf("Enter the number of terms: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        int coefficient, exponent;
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        addNode(&poly1, coefficient, exponent);
    }

    printf("Enter the second polynomial equation:\n");
    int n2;
    printf("Enter the number of terms: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        int coefficient, exponent;
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        addNode(&poly2, coefficient, exponent);
    }

    printf("Polynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);

    Node* result = addPolynomials(poly1, poly2);
    printf("Result: ");
    printPolynomial(result);

    return 0;
}