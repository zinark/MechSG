#pragma once
#include <iostream>
#include "Statistics.h"
using namespace std;

namespace CRPG
{
    class Player
    {
    
    private:
        string _Name;
        Statistics _Statistics;

    public:
        Player(void);
        Player (string name);
        ~Player(void);

        Statistics& Statistics () { return _Statistics; }
        string& Name () { return _Name;}

        Player& WithStat (const CRPG::Statistics& stat);
    };
}
