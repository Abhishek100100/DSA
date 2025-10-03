class Solution {
bool f(string &s,  vector<vector<int>>  &dp, int index, int count)
{
    int n = s.length();
    if(count<0) return false;
    if(index==n) return  count==0;
    if(dp[index][count]!=-1) return dp[index][count];
    
    if(s[index]=='(') 
    {
        return dp[index][count]=f(s, dp, index+1, count+1);
    } 

    else if(s[index]==')')
    {
        return dp[index][count]=f(s, dp, index+1, count-1);
    }

    // if it is * then try with "(" ,  ")" and this " " 
    else return dp[index][count] = ( f(s, dp, index+1, count) ||  f(s, dp, index+1, count+1) ||  f(s, dp, index+1, count-1));
}
public:
    bool checkValidString(string s) {
        // can be solved with greedy approach
        // Approach 2 : recursive + memoisation = dp solution

        int n= s.length();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        //passing string, index, count in the function
       return f(s, dp, 0, 0);
        
    }
};