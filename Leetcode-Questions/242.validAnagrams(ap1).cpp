class Solution {
public:
    bool isAnagram(string s, string t) {
        // i will write the brute approach i can think of
        sort(s.begin(),s.end()); //tc : O(nlogn)
        sort(t.begin(), t.end());
        return s==t;
    }
};