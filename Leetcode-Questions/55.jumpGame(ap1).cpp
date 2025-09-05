class Solution {
public:
    bool canJump(vector<int>& nums) {
          int size = nums.size();
          // greedy approach
          // see i can maintain a variable max index, if is ever goes >= last index
          // then we can reach the end
          
          int maxIndex=0;
          for(int i=0;i<size;i++)
          {
             if(i>maxIndex) return false;
             maxIndex= max(maxIndex, i+nums[i]);
          }
          return true;
    }
};