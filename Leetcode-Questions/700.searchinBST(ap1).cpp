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
    TreeNode* helper(TreeNode* root, int& val)
    {
        // This solution uses auxiliary space : O(n) 
        if(root==NULL) return NULL;
        
        if(root->val==val) return root;
        else if(root->val<val) return helper(root->right,val);
        else return helper(root->left,val);
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return helper(root,val);
    }
};