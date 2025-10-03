#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int Fact(int n, int facto)
{
    if(n==1 or n==0)
    {
        cout << facto;
        return n;
    }
    Fact(n-1,n*facto);
}


int main()
{
 int number;
 cin >> number;
 Fact(number,1);
 return 0;

}