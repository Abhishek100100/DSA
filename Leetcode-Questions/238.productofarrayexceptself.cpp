// 3/3 solution :  This solves the problem in O(n) time and O(1) space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //Optimal O(1) approach
        vector<int> output; // for returning answer
        int product=1;
        int n = nums.size();

        // step 1 : form the left product array
        if(n<1) return output;
        for(auto it : nums) 
        {
            product *= it;
            output.push_back(product); //our left array is populated now
        }

        // step 2 : since we are not forming right array, we will do inplace computation for final output
        // we have to traverse output array from back to second index and do changes
        product =1;
        for(int i=n-1;i>0;i--)
        {
            output[i]= output[i-1] * product;
            product *= nums[i];
        }
        output[0] = product;

        return output;
    }
};