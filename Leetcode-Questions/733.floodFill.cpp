// Leetcode 733. Flood Fill
// https://leetcode.com/problems/flood-fill/
// Time complexity is O(N*M) where N is number of rows and M is number of columns and N*M is the total number of cells in the grid.
// Space complexity is O(N*M) for the visited matrix.


class Solution {
private : 
   void dfsTraversal(vector<vector<int>>& image, vector<vector<int>>& floodImage, int sr, int sc, int color, int initColor)
   {
        // assigning new color to the pixel
        floodImage[sr][sc] = color;

        // declaring variables
        int rowDel[] = {-1,0,1,0};
        int colDel[] = {0,1,0,-1};
        int rowSize = image.size();
        int colSize = image[0].size();

        // running loop to traverse neighbours and color them
        for(int i=0;i<4;i++)
        {
            int rowN = sr+rowDel[i];
            int colN = sc+colDel[i];

            if((rowN<rowSize && colN<colSize) 
            && (rowN>=0 && colN>=0) 
            && (image[rowN][colN]==initColor)
            && floodImage[rowN][colN]!=color)
            {
                dfsTraversal(image,floodImage,rowN, colN, color, initColor);
            }
        }
    
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> floodImage = image;
        int initColor = image[sr][sc];

        dfsTraversal(image, floodImage, sr, sc, color, initColor);

        return floodImage;
    }
}; 