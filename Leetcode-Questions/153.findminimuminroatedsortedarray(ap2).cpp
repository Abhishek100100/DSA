// Leetcode 153. Find Minimum in Rotated Sorted Array
// Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& nums) {
        // Since the array is sorted, we will use this to our advantage
        // we can apply binary search to the problem to find the pivot element
        // the cases are tricky, the thing is the chosen sorted half may or may not have the element
        // in that case we pick min out of it and then move to the unsorted half and search for the element
        // remember in a rotated sorted array, definitely one half is always sorted
        int pivot = INT_MAX;
        int low=0, high=nums.size()-1;

        while(low<=high)
        {
            int mid = (low+high)/2;

            // check in left half if it's sorted
            if(nums[low]<=nums[mid])
            {
                pivot = min(pivot, nums[low]);
                low = mid+1;
            }

            // check in right half if that's sorted
            else
            {
                pivot = min(pivot, nums[mid]);
                high = mid-1;
            }
        }
        return pivot;
    }
};