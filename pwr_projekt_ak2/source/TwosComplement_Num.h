//
// Created by Jacek Bogdański & Michał Kaźmierczak.
//

#ifndef PWR_PROJEKT_AK2_TWOSCOMPLEMENT_NUM_H
#define PWR_PROJEKT_AK2_TWOSCOMPLEMENT_NUM_H

#include <vector>

class TwosComplement_Num {

    /**
     * weight of the lowest bit (2^precision)
     */
    int precision;

    /**
     * number of bits
     */
    int size;

    /**
     * variable holding bits
     */
    std::vector<bool> data;

public:

    /**
     * constructor for float
     * @param a
     * @param size
     * @param precision
     */
    TwosComplement_Num(float a, int size, int precision);

    /**
     * constructor for int
     * @param a
     * @param size
     * @param precision
     */
    TwosComplement_Num(int a, int size, int precision);

    /**
     * method to check, if number is negative
     * @return true when negative, false when positive
     */
    bool isNegative();

    /**
     * method to check, if number is positive
     * @return true when positive, false when negative
     */
    bool isPositive();


    /**
     * method to cast number to float
     * @return float value of number
     */
    float floatVal();

    /**
     * Getter for size
     * @return size
     */
    int getSize();

    /**
     * Getter for precision
     * @return precision
     */
    int getPrecision();
};


#endif //PWR_PROJEKT_AK2_TWOSCOMPLEMENT_NUM_H
