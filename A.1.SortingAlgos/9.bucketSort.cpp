// Bucket Sort
// Similar to radix sort, the difference is that in radix sort we sort based on digits, whereas in bucket sort we distribute the elements into a number of buckets and then sort each bucket individually.
// The time complexity and space complexity of bucket sort is O(n + k) and O(n + k) respectively, where n is the number of elements in the input array and k is the number of buckets.
// NOTE: This implementation is designed for floating-point numbers in the range [0, 1).
// the elements are uniformly distributed over the interval, which simply means that the elements are spread out evenly across the range.

#include <iostream>
#include <vector>
#include <algorithm> // For sort
#include <cmath>     // For floor
using namespace std;

// A utility function to print the elements of a vector
void display(const vector<float>& nums) {
    for (float val : nums) {
        cout << val << " ";
    }
    cout << endl;
}

// Insertion sort function to sort individual buckets
void insertionSort(vector<float>& bucket) {
    for (size_t i = 1; i < bucket.size(); ++i) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to sort a vector of floats using bucket sort
void bucketSort(vector<float>& arr) {
    int n = arr.size();
    if (n <= 1) {
        return;
    }

    // 1) Create n empty buckets
    vector<vector<float>> buckets(n);

    // 2) Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = n * arr[i];
        // Ensure index is within bounds for value 1.0
        if (bucket_index >= n) {
            bucket_index = n - 1;
        }
        buckets[bucket_index].push_back(arr[i]);
    }

    // 3) Sort individual buckets using insertion sort
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i]);
    }

    // 4) Concatenate all buckets back into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (size_t j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

// Driver program to test above function
int main() {
    // Use std::vector instead of a C-style array
    vector<float> data = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    
    cout << "Original array: ";
    // Pass the vector directly to the display function
    display(data);

    // Pass the vector by reference to the bucketSort function
    bucketSort(data);

    cout << "Sorted array is: " ;
    display(data);

    return 0;
}
