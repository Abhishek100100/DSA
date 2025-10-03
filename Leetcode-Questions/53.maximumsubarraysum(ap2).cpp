class Solution {
public:
    // Three approaches for this brute, better and optimal
    //  Better Approach : Run two loops and calculate sum of every sub-array
    int maxSubArray(vector<int>& nums) {
    
        int n = nums.size();
        int maxsum = INT_MIN;

        for(int i=0;i<n;i++)
        {
            int sum = 0;
            for(int j=i;j<n;j++) 
            {
                sum = sum + nums[j];
                maxsum = max(maxsum, sum);
            }
        }
        return maxsum;
    }
};