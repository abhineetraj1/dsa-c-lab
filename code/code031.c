#include <stdio.h>

int main() {
    int rows, cols, nonzeroCount;

    // Read the size and number of nonzero elements in the sparse matrix
    printf("Enter sparse matrix in 3-tuple format:\n");
    scanf("%d %d %d", &rows, &cols, &nonzeroCount);

    // Create a 3-tuple array to store the sparse matrix
    int sparseMatrix[nonzeroCount][3];

    // Input the sparse matrix data
    printf("Enter the 3-tuple data:\n");
    for (int i = 0; i < nonzeroCount; i++) {
        scanf("%d %d %d", &sparseMatrix[i][0], &sparseMatrix[i][1], &sparseMatrix[i][2]);
    }

    // Create a 3-tuple array to store the transpose of the sparse matrix
    int transposeMatrix[nonzeroCount][3];

    // Initialize a count array to store the number of elements in each column
    int colCount[cols];
    for (int i = 0; i < cols; i++) {
        colCount[i] = 0;
    }

    // Calculate the number of elements in each column
    for (int i = 0; i < nonzeroCount; i++) {
        colCount[sparseMatrix[i][1]]++;
    }

    // Calculate the starting position of each column in the transpose matrix
    int startPosition[cols];
    startPosition[0] = 0;
    for (int i = 1; i < cols; i++) {
        startPosition[i] = startPosition[i - 1] + colCount[i - 1];
    }

    // Populate the transpose matrix
    for (int i = 0; i < nonzeroCount; i++) {
        int col = sparseMatrix[i][1];
        int pos = startPosition[col];
        transposeMatrix[pos][0] = sparseMatrix[i][1];
        transposeMatrix[pos][1] = sparseMatrix[i][0];
        transposeMatrix[pos][2] = sparseMatrix[i][2];
        startPosition[col]++;
    }

    // Display the transpose of the sparse matrix
    printf("Transpose of sparse matrix:\n");
    printf("R C Element\n");
    for (int i = 0; i < nonzeroCount; i++) {
        printf("%d %d %d\n", transposeMatrix[i][0], transposeMatrix[i][1], transposeMatrix[i][2]);
    }

    return 0;
}
