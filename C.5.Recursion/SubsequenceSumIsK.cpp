#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// index - input array's index from 0 to size/n
// size - input array size
// sum - required sum
// arrsum - function's local summation to compare with sum
// vecto - vector to store the subsequences
// arr[] - this is the input array.

void SubSequenceSum(int index, int size, int sum, int arrsum, vector<int> vecto, int arr[])
{
    if(index == size) 
    {
        if(arrsum==sum) 
        {
            for(auto it : vecto) cout << it << " ";
            cout << endl;
        }
        //if(vecto.size() == 0) cout << "{}";
        return;
    }

    vecto.push_back(arr[index]);
    arrsum = arrsum + arr[index];
    SubSequenceSum(index+1,size,sum, arrsum, vecto,arr);
    vecto.pop_back();    //learnt that popback doesnt need arguments
    arrsum = arrsum - arr[index];
    SubSequenceSum(index+1,size,sum,arrsum,vecto,arr); //we can put this line just after the if condition to print in reverse order.
    return;
}

int main()
{
    int n,sum;
    cin >> n;
    cin >> sum;
    int arr[n];
    vector<int> vecto;
    //fill array with input numbers
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    SubSequenceSum(0,n,sum,0,vecto,arr);   
    return 0;
}


