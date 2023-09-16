#include <stdio.h>
#include <stdlib.h>

// Define the structure for a priority queue node
struct PriorityQueueNode {
    int data;
    int priority;
    struct PriorityQueueNode* next;
};

// Function to create a new priority queue node
struct PriorityQueueNode* createNode(int data, int priority) {
    struct PriorityQueueNode* newNode = (struct PriorityQueueNode*)malloc(sizeof(struct PriorityQueueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the priority queue based on priority
void enqueue(struct PriorityQueueNode** front, int data, int priority) {
    struct PriorityQueueNode* newNode = createNode(data, priority);

    if (*front == NULL || priority < (*front)->priority) {
        newNode->next = *front;
        *front = newNode;
    } else {
        struct PriorityQueueNode* current = *front;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    printf("Enqueued element %d with priority %d\n", data, priority);
}

// Function to dequeue (remove) the highest priority element from the priority queue
int dequeue(struct PriorityQueueNode** front) {
    if (*front == NULL) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return -1; // Return -1 as an indicator of an error
    }
    struct PriorityQueueNode* temp = *front;
    int dequeuedItem = temp->data;
    *front = (*front)->next;
    free(temp);
    return dequeuedItem;
}

// Function to display the priority queue elements
void display(struct PriorityQueueNode* front) {
    if (front == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }
    printf("Priority Queue:\n");
    printf("Priority\tItem\n");
    while (front != NULL) {
        printf("%d\t\t%d\n", front->priority, front->data);
        front = front->next;
    }
}

int main() {
    struct PriorityQueueNode* front = NULL;

    int choice, item, priority;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to be enqueued: ");
                scanf("%d", &item);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(&front, item, priority);
                break;
            case 2:
                item = dequeue(&front);
                if (item != -1) {
                    printf("Dequeued element: %d\n", item);
                }
                break;
            case 3:
                display(front);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid option. Please enter a valid choice.\n");
        }
    }

    return 0;
}
