class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Approach 1 : Brute | this violated the constraint in the problem
        // this take O(n) to find the target if it exists
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target) return i;
        }
        return -1;
    }
};