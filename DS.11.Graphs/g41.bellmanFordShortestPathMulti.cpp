class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        // Then go through all the edges and relax them to find updated distance for V-1 iteration
        // by running for V-1 times we ensure negative cycle doesnt impact us and worst case is handled as well
        
        // step 1 : Basic declaration and initialisations
        vector<int> distance(V,1e8);
        int E = edges.size();
        
        distance[src]=0;
        
        // step 2 : relax the edges V-1 times
        // our job is done here and we can simply return the distance vector, but go to step3
        
        for(int i=0;i<V-1;i++)
        {
            for(auto it:edges)
                {
                    int u = it[0];
                    int v = it[1];
                    int wt = it[2];
                    
                    if( distance[u]!=1e8 && distance[v] > distance[u] + wt)
                    {
                        distance[v] = distance[u]+wt;
                    }
                }
        }
        
        
        
        // step 3 : they have mentioned to return array of -1 in case of negative cycle
        // run one more loop and check is the distance array changes
        for(auto it:edges)
                {
                    int u = it[0];
                    int v = it[1];
                    int wt = it[2];
                    
                    if( distance[u]!=1e8 && distance[v] > distance[u] + wt)
                    {
                        // if i am still able to update it means cycle exists
                        return {-1};
                    }
                }
        
        return distance;
    }
};

Time Complexity: O(V*E), where V = no. of vertices and E = no. of Edges
