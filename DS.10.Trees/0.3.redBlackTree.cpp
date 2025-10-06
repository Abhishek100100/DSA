#include <iostream>

using namespace std;

// Enum for node colors
enum Color { RED, BLACK };

// A node structure for the Red-Black Tree
struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    // Constructor for a new node
    Node(int data) : data(data) {
        parent = left = right = NULL;
        // New nodes are initially RED
        color = RED;
    }
};

class RedBlackTree {
private:
    Node* root;

protected:
    // Helper function for left rotation
    void rotateLeft(Node *&pt) {
        Node *pt_right = pt->right;
        pt->right = pt_right->left;

        if (pt->right != NULL)
            pt->right->parent = pt;

        pt_right->parent = pt->parent;

        if (pt->parent == NULL)
            root = pt_right;
        else if (pt == pt->parent->left)
            pt->parent->left = pt_right;
        else
            pt->parent->right = pt_right;

        pt_right->left = pt;
        pt->parent = pt_right;
    }

    // Helper function for right rotation
    void rotateRight(Node *&pt) {
        Node *pt_left = pt->left;
        pt->left = pt_left->right;

        if (pt->left != NULL)
            pt->left->parent = pt;

        pt_left->parent = pt->parent;

        if (pt->parent == NULL)
            root = pt_left;
        else if (pt == pt->parent->left)
            pt->parent->left = pt_left;
        else
            pt->parent->right = pt_left;

        pt_left->right = pt;
        pt->parent = pt_left;
    }

    // Fixes violations caused by insertion
    void fixInsertRBTree(Node *&pt) {
        Node *parent_pt = NULL;
        Node *grand_parent_pt = NULL;

        while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
            parent_pt = pt->parent;
            grand_parent_pt = pt->parent->parent;

            // Case A: Parent of pt is left child of Grand-parent of pt
            if (parent_pt == grand_parent_pt->left) {
                Node *uncle_pt = grand_parent_pt->right;

                // Case 1: The uncle of pt is also red -> only recoloring required
                if (uncle_pt != NULL && uncle_pt->color == RED) {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                } else {
                    // Case 2: pt is right child of its parent -> left-rotation required
                    if (pt == parent_pt->right) {
                        rotateLeft(parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }
                    // Case 3: pt is left child of its parent -> right-rotation required
                    rotateRight(grand_parent_pt);
                    swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
            // Case B: Parent of pt is right child of Grand-parent of pt
            else {
                Node *uncle_pt = grand_parent_pt->left;
                // Case 1: The uncle of pt is also red -> only recoloring required
                if ((uncle_pt != NULL) && (uncle_pt->color == RED)) {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                } else {
                    // Case 2: pt is left child of its parent -> right-rotation required
                    if (pt == parent_pt->left) {
                        rotateRight(parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }
                    // Case 3: pt is right child of its parent -> left-rotation required
                    rotateLeft(grand_parent_pt);
                    swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
        }
        root->color = BLACK;
    }

    // Helper function for inorder traversal
    void inorder(Node* node) {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    
    // Helper function to delete the entire tree
    void deleteTree(Node* node) {
        if (node == NULL) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    // Constructor
    RedBlackTree() { root = NULL; }

    // Public function to insert a value
    void insert(const int &data) {
        Node *pt = new Node(data);
        // Do a normal BST insert
        root = bstInsert(root, pt);
        // Fix Red Black Tree violations
        fixInsertRBTree(pt);
    }

    // Standard BST insert function
    Node* bstInsert(Node* root, Node* pt) {
        if (root == NULL)
            return pt;

        if (pt->data < root->data) {
            root->left = bstInsert(root->left, pt);
            root->left->parent = root;
        } else if (pt->data > root->data) {
            root->right = bstInsert(root->right, pt);
            root->right->parent = root;
        }
        return root;
    }
    
    // Public function for inorder traversal
    void inorderTraversal() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    // Destructor
    ~RedBlackTree() {
        deleteTree(root);
    }
};

int main() {
    RedBlackTree tree;

    cout << "--- Inserting nodes ---" << endl;
    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);

    cout << "Inorder Traversal of Created Tree" << endl;
    tree.inorderTraversal();

    return 0;
}
