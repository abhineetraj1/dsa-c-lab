#include <stdio.h>

void dfs(int vertex, int n, int graph[][n], int visited[]) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(i, n, graph, visited);
        }
    }
}

int main() {
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[n][n]; // Adjacency Matrix

    // Initialize the Adjacency Matrix to all zeros
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            char response;
            printf("Vertices %d & %d are Adjacent? (Y/N): ", i + 1, j + 1);
            scanf(" %c", &response);
            if (response == 'Y' || response == 'y') {
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }

    // Calculate and display the degree of each vertex
    printf("Vertex Degree\n");
    for (i = 0; i < n; i++) {
        int degree = 0;
        for (j = 0; j < n; j++) {
            degree += graph[i][j];
        }
        printf("%d %d\n", i + 1, degree);
    }

    // DFS traversal
    int startVertex;
    printf("Enter start vertex: ");
    scanf("%d", &startVertex);

    int visited[n];
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Depth First Search: ");
    dfs(startVertex, n, graph, visited);
    printf("\n");

    return 0;
}
