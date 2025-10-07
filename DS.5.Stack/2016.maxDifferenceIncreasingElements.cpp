class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        int diff;
        int maxdiff = 0;
        int currentMin = nums[0];
        int n = nums.size();

        for(int i=1;i<n;i++)
        {
            diff = nums[i]-currentMin;
            maxdiff = max(maxdiff, diff);
            currentMin = min(currentMin, nums[i]);
        }

        if(maxdiff>0) return maxdiff;
        else return -1;
    }
};