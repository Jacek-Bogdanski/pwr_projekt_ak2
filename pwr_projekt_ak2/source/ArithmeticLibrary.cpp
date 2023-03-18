//
// Created by Jacek Bogdański & Michał Kaźmierczak
//
#include <bitset>
#include <iostream>
#include "ArithmeticLibrary.h"

using namespace std;

int ArithmeticLibrary::sum(int a, int b) {
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

    cout << "Wynik: " << sum.to_ulong() << endl;
    cout << "Bity przeniesienia: " << carry_bits << endl;

    return sum.to_ulong();
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