//
// Created by Jacek Bogdański & Michał Kaźmierczak.
//

#include <gtest/gtest.h>
#include <cmath>
#include "../../source/TwosComplement_ArithmeticLibrary.h"
using namespace std;

TEST(AddTest, AddNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(16,16,0);
    TwosComplement_Num b = *new TwosComplement_Num(4,16,0);
    EXPECT_EQ(TwosComplement::add(a,b).floatVal(), 20.0);
}

TEST(AddTest, AddZerosNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(0,16,0);
    TwosComplement_Num b = *new TwosComplement_Num(0,16,0);
    EXPECT_EQ(TwosComplement::add(a,b).floatVal(), 0.0);
}

TEST(AddTest, AddNegativesNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(-16,16,0);
    TwosComplement_Num b = *new TwosComplement_Num(-4,16,0);
    EXPECT_EQ(TwosComplement::add(a,b).floatVal(), -20.0);
}

TEST(AddTest, AddFloatsNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(16.2,16,-8);
    TwosComplement_Num b = *new TwosComplement_Num(2.4,16,-8);
    EXPECT_EQ(round((TwosComplement::add(a,b).floatVal())*10.0)/10.0, 18.6);
}

TEST(AddTest, AddDoubledSizeNoFailure)
{
    TwosComplement_Num a = *new TwosComplement_Num(16,16,0);
    TwosComplement_Num b = *new TwosComplement_Num(4,16,0);

    a.doubleSize();
    b.doubleSize();

    EXPECT_EQ(TwosComplement::add(a,b).floatVal(), 20.0);
}