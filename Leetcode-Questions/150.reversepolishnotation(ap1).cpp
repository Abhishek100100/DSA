// Approach 1 : normal implementation with operation function
class Solution {
public:
    int operation(int a, int b, string token)
    {
        if(token == "+") return a+b;
        else if(token == "-") return a-b;
        else if(token == "*") return (long)a*(long)b;
        else return a/b;

    }

    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;

        for(auto it : tokens)
        {
            if(it=="+" || it=="-" || it=="*" || it=="/")
            {
                int val2 = st.top();
                st.pop();
                int val1 = st.top();
                st.pop();
                st.push(operation(val1,val2,it));
            }

            else
            {
                st.push(stoi(it));
            }
        }  
        return st.top();  
    }

    
};