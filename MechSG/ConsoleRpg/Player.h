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
        Weapon _Weapon;
        int _Experience;
        int _NextLevel;

    public:
        Player(void);
        Player (string name);
        ~Player(void);

        
        void Attack (Monster& monster);
        void TakeDamage (int value);
        bool IsDie ();
        bool CanRun ();
        void LevelUp ();
        void Rest ();

        Statistics& GetStatistics () { return _Statistics; }
        string& Name () { return _Name;}

        Player& WithStat (const CRPG::Statistics& stat);
        Player& Weaponed (const Weapon& weapon);
        Player& Experienced (int value);
    };
}
