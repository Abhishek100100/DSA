// Here is the code for bfs traversal of a graph using an adjacency list representation.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
@ToDo Implement BFS traversal using the adjacency list representation
step 1 : write code to store graph in adjacency list
step 2 : write a function to perform BFS traversal on the given graph
step 3 : write a function to display the BFS traversal result
*/

// I wasn't able to compile this code with normal visited array[size] , since the size of the vector is not known at compile time.
// So I am creating a visited bool vector with fixed size
// this const keyword only exists to keep the passed parameters protected from alterations
vector<int> bfsGraph(const vector<vector<int>> &adjList, int vertex)
{
    int size = adjList.size();
    vector<bool> visited(size, 0); //visited array
    vector<int> bfs; // for storing bfs traversal
    queue<int> q;
    
    q.push(vertex); // initialising with starting vertex
    visited[vertex]=1;

    while(!q.empty())
    {
        auto node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it: adjList[node])
        {
            if(!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
        }
        
    }
    
   return bfs;
}

void printBFS(const vector<int> &bfs) {
    for (auto it : bfs) cout << it << " ";
    cout << endl;
}


int main()
{
    vector<vector<int>> adjList;
    int vertices, edges, isDirected = 0; 
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;
    adjList.resize(vertices + 1); 

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        // If the graph is undirected, add the reverse edge
        if(!isDirected)  adjList[v].push_back(u);
    }
    /*

        1
       / \
      2---3---4
     / \  |   |
    5   6 7---8


    */
    int startVertex;
    cout << "Enter starting vertex for BFS: ";
    cin >> startVertex;

    vector<int> bfsResult = bfsGraph(adjList, startVertex);
    cout << "BFS Traversal: ";
    printBFS(bfsResult);

    return 0;
}