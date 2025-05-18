// return the indices of the two numbers such that they add up to a specific target
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //coding up better solution for returning index
        map<int,int> mpp;
        int size = nums.size();
        int diff;

        for(int i=0;i<size;i++)
        {
            diff = target - nums[i];
            if(mpp.find(diff) != mpp.end()) return {mpp[diff],i};
            mpp[nums[i]]=i;
        }
        return {-1,-1};
    }
};



// 2nd version 
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