// Approach 2 with two pointer approach
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // this is returning whether yes/no question
        // we can apply two pointer approach
        
        int left = 0;
        int right = arr.size()-1;
        sort(arr.begin(), arr.end());
        while(left<=right)
        {
            int flag = arr[left] + arr[right];
            if(flag==target) return true;
            else if(flag<target) left++;
            else right--;
        }
        
        return false;
    }
};