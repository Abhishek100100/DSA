class Solution {
bool f(string &s, int index, int count)
{
    int n = s.length();
    if(count<0) return false;
    if(index==n) return  count==0;

    if(s[index]=='(') 
    {
        return f(s, index+1, count+1);
    } 

    else if(s[index]==')')
    {
        return f(s, index+1, count-1);
    }

    // if it is * then try with "(" ,  ")" and this " " 
    else return  f(s, index+1, count) ||  f(s, index+1, count+1) ||  f(s, index+1, count-1);;
}
public:
    bool checkValidString(string s) {
        // can be solved with greedy approach
        // Approach 1 : recursive solution

        //passing string, index, count in the function
       return f(s, 0, 0);
        
    }
};