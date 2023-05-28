//
// Created by Jacek Bogdański & Michał Kaźmierczak.
//

#ifndef PWR_PROJEKT_AK2_TWOSCOMPLEMENT_NUM_H
#define PWR_PROJEKT_AK2_TWOSCOMPLEMENT_NUM_H

#include <vector>
#include <string>

class TwosComplement_Num {

    /**
     * weight of the lowest bit (2^precision)
     */
    int precision;

    /**
     * number of bits
     */
    int size;

public:

    /**
     * variable holding bits
     */
    std::vector<bool> data;


    /**
     * constructor for float
     * @param a
     * @param size
     * @param precision
     */
    TwosComplement_Num(double a, int size, int precision);

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
     * method returning bit string
     * @return bit string
     */
    std::string bitString();

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

    /**
     * Getter for data
     * @return data
     */
    std::vector<bool> getData();

    /**
     * Function doubling size of number
     */
    void doubleSize();

    /**
     * Suma liczb
     * @param a first number
     * @param b second number
     * @return sum of numbers a, b
     */
    static TwosComplement_Num add(TwosComplement_Num a, TwosComplement_Num b);

    /**
     * Dodanie liczby do obiektu
     * @param b
     */
    TwosComplement_Num add(TwosComplement_Num b);

    /**
     * Różnica liczb
     * @param a first number
     * @param b second number
     * @return diff of numbers a, b
     */
    static TwosComplement_Num subtract(TwosComplement_Num a, TwosComplement_Num b);

    /**
     * Odjęcie liczby od obiektu
     * @param b
     */
    TwosComplement_Num subtract(TwosComplement_Num b);

    /**
     * Iloczyn liczb
     * @param a first number
     * @param b second number
     * @return iloczyn of numbers a, b
     */
    static TwosComplement_Num multiply(TwosComplement_Num a, TwosComplement_Num b);

    /**
     * Pomnożenie liczby przez obiekt
     * @param b
     */
    TwosComplement_Num multiply(TwosComplement_Num b);

    /**
     * Iloraz liczb
     * @param a first number
     * @param b second number
     * @return iloraz of numbers a, b
     */
    static TwosComplement_Num divide(TwosComplement_Num a, TwosComplement_Num b);

    /**
     * Podzielenie obiektu przez liczbę
     * @param b
     */
    void divide(TwosComplement_Num b);

    /**
     * Negacja liczby
     * @param a number
     * @return negation of number
     */
    static TwosComplement_Num negate(TwosComplement_Num a);

    /**
     * Negacja obiektu
     */
    void negate();

    /**
     * Ustawienie nowej precyzji obiektu ze zmiana dlugosci
     */
    void setPrecision(int newPrecision);

    /**
     * Ustawienie nowego rozmiaru obiektu z rozszerzeniem
     */
    void setSize(int newSize);
};


#endif //PWR_PROJEKT_AK2_TWOSCOMPLEMENT_NUM_H
