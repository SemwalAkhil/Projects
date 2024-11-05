// TRAVERSE THE ADJACENT MATRIX WITH DEPTH FIRST SEARCH

#include <iostream>
using namespace std;

class Graph {
    int vertices;         
    int** adjMatrix;      

public:

    Graph(int V) {
        vertices = V;
        adjMatrix = new int*[V];
        for (int i = 0; i < V; i++) {
            adjMatrix[i] = new int[V];
            for (int j = 0; j < V; j++) {
                adjMatrix[i][j] = 0; 
            }
        }
    }

    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    
    void addEdge(int src, int dest) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1; 
    }

    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[v][i] == 1 && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int startVertex) {
        bool* visited = new bool[vertices];
        for (int i = 0; i < vertices; i++) {
            visited[i] = false;
        }

        DFSUtil(startVertex, visited);

        delete[] visited;
    }
};

int main() {
    int V, E;
    
    cout << "Enter the number of vertices: ";
    cin >> V;

    Graph graph(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter edges (source and destination):" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest;
        cin >> src >> dest;
        graph.addEdge(src, dest);
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    cout << "\nDFS Traversal starting from vertex " << startVertex << ": ";
    graph.DFS(startVertex);

    return 0;
}
