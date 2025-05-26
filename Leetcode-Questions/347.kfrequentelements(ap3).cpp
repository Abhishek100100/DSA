// There are 3 ways to do this - 
// 1st approach with brute force with O(n2) time complexity, using hash map with O(n) time complexity and using priority queue with O(nlogk) time complexity.
// 2nd approach with hash map and priority queue with time complexity O(nlogn)
// 3rd approach with just a vector we call as bucket will be O(n) time complexity.

// Approach 3 : Bucket Sort O(n) approach
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        //step 1 : hash the array and note the frequency
        unordered_map<int,int> map;
        for(auto it: nums) map[it]++;

        //step 2 : create a bucket vector of size equal to vector size + 1
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);

        // index = frequency ; value = elements
        for (auto const& [num, freq] : map) {
            // I need to push the elements from num at the index equal to frequency
            bucket[freq].push_back(num);
        }

        //step 3 : pick elements from the right till k elements are obtained
        vector<int> ans;
        for (int i = n; i >= 0 && k > 0; i--) {
            if (!bucket[i].empty()) {
                for (int val : bucket[i]) {
                    ans.push_back(val);
                    k--;
                    if (k == 0) break;
                }
            }
        }
        return ans;
    }
};
