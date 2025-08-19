class Solution {
    
private: 
  bool bfsDetect(int src, vector<vector<int>> &adjList, vector<bool> &vis)
  {
      queue <pair<int,int>> q; // storing (node,parent)
      q.push({src,-1});
      vis[src] = 1;
      
      while(!q.empty())
      {
          int node = q.front().first;
          int parent = q.front().second;
          q.pop();
          
          // iterating over all the neighbours of the node
          for(auto it: adjList[node])
          {
              //if not visited yet
              if(vis[it]==0) 
              {
                  vis[it]=1;
                  q.push({it,node});
              }
              
              //if visited but parent is not same as visited node
              else if(it!=parent)
              {
                  return true;
              }
          }
      }
      
      return false;
  }

  bool dfsDetect(int node, int parent, vector<vector<int>> &adjList, vector<bool> &visited)
  {
    //mark the node as visited first
    visited[node]=1;
    
    //traverse each neighbour and check if they have been visited
    for(auto it : adjList[node])
    {
        if(visited[it]==0)
        {
            if(dfsDetect(it,node,adjList,visited)==true) return true;
        }
        
        else if(it!=parent) return true;
    }
    return false;
  }
  
public:
  bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        // bfs is an level wise traversal
        // to deal with connected components we will run an loop on all vertices
        
        // step 1 : Lets turn edges to list
        vector<vector<int>> adjList(V);
        for(auto it: edges)
        {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        
        // step 2 : take visited array and assign to zero initially
        // then do bfs detect check on each vertex (connected components)
        vector<bool>vis(V,0);
        
        // visiting all the vertices
        for (int i = 0; i < V; i++) 
        {
            if (!vis[i]) 
            {
                //if (bfsDetect(i, adjList, vis)) return true;
                if (dfsDetect(i,-1, adjList, vis)) return true;
            }
        }
    
    // If no cycle is found
    return false;
    }
};