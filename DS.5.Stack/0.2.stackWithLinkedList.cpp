#include <iostream>

using namespace std;

// A node structure for the linked list
struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top; // This will point to the top of the stack

public:
    // Constructor to initialize the stack
    Stack() {
        top = NULL; // Initialize top to NULL to indicate an empty stack
    }

    // Function to add an element to the stack (push operation)
    void push(int value) {
        Node* newNode = new Node(); // Create a new node
        newNode->data = value;      // Assign data to the new node
        newNode->next = top;        // Make the new node point to the old top
        top = newNode;              // The new node is now the top
        cout << value << " was pushed to the stack." << endl;
    }

    // Function to remove an element from the stack (pop operation)
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return;
        }
        Node* temp = top; // Create a temporary pointer to the top node
        int popped_value = temp->data;
        top = top->next; // Move top to the next node
        delete temp;     // Free the memory of the old top node
        cout << popped_value << " was popped from the stack." << endl;
    }

    // Function to see the top element without removing it (peek operation)
    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty." << endl;
            return -1; // Returning -1 to indicate an error or empty stack
        }
        return top->data;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return (top == NULL);
    }

    // Function to display all the elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Elements in stack are: ";
        Node* current = top;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    // Destructor to free all memory when the stack is destroyed
    ~Stack() {
        Node* current = top;
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
    Stack myStack; // Creating a stack object

    cout << "--- Pushing elements onto the stack ---" << endl;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);

    cout << "\n--- Displaying the stack ---" << endl;
    myStack.display();

    cout << "\n--- Peeking the top element ---" << endl;
    cout << "Top element is: " << myStack.peek() << endl;

    cout << "\n--- Popping an element ---" << endl;
    myStack.pop();

    cout << "\n--- Displaying the stack after pop ---" << endl;
    myStack.display();

    cout << "\n--- Checking if stack is empty ---" << endl;
    if (myStack.isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    cout << "\n--- Popping all elements to show underflow ---" << endl;
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop(); // This will cause an underflow message

    return 0;
}
