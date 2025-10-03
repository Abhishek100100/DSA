class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //Brute O(n^2) approach        
        int size = nums.size();
        vector<int> ans(size,0);

        for(int i=0;i<size;i++)
        {
            int product =1;
            for(int j=0;j<size;j++)
            {
                if(i!=j)
                { 
                    product=product*nums[j];
                }
            }
            ans[i]= (product);
        }
        return ans;
    }
};