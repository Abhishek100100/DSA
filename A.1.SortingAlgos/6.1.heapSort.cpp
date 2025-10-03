// Heap sort : using vector
// Youtube : https://www.youtube.com/watch?v=Q_eia3jC9Ts
// The time and space complexity of heap sort is O(n log n) and O(1) respectively.
// We take/convert the input array into usually an array or a binary heap ( which is ACBT) and then we repeatedly extract the maximum element from the heap and place it at the end of the array.
// the process of building heap is called heapify.

// for an array based representatuon, any element at index i has its left child at index 2*i + 1 and right child at index 2*i + 2 and its parent at index (i-1)/2.
// This is an inplace algorithm as it requires only a constant amount O(1) of additional storage space.


#include <iostream>
#include <vector>
#include <algorithm> // For swap
using namespace std;

// A utility function to print a vector
void display(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

// To heapify a subtree rooted with node i which is an index in arr[]
// n is the size of the heap
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // Left child
    int right = 2 * i + 2;    // Right child

    // This function is supposed to maintain heap property, it set's the current, left and right node and then checks if the left or right child is greater than the current node, 
    // if yes then it swaps the current node with the largest child and then recursively calls itself on the affected subtree.
    // the reason we check left,right <= n is to make sure that we don't go out of bounds of the array.

    // See if left child of root exists and is greater than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // See if right child of root exists and is greater than the largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Change root, if needed (yes basically if the largest is not the root)
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// The main function to sort an array of given size
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 1. Build a max-heap from the input array
    // the reason we start from n/2 - 1 is that all elements after that are leaf nodes and hence already satisfy the heap property
    // basicaly we start from the last non-leaf node and go up to the root node, which is rightmost node at a level just above the leaf nodes
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 2. One by one extract an element from heap | basically it is deleting the root node until the heap is empty and then placing the deleted nodes at the end of the array
    // once we have built a max-heap, the largest element is at the root of the heap (index 0).
    // make an array which is max heap, and then notice how it shrinks from end and grows from start
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> data = {12, 11, 13, 5, 6, 7};
    cout << "Original array: ";
    display(data);

    heapSort(data);

    cout << "Sorted array:   ";
    display(data);
    return 0;
}