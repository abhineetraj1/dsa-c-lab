#include <stdio.h>

// Function to compare two numbers by address
void compareNumbers(int *num1, int *num2) {
    if (*num1 > *num2) {
        printf("%d is greater than %d\n", *num1, *num2);
    } else if (*num1 < *num2) {
        printf("%d is smaller than %d\n", *num1, *num2);
    } else {
        printf("Both numbers are same\n");
    }
}

int main() {
    int num1, num2;

    // Read two numbers from the user
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Call the compareNumbers function with addresses of num1 and num2
    compareNumbers(&num1, &num2);

    return 0;
}
