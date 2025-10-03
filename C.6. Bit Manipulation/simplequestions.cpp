#include <iostream>
using namespace std;

// 1. Swapping Two Numbers with XOR
void swapXOR(int &a, int &b) {
    // Num1 = (Num1 ^ Num2)
    a = a ^ b;
    // Num2 = (Num1 ^ Num2)
    b = a ^ b;
    // Num1 = (Num1 ^ Num2)
    a = a ^ b;
}

// 2. Check if i'th Bit is Set
void checkBit(int num, int i) {
    if ( (num & (1 << i)) != 0 )
        cout << "SET" << endl;
    else
        cout << "NOT SET" << endl;
}

// 3. Set the i'th Bit
int setBit(int num, int i) {
    return (num | (1 << i));
}

// 4. Clear the i'th Bit
int clearBit(int num, int i) {
    return (num & (~(1 << i)));
}

// 5. Toggle the i'th Bit
int toggleBit(int num, int i) {
    return (num ^ (1 << i));
}

// 6. Remove the Last Set Bit (Rightmost)
int removeLastSetBit(int num) {
    return (num & (num - 1));
}

// 7. Check Power of 2
void isPowerOfTwo(int num) {
    if (num > 0 && (num & (num - 1)) == 0)
        cout << "Power of 2" << endl;
    else
        cout << "Not a power of 2" << endl;
}

// 8. Check if Number is Odd or Even
// this works because in binary representation, odd numbers have their least significant bit set to 1
void oddOrEven(int num) {
    if ( (num & 1) == 1 )
        cout << "odd" << endl;
    else
        cout << "even" << endl;
}

// 9. Divide a Number by 2 (Right Shift)
int divideByTwo(int num) {
    return (num >> 1);
}

// 10. Count Number of Set Bits (C++ Built-in)
int builtinCountSetBits(int num) {
    return __builtin_popcount(num); // GCC/Clang only
}

// 11. Count Set Bits (Generic Method)
int manualCountSetBits(int num) {
    int count = 0;
    while (num != 0) {
        // other way to do this is with 
        num = num & (num - 1);
        count++;
    }
    return count;
}

int main() {
    int a = 5, b = 7, i = 1, num = 10;
    
    // 1. Swap
    cout << "--- Swap ---" << endl;
    cout << "Before: a=" << a << ", b=" << b << endl;
    swapXOR(a, b);
    cout << "After: a=" << a << ", b=" << b << endl;

    // 2. Check i'th Bit
    cout << "--- Check Bit ---" << endl;
    checkBit(num, i);

    // 3. Set Bit
    cout << "--- Set Bit ---" << endl;
    cout << setBit(num, i) << endl;

    // 4. Clear Bit
    cout << "--- Clear Bit ---" << endl;
    cout << clearBit(num, i) << endl;

    // 5. Toggle Bit
    cout << "--- Toggle Bit ---" << endl;
    cout << toggleBit(num, i) << endl;

    // 6. Remove Last Set Bit
    cout << "--- Remove Last Set Bit ---" << endl;
    cout << removeLastSetBit(num) << endl;

    // 7. Power of 2
    cout << "--- Power of 2 ---" << endl;
    isPowerOfTwo(num);

    // 8. Odd or Even
    cout << "--- Odd or Even ---" << endl;
    oddOrEven(num);

    // 9. Divide by 2
    cout << "--- Divide by 2 ---" << endl;
    cout << divideByTwo(num) << endl;

    // 10. Builtin Count Set Bits
    cout << "--- Builtin Count Set Bits ---" << endl;
    cout << builtinCountSetBits(num) << endl;

    // 11. Manual Count Set Bits
    cout << "--- Manual Count Set Bits ---" << endl;
    cout << manualCountSetBits(num) << endl;

    return 0;
}
