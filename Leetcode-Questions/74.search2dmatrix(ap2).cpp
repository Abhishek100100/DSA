//Leetcode Question 74: Search a 2D Matrix
// Will solve this with index mapping from 1D array to 2D array
class Solution {
public:
    bool bsearch(vector<vector<int>>& matrix, int target, int low, int high, int n)
    {
        if(low>high) return false;
        else
        {
            int mid = (low+high)/2;
            // here is the thing to note
            // row no. in 2d is (mid index in 1D)/(#columns)
            // column no. in 2d is (mid index in 1D)%(#columns)
            int row = mid/n;
            int col = mid%n;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) return bsearch(matrix,target,mid+1,high,n);
            else return bsearch(matrix,target,low,mid-1,n);
        }
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // the rows and columns are already sorted in ascending order
        // size of rows and columns
        int m = matrix.size();
        int n = matrix[0].size();

        //basic check
        if(m==0 || n==0) return false;

        int low = 0, high=m*n-1;
        return bsearch(matrix,target,low,high,n);
    }
};