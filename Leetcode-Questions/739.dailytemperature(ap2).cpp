// Leetcode 739: Daily Temperatures
// Approach 2 : optimal with monotonic stack (decreasing)
// remember that we will be starting from end to remember history
// the logic was simple i was getting confused, see previous submissions
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
            {
                st.pop();
            }

            if(st.empty()) ans[i]=0;
            else ans[i]=(st.top()-i);

            st.push(i);

        }
        return ans;
    }
};