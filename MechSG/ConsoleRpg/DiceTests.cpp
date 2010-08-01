#include <gtest/gtest.h>
#include "Range.h"
#include "Dice.h"
#include <iostream>

using namespace CRPG;
using namespace std;

TEST (Dice, RangeTest)
{
    Range range(1,6);
    EXPECT_EQ (1, range.LowRange ());
    EXPECT_EQ (6, range.HighRange());
}

TEST (Dice, DiceRollsWithGivenRange)
{
    Range range (1,6);
    Dice dice (range);
    EXPECT_LE (1, dice.Roll());
    EXPECT_GE (6, dice.Roll());
}

TEST (Dice, RollSome5Result)
{
    Dice dice (Range (1,2));
    for (int i=0; i<5; i++)
        dice.Roll();
}