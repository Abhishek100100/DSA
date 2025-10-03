#include<iostream>
using namespace std;



int main()
{
    int a, b;
    cout << "Enter two numbers to swap: ";
    cin >> a >> b;

    // Swapping two numbers without third variable using bitwise XOR
    a = a^b;
    b= a^b;
    a = a^b;

    cout << "After swapping: " << a << " " << b << endl;
    return 0;
}