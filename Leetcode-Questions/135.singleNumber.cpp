class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Bit manipulation
        // The logic is that xorr of same number is zero, so whatever is 
        // appearing twice will be eliminated
        int xorr = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            xorr = xorr ^ nums[i];
        }

    return xorr;
    }
};