#include <iostream>

using namespace std;

// A node structure for the linked list
struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head; // Points to the head of the list

public:
    // Constructor to initialize the list
    SinglyLinkedList() {
        head = NULL; // List is initially empty
    }

    // Function to get the length of the list
    int getLength() {
        int count = 0;
        Node* current = head;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Function to search for a specific key
    bool searchNode(int key) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Function to add a node at the end of the list (append)
    void appendNode(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            cout << value << " appended as the head of the list." << endl;
            return;
        }

        Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
        cout << value << " appended to the list." << endl;
    }

    // Function to add a node at the beginning of the list (prepend)
    void prependNode(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << value << " prepended to the list." << endl;
    }

    // Function to insert a node after a given node's key
    void insertNodeAfter(int key, int value) {
        Node* current = head;
        while (current != NULL && current->data != key) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Node with key " << key << " not found." << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = current->next;
        current->next = newNode;
        cout << value << " inserted after " << key << "." << endl;
    }

    // Function to delete a node by its key
    void deleteNodeByKey(int key) {
        if (head == NULL) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        // If the head node itself holds the key
        if (temp != NULL && temp->data == key) {
            head = temp->next;
            delete temp;
            cout << key << " deleted from the list." << endl;
            return;
        }

        // Search for the key to be deleted
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        // If key was not present in the list
        if (temp == NULL) {
            cout << "Node with key " << key << " not found." << endl;
            return;
        }

        // Unlink the node from the linked list
        prev->next = temp->next;
        delete temp;
        cout << key << " deleted from the list." << endl;
    }

    // Function to delete a node at a given position (0-indexed)
    void deleteNodeByPosition(int position) {
        if (head == NULL) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }

        Node* temp = head;

        // If head needs to be removed
        if (position == 0) {
            head = temp->next;
            cout << "Node at position " << position << " (value " << temp->data << ") deleted." << endl;
            delete temp;
            return;
        }

        // Find previous node of the node to be deleted
        for (int i = 0; temp != NULL && i < position - 1; i++) {
            temp = temp->next;
        }

        // If position is more than number of nodes
        if (temp == NULL || temp->next == NULL) {
            cout << "Position " << position << " is out of bounds." << endl;
            return;
        }

        // Node temp->next is the node to be deleted
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        cout << "Node at position " << position << " (value " << nodeToDelete->data << ") deleted." << endl;
        delete nodeToDelete;
    }
    
    // Function to get the Nth node from the start (1-indexed)
    void getNthNodeFromStart(int n) {
        Node* current = head;
        int count = 1;
        while (current != NULL) {
            if (count == n) {
                cout << "The " << n << "th node from the start is: " << current->data << endl;
                return;
            }
            count++;
            current = current->next;
        }
        cout << "The list does not have a " << n << "th node." << endl;
    }

    // Function to get the Nth node from the end (1-indexed)
    void getNthNodeFromEnd(int n) {
        Node* main_ptr = head;
        Node* ref_ptr = head;

        int count = 0;
        if (head != NULL) {
            while (count < n) {
                if (ref_ptr == NULL) {
                    cout << n << " is greater than the number of nodes in the list." << endl;
                    return;
                }
                ref_ptr = ref_ptr->next;
                count++;
            }

            while (ref_ptr != NULL) {
                main_ptr = main_ptr->next;
                ref_ptr = ref_ptr->next;
            }
            cout << "The " << n << "th node from the end is: " << main_ptr->data << endl;
        }
    }


    // Function to display all the elements in the list
    void displayList() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }
        cout << "Elements in the list are: ";
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free all memory when the list is destroyed
    ~SinglyLinkedList() {
        Node* current = head;
        Node* nextNode;
        while (current != NULL) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

// Main function to run the program
int main() {
    SinglyLinkedList myList;

    cout << "--- Appending nodes ---" << endl;
    myList.appendNode(10);
    myList.appendNode(20);
    myList.appendNode(30);
    myList.appendNode(40);
    myList.appendNode(50);
    myList.displayList();

    cout << "\n--- Getting List Length ---" << endl;
    cout << "Length of the list is: " << myList.getLength() << endl;

    cout << "\n--- Searching for a node ---" << endl;
    cout << "Is 30 in the list? " << (myList.searchNode(30) ? "Yes" : "No") << endl;
    cout << "Is 99 in the list? " << (myList.searchNode(99) ? "Yes" : "No") << endl;

    cout << "\n--- Deleting a node by position ---" << endl;
    myList.deleteNodeByPosition(2); // Deletes 30
    myList.displayList();

    cout << "\n--- Getting Nth node from start ---" << endl;
    myList.getNthNodeFromStart(3); // Should be 40

    cout << "\n--- Getting Nth node from end ---" << endl;
    myList.getNthNodeFromEnd(2); // Should be 40
    
    return 0;
}

