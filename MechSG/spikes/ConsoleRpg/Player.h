#pragma once
#include <iostream>
#include "Statistics.h"
#include "Monster.h"
#include "Challenger.h"
using namespace std;
using namespace CRPG;

namespace CRPG
{
    class Monster;

    class Player : public Challenger
    {

    private:
        int _Experience;
        int _NextLevelExperience;

    public:
        Player(void);
        Player (string name);
        ~Player(void);

        bool CanRun ();
        void LevelUpIfApplicable ();
        void Rest ();
        void AddExperience (int totalExperience);

        int NextLevelExperience () const { return _NextLevelExperience; }
        

        // Player& Challenger::WithStat(const Statistics& stat);
        // Player& WithStat (const Statistics& stat);
        //Player& Weaponed (const Weapon& weapon);
        Player& Experienced (int value);
        Player& SetNextLevelExperience (int value) { _NextLevelExperience = value; return *this; }
    };
}
