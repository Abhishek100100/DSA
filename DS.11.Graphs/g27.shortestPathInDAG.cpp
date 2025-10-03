// User function Template for C++
class Solution {
  private : 
  void topoSort(int source, stack<int> &st, vector<int> &visited,  vector<vector<pair<int,int>>> &adjList)
  {
      visited[source]=1;
      
      for(auto it: adjList[source])
      {
          int node = it.first;
          if(visited[node]==0)
          {
              topoSort(node, st, visited, adjList);
          }
      }
      
      st.push(source);
  }
  
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        /*
        Given:
        - V is the number of vertices
        - E is the number of edges
        - edges stores [u,v,wt]   u---(wt)--->v
        */
        
        // step 1: Let's create adjacency list
        vector<vector<pair<int,int>>> adjList(V);
        for(auto it: edges)
        {
            adjList[it[0]].push_back({it[1],it[2]});
        }
        
        // step 2 : Let's do toposort (dfs)(anything can be chosen)
        stack<int> st;
        vector<int> visited(V,0);
        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                topoSort(i, st, visited, adjList);
            }
        }
        
        
        // step 3 : Lets do the distance computation
        vector<int> distance(V, 1e9);
        distance[0]=0;
        
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            for(auto it: adjList[node])
            {
                int v = it.first;
                int wt = it.second;
                distance[v] = min(distance[node] + wt, distance[v]); 
            }
        }
        
        
        // step 4 : for unreachable nodes
        for (int i = 0; i < V; i++) {
            if (distance[i] == 1e9) {
                distance[i] = -1;
            }
        }
        
        return distance;
    }
};
