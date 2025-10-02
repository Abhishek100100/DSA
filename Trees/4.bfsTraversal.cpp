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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*> que;
        vector<vector<int>> ans; 
        vector<int> temp;
        if (root == nullptr) return ans;
        que.push(root);
        while(!que.empty())
        {
            int qsize = que.size();
            for(int i=0; i<qsize;i++)
            {
                TreeNode* node = que.front();
                que.pop();
                if(node->left!=NULL) que.push(node->left);
                if(node->right!=NULL) que.push(node->right);
                temp.push_back(node->val);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};