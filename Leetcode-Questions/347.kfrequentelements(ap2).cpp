// There are 3 ways to do this - 
// 1st approach with brute force with O(n2) time complexity, using hash map with O(n) time complexity and using priority queue with O(nlogk) time complexity.
// 2nd approach with hash map and priority queue with time complexity O(nlogn)
// and 3rd approach with just a vector we call as bucket will be O(n) time complexity.

// Approach 2 : Using Hash Map and Priority Queue
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // This can be solved with hash map and priority queue
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
    }
};
