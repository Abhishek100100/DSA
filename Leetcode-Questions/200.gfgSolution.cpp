class Solution {
    void bfsTraversal(int i, int j, int row, int col,vector<vector<bool>> &visited, vector<vector<char>>& grid )
    {
        // first mark it as visited
        visited[i][j]=1;
        
        //maintain data structures
        queue<pair<int,int>> q;
        q.push({i,j});
        
        while(!q.empty())
        {
            int tempRow = q.front().first;
            int tempCol  = q.front().second;
            q.pop();
            
            for(int rowdel=-1;rowdel<=1;rowdel++)
            {
                for(int coldel=-1;coldel<=1;coldel++)
                {
                    int newRow = tempRow+ rowdel;
                    int newCol = tempCol+ coldel;
                    if((newRow>=0 && newCol>=0) && (newRow<row && newCol<col)
                    && visited[newRow][newCol]==0
                    && grid[newRow][newCol]=='L'
                    )
                    {
                       visited[newRow][newCol]=1;
                       q.push({newRow,newCol});
                    }
                }
            }
        }
    }
  public:
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        
        // let's make a visited matrix first
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        
        vector<vector<bool>> visited(row, vector<bool>(col,0));
        
        
        // traverse the matrix
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(visited[i][j]==0 && grid[i][j]=='L')
                {
                    count++;
                    bfsTraversal(i,j,row, col, visited, grid);
                }
            }
        };
        
        
        return count;
    }
};