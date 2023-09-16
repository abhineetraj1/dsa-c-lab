#include <stdio.h>

int main() {
    int rows1, cols1, nonzeroCount1;
    int rows2, cols2, nonzeroCount2;

    // Read the size and number of nonzero elements for matrix 1
    printf("Enter sparse matrix-1 in 3-tuple format:\n");
    scanf("%d %d %d", &rows1, &cols1, &nonzeroCount1);

    // Create 3-tuple array for matrix 1
    int matrix1[nonzeroCount1][3];

    // Input the 3-tuple data for matrix 1
    printf("Enter the 3-tuple data for matrix 1:\n");
    for (int i = 0; i < nonzeroCount1; i++) {
        scanf("%d %d %d", &matrix1[i][0], &matrix1[i][1], &matrix1[i][2]);
    }

    // Read the size and number of nonzero elements for matrix 2
    printf("Enter sparse matrix-2 in 3-tuple format:\n");
    scanf("%d %d %d", &rows2, &cols2, &nonzeroCount2);

    // Create 3-tuple array for matrix 2
    int matrix2[nonzeroCount2][3];

    // Input the 3-tuple data for matrix 2
    printf("Enter the 3-tuple data for matrix 2:\n");
    for (int i = 0; i < nonzeroCount2; i++) {
        scanf("%d %d %d", &matrix2[i][0], &matrix2[i][1], &matrix2[i][2]);
    }

    // Check if matrix dimensions are compatible for addition
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrix dimensions are not compatible for addition.\n");
        return 1;
    }

    // Calculate the size of the result matrix
    int nonzeroCountResult = nonzeroCount1 + nonzeroCount2;
    
    // Create a result 3-tuple array
    int resultMatrix[nonzeroCountResult][3];

    // Perform matrix addition and store the result in the result 3-tuple array
    int i = 0, j = 0, k = 0;
    while (i < nonzeroCount1 && j < nonzeroCount2) {
        if (matrix1[i][0] < matrix2[j][0] || (matrix1[i][0] == matrix2[j][0] && matrix1[i][1] < matrix2[j][1])) {
            resultMatrix[k][0] = matrix1[i][0];
            resultMatrix[k][1] = matrix1[i][1];
            resultMatrix[k][2] = matrix1[i][2];
            i++;
        } else if (matrix1[i][0] > matrix2[j][0] || (matrix1[i][0] == matrix2[j][0] && matrix1[i][1] > matrix2[j][1])) {
            resultMatrix[k][0] = matrix2[j][0];
            resultMatrix[k][1] = matrix2[j][1];
            resultMatrix[k][2] = matrix2[j][2];
            j++;
        } else {
            resultMatrix[k][0] = matrix1[i][0];
            resultMatrix[k][1] = matrix1[i][1];
            resultMatrix[k][2] = matrix1[i][2] + matrix2[j][2];
            i++;
            j++;
        }
        k++;
    }

    // Copy any remaining elements from matrix 1
    while (i < nonzeroCount1) {
        resultMatrix[k][0] = matrix1[i][0];
        resultMatrix[k][1] = matrix1[i][1];
        resultMatrix[k][2] = matrix1[i][2];
        i++;
        k++;
    }

    // Copy any remaining elements from matrix 2
    while (j < nonzeroCount2) {
        resultMatrix[k][0] = matrix2[j][0];
        resultMatrix[k][1] = matrix2[j][1];
        resultMatrix[k][2] = matrix2[j][2];
        j++;
        k++;
    }

    // Display the result in 3-tuple format
    printf("Resultant Matrix in 3-tuple format:\n");
    printf("%d %d %d\n", rows1, cols1, k);
    for (int i = 0; i < k; i++) {
        printf("%d %d %d\n", resultMatrix[i][0], resultMatrix[i][1], resultMatrix[i][2]);
    }

    return 0;
}
