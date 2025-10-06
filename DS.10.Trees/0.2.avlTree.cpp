#include <iostream>
#include <algorithm> // For std::max

using namespace std;

// A node structure for the AVL Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

class AvlTree {
private:
    Node* root;

    // Helper function to get the height of a node
    int getHeight(Node* n) {
        if (n == NULL)
            return 0;
        return n->height;
    }

    // Helper function to get the balance factor of a node
    int getBalanceFactor(Node* n) {
        if (n == NULL)
            return 0;
        return getHeight(n->left) - getHeight(n->right);
    }

    // Function to create a new node
    Node* createNode(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        newNode->height = 1; // New node is initially at a leaf
        return newNode;
    }

    // Right rotate subtree rooted with y
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        // Return new root
        return x;
    }

    // Left rotate subtree rooted with x
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        // Return new root
        return y;
    }
    
    // Helper function to insert a node recursively and balance the tree
    Node* insert(Node* node, int value) {
        // 1. Perform standard BST insertion
        if (node == NULL)
            return createNode(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else // Equal keys are not allowed in BST
            return node;

        // 2. Update height of this ancestor node
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // 3. Get the balance factor of this ancestor node
        int balance = getBalanceFactor(node);

        // 4. If the node becomes unbalanced, there are 4 cases

        // Left Left Case
        if (balance > 1 && value < node->left->data)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && value > node->right->data)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // return the (unchanged) node pointer
        return node;
    }
    
    // Helper function to find the minimum value node in a subtree
    Node* findMin(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    // Helper function to delete a node recursively and balance the tree
    Node* deleteNode(Node* root, int key) {
        // 1. Standard BST delete
        if (root == NULL)
            return root;

        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else {
            // node with only one child or no child
            if ((root->left == NULL) || (root->right == NULL)) {
                Node* temp = root->left ? root->left : root->right;
                if (temp == NULL) { // No child case
                    temp = root;
                    root = NULL;
                } else { // One child case
                    *root = *temp; 
                }
                delete temp;
            } else {
                // node with two children
                Node* temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        if (root == NULL)
            return root;

        // 2. Update height
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // 3. Get balance factor
        int balance = getBalanceFactor(root);

        // 4. Rebalance if needed
        // Left Left Case
        if (balance > 1 && getBalanceFactor(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && getBalanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalanceFactor(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 && getBalanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }


    // Helper function for preorder traversal (Root, Left, Right)
    void preorder(Node* current) {
        if (current != NULL) {
            cout << current->data << " ";
            preorder(current->left);
            preorder(current->right);
        }
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
    AvlTree() {
        root = NULL;
    }

    // Public function to insert a value
    void insert(int value) {
        root = insert(root, value);
    }
    
    // Public function to delete a value
    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    // Public function for preorder traversal
    void preorderTraversal() {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }
    
    // Destructor
    ~AvlTree() {
        deleteTree(root);
    }
};

int main() {
    AvlTree avl;

    cout << "--- Inserting nodes (demonstrates balancing) ---" << endl;
    // This sequence would unbalance a regular BST
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    cout << "Preorder traversal of the constructed AVL tree is" << endl;
    avl.preorderTraversal();
    
    cout << "\n--- Deleting a node (40) ---" << endl;
    avl.deleteNode(40);
    cout << "Preorder traversal after deletion of 40" << endl;
    avl.preorderTraversal();

    return 0;
}
