//
// Created by Jacek Bogdański & Michał Kaźmierczak.
//

#include <gtest/gtest.h>
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