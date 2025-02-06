#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* head;
} Graph;

void addEdge(Graph* graph, int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = graph[u].head;
    graph[u].head = newNode;
}

void printGraph(Graph* graph, int vertices) {
    for (int i = 0; i < vertices; i++) {
        Node* temp = graph[i].head;
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int vertices, edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    Graph* graph = (Graph*)malloc(vertices * sizeof(Graph));
    for (int i = 0; i < vertices; i++) {
        graph[i].head = NULL;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printGraph(graph, vertices);
    return 0;
}
