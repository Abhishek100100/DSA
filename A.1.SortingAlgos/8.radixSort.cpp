// Radix sort aka bucket sort : using counting sort as a subroutine
// The time and space complexity of radix sort is O(d*(n + k)) and O(n + k) respectively, where d is the number of digits in the maximum number, n is the number of elements in the input array, and k is the range of the input (i.e., the difference between the maximum and minimum values).
// youtube : https://www.youtube.com/watch?v=Il45xNUHGp0
// This algorithm processes each digit of the numbers in the input array, starting from the least significant digit (LSD) to the most significant digit (MSD).
// For each digit, it uses a stable sorting algorithm (like counting sort) to sort the numbers based on that digit.
// here we go in passes, where passes is equal to the number of digits in the maximum number in the array.

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

// A utility function to get the maximum value in an array
int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// A function to perform counting sort on arr[] according to the digit represented by exp.
// exp is 10^i where i is the current digit number (0 for units, 1 for tens, etc.)
void countingSortForRadix(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // output array
    int count[10] = {0}; // count array for digits 0-9

    // 1. Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // 2. Change count[i] so that count[i] now contains the actual
    //    position of this digit in the output[] array
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 3. Build the output array
    // Start from the end to make the sort stable
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // 4. Copy the output array to arr[], so that arr[] now
    //    contains sorted numbers according to the current digit
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// The main function that implements Radix Sort
void radixSort(vector<int>& arr) {
    // Find the maximum number to know the number of digits
    int m = getMax(arr);

    // Do counting sort for every digit. Note that instead of passing the digit
    // number, exp is passed. exp is 10^i where i is the current digit number.
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countingSortForRadix(arr, exp);
    }
}

int main() {
    vector<int> data = {170, 45, 75, 90, 802, 24, 2, 66};
    cout << "Original array: ";
    display(data);

    radixSort(data);

    cout << "Sorted array:   ";
    display(data);

    return 0;
}