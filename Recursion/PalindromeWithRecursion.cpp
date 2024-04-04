#include <bits/stdc++.h>
#include <iostream>
using namespace std;


bool IsPalindrome(int i, int n, string &pali)
{
    if(i>=n/2) return true;
    if(pali[i]!=pali[n-i-1]) return false;
    return IsPalindrome(i+1,n,pali);
}



int main()
{
    
    string pali;
    cin >> pali;
    int n= pali.size();
    cout << IsPalindrome(0,n,pali);

    return 0;
}


