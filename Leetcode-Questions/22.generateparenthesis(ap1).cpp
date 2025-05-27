// Leetcode Question 22: Generate Parentheses
// Approach 1 :  Recursion + Valid Parenthisis check
class Solution {
public:
    // valid parenthesis check
    bool isValid(string &curr)
    {
        int count = 0;
        for(auto it: curr)
        {
            if(it=='(') count++;
            else count--;
            // there was a flaw with this count check, have fixed it with below check
            if(count<0) return false; 
        }
        if(count) return false;
        else return true;
    }

    // recursive function
    void Combinations(string& curr, int n, vector<string> &ans)
    {
        // base condition
        if(curr.length()==2*n)
        {
            // check if valid, and then put into result
            if(isValid(curr)) ans.push_back(curr);
            return ;
        }

        // push the "(" into the string (note we have applied vector operation to string)
        curr.push_back('(');
        Combinations(curr,n, ans);
        curr.pop_back();
        
        curr.push_back(')');
        Combinations(curr,n, ans);
        curr.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        // Approach 1 :  Recursion + Valid Parenthisis check
        vector<string> ans;
        string curr = "";
        Combinations(curr,n,ans);
        return ans;
    }
};