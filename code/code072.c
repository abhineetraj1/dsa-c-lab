#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a queue node
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

// Define the structure for the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize the queue
void initialize(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue (insert) an element into the queue
void enqueue(struct Queue* queue, int item) {
    struct Node* newNode = createNode(item);
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%d enqueued into Queue\n", item);
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return -1 as an indicator of an error
    }
    int dequeuedItem = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    printf("Element deleted\n");
    return dequeuedItem;
}

// Function to traverse and display the queue elements
void traverse(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    initialize(&queue);

    int choice, item;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to be pushed into the queue: ");
                scanf("%d", &item);
                enqueue(&queue, item);
                break;
            case 2:
                item = dequeue(&queue);
                if (item != -1) {
                    printf("%d deleted from Queue\n", item);
                }
                break;
            case 3:
                if (isEmpty(&queue)) {
                    printf("Queue is empty: True\n");
                } else {
                    printf("Queue is empty: False\n");
                }
                break;
            case 4:
                traverse(&queue);
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
