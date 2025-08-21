class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        // it says to return an cost matrix such that it denotes shortest distance from every other node
        
        // we can do this simply by running three loop
        // 1st loop will cover all vertices
        // 2nd and 3rd loop will iterate over each index in the matrix and compute the cost
        // negative edge weight may exist but negative cycles won't
        int n= dist.size(); // since it's a square matrix it will be nxn
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(j==k) dist[j][k]=0;
                    if(dist[j][i]==1e8 || dist[i][k]==1e8) continue;
                    dist[j][k]= min(dist[j][i]+dist[i][k] , dist[j][k]);
                    
                }
            }
        }
    }
};
