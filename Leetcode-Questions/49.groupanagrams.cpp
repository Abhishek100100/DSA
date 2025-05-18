class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Method 1 : Based on sorting and hashing
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



// METHOD 2 : Based on frequency count
class Solution {
public:
    // Function to generate a frequency key for each string
    string getFrequencyKey(const string& s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        string key;
        for (int i = 0; i < 26; ++i) {
            key += '#' + to_string(count[i]);
        }
        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        for (const string& s : strs) {
            string key = getFrequencyKey(s);
            mpp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& pair : mpp) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};
