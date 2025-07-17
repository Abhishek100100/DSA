
class Solution {
private:
    void dfs(vector<vector<int>>&adjList, int node, vector<bool> &visited)
    {
        visited[node]=1;
        for(auto it: adjList[node])
        {
            if(visited[it]==0) dfs(adjList,it,visited);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        vector<vector<int>> adjList; //adjacency list 
        int vertex= isConnected.size(); // number of vertices
        vector<bool> visited(vertex, 0); // visited array
        int count = 0;  // number of provinces

        //1 based indexing
        adjList.resize(vertex); // To fix the size during compile time

        // Building adjacency list from adjacency matrix
        for(int i=0;i<vertex;i++)
        {
            for(int j=0;j<vertex;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        // Logic for counting number of provinces
        for(int i=0;i<vertex;i++)
        {
            if(visited[i]==0)
            {
                count++;
                dfs(adjList,i,visited);
            }
        }
        return count;
    }
};