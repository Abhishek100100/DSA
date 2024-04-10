
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


struct Node 
{
    int data;        // Defining the value of the Node (integer data)
    struct Node* left;    // Reference pointer to the left child Node  
    struct Node* right;   //Reference pointer to the right child Node   

    // Constructor Method to initialize the Node with a value
    Node(int val) {
        data = val;   // Set the value of the Node to the passed integer
        left = right = NULL;  // Initialize left and right pointers as NULL
    }
};

// Function to print preorder traversal
void Preorder(struct Node* node)
{
    if (node == NULL) return;

    // Deal with the node
    cout << node->data << " ";

    // Recur on left subtree
    Preorder(node->left);

    // Recur on right subtree
    Preorder(node->right);
}

// Function to print Inorder traversal
void Inorder(struct Node* node)
{
    if (node == NULL) return;

    // Recur on left subtree
    Inorder(node->left);

    // Deal with the node
    cout << node->data << " ";

    // Recur on right subtree
    Inorder(node->right);
}

// Function to print Postorder traversal
void Postorder(struct Node* node)
{
    if (node == NULL) return;

    // Recur on left subtree
    Postorder(node->left);

    // Recur on right subtree
    Postorder(node->right);

    // Deal with the node
    cout << node->data << " ";
}


int main() {
   /*create root*/
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    //Print preorder traversal
    cout << "Preorder " ;
    Preorder(root);
    cout << endl;

    //Print Inorder traversal
    cout << "Inorder " ;
    Inorder(root);
    cout << endl;

    //print PostOrder traversal
    cout << "Postorder " ;
    Postorder(root);

    return 0;
}

                