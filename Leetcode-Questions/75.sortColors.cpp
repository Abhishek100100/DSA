class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
        we will use three pointers to solve this
        0s : 0 to low-1
        1s : low to mid-1
        unknown : mid to high
        2's : high+1 to n-1
        */
        int n = nums.size();

        int low=0;
        int mid=0;
        int high = n-1;

        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            else if(nums[mid]==1)
            {
                swap(nums[low], nums[mid]);
                mid++;
            }

            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        
    }
};