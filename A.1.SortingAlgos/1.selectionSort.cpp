// Selection sort :
// it is an in-place comparison sorting algorithm with time and space complexity of O(n^2) and O(1) respectively.
// the basic logic is to pick each element, and then go over the array to find the smallest element and swap it with the picked element.
// real-life example : sorting playing cards in your hand

#include <bits/stdc++.h> // for including all standard libraries
#include<iostream>
using namespace std;

void selectionSort(vector<int> &nums)
{
  int n = nums.size();
  int current=0;

  for(int i=0; i<n-1; i++)
  {
    current = i;
    for(int j=i+1; j<n; j++)
    {
      if(nums[j]<nums[current])
        current = j;
    }
    swap(nums[i], nums[current]);
  }
}

void display(vector<int> &nums)
{
    for (auto x : nums)
        cout << x << " ";
    cout << endl;
}

int main()
{
    vector<int> nums = {64, 25, 12, 22, 11};
    
    cout << "Original array: ";
    display(nums);

    selectionSort(nums);
    
    cout << "Sorted array: ";
    display(nums);
    return 0;
}
