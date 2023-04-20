//
// Created by Jacek Bogdański & Michał Kaźmierczak.
//

#include <iostream>
#include <cmath>
#include "TwosComplement_ArithmeticLibrary.h"
#include "TwosComplement_Num.h"

namespace TwosComplement {

    std::vector<bool> addVectors(std::vector<bool> a, std::vector<bool> b, int size){
        std::vector<bool> result = std::vector<bool>(size, 0);
        bool carry = false;
        for (int i = size - 1; i >= 0; i--) {
            bool num_a = a[i];
            bool num_b = b[i];
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

            result[i] = sum%2;
            carry = (num_a && num_b) || (num_a && carry) || (num_b && carry);
        }

        return result;
    }

    TwosComplement_Num add(TwosComplement_Num a, TwosComplement_Num b){
        int size = std::max(a.getSize(), b.getSize());
        int precision = std::max(a.getPrecision(), b.getPrecision());
        TwosComplement_Num result(0, size, precision);

        // TODO: rozne precyzje - przesuniecie zeby byly rowno

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

        return result;
    };

    TwosComplement_Num subtract(TwosComplement_Num a, TwosComplement_Num b){
        TwosComplement_Num negative_b = TwosComplement::negate(b);
        TwosComplement_Num result = TwosComplement::add(a,negative_b);
        return result;
    };

    TwosComplement_Num multiply(TwosComplement_Num a, TwosComplement_Num b){
        // rozszerzenie liczb
        a.doubleSize();
        b.doubleSize();

        // TODO: rozne precyzje - przesuniecie zeby byly rowno

        // znak
        bool aNegative = a.isNegative();
        bool bNegative = b.isNegative();
        if(aNegative){
            a = negate(a);
        }
        if(bNegative){
            b = negate(b);
        }

        // std::cout<<std::endl<<a.bitString()<<std::endl;
        // std::cout<<b.bitString()<<std::endl<<std::endl;

        int size = std::max(a.getSize(), b.getSize());
        int precision = std::max(a.getPrecision(), b.getPrecision());
        TwosComplement_Num result(0, size, precision*2);


        // Perform binary multiplication
        for (int i = 0; i < size/2; i++) {
            if (b.data[size-1-i]) {
                std::vector<bool> shifted_a = a.data;

                // bit shift on vector, fill zeros
                shifted_a.erase(shifted_a.begin(),shifted_a.begin()+i);
                shifted_a.insert(shifted_a.end(), i, 0);

                result.data = addVectors(result.data, shifted_a,size);
            }
        }

        // return correct negatives
        if(aNegative != bNegative){
            return negate(result);
        }
        return result;
    };

    TwosComplement_Num divide(TwosComplement_Num a, TwosComplement_Num b){
        if(b.floatVal()==0){
            throw "Division by zero!";
        }
        return *new TwosComplement_Num(a.floatVal() / b.floatVal(),a.getSize(),a.getPrecision());
    };

    TwosComplement_Num negate(TwosComplement_Num a){
        for (int i = 0; i < a.getSize(); i++) {
            a.data[i] = !a.data[i];
        }
        // add 1 bit
        TwosComplement_Num b(pow(2,a.getPrecision()), a.getSize(), a.getPrecision() );
        a = add(a,b);
        return a;
    };
}
