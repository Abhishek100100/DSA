class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Two approaches to solve this brute O(n2) and optimal O(n)
        // Brute Solution - gives TLE on Leetcode
        
        /*
        step 1: use two loops to pivot one element and then calculate cost with the
                other elements
        step 2: maintain cost, max_profit variable
        */

        int max_profit = 0, cost;
        int n = prices.size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1;j<n;j++)
            {
                cost = prices[j]-prices[i];
                max_profit = max(max_profit, cost);
            }
        }
        return max_profit;
    }
};