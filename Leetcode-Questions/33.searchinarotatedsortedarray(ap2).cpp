// Leetcode 33 - Search in Rotated Sorted Array
// Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Approach 2 : Optimal | will apply binary search
        // this take O(logn) to find the target if it exists
        int n = nums.size();
        
        int low=0, high=n-1;
        // standard while to find mid and eliminate the unwanted half
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            // if found at mid index then return mid
            if(nums[mid]==target) return mid;

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
        return -1;
    }
};