// Leetcode 153 - Find Minimum in Rotated Sorted Array
// Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& nums) {
        // brute force : linear search (violates the constraint in solution)
        // just writing to solve it with brute
        int mini = INT_MAX;
        for(auto it: nums) mini = min(mini, it);
        return mini;
    }
};