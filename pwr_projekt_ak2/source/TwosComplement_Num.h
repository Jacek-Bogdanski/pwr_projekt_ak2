#ifndef PWR_PROJEKT_AK2_TWOSCOMPLEMENT_NUM_H
#define PWR_PROJEKT_AK2_TWOSCOMPLEMENT_NUM_H

#include <vector>

class TwosComplement_Num {
    int precision;
    std::vector<bool> data;
    bool isNegative();
};


#endif //PWR_PROJEKT_AK2_TWOSCOMPLEMENT_NUM_H
