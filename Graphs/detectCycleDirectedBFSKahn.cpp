class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        // the logic here is that, we will generate toposort array and if the size of
        // that array is not equal to V, then the graph has cycles
        
        
        // step 1 : declare variables and misc
        vector<vector<int>> adjList(V);
        vector<int> indegree(V,0);
        vector<int> toposort;
        queue<int> q;
        
        
        // step 2 : create adjList from edges matrix and indegree vector
        for(auto it: edges)
        {
            adjList[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        
        
        // step 3 : bfs traversal 
        
        // 3.1 first finding all elements with indegree 0 and pushing them to stack
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            toposort.push_back(node);
            
            // reduce the indegree of adjacent element since we have entered that node into the topo sort array
            for(auto it: adjList[node])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        
        // step 4 : check size of toposort and return ans accordingly
        return (toposort.size()==V) ? false : true; 
    }
};