//
// Created by Jacek Bogdański & Michał Kaźmierczak.
//

#include <iostream>
#include "TwosComplement_ArithmeticLibrary.h"
#include "TwosComplement_Num.h"

namespace TwosComplement {
    TwosComplement_Num TwosComplement::add(TwosComplement_Num a, TwosComplement_Num b){

        return *new TwosComplement_Num(a.floatVal() + b.floatVal(),a.getSize(),a.getPrecision());
    };

    TwosComplement_Num TwosComplement::subtract(TwosComplement_Num a, TwosComplement_Num b){

        return *new TwosComplement_Num(a.floatVal() - b.floatVal(),a.getSize(),a.getPrecision());
    };

    TwosComplement_Num TwosComplement::multiply(TwosComplement_Num a, TwosComplement_Num b){

        return *new TwosComplement_Num(a.floatVal() * b.floatVal(),a.getSize(),a.getPrecision());
    };

    TwosComplement_Num TwosComplement::divide(TwosComplement_Num a, TwosComplement_Num b){
        return *new TwosComplement_Num(a.floatVal() / b.floatVal(),a.getSize(),a.getPrecision());
    };
}
