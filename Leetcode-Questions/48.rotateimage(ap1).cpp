class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>>& matrix) {
        // Two approaches for this brute and optimal
        // Brute Approach

        /*
        Step 1 : Create an answer matrix
        Step 2 : Then map the index i,j to the resultant matrix
        Step 3 : return the ans matrix

        Given : 
            0  1  2  
         0  1  2  3 
         1  4  5  6 
         2  7  8  9

        Result:
            0  1  2  
         0  7  4  1 
         1  8  5  2 
         2  9  6  3

        [i][j] --> [j][n-1-i] 

        [0][0] --> [0][2]
        [0][1] --> [1][2]
        [0][2] --> [2][2]

        [1][0] --> [0][1]
        [1][1] --> [1][1]
        [1][2] --> [2][1]

        [2][0] --> [0][0]
        [2][1] --> [1][0]
        [2][2] --> [2][0]
        */

        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[j][n-1-i] = matrix[i][j];
            }
        }

        return ans;
    }
};
