#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int Factorial(int n)
{
    if(n==1 or n==0) return 1;
    return n * Factorial(n-1);
    
}

int main()
{
 int number;
 cin >> number;
 cout << Factorial(number);
 return 0;
}