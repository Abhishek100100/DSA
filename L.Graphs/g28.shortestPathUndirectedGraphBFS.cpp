class Solution {
  public:
    void bfsTraversal(int source, vector<int> &distance, vector<vector<int>>& adj, queue<int> &q )
    {
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it: adj[node])
            {
                if(distance[it]==1e9) 
                {
                    distance[it] = min(distance[it], distance[node]+1);
                    q.push(it);
                }
            }
        }
    };
    
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // We will solve this using BFS method and the same logic as in directed graph
        
        //step 1 : declarations and initialisations
        int V = adj.size();   // number of vertices
        vector<int> distance(V,1e9); // distance vector
        queue<int> q;   // queue data structure
        
        distance[src]=0;
        q.push(src);
        
        // step 2 : just in case connected components exists (we are finding shprtest path it doesnt matter if 
        //connected components exists, they should be rechable from the source node)
    
        bfsTraversal(src, distance, adj, q);
  
        
        // step 3: replace the infinity distance with -1, as asked in problem
        for(int i=0;i<V;i++)
        {
            if(distance[i]==1e9) distance[i]=-1;
        }
        
        return distance;
    }
};
