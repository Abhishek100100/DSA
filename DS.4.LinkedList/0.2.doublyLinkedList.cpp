#include <iostream>

using namespace std;

// A node structure for the doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head; // Points to the head of the list

public:
    // Constructor to initialize the list
    DoublyLinkedList() {
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
            newNode->prev = NULL;
            head = newNode;
            cout << value << " appended as the head of the list." << endl;
            return;
        }

        Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
        cout << value << " appended to the list." << endl;
    }

    // Function to add a node at the beginning of the list (prepend)
    void prependNode(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }
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
        newNode->prev = current;
        if (newNode->next != NULL) {
            newNode->next->prev = newNode;
        }
        cout << value << " inserted after " << key << "." << endl;
    }

    // Function to delete a node by its key
    void deleteNodeByKey(int key) {
        if (head == NULL) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }

        Node* current = head;
        // Find the node to be deleted
        while (current != NULL && current->data != key) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Node with key " << key << " not found." << endl;
            return;
        }

        // If node to be deleted is head node
        if (current == head) {
            head = current->next;
        }
        
        // Change next only if node to be deleted is NOT the last node
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }

        // Change prev only if node to be deleted is NOT the first node
        if (current->prev != NULL) {
            current->prev->next = current->next;
        }

        delete current;
        cout << key << " deleted from the list." << endl;
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

    // Function to display all the elements in the list from the front
    void displayList() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }
        cout << "Elements in foward order: NULL <- ";
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
    
    // Function to display all elements in reverse order
    void displayListReverse() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }
        // Go to the last node
        Node* last = head;
        while(last->next != NULL) {
            last = last->next;
        }
        
        cout << "Elements in reverse order: NULL <- ";
        while(last != NULL) {
            cout << last->data << " <-> ";
            last = last->prev;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free all memory when the list is destroyed
    ~DoublyLinkedList() {
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
    DoublyLinkedList myList;

    cout << "--- Appending nodes ---" << endl;
    myList.appendNode(10);
    myList.appendNode(20);
    myList.appendNode(30);
    myList.appendNode(40);
    myList.displayList();

    cout << "\n--- Displaying list in reverse ---" << endl;
    myList.displayListReverse();
    
    cout << "\n--- Prepending a node ---" << endl;
    myList.prependNode(5);
    myList.displayList();

    cout << "\n--- Inserting a node ---" << endl;
    myList.insertNodeAfter(20, 25);
    myList.displayList();

    cout << "\n--- Deleting a node by key ---" << endl;
    myList.deleteNodeByKey(30);
    myList.displayList();
    
    cout << "\n--- Getting Nth node from start ---" << endl;
    myList.getNthNodeFromStart(4);

    cout << "\n--- Displaying final list in reverse ---" << endl;
    myList.displayListReverse();
    
    return 0;
}
