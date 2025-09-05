class Solution {
public:
    bool isValid(string s) {
        stack<char> validpara ; 

        //write basic code, then handle edge cases
        for(int i=0 ; i< s.size();i++)
        {
            if(s[i]== '(' || s[i]=='{' || s[i]=='[') validpara.push(s[i]);
            else 
            {
                if(validpara.empty()) return false;
                if((s[i]==')' && validpara.top()=='(') ||
                (s[i]=='}' && validpara.top()=='{') ||
                (s[i]==']' && validpara.top()=='[')) validpara.pop();

                else return false;
            };
        };

        return validpara.empty();
};

};