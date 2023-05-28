//
// Created by Jacek Bogdański & Michał Kaźmierczak.
//

#include "TwosComplement_Num.h"
#include "TwosComplement_Exception.h"
#include <iostream>
#include <cmath>
#include <sstream>

/**
 * constructor for double number
 * @param a
 * @param size
 * @param precision
 */
TwosComplement_Num::TwosComplement_Num(double a, int size = 16, int precision = -4) {
    if(size<1){
        throw TwosComplement_Exception("invalid size");
    }
    this->precision = precision;
    this->size = size;
    this->data = std::vector<bool>(this->size, 0);

    bool isNegative = (a < 0);
    if (isNegative) {
        a = -a;
    }
    int power = precision + size - 1;
    double value = pow(2, power);

    // liczba nie moze byc wieksza od 2*max-1
    if(a > (value * 2 - 1)){
        throw TwosComplement_Exception("number-overflow");
    }

    for (int i = 0; i < size; i++) {
        if (value <= a && a > 0) {
            this->data[i] = 1;
            a -= value;
        } else {
            this->data[i] = 0;
        }
        value /= 2;
    }

    // pierwszy bit pozostaje zerowy, inaczej reprezentacja nie jest prawidlowa
    if(this->data[0]==1){
        throw TwosComplement_Exception("number-overflow");
    }

    if (isNegative) {
        // odwrocic liczbe
        for (int i = 0; i < size; i++) {
            this->data[i] = !this->data[i];
        }

        // dodanie 1
        bool carry = true;
        for (int i = size - 1; i >= 0; i--) {
            if (this->data[i] && carry) {
                this->data[i] = 0;
                carry = true;
            } else if (carry) {
                this->data[i] = 1;
                carry = false;
            }
        }
    }
}

/**
 * method to check, if number is negative
 * @return true when negative, false when positive
 */
bool TwosComplement_Num::isNegative() {
    if(this->data[0]==1){
        return true;
    }
    return false;
}

/**
 * method to check, if number is positive
 * @return true when positive, false when negative
 */
bool TwosComplement_Num::isPositive() {
    if(this->data[0]==1){
        return false;
    }
    return true;
}

/**
 * Function doubling size of number
 */
void TwosComplement_Num::doubleSize(){
    int value = 0;
    if(this->isNegative()){
        value = 1;
    }
    // kopia bitów
    std::vector<bool> vect = std::vector<bool>(2*this->size, value);
    for (int i = 0; i < this->size; i++) {
        vect[i+this->size] = this->data[i];
    }
    this->size *= 2;
    this->data = vect;
}

/**
 * Function setting size of number
 */
void TwosComplement_Num::setSize(int newSize){
    if(newSize < this->size){
        return;
    }
    int diff = newSize-this->size;
    int value = 0;
    if(this->isNegative()){
        value = 1;
    }
    // kopia bitów
    std::vector<bool> vect = std::vector<bool>(newSize, value);
    for (int i = 0; i < this->size; i++) {
        vect[i+diff] = this->data[i];
    }
    this->size = newSize;
    this->data = vect;
}

/**
 * method to cast number to float
 * @return float value of number
 */
float TwosComplement_Num::floatVal() {
    bool isNegative = this->data[0];
    float a = 0;

    // kopia bitów
    std::vector<bool> vect = std::vector<bool>(this->size, 0);
    for (int i = 0; i < this->size; i++) {
        vect[i] = this->data[i];
    }

    // odwrócenie
    if (isNegative) {
        // odwrocic liczbe
        for (int i = 0; i < this->size; i++) {
            vect[i] = !vect[i];
        }

        // dodanie 1
        bool carry = true;
        for (int i = this->size - 1; i >= 0; i--) {
            if (vect[i] && carry) {
                vect[i] = 0;
                carry = true;
            } else if (carry) {
                vect[i] = 1;
                carry = false;
            }
        }
    }

    int power = this->precision + this->size - 1;
    double value = pow(2, power);

    for (int i = 0; i < size; i++) {
        if (vect[i]) {
            a += value;
        }
        value /= 2;
    }

    if (isNegative) {
        return -a;
    }
    return a;
}

/**
 * method returning bit string
 * @return bit string
 */
std::string TwosComplement_Num::bitString() {
    std::stringstream a("");
    for (int i = 0; i < this->getSize(); i++) {
        a << (this->data[i] ? "1" : "0");
    }
    std::string b;
    a >> b;
    return b;
};

/**
 * Getter for size
 * @return size
 */
int TwosComplement_Num::getSize() {
    return this->size;
}

/**
 * Getter for precision
 * @return precision
 */
int TwosComplement_Num::getPrecision() {
    return this->precision;
}

/**
 * Getter for data
 * @return data
 */
std::vector<bool> TwosComplement_Num::getData(){
    return this->data;
};


TwosComplement_Num TwosComplement_Num::add(TwosComplement_Num a, TwosComplement_Num b){
    int precision_n = std::min(a.getPrecision(), b.getPrecision());
    // wyrownanie przecyzji
    if(a.getPrecision() != precision_n){
        a.setPrecision(precision_n);
    }
    if(b.getPrecision() != precision_n){
        b.setPrecision(precision_n);
    }

    int size_n = std::max(a.getSize(), b.getSize());
    // wyrownanie rozmiaru
    if(a.getSize() != size_n){
        a.setSize(size_n);
    }
    if(b.getSize() != size_n){
        b.setSize(size_n);
    }

    // liczba wynikowa
    TwosComplement_Num result(0, size_n, precision_n);

    bool carry = false;
    for (int i = a.getSize() - 1; i >= 0; i--) {
        bool num_a = a.getData()[i];
        bool num_b = b.getData()[i];
        bool sum = false;
        asm (
                "add %1, %0\n\t"
                "adc %2, %0\n\t"
                : "+r" (sum)
                : "r" (num_a), "r" (num_b)
                : "cc"
                );
        asm (
                "adc %1, %0\n\t"
                : "+r" (sum)
                : "r" (carry)
                : "cc"
                );

        result.data[i] = sum%2;
        carry = (num_a && num_b) || (num_a && carry) || (num_b && carry);
    }

    if(carry && !(a.isNegative() || b.isNegative())){
        throw TwosComplement_Exception("overflow");
    }

    // jesli znaki nie sa poprawne
    if(a.isPositive() && b.isPositive() && result.isNegative()){
        throw TwosComplement_Exception("overflow");
    }

    return result;
};

TwosComplement_Num TwosComplement_Num::add(TwosComplement_Num b){
    return TwosComplement_Num::add(*this,b);
}

TwosComplement_Num TwosComplement_Num::subtract(TwosComplement_Num a, TwosComplement_Num b){
    TwosComplement_Num negative_b = TwosComplement_Num::negate(b);
    TwosComplement_Num result = TwosComplement_Num::add(a,negative_b);
    return result;
};

TwosComplement_Num TwosComplement_Num::subtract(TwosComplement_Num b){
    return TwosComplement_Num::subtract(*this,b);
}

TwosComplement_Num TwosComplement_Num::multiply(TwosComplement_Num a, TwosComplement_Num b){
    // rozszerzenie liczb
    a.doubleSize();
    b.doubleSize();

    int precision_n = std::min(a.getPrecision(), b.getPrecision());
    // wyrownanie przecyzji
    if(a.getPrecision() != precision_n){
        a.setPrecision(precision_n);
    }
    if(b.getPrecision() != precision_n){
        b.setPrecision(precision_n);
    }

    int size_n = std::max(a.getSize(), b.getSize());
    // wyrownanie rozmiaru
    if(a.getSize() != size_n){
        a.setSize(size_n);
    }
    if(b.getSize() != size_n){
        b.setSize(size_n);
    }

    // liczba wynikowa
    TwosComplement_Num result(0, size_n, precision_n*2);

    // znak
    bool aNegative = a.isNegative();
    bool bNegative = b.isNegative();
    if(aNegative){
        a = TwosComplement_Num::negate(a);
    }
    if(bNegative){
        b = TwosComplement_Num::negate(b);
    }

    std::vector<bool> shifted_a = a.data;
    std::vector<bool> result_n = std::vector<bool>(size_n, 0);
    bool carry;

    // Perform binary multiplication
    for (int i = size_n-1; i >=(size_n-1)/2; i--) {
        carry = false;

        bool num_b = b.data[i];
        for (int k = size_n - 1; k >= 0; k--) {
            bool num_a = shifted_a[k];

            bool sum = result_n[k];
            asm (
                    "movzbl %1, %%eax\n\t"
                    "mul %2\n\t"
                    "add %%al, %0\n\t"
                    : "+r" (sum)
                    : "r" (num_a), "r" (num_b)
                    : "cc", "%eax"
                    );
            asm (
                    "adc %1, %0\n\t"
                    : "+r" (sum)
                    : "r" (carry)
                    : "cc"
                    );

            result_n[k] = sum%2;
            carry = carry && num_a && num_b;
        }

        // bit shift on vector, fill zeros
        shifted_a.erase(shifted_a.begin(),shifted_a.begin()+1);
        shifted_a.insert(shifted_a.end(), 1, 0);
    }

    if(carry){
        throw TwosComplement_Exception("overflow");
    }

    result.data = result_n;

    // return correct negatives
    if(aNegative != bNegative){
        return TwosComplement_Num::negate(result);
    }
    return result;
};

TwosComplement_Num TwosComplement_Num::multiply(TwosComplement_Num b){
    return TwosComplement_Num::multiply(*this,b);
}

TwosComplement_Num TwosComplement_Num::divide(TwosComplement_Num a, TwosComplement_Num b){
    if(b.floatVal()==0){
        throw TwosComplement_Exception("division-by-zero");
    }
    return *new TwosComplement_Num(a.floatVal() / b.floatVal(),a.getSize(),a.getPrecision());
};

void TwosComplement_Num::divide(TwosComplement_Num b){
    TwosComplement_Num c = TwosComplement_Num::divide(*this,b);
    *this = c;
}


TwosComplement_Num TwosComplement_Num::negate(TwosComplement_Num a){
    for (int i = 0; i < a.getSize(); i++) {
        a.data[i] = !a.data[i];
    }
    // add 1 bit
    TwosComplement_Num b(pow(2,a.getPrecision()), a.getSize(), a.getPrecision() );
    a = TwosComplement_Num::add(a,b);
    return a;
};

/**
 * Function setting precision for number precision match
 */
void TwosComplement_Num::setPrecision(int newPrecision){
    int diff = newPrecision - precision;
    if(diff >= 0){
        return;
    }
    diff = -diff;

    // kopia bitów
    std::vector<bool> vect = std::vector<bool>(this->size + diff, 0);
    for (int i = 0; i < this->size; i++) {
        vect[i] = this->data[i];
    }

    this->size += diff;
    this->precision = newPrecision;
    this->data = vect;
}