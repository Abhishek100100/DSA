class Solution {
private:

public:
    int orangesRotting(vector<vector<int>>& grid) {

        // basic declration and initialisations
        int rows =grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited = grid;
        queue<pair< pair<int,int>, int>> q; // stores [{row,column},time]

        // traverse the grid and push all the rotten oranges into queue
        // keeping count of fresh oranges as well
        int countFresh=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==2) q.push({{i,j},0});
                if(grid[i][j]==1) countFresh++;
            }
        }

        // Let's apply the bfs logic now
        int time=0;
        int dRow[]= {-1,0,1,0};
        int dCol[]= {0,1,0,-1};
        int count=0; // count of fresh orange being rotten

        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);

            //bfs traversal of neighbours
            for(int i=0;i<4;i++)
            {
                int nRow = r + dRow[i];
                int nCol = c + dCol[i];

                if(
                    (nRow>=0 && nCol>=0) &&
                    (nRow < rows && nCol < cols) &&
                    (visited[nRow][nCol]==1) &&
                    (grid[nRow][nCol]==1)
                )
                {
                    q.push({{nRow,nCol}, time+1});
                    visited[nRow][nCol]=2;
                    count++;
                }
            }
        }

        if(count != countFresh) return -1;
        else return time;
    }
};