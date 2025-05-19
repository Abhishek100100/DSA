class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // I have to turn it into a two sum with target equal to -ve of pivot
        // I need to skip the duplicate elements while finding two sum
        // I need to skip the duplicate pivot to avoid duplicate triplets

        //declaring the variables
        vector<vector<int>> ans;
        int n = nums.size();

        // base condition
        if(n<3) return {};

        // sort the array first
        sort(nums.begin(), nums.end());

        for(int i=0;i<n ; i++)
        {
            // Skip duplicate pivots (need to understand this more)
            if (i > 0 && nums[i] == nums[i - 1]) {
                //When continue is encountered, the rest of the code within the current iteration of the outer for loop is skipped
                continue; 
            }

            int target = 0 - nums[i];
            int left = i+1 ;
            int right = n-1 ;
       
            while(left<right)
            {   
                
                int sum = nums[left] + nums[right];
                if(sum==target) 
                {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    //skip duplicate from left and right pointer
                    // we have added this left<right as well while checking
                    while(left<right && nums[left]==nums[left+1]) left++;
                    while(left<right && nums[right]==nums[right-1]) right--;

                    left++;
                    right--;
                }
                else if(sum<target) left++;
                else right--;
            }
        }

        return ans;
    }
};