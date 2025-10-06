#include <iostream>

using namespace std;

// A node structure for the circular linked list
struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head; // Points to one of the nodes in the circle

public:
    // Constructor to initialize the list
    CircularLinkedList() {
        head = NULL;
    }

    // Function to insert a node at the end of the list
    void appendNode(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            newNode->next = head; // Points to itself
            cout << value << " appended as the head." << endl;
            return;
        }

        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        last->next = newNode;
        newNode->next = head;
        cout << value << " appended to the list." << endl;
    }

    // Function to insert a node at the beginning of the list
    void prependNode(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            cout << value << " prepended as the head." << endl;
            return;
        }

        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        newNode->next = head;
        last->next = newNode;
        head = newNode; // New node becomes the head
        cout << value << " prepended to the list." << endl;
    }

    // Function to delete a node by its key
    void deleteNodeByKey(int key) {
        if (head == NULL) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }

        Node* current = head;
        Node* prev = NULL;

        // Find the node with the key
        do {
            if (current->data == key) {
                break;
            }
            prev = current;
            current = current->next;
        } while (current != head);
        
        // If the node was not found
        if (current->data != key) {
             cout << "Node with key " << key << " not found." << endl;
             return;
        }

        // If the node is the only node in the list
        if (current->next == head && prev == NULL) {
            head = NULL;
            delete current;
            cout << key << " deleted. List is now empty." << endl;
            return;
        }

        // Find the last node to update its 'next' if head is deleted
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        // If the node to be deleted is the head node
        if (current == head) {
            last->next = head->next;
            head = head->next;
            delete current;
            cout << key << " (head) deleted from the list." << endl;
            return;
        }
        
        // For any other node
        prev->next = current->next;
        delete current;
        cout << key << " deleted from the list." << endl;
    }

    // Function to display all the elements in the list
    void displayList() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* current = head;
        cout << "List contents: ";
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        cout << "(back to head " << head->data << ")" << endl;
    }
    
    // Destructor to free all memory
    ~CircularLinkedList() {
        if (head == NULL) {
            return;
        }
        Node* current = head;
        Node* nextNode;
        
        // Break the circle to traverse like a normal list
        Node* last = head;
        while(last->next != head){
            last = last->next;
        }
        last->next = NULL;

        while(current != NULL) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

// Main function to run the program
int main() {
    CircularLinkedList myList;

    cout << "--- Appending nodes ---" << endl;
    myList.appendNode(10);
    myList.appendNode(20);
    myList.appendNode(30);
    myList.displayList();

    cout << "\n--- Prepending a node ---" << endl;
    myList.prependNode(5);
    myList.displayList();

    cout << "\n--- Deleting a middle node ---" << endl;
    myList.deleteNodeByKey(20);
    myList.displayList();

    cout << "\n--- Deleting the head node ---" << endl;
    myList.deleteNodeByKey(5);
    myList.displayList();

    cout << "\n--- Deleting remaining node ---" << endl;
    myList.deleteNodeByKey(30);
    myList.displayList();
    
    myList.deleteNodeByKey(10);
    myList.displayList();

    return 0;
}
