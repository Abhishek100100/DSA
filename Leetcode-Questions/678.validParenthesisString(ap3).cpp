class Solution {
public:
    bool checkValidString(string s) {
        // can be solved with greedy approach
        // Approach 3 : greedy solution using min max

        int n= s.length();
        int mini=0, maxi=0;

        for(int i=0;i<n;i++)
        {
            // this is the condition for open parenthesis
            if(s[i]=='(')
            {
                mini++;
                maxi++;
            }
            // condition for close parenthesis
            else if(s[i]==')')
            {
                mini--;
                maxi--;
            }
            // condition for * 
            else
            {
                mini--;
                maxi++;
            }

             if(mini<0) mini=0;
             if(maxi<0) return false;
        }
      
       return mini==0;
    }
};