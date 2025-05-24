class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        deque<int> dq; //to store index in monotonic decreasing order

        for(int i=0;i<n;i++)
        {
            // step 1 : remove the elements not in the current sliding window
            while(!dq.empty() && dq.front()<=i-k)
            {
                dq.pop_front();
            }
            // step 2 : if the element at current index is greater then remove smallers from the deque
            while(!dq.empty() && (nums[i] >= nums[dq.back()]))
            {
                dq.pop_back();
            }
            // step 3 : push i in deque for nums[i]
            dq.push_back(i);

            // step 4 :  if i+1 >= k then that's the max element of that window
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};