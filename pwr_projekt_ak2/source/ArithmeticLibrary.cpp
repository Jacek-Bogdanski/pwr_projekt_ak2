//
// Created by Jacek Bogdański & Michał Kaźmierczak
//
#include <bitset>
#include <iostream>
#include "ArithmeticLibrary.h"
#include <cstdint>
template <size_t N>
int ArithmeticLibrary::sum_v1(int a, int b) {
    int carry = 0;
    std::bitset<N> sum, a_bits, b_bits, carry_bits;

    a_bits = a;
    b_bits = b;

    if (ArithmeticLibrary::debugMode) {
        std::cout << "Operation: SUM" << std::endl;
        std::cout << "Operand 1:  " << a_bits << std::endl;
        std::cout << "Operand 2:  " << b_bits << std::endl;
    }

    for (int i = 0; i < N; i++) {
        sum[i] = a_bits[i] ^ b_bits[i] ^ carry;     // potrójny XOR
        carry = (a_bits[i] & b_bits[i]) | (b_bits[i] & carry) | (carry & a_bits[i]);  // operacja AND OR AND OR AND
        carry_bits[i] = carry;                      // przeniesienie
    }

    if (ArithmeticLibrary::debugMode) {
        std::cout << "Result v1:  " << sum << std::endl;
        std::cout << "Carry bits: " << carry_bits << std::endl;
    }

    return sum.to_ulong();
}

int ArithmeticLibrary::sum_v2(int a, int b) {
    int32_t sum, carry;
    std::bitset<32> a_bits, b_bits, result;
    // Zamiana liczb na binarne
    a = (a & 0x7FFFFFFF) | ((a >> 31) ? 0x80000000 : 0);
    b = (b & 0x7FFFFFFF) | ((b >> 31) ? 0x80000000 : 0);

    a_bits = a;
    b_bits = b;

    if (ArithmeticLibrary::debugMode) {
        std::cout << "Operation: SUM" << std::endl;
        std::cout << "Operand 1: " << a_bits << std::endl;
        std::cout << "Operand 2: " << b_bits << std::endl;
    }

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
        std::cout << "Error: Overflow occurred." << std::endl;
        return NULL;
    }
    result = sum;
    if (ArithmeticLibrary::debugMode) {
        std::cout << "Result v2: " << result << std::endl;
    }

    // Zamiana liczb z powrotem na U2
    sum = (sum & 0x7FFFFFFF) | ((sum >> 31) ? 0x80000000 : 0);

    return sum;
}

int ArithmeticLibrary::sum_v3_asm(int a, int b) {
    int32_t sum;
    int32_t carry = 0;

    asm("xor %%edx, %%edx;"
        "add %2, %0;"
        "adc %3, %0;"
            : "+r" (sum)
            : "d" (carry), "r" (a), "r" (b)
            );

    // Check for overflow
    if ((a < 0 && b < 0 && sum >= 0) || (a > 0 && b > 0 && sum <= 0)) {
        std::cout << "Error: Overflow occurred." << std::endl;
        return 0;
    }

    return sum;
}

int ArithmeticLibrary::subtract_v2(int a, int b) {
    std::bitset<32> result, a_bits, b_bits;
    int32_t sum, carry, difference;
    a_bits = a;
    b_bits = b;

    if (ArithmeticLibrary::debugMode) {
        std::cout << "Operation: SUBTRACT" << std::endl;
        std::cout << "Operand 1:  " << a_bits << std::endl;
        std::cout << "Operand 2:  " << b_bits << std::endl;
    }

    b = ~b+1;
    b_bits = b;

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
        std::cout << "Error: Overflow occurred." << std::endl;
        return NULL;
    }
    result = sum;
    if (ArithmeticLibrary::debugMode) {
        std::cout << "Result v2: " << result << std::endl;
    }

    // Zamiana liczb z powrotem na U2
    difference = (sum & 0x7FFFFFFF) | ((sum >> 31) ? 0x80000000 : 0);

    return difference;
}

int ArithmeticLibrary::multiply(int a, int b) {
    std::bitset<32> product, a_bits, b_bits, carry_bits;

    a_bits = a;
    b_bits = b;

    if (ArithmeticLibrary::debugMode) {
        std::cout << "Operation: MULTIPLY" << std::endl;
        std::cout << "Operand 1:  " << a_bits << std::endl;
        std::cout << "Operand 2:  " << b_bits << std::endl;
    }
    return a * b;
}

int ArithmeticLibrary::divide(int a, int b) {
    std::bitset<32> quotient, a_bits, b_bits, carry_bits;

    a_bits = a;
    b_bits = b;

    if (ArithmeticLibrary::debugMode) {
        std::cout << "Operation: DIVIDE" << std::endl;
        std::cout << "Operand 1:  " << a_bits << std::endl;
        std::cout << "Operand 2:  " << b_bits << std::endl;
    }
    return a / b;
}

void ArithmeticLibrary::setDebugMode(bool mode) {
    ArithmeticLibrary::debugMode = mode;
};

bool ArithmeticLibrary::debugMode = false;

ArithmeticLibrary::ArithmeticLibrary() = default;