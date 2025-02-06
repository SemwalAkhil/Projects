#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

void BFS(int adj[MAX][MAX], int vertices, int start) {
    bool visited[MAX] = {false};
    int queue[MAX], front = 0, rear = -1;

    visited[start] = true;
    queue[++rear] = start;

    while (front <= rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (adj[current][i] && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int adj[MAX][MAX] = {0};
    int vertices, edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // Uncomment for undirected graph
    }

    printf("BFS Traversal starting from vertex 0: ");
    BFS(adj, vertices, 0);
    return 0;
}
