#include <stdio.h>

// Define the structure for complex numbers
struct Complex {
    float real;
    float imaginary;
};

// Function to add two complex numbers (call by value)
struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;
    return result;
}

// Function to multiply two complex numbers (call by address)
void multiplyComplex(struct Complex *num1, struct Complex *num2) {
    float real = (num1->real * num2->real) - (num1->imaginary * num2->imaginary);
    float imaginary = (num1->real * num2->imaginary) + (num1->imaginary * num2->real);
    num1->real = real;
    num1->imaginary = imaginary;
}

int main() {
    struct Complex num1, num2, result;
    int choice;

    // Input complex numbers
    printf("Enter complex number 1 (real imaginary): ");
    scanf("%f %f", &num1.real, &num1.imaginary);

    printf("Enter complex number 2 (real imaginary): ");
    scanf("%f %f", &num2.real, &num2.imaginary);

    // Menu-driven loop
    do {
        printf("\nMENU\n");
        printf("1. Addition\n");
        printf("2. Multiplication\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                result = addComplex(num1, num2);
                printf("Sum=%.2f+%.2fi\n", result.real, result.imaginary);
                break;

            case 2:
                multiplyComplex(&num1, &num2);
                printf("Product=%.2f+%.2fi\n", num1.real, num1.imaginary);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
