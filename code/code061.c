#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10 // Change this value to adjust the stack size

// Define a stack structure
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
bool isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(struct Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->items[++(stack->top)] = item;
    printf("%d pushed into Stack\n", item);
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return -1 as an indicator of an error
    }
    int poppedItem = stack->items[(stack->top)--];
    printf("%d deleted from Stack\n", poppedItem);
    return poppedItem;
}

// Function to display the stack elements
void display(struct Stack *stack) {
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initialize(&stack);

    int choice, item;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to be pushed into the stack: ");
                scanf("%d", &item);
                push(&stack, item);
                break;
            case 2:
                item = pop(&stack);
                if (item != -1) {
                    printf("%d deleted from Stack\n", item);
                }
                break;
            case 3:
                if (isEmpty(&stack)) {
                    printf("Stack empty: True\n");
                } else {
                    printf("Stack empty: False\n");
                }
                break;
            case 4:
                if (isFull(&stack)) {
                    printf("Stack full: True\n");
                } else {
                    printf("Stack full: False\n");
                }
                break;
            case 5:
                display(&stack);
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid option. Please enter a valid choice.\n");
        }
    }

    return 0;
}
