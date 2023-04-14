//
// Created by Jacek Bogdański & Michał Kaźmierczak.
//

#include "TwosComplement_Num.h"

/**
 * constructor for float
 * @param a
 * @param size
 * @param precision
 */
TwosComplement_Num::TwosComplement_Num(float a, int size=16, int precision = -4){
    this->precision = precision;
    this->size = size;

    this->data = std::vector<bool>(this->size);
}

/**
 * constructor for int
 * @param a
 * @param size
 * @param precision
 */
TwosComplement_Num::TwosComplement_Num(int a, int size=16, int precision = 0){
    this->precision = precision;
    this->size = size;

    this->data = std::vector<bool>(this->size);
}

/**
 * method to check, if number is negative
 * @return true when negative, false when positive
 */
bool TwosComplement_Num::isNegative() {
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
 * method to cast number to float
 * @return float value of number
 */
float TwosComplement_Num::floatVal() {
    return 0.0;
}


/**
 * Getter for size
 * @return size
 */
int TwosComplement_Num::getSize(){
    return this->size;
}

/**
 * Getter for precision
 * @return precision
 */
int TwosComplement_Num::getPrecision(){
    return this->precision;
}