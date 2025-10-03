// there are 4 ways to solve this
// bad brute, good brute, better and optimal approach

// Approach 2 : good brute approach
// Will create an m+n sized array and then fill it with comparing pointers and return the mid element
class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int size = size1 + size2;
        
        vector<int> nums;

        int i=0, j=0;
        while(i<size1 && j<size2)
        {

            if(nums1[i]<=nums2[j])
            {
                nums.push_back(nums1[i]);
                i++;
            }

            else 
            {
                nums.push_back(nums2[j]);
                j++;
            }
        }

        while(i!=size1 && j==size2)
        {
            nums.push_back(nums1[i]);
            i++;
        }

        while(i==size1 && j!=size2)
        {
            nums.push_back(nums2[j]);
            j++;
        }

        if(size%2 == 1) return double(nums[size/2]);
        else return (nums[size/2] + nums[(size/2) - 1])/2.0;
    }
};