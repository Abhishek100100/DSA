#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted sub-arrays of a given array.
// The sub-arrays are array[low...mid] and array[mid+1...high].
void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Create temporary arrays to hold the two halves
    int *left_array = (int*)malloc(n1 * sizeof(int));
    int *right_array = (int*)malloc(n2 * sizeof(int));

    // Copy data to the temporary arrays
    for (i = 0; i < n1; i++) {
        left_array[i] = arr[low + i];
    }
    for (j = 0; j < n2; j++) {
        right_array[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into the original array
    i = 0; // Initial index of the left sub-array
    j = 0; // Initial index of the right sub-array
    k = low; // Initial index of the merged sub-array

    while (i < n1 && j < n2) {
        if (left_array[i] <= right_array[j]) {
            arr[k] = left_array[i];
            i++;
        } else {
            arr[k] = right_array[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of the left sub-array
    while (i < n1) {
        arr[k] = left_array[i];
        i++;
        k++;
    }

    // Copy any remaining elements of the right sub-array
    while (j < n2) {
        arr[k] = right_array[j];
        j++;
        k++;
    }
    
    // Free the temporary arrays to prevent memory leaks
    free(left_array);
    free(right_array);
}

// The main function that implements Merge Sort.
// It recursively divides the array into two halves until each sub-array
// contains only one element, and then merges them back together.
void mergeSort(int arr[], int low, int high) {
    // Base case: if the sub-array has one or zero elements, it's already sorted
    if (low < high) {
        // Find the middle point
        int mid = low + (high - low) / 2;

        // Recursively sort the first half
        mergeSort(arr, low, mid);

        // Recursively sort the second half
        mergeSort(arr, mid + 1, high);

        // Merge the two sorted halves
        merge(arr, low, mid, high);
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
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, n);

    // Call the mergeSort function
    mergeSort(arr, 0, n - 1);

    printf("\nSorted array is \n");
    printArray(arr, n);

    return 0;
}