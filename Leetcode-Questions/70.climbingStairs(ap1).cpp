 // Approach 1 : Recursive solution
class Solution {
private : 
    int f(int n)
    {
        //f(n) denotes no of ways to reach nth stair from step 0
        if(n==0) return 0; // it has reached the end
        if(n==1) return 1; // at the last step only climb 1 can be done
        if(n==2) return 2; // as at the last second step i can do 2x climb 1 or 1x climb 2

        int left = f(n-1);
        int right = f(n-2);
        return left+right;
    }

public:
    int climbStairs(int n) {
        // this can be solved using dp 
       
        return f(n);
    }
};