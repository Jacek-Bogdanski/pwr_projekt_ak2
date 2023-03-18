//
// Created by Jacek Bogdański & Michał Kaźmierczak
//
#include <bitset>
#include <iostream>
#include "ArithmeticLibrary.h"
#include <cstdint>

using namespace std;

int ArithmeticLibrary::sum_v1(int a, int b) {
    int carry = 0;
    bitset<32> sum, a_bits, b_bits, carry_bits;

    a_bits = a;
    b_bits = b;

    cout << a << " : " <<a_bits << endl;
    cout << b << " : " << b_bits << endl;

    for (int i = 0; i < 32; i++)
    {
        sum[i] = a_bits[i] ^ b_bits[i] ^ carry;     // potrójny XOR
        carry = (a_bits[i] & b_bits[i]) | (b_bits[i] & carry) | (carry & a_bits[i]);  // operacja AND OR AND OR AND
        carry_bits[i] = carry;                      // przeniesienie
    }

    cout << "Sum in addition ver1 is: " << sum.to_ulong() << endl;
    cout << "Bity przeniesienia: " << carry_bits << endl;

    return sum.to_ulong();
}

int ArithmeticLibrary::sum_v2(int a, int b) {
    int32_t sum, carry;

    // Zamiana liczb na binarne
    a = (a & 0x7FFFFFFF) | ((a >> 31) ? 0x80000000 : 0);
    b = (b & 0x7FFFFFFF) | ((b >> 31) ? 0x80000000 : 0);

    // Dodawania
    sum = a ^ b;
    carry = a & b;
    while (carry != 0) {
        carry = carry << 1;
        a = sum;
        b = carry;
        sum = a ^ b;
        carry = a & b;
    }

    // Sprawdzenie przepełnienia flaga overflow
    if ((a < 0 && b < 0 && sum >= 0) || (a > 0 && b > 0 && sum <= 0)) {
        cout << "Error: Overflow occurred." << endl;
    } else {
        // Zamiana liczb z powrotem na U2
        sum = (sum & 0x7FFFFFFF) | ((sum >> 31) ? 0x80000000 : 0);
        cout << "Sum in addition ver2 is: " << sum << endl;
    }

    return sum;
}

int ArithmeticLibrary::subtract(int a, int b) {
    return a-b;
}

int ArithmeticLibrary::multiply(int a, int b) {
    return a*b;
}

int ArithmeticLibrary::divide(int a, int b) {
    return a/b;
}

ArithmeticLibrary::ArithmeticLibrary() = default;