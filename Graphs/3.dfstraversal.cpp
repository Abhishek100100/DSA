// Here is the code for dfs traversal of a graph using an adjacency list representation.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
@ToDo Implement dfs traversal using the adjacency list representation
step 1 : write code to store graph in adjacency list
step 2 : write a function to perform dfs traversal on the given graph
step 3 : write a function to display the dfs traversal result
*/

void dfshelper(const vector<vector<int>> &adjList, int node, vector<bool> &visited, vector<int> &dfs)
{
    visited[node]=1;
    dfs.push_back(node);
    for(auto it: adjList[node])
    {
        if(!visited[it])
        {
            dfshelper(adjList,it, visited, dfs);
        }
    }
}

// 0 based indexing graph
vector<int> dfsGraph(const vector<vector<int>> &adjList, int vertex)
{
    int size = adjList.size();
    vector<bool> visited(size,0);
    vector<int> dfs;

    dfshelper(adjList, vertex, visited, dfs);
    return dfs;
}

void printDFS(const vector<int> &dfs) {
    for (auto it : dfs) cout << it << " ";
    cout << endl;
}


int main()
{
    vector<vector<int>> adjList;
    int vertices, edges, isDirected = 0; 
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    // For 1- based indexing
    //adjList.resize(vertices + 1); // vertices numbered 1 to N
    // For 0-based indexing 
    adjList.resize(vertices); // vertices numbered 0 to N-1

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        // If the graph is undirected, add the reverse edge
        if(!isDirected)  adjList[v].push_back(u);
    }
    /*

        0
       / \
      1   2---3
     / \  |   |
    4   5 6---7

    8 8
    0 1
    0 2
    1 4
    1 5
    2 3
    2 6
    3 7
    6 7
    */
    int startVertex;
    cout << "Enter starting vertex for DFS: ";
    cin >> startVertex;

    vector<int> dfsResult = dfsGraph(adjList, startVertex);
    cout << "DFS Traversal: ";
    printDFS(dfsResult);

    return 0;
}