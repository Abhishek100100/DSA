class Solution {
public:
    bool isAnagram(string s, string t) {
        // i will now write the approach with hash maps
        if(s.length()!=t.length()) return false;
        unordered_map<int,int> maps, mapt;
        
        for(auto it:s) maps[it]++;
        for(auto it:t) mapt[it]++;
        return maps==mapt; // this is how we can compare two maps
    }
};