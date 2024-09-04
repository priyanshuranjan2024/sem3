#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int val;
} sparse_matrix;


// Define a function to transpose the sparse matrix
void transpose_sparse_matrix(sparse_matrix *matrix, int num_elements, sparse_matrix **transposed_matrix) {
    // Check for invalid input
    if (matrix == NULL || num_elements < 0) {
        return;
    }

    // Allocate memory for the transposed matrix
    *transposed_matrix = (sparse_matrix *)malloc(num_elements * sizeof(sparse_matrix));
    if (*transposed_matrix == NULL) {
        // Handle memory allocation error
        return;
    }

    // Initialize the transposed matrix
    for (int i = 0; i < num_elements; i++) {
        (*transposed_matrix)[i].row = matrix[i].col;
        (*transposed_matrix)[i].col = matrix[i].row;
        (*transposed_matrix)[i].val = matrix[i].val;
    }
}

// Define a function to print the sparse matrix
void print_sparse_matrix(sparse_matrix *matrix, int num_elements) {
    printf("Matrix:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("(%d, %d, %d)\n", matrix[i].row, matrix[i].col, matrix[i].val);
    }
}

int main() {
    // Example sparse matrix
    sparse_matrix matrix[] = {
        {0, 0, 1},
        {0, 1, 2},
        {1, 0, 3},
        {1, 1, 4},
        {2, 0, 5},
        {2, 1, 6}
    };
    int num_elements = sizeof(matrix) / sizeof(sparse_matrix);

    // Transpose the sparse matrix
    sparse_matrix *transposed_matrix;
    transpose_sparse_matrix(matrix, num_elements, &transposed_matrix);

    // Print the transposed matrix
    print_sparse_matrix(transposed_matrix, num_elements);

    // Free the memory allocated for the transposed matrix
    free(transposed_matrix);

    return 0;
}