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
        // approach 1 :  recursion
        // here the parameters are input array, index, jump number
        return minJump(nums,0,0);
    }
};