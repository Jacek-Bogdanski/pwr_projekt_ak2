//
// Created by Jacek Bogdański & Michał Kaźmierczak.
//

#include "TwosComplement_Num.h"
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
    this->precision = precision;
    this->size = size;
    this->data = std::vector<bool>(this->size, 0);

    bool isNegative = (a < 0);
    if (isNegative) {
        a = -a;
    }
    int power = precision + size - 1;
    double value = pow(2, power);

    for (int i = 0; i < size; i++) {
        if (value <= a && a > 0) {
            this->data[i] = 1;
            a -= value;
        } else {
            this->data[i] = 0;
        }
        value /= 2;
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
    return !TwosComplement_Num::isNegative();
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