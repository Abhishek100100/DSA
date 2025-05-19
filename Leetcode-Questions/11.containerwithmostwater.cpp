class Solution {
public:
    int maxArea(vector<int>& height) {
        // This can be solved with two pointer and greedy approach

        // step 1 : initialise and declare variables
        int ans=0;
        int left = 0;
        int right = height.size()-1;

        // step 2 : traverse the height array and optimise the height
        while(left<=right)
        {
            int length = min(height[left], height[right]) ;
            int width = right - left;
            int volume = length * width; //standard area formula
            ans = max(ans, volume);
            
            // here is the logic to check which pointer to move next based on height
            if(height[left]>height[right]) right--;
            else left++;
        }

        return ans;
    }
};