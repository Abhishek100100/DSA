class Solution {
public:

    void CombSum(int index, int target, vector<int> &candidates, vector<int> &ds, vector<vector<int>> &finalans)
    {
        if(index==candidates.size())
        {
            if(target==0) finalans.push_back(ds);
            return; 
        }

        //pick element
        if(candidates[index] <= target)
        {
            ds.push_back(candidates[index]);
            CombSum(index, target- candidates[index],candidates,ds,finalans);
            ds.pop_back();
        }

        CombSum(index+1, target, candidates, ds, finalans);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> ds;
        vector<vector<int>> finalans ; 
        CombSum(0,target,candidates,ds, finalans);
        return finalans;        
    }
};