#pragma once
#include <iostream>
#include "Statistics.h"
#include "Monster.h"
using namespace std;
using namespace CRPG;

namespace CRPG
{
    class Monster;

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
        void Attack (const Monster& monster);
        void TakeDamage (int value);

        Player& WithStat (const CRPG::Statistics& stat);
    };
}
