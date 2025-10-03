#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void SubSequence(int index, int size, vector<int> vecto, int arr[])
{
    if(index == size) 
    {
        for(auto it : vecto) 
        {
            cout << it << " "; 
        }
        if(vecto.size() == 0) cout << "{}";
        cout << " " << endl;
        return;
    }

    vecto.push_back(arr[index]);
    SubSequence(index+1,size,vecto,arr);
    vecto.pop_back();    //learnt that popback doesnt need arguments
    SubSequence(index+1,size,vecto,arr); //we can put this line just after the if condition to print in reverse order.
    return;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    vector<int> vecto;
    //fill array with input numbers
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    SubSequence(0,n,vecto,arr);
    return 0;
}


