// Bubble Sort
// it is an in-place sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.
// time and space complexity of O(n^2) and O(1) respectively.
// real-life example : stack of books where heavier books sink to the bottom
#include <iostream>
using namespace std;

void bubbleSort(int nums[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (nums[j] > nums[j + 1]) {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

void display( int nums[], int n)
{
    for (int i = 0; i < n; i++) 
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    
    int nums[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(nums) / sizeof(nums[0]);
    
    printf("Unsorted array: \n");
    display(nums, n);

    bubbleSort(nums, n);
    
    printf("Sorted array: \n");
    display(nums, n);
    
    return 0;
}
