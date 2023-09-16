#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a stack node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed into Stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return -1 as an indicator of an error
    }
    struct Node* temp = *top;
    int poppedItem = temp->data;
    *top = (*top)->next;
    free(temp);
    printf("%d deleted from Stack\n", poppedItem);
    return poppedItem;
}

// Function to check if the stack is empty
bool isEmpty(struct Node* top) {
    return (top == NULL);
}

// Function to display the stack elements
void display(struct Node* top) {
    printf("Stack: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;
    int choice, item;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to be pushed into the stack: ");
                scanf("%d", &item);
                push(&top, item);
                break;
            case 2:
                item = pop(&top);
                if (item != -1) {
                    printf("%d deleted from Stack\n", item);
                }
                break;
            case 3:
                if (isEmpty(top)) {
                    printf("Stack empty: True\n");
                } else {
                    printf("Stack empty: False\n");
                }
                break;
            case 4:
                display(top);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid option. Please enter a valid choice.\n");
        }
    }

    return 0;
}
