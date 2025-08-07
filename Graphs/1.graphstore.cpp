#include<iostream>
#include<vector>
using namespace std;

class Graph {
private:
    int vertices;
    int edges;
    bool isDirected;

public:
    // Constructor
    Graph(int n, int m, bool directed = false) {
        vertices = n;
        edges = m;
        isDirected = directed;
    }
    
    // Function to create adjacency matrix || Time and space complexity: O(V^2)
    void createAdjacencyMatrix() 
    { 
        int adjMatrix[vertices + 1][vertices + 1];
        // Initialize matrix with 0s
        for(int i = 0; i <= vertices; i++) {
            for(int j = 0; j <= vertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
        
        // Populating the adjacency matrix
        for(int i = 0; i < edges; i++) {
            int u, v;
            cin >> u >> v;
            adjMatrix[u][v] = 1;
            if (!isDirected) {
                adjMatrix[v][u] = 1;
            }
        }
        
        // Display adjacency matrix
        cout << "\nAdjacency Matrix:\n";
        for(int i = 1; i <= vertices; i++) {
            for(int j = 1; j <= vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
    
    // Function to create adjacency list | Time and space complexity: O(V + E)
    void createAdjacencyList() {
        vector<vector<int>> adjList(vertices + 1);
        
        for(int i = 0; i < edges; i++) {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            if (!isDirected) {
                adjList[v].push_back(u);
            }
        }
        
        // Display adjacency list
        cout << "\nAdjacency List:\n";
        for(int i = 1; i <= vertices; i++) {
            cout << i << " -> ";
            for(int j = 0; j < adjList[i].size(); j++) {
                cout << adjList[i][j];
                if(j < adjList[i].size() - 1) cout << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    // Taking number of vertices and edges as input
    int n, m;
    cin >> n >> m;
    
    bool directed = false;
    
    // Since I have made an class for graph, here I am making an object of that class
    Graph graph(n, m, directed);
    
    //graph.createAdjacencyMatrix();
     graph.createAdjacencyList();

    // note : for weighted graphs, we can modify the adjacency list to store pairs of (vertex, weight)
    return 0;
}
