class MyStack {
  private:
  // we can only declare the member variables here
  vector<int> stackArr;
  int top;
  
  public:
    // we cant define variables without constructor
    MyStack()
    {
        stackArr.resize(100);
        top=-1;
    }
    
    void push(int x) {
        // code here
        top++;
        stackArr[top]=x;
    }

    int pop() {
        if(top==-1) return -1;
        else
        {
           int popped = stackArr[top]; 
           top--;
           return popped;
        }
    }
};