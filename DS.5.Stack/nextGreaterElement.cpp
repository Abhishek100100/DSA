class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int> ms; // I am maintaining monotonically increasing stack
        // we will only be storing index in the stack
        // but will store back the actual element in the ans arr
        
        
        for(int i=n-1;i>=0;i--)
        {
            // 1. Clean the stack: Pop elements smaller than or equal to current
            while(!ms.empty() && arr[ms.top()] <= arr[i]) ms.pop();
            
            // 2. Find the answer
            if(ms.empty()) 
            {
                ans[i] = -1;
            }
            
            else
            {
                ans[i]=arr[ms.top()];
            }
            
            // 3. Push the current index onto the stack
            ms.push(i);
            
        }
        
        return ans;
    }
};