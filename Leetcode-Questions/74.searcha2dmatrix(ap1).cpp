//Leetcode Question 74: Search a 2D Matrix
// This is solved using linear search and time and space complexity for this is O(m*n) and O(1) respectively
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int col =  matrix[0].size();
        int row = matrix.size();
        for(int i=0;i< row;i++)
        {
            for(int j=0;j< col;j++)
            {
                if(matrix[i][j] == target) return true;
            }
        }

        return false;
    }
};