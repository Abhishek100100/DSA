// Leetcode Question 167: Two Sum II - Input Array Is Sorted
// This can be solved with two pointer approach
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 1 based indexing doesnt change the way we access, that's just for returning the answer
        int left = 0;
        int right = numbers.size()-1;

        while(left<=right)
        {
            int sum = numbers[left] + numbers[right];
            if(sum==target) return {left+1,right+1};
            else if(sum<target) left++;
            else right--;
        }

        return {left+1,right+1};
    }
};