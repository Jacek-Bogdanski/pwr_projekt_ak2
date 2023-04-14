//
// Created by Jacek Bogdański & Michał Kaźmierczak.
//

#include <gtest/gtest.h>
#include <cmath>
#include "../../source/TwosComplement_ArithmeticLibrary.h"
using namespace std;

TEST(DivideTest, DivideNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(16.0,16,0);
    TwosComplement_Num b = *new TwosComplement_Num(4.0,16,0);
    EXPECT_EQ(TwosComplement::divide(a,b).floatVal(), 4.0);
}

TEST(DivideTest, DivideNegativesNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(-8.0,16,0);
    TwosComplement_Num b = *new TwosComplement_Num(-4.0,16,0);
    EXPECT_EQ(TwosComplement::divide(a,b).floatVal(), 2.0);
}

TEST(DivideTest, DivideFloatsNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(8.4,16,-8);
    TwosComplement_Num b = *new TwosComplement_Num(2.0,16,-8);
    EXPECT_EQ(round((TwosComplement::divide(a,b).floatVal())*10.0)/10.0, 4.2);
}