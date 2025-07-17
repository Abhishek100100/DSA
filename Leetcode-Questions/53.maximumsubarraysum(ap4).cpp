class Solution {
public:
    // Three approaches for this brute, better and optimal
    //  Optimal Approach : Kadanes Algo to return max subarray itself
    /*
    - Keep sum and maxsum as two variables
    - assign maxsum with lowest value and keep on updating if sum>maxsum at any stage
    - if the sum starts becoming negative, reset the sum and keep adding the rest elements
    */ 
    int maxSubArray(vector<int>& nums) {
    
        int n = nums.size();
        int maxsum = INT_MIN;
        int sum = 0;
        int start=-1, ansStart=-1, ansEnd=-1;

        for(int i=0;i<n;i++)
        {
            if(sum==0) start=i;
            sum = sum + nums[i];
            if(sum>maxsum) 
            {
                maxsum=sum;
                ansStart=start;
                ansEnd=i;
            }
            if(sum<0) sum=0;
        }

        // Construct the result subarray using the recorded indices
        vector<int> max_subarray;
        for (int k = ansStart; k <= ansEnd; k++) {
            max_subarray.push_back(nums[k]);
        }


        for(auto it: max_subarray) cout << it << " ";
        return maxsum;
    }
};