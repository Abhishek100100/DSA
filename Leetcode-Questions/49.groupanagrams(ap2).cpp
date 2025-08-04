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
            key += 'A' + to_string(count[i]);
        }
        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // map for hashing the characters
        unordered_map<string, vector<string>> mpp;
        
        for (auto s : strs) {
            string key = getFrequencyKey(s);
            mpp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
