#include "TwosComplement_Num.h"

bool TwosComplement_Num::isNegative() {
    return false;
}

bool TwosComplement_Num::isPositive() {
    return !TwosComplement_Num::isNegative();
}
