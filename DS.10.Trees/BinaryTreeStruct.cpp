
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Method 1 :  Structure definition for a Node in a binary tree
struct Node {
    int data;        // Defining the value of the Node (integer data)
    struct Node* left;    // Reference pointer to the left child Node  
    struct Node* right;   //Reference pointer to the right child Node   

    // Constructor Method to initialize the Node with a value
    Node(int val) {
        data = val;   // Set the value of the Node to the passed integer
        left = right = NULL;  // Initialize left and right pointers as NULL
    }
};



int main() {
   /*create root*/
    Node* root = new Node(1);
 
    /* following is the tree after above statement
    1
    / \
    NULL NULL
    */
    root->left = new Node(2);
    root->right = new Node(3);
 
    /* 2 and 3 become left and right children of 1
       1
      / \
     2   3
    / \ / \
    NULL NULL NULL NULL
    */
    root->left->left = new Node(4);
    /* 4 becomes left child of 2
         1
       /   \
      2     3
     / \    / \
    4 NULL NULL NULL
    /   \
    NULL NULL
    */
    return 0;
}

                