// Leetcode 81 - Search in Rotated Sorted Array II
// Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// problem 33 had unique elements, this may have repeating elements
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // Approach 1 : Brute | this violated the constraint in the problem
        // this take O(n) to find the target if it exists
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target) return true;
        }
        return false;
    }
};