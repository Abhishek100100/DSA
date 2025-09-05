class Solution {
private: 
    int minJump(vector<int>& nums, int ind, int jump)
    {
       int n = nums.size();
       if(ind>=n-1) return jump;
       int mini = INT_MAX;
        for(int i=1;i<=nums[ind];i++)
         {
            mini = min(mini, minJump(nums,ind+i,jump+1));
         }
         return mini;     
    }
public:
    int jump(vector<int>& nums) {
        // we can solve it using recursive and greedy approach
        // approach 3 :  greedy and optimal
        int n = nums.size();
        int jumps=0, left=0, right=0;

        while(right<n-1)
        {
            int farthest=0;
            for(int i=left;i<=right;i++) farthest = max(farthest, i + nums[i]);
            left= right+1;
            right=farthest;
            jumps++;
        }
        return jumps;
    }
};