#include <stdio.h>

int main() {
    int rows, cols;

    // Read the size of the sparse matrix
    printf("Enter size of the sparse matrix (rows cols): ");
    scanf("%d %d", &rows, &cols);

    int matrix[100][100];

    // Input elements of the sparse matrix
    printf("Enter elements of sparse matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Find the number of nonzero elements
    int nonzeroCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                nonzeroCount++;
            }
        }
    }

    // Create a 3-tuple array to store the sparse matrix
    int sparseMatrix[nonzeroCount + 1][3];
    sparseMatrix[0][0] = rows;
    sparseMatrix[0][1] = cols;
    sparseMatrix[0][2] = nonzeroCount;

    int k = 1; // Index for the sparseMatrix array

    // Populate the sparseMatrix with nonzero elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[k][0] = i;
                sparseMatrix[k][1] = j;
                sparseMatrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    // Display the sparse matrix in 3-tuple format
    printf("Sparse matrix in 3-tuple format:\n");
    for (int i = 0; i <= nonzeroCount; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", sparseMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
