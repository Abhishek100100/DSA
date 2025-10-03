// Approach 1 : Based on sorting and hashing
// Time and Space Complexity : O(n * k log k) where n is the number of strings and k is the maximum length of a string
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        //step 1 : to temp sort each word and hash it to map  
        for(int i=0;i<strs.size();i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            mp[tmp].push_back(strs[i]);
        }

        //step 2 : now i need to store the strings based on index to vector
        for(auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};



