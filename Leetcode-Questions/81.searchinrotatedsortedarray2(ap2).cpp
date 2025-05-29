// Leetcode 81 - Search in Rotated Sorted Array II
// Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// problem 33 had unique elements, this may have repeating elements
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // Approach 2 : Optimal | will apply binary search
        // this take O(logn) to find the target if it exists
        int n = nums.size();
        
        int low=0, high=n-1;
        // standard while to find mid and eliminate the unwanted half
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            // if found at mid index then return mid
            if(nums[mid]==target) return true;

            // the problem with dup. elements is that arr[low]==arr[mid]==arr[high]
            // so we trim down the search space
            if(nums[low]==nums[mid] && nums[mid]==nums[high])
            {
                low = low+1;
                high = high-1;
                continue; // this keyword will skip the loop and continue on the next
            }

            // choose left or right half
            // if left half is sorted 
            if(nums[low]<=nums[mid])
            {
                if(nums[low]<=target && target <= nums[mid])
                {
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
            // if right half is sorted
            else {
                if(nums[mid]<=target && target<=nums[high])
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
        }

        // target not found
        return false;
    }
};