//
// Created by Jacek Bogdański & Michał Kaźmierczak.
//

#include <gtest/gtest.h>
#include "../../source/TwosComplement_ArithmeticLibrary.h"
using namespace std;

TEST(DivideTest, DivideNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(16,16,0);
    TwosComplement_Num b = *new TwosComplement_Num(4,16,0);
    EXPECT_EQ(TwosComplement::divide(a,b).floatVal(), 4.0);
}

TEST(DivideTest, DivideNegativesNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(-8,16,0);
    TwosComplement_Num b = *new TwosComplement_Num(-4,16,0);
    EXPECT_EQ(TwosComplement::divide(a,b).floatVal(), 2.0);
}