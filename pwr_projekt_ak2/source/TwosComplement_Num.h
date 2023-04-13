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
};


#endif //PWR_PROJEKT_AK2_TWOSCOMPLEMENT_NUM_H
