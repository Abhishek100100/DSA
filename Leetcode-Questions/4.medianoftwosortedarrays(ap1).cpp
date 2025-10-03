// there are 4 ways to solve this
// bad brute, good brute, better and optimal approach

// Approach 1 : bad brute approach
// Will create an m+n sized array and then sort it and return the mid element
class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       
        int size = nums1.size() + nums2.size();
        vector<int> nums;

        for(auto it: nums1) nums.push_back(it);
        for(auto it: nums2) nums.push_back(it);

        sort(nums.begin(), nums.end());

        if(size%2 == 1) return double(nums[size/2]);
        else return (nums[size/2] + nums[(size/2) - 1])/2.0;
    }
};