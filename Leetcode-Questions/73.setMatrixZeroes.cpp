class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int rowsize = matrix.size();
       int colsize = matrix[0].size();


       vector<int> row(colsize,-1);
       vector<int> col(rowsize,-1);

       // first pass
       for(int i=0;i<rowsize;i++)
       {
        for(int j=0;j<colsize;j++)
        {
            if(matrix[i][j]==0) 
            {
                row[j]=0;
                col[i]=0;
            }
        }
       } 


       // second pass - mark them as 0's
       for(int i=0;i<rowsize;i++)
       {
        for(int j=0;j<colsize;j++)
        {
            if(row[j]==0 || col[i]==0) matrix[i][j]=0;
        }
       } 

    }
};