#include <bits/stdc++.h>
#include <iostream>
using namespace std;


void reverse(int i, int n, int arr[]){
    if(i >= n/2) return;
    swap(arr[i], arr[n-i-1]); //part of above include header
    reverse(i+1,n,arr);
}

int main()
{
    int n;
    cin >> n;
    int num[n];
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    
    reverse(0,n,num);
    for(int i=0;i<n;i++){
        cout << num[i] << " ";
    }

    return 0;
}


