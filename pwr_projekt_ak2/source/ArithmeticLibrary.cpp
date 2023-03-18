//
// Created by Jacek Bogdański & Michał Kaźmierczak
//

#include "ArithmeticLibrary.h"

int ArithmeticLibrary::sum(int a, int b) {
    return a+b;
}

int ArithmeticLibrary::subtract(int a, int b) {
    return a-b;
}

int ArithmeticLibrary::multiply(int a, int b) {
    return a*b;
}

int ArithmeticLibrary::divide(int a, int b) {
    return a/b;
}

ArithmeticLibrary::ArithmeticLibrary() = default;