#include <iostream>

using namespace std;

// A node structure for the linked list
struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front; // Points to the front of the queue
    Node* rear;  // Points to the back of the queue

public:
    // Constructor to initialize the queue
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Function to add an element to the queue (enqueue operation)
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        // If the queue is empty, the new node is both front and rear
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            // Add the new node at the end of the queue and change rear
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " was enqueued." << endl;
    }

    // Function to remove an element from the queue (dequeue operation)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot remove from an empty queue." << endl;
            return;
        }

        Node* temp = front;
        int dequeued_value = temp->data;

        // Move front one node ahead
        front = front->next;

        // If front becomes NULL, then change rear to NULL as well
        if (front == NULL) {
            rear = NULL;
        }

        delete temp; // Free the old front node
        cout << dequeued_value << " was dequeued." << endl;
    }

    // Function to see the front element without removing it (peek operation)
    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty." << endl;
            return -1; // Returning -1 to indicate an error or empty queue
        }
        return front->data;
    }

    // Function to display all the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Elements in queue are: ";
        Node* current = front;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    // Destructor to free all memory when the queue is destroyed
    ~Queue() {
        Node* current = front;
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
    Queue myQueue; // Creating a queue object

    cout << "--- Enqueuing elements into the queue ---" << endl;
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40);

    cout << "\n--- Displaying the queue ---" << endl;
    myQueue.display();

    cout << "\n--- Peeking the front element ---" << endl;
    cout << "Front element is: " << myQueue.peek() << endl;

    cout << "\n--- Dequeuing an element ---" << endl;
    myQueue.dequeue();

    cout << "\n--- Displaying the queue after dequeue ---" << endl;
    myQueue.display();
    
    cout << "\n--- Checking if queue is empty ---" << endl;
    if (myQueue.isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }

    cout << "\n--- Dequeuing all elements to show underflow ---" << endl;
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue(); // This will cause an underflow message

    return 0;
}
