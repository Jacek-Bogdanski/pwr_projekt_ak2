//
// Created by Jacek Bogdański & Michał Kaźmierczak.
//

#include <gtest/gtest.h>
#include <cmath>
#include "../../source/TwosComplement_Num.h"
#include "../../source/TwosComplement_Exception.h"

using namespace std;

TEST(AddTest, AddNoFailure) {
    TwosComplement_Num a = *new TwosComplement_Num(16, 16, 0);
    TwosComplement_Num b = *new TwosComplement_Num(4, 16, 0);
    EXPECT_EQ(TwosComplement_Num::add(a, b).floatVal(), 20.0);
}

TEST(AddTest, AddZerosNoFailure) {
    TwosComplement_Num a = *new TwosComplement_Num(0, 16, 0);
    TwosComplement_Num b = *new TwosComplement_Num(0, 16, 0);
    EXPECT_EQ(TwosComplement_Num::add(a, b).floatVal(), 0.0);
}

TEST(AddTest, AddNegativesNoFailure) {
    TwosComplement_Num a = *new TwosComplement_Num(-16, 16, 0);
    TwosComplement_Num b = *new TwosComplement_Num(-4, 16, 0);
    EXPECT_EQ(TwosComplement_Num::add(a, b).floatVal(), -20.0);
}

TEST(AddTest, AddDiffrentSizeNoFailure) {
    TwosComplement_Num a = *new TwosComplement_Num(16, 16, 0);
    TwosComplement_Num b = *new TwosComplement_Num(4, 22, 0);
    EXPECT_EQ(TwosComplement_Num::add(a, b).floatVal(), 20.0);
}

TEST(AddTest, AddDiffrentPrecisionNoFailure) {
    TwosComplement_Num a = *new TwosComplement_Num(16, 16, 0);
    TwosComplement_Num b = *new TwosComplement_Num(4, 16, -2);
    EXPECT_EQ(TwosComplement_Num::add(a, b).floatVal(), 20.0);
}

TEST(AddTest, AddFloatsNoFailure) {
    TwosComplement_Num a = *new TwosComplement_Num(16.2, 16, -8);
    TwosComplement_Num b = *new TwosComplement_Num(2.4, 16, -8);
    EXPECT_EQ(round((TwosComplement_Num::add(a, b).floatVal()) * 10.0) / 10.0, 18.6);
}

TEST(AddTest, AddDoubledSizeNoFailure) {
    TwosComplement_Num a = *new TwosComplement_Num(16, 16, 0);
    TwosComplement_Num b = *new TwosComplement_Num(4, 16, 0);

    a.doubleSize();
    b.doubleSize();

    EXPECT_EQ(TwosComplement_Num::add(a, b).floatVal(), 20.0);
}

TEST(AddTest, AddNumberOverflowFailure) {
    EXPECT_THROW({
                     try {
                         TwosComplement_Num a = *new TwosComplement_Num(pow(2, 15), 16, 0);
                         TwosComplement_Num b = *new TwosComplement_Num(pow(2, 15), 16, 0);
                         TwosComplement_Num::add(a, b);
                     }
                     catch (TwosComplement_Exception &e) {
                         EXPECT_STREQ("number-overflow", e.what());
                         throw;
                     }
                 }, TwosComplement_Exception);

}

TEST(AddTest, AddOverflowFailure) {
    EXPECT_THROW({
                     try {
                         TwosComplement_Num a = *new TwosComplement_Num(pow(2, 15)-1, 16, 0);
                         TwosComplement_Num b = *new TwosComplement_Num(pow(2, 15)-1, 16, 0);
                         TwosComplement_Num c = TwosComplement_Num::add(a, b);
                     }
                     catch (TwosComplement_Exception &e) {
                         EXPECT_STREQ("overflow", e.what());
                         throw;
                     }
                 }, TwosComplement_Exception);
}

TEST(AddTest, AddBigDiffrenceNumbersNoFailure) {
    TwosComplement_Num a = *new TwosComplement_Num(777777.125, 255, -40);
    TwosComplement_Num b = *new TwosComplement_Num(4, 22, 0);
    EXPECT_EQ(TwosComplement_Num::add(a, b).floatVal(), 777781.125);
}

TEST(AddTest, AddBigDiffrenceNumbersTwoNoFailure) {
    TwosComplement_Num a = *new TwosComplement_Num(777777.5, 255, -40);
    TwosComplement_Num b = *new TwosComplement_Num(0.0625, 100, -50);
    EXPECT_EQ(round(TwosComplement_Num::add(a, b).floatVal()*1000.0)/1000.0, round(777777.5625*1000.0)/1000.0);
}