#include<bits/stdc++.h>
#include<iostream>
using namespace std;
// code for merge sort


void Merge(int low, int mid, int high,int array[], vector<int> &temp)
{
    temp.clear(); //clearing temporary vector...don't need to do this with array, in array we need to maintain a index variable.
    int left=low;
    int right = mid+1;

    // condition to compare each element in both LHS and RHS array
    while(left<=mid && right<=high)
    {
        if(array[left]<= array[right]) 
        {
            temp.push_back(array[left]);
            left++;
        }
        else 
        {
            temp.push_back(array[right]);
            right++;
        }        
    }

    // condition if only leftside array elements are left
    while(left<=mid)
    {
        temp.push_back(array[left]);
        left++;
    }

    // condition if only right array elements are left
    while(right<=high)
    {
        temp.push_back(array[right]);
        right++;
    }


    //for loop to store temp[] results into array[]
    for(int i=low; i<=high;i++) array[i] = temp[i-low];
}

void MergeSort(int low, int high, int array[], vector<int> &temp)
{
    if(low >= high) return;
    int mid = (low+high)/2;
    MergeSort(low,mid,array,temp);
    MergeSort(mid+1,high,array,temp);
    Merge(low,mid,high,array,temp);
}


int main()
{
    //take arraysize as input
    int arraysize;
    cin >> arraysize; 
    int array1[arraysize];
    vector<int> temp;

    //take input into the array
    for(int i=0;i<arraysize;i++) cin >> array1[i];

    //call the mergesort function
    MergeSort(0,arraysize-1,array1,temp);

    //print the sorted array
    for(int i=0;i<arraysize;i++)  cout << array1[i] << " ";

    return 0;
}