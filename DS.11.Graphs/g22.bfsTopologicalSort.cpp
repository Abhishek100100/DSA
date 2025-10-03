class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        // step 0 : declare a visited array and a stack to keep track
        vector<vector<int>> adjList(V);
        queue<int> q;
        vector<int> indegree(V,0);
        vector<int> ans;
        
        
        //step 1 : build adjacency list and populate indegree array
        for(auto it:edges)
        {
            adjList[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        
        
        // step 2 : to push all the nodes with indegree 0 into the queue
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==false)
            {
                q.push(i);
            }
        }
        
        
        // step 3 : bfs traversal on the graph
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            // since the current node is in toposort, reduce indegree of it's adjacent nodes
            for(auto it: adjList[node])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        return ans;
    }
};
