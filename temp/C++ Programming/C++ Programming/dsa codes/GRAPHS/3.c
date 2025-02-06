#include <stdio.h>
#include <stdbool.h>

#define MAX 10

void DFS(int adj[MAX][MAX], int vertices, int start, bool visited[]) {
    visited[start] = true;
    printf("%d ", start);

    for (int i = 0; i < vertices; i++) {
        if (adj[start][i] && !visited[i]) {
            DFS(adj, vertices, i, visited);
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

    bool visited[MAX] = {false};
    printf("DFS Traversal starting from vertex 0: ");
    DFS(adj, vertices, 0, visited);
    return 0;
}
