//  ENTER THE VERTICES AND EDGES AND REPRESENT IN ADJACENCY MATRIX AND PRINT IT

#include <iostream>
using namespace std;

int main() {
    int vertices, edges;
    
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    
    // Dynamically allocate a 2D array for the adjacency matrix
    int** adjMatrix = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        adjMatrix[i] = new int[vertices];
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;  // Initialize all entries to 0
        }
    }
    
    cout << "Enter the number of edges: ";
    cin >> edges;
    
    cout << "Enter the edges (source and destination):" << endl;
    for (int i = 0; i < edges; i++) {
        int src, dest;
        cin >> src >> dest;
        
        // Assuming an undirected graph, set both adjMatrix[src][dest] and adjMatrix[dest][src] to 1
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }
    
    // Display the adjacency matrix
    cout << "\nAdjacency Matrix:" << endl;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // Deallocate memory for the adjacency matrix
    for (int i = 0; i < vertices; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    return 0;
}
