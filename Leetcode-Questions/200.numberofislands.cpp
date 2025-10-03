// Leetcode 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/
// Time and Space Complexity is O(N*M) where N is number of rows and M is number of columns and N*M is the total number of cells in the grid.


class Solution {
public:
    void bfstraversal(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid, int rowsize, int colsize)
    {
        visited[row][col]=1; // mark that position as visited
        queue<pair<int,int>> q; 
        q.push({row,col});

        // bfs logic
        while(!q.empty())
        {
            row = q.front().first;
            col  = q.front().second;
            q.pop();

            // traverse the neighbours and mark them visited
            // here remember the delta logic(different for 4 and 8 neighbour)
            // here we have 4 neighbours
            int rowdel[] = {-1, 0, 1, 0};
            int coldel[] = {0, 1, 0, -1};

            for(int i=0; i<4; i++) 
            {
                int rowngbr = row + rowdel[i];
                int colngbr = col + coldel[i];
                if((rowngbr >=0 && rowngbr < rowsize) && (colngbr >=0 && colngbr < colsize)
                         && (grid[rowngbr][colngbr]=='1')
                         && !visited[rowngbr][colngbr])
                         {
                            visited[rowngbr][colngbr]=1;
                            q.push({rowngbr,colngbr});
                         }
                }
            
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rowsize = grid.size(); // number of rows
        int colsize = grid[0].size(); // number of columns
        int count = 0; // number of islands

        // visited matrix
        vector<vector<int>> visited(rowsize, vector<int>(colsize,0));

        // traverse the matrix named as grid
        for(int row=0; row< rowsize;row++)
        {
            for(int col=0;col<colsize;col++)
            {
                if(visited[row][col]!=1 && grid[row][col]=='1')
                {
                    count++;
                    bfstraversal(row,col,visited, grid, rowsize, colsize);
                }
            }
        }
        return count;

    }
};