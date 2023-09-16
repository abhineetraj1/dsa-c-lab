#include <stdio.h>

int main() {
    int maxDegree;

    // Read the maximum degree of the polynomial
    printf("Enter maximum degree of x: ");
    scanf("%d", &maxDegree);

    int poly1[maxDegree + 1]; // Array to store coefficients of Polynomial-1
    int poly2[maxDegree + 1]; // Array to store coefficients of Polynomial-2

    // Input coefficients of Polynomial-1
    printf("Enter Polynomial-1 from lowest degree to highest degree: ");
    for (int i = 0; i <= maxDegree; i++) {
        scanf("%d", &poly1[i]);
    }

    // Input coefficients of Polynomial-2
    printf("Enter Polynomial-2: ");
    for (int i = 0; i <= maxDegree; i++) {
        scanf("%d", &poly2[i]);
    }

    // Create an array to store the coefficients of the resultant polynomial
    int result[maxDegree + 1];

    // Perform addition of the polynomials
    for (int i = 0; i <= maxDegree; i++) {
        result[i] = poly1[i] + poly2[i];
    }

    // Display the sum polynomial
    printf("Resultant Polynomial: ");
    for (int i = maxDegree; i >= 0; i--) {
        if (result[i] != 0) {
            if (i == 0) {
                printf("%d", result[i]);
            } else if (i == 1) {
                printf("%dx+", result[i]);
            } else {
                printf("%dx^%d+", result[i], i);
            }
        }
    }
    printf("\n");

    return 0;
}
