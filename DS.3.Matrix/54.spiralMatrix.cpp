
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       // code here 
        //will solve with 4 pointers and a vector to return ans 
        int left=0;
        int right=matrix[0].size()-1;
        int top=0;
        int bottom=matrix.size()-1;
        vector<int> ans;
        
        //we are moving like right--bottom--left--top 
        while(left<=right && top<=bottom)
        {
        //right
        for(int i=left;i<=right;i++) ans.push_back(matrix[top][i]);
        top++;
        
        //bottom
        for(int i=top;i<=bottom;i++) ans.push_back(matrix[i][right]);
        right--;
        
        //left - 
        if(top<=bottom) for(int i=right;i>=left;i--) ans.push_back(matrix[bottom][i]);
        bottom--;
        
        //top
        if(left<= right) for(int i=bottom;i>=top;i--) ans.push_back(matrix[i][left]);
        left++;
        
        }
        
        return ans;
        /*
        @remember the edge cases and conditions, I missed <=
        @ for left and top if only 1 row/column is there we need to check the condition.
        */ 
    }
};