// return the indices of the two numbers such that they add up to a specific target
// Approach 1 with map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //coding up better solution for returning index
        map<int,int> mpp;
        int size = nums.size();
        int diff;

        for(int i=0;i<size;i++)
        {
            diff = target - nums[i];
            if(mpp.find(diff) != mpp.end()) return {mpp[diff],i};
            mpp[nums[i]]=i;
        }
        return {-1,-1};
    }
};

