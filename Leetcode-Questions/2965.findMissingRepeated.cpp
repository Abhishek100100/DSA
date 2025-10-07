class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        // to find repeating and missing number
        int x; //repeating number
        int y; // missing number

        int size = grid.size() * grid.size();
        vector<int> nums(size+1,0);

        // creating frequency array of all the elements
        for(auto it1 : grid)  for(auto it2 : it1) nums[it2]++;

        // traverse the nums array to find the remaining numbers
        for(int i=1;i<size+1;i++)
        {
            if(nums[i]==0) y=i;
            if(nums[i]==2) x=i;
        }

        return {x,y};
    }
};