//Position this line where user code will be pasted.
class Solution {
  private:
  
  void dfs(int i, vector<bool> &visited, stack<int> &st , vector<vector<int>> &adj )
  {
      visited[i]=1;
      
      for(auto it: adj[i])
      {
          if(visited[it]==0)
          {
              dfs(it, visited, st, adj);
          }
      }
     
      st.push(i);
  }
  
  void dfsTranspose(int i, vector<bool> &visited, vector<vector<int>> &adjTranspose )
  {
      visited[i]=1;
      
      for(auto it: adjTranspose[i])
      {
          if(visited[it]==0)
          {
              dfsTranspose(it, visited, adjTranspose);
          }
      }
  
  }
  
  public:
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        /*
            1. If we think let's say that our graph has n Strongly Connected Component, say sc1, sc2 ...scn. Then whole graph will be visited in order, `sc1-->sc2-->sc3-->....-->scn`.
            2. Now if we remove all the edges which connect the 2 connected component then in one visit we will be traversing 1 Strongly Connected Component. `sc1, sc2, sc3,...,scn`.
            3. So, Idea is to remove link between connected component. Ok! but how we know in advance exactly which edge is link? Ans is we don't. And that's why instead of removing edge, we will reverse all the edge. so a link edge b/w `sc1-->sc2` became `sc2-->sc1` and thus if you start with sc1, you will only visit sc1 component.
            4. Does reversing edge will not affect component's like sc1,sc2 etc. Ans is no because they are Strongly Connected component, if you reverse each edge of a Strongly Connected Component, it will still be a Strongly Connected Component.
            5. Ok! Alright, One final caveat, let's say we start traversing from sc2? Then in one visit we can traverse both sc1,sc2. To prevent this, we will sort the vertices in finish time of dfs and visit the vertices who finished last. So, if in original graph, there is a relation like `sc1-->sc2`, sc1 will always finish last and thus will be picked first.
            6. Does BFS work? No, we have to sort according to finish time.
        
        */
        
        // step 1 :  initialisation and declarations
        int V = adj.size();
        vector<bool> visited(V,0);
        stack<int> st;
        int scc = 0;
        
        vector<vector<int>> adjTranspose(V);
        
        // step 2 : Applying dfs to find the finishing time of each node
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                dfs(i, visited, st, adj);
            }
        }
        
        // now our stack is ready with finishing time ordering
        
        // step 3 : reverse the edges in the adj list, that is to make a transpose of it
        for(int i=0;i<V;i++)
        {
            visited[i]=0; // just resetting the visited array for step4 use
            for(auto it: adj[i])
            {
                adjTranspose[it].push_back(i);
            }
        }
        
        
        // step 4 : now we can apply dfs on the transpose adjlist to count the number of strongly connected components
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
           
            if(visited[node]==0)
            {
                scc++;
                dfsTranspose(node, visited, adjTranspose);
            }
        }
        
        
        return scc;
        
    }
};