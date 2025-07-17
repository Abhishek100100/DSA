class Solution {
public:
    // Three approaches for this brute, better and optimal
    //  Brute Approach : Run three loops and calculate sum of every sub-array
    int maxSubArray(vector<int>& nums) {
    
        int n = nums.size();
        int maxsum = INT_MIN;

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int sum=0;
                for(int k=i;k<=j;k++)
                {
                    sum = sum + nums[k];
                }
                maxsum = max(maxsum, sum);
            }
        }
        return maxsum;
    }
};