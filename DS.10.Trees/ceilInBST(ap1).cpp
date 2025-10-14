class Solution {
  public:
  
    int helper(Node* root, int& x, int& ceil)
    {
        if(root==nullptr) return ceil;
        
      
        if(root->data==x)  return ceil=root->data;
        
        else if(root->data<x)
        {
            return helper(root->right,x,ceil);
        }
        
        else
        {
            ceil = root->data;
            return helper(root->left,x,ceil);
        }
        
        return ceil;
    }
  
    int findCeil(Node* root, int x) {
        // code here
        int ceil=-1;
        return helper(root, x , ceil);
    }
};
