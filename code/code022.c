#include <stdio.h>

// Function to find the number of nonzero elements in a matrix
int countNonZero(int matrix[][100], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

// Function to display the upper triangular matrix
void displayUpperTriangular(int matrix[][100], int size) {
    printf("Upper triangular matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j >= i) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Function to display elements just above and below the main diagonal
void displayAboveBelowDiagonal(int matrix[][100], int size) {
    printf("Elements above and below the main diagonal:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j == i - 1 || j == i + 1) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int size;
    
    // Read the size of the square matrix
    printf("Enter size of the square matrix: ");
    scanf("%d", &size);

    int matrix[100][100];

    // Input elements of the matrix
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Find and print the number of nonzero elements
    int nonZeroCount = countNonZero(matrix, size);
    printf("Nonzero elements: %d\n", nonZeroCount);

    // Display the upper triangular matrix
    displayUpperTriangular(matrix, size);

    // Display elements just above and below the main diagonal
    displayAboveBelowDiagonal(matrix, size);

    return 0;
}
