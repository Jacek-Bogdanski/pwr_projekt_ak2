//
// Created by Jacek Bogdański & Michał Kaźmierczak.
//

#ifndef PWR_PROJEKT_AK2_TWOSCOMPLEMENT_ARITHMETICLIBRARY_H
#define PWR_PROJEKT_AK2_TWOSCOMPLEMENT_ARITHMETICLIBRARY_H

#include "TwosComplement_Num.h"

namespace TwosComplement {
    TwosComplement_Num add(TwosComplement_Num a, TwosComplement_Num b);
    TwosComplement_Num subtract(TwosComplement_Num a, TwosComplement_Num b);
    TwosComplement_Num multiply(TwosComplement_Num a, TwosComplement_Num b);
    TwosComplement_Num divide(TwosComplement_Num a, TwosComplement_Num b);
    TwosComplement_Num negate(TwosComplement_Num a);

    std::vector<bool> addVectors(std::vector<bool> a, std::vector<bool> b, int size);
}

#endif //PWR_PROJEKT_AK2_TWOSCOMPLEMENT_ARITHMETICLIBRARY_H
