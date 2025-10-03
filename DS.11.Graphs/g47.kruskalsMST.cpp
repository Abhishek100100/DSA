// User function Template for C++

class DisjointSet
{
    private : 
    vector<int> parent, rank, size;

    public: 

    DisjointSet(int n)
    {
        //0 based indexing
        parent.resize(n);
        rank.resize(n,0);
        size.resize(n,0);

        // making the parent of each node to itself
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i]=1;
        }
    }

    int findUltimateParent(int node)
    {
        // here we are doing path compression
        // we do this by recursively calling the function until we reach the ultimate parent
        if (parent[node] == node) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }


    void unionByRank(int u, int v)
    {
        int ultimatepu = findUltimateParent(u);
        int ultimatepv = findUltimateParent(v);

        if(ultimatepu==ultimatepv) return;
        if(rank[ultimatepu] < rank[ultimatepv]) parent[ultimatepu] = ultimatepv;
        else if(rank[ultimatepu] > rank[ultimatepv]) parent[ultimatepv] = ultimatepu;
        else 
        {
            parent[ultimatepv] = ultimatepu;
            rank[ultimatepu]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ultimatepu = findUltimateParent(u);
        int ultimatepv = findUltimateParent(v);

        if(ultimatepu==ultimatepv) return;
        if(size[ultimatepu] < size[ultimatepv]) {
            parent[ultimatepu] = ultimatepv;
            size[ultimatepv] += size[ultimatepu];
        }
        else {
            parent[ultimatepv] = ultimatepu;
            size[ultimatepu] += size[ultimatepv];
        }
    }
};


class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        
        // step 1 : declarations and initialisations
        int mstSum = 0;
        vector<pair<int,int>> mst;
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        > minHeap;
        
        //step 2: we are pushing all the edges into a min heap sorted by edge weight
        // given data is V vertex and Edges vector : {u,v,wt}
        // see this is a undirected graph, I can convert this to directed inorder to apply kruskals
        //but even without that the MST logic will work fine
        for(auto it: edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            minHeap.push({wt,{u,v}});
        }
        
        // step 3: kruskal's algo logic
        
        // it says that for each edge in the minHeap, check if they belong to the same component
        // if yes then ignore it, else add it to the mst vector and stores the edges
        // at the same time increment the mstSum
        
        DisjointSet ds(V);
        
        // I used for loop before, note that minheap are not meant to be accessed iteratively
        while(!minHeap.empty())
        {
            int u = minHeap.top().second.first;
            int v = minHeap.top().second.second;
            int wt = minHeap.top().first;
            minHeap.pop();
            
            // checking if the nodes are not present in the same component then
            if(ds.findUltimateParent(u)!=ds.findUltimateParent(v))
            {
                mstSum = mstSum + wt;
                mst.push_back({u,v});
                ds.unionBySize(u,v);
            }
        }
        
        return mstSum;
        
    }
};