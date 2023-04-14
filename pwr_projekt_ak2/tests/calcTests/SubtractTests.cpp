//
// Created by Jacek Bogdański & Michał Kaźmierczak.
//

#include <gtest/gtest.h>
#include <cmath>
#include "../../source/TwosComplement_ArithmeticLibrary.h"
using namespace std;

TEST(SubtractTest, SubtractNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(16,16,0);
    TwosComplement_Num b = *new TwosComplement_Num(4,16,0);
    EXPECT_EQ(TwosComplement::subtract(a,b).floatVal(), 12.0);
}

TEST(SubtractTest, SubtractZerosNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(0,16,0);
    TwosComplement_Num b = *new TwosComplement_Num(0,16,0);
    EXPECT_EQ(TwosComplement::subtract(a,b).floatVal(), 0.0);
}

TEST(SubtractTest, SubtractNegativesNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(-16,16,0);
    TwosComplement_Num b = *new TwosComplement_Num(-4,16,0);
    EXPECT_EQ(TwosComplement::subtract(a,b).floatVal(), -12.0);
}

TEST(SubtractTest, SubtractFloatsNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(3.0,16,-8);
    TwosComplement_Num b = *new TwosComplement_Num(2.1,16,-8);
    EXPECT_EQ(round((TwosComplement::subtract(a,b).floatVal())*10.0)/10.0, 0.9);
}