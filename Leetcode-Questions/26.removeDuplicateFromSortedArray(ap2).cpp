class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //Optimal : Two pointer approach
        int i=0;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j] != nums[i])
            {
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;
    }
};