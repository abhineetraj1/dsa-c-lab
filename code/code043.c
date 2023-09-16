#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int coefficient;
    int degree;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int deg) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->coefficient = coeff;
    newNode->degree = deg;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term (coeff, deg) into the linked list
void insertTerm(struct Node** head, int coeff, int deg) {
    struct Node* newNode = createNode(coeff, deg);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to add two polynomial equations represented as linked lists
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL || poly2 != NULL) {
        int coeff = 0, deg = 0;
        if (poly1 != NULL) {
            coeff += poly1->coefficient;
            deg = poly1->degree;
            poly1 = poly1->next;
        }
        if (poly2 != NULL) {
            coeff += poly2->coefficient;
            deg = poly2->degree;
            poly2 = poly2->next;
        }
        if (coeff != 0) {
            insertTerm(&result, coeff, deg);
        }
    }
    return result;
}

// Function to display a polynomial equation
void displayPolynomial(struct Node* poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->degree);
        if (poly->next != NULL) {
            printf("+");
        }
        poly = poly->next;
    }
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;
    int maxDegree, coeff;

    // Input Polynomial-1
    printf("Polynomial-1:\n");
    printf("Enter the Maximum power of x: ");
    scanf("%d", &maxDegree);
    for (int i = maxDegree; i >= 0; i--) {
        printf("Enter the coefficient of degree %d: ", i);
        scanf("%d", &coeff);
        if (coeff != 0) {
            insertTerm(&poly1, coeff, i);
        }
    }

    // Input Polynomial-2
    printf("\nPolynomial-2:\n");
    printf("Enter the Maximum power of x: ");
    scanf("%d", &maxDegree);
    for (int i = maxDegree; i >= 0; i--) {
        printf("Enter the coefficient of degree %d: ", i);
        scanf("%d", &coeff);
        if (coeff != 0) {
            insertTerm(&poly2, coeff, i);
        }
    }

    // Add the polynomials
    sum = addPolynomials(poly1, poly2);

    // Display the sum polynomial
    printf("\nSum: ");
    displayPolynomial(sum);
    printf("\n");

    // Free memory
    while (sum != NULL) {
        struct Node* temp = sum;
        sum = sum->next;
        free(temp);
    }

    return 0;
}
