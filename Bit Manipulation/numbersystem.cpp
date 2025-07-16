#include<iostream>
using namespace std;

// Function to convert decimal to binary
string decimalToBinary(int n) {
    if (n == 0) return "0";
    string binary = "";
    while (n > 0) {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    return binary;
}

// Function to convert decimal to octal
string decimalToOctal(int n) {
    if (n == 0) return "0";
    string octal = "";
    while (n > 0) {
        octal = to_string(n % 8) + octal;
        n /= 8;
    }
    return octal;
}

// Function to convert decimal to hexadecimal
string decimalToHexadecimal(int n) {
    if (n == 0) return "0";
    string hex = "";
    while (n > 0) {
        int remainder = n % 16;
        if (remainder < 10)
            hex = to_string(remainder) + hex;
        else
            hex = char(remainder - 10 + 'A') + hex;
        n /= 16;
    }
    return hex;
}

// Function to convert binary to octal
// Function to convert binary to decimal
// Function to convert binary to hexadecimal

// Function to convert octal to binary
// Function to convert octal to decimal
// Function to convert octal to hexadecimal

// Function to convert hexadecimal to binary
string hexadecimalToBinary(const string& hex) {
    string binary = "";
    for (char c : hex) {
        int value;
        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            value = c - 'a' + 10;
        } else {
            continue; // Invalid character
        }
        for (int i = 3; i >= 0; --i) {
            binary += (value & (1 << i)) ? '1' : '0';
        }
    }
    return binary;
}

// Function to convert hexadecimal to octal
string hexadecimalToOctal(const string& hex) {
    string binary = hexadecimalToBinary(hex);
    int decimalValue = 0;
    for (char c : binary) {
        decimalValue = (decimalValue << 1) | (c - '0');
    }
    return decimalToOctal(decimalValue);
}
// Function to convert hexadecimal to decimal
int hexadecimalToDecimal(const string& hex) {
    int decimalValue = 0;
    for (char c : hex) {
        int value;
        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            value = c - 'a' + 10;
        } else {
            continue; // Invalid character
        }
        decimalValue = (decimalValue << 4) | value;
    }
    return decimalValue;
}

int main()
{
    //take the decimal number as input
    int n;
    cin >> n;

    return 0;
}