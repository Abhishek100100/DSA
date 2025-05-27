// Leetcode Question 150: Evaluate Reverse Polish Notation
// Approach 2 : Unordered Map and Lambda Function
// note : this is slower than the first approach but more elegant and readable

class Solution {
public:
    
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        // see this is how we declare lambda function learn this
        unordered_map<string, function<int(int,int)>> mp = {
            {"+", [](int a, int b) {return a+b;}},
            {"-", [](int a, int b) {return a-b;}},
            {"*", [](int a, int b) {return (long)a*(long)b;}},
            {"/", [](int a, int b) {return a/b;}}
        };

        for(auto it : tokens)
        {
            if(it=="+" || it=="-" || it=="*" || it=="/")
            {
                int val2 = st.top();
                st.pop();
                int val1 = st.top();
                st.pop();
                st.push(mp[it](val1,val2)); // see here we are calling
            }

            else
            {
                st.push(stoi(it));
            }
        }  
        return st.top();  
    }

    
};