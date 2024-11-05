// CREATE THE GRAPH AS A ADJACENCY LIST WITH OPERATIONS SUCH AS INSERTION, DELETION

#include <iostream>
#include <list>
using namespace std;

class Graph {
    int vertices;        // Number of vertices
    list<int>* adjList;  // Pointer to an array of adjacency lists

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int V) {
        vertices = V;
        adjList = new list<int>[V];
    }
    
    // Destructor to free dynamically allocated memory
    ~Graph() {
        delete[] adjList;
    }

    // Function to add an edge from source to destination
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest); // Add dest to src's list
        adjList[dest].push_back(src); // Add src to dest's list (for undirected graph)
    }
    
    // Function to remove an edge from source to destination
    void removeEdge(int src, int dest) {
        adjList[src].remove(dest); // Remove dest from src's list
        adjList[dest].remove(src); // Remove src from dest's list (for undirected graph)
    }

    // Function to display the graph as an adjacency list
    void displayGraph() {
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << ":";
            for (auto& vertex : adjList[i]) {
                cout << " -> " << vertex;
            }
            cout << endl;
        }
    }
};

int main() {
    int V, choice, src, dest;
    
    cout << "Enter the number of vertices: ";
    cin >> V;

    Graph graph(V);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Edge\n";
        cout << "2. Remove Edge\n";
        cout << "3. Display Graph\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter source and destination to add edge: ";
                cin >> src >> dest;
                graph.addEdge(src, dest);
                break;

            case 2:
                cout << "Enter source and destination to remove edge: ";
                cin >> src >> dest;
                graph.removeEdge(src, dest);
                break;

            case 3:
                cout << "\nAdjacency List of the Graph:\n";
                graph.displayGraph();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
