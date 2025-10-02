// Insertion sort
// it is an in-place comparison sorting algorithm with time and space complexity of O(n^2) and O(1) respectively.
// https://www.youtube.com/watch?v=8mJ-OhcfpYg
// the basic logic is to go over each element and compare it with the elements before it, and insert it in the correct position.
// real-life example : sorting playing cards in your hand

#include <iostream>
using namespace std;

void insertionSort(vector<int> &nums)
{
    int n = nums.size();
    int temp;

    for(int i=0;i<n;i++)
    {
        temp=nums[i];
        for(int j=i-1;j>=0;j--)
        {
            if(nums[j]>temp)
                nums[j+1]=nums[j];
            else
            {
                nums[j+1]=temp;
                break;
            }
            if(j==0)
                nums[0]=temp;
        }
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

    insertionSort(nums);
    
    cout << "Sorted array: ";
    display(nums);
    return 0;
}