// Function to search a node in BST.
class Solution {

  public:
  
    int helper(Node* root, int& x, int& flr)
    {
        if(root==nullptr) return flr;
        
        if(root->data==x) return flr=root->data;
        else if(root->data<x) 
        {
            flr=root->data;
            return helper(root->right,x,flr);
        }
        else
        {
            return helper(root->left,x,flr);
        }
    }
    
    int floor(Node* root, int x) {
        // Code here
        int flr=-1;
        return helper(root,x,flr);
        
    }
};

