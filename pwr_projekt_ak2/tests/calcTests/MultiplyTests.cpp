//
// Created by Jacek Bogdański & Michał Kaźmierczak.
//

#include <gtest/gtest.h>
#include <cmath>
#include "../../source/TwosComplement_Num.h"
#include "../../source/TwosComplement_Exception.h"
using namespace std;

TEST(MultiplyTest, MultiplyNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(4,16,0);
    TwosComplement_Num b = *new TwosComplement_Num(4,16,0);
    EXPECT_EQ(TwosComplement_Num::multiply(a,b).floatVal(), 16.0);
}

TEST(MultiplyTest, MultiplyZerosNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(0,16,0);
    TwosComplement_Num b = *new TwosComplement_Num(0,16,0);
    EXPECT_EQ(TwosComplement_Num::multiply(a,b).floatVal(), 0.0);
}

TEST(MultiplyTest, MultiplyNegativesNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(-4.0,16,0);
    TwosComplement_Num b = *new TwosComplement_Num(-4.0,16,0);
    EXPECT_EQ(TwosComplement_Num::multiply(a,b).floatVal(), 16.0);
}

TEST(MultiplyTest, MultiplyFloatsNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(4.0,16,-8);
    TwosComplement_Num b = *new TwosComplement_Num(2.5,16,-8);
    float result = TwosComplement_Num::multiply(a,b).floatVal();
    EXPECT_EQ(round(result*10.0)/10.0, 10.0);
}

TEST(MultiplyTest, MultiplySmallNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(4.0,8,0);
    TwosComplement_Num b = *new TwosComplement_Num(3,8,0);
    float result = TwosComplement_Num::multiply(a,b).floatVal();
    EXPECT_EQ(round(result*10.0)/10.0, 12.0);
}