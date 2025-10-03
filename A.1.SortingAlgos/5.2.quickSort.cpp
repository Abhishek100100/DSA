// QuickSort Algorithm in C++
// Time and space complexity of O(n log n) and O(log n) respectively.
// It is an in-place comparison sorting algorithm.
// So the logic is to pick an element as pivot and then place it at an position such that all elements smaller than the pivot are on the left and all elements greater than the pivot are on the right.
// Youtube : https://www.youtube.com/watch?v=Vtckgz38QHs
#include <iostream>
#include <vector>
using namespace std;
    
// Function to print the elements of a vector
void display(const vector<int>& nums) {
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;
}

// This function takes the last element as pivot, places the pivot element at its
// correct position in the sorted array, and places all smaller elements to the left
// and all greater elements to the right of the pivot.
int partition(vector<int>& arr, int low, int high) {
    // Choosing the last element as the pivot
    int pivot = arr[high];
    
    // Index of the smaller element
    int i = (low - 1);

    // Iterate through the array from the lowest index to the highest
    // basically if the element at j is smaller than pivot then increment i and swap arr[i] and arr[j]
    // else just move j to the next element
    // and at last when j reaches the end swap arr[i+1] and arr[high] (or pivot) 
    for (int j = low; j < high; j++) {
        // If the current element is smaller than the pivot
        if (arr[j] < pivot) {
            // Increment index of smaller element
            i++;
            // Swap the smaller element with the element at index i
            swap(arr[i], arr[j]);
        }
    }
    // Swap the pivot element with the element at index i + 1
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// The main function that implements QuickSort
// low is the starting index, and high is the ending index of the array to be sorted
void quickSort(vector<int>& arr, int low, int high) {
    // Base case: if the low index is greater than or equal to the high index,
    // the sub-array is already sorted or has one element.
    if (low < high) {
        // pi is the partitioning index, arr[pi] is now at the right place
        int pi = partition(arr, low, high);

        // Recursively sort the sub-arrays on the left and right of the pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Example vector to be sorted
    vector<int> data = {10, 7, 8, 9, 1, 5};
    int n = data.size();
    
    cout << "Original array: ";
    display(data);
    
    // Call the QuickSort function
    quickSort(data, 0, n - 1);
    
    cout << "Sorted array: ";
    display(data);
    
    return 0;
}
