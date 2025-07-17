class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Two approaches for this brute and optimal
        // Optimal Approach
        /*
        Step 1 : Do Transpose of given matrix and do index mapping for that
        Step 2 : Then reverse each row to obtain the resultant matrix
        Step 3 : return the matrix

        Given : 
            0  1  2  
         0  1  2  3 
         1  4  5  6 
         2  7  8  9

        Transpose : row and column exchange
            0  1  2  
         0  1  4  7 
         1  2  5  8 
         2  3  6  9

        [i][j] --> [j][i]
        [0][0] --> [0][0]
        [0][1] --> [1][0]
        [0][2] --> [2][0]

        [1][0] --> [0][1]
        [1][1] --> [1][1]
        [1][2] --> [2][1]

        [2][0] --> [0][2]
        [2][1] --> [1][2]
        [2][2] --> [2][2]

        Result: reverse the rows of transpose matrix
            0  1  2  
         0  7  4  1 
         1  8  5  2 
         2  9  6  3
        */

        int n = matrix.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && i<j) swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};