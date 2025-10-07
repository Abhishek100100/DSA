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
    void inorder(TreeNode* root, int &k, int &answer)
    {
        if(root==nullptr || k<=0 ) return;
        
        inorder(root->left,k,answer);
        if(k>0)
        {
            k--;
            if(k==0) 
            {
                answer=root->val;
                return;
            }
            inorder(root->right, k, answer);
        }
      
    }
    int kthSmallest(TreeNode* root, int k) {
        // there are 3-4 ways to do it 
        // 1. do traversal , sort the array, then return the kth element from start
        //2. do inorder traversal, as the inorder of BST is always sorted, then return k
        //3 . do step 2, just that maintain a count...when count==k return the value and no need for further traversal
        int answer=0;
        inorder(root,k,answer);
        return answer;

    }
};