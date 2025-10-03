//Q. Return sum of number till n using functional recursion
// what I understood is that to return a value instead of printing to the console we use functional recursion
#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int NaturalSum(int n)
{
    if(n<1) return n;
    return n + NaturalSum(n-1);
    
}


int main()
{
 int number;
 cin >> number;
 cout << NaturalSum(number);
 return 0;
}