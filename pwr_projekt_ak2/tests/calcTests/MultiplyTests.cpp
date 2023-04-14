//
// Created by Jacek Bogdański & Michał Kaźmierczak.
//

#include <gtest/gtest.h>
#include "../../source/TwosComplement_ArithmeticLibrary.h"
using namespace std;

TEST(MultiplyTest, MultiplyNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(4,16,0);
    TwosComplement_Num b = *new TwosComplement_Num(4,16,0);
    EXPECT_EQ(TwosComplement::multiply(a,b).floatVal(), 16.0);
}

TEST(MultiplyTest, MultiplyZerosNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(0,16,0);
    TwosComplement_Num b = *new TwosComplement_Num(0,16,0);
    EXPECT_EQ(TwosComplement::multiply(a,b).floatVal(), 0.0);
}

TEST(MultiplyTest, MultiplyNegativesNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(-4,16,0);
    TwosComplement_Num b = *new TwosComplement_Num(-4,16,0);
    EXPECT_EQ(TwosComplement::multiply(a,b).floatVal(), 16.0);
}