/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        //Optimal way to solve the problem

        // base condition
        if(root==nullptr || root==p || root==q) return root;

        //here we are going both left and right and finding the node p and q
        TreeNode* ln = helper(root->left,p,q);
        TreeNode* rn = helper(root->right,p,q);

        // once we have both ln and rn of an root
        //if the ln is null but return rn (that could be both null or a node)
        if(ln==nullptr) return rn;
        // if the rn is null then return ln (that could be both null or a node)
        else if(rn==nullptr) return ln;
        // since both of them are not null, it means that's our LCA
        else return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if we find the node we will take the value and return it, else return null

        return helper(root,p,q);
    }
};