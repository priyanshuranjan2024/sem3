#include <stdio.h>

// Function to convert a sparse matrix to 3-tuple format
void convertTo3Tuple(int matrix[][10], int n, int m, int tuple[][3]) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                tuple[k][0] = i;
                tuple[k][1] = j;
                tuple[k][2] = matrix[i][j];
                k++;
            }
        }
    }
}

// Function to print the 3-tuple format
void print3Tuple(int tuple[][3], int size) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
    }
}

int main() {
    int n, m;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    int matrix[10][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    int size = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                size++;
            }
        }
    }

    int tuple[size][3];
    convertTo3Tuple(matrix, n, m, tuple);

    printf("Sparse Matrix in 3-Tuple Format:\n");
    print3Tuple(tuple, size);

    return 0;
}