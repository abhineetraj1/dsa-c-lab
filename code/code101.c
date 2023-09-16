#include <stdio.h>

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

    return 0;
}
