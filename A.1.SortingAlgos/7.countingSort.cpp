// Counting sort : non-comparison based sorting algorithm
// The time and space complexity of counting sort is O(n + k) and O(k) respectively, where n is the number of elements in the input array and k is the range of the input values (i.e., the difference between the maximum and minimum values).

// It operates by counting the number of occurrences of each unique element in the input array. This count is then used to determine the correct position
// of each element in the sorted output array.
// NOTE: This implementation assumes that the input elements are non-negative integers.

#include <iostream>
#include <vector>
#include <algorithm> // For max_element
using namespace std;

// A utility function to print the elements of a vector
void display(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

// The main function that implements Counting Sort
void countingSort(vector<int>& arr) {
    int n = arr.size();
    // Base case: an array with 0 or 1 elements is already sorted
    if (n <= 1) {
        return;
    }

    // 1. Find the largest element in the array to determine the range.
    int max_val = *max_element(arr.begin(), arr.end());

    // 2. Create a 'count' array to store the frequency of each element.
    // Its size is max_val + 1, and it's initialized to all zeros.
    vector<int> count(max_val + 1, 0);

    // 3. Store the count of each element from the input array.
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // 4. Modify the 'count' array to store the cumulative sum of counts.
    // After this, count[i] will contain the actual position (index + 1)
    // of the element 'i' in the output array.
    for (int i = 1; i <= max_val; i++) {
        count[i] += count[i - 1];
    }

    // 5. Build the output array.
    // Create a temporary array to store the sorted elements.
    vector<int> output(n);
    // Iterate through the input array from the end to maintain stability.
    // If we iterate from the start, the sort will not be stable because of the way we are placing elements in the output array.
    // Stability means that two equal elements retain their relative order in the sorted output as they were
    for (int i = n - 1; i >= 0; i--) {
        // Place the element at its correct sorted position, it is count[arr[i]] - 1 because count array is 1-based index
        output[count[arr[i]] - 1] = arr[i];
        // Decrement the count for that element
        count[arr[i]]--;
    }

    // 6. Copy the sorted elements from the output array back to the original array.
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    vector<int> data = {4, 2, 2, 8, 3, 3, 1};
    cout << "Original array: ";
    display(data);

    countingSort(data);

    cout << "Sorted array:   ";
    display(data);

    return 0;
}