class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        // O(n) time complexity with two product array
        
        // Handle edge case for empty input
        if (n == 0) {
            return {};
        }

        // Initialize three vectors:
        // left_products[i] stores product of all elements to the left of nums[i]
        // right_products[i] stores product of all elements to the right of nums[i]
        // ans[i] stores the final result
        std::vector<int> left_products(n);
        std::vector<int> right_products(n);
        std::vector<int> ans(n);

        // Step 1: Populate left_products array
        // For the first element, there's nothing to its left, so product is 1
        left_products[0] = 1;
        for (int i = 1; i < n; ++i) {
            left_products[i] = left_products[i - 1] * nums[i - 1];
        }

        // Step 2: Populate right_products array
        // For the last element, there's nothing to its right, so product is 1
        right_products[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            right_products[i] = right_products[i + 1] * nums[i + 1];
        }

        // Step 3: Populate the final answer array
        // ans[i] = (product of elements to the left of i) * (product of elements to the right of i)
        for (int i = 0; i < n; ++i) {
            ans[i] = left_products[i] * right_products[i];
        }

        return ans;
    }
};
