#include <iostream>

using namespace std;

#define MAX_SIZE 100 // We are setting a maximum size for our stack

class Stack {
private:
    int top; // This will keep track of the top element
    int arr[MAX_SIZE]; // This is the array we'll use for our stack

public:
    // Constructor to initialize the stack
    Stack() {
        top = -1; // We set top to -1 to indicate the stack is empty initially
    }

    // Function to add an element to the stack (push operation)
    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow! Cannot push more elements." << endl;
            return;
        }
        // Increment top, then add the element
        top++;
        arr[top] = value;
        cout << value << " was pushed to the stack." << endl;
    }

    // Function to remove an element from the stack (pop operation)
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return;
        }
        // Just decrement top, the value is technically still there but will be overwritten
        int popped_value = arr[top];
        top--;
        cout << popped_value << " was popped from the stack." << endl;
    }

    // Function to see the top element without removing it (peek operation)
    int peek() {
        if (top < 0) {
            cout << "Stack is Empty." << endl;
            return -1; // Returning -1 to indicate an error or empty stack
        }
        return arr[top];
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return (top < 0);
    }

    // Function to display all the elements in the stack
    void display() {
        if (top < 0) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Elements in stack are: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
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
