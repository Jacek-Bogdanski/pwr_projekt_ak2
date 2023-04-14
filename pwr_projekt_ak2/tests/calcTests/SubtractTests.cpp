//
// Created by Jacek Bogdański & Michał Kaźmierczak.
//

#include <gtest/gtest.h>
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