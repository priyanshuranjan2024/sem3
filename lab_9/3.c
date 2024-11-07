#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to find the length of a linked list
int getLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find the intersection node
struct Node* getIntersectionNode(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    
    // Align both pointers to the same starting position from the end
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    if (len1 > len2) {
        int diff = len1 - len2;
        for (int i = 0; i < diff; i++) {
            ptr1 = ptr1->next;
        }
    } else if (len2 > len1) {
        int diff = len2 - len1;
        for (int i = 0; i < diff; i++) {
            ptr2 = ptr2->next;
        }
    }

    // Traverse both lists and find the intersection point
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // If no intersection point is found
    return NULL;
}

// Main function to test the code
int main() {
    // Creating two linked lists
    struct Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);

    struct Node* head2 = newNode(9);
    head2->next = newNode(8);
    head2->next->next = head1->next->next; // Intersection at node with data 3

    struct Node* intersectionNode = getIntersectionNode(head1, head2);
    if (intersectionNode != NULL) {
        printf("The intersection point is at node with data = %d\n", intersectionNode->data);
    } else {
        printf("The two lists do not intersect.\n");
    }

    return 0;
}
