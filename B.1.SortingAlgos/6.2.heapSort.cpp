// Heap sort : using binary heap
// The time and space complexity of binary heap based heap sort is O(n log n) and O(n) respectively.
// We take/convert the input array into usually an array or a binary heap ( which is ACBT) and then we repeatedly extract the maximum element from the heap and place it at the end of the array.
// the process of building heap is called heapify.

// for an binary heap based representation, any element has its left child and right child and parent as per the binary tree structure.
// if follows two properties:
// 1. Shape property: It is a complete binary tree. This means that all levels of the tree are fully filled except possibly for the last level, which is filled from left to right.
// 2. Heap property: In a max heap, for any given node, the value of the node is greater than or equal to the values of its children. In a min heap, the value of the node is less than or equal to the values of its children.
// this is not an inplace algorithm as it requires O(n) space for storing the heap.


#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm> // For swap
using namespace std;

// A class for a max-heap implemented using a vector
class MaxHeap {
private:
    vector<int> heap;

    // Helper function to get the parent index
    int parent(int i) { return (i - 1) / 2; }

    // Helper function to get the left child index
    int leftChild(int i) { return 2 * i + 1; }

    // Helper function to get the right child index
    int rightChild(int i) { return 2 * i + 2; }

    // Moves a node up the tree to maintain the heap property (for insertion)
    void siftUp(int i) {
        // While the node is not the root and is greater than its parent, swap them
        while (i > 0 && heap[i] > heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i); // Move up to the parent's index
        }
    }

    // Moves a node down the tree to maintain the heap property (for extraction)
    // This is the same logic as the heapify function in Heap Sort
    void siftDown(int i) {
        int maxIndex = i;
        int l = leftChild(i);
        int r = rightChild(i);
        int size = heap.size();

        // Check if left child exists and is greater than the current max
        if (l < size && heap[l] > heap[maxIndex]) {
            maxIndex = l;
        }

        // Check if right child exists and is greater than the current max
        if (r < size && heap[r] > heap[maxIndex]) {
            maxIndex = r;
        }

        // If the current node is not the largest, swap it and continue sifting down
        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            siftDown(maxIndex);
        }
    }

public:
    // Insert a new value into the heap
    void insert(int value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    // Remove and return the maximum element (the root)
    int extractMax() {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }
        int result = heap[0];
        // Move the last element to the root
        heap[0] = heap.back();
        heap.pop_back();
        // Restore the heap property by sifting the new root down
        if (!heap.empty()) {
            siftDown(0);
        }
        return result;
    }

    // Get the maximum element without removing it
    int getMax() {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }
        return heap[0];
    }
    
    // Check if the heap is empty
    bool isEmpty() {
        return heap.empty();
    }
    
    // Print the heap contents
    void printHeap() {
        for(int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap heap;
    cout << "Inserting 10, 20, 15, 30, 5..." << endl;
    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.insert(30);
    heap.insert(5);

    cout << "Heap state: ";
    heap.printHeap(); // Expected: 30 20 15 10 5 (or similar heap order)

    cout << "Extracted max: " << heap.extractMax() << endl; // Should be 30
    cout << "Heap state after extraction: ";
    heap.printHeap();

    cout << "Current max: " << heap.getMax() << endl; // Should be 20

    return 0;
}
