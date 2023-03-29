//
// Created by Jacek Bogdański & Michał Kaźmierczak
//

#ifndef PWR_PROJEKT_AK2_ARITHMETICLIBRARY_H
#define PWR_PROJEKT_AK2_ARITHMETICLIBRARY_H

class ArithmeticLibrary {
public:
    static bool debugMode;
    static int sum_v1(int a, int b);
    static int sum_v2(int a, int b);
    static int subtract_v2(int a, int b);
    static int multiply(int a, int b);
    static int divide(int a, int b);

    static void setDebugMode(bool mode);

    ArithmeticLibrary();
};

#endif //PWR_PROJEKT_AK2_ARITHMETICLIBRARY_H
