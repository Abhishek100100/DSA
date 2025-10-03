class Solution {
int timer=1;
private : 
void dfs(int node, int parent,vector<bool> &visited, vector<int> &startTime, vector<int> &finishTime, 
          vector<vector<int>> &adjList, vector<vector<int>> &ans)
{
    //mark the node as visited
    visited[node]=1;
    startTime[node] = finishTime[node]= timer;
    timer++;

    // traverse across the adjacent nodes
    for(auto it: adjList[node])
    {
        // if the adjacent node is the parent
        if(it==parent) continue;
        if(visited[it]==0)
        {
            dfs(it, node, visited, startTime, finishTime, adjList, ans);
            finishTime[node]= min(finishTime[node], finishTime[it]);

            // node -- it be a bridge?
            if(finishTime[it]>startTime[node])
            {
                ans.push_back({it,node});
            }
        }

        else {
            finishTime[node]=min(finishTime[node],startTime[it]);
        }
    }
}

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // this is a graph problem where V = n and connections is list of edges
        // the problem is the return the list of edges which are critical/bridges in the given graph

        // we can solve this using tarjan algorithm

        // step 1 : declaration and initialisation
        vector<vector<int>> adjList(n); // adjacency List
        vector<vector<int>> ans; // for returning the bridges list
        
        vector<bool> visited(n,0);
        vector<int> startTime(n);
        vector<int> finishTime(n);
        
        
        // step 2 : convert the edges list into adjacent list
        for(auto it: connections)
        {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }


        // step 3 : 
        dfs(0,-1, visited, startTime, finishTime, adjList, ans);
        return ans;
    }
};