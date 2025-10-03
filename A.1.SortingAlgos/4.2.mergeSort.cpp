// Merge Sort
// it is a divide and conquer algorithm that divides the input array into two halves, calls itself
// time and space complexity of O(n log n) and O(n) respectively.

#include <iostream>
#include <vector>
using namespace std;

// Helper function to merge two sorted sub-arrays
// The two sub-arrays are array[low...mid] and array[mid+1...high]
void merge(int low, int mid, int high, vector<int>& nums) {
    // Create a temporary vector to store the merged results
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // Compare elements from both halves and add the smaller one to the temp vector
    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        } else {
            temp.push_back(nums[right]);
            right++;
        }
    }

    // Copy any remaining elements from the left sub-array
    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }

    // Copy any remaining elements from the right sub-array
    while (right <= high) {
        temp.push_back(nums[right]);
        right++;
    }

    // Copy the elements from the temporary vector back to the original array
    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
}

// The main function that implements Merge Sort using recursion
// It divides the array into two halves, calls itself for each half,
// and then merges the two sorted halves.
void mergeSort(int low, int high, vector<int>& nums) {
    // Base case: if the sub-array has one or zero elements, it's already sorted
    if (low >= high) {
        return;
    }
    
    // Find the middle point of the array
    int mid = low + (high - low) / 2;
    
    // Recursively sort the left half
    mergeSort(low, mid, nums);
    
    // Recursively sort the right half
    mergeSort(mid + 1, high, nums);
    
    // Merge the two sorted halves
    merge(low, mid, high, nums);
}

// Function to print the elements of a vector
void display(const vector<int>& nums) {
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> data = {10, 7, 8, 9, 1, 5};
    int n = data.size();

    cout << "Original array: ";
    display(data);

    // Call the MergeSort function to sort the array
    mergeSort(0, n - 1, data);

    cout << "Sorted array: ";
    display(data);

    return 0;
}