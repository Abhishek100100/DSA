// Leetcode Question 22: Generate Parentheses
// Approach 2 :  Approach 1 + minor checks and optimisation
class Solution {
public:
   
    // recursive function
    void Combinations(string& curr, int n, vector<string> &ans, int open, int close)
    {
        // base condition
        if(curr.length()==2*n)
        {
            // check if valid, and then put into result
            ans.push_back(curr);
            return ;
        }

        // push the "(" into the string (note we have applied vector operation to string)
        if(open<n)
        {
            // open++;  not needed
            curr.push_back('(');
            Combinations(curr,n, ans, open+1, close);
            curr.pop_back();
        }
        
        if(close<open)
        {
            //close++; not needed
            curr.push_back(')');
            Combinations(curr,n, ans, open, close+1);
            curr.pop_back();
        }        
    }

    vector<string> generateParenthesis(int n) {
        // Approach 1 :  Recursion + Valid Parenthisis check
        vector<string> ans;
        string curr = "";
        int open= 0, close=0;
        Combinations(curr,n,ans, open, close);
        return ans;
    }
};