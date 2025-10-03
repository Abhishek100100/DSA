class Solution {
public:
    // Three approaches for this brute, better and optimal
    //  Optimal Approach : Kadanes Algo
    /*
    - Keep sum and maxsum as two variables
    - assign maxsum with lowest value and keep on updating if sum>maxsum at any stage
    - if the sum starts becoming negative, reset the sum and keep adding the rest elements
    */ 
    int maxSubArray(vector<int>& nums) {
    
        int n = nums.size();
        int maxsum = INT_MIN;
        int sum = 0;

        for(int i=0;i<n;i++)
        {
            sum = sum + nums[i];
            if(sum>maxsum) maxsum=sum;
            if(sum<0) sum=0;
            
        }
        return maxsum;
    }
};



