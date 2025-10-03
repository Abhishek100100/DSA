// Linear Search
// It is a sequential search algorithm that starts at one end and goes through each element of a
// list until the desired element is found; otherwise, the search continues till the end of the data set.
// The time complexity is O(n) in the worst case (element is at the end or not present) and the
// space complexity is O(1) as it requires no extra space.

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

// Function to perform linear search on a vector
// It returns the index of the target element if found, otherwise returns -1.
int linearSearch(const vector<int>& arr, int target) {
    int n = arr.size();
    // Iterate through each element of the array
    for (int i = 0; i < n; i++) {
        // If the current element matches the target, return its index
        if (arr[i] == target) {
            return i;
        }
    }
    // If the loop completes without finding the element, return -1
    return -1;
}

// Driver program to test above function
int main() {
    vector<int> data = {22, 35, 12, 6, 89, 43, 91};
    int target = 89;

    cout << "Array to search in: ";
    display(data);

    // Call the linearSearch function
    int result = linearSearch(data, target);

    // Check the result and print the appropriate message
    if (result != -1) {
        cout << "Element " << target << " found at index: " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }
    
    // Example for an element not in the array
    target = 100;
    result = linearSearch(data, target);
    if (result != -1) {
        cout << "Element " << target << " found at index: " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
