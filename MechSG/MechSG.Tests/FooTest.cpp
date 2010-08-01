#include <gtest/gtest.h>
#include "Foo.h"
#include <iostream>
using namespace std;

TEST (CASE1, ReturnsTrue)
{
    EXPECT_EQ (true, Foo ().IsGreater(5,4));
}

TEST (CASE1, ReturnFalse)
{
    EXPECT_EQ (false, Foo().IsGreater(4,5));
}