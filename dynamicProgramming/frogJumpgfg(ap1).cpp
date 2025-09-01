class Solution {
  private : 
  int f(int n, vector<int>&height)
  {
      // the frog can jump 1 or 2 step
      if(n==0) return 0;
      int jumpOne = f(n-1, height) + abs(height[n]-height[n-1]);
      int jumpTwo = INT_MAX;
      if(n>1) jumpTwo = f(n-2, height) + abs(height[n]-height[n-2]);
      
      return min(jumpOne, jumpTwo);
  }
  
  public:
    int minCost(vector<int>& height) {
    
        // We can solve it using dynamic programming
        
        // Approach 1 : Recursive solution
        
        // let's say the stair number is from 0 to "height-1" ...so total "height" stairs
        // f(height-1) is the min energy to reach at the last step
        int n = height.size()-1;
        return f(n, height);
    }
};