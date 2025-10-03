#include <bits/stdc++.h>
#include <iostream>
using namespace std;


void reverse(int left, int right, int arr[]){

    if(left>=right) return;
    swap(arr[left], arr[right]); //part of above include header
    reverse(left+1,right-1,arr);
    
}

int main()
{
    int n;
    cin >> n;
    int num[n];
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    
    reverse(0,n-1,num);
    for(int i=0;i<n;i++){
        cout << num[i] << " ";
    }

    return 0;
}


