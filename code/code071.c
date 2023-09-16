#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Change this value to adjust the queue size

// Define the structure for a linear queue
struct Queue {
    int items[MAX_SIZE];
    int front, rear;
};

// Function to initialize the queue
void initialize(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue *queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
bool isFull(struct Queue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to enqueue (insert) an element into the queue
void enqueue(struct Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = item;
    printf("%d enqueued into Queue\n", item);
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return -1 as an indicator of an error
    }
    int dequeuedItem = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    printf("Element deleted\n");
    return dequeuedItem;
}

// Function to traverse and display the queue elements
void traverse(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->items[queue->rear]);
}

int main() {
    struct Queue queue;
    initialize(&queue);

    int choice, item;

    printf("Enter the size of Queue: ");
    int size;
    scanf("%d", &size);

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (queue.rear - queue.front + 1 < size) {
                    printf("Enter element: ");
                    scanf("%d", &item);
                    enqueue(&queue, item);
                } else {
                    printf("Queue is full. Cannot enqueue.\n");
                }
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
                if (isFull(&queue)) {
                    printf("Queue is full: True\n");
                } else {
                    printf("Queue is full: False\n");
                }
                break;
            case 5:
                traverse(&queue);
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
