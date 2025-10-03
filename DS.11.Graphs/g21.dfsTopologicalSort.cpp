class Solution {
  private : 
  // step 2.2 : for dfs traversal 
   void dfsTopo(int node, stack<int> &st, vector<bool> &visited, vector<vector<int>>& adjList )
   {
       visited[node]=true;
       
       for(auto it : adjList[node])
       {
           if(visited[it]==false)
           {
               dfsTopo(it, st, visited, adjList);
           }
       }
       st.push(node);
   }
   
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        // step 0 : declare a visited array and a stack to keep track
        vector<vector<int>> adjList(V);
        vector<bool> visited(V,false);
        stack<int> st;
        vector<int> ans;
        
        
        //step 1 : build adjacency list 
        for(auto it:edges)
        {
            adjList[it[0]].push_back(it[1]);
        }
        
        
        
        
        // step 2.1: to cover for connected components case
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                dfsTopo(i, st, visited, adjList);
            }
        }
        
        
        // step 3 : take out all the elements from stack and push them to ans vector
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};