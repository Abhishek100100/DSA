class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        // Prim's algorith:
        
        // step 1 : declaration and initialisation
        // note : as per question we need not store parent for getting mst, but will solve it that way
        vector<vector<pair<int,int>>> adjList(V);
        vector<pair<int,int>> mst;
        vector<bool> visited(V,0);
        int sum=0;
        
        priority_queue< 
        pair<int,pair<int,int>> 
        , vector<pair<int,pair<int,int>>> 
        , greater<pair<int,pair<int,int>>>
        > minHeap;  
        // stores {weight, node, parent}
        
        
        
        // step 2 : convert the edge data to adjacency List
        for(auto it: edges)
        {
            adjList[it[0]].push_back({it[1],it[2]});
            adjList[it[1]].push_back({it[0],it[2]});
        }
        
        // step 3 : apply the prim's algo logic
        minHeap.push({0,{0,-1}});
        while(!minHeap.empty())
        {
            int wt = minHeap.top().first;
            int node = minHeap.top().second.first;
            int parent = minHeap.top().second.second;
            minHeap.pop();
            
            if(visited[node]) continue;
            
            // so this node is unvisited
            visited[node]=1;
            sum = sum + wt;
            if(parent!=-1) mst.push_back({parent,node});
                
            for(auto it: adjList[node])
                {
                    int adjNode = it.first;
                    int adjWt = it.second;
                    
                    if(visited[adjNode]==0)
                    {
                        minHeap.push({adjWt,{adjNode, node}});
                    }
                }
        }
        
        return sum;
    }
};