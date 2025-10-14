// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        int flr=-1;
        
        while(root)
        {
            if(root->data==x) return flr=root->data;
            else if(root->data> x) root=root->left;
            else
            {
                flr=root->data;
                root=root->right;
            }
        }
        return flr;
        
    }
};

