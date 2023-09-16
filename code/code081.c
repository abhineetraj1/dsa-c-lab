#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Change this value to adjust the deque size

// Define the structure for a deque
struct Deque {
    int items[MAX_SIZE];
    int front, rear;
};

// Function to initialize the deque
void initialize(struct Deque* deque) {
    deque->front = -1;
    deque->rear = -1;
}

// Function to check if the deque is empty
bool isEmpty(struct Deque* deque) {
    return (deque->front == -1);
}

// Function to check if the deque is full
bool isFull(struct Deque* deque) {
    return ((deque->rear + 1) % MAX_SIZE == deque->front);
}

// Function to insert an element at the right end of the deque
void insertRight(struct Deque* deque, int item) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }
    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }
    deque->items[deque->rear] = item;
    printf("Element %d inserted at the right end of Deque\n", item);
}

// Function to delete an element from the left end of the deque
int deleteLeft(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete.\n");
        return -1; // Return -1 as an indicator of an error
    }
    int deletedItem = deque->items[deque->front];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }
    printf("%d deleted from the left end of Deque\n", deletedItem);
    return deletedItem;
}

// Function to delete an element from the right end of the deque
int deleteRight(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete.\n");
        return -1; // Return -1 as an indicator of an error
    }
    int deletedItem = deque->items[deque->rear];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    printf("%d deleted from the right end of Deque\n", deletedItem);
    return deletedItem;
}

// Function to display the deque elements
void display(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque: ");
    int i = deque->front;
    while (true) {
        printf("%d ", deque->items[i]);
        if (i == deque->rear) {
            break;
        }
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    struct Deque deque;
    initialize(&deque);

    int choice, item;

    while (1) {
        printf("\nDeque Menu\n");
        printf("1. Insert at right\n");
        printf("2. Delete from left\n");
        printf("3. Delete from right\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to be inserted at the right end: ");
                scanf("%d", &item);
                insertRight(&deque, item);
                break;
            case 2:
                item = deleteLeft(&deque);
                if (item != -1) {
                    printf("%d deleted\n", item);
                }
                break;
            case 3:
                item = deleteRight(&deque);
                if (item != -1) {
                    printf("%d deleted\n", item);
                }
                break;
            case 4:
                display(&deque);
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
