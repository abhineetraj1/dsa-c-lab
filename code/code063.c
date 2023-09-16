#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the structure for a stack node
struct Node {
    char data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(char data) {
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
void push(struct Node** top, char data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
char pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return '\0';
    }
    struct Node* temp = *top;
    char poppedItem = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedItem;
}

// Function to check if the stack is empty
bool isEmpty(struct Node* top) {
    return (top == NULL);
}

// Function to return the precedence of an operator
int precedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    } else if (operator == '^') {
        return 3;
    }
    return 0;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    struct Node* stack = NULL;
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char token = infix[i];

        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(&stack, token);
        } else if (token == ')') {
            while (!isEmpty(stack) && stack->data != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(stack) && stack->data != '(') {
                printf("Invalid expression.\n");
                exit(1);
            } else {
                pop(&stack); // Pop '('
            }
        } else {
            while (!isEmpty(stack) && precedence(token) <= precedence(stack->data)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        }

        i++;
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[100], postfix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix: %s\n", postfix);

    return 0;
}
