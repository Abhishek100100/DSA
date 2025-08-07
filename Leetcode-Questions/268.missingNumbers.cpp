class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // given an n+1 sized array with numbers from 0 to n except a single number
        int ans=0;
        for(auto it : nums)  ans = ans ^ it;

        int n = nums.size();
        for(int i=0;i<=n;i++)
        {
            ans = ans ^ i;
        }

        return ans;
    }
};