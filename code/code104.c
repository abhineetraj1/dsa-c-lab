#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int in_degree[n], out_degree[n], total_degree[n];

    // Initialize the degree arrays to zeros
    for (i = 0; i < n; i++) {
        in_degree[i] = 0;
        out_degree[i] = 0;
        total_degree[i] = 0;
    }

    int graph[n][n]; // Adjacency Matrix

    // Initialize the Adjacency Matrix to all zeros
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            char response;
            if (i != j) {
                printf("Vertices %d & %d are Adjacent? (Y/N): ", i + 1, j + 1);
                scanf(" %c", &response);
                if (response == 'Y' || response == 'y') {
                    graph[i][j] = 1;
                    out_degree[i]++;
                    in_degree[j]++;
                    total_degree[i]++;
                    total_degree[j]++;
                }
            }
        }
    }

    // Display the degree of each vertex
    printf("Vertex In_Degree Out_Degree Total_Degree\n");
    for (i = 0; i < n; i++) {
        printf("%d %d %d %d\n", i + 1, in_degree[i], out_degree[i], total_degree[i]);
    }

    return 0;
}
