class Solution {
private: 
    int minJump(vector<int>& nums, int ind, vector<int> &dp)
    {
       int n = nums.size();
       if(ind>=n-1) return 0;
       if(dp[ind]!=-1) return dp[ind];
       int mini = 1e9;
        for(int i=1;i<=nums[ind];i++)
         {
            mini = min(mini,1 + minJump(nums,ind+i,dp));
         }
        return dp[ind] = mini;     
    }
public:
    int jump(vector<int>& nums) {
        // we can solve it using recursive and greedy approach
        // approach 2 :  recursion + memoisation --> dp
        // here the parameters are input array, index, jump number
        int n = nums.size();
        vector<int> dp(n, -1);
        return minJump(nums,0,dp);
    }
};