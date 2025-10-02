#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// This function takes the last element as the pivot, places the pivot element at its
// correct sorted position, and places all smaller elements to the left of the pivot
// and all greater elements to the right.
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = (low - 1);     // Initialize the index of the smaller element

    // Iterate through the array from the starting index `low` up to the pivot (high-1)
    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // Increment the index of the smaller element
            swap(&arr[i], &arr[j]); // Swap the smaller element with the element at index i
        }
    }
    // After the loop, swap the pivot element with the element at index i + 1.
    // This places the pivot in its correct sorted position.
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); // Return the partitioning index
}

// The main function that implements the Quick Sort algorithm.
// It uses a recursive approach to divide the array into smaller sub-arrays
// and then sort them.
void quickSort(int arr[], int low, int high) {
    // Base case: if the low index is less than the high index,
    // a valid sub-array exists and needs to be partitioned.
    if (low < high) {
        // `pi` is the partitioning index, arr[pi] is now in its sorted position
        int pi = partition(arr, low, high);

        // Recursively sort the sub-array on the left of the pivot
        quickSort(arr, low, pi - 1);
        
        // Recursively sort the sub-array on the right of the pivot
        quickSort(arr, pi + 1, high);
    }
}

// Utility function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    // Call the QuickSort function to sort the array
    quickSort(arr, 0, n - 1);

    printf("\nSorted array: \n");
    printArray(arr, n);

    return 0;
}
