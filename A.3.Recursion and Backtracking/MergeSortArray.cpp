#include<bits/stdc++.h>
#include<iostream>
using namespace std;
// code for merge sort that takes array as temporary data structure instead of vector


void Merge(int low, int mid, int high,int array[], int temp[])
{
    int index=0;
    int left=low;
    int right = mid+1;

    // condition to compare each element in both LHS and RHS array
    while(left<=mid && right<=high)
    {
        if(array[left]<= array[right]) 
        {
            temp[index]=array[left];
            index++;
            left++;
        }
        else 
        {
            temp[index] = array[right];
            index++;
            right++;
        }        
    }

    // condition if only leftside array elements are left
    while(left<=mid)
    {
        temp[index] = array[left];
        index++;
        left++;
    }

    // condition if only right array elements are left
    while(right<=high)
    {
        temp[index] = array[right];
        index++;
        right++;
    }


    //for loop to store temp[] results into array[]
    for(int i=low; i<=high;i++) array[i] = temp[i-low];
}

void MergeSort(int low, int high, int array[], int temp[])
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
    int array[arraysize];
    int temp[arraysize];

    //take input into the array
    for(int i=0;i<arraysize;i++) cin >> array[i];

    //call the mergesort function
    MergeSort(0,arraysize-1,array,temp);

    //print the sorted array
    for(int i=0;i<arraysize;i++)  cout << array[i] << " ";

    return 0;
}