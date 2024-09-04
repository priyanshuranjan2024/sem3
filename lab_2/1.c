#include <stdio.h>

// Function to insert an element at a specific position
void insertElement(int arr[], int *n, int pos, int element) {
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    (*n)++;
}

// Function to delete an element from a specific position
void deleteElement(int arr[], int *n, int pos) {
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Function to traverse the array
void traverseArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int choice;
    while (1) {
        printf("Menu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Linear search\n");
        printf("4. Traverse the array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int pos, element;
                printf("Enter the position: ");
                scanf("%d", &pos);
                printf("Enter the element: ");
                scanf("%d", &element);
                insertElement(arr, &n, pos, element);
                break;
            }
            case 2: {
                int pos;
                printf("Enter the position: ");
                scanf("%d", &pos);
                deleteElement(arr, &n, pos);
                break;
            }
            case 3: {
                int key;
                printf("Enter the key: ");
                scanf("%d", &key);
                int result = linearSearch(arr, n, key);
                if (result != -1) {
                    printf("Element found at position %d\n", result);
                } else {
                    printf("Element not found\n");
                }
                break;
            }
            case 4: {
                traverseArray(arr, n);
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