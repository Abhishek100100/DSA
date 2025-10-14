/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  

    TreeNode* searchBST(TreeNode* root, int val) {
         // This solution uses auxiliary space : O(1) 
        TreeNode* temp = root;
        while(temp!=nullptr && temp->val!=val)
        {
           temp = val<temp->val ? temp->left : temp->right;
        }
        return temp;
    }
};