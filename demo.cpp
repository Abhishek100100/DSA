#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void Merge(int low, int mid, int high, int array[], vector<int> &temp) {
    temp.clear(); // Clearing temp vector
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (array[left] <= array[right]) {
            temp.push_back(array[left]);
            left++;
        } else {
            temp.push_back(array[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(array[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(array[right]);
        right++;
    }

    // Copying elements from temp back to array
    for (int i = low; i <= high; i++) {
        array[i] = temp[i - low];
    }
}

void MergeSort(int low, int high, int array[], vector<int> &temp) {
    if (low < high) { // Corrected condition
        int mid = (low + high) / 2;
        MergeSort(low, mid, array, temp);
        MergeSort(mid + 1, high, array, temp);
        Merge(low, mid, high, array, temp);
    }
}

int main() {
    int arraysize;
    cin >> arraysize;
    int array[arraysize];
    vector<int> temp;

    for (int i = 0; i < arraysize; i++) cin >> array[i];

    MergeSort(0, arraysize - 1, array, temp);

    for (int i = 0; i < arraysize; i++) cout << array[i] << " ";

    return 0;
}
