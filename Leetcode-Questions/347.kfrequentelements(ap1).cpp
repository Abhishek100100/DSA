// There are 3 ways to do this - 
// 1st approach with brute force with O(n2) time complexity, using hash map with O(n) time complexity and using priority queue with O(nlogk) time complexity.
// 2nd approach with hash map and priority queue with time complexity O(nlogn)
// and 3rd approach with just a vector we call as bucket will be O(n) time complexity.

// Approach 1 : Brute Force O(n^2) approach
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //step 1 : hash the elements into a map
        unordered_map<int,int> mp; // map <number,frequency>
        for(auto it: nums) mp[it]++;
        
        //step 2 : sort the map based on frequency
        vector<pair<int,int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second > b.second; // sort in descending order of frequency
        });
        
        //step 3 : store the top k frequent elements into the answer vector
        vector<int> ans;
        for(int i=0; i<k && i<vec.size(); i++) {
            ans.push_back(vec[i].first);
        }
        
        return ans;
    }
};
