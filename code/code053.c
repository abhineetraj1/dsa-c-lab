#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the sparse matrix linked list
struct Node {
    int row, col, value;
    struct Node* next;
};

// Function to create a new node for the sparse matrix
struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the sparse matrix linked list
void insertNode(struct Node** head, int row, int col, int value) {
    struct Node* newNode = createNode(row, col, value);

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

// Function to display the sparse matrix in 3-tuple format
void displaySparseMatrix(struct Node* head, int rows, int cols) {
    if (head == NULL) {
        printf("Sparse matrix is empty.\n");
        return;
    }

    printf("sparse matrix in 3-tuple format\n");
    printf("%d %d %d\n", rows, cols, 0); // Print the dimensions

    struct Node* current = head;
    while (current != NULL) {
        printf("%d %d %d\n", current->row, current->col, current->value);
        current = current->next;
    }
}

int main() {
    struct Node* head = NULL;
    int rows, cols;

    // Input the size of the sparse matrix
    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &rows, &cols);

    // Input the elements of the sparse matrix
    printf("Enter elements of sparse matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int element;
            scanf("%d", &element);
            if (element != 0) {
                insertNode(&head, i, j, element);
            }
        }
    }

    // Display the sparse matrix in 3-tuple format
    displaySparseMatrix(head, rows, cols);

    // Free memory
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
