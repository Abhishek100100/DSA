class Solution {
public:
    bool canJump(vector<int>& nums) {
          int size = nums.size();
          int last_position = size-1;
          // can be solved with dp but greedy approach is simpler
          // stand at the last position and see if you can reach the end
          // by last-1 position

          //for loop from second last to 0
          for(int i=size-2;i>=0;i--)
          {
            if(i+nums[i]>=last_position)
            {
                last_position = i;
            }
          }
        return last_position==0;
    }
};