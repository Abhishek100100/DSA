// there are two approaches to solve this problem
// approach 1 takes O(2n) space complexity
// approach 2 takes O(n) space complexity 

// Approach 1 Solution
class MinStack {
public:
    stack<pair<int,int>> st;
    int mini = INT_MAX;

    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()) st.push({val,val});
        else
        {
          int mini = min(val,st.top().second);
          st.push({val,mini});
        }
        
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */