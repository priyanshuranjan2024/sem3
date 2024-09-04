 #include <stdio.h>

// Function to find the number of nonzero elements
int countNonZeroElements(int matrix[][10], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

// Function to display the upper triangular matrix
void displayUpperTriangularMatrix(int matrix[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Function to display the elements just above and below the main diagonal
void displayDiagonalElements(int matrix[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j - 1 || i == j + 1) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int matrix[10][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    int choice;
    while (1) {
        printf("Menu:\n");
        printf("1. Find the number of nonzero elements\n");
        printf("2. Display upper triangular matrix\n");
        printf("3. Display elements just above and below the main diagonal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int count = countNonZeroElements(matrix, n);
                printf("Number of nonzero elements: %d\n", count);
                break;
            }
            case 2: {
                displayUpperTriangularMatrix(matrix, n);
                break;
            }
            case 3: {
                displayDiagonalElements(matrix, n);
                break;
            }
            case 4: {
                return 0;
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    }

    return 0;
}