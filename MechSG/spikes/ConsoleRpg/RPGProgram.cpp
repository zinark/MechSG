#include "RPGProgram.h"
#include <gtest/gtest.h>
#include "Console.h"
using namespace testing;
using namespace CRPG;

RPGProgram::RPGProgram(void)
{
}


RPGProgram::~RPGProgram(void)
{
}

void RPGProgram::Test()
{
    int argc;
    char** argv = 0;
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS ();
    
    Console console;
    console.ReadLine ();
}
