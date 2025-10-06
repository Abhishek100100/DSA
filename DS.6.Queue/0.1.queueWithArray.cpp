#include <iostream>

using namespace std;

#define MAX_SIZE 100 // We are setting a maximum size for our queue

class Queue {
private:
    int arr[MAX_SIZE];
    int front; // Keeps track of the front of the queue
    int rear;  // Keeps track of the back of the queue

public:
    // Constructor to initialize the queue
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        // This condition checks for the circular nature of the queue
        return (front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1));
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to add an element to the queue (enqueue operation)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot add more elements." << endl;
            return;
        }

        if (isEmpty()) {
            front = 0; // If it's the first element
        }
        // Increment rear in a circular manner
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
        cout << value << " was enqueued." << endl;
    }

    // Function to remove an element from the queue (dequeue operation)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot remove from an empty queue." << endl;
            return;
        }
        
        int dequeued_value = arr[front];
        
        // If this was the last element in the queue
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            // Increment front in a circular manner
            front = (front + 1) % MAX_SIZE;
        }
        cout << dequeued_value << " was dequeued." << endl;
    }

    // Function to see the front element without removing it (peek operation)
    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty." << endl;
            return -1; // Returning -1 to indicate an error or empty queue
        }
        return arr[front];
    }

    // Function to display all the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Elements in queue are: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } else {
            // Handles the case where the queue has wrapped around
            for (int i = front; i < MAX_SIZE; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
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
