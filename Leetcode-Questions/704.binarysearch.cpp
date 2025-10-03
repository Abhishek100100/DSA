// Leetcode 704: Binary Search
class Solution {
public:

    int iterativebs(vector<int>& nums, int target)
    {
        int low= 0;
        int high = nums.size()-1;
        
        while(low<=high)
        {
            int mid = (low+high)/2; //I kept this above out of loop
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }

    int recursivebs(vector<int>& nums, int target, int low, int high)
    {
        if(low>high) return -1;
        else
        {
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) return recursivebs(nums, target, mid+1,high);
            else return recursivebs(nums, target,low, mid-1);
        }
    }

    int search(vector<int>& nums, int target) {
        int size = nums.size();
        //return iterativebs(nums,target);
        return recursivebs(nums,target,0,size-1);
    }
};