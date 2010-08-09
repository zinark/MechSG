#pragma once
#include <string>
#include <iostream>
using namespace std;

namespace CRPG
{
    class Console
    {
    public:
        Console(void);
        ~Console(void);
        void Out (string text);
        void ReadLine ();
    };
}
