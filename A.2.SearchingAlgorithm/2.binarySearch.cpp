// Binary Search
// It is a search algorithm that finds the position of a target value within a sorted array.
// It works by repeatedly dividing the search interval in half.
// PREREQUISITE: The input array must be sorted.
// The time complexity is O(log n) and the space complexity is O(1) for the iterative version.

#include <iostream>
#include <vector>
using namespace std;

// A utility function to print the elements of a vector
void display(const vector<int>& nums) {
    for (int val : nums) {
        cout << val << " ";
    }
    cout << endl;
}

// Function to perform iterative binary search on a vector
// It returns the index of the target element if found, otherwise returns -1.
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    // Loop until the search space is exhausted
    while (left <= right) {
        // Calculate the middle index to avoid potential overflow
        int mid = left + (right - left) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If the target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If the target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // If the loop completes without finding the element, return -1
    return -1;
}

// Driver program to test above function
int main() {
    // NOTE: The data must be sorted for binary search to work correctly.
    vector<int> data = {6, 12, 22, 35, 43, 89, 91};
    int target = 89;

    cout << "Array to search in: ";
    display(data);

    // Call the binarySearch function
    int result = binarySearch(data, target);

    // Check the result and print the appropriate message
    if (result != -1) {
        cout << "Element " << target << " found at index: " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }
    
    // Example for an element not in the array
    target = 100;
    result = binarySearch(data, target);
    if (result != -1) {
        cout << "Element " << target << " found at index: " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
