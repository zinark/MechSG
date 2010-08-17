#include <iostream>
#include <gtest/gtest.h>

using namespace testing;
using namespace std;

int main (int argc, char** argv)
{
	InitGoogleTest (&argc, argv);
	RUN_ALL_TESTS ();
	int x;
	cin >> x;
}