// Leetcode Question 739: Daily Temperatures
// This can be solved with two pointers approach, but it will cause TLE
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // lets try to do this with two pointers approach
        // worked for 47/48 and caused TLE for a solution
        vector<int> ans;
        int n = temperatures.size();
        int left = 0, right=0;

        for(int i=0; i<n; i++)
        {
            left = i;
            right = i+1;

            while(right<n && temperatures[left]>=temperatures[right])
            {
                right++;
            }

            if(right<n && temperatures[left]<temperatures[right]) ans.push_back(right-left);
            else ans.push_back(0);
        }
        return ans;
    }
};