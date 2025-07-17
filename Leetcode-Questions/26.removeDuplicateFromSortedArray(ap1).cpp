class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //Brute : Additional DS approach
        // Time and Space Complexity : O(nlog(n)) and O(n)
        set<int> ans;

        for(auto it: nums) ans.insert(it);
        
        int k = 0;
        for(auto it: ans) 
        {
            nums[k]= it;
            k++;
        }
        return k;
    }
};