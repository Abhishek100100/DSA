#include <iostream>

using namespace std;

// A node structure for the Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

class BinarySearchTree {
private:
    Node* root; // Points to the root of the tree

    // Helper function to insert a node recursively
    Node* insert(Node* current, int value) {
        if (current == NULL) {
            return createNode(value);
        }

        if (value < current->data) {
            current->left = insert(current->left, value);
        } else if (value > current->data) {
            current->right = insert(current->right, value);
        }
        // If value is equal, do nothing to avoid duplicates
        return current;
    }

    // Helper function to search for a key recursively
    bool search(Node* current, int key) {
        if (current == NULL) {
            return false;
        }
        if (current->data == key) {
            return true;
        }
        if (key < current->data) {
            return search(current->left, key);
        }
        return search(current->right, key);
    }
    
    // Helper function to find the minimum value node in a subtree
    Node* findMin(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    // Helper function to delete a node recursively
    Node* deleteNode(Node* current, int key) {
        if (current == NULL) {
            return current;
        }

        // Find the node to be deleted
        if (key < current->data) {
            current->left = deleteNode(current->left, key);
        } else if (key > current->data) {
            current->right = deleteNode(current->right, key);
        } else {
            // Node with only one child or no child
            if (current->left == NULL) {
                Node* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == NULL) {
                Node* temp = current->left;
                delete current;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = findMin(current->right);
            current->data = temp->data;
            current->right = deleteNode(current->right, temp->data);
        }
        return current;
    }

    // Helper function for inorder traversal (Left, Root, Right)
    void inorder(Node* current) {
        if (current != NULL) {
            inorder(current->left);
            cout << current->data << " ";
            inorder(current->right);
        }
    }

    // Helper function for preorder traversal (Root, Left, Right)
    void preorder(Node* current) {
        if (current != NULL) {
            cout << current->data << " ";
            preorder(current->left);
            preorder(current->right);
        }
    }
    
    // Helper function for postorder traversal (Left, Right, Root)
    void postorder(Node* current) {
        if (current != NULL) {
            postorder(current->left);
            postorder(current->right);
            cout << current->data << " ";
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
    BinarySearchTree() {
        root = NULL;
    }

    // Public function to insert a value
    void insert(int value) {
        root = insert(root, value);
    }
    
    // Public function to search for a value
    bool search(int key) {
        return search(root, key);
    }
    
    // Public function to delete a value
    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    // Public function for inorder traversal
    void inorderTraversal() {
        cout << "Inorder (sorted):   ";
        inorder(root);
        cout << endl;
    }

    // Public function for preorder traversal
    void preorderTraversal() {
        cout << "Preorder:           ";
        preorder(root);
        cout << endl;
    }

    // Public function for postorder traversal
    void postorderTraversal() {
        cout << "Postorder:          ";
        postorder(root);
        cout << endl;
    }
    
    // Destructor
    ~BinarySearchTree() {
        deleteTree(root);
    }
};

int main() {
    BinarySearchTree bst;

    cout << "--- Inserting nodes ---" << endl;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "\n--- Tree Traversals ---" << endl;
    bst.inorderTraversal();
    bst.preorderTraversal();
    bst.postorderTraversal();

    cout << "\n--- Searching for a node ---" << endl;
    cout << "Is 40 in the tree? " << (bst.search(40) ? "Yes" : "No") << endl;
    cout << "Is 90 in the tree? " << (bst.search(90) ? "Yes" : "No") << endl;

    cout << "\n--- Deleting a leaf node (20) ---" << endl;
    bst.deleteNode(20);
    bst.inorderTraversal();
    
    cout << "\n--- Deleting a node with one child (70) ---" << endl;
    bst.deleteNode(70);
    bst.inorderTraversal();

    cout << "\n--- Deleting the root node (50) ---" << endl;
    bst.deleteNode(50);
    bst.inorderTraversal();

    return 0;
}
