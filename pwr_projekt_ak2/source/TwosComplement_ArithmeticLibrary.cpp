//
// Created by Jacek Bogdański & Michał Kaźmierczak.
//

#include <iostream>
#include "TwosComplement_ArithmeticLibrary.h"
#include "TwosComplement_Num.h"

namespace TwosComplement {
    TwosComplement_Num add(TwosComplement_Num a, TwosComplement_Num b){
        int size = std::max(a.getSize(), b.getSize());
        int precision = std::max(a.getPrecision(), b.getPrecision());
        TwosComplement_Num result(0, size, precision);

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
        std::cout << std::endl<<std::endl;
        return result;
    };

    TwosComplement_Num subtract(TwosComplement_Num a, TwosComplement_Num b){

        return *new TwosComplement_Num(a.floatVal() - b.floatVal(),a.getSize(),a.getPrecision());
    };

    TwosComplement_Num multiply(TwosComplement_Num a, TwosComplement_Num b){

        return *new TwosComplement_Num(a.floatVal() * b.floatVal(),a.getSize(),a.getPrecision());
    };

    TwosComplement_Num divide(TwosComplement_Num a, TwosComplement_Num b){
        return *new TwosComplement_Num(a.floatVal() / b.floatVal(),a.getSize(),a.getPrecision());
    };

    TwosComplement_Num negate(TwosComplement_Num a){
        for (int i = 0; i < a.getSize(); i++) {
            a.data[i] = !a.data[i];
        }
        // add 1
        TwosComplement_Num b(1, a.getSize(), a.getPrecision() );
        a = add(a,b);
        return a;
    };
}
