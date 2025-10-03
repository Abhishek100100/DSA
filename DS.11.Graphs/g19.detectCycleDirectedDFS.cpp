class Solution {
  public:
    bool dfsTraversal(int start, vector<vector<int>> &adjList, vector<int> &visited, vector<int> &pathVisited )
    {
        visited[start]=1;
        pathVisited[start]=1;
        
        for(auto it: adjList[start])
        {
            // when the adjacent node is not visited
            if(visited[it]==0)
            {
                if(dfsTraversal(it, adjList,visited, pathVisited)==true) return true;
            }
            
            // if the node is already visited and is on the same/constant path
            else if(pathVisited[it]==1)
            {
                return true;
            }
        }
        
        // unmarking path as different route is going on
        pathVisited[start]=0;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        // step 1 : Let's turn the edges into adjacency list
        vector<vector<int>> adjList(V);
        for(auto it: edges)
        {
            adjList[it[0]].push_back(it[1]);
        }
        
        // step 2: for dfs traversal on components
        vector<int> visited(V,0);
        vector<int> pathVisited(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(dfsTraversal(i, adjList, visited, pathVisited)==true) return true;
        }
        
        return false;
    }
};

