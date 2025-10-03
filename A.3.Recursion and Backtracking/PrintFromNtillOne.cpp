#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class recursive{
    public: 
    void WithoutLoop(int n)
    {
        if(n==0) return;
        WithoutLoop(n-1);
        cout << n << endl;
    }
};


int main()
{
    int num;
    recursive abcd;
    cin >> num;
    abcd.WithoutLoop(num);
    return 0;
}

