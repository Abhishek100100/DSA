class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Array question
        // Two approaches to solve this brute O(n2) and optimal O(n)
        
        // Optimal Solution
        // The idea is to select an element in the array and subtract it with
        // the smallest/min element on it's left, whoever gives maximum number 
        //shall remain the profit.
        int min_price = prices[0];
        int profit, max_profit=0;
        int n = prices.size();
        
        for(int i=1; i<n; i++)
        {
            profit = prices[i] - min_price;
            max_profit = max(profit, max_profit);
            min_price = min(prices[i],min_price);
        }
        return max_profit;
    }
};