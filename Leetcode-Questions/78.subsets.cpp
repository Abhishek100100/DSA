// Leetcode 78 - Subsets

class Solution {
public:
    vector<vector<int>> result; 

    void solve(int index, vector<int>& nums, vector<int> &temp, int size)
    {
        //this can be solved with take and not take approach
        
        //base condition
        if(index>=size)
        {
            result.push_back(temp);
            return;
        } 

        //take ith element
        temp.push_back(nums[index]);
        solve(index+1, nums, temp, size);
        // skip ith element
        temp.pop_back();
        solve(index+1, nums, temp, size);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp; // to store individual subset
        int size = nums.size(); // size of array

        // recursively solving the function
        // passing start index, og array, temp array, size of array
        solve(0, nums, temp, size); 

        // returning the ans stored in global vector of array
        return result;

    }
};