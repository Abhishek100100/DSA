// There are 3 ways to do this - 
// 1st approach with brute force with O(n2) time complexity, using hash map with O(n) time complexity and using priority queue with O(nlogk) time complexity.
// 2nd approach with hash map and priority queue with time complexity O(nlogn)
// and 3rd approach with just a vector we call as bucket will be O(n) time complexity.


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // three approaches 1. brute, 2. Priority Queue , 3.Bucket Sort O(n) approach
        /*
        // Approach 2

        //step 1 : hash the elements into a map
        unordered_map<int,int> mp; // map <number,frequency>
        for(auto it: nums) mp[it]++;
        
        //step 2 : push the (num,freq) data into the min heap
        typedef pair<int,int> P; // for storing (freq,num) only till k size
        priority_queue<P, vector<P>, greater<P>> pq;

        for(auto it: mp)
        {
            
            // what i have to do is traverse the entire map
            // push the elements into pq
            // if the size of pq is greater than K, then do a pop
            // and push the new element
            
            int value = it.first;
            int frequency = it.second;

            pq.push({frequency,value});
            if(pq.size()>k) pq.pop();
        }

        //step 4 : store the pq elements into the returning data structure
        vector<int> ans;
        while(pq.empty()!=1)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
        */

        //Approach 3

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
