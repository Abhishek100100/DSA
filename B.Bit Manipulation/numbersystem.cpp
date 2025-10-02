#include<iostream>
using namespace std;

// Function to convert decimal to binary
string decimalToBinary(int n) {
    if (n == 0) return "0";
    string binary = "";
    while (n > 0) {
        binary = to_string(n % 2) + binary;
        n = n/2;
    }
    return binary;
}
// Function to convert binary to decimal
int binaryToDecimal(const string& binary) {
    int decimalValue = 0;
    for (char c : binary) {
        decimalValue = (decimalValue << 1) | (c - '0');
    }
    return decimalValue;
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
// Function to convert octal to decimal
int octalToDecimal(const string& octal) {
    int decimalValue = 0;
    for (char c : octal) {
        decimalValue = (decimalValue << 3) | (c - '0');
    }
    return decimalValue;
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


// Function to convert binary to octal
string binaryToOctal(const string& binary) {
    int decimalValue = binaryToDecimal(binary);
    return decimalToOctal(decimalValue);
}

// Function to convert binary to hexadecimal
string binaryToHexadecimal(const string& binary) {
    int decimalValue = binaryToDecimal(binary);
    return decimalToHexadecimal(decimalValue);
}

// Function to convert octal to binary
string octalToBinary(const string& octal) {
    int decimalValue = octalToDecimal(octal);
    return decimalToBinary(decimalValue);
}


// Function to convert octal to hexadecimal
string octalToHexadecimal(const string& octal) {
    int decimalValue = octalToDecimal(octal);
    return decimalToHexadecimal(decimalValue);
}

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


int main()
{
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;

    cout << "Binary: " << decimalToBinary(n) << endl;
    cout << "Octal: " << decimalToOctal(n) << endl;
    cout << "Hexadecimal: " << decimalToHexadecimal(n) << endl;

    string hex_val = "FF";
    cout << "\nFor Hex value " << hex_val << ":" << endl;
    cout << "Decimal: " << hexadecimalToDecimal(hex_val) << endl;
    cout << "Binary: " << hexadecimalToBinary(hex_val) << endl;
    cout << "Octal: " << hexadecimalToOctal(hex_val) << endl;

    return 0;
}