#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Queue structure for BFS
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Create a new queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if the queue is full
bool isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Check if the queue is empty
bool isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Enqueue an element into the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

void bfs(int startVertex, int n, int graph[][n]) {
    bool visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    struct Queue* queue = createQueue(n);
    visited[startVertex] = true;
    enqueue(queue, startVertex);

    printf("Breadth First Search: ");
    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < n; i++) {
            if (graph[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                enqueue(queue, i);
            }
        }
    }

    free(queue->array);
    free(queue);
}

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[n][n]; // Adjacency Matrix

    // Input adjacency matrix
    printf("Enter Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // BFS traversal
    int startVertex;
    printf("Enter start vertex: ");
    scanf("%d", &startVertex);

    bfs(startVertex, n, graph);
    printf("\n");

    return 0;
}
