// Leetcode 694 : 
class Solution {
  private:
  void dfs(int row, int col, int rowBase, int colBase,int rowSize,int colSize, vector<vector<int>>& grid,vector<vector<int>> &visited, vector<pair<int,int>> &island  )
  {
      visited[row][col]=1;
      island.push_back({row-rowBase, col-colBase});
      
      int rowDel[] = {-1, 0, 1, 0};
      int colDel[] = {0, -1, 0, 1};
      
      //step 3 : dfs traversal
      for(int i=0;i<4;i++)
      {
         int rowNgbr = row + rowDel[i];
         int colNgbr = col + colDel[i];
         
         if((rowNgbr >=0 && rowNgbr< rowSize)
         && (colNgbr >=0 && colNgbr< colSize)
         && visited[rowNgbr][colNgbr]==0 && grid[rowNgbr][colNgbr]==1
         )
         {
             dfs(rowNgbr, colNgbr, rowBase, colBase, rowSize, colSize, grid, visited, island);
         }
      }
  }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        // step 1 : Let's declare DS and measure size
        int rowSize = grid.size();      // no. of rows
        int colSize = grid[0].size();   // no. of cols
        
        vector<vector<int>> visited(rowSize, vector<int>(colSize,0)); //visited matrix
        set<vector<pair<int,int>>> st;  //set for storing unique islands
        
        
        // step 2 : the traversal logic
        for(int i=0;i<rowSize;i++)
        {
            for(int j=0;j<colSize;j++)
            {
                if(visited[i][j]==0 && grid[i][j]==1)
                {
                    vector<pair<int,int>> island;
                    dfs(i, j, i, j, rowSize, colSize, grid, visited, island);
                    st.insert(island);
                }
            }
        }
        
        return st.size();
    }
};
