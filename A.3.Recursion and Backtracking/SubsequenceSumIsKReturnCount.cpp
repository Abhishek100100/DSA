#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// index - input array's index from 0 to size/n
// size - input array size
// sum - required sum
// arrsum - function's local summation to compare with sum
// vecto - vector to store the subsequences | We are NOT taking vector since we do not want to store the subsequence to be printed we just need the count
// arr[] - this is the input array.

int SubSequenceSumCount(int index, int size, int sum, int arrsum, int arr[])
{
    if(index == size) 
    {
        //condition is satisfied
        if(arrsum==sum) return 1;
       
        //condition of not satisfied
        return 0;
    }

    
    arrsum = arrsum + arr[index];
    //condition if i get it in the take condition and avoid further recursion
    int l = SubSequenceSumCount(index+1,size,sum, arrsum, arr); // l is just variable to maintain count of left side recursion tree


    arrsum = arrsum - arr[index];
    // condition if we dont't have any subsequence from above
    int r = SubSequenceSumCount(index+1,size,sum,arrsum,arr) ; 

    return l+r; //returning count of such subsequences whose sum is k.
}

int main()
{
    int n,sum;
    cin >> n;
    cin >> sum;
    int arr[n];
    
    //fill array with input numbers
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << SubSequenceSumCount(0,n,sum,0,arr);   
    return 0;
}


// input must be like this 
// 3
// 2
// 1 2 1