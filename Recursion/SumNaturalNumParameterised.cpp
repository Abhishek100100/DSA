//Q. Return sum of number till n using parameterised recursion
// what I understood is that to print on console we use parameterised recursion
#include<bits/stdc++.h>
#include<iostream>
using namespace std;


void NaturalSum(int n, int sum)
{
    if(n==0)
    {
        cout << sum;
        return;
    }

    NaturalSum(n-1,sum+n);
    
}


int main()
{
 int number;
 cin >> number;
 NaturalSum(number,0);
return 0;

}