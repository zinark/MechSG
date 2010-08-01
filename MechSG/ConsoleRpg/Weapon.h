#pragma once
#include <string>
#include "Range.h"
using namespace std;

namespace CRPG
{

    class Weapon
    {
    private:
        string _Name;
        Range _Range;
        

    public:
        Weapon(string name, Range& range);
        Weapon(void);
        ~Weapon(void);
        string Name () const { return _Name; }
        Range DamageRange () const { return _Range; }
    };
}